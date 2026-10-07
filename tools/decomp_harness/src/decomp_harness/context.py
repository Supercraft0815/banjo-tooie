from __future__ import annotations

import json
from difflib import SequenceMatcher
from pathlib import Path
import re

from .common import command
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


def context_pack(root, function, state, config):
    source = (root/function['source']).read_text()
    macro = next((m for m in global_asms(source) if m['symbol'] == function['symbol']), None)
    position = macro['start'] if macro else source.find(function['symbol'])
    radius = 12 if function['difficulty'] == 'easy' else 28
    before = source[:position].splitlines()[-radius:]
    after = source[position:].splitlines()[:radius]
    neighbors = '\n'.join(l for l in before+after if 'GLOBAL_ASM' not in l and l.strip())
    includes = '\n'.join(l for l in source.splitlines() if l.startswith('#include'))
    features = json.loads(function['features'])
    terms = [function['symbol'], *features['calls'], *features['globals']]
    related = excerpts(root, terms, ('src', 'include'), 6000)
    # Find nearby type declarations using locally observed type names only.
    types = re.findall(r'\b(?:struct\s+)?([A-Z][A-Za-z0-9_]*(?:State|Info|Actor|Data|Struct))\b', neighbors+related)
    type_info = excerpts(root, types, ('include',), 2500)
    asm = (root/function['asm']).read_text()
    bk = ''
    if config['banjo_kazooie_repo']:
        bkroot = Path(config['banjo_kazooie_repo']).expanduser().resolve()
        semantic_terms = [t for t in terms if not re.match(r'^(?:func|D|R)_[0-9A-Fa-f]{8}', t)]
        constants = re.findall(r'\b0x[0-9a-fA-F]{3,}\b', asm)
        bk = excerpts(bkroot, semantic_terms+constants[:8], ('src', 'include', 'asm'), 3000)
        bk += '\n'+asm_analogues(bkroot, asm, state)
    knowledge = list(state.db.execute('SELECT tags,summary FROM knowledge'))
    tokens = set(re.findall(r'\w+', function['source']+' '+asm))
    knowledge.sort(key=lambda row: len(tokens & set(row['tags'].split())), reverse=True)
    notes = '\n'.join(row['summary'] for row in knowledge if tokens & set(row['tags'].split()))[:1600]
    history = state.history(function['id'], 4)
    previous = ''
    if function['best_run']:
        result = root / '.decomp-agent/runs' / function['best_run'] / 'comparison.json'
        if result.exists():
            value = json.loads(result.read_text())
            value.pop('diffs', None)
            previous = json.dumps(value, ensure_ascii=False)[:4000]
    last_patch = ''
    if history:
        path = root / '.decomp-agent/runs' / history[-1]['id'] / 'source.diff'
        if path.exists():
            last_patch = path.read_text()[:4000]
    budget = config['context_chars']
    current = ''
    if function['best_source']:
        from .guard import candidate_guard
        from .common import HarnessError
        try:
            current = candidate_guard(source, function['best_source'].decode(), function['symbol'])
        except (HarnessError, UnicodeError):
            current = '[Saved candidate does not fit the current source; use the target directive.]'
    directive = source[macro['start']:macro['end']] if macro else ''
    line = source[:position].count('\n') + 1
    pack = (f"Target: {function['id']}\nSource: {function['source']}\nTarget line: {line}\nASM: {function['asm']}\n"
            f"Exact target directive (or current C below):\n{directive}\nCurrent candidate:\n{current[:4000]}\n"
            f"Compiler: IDO 5.3, -O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul\n"
            f"Existing primitive typedefs from PR/ultratypes.h (do not redeclare or reread):\n{primitive_types(root)}\n"
            f"Features: {json.dumps(features)}\nBest score: {function['best_score']}\n"
            f"Recent attempts: {json.dumps(history)}\nPrevious diff: {previous}\n"
            f"Last compiler/agent error: {function['last_error']}\nLast attempted source patch:\n{last_patch}\n"
            f"Relevant compiler/pattern notes:\n{notes}\nIncludes:\n{includes}\n"
            f"Neighbor context:\n{neighbors[:3500]}\nLocal symbol/prototype/pattern hits:\n{related}\n"
            f"Type hints:\n{type_info}\nRead-only BK search results:\n{bk}\n")
    # The full ASM and current C always exist in the worker, even for extreme targets.
    available = max(1000, budget-len(pack)-200)
    asm_context = asm if len(asm) <= available else asm[:available]+'\n[Context budget reached; read the full target ASM file locally.]'
    return (pack[:max(0, budget-1200)] + '\nOriginal ASM:\n' + asm_context)[:budget]


def worker_prompt(function, pack, native):
    validation = f"make -j1 build/us/{function['source']}.o"
    return f'''Implement exactly one matching C function: {function['symbol']}.
Edit ONLY {function['source']}; replace only its target GLOBAL_ASM directive.
Keep the surrounding file byte-for-byte unchanged. Put any necessary declarations
inside the function. The pack supplies the exact edit target, ASM, primitive typedefs
and local context. Use them directly: do not reread these files to confirm the same
information. Read a narrow file range only to resolve a specific missing fact.
If an editing tool requires a prior read, read only a few lines around Target line.
This directory is a disposable source copy. No git actions or other agents.
Goal: byte/instruction-identical IDO output, not approximately equivalent semantics.
Never use GLOBAL_ASM, inline asm, generated byte arrays, incbin, conditional compilation,
reference changes, build/diff modifications, or other tricks to manufacture a match.
Do not read credentials, environment configuration or personal files. No network.
Prefer existing types and nearby C patterns; spend context on this function only.
One implementation attempt per invocation. Return structured notes after editing.
Validation command: {validation}
{'You may run that object build; the parent separately verifies the full ROM.' if native else 'The compiler is Linux-only on this host. The parent runs that build in an isolated container after you finish; do not invoke Docker or install tools.'}
The parent, not your final answer, determines whether the code matches.
If blocked, describe the concrete missing type/compiler issue in the result.

{pack}
'''
