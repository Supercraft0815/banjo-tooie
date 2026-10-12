from __future__ import annotations

import hashlib
from pathlib import Path
import re

from .common import HarnessError

LEX = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\n]*|/\*[\s\S]*?\*/')
MACRO = re.compile(r'(?m)^[ \t]*(?:#[ \t]*pragma[ \t]+)?GLOBAL_ASM\s*\(\s*"([^"\n]+)"\s*\)[ \t]*;?')
INSN = re.compile(r'/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s*\*/\s*(\S+)(.*)')


def uncomment(text: str) -> str:
    return LEX.sub(lambda m: re.sub(r'[^\n]', ' ', m[0]) if m[0].startswith(('/', '/*')) else m[0], text)


def global_asms(text: str):
    """Retain offsets, ignore comments/strings and statically disabled #if 0 arms.

    Unknown build conditions are intentionally conservative (both arms discovered).
    The compiled baseline remains authoritative about whether a symbol exists.
    """
    clean = uncomment(text)
    active = True
    stack = []
    lines = []
    for line in clean.splitlines(keepends=True):
        directive = re.match(r'\s*#\s*(if|ifdef|ifndef|else|elif|endif)\b(.*)', line)
        if directive:
            op, value = directive.groups()
            if op in ('if', 'ifdef', 'ifndef'):
                value = value.strip().strip('()').strip()
                cond = value != '0' if op == 'if' and value in ('0', '1') else None
                stack.append((active, cond))
                active = active and cond is not False
            elif stack and op in ('else', 'elif'):
                parent, cond = stack[-1]
                active = parent and (cond is None or not cond)
                if op == 'elif':
                    active = parent and cond is not True and value.strip() != '0'
                    current = value.strip().strip('()').strip()
                    taken = current != '0' if current in ('0', '1') else None
                    stack[-1] = (parent, True if cond is True else None if cond is None or taken is None else taken)
            elif stack and op == 'endif':
                active = stack.pop()[0]
        lines.append(line if active else re.sub(r'[^\n]', ' ', line))
    masked = ''.join(lines)
    for m in MACRO.finditer(masked):
        path = Path(m[1])
        if path.is_absolute() or '..' in path.parts or path.suffix != '.s':
            raise HarnessError(f"Unsafe GLOBAL_ASM path: {path}")
        yield {"asm": path.as_posix(), "symbol": path.stem, "start": m.start(), "end": m.end()}


def shape_operand(operand: str) -> str:
    """Operand class for near-duplicate grouping: symbols, labels and plain immediates
    vary; registers, stack offsets and memory displacements must stay identical."""
    operand = re.sub(r'\s+', '', operand.split('#')[0])
    operand = re.sub(r'\.L\w+', 'L', operand)
    operand = re.sub(r'(?<![\w$.%])[A-Za-z_]\w*', 'S', operand)
    if '$sp' not in operand:
        operand = re.sub(r'(?<![\w$])-?(?:0x[0-9A-Fa-f]+|\d+)(?![\w(])', 'I', operand)
    return operand


def shape_key(body):
    rows = [op + ' ' + shape_operand(rest) for *_, op, rest in body]
    return hashlib.sha256('\n'.join(rows).encode()).hexdigest()[:24] if rows else None


def asm_features(text: str, symbol: str):
    lines = text.splitlines()
    start = next((i for i, l in enumerate(lines) if re.match(rf'\s*(?:glabel|[.]globl)\s+{re.escape(symbol)}\s*$', l)), None)
    body = []
    for line in lines[start:] if start is not None else []:
        if re.match(rf'\s*endlabel\s+{re.escape(symbol)}\b', line):
            break
        m = INSN.search(line)
        if m:
            body.append(m.groups())
    calls = sorted(set(re.findall(r'\bjal\s+([A-Za-z_]\w*)', text)))
    globals_ = sorted(set(re.findall(r'%(?:hi|lo)\(([^) +]+)', text)))
    stack = re.search(r'addiu\s+\$sp,\s*\$sp,\s*-(0x[0-9a-fA-F]+|[0-9]+)', text)
    ops = [b[3] for b in body]
    features = {
        "kind": 'function' if start is not None else 'data' if re.search(r'\bdlabel\s+'+re.escape(symbol)+r'\b', text) else 'missing',
        "instructions": len(body), "branches": sum(op.startswith('b') for op in ops),
        "calls": calls, "globals": globals_, "stack": int(stack[1], 0) if stack else 0,
        "float_ops": sum('.s' in op or '.d' in op or op in ('lwc1', 'swc1', 'mtc1', 'mfc1') for op in ops),
        "indirect_calls": ops.count('jalr'), "switches": sum('jr ' in l and '$ra' not in l for l in lines),
        "memory_ops": sum(op in ('lw', 'sw', 'lb', 'lbu', 'lh', 'lhu', 'sh', 'sb', 'ld', 'sd') for op in ops),
        "isa64_ops": sorted(set(ops) & {'ld', 'sd', 'dadd', 'daddu', 'daddi', 'daddiu', 'dsub', 'dsubu',
                                        'dsll', 'dsll32', 'dsrl', 'dsrl32', 'dsra', 'dsra32', 'dmult', 'ddiv'}),
        "rom_start": int(body[0][0], 16) if body else None,
        "vram": int(body[0][1], 16) if body else None,
        "shape": shape_key(body),
    }
    weight = (len(body) + features['branches'] * 5 + len(calls) * 3 +
              features['float_ops'] * 2 + features['indirect_calls'] * 35 + features['switches'] * 60)
    features['difficulty'] = 'easy' if weight <= 45 else 'medium' if weight <= 150 else 'hard' if weight <= 450 else 'extreme'
    if not body:
        features['difficulty'] = 'extreme'
    return features


def scan(root: Path):
    seen = set()
    for source in sorted((root / 'src').rglob('*.c')):
        if source.is_symlink():
            raise HarnessError(f"Symlink source refused: {source}")
        relative = source.relative_to(root).as_posix()
        for macro in global_asms(source.read_text()):
            identity = relative + '::' + macro['symbol']
            if identity in seen:
                raise HarnessError(f"Duplicate GLOBAL_ASM for {identity}; resolve conditional definitions first")
            seen.add(identity)
            asm = root / macro['asm']
            if not asm.resolve().is_relative_to(root.resolve()):
                raise HarnessError(f"ASM leaves repository: {asm}")
            features = asm_features(asm.read_text(), macro['symbol']) if asm.exists() else asm_features('', macro['symbol'])
            yield {"id": identity, "symbol": macro['symbol'], "source": relative,
                   "asm": macro['asm'], "segment": macro['symbol'].rsplit('_', 1)[-1] if relative.startswith('src/overlays/') else Path(relative).parts[1],
                   "size": features['instructions'] * 4, "difficulty": features['difficulty'],
                   "features": features, "dependencies": features['calls'], "shape": features.pop('shape'),
                   "asm_sha": hashlib.sha256(asm.read_bytes()).hexdigest() if asm.exists() else None}
