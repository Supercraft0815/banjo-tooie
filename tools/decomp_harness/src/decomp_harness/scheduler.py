from collections import Counter
import json

from .common import HarnessError

RANK = {'easy': 0, 'medium': 1, 'hard': 2, 'extreme': 3}


def next_function(state, difficulty=None, excluded=(), busy=()):
    """Cheapest progress first:

    1. members of an already solved shape group (local transfer, no inference),
    2. easier functions before harder ones, resumable candidates first,
    3. representatives of large unsolved groups (one model run can unlock many),
    4. functions whose callees are already decompiled (known prototypes),
    5. smaller before larger.
    """
    rows = [dict(r) for r in state.db.execute("SELECT * FROM functions WHERE status='pending' AND present=1")]
    pending = {r['symbol'] for r in rows}
    groups = Counter(r['shape'] for r in rows if r['shape'])
    solved = {r[0] for r in state.db.execute('SELECT DISTINCT shape FROM solutions WHERE shape IS NOT NULL')}
    tried = {r[0] for r in state.db.execute(
        "SELECT DISTINCT function_id FROM local_trials WHERE candidate_sha NOT LIKE 'm2c:%' AND candidate_sha NOT LIKE 'permuter:%'")}
    # A blocked member suggests the group needs more than one routine model run.
    spoiled = {r[0] for r in state.db.execute(
        "SELECT DISTINCT shape FROM functions WHERE shape IS NOT NULL AND status IN ('blocked','needs_human')")}

    def priority(r):
        shape = r['shape']
        harvest = shape in solved and r['id'] not in tried
        group = groups[shape] if shape and shape not in solved and shape not in spoiled else 1
        callees = sum(c in pending for c in json.loads(r['dependencies']) if c != r['symbol'])
        return (0 if harvest else 1, RANK.get(r['difficulty'], 3), 0 if r['best_source'] is not None else 1,
                -group, callees, r['size'] or 0, r['id'])

    busy = set(busy)
    choices = (r for r in rows if (not difficulty or r['difficulty'] == difficulty)
               and r['id'] not in excluded and not resources(r) & busy)
    return min(choices, key=priority, default=None)


def resources(function):
    shape = function.get('shape')
    return {function['source'], function['symbol'], *json.loads(function['dependencies']),
            *(('shape:'+shape,) if shape else ())}


def route(function, config, model=None):
    stages = config['routing']
    stage = function['stage']
    if (function['difficulty'] == 'easy' and config['easy_model']['enabled']
            and not function.get('initial_done', 0) and (stage == -2 or function['cycle_attempts'] == 0) and not model):
        return -2, dict(config['easy_model'])
    if stage < 0:
        stage = min({'easy': 0, 'medium': 1, 'hard': 2, 'extreme': 3}[function['difficulty']], len(stages)-1)
    if stage >= len(stages):
        raise HarnessError('Routing exhausted; retry function to reset escalation')
    return stage, {**stages[stage], 'model': model or stages[stage]['model']}


def advance(function, history, config, stage):
    used = function['stage_attempts'] + 1
    total = function['cycle_attempts'] + 1
    if stage == -2:
        if used < config['easy_model']['attempts']:
            return -2, used, total, total >= config['max_attempts_per_function']
        return 0, 0, total, total >= config['max_attempts_per_function']
    scores = [h['score'] for h in history if h['score'] is not None]
    window = config['stagnation_window']
    stagnant = len(scores) > window and max(scores[-window:]) - scores[-window-1] < config['minimum_gain']
    if used >= config['routing'][stage]['attempts'] or stagnant and used >= window:
        stage, used = stage + 1, 0
    normal_limit = config['max_attempts_per_function']
    if stage >= len(config['routing']) or total >= normal_limit:
        rising = len(scores) >= 2 and scores[-1] - scores[-2] >= config['minimum_gain']
        if rising and total < normal_limit + config['extra_attempts']:
            return len(config['routing'])-1, 0, total, False
        return stage, used, total, True
    return stage, used, total, False
