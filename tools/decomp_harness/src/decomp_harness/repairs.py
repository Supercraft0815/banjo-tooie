"""Bounded C/interface repairs. Only the trusted full ROM check can accept them."""
from __future__ import annotations

import hashlib
import json
import re
from pathlib import Path

from .common import HarnessError, atomic_write, command, save_json
from .guard import candidate_guard, extract_function, verify_worker_changes
from .scanner import LEX, global_asms, uncomment


def repair_scope(root, function):
    """Existing headers and C definitions for the target's named dependencies."""
    features = json.loads(function['features'])
    terms = [function['symbol'], *features.get('calls', []), *features.get('globals', [])]
    paths = [str(root/p) for p in ('include', 'src') if (root/p).is_dir()]
    args = ['rg', '-l', '-w', '--glob', '*.h', '--glob', '*.c']
    for term in terms:
        args += ['-F', '-e', term]
    hits = command([*args, *paths], check=False, timeout=30).stdout.decode().splitlines() if paths else []
    result = {}
    for name in sorted(hits, key=lambda p: (not p.endswith('.h'), p)):
        path = Path(name)
        relative = path.relative_to(root).as_posix()
        if relative == function['source'] or path.is_symlink():
            continue
        text = path.read_text()
        if path.suffix == '.c' and not any(extract_function(text, term) for term in features.get('calls', [])):
            continue
        result[relative] = path.read_bytes()
        # A larger dependency change should be a separate, deliberately scoped task.
        if len(result) == 8:
            break
    return result


def c_surface(text):
    """Preserve directives, ASM imports and existing function identities."""
    macros = list(global_asms(text))
    for macro in reversed(macros):
        text = text[:macro['start']] + ' ' * (macro['end']-macro['start']) + text[macro['end']:]
    code = uncomment(text.replace('\\\n', ''))
    if re.search(r'\b(?:GLOBAL_ASM|asm|__asm__|__asm|_Pragma)\b|[.]incbin', code):
        raise HarnessError('ASM workaround refused in dependency repair')
    # Joining continuations also protects multi-line defines and includes.
    directives = re.findall(r'(?m)^\s*#[^\n]*', code.replace('\\\n', ''))
    clean = LEX.sub(lambda m: ' ' * len(m[0]), text)
    names = {m[1] for m in re.finditer(r'\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*{', clean)
             if extract_function(text, m[1]) is not None}
    return [text_.strip() for text_ in directives], names


def guard_candidate(original, candidate, symbol):
    try:
        return candidate_guard(original, candidate, symbol)
    except HarnessError:
        guard_repair(original, candidate, symbol)
        replacement = extract_function(candidate, symbol)
        if not replacement:
            raise HarnessError('Repair did not define the target function')
        return replacement


def guard_repair(before, after, target=None):
    expected = list(global_asms(before))
    actual = list(global_asms(after))
    if target and sum(m['symbol'] == target for m in expected) != 1:
        raise HarnessError('Repair target must have exactly one GLOBAL_ASM')
    keep = lambda text, macros: [text[m['start']:m['end']] for m in macros if m['symbol'] != target]
    if (keep(before, expected) != keep(after, actual)
            or target and any(m['symbol'] == target for m in actual)):
        raise HarnessError('Repair changed another ASM directive or left the target unchanged')
    directives, names = c_surface(before)
    updated_directives, updated_names = c_surface(after)
    if directives != updated_directives:
        raise HarnessError('Repair changed preprocessor directives')
    if updated_names != names | ({target} if target else set()):
        raise HarnessError('Repair added, removed or renamed an unrelated function')


def guard_support(scope, changes):
    if set(changes) - set(scope):
        raise HarnessError('Dependency repair exceeds the supplied file scope')
    for path, after in changes.items():
        guard_repair(scope[path].decode(), after.decode())


def worker_candidate(worker, before, function, original, scope, redact):
    verify_worker_changes(worker, before, function['source'], scope)
    candidate = (worker/function['source']).read_bytes()
    changes = {p: (worker/p).read_bytes() for p, value in scope.items() if (worker/p).read_bytes() != value}
    if any(redact(value.decode()) != value.decode() for value in [candidate, *changes.values()]):
        raise HarnessError('Credential material rejected before candidate persistence')
    guard_candidate(original.decode(), candidate.decode(), function['symbol'])
    guard_support(scope, changes)
    return candidate, changes


def seed_worker(worker, root, function, original, scope):
    support, candidate = {}, function['best_source'] or original
    if function['best_run']:
        try:
            support = load_support(root/'.decomp-agent/runs'/function['best_run'], scope)
        except HarnessError:
            candidate = original
    atomic_write(worker/function['source'], candidate)
    for path, value in scope.items():
        atomic_write(worker/path, support.get(path, value))


def save_support(directory, scope, changes):
    save_json(directory/'support.json', {path: {'before_sha': hashlib.sha256(scope[path]).hexdigest(),
                                               'after': after.decode()} for path, after in changes.items()})


def recheck_key(function, original, scope):
    data = original + (function['best_source'] or b'') + (function['asm_sha'] or '').encode()
    for path, value in sorted(scope.items()):
        data += path.encode() + value
    return 'recheck-v1:' + hashlib.sha256(data).hexdigest()


def load_support(directory, scope):
    path = directory/'support.json'
    if not path.is_file():
        return {}
    saved = json.loads(path.read_text())
    if any(p not in scope or value['before_sha'] != hashlib.sha256(scope[p]).hexdigest()
           for p, value in saved.items()):
        raise HarnessError('Saved dependency repair has a stale baseline; rebuild it from current declarations')
    changes = {p: value['after'].encode() for p, value in saved.items()}
    guard_support(scope, changes)
    return changes


def run_repair_evidence(root, function, run):
    from .matching import instructions, score
    directory = root/'.decomp-agent/runs'/run['id']
    if run['outcome'] == 'guard_rejected' and 'outside the target directive' in (run['error'] or ''):
        candidate = (directory/'source-after.c').read_text()
        guard_candidate((root/function['source']).read_text(), candidate, function['symbol'])
        return 'Previously rejected C/interface repair now passes the bounded guard', (candidate.encode(), run['id'])
    if function['best_source'] and (directory/'expected.asm').is_file() and (directory/'actual.asm').is_file():
        symbol, length = function['symbol'], function['size']//4
        comparison = score(instructions((directory/'expected.asm').read_text(), symbol, length),
                           instructions((directory/'actual.asm').read_text(), symbol, length))
        if comparison['relocation_only']:
            return 'Relocation-only candidate can now reach full ROM validation', None
    result = directory/'result.json'
    message = json.loads(result.read_text()).get('message', {}) if result.is_file() else {}
    blocker = message.get('blocker', '') if isinstance(message, dict) else ''
    if re.search(r'outside.*(?:target|function)|header|prototype|signature|return type|conflicting.*declaration', blocker, re.I):
        return 'Dependency/interface repair is now supported', None
    prompt = directory/'prompt.txt'
    if 'astra' in (run['model'] or '') and prompt.is_file() and './decomp-compile' not in prompt.read_text():
        return 'Old attempt had no compiler feedback loop', None
    return '', None


def refresh_repairs(root, state):
    """One retry per new capability, only when recorded evidence identifies its use."""
    from .common import git
    from .patterns import candidate_source
    refreshed = []
    rows = state.db.execute("SELECT * FROM functions WHERE present=1 AND difficulty='easy' AND status IN ('blocked','needs_human')").fetchall()
    for row in rows:
        f = dict(row)
        if json.loads(f['features']).get('isa64_ops'):
            continue
        key = 'repair-refresh-v1:' + f['id']
        if state.meta(key) or git(root, 'status', '--porcelain=v1', '--', f['source']):
            continue
        history = state.history(f['id'], 8)
        reason, recovered = '', None
        if 'Uncommitted target changes' in (f['last_error'] or ''):
            reason = 'Target is clean again'
        for run in reversed(history):
            try:
                if reason:
                    break
                reason, recovered = run_repair_evidence(root, f, run)
            except (OSError, ValueError, HarnessError):
                continue
        if not reason:
            continue
        original = (root/f['source']).read_text()
        candidate = recovered[0] if recovered else f['best_source']
        if candidate and not recovered:
            # Retain only the function when unrelated matches changed its translation unit.
            code = extract_function(candidate.decode(), f['symbol'])
            if code:
                candidate = candidate_source(original, f['symbol'], code)
        state.update(f['id'], status='pending', stage=-1, stage_attempts=0, cycle_attempts=0,
                     initial_done=int(bool(history)), last_error=reason, best_source=candidate,
                     best_run=recovered[1] if recovered else f['best_run'],
                     base_sha=hashlib.sha256(original.encode()).hexdigest())
        state.set_meta(key, reason)
        refreshed.append({'function': f['id'], 'reason': reason})
    return refreshed
