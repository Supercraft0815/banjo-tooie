from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import json
from pathlib import Path
import shutil
import sqlite3
import sys
import time

from .build import Builder, import_rom, snapshot, verify_rom
from .common import Control, HarnessError, atomic_write, command, git, load_config, locked, save_json
from .context import context_pack
from .guard import recover_publications
from .scanner import scan
from .scheduler import next_function, route
from .state import State
from .workflow import Loop, initialize_knowledge, probe_models, configured_models, runner_for
from .patterns import candidates, local_plan, seed_matches


def positive(value):
    value = int(value)
    if value <= 0:
        raise argparse.ArgumentTypeError('must be positive')
    return value


def parser():
    cli = argparse.ArgumentParser(prog='decomp-agent', description='Subscription CLI matching harness; local patterns; no API-key billing')
    cli.add_argument('--repo', type=Path, help='Repository root (default: current Git repository)')
    sub = cli.add_subparsers(dest='command', required=True)
    for name in ('init', 'doctor', 'scan', 'status', 'next', 'run', 'retry', 'refresh-repairs', 'inspect', 'verify', 'report', 'patterns', 'stop-after-current', 'knowledge', 'progress'):
        p = sub.add_parser(name)
        p.add_argument('--json', action='store_true')
        if name in ('retry', 'inspect', 'verify'):
            p.add_argument('function')
        if name in ('run', 'next'):
            p.add_argument('--difficulty', choices=('easy', 'medium', 'hard', 'extreme'))
        if name in ('run', 'next', 'doctor'):
            p.add_argument('--model', help='Explicit model override; never an automatic fallback')
            p.add_argument('--provider', choices=('codex', 'claude'), help='Explicit subscription CLI backend (requires --model for run/next)')
        if name == 'run':
            p.add_argument('--concurrency', type=positive, help='Isolated workers (each with its own worktree); validation and commits stay serialized')
            local = p.add_mutually_exclusive_group()
            local.add_argument('--local-only', action='store_true', help='Only deterministic/reused candidates; no CLI authentication or inference')
            local.add_argument('--no-local', action='store_true', help='Skip local candidates, e.g. for a bounded model benchmark')
            p.add_argument('--max-functions', type=positive)
            p.add_argument('--max-attempts', type=positive, help='Maximum worker CLI launches across this invocation, including retries')
            p.add_argument('--max-runtime', type=positive, help='Wall clock limit in seconds, including builds and probes')
            p.add_argument('--function', help='Limit this run to one symbol or source::symbol')
            p.add_argument('--stop-after-current', action='store_true')
            p.add_argument('--dry-run', action='store_true', help='Local plan only; never launches model CLIs or compiles')
            p.add_argument('--no-build-cache', action='store_true', help='Force a fresh isolated baseline; do not retain its build')
        if name == 'doctor':
            p.add_argument('--offline', action='store_true', help='No inference; mark live model checks skipped')
            p.add_argument('--no-build', action='store_true', help='Skip baseline build; report is incomplete')
            p.add_argument('--refresh-models', action='store_true', help='Repeat minimal probes even if cached')
        if name == 'init':
            p.add_argument('--rom', type=Path)
            p.add_argument('--setup', action='store_true', help='Run existing make setup (may download compilers, never a ROM)')
            p.add_argument('--build-image', action='store_true')
        if name == 'knowledge':
            p.add_argument('--add', help='Persist a concise human-reviewed finding')
            p.add_argument('--tags', default='IDO')
    return cli


def summary(state):
    statuses = dict(state.db.execute('SELECT status,count(*) FROM functions GROUP BY status'))
    kinds = Counter(json.loads(r[0]).get('kind') for r in state.db.execute("SELECT features FROM functions WHERE present=1 AND status!='matched'"))
    models = [dict(r) for r in state.db.execute('''SELECT provider,model,kind,count(*) AS runs,
        round(sum(ended-started),2) AS seconds, sum(outcome='matched') AS matches
        FROM runs GROUP BY provider,model,kind''')]
    usage, grouped_usage = Counter(), defaultdict(Counter)
    for row in state.db.execute('SELECT provider,model,kind,usage FROM runs WHERE usage IS NOT NULL'):
        values = {k: v for k, v in json.loads(row['usage']).items() if isinstance(v, (int, float))}
        usage.update(values)
        grouped_usage[row['provider'], row['model'], row['kind']].update(values)
    for group in models:
        group['reported_usage'] = dict(grouped_usage[group['provider'], group['model'], group['kind']])
    workers = state.db.execute("SELECT count(*) FROM runs WHERE kind='worker'").fetchone()[0]
    matched = state.db.execute("SELECT count(*) FROM runs WHERE kind='worker' AND outcome='matched'").fetchone()[0]
    local = state.db.execute("SELECT count(*) FROM runs WHERE kind='local' AND outcome='matched'").fetchone()[0]
    # Code bytes are the honest progress measure: 400 tiny getters are not 400 functions' worth of work.
    matched_bytes, total_bytes = state.db.execute(
        "SELECT coalesce(sum(CASE WHEN status='matched' THEN size END),0), coalesce(sum(size),0) FROM functions WHERE status!='skipped'").fetchone()
    return {'open_functions': kinds.get('function', 0), 'data_directives': kinds.get('data', 0),
            'matched_code_bytes': matched_bytes, 'code_bytes': total_bytes,
            'matched_code_percent': round(100*matched_bytes/total_bytes, 3) if total_bytes else 0,
            'statuses': statuses, 'runs': models, 'reported_usage': dict(usage),
            'matched_functions_per_worker_run': matched/workers if workers else 0,
            'local_matches': local, 'learned_patterns': state.db.execute('SELECT count(*) FROM patterns').fetchone()[0],
            'solved_shape_groups': state.db.execute('SELECT count(DISTINCT shape) FROM solutions').fetchone()[0],
            'state_schema': 3}


# tools/progress.py (mapfile .text) at the fork point 25033be6. The ROM never changes, so the
# total is fixed; progress.py itself keeps reporting the fork value because matched functions'
# nonmatching .s files are retained as references.
TOTAL_CODE_BYTES = 2904832
FORK_DECOMPED_BYTES = 377848
# Same run, per src/ folder (the README badges): folder -> (decomped at fork, total).
FORK_SEGMENT_BYTES = {'boot': (15936, 15936), 'core1': (62860, 153680), 'core2': (97384, 616096),
                      'overlays': (201668, 2119120)}


def progress(state):
    count, matched = state.db.execute(
        "SELECT count(*), coalesce(sum(size),0) FROM functions WHERE status='matched'").fetchone()
    pct = lambda b: round(100*b/TOTAL_CODE_BYTES, 3)
    gained = dict(state.db.execute(
        "SELECT substr(source,5,instr(substr(source,5),'/')-1), sum(size) FROM functions WHERE status='matched' GROUP BY 1"))
    segments = {name: {'fork_percent': round(100*fork/total, 2), 'percent': round(100*(fork+gained.get(name, 0))/total, 2)}
                for name, (fork, total) in FORK_SEGMENT_BYTES.items()}
    # Open = still present and unmatched, same filter as the scheduler's queue; matched counts harness matches.
    difficulties = {r[0]: {'open': r[1], 'open_code_bytes': r[2], 'matched': r[3]} for r in state.db.execute('''
        SELECT difficulty, coalesce(sum(present=1 AND status!='matched'),0),
               coalesce(sum(CASE WHEN present=1 AND status!='matched' THEN size END),0), coalesce(sum(status='matched'),0)
        FROM functions WHERE json_extract(features,'$.kind')='function' GROUP BY difficulty
        ORDER BY CASE difficulty WHEN 'easy' THEN 1 WHEN 'medium' THEN 2 WHEN 'hard' THEN 3 ELSE 4 END''')}
    return {'segments': segments, 'difficulties': difficulties, 'fork_percent': pct(FORK_DECOMPED_BYTES), 'project_percent': pct(FORK_DECOMPED_BYTES+matched),
            'gained_percent_points': pct(matched), 'matched_functions': count, 'matched_code_bytes': matched,
            'decomped_code_bytes': FORK_DECOMPED_BYTES+matched, 'total_code_bytes': TOTAL_CODE_BYTES}


def doctor(root, state, config, control, args):
    checks = []

    def check(name, action):
        try:
            detail = action()
            if detail is False:
                raise HarnessError('Check failed; see .decomp-agent/logs/doctor-'+name+'.log')
            checks.append({'check': name, 'status': 'ok', 'detail': detail})
        except (HarnessError, OSError, ValueError) as e:
            checks.append({'check': name, 'status': 'error', 'detail': str(e)})

    check('python', lambda: sys.version.split()[0])
    check('sqlite', lambda: sqlite3.sqlite_version)
    check('git', lambda: {'branch': git(root, 'symbolic-ref', '--short', 'HEAD'), 'status': git(root, 'status', '--short')})
    check('rom', lambda: verify_rom(root))
    check('decompressed-rom', lambda: verify_rom(root, True))
    models = configured_models(config)
    if args.model:
        models = [{'model': args.model, 'effort': 'low', 'provider': args.provider or 'codex'}]
    elif args.provider:
        models = [m for m in models if m.get('provider', 'codex') == args.provider]
    providers = {args.provider} if args.provider else {m.get('provider', 'codex') for m in models}
    for provider in sorted(providers):
        check(provider+'-auth', lambda provider=provider: runner_for(provider).authenticate())
    builder = Builder(root, config, control)
    check('dependencies', lambda: builder.dependencies(root/'.decomp-agent/logs/doctor-dependencies.log'))
    check('compiler', lambda: builder.invoke(['sh', '-c', 'test -x tools/ido/cc && mips-linux-gnu-gcc --version && mips-linux-gnu-objdump --version && make --version'], root/'.decomp-agent/logs/doctor-compiler.log') == 0)
    check('diff-tools', lambda: builder.invoke(['python3', 'diff.py', '--help'], root/'.decomp-agent/logs/doctor-diff-tools.log') == 0)
    if config['banjo_kazooie_repo']:
        check('bk', lambda: git(Path(config['banjo_kazooie_repo']).expanduser(), 'rev-parse', '--show-toplevel'))
    else:
        checks.append({'check': 'bk', 'status': 'optional', 'detail': 'No BK repository configured'})
    if args.no_build:
        checks.append({'check': 'baseline', 'status': 'skipped', 'detail': '--no-build'})
    else:
        check('baseline', lambda: builder.regression(root/'.decomp-agent/logs/doctor-baseline.log'))
    if args.offline:
        checks.append({'check': 'models', 'status': 'skipped', 'detail': 'Offline: no CLI inference'})
    elif not any(c['status'] == 'error' for c in checks):
        check('models', lambda: probe_models(root, state, config, control, models, args.refresh_models, live_first=True)[1])
    else:
        checks.append({'check': 'models', 'status': 'skipped', 'detail': 'Resolve prerequisite failures before consuming usage'})
    report = {'ok': not any(c['status'] == 'error' for c in checks),
              'complete': not any(c['status'] == 'skipped' for c in checks), 'checks': checks}
    save_json(root/'.decomp-agent/doctor.json', report)
    return report


def init(root, state, config, control, args):
    config_path = root/'.decomp-agent/config.toml'
    if not config_path.exists():
        atomic_write(config_path, Path(__file__).with_name('default.toml').read_text())
    if args.rom:
        import_rom(args.rom.expanduser().resolve(), root)
    verify_rom(root)
    if args.build_image:
        from .common import run_logged
        code = run_logged(['docker', 'build', '--platform', config['build']['platform'], '-t', config['build']['image'],
                           'tools/decomp_harness'], root, root/'.decomp-agent/logs/docker-build.log', 1800, control)
        if code:
            raise HarnessError('Docker image build failed; see .decomp-agent/logs/docker-build.log')
    if args.setup:
        p = command(['git', 'submodule', 'status', '--recursive'], root).stdout.decode()
        if any(line.startswith(('-', '+', 'U')) for line in p.splitlines()):
            raise HarnessError('Submodules are missing or not pinned. Run git submodule update --init --recursive before setup.')
        if Builder(root, config, control).invoke(['make', 'setup'], root/'.decomp-agent/logs/setup.log', network=True):
            raise HarnessError('make setup failed; see .decomp-agent/logs/setup.log')
        verify_rom(root, True)
    initialize_knowledge(state)
    state.sync(scan(root))
    return {'initialized': True, 'config': str(config_path), **summary(state)}


def dry_run(root, state, config, args):
    state.sync(scan(root))
    seed_matches(root, state)
    if args.local_only:
        plan = local_plan(root, state, args.difficulty, args.function,
                          m2c=config['m2c'] and (root/'tools/m2c/m2c.py').is_file())
        plan['plan'] = plan['plan'][:args.max_functions]
        return {'dry_run': True, 'codex_runs': 0, 'model_runs': 0, **plan}
    choices, excluded = [], set()
    limit = args.max_functions or 1
    for _ in range(limit):
        f = state.get(args.function) if args.function and not choices else next_function(state, args.difficulty, excluded)
        if not f or args.function and choices:
            break
        excluded.add(f['id'])
        stage, model = route(f, config, args.model)
        pack = context_pack(root, f, state, config) if (root/f['asm']).exists() else 'Run init --setup to generate ASM'
        path = root/'.decomp-agent/context'/f'dry-{len(choices)+1}.txt'
        atomic_write(path, pack)
        local = list(candidates(root, f, state)) if config['local_patterns'] and not args.no_local and (root/f['asm']).exists() else []
        if args.provider:
            model['provider'] = args.provider
        choices.append({'function': f['id'], 'difficulty': f['difficulty'], 'bytes': f['size'],
                        'local_candidates': len(local), 'local_only': args.local_only,
                        'stage': stage, **model, 'context_chars': len(pack), 'context': str(path)})
    return {'dry_run': True, 'codex_runs': 0, 'model_runs': 0, 'concurrency': config['concurrency'], 'plan': choices}


def verify(root, state, config, control, function):
    f = state.get(function)
    work = snapshot(root)
    try:
        builder = Builder(work, config, control)
        log = root/'.decomp-agent/logs/verify.log'
        ok = builder.regression(log)
        from .scanner import global_asms
        implemented = not any(m['symbol'] == f['symbol'] for m in global_asms((work/f['source']).read_text()))
        return {'function': f['id'], 'full_rom_exact': ok, 'implemented': implemented,
                'exact_match': ok and implemented, 'status': f['status'], 'log': str(log)}
    finally:
        shutil.rmtree(work)


def pattern_report(root, state):
    result = local_plan(root, state)
    result['sample'] = result.pop('plan')[:20]
    return {**result, 'candidate_functions': result['eligible_functions'], 'model_runs': 0, 'compiled': False}


def dispatch(root, state, config, control, args):
    if args.command == 'init':
        return init(root, state, config, control, args)
    if args.command == 'doctor':
        return doctor(root, state, config, control, args)
    if args.command == 'scan':
        count = state.sync(scan(root))
        return {'global_asm_directives': count, **summary(state)}
    if args.command in ('status', 'report'):
        report = summary(state)
        if args.command == 'report':
            save_json(root/'.decomp-agent/report.json', report)
            text = '\n\n'.join(f"{r['tags']}\n{r['summary']}\nSource: {r['origin']}" for r in state.db.execute('SELECT * FROM knowledge'))
            atomic_write(root/'.decomp-agent/knowledge.md', text+'\n')
        return report
    if args.command == 'next':
        f = next_function(state, args.difficulty)
        if not f:
            return {'next': None}
        stage, model = route(f, config, args.model)
        if args.provider:
            model['provider'] = args.provider
        return {'next': f['id'], 'difficulty': f['difficulty'], 'size': f['size'], 'stage': stage, **model}
    if args.command == 'progress':
        return progress(state)
    if args.command == 'patterns':
        return pattern_report(root, state)
    if args.command == 'run':
        return dry_run(root, state, config, args) if args.dry_run else Loop(root, state, config, control, args).run()
    if args.command == 'refresh-repairs':
        from .repairs import refresh_repairs
        state.sync(scan(root))
        return {'refreshed': refresh_repairs(root, state)}
    if args.command == 'retry':
        f = state.get(args.function)
        if f['status'] == 'matched':
            raise HarnessError('Matched functions cannot be retried; use verify')
        state.transition(f['id'], 'pending', stage=-1, stage_attempts=0, cycle_attempts=0, initial_done=0, last_error=None)
        with state.db:
            state.db.execute('DELETE FROM local_trials WHERE function_id=?', (f['id'],))
        return {'pending': f['id'], 'best_attempt_retained': bool(f['best_source'])}
    if args.command == 'inspect':
        f = state.get(args.function)
        f['best_source_bytes'] = len(f.pop('best_source') or b'')
        return {**f, 'history': state.history(f['id'], 20)}
    if args.command == 'verify':
        return verify(root, state, config, control, args.function)
    if args.command == 'knowledge':
        if args.add:
            state.note(args.tags, args.add, 'human-reviewed CLI entry')
        return [dict(r) for r in state.db.execute('SELECT * FROM knowledge')]
    raise HarnessError('Unknown command')


def main(argv=None):
    args = parser().parse_args(argv)
    state, control = None, Control(getattr(args, 'max_runtime', None))
    control.install()
    try:
        root = args.repo.expanduser().resolve() if args.repo else Path(git(Path.cwd(), 'rev-parse', '--show-toplevel'))
        if not (root/'baserom.us.yaml').exists():
            raise HarnessError('This does not appear to be the Banjo-Tooie repository')
        config = load_config(root)
        if getattr(args, 'concurrency', None) is not None:
            config['concurrency'] = args.concurrency
        if getattr(args, 'no_build_cache', False):
            config['build_cache'] = False
        if args.command in ('run', 'next') and args.provider and not args.model:
            raise HarnessError('--provider requires an explicit --model')
        if args.command == 'run' and args.local_only and not config['local_patterns']:
            raise HarnessError('--local-only requires local_patterns=true')
        state_dir = root/'.decomp-agent'
        if args.command == 'stop-after-current':
            atomic_write(state_dir/'stop-after-current', 'stop\n')
            print('Stop requested: active functions may finish; no next function will start.')
            return 0
        # Read-only commands use WAL without taking the scheduler lock.
        from contextlib import nullcontext
        readonly = args.command in ('status', 'progress', 'report', 'inspect', 'next', 'patterns')
        with nullcontext() if readonly else locked(state_dir):
            if not readonly:
                # Under the lock no process owns a build tree: these are leftovers of killed runs.
                shutil.rmtree(state_dir/'build-tmp', ignore_errors=True)
            state = State(state_dir/'state.db')
            result = dispatch(root, state, config, control, args)
            print(json.dumps(result, indent=2, ensure_ascii=False))
            failed = isinstance(result, dict) and (result.get('ok') is False or result.get('exact_match') is False)
            return 1 if failed else 130 if control.stopped() else 0
    except (HarnessError, OSError, ValueError, sqlite3.Error) as e:
        print(f'decomp-agent: {e}', file=sys.stderr)
        return 130 if control.stopped() else 2
    finally:
        if state:
            state.close()
        control.restore()


if __name__ == '__main__':
    raise SystemExit(main())
