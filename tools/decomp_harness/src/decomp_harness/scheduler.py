from .common import HarnessError


def next_function(state, difficulty=None, excluded=()):
    rows = state.db.execute("""SELECT * FROM functions WHERE status='pending' AND present=1
        ORDER BY CASE difficulty WHEN 'easy' THEN 0 WHEN 'medium' THEN 1 WHEN 'hard' THEN 2 ELSE 3 END,
        CASE WHEN best_source IS NOT NULL THEN 0 ELSE 1 END, size, id""").fetchall()
    return next((dict(r) for r in rows if (not difficulty or r['difficulty'] == difficulty) and r['id'] not in excluded), None)


def route(function, config, model=None):
    stages = config['routing']
    stage = function['stage']
    if stage < 0:
        stage = min({'easy': 0, 'medium': 1, 'hard': 2, 'extreme': 3}[function['difficulty']], len(stages)-1)
    if stage >= len(stages):
        raise HarnessError('Routing exhausted; retry function to reset escalation')
    return stage, {**stages[stage], 'model': model or stages[stage]['model']}


def advance(function, history, config, stage):
    used = function['stage_attempts'] + 1
    total = function['cycle_attempts'] + 1
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
