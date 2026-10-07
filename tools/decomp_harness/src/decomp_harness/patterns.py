"""Small, deliberately conservative C generators. A candidate is never a match."""
import hashlib
import json
import re

from .common import HarnessError
from .guard import candidate_guard
from .scanner import INSN, global_asms


def pattern_key(asm, symbol):
    rows = []
    for m in INSN.finditer(asm):
        operand = re.sub(r'\s+', '', m[5].split('#')[0])
        operand = re.sub(r'\b'+re.escape(symbol)+r'\b', '__DECOMP_TARGET__', operand)
        rows.append((m[4], operand))
    return hashlib.sha256(json.dumps(rows).encode()).hexdigest() if rows else None


def replacements(asm, symbol):
    """Decode only straight-line integer/float loads, stores and constants.

    No relocation-bearing instructions, data, branches or inferred structures.
    ponytail: this tiny recognizer intentionally leaves complex MIPS to a model.
    """
    rows = list(INSN.finditer(asm))
    if '%' in asm or not 2 <= len(rows) <= 3 or any(m[4].startswith('.') for m in rows):
        return []
    words = [int(m[3], 16) for m in rows]
    addresses = [int(m[2], 16) for m in rows]
    if addresses != list(range(addresses[0], addresses[0]+4*len(rows), 4)):
        return []
    ret, params, body = None, 'void', ''
    if len(words) == 3:
        # lui v0,hi; jr ra; addiu/ori v0,v0,lo
        a, jump, b = words
        if jump == 0x03E00008 and a >> 16 == 0x3C02 and b >> 16 in (0x2442, 0x3442):
            low = b & 0xFFFF
            if b >> 16 == 0x2442 and low & 0x8000:
                low -= 0x10000
            value = ((a & 0xFFFF) << 16) + low if b >> 16 == 0x2442 else ((a & 0xFFFF) << 16) | low
            ret, body = 'u32', f'return 0x{value & 0xFFFFFFFF:08X}U;'
    elif words[0] == 0x03E00008:
        word = words[1]
        op, base, register = word >> 26, (word >> 21) & 31, (word >> 16) & 31
        immediate = word & 0xFFFF
        offset = immediate - 0x10000 if immediate & 0x8000 else immediate
        loads = {0x20: ('s8', 's32', 1), 0x24: ('u8', 'u32', 1),
                 0x21: ('s16', 's32', 2), 0x25: ('u16', 'u32', 2),
                 0x23: ('s32', 's32', 4), 0x31: ('f32', 'f32', 4)}
        stores = {0x28: ('s8', 1), 0x29: ('s16', 2), 0x2B: ('s32', 4)}
        if word == 0:
            ret = 'void'
        elif base == 4 and op in loads and register == (0 if op == 0x31 else 2):
            type_, ret, width = loads[op]
            if offset % width:
                return []
            params, body = f'{type_} *arg0', f'return arg0[{offset // width}];'
        elif base == 4 and op in stores and register == 5:
            type_, width = stores[op]
            if offset % width:
                return []
            ret, params, body = 'void', f'{type_} *arg0, s32 arg1', f'arg0[{offset // width}] = arg1;'
        elif base == 0 and register == 2 and op in (9, 13, 15):
            ret = 's32' if op == 9 else 'u32'
            value = offset if op == 9 else immediate << 16 if op == 15 else immediate
            body = f'return {value};' if op == 9 else f'return 0x{value:08X}U;'
        elif word in (0x00801025, 0x00801021):
            ret, params, body = 's32', 's32 arg0', 'return arg0;'
    if ret is None:
        return []
    return [f'{ret} {symbol}({params}) {{\n' + (f'    {body}\n' if body else '') + '}']


def candidate_source(original, symbol, replacement):
    macros = [m for m in global_asms(original) if m['symbol'] == symbol]
    if len(macros) != 1:
        raise HarnessError('Local candidate requires one target directive')
    m = macros[0]
    result = original[:m['start']] + replacement + original[m['end']:]
    candidate_guard(original, result, symbol)
    return result.encode()


def candidates(root, function, state):
    asm = (root/function['asm']).read_text()
    key = pattern_key(asm, function['symbol'])
    seen = set()
    for row in state.db.execute('SELECT replacement,origin FROM patterns WHERE asm_key=? ORDER BY created DESC LIMIT 3', (key,)):
        code = row['replacement'].replace('__DECOMP_TARGET__', function['symbol'])
        seen.add(code)
        yield 'reuse:'+row['origin'][:12], code
    for code in replacements(asm, function['symbol']):
        if code not in seen:
            yield 'template', code


def remember(root, state, function, replacement, commit):
    key = pattern_key((root/function['asm']).read_text(), function['symbol'])
    if key:
        template = re.sub(r'\b'+re.escape(function['symbol'])+r'\b', '__DECOMP_TARGET__', replacement)
        with state.db:
            state.db.execute('INSERT OR IGNORE INTO patterns(asm_key,replacement,origin,created) VALUES (?,?,?,unixepoch())',
                             (key, template, commit))


def seed_matches(root, state):
    """Learn previous validated matches too; reused code still undergoes all checks."""
    for row in state.db.execute("SELECT * FROM functions WHERE status='matched' AND best_run IS NOT NULL AND best_source IS NOT NULL").fetchall():
        f = dict(row)
        before = root/'.decomp-agent/runs'/f['best_run']/'source-before.c'
        if before.exists() and (root/f['asm']).exists():
            try:
                code = candidate_guard(before.read_text(), f['best_source'].decode(), f['symbol'])
            except (HarnessError, UnicodeError):
                continue
            remember(root, state, f, code, f['commit_sha'] or f['best_run'])
