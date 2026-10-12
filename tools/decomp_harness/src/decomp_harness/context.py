from __future__ import annotations

import json
from difflib import SequenceMatcher
from pathlib import Path
import re

from .bkmap import bk_context
from .common import command
from .patterns import known_declarations
from .scanner import global_asms, INSN


def primitive_types(root):
    path = root/'lib/ultralib/include/PR/ultratypes.h'
    if not path.exists():
        return ''
    return '\n'.join(re.sub(r'\s+', ' ', m[0]) for m in re.finditer(
        r'typedef\s+[^;{}]+\b(?:[su](?:8|16|32|64)|f(?:32|64))\s*;', path.read_text()))


def asm_analogues(root, target_asm, state):
    """Cached local opcode/call-pattern search; never writes into the BK repo."""
    repo = str(root)
    existing = {r['path']: r['mtime_ns'] for r in state.db.execute('SELECT path,mtime_ns FROM reference_asm WHERE repo=?', (repo,))}
    present = set()
    with state.db:
        for path in (root/'asm').rglob('*.s'):
            relative = path.relative_to(root).as_posix()
            present.add(relative)
            modified = path.stat().st_mtime_ns
            if existing.get(relative) == modified:
                continue
            text = path.read_text(errors='replace')
            symbol = re.search(r'\bglabel\s+(\w+)', text)
            ops = [m[4] for m in INSN.finditer(text)]
            calls = re.findall(r'\bjal\s+(\w+)', text)
            if symbol and ops:
                state.db.execute('INSERT OR REPLACE INTO reference_asm VALUES (?,?,?,?,?,?)',
                                 (repo, relative, modified, symbol[1], json.dumps(calls), json.dumps(ops)))
            else:
                state.db.execute('DELETE FROM reference_asm WHERE repo=? AND path=?', (repo, relative))
        for stale in existing.keys()-present:
            state.db.execute('DELETE FROM reference_asm WHERE repo=? AND path=?', (repo, stale))
    target_ops = [m[4] for m in INSN.finditer(target_asm)]
    target_calls = set(re.findall(r'\bjal\s+(\w+)', target_asm))
    ranked = []
    for row in state.db.execute('SELECT * FROM reference_asm WHERE repo=?', (repo,)):
        ops, calls = json.loads(row['opcodes']), set(json.loads(row['calls']))
        if abs(len(ops)-len(target_ops)) > max(5, len(target_ops)//3):
            continue
        similarity = SequenceMatcher(None, target_ops, ops, autojunk=False).ratio()
        similarity += len(calls & target_calls)/max(1, len(calls | target_calls))
        if similarity >= 0.8:
            ranked.append((similarity, row['path'], row['symbol']))
    return '\n'.join(f'{path} ({symbol}, local opcode/call similarity {similarity:.2f})\n'+(root/path).read_text(errors='replace')[:1000]
                     for similarity, path, symbol in sorted(ranked, reverse=True)[:2])[:2600]


def excerpts(root: Path, terms, folders, limit=5000):
    terms = sorted(set(t for t in terms if len(t) > 3))[:24]
    paths = [str(root/f) for f in folders if (root/f).exists()]
    if not terms or not paths:
        return ''
    args = ['rg', '--no-heading', '-n', '-m', '2', '--glob', '*.c', '--glob', '*.h', '--glob', '*.s']
    for term in terms:
        args += ['-F', '-e', term]
    output = command([*args, *paths], timeout=30, check=False).stdout.decode(errors='replace')
    hits = output.splitlines()
    # Prefer definitions and prototypes over opaque GLOBAL_ASM stubs.
    hits.sort(key=lambda line: ('GLOBAL_ASM' in line, len(line)))
    return '\n'.join(line.replace(str(root)+'/', '') for line in hits)[:limit]


def probe_feedback(directory):
    entries, seen = [], set()
    result = directory/'worker-summary.json'
    if result.is_file():
        message = json.loads(result.read_text())
        entries.append(f"Reported blocker: {message.get('blocker', '')[:800]}\nSummary: {message.get('summary', '')[:800]}")
    for path in sorted(directory.glob('compile-*.json'), key=lambda p: int(p.stem.split('-')[1]), reverse=True):
        probe = json.loads(path.read_text())
        if probe['reply'] in seen:
            continue
        seen.add(probe['reply'])
        entries.append(f"{path.stem}: {probe['reply'][:900]}")
        if len(seen) == 3:
            break
    return '\n'.join(entries)


def failed_attempts(root, history):
    """Give retries the tested patches and their actual compiler feedback."""
    entries, seen = [], {}
    for run in reversed(history):
        if run['outcome'] not in ('nonmatching', 'compile_error', 'guard_rejected'):
            continue
        directory = root / '.decomp-agent/runs' / run['id']
        try:
            patch = (directory / 'source.diff').read_text()
        except OSError:
            patch = ''
        entry = f"Run {run['id']}: {run['outcome']}, score={run['score']}\n"
        entry += 'Tested compiler variants (full sources and feedback saved in run artifacts):\n' + probe_feedback(directory) + '\n'
        if patch and patch in seen:
            entry += f"Identical source patch to {seen[patch]}; already tried.\n"
        else:
            seen[patch] = run['id']
            entry += 'Tested source patch:\n' + (patch[:1000] or '[unavailable]')
            if len(patch) > 1000:
                entry += '\n[patch truncated]'
            entry += '\n'
        try:
            comparison = json.loads((directory / 'comparison.json').read_text())
            feedback = {key: comparison.get(key) for key in
                        ('exact', 'different_instructions', 'first_diff')}
            entry += 'Compiler comparison: ' + json.dumps(feedback)[:1500] + '\n'
        except (OSError, ValueError):
            entry += f"Compiler comparison unavailable; error: {run['error']}\n"
        entries.append(entry)
    # Full probe ledger stays on disk; keep recent distinct failures ahead of patch text.
    return '\n'.join(entries)[:6000]


def context_pack(root, function, state, config, budget=None, shared=True, draft=None):
    """Context for one target. `shared=False` omits file-wide facts already given for
    another target of the same batch; `draft` is an unverified m2c translation."""
    source = (root/function['source']).read_text()
    macro = next((m for m in global_asms(source) if m['symbol'] == function['symbol']), None)
    position = macro['start'] if macro else source.find(function['symbol'])
    radius = (12 if function['difficulty'] == 'easy' else 28) if shared else 6
    before = source[:position].splitlines()[-radius:]
    after = source[position:].splitlines()[:radius]
    neighbors = '\n'.join(l for l in before+after if 'GLOBAL_ASM' not in l and l.strip())
    includes = '\n'.join(l for l in source.splitlines() if l.startswith('#include'))
    features = json.loads(function['features'])
    terms = [function['symbol'], *features['calls'], *features['globals']]
    declared = known_declarations(state, [*features['calls'], *features['globals']])
    related = excerpts(root, terms, ('src', 'include'), 6000 if shared else 2500)
    # Find nearby type declarations using locally observed type names only.
    types = re.findall(r'\b(?:struct\s+)?([A-Z][A-Za-z0-9_]*(?:State|Info|Actor|Data|Struct))\b', neighbors+related)
    type_info = excerpts(root, types, ('include',), 2500 if shared else 1000)
    asm = (root/function['asm']).read_text()
    bk = analogue = ''
    if config['banjo_kazooie_repo']:
        bkroot = Path(config['banjo_kazooie_repo']).expanduser().resolve()
        analogue = bk_context(root, bkroot, function['id'], features['calls'])
        if analogue is None:   # no bk_map.json: blind text/opcode search instead of known analogues
            semantic_terms = [t for t in terms if not re.match(r'^(?:func|D|R)_[0-9A-Fa-f]{8}', t)]
            constants = re.findall(r'\b0x[0-9a-fA-F]{3,}\b', asm)
            bk = excerpts(bkroot, semantic_terms+constants[:8], ('src', 'include', 'asm'), 3000)
            bk += '\n'+asm_analogues(bkroot, asm, state)
            analogue = ''
    knowledge = list(state.db.execute('SELECT tags,summary FROM knowledge'))
    tokens = set(re.findall(r'\w+', function['source']+' '+asm))
    knowledge.sort(key=lambda row: len(tokens & set(row['tags'].split())), reverse=True)
    notes = '\n'.join(row['summary'] for row in knowledge if tokens & set(row['tags'].split()))[:1600]
    history = state.history(function['id'], 8)
    previous = ''
    if function['best_run']:
        result = root / '.decomp-agent/runs' / function['best_run'] / 'comparison.json'
        if result.exists():
            value = json.loads(result.read_text())
            value.pop('diffs', None)
            previous = json.dumps(value, ensure_ascii=False)[:4000]
    budget = budget or config['context_chars']
    current = ''
    if function['best_source']:
        from .repairs import guard_candidate
        from .common import HarnessError
        try:
            current = guard_candidate(source, function['best_source'].decode(), function['symbol'])
        except (HarnessError, UnicodeError):
            current = '[Saved candidate does not fit the current source; use the target directive.]'
    directive = source[macro['start']:macro['end']] if macro else ''
    line = source[:position].count('\n') + 1
    common = (f"Compiler: IDO 5.3, -O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul\n"
              f"Existing primitive typedefs from PR/ultratypes.h (do not redeclare or reread):\n{primitive_types(root)}\n"
              if shared else '')
    m2c = (f"Unverified m2c draft (types/order may be wrong; a starting point, not a result):\n{draft[:6000]}\n"
           if draft and not current else '')
    pack = (f"Target: {function['id']}\nSource: {function['source']}\nTarget line: {line}\nASM: {function['asm']}\n"
            f"Exact target directive (or current C below):\n{directive}\nCurrent candidate:\n{current[:4000]}\n"
            f"{common}{m2c}{analogue}"
            f"Features: {json.dumps(features)}\nBest score: {function['best_score']}\n"
            f"Last compiler/agent error: {function['last_error']}\n"
            f"Recent attempts: {json.dumps(history)}\nPrevious diff: {previous}\n"
            f"Failed attempts (newest first):\n{failed_attempts(root, history)}\n"
            f"Last compiler/agent error: {function['last_error']}\n"
            f"Relevant compiler/pattern notes:\n{notes}\n" + (f"Includes:\n{includes}\n" if shared else '') +
            f"Declarations verified in matched code (reuse; declare inside the function if needed):\n{declared}\n"
            f"Neighbor context:\n{neighbors[:3500]}\nLocal symbol/prototype/pattern hits:\n{related}\n"
            f"Type hints:\n{type_info}\nRead-only BK search results:\n{bk}\n")
    # The full ASM and current C always exist in the worker, even for extreme targets.
    available = max(1000, budget-len(pack)-200)
    asm_context = asm if len(asm) <= available else asm[:available]+'\n[Context budget reached; read the full target ASM file locally.]'
    return (pack[:max(0, budget-1200)] + '\nOriginal ASM:\n' + asm_context)[:budget]


def worker_prompt(function, pack, compiles, batch=(), support=()):
    """`compiles` > 0 enables ./decomp-compile; `batch` lists further targets in the same file."""
    symbols = [function['symbol'], *(f['symbol'] for f in batch)]
    if batch:
        task = f'''Implement matching C functions for these {len(symbols)} targets in {function['source']}:
{', '.join(symbols)}. Each target directive is wrapped in comment markers
/* decomp-target-begin NAME */ ... /* decomp-target-end NAME */. Replace only the
GLOBAL_ASM line between a pair of markers with that C function; keep every marker
and everything outside the marked regions byte-for-byte unchanged. Leave a directive
in place when you cannot match it; each target is validated and committed separately.'''
    else:
        task = f'''Implement exactly one matching C function: {function['symbol']}.
Edit {function['source']}. Improve the existing C implementation when present;
otherwise replace its target GLOBAL_ASM directive with C. Never restore an ASM
directive over an existing candidate.
If a verified type/prototype/data-layout error prevents a match, repair the relevant
declarations or existing C definitions in that file or these dependency files:
{', '.join(support) or '[no additional dependency files]'}.
Keep unrelated code unchanged. Preserve every other ASM import, all preprocessor
directives and all existing function names. Do not create files or helper functions.
Explain any change outside the target in your summary; the parent validates and
commits all dependent changes together, only after the full ROM is byte-identical.'''
    if compiles:
        loop = f'''Compile loop: after each edit run `./decomp-compile` (no arguments). The trusted
parent compiles the file with the original IDO flags and prints the normalized
instruction diff (expected | actual) per edited target. Fix the reported differences
and compile again. Stop as soon as every target reports OBJECT MATCH or LINK CHECK READY, or when the
budget of {compiles} requests is used; then finish with your best version. A rejected
request explains which guard rule the file violated. Never run make, Docker or IDO.'''
    else:
        loop = '''The compiler is Linux-only on this host. The parent builds after you finish;
do not invoke Docker or install tools.'''
    return f'''{task}
Reuse canonical declarations; fix inconsistent prototypes rather than invent casts.
The pack supplies the exact edit
target, ASM, primitive typedefs and local context. Use them directly: do not reread
these files to confirm the same information. Read a narrow file range only to resolve
a specific missing fact. If an editing tool requires a prior read, read only a few
lines around Target line. This directory is a disposable source copy. No git actions
or other agents.
Goal: byte/instruction-identical IDO output, not approximately equivalent semantics.
Never use GLOBAL_ASM, inline asm, generated byte arrays, incbin, conditional compilation,
reference changes, build/diff modifications, or other tricks to manufacture a match.
Do not read credentials, environment configuration or personal files. No network.
Prefer existing types and nearby C patterns; spend context on these functions only.
Continue from the current best candidate and the recorded failed attempts below.
Do not resubmit a tested failed source patch, including cosmetic rewrites. Different
C expressions can produce identical machine code: use the recorded compiler diffs,
not just the score. Identify what the previous variants failed to change and try a
new, concrete compiler hypothesis. In your summary, explain what you changed and
which instruction difference it fixed.
If a recorded full-ROM check already rejected this source, an identical OBJECT MATCH
or LINK CHECK READY is not progress: investigate its addresses/types/dependencies
and the recorded link result before resubmitting. Full-ROM checks remain mandatory.
{loop}
The parent, not your final answer, determines whether the code matches.
If blocked, describe the concrete missing type/compiler issue in the result.

{pack}
'''
