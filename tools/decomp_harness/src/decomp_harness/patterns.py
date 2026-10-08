"""Conservative straight-line MIPS recipes; every result still needs a full ROM check."""
import hashlib
import json
import re
from functools import lru_cache

from .common import HarnessError
from .guard import candidate_guard
from .scanner import INSN, LEX, global_asms

LOADS = {0x20: ('s8', 's32', 1), 0x24: ('u8', 'u32', 1),
         0x21: ('s16', 's32', 2), 0x25: ('u16', 'u32', 2),
         0x23: ('s32', 's32', 4), 0x31: ('f32', 'f32', 4)}
STORES = {0x28: ('s8', 1), 0x29: ('s16', 2), 0x2B: ('s32', 4), 0x39: ('f32', 4)}
RETURN = 0x03E00008


def body_rows(asm, symbol):
    start = re.search(r'(?m)^\s*glabel\s+'+re.escape(symbol)+r'\s*$', asm)
    end = re.search(r'(?m)^\s*endlabel\s+'+re.escape(symbol)+r'\s*$', asm)
    if not start or not end or end.start() <= start.end():
        return []
    # Alignment NOPs after endlabel belong to the section, not the function recipe.
    return list(INSN.finditer(asm[start.end():end.start()]))


def pattern_key(asm, symbol):
    rows = []
    for m in body_rows(asm, symbol):
        operand = re.sub(r'\s+', '', m[5].split('#')[0])
        operand = re.sub(r'\b'+re.escape(symbol)+r'\b', '__DECOMP_TARGET__', operand)
        rows.append((m[4], operand))
    return hashlib.sha256(json.dumps(rows).encode()).hexdigest() if rows else None


def definition(symbol, result, parameters, body):
    return f'{result} {symbol}({parameters}) {{\n'+''.join('    '+line+'\n' for line in body.splitlines())+'}'


def signed16(word):
    value = word & 0xFFFF
    return value - 0x10000 if value & 0x8000 else value


def relocation(row, part):
    match = re.search(r'%'+part+r'\(\s*([A-Za-z_]\w*)(?:\s*([+-])\s*(0x[0-9a-fA-F]+|[0-9]+))?\s*\)', row[5])
    if not match:
        return None
    offset = int(match[3], 0) if match[3] else 0
    return match[1], -offset if match[2] == '-' else offset


def global_leaf(rows, words, symbol):
    if len(words) != 3 or words[0] >> 26 != 15 or words[1] != RETURN:
        return None
    high, low = relocation(rows[0], 'hi'), relocation(rows[2], 'lo')
    if not high or high != low or (words[2] >> 21) & 31 != (words[0] >> 16) & 31:
        return None
    name, offset = high
    word = words[2]
    op, reg = word >> 26, (word >> 16) & 31
    if op == 9 and reg == 2:
        expr = '&'+name if not offset else f'(u8 *)&{name} + {offset}'
        return definition(symbol, 'void *', 'void', f'extern u8 {name};\nreturn {expr};')
    if op in LOADS and reg == (0 if op == 0x31 else 2):
        type_, result, width = LOADS[op]
        if offset % width:
            return None
        return definition(symbol, result, 'void', f'extern {type_} {name};\nreturn *({type_} *)((u8 *)&{name} + {offset});')
    if op in STORES and reg == (12 if op == 0x39 else 4):
        type_, width = STORES[op]
        if offset % width:
            return None
        param = 'f32' if op == 0x39 else 's32'
        return definition(symbol, 'void', f'{param} arg0', f'extern {type_} {name};\n*({type_} *)((u8 *)&{name} + {offset}) = arg0;')
    return None


def table_getter(rows, words, symbol):
    if len(words) != 5 or words[3] != RETURN:
        return None
    shift, upper, add, _, load = words
    op = load >> 26
    if (shift & 0xFFE0003F or (shift >> 16) & 31 != 4 or upper >> 26 != 15
            or add & 0xFC0007FF != 0x21 or op not in LOADS):
        return None
    temp, base, address = (shift >> 11) & 31, (upper >> 16) & 31, (add >> 11) & 31
    if ({(add >> 21) & 31, (add >> 16) & 31} != {temp, base}
            or (load >> 21) & 31 != address or (load >> 16) & 31 != (0 if op == 0x31 else 2)):
        return None
    high, low = relocation(rows[1], 'hi'), relocation(rows[4], 'lo')
    type_, result, width = LOADS[op]
    if not high or high != low or 1 << ((shift >> 6) & 31) != width or high[1] % width:
        return None
    name, offset = high
    index = 'arg0' if not offset else f'arg0 + {offset // width}'
    return definition(symbol, result, 's32 arg0', f'extern {type_} {name}[];\nreturn (({type_} *)&{name})[{index}];')


def indirect_access(words, symbol):
    float_move = len(words) in (3, 4) and words[0] == 0x44856000  # mtc1 a1,f12
    if float_move:
        words = words[1:]
    if len(words) not in (2, 3) or words[-2] != RETURN:
        return None
    base = '(u8 *)arg0'
    reg = 4
    if len(words) == 3:
        pointer = words[0]
        if pointer >> 26 != 0x23 or (pointer >> 21) & 31 != 4 or signed16(pointer) % 4:
            return None
        reg = (pointer >> 16) & 31
        if reg in (0, 5, 29, 31):
            return None
        base = f'(u8 *)*(void **)((u8 *)arg0 + {signed16(pointer)})'
    word = words[-1]
    op, target, offset = word >> 26, (word >> 16) & 31, signed16(word)
    if (word >> 21) & 31 != reg:
        return None
    if op in LOADS and not float_move and target == (0 if op == 0x31 else 2):
        type_, result, width = LOADS[op]
        if offset % width:
            return None
        return definition(symbol, result, 'void *arg0', f'return *({type_} *)({base} + {offset});')
    if op in STORES and target == (12 if float_move else 5) and (op == 0x39) == float_move:
        type_, width = STORES[op]
        if offset % width:
            return None
        param = 'f32' if float_move else 's32'
        return definition(symbol, 'void', f'void *arg0, {param} arg1', f'*({type_} *)({base} + {offset}) = arg1;')
    return None


def direct_leaf(words, symbol):
    if len(words) == 3:
        a, jump, b = words
        if jump == RETURN and a >> 16 == 0x3C02 and b >> 16 in (0x2442, 0x3442):
            value = ((a & 0xFFFF) << 16) + signed16(b) if b >> 16 == 0x2442 else ((a & 0xFFFF) << 16) | (b & 0xFFFF)
            return definition(symbol, 'u32', 'void', f'return 0x{value & 0xFFFFFFFF:08X}U;')
        return None
    if len(words) != 2 or words[0] != RETURN:
        return None
    word = words[1]
    op, base, reg, offset = word >> 26, (word >> 21) & 31, (word >> 16) & 31, signed16(word)
    if word == 0:
        return definition(symbol, 'void', 'void', '')
    if base == 4 and op in LOADS and reg == (0 if op == 0x31 else 2):
        type_, result, width = LOADS[op]
        if not offset % width:
            return definition(symbol, result, f'{type_} *arg0', f'return arg0[{offset // width}];')
    if base == 4 and op in STORES and op != 0x39 and reg == 5:
        type_, width = STORES[op]
        if not offset % width:
            return definition(symbol, 'void', f'{type_} *arg0, s32 arg1', f'arg0[{offset // width}] = arg1;')
    if base == 0 and reg == 2 and op in (9, 13, 15):
        value = offset if op == 9 else (word & 0xFFFF) << 16 if op == 15 else word & 0xFFFF
        literal = str(value) if op == 9 else f'0x{value:08X}U'
        return definition(symbol, 's32' if op == 9 else 'u32', 'void', f'return {literal};')
    if word in (0x00801025, 0x00801021):
        return definition(symbol, 's32', 's32 arg0', 'return arg0;')
    if base == 4 and reg == 2 and op in (9, 12, 13, 14):
        operator = {9: '+', 12: '&', 13: '|', 14: '^'}[op]
        value = offset if op == 9 else word & 0xFFFF
        return definition(symbol, 'u32', 'u32 arg0', f'return arg0 {operator} {value};')
    return None


@lru_cache(maxsize=64)
def top_level(source):
    clean = LEX.sub(lambda m: ' '*len(m[0]), source)
    depth, result = 0, []
    for char in clean:
        if char == '{':
            depth += 1
        elif char == '}':
            depth = max(0, depth-1)
        result.append(char if not depth else ' ')
    return ''.join(result)


def replacements(asm, symbol, source=''):
    rows = body_rows(asm, symbol)
    if not 2 <= len(rows) <= 5 or any(m[4].startswith('.') for m in rows):
        return []
    words = [int(m[3], 16) for m in rows]
    addresses = [int(m[2], 16) for m in rows]
    if addresses != list(range(addresses[0], addresses[0]+4*len(rows), 4)):
        return []
    relocated = any('%' in m[5] for m in rows)
    if relocated:
        code = global_leaf(rows, words, symbol) or table_getter(rows, words, symbol)
    else:
        code = direct_leaf(words, symbol) or indirect_access(words, symbol)
    if not code:
        return []
    # Reuse a declaration already used by this compiling source, including struct types.
    # GLOBAL_ASM data labels alone do not declare a C identifier.
    declaration = re.search(r'    extern [^;]+\b([A-Za-z_]\w*)(?:\[\])?;\n', code)
    if declaration and re.search(r'\b'+re.escape(declaration[1])+r'\b', top_level(source)):
        code = code[:declaration.start()] + code[declaration.end():]
    return [code]


def candidate_source(original, symbol, replacement):
    macros = [m for m in global_asms(original) if m['symbol'] == symbol]
    if len(macros) != 1:
        raise HarnessError('Local candidate requires one target directive')
    m = macros[0]
    result = original[:m['start']] + replacement + original[m['end']:]
    candidate_guard(original, result, symbol)
    return result.encode()


def candidates(root, function, state, source=None):
    asm = (root/function['asm']).read_text()
    key = pattern_key(asm, function['symbol'])
    seen = set()
    for row in state.db.execute('SELECT replacement,origin FROM patterns WHERE asm_key=? ORDER BY created DESC LIMIT 3', (key,)):
        code = row['replacement'].replace('__DECOMP_TARGET__', function['symbol'])
        seen.add(code)
        yield 'reuse:'+row['origin'][:12], code
    source = (root/function['source']).read_text() if source is None else source
    for code in replacements(asm, function['symbol'], source):
        if code not in seen:
            yield 'template', code


def trial_key(candidate, function):
    return hashlib.sha256(candidate + (function['asm_sha'] or '').encode()).hexdigest()


def untried_candidates(root, function, state, source=None):
    source = (root/function['source']).read_text() if source is None else source
    tried = {r[0] for r in state.db.execute('SELECT candidate_sha FROM local_trials WHERE function_id=?', (function['id'],))}
    for origin, code in candidates(root, function, state, source):
        candidate = candidate_source(source, function['symbol'], code)
        if trial_key(candidate, function) not in tried:
            yield origin, code


def local_plan(root, state, difficulty=None, function=None):
    """One cheap project pass, before any Git manifests, objdump or compilation."""
    rows = [state.get(function)] if function else [dict(r) for r in state.db.execute("""
        SELECT * FROM functions WHERE present=1 AND status='pending'
        ORDER BY size, id""")]
    if function and rows[0]['status'] != 'pending':
        raise HarnessError(f"{rows[0]['symbol']} is {rows[0]['status']}; use retry first")
    sources, found, scanned = {}, [], 0
    for f in rows:
        if (difficulty and f['difficulty'] != difficulty or not (root/f['asm']).is_file()
                or json.loads(f['features']).get('kind') != 'function'):
            continue
        scanned += 1
        if f['source'] not in sources:
            sources[f['source']] = (root/f['source']).read_text()
        source = sources[f['source']]
        choices = list(untried_candidates(root, f, state, source))
        # Full candidate/manifest checks still happen in resume_candidate before use.
        history = state.history(f['id'], 1)
        resume = bool(history and history[0]['outcome'] in ('ok', 'matched', 'interrupted')
                      and f['base_sha'] == hashlib.sha256(source.encode()).hexdigest()
                      and (root/'.decomp-agent/runs'/history[0]['id']/'source-after.c').is_file())
        if choices or resume:
            found.append({'function': f['id'], 'source': f['source'], 'symbol': f['symbol'],
                          'dependencies': f['dependencies'], 'candidates': len(choices),
                          'origins': [c[0] for c in choices], 'resume': resume})
    return {'scanned_functions': scanned, 'eligible_functions': len(found), 'plan': found}


def remember(root, state, function, replacement, commit):
    key = pattern_key((root/function['asm']).read_text(), function['symbol'])
    if key:
        template = re.sub(r'\b'+re.escape(function['symbol'])+r'\b', '__DECOMP_TARGET__', replacement)
        with state.db:
            state.db.execute('INSERT OR IGNORE INTO patterns(asm_key,replacement,origin,created) VALUES (?,?,?,unixepoch())',
                             (key, template, commit))


def seed_matches(root, state):
    for row in state.db.execute("SELECT * FROM functions WHERE status='matched' AND best_run IS NOT NULL AND best_source IS NOT NULL").fetchall():
        f = dict(row)
        before = root/'.decomp-agent/runs'/f['best_run']/'source-before.c'
        if before.exists() and (root/f['asm']).exists():
            try:
                code = candidate_guard(before.read_text(), f['best_source'].decode(), f['symbol'])
            except (HarnessError, UnicodeError):
                continue
            remember(root, state, f, code, f['commit_sha'] or f['best_run'])
