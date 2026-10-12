from __future__ import annotations

from difflib import SequenceMatcher
import re

from .common import HarnessError

SYMBOL = re.compile(r'^([0-9a-fA-F]{8}) .{7} (\S+)\t[0-9a-fA-F]{8} ?(.*)$')
NOT_DATA = {'*UND*', '*ABS*', '*COM*', '.text'}
IMMEDIATE = re.compile(r'(-?(?:0x[0-9a-fA-F]+|\d+))(?=\(\w+\)$|$)')


def local_data(dump: str):
    """Symbols defined in this object's data sections, from objdump -t."""
    result = {}
    for line in dump.splitlines():
        match = SYMBOL.match(line)
        if match and match[2] not in NOT_DATA and match[3]:
            result[match[3]] = (match[2], int(match[1], 16))
    return result


def rebase(row, data):
    """Express named local-data relocations as section+offset, like IDO emits them.

    asm-processor references `jtbl_X`/`R_X` by name, IDO references `.rodata` with
    the offset in the instruction. Both encode the same final address.
    """
    for index, reloc in enumerate(row['relocs']):
        kind, _, name = reloc.partition(' ')
        if kind not in ('R_MIPS_HI16', 'R_MIPS_LO16') or name not in data:
            continue
        section, value = data[name]
        row['relocs'][index] = f'{kind} {section}'
        if kind == 'R_MIPS_HI16':
            value = (value + 0x8000) >> 16
        if value:
            row['asm'] = IMMEDIATE.sub(lambda m: (hex if m[1].lstrip('-').startswith('0x') else str)(int(m[1], 0) + value),
                                       row['asm'], count=1)


def instructions(dump: str, symbol: str, length: int | None = None):
    """Normalize objdump addresses, retain opcodes/registers/immediates/relocations.

    `length` is the instruction count between glabel and endlabel; trailing alignment
    NOPs beyond it are section padding. This is a guidance metric only. A score of 100
    never proves a match: the trusted full linked decompressed ROM must compare too.
    """
    rows = []
    start = None
    for line in dump.splitlines():
        label = re.match(r'^([0-9a-fA-F]+) <([^>]+)>:', line.strip())
        if label:
            if label[2] == symbol:
                start = int(label[1], 16)
            elif start is not None:
                break
            continue
        if start is None:
            continue
        match = re.match(r'^\s*([0-9a-fA-F]+):\s+([0-9a-fA-F]{8})\s+(.+)', line)
        if match:
            asm = re.sub(r'\s+', ' ', match[3].strip())
            asm = re.sub(r'\s*<[^>]+>', '', asm)
            mnemonic = asm.split()[0]
            if mnemonic.startswith('b') and mnemonic not in ('break',):
                asm = re.sub(r'(?<=[, ])([0-9a-fA-F]+)$', lambda m: f'@{int(m[1], 16)-start:+x}', asm)
            rows.append({'offset': int(match[1], 16)-start, 'word': match[2].lower(), 'asm': asm, 'relocs': []})
        else:
            reloc = re.match(r'^\s*([0-9a-fA-F]+):\s+(R_MIPS_\w+)\s+(.+)', line)
            if reloc:
                offset = int(reloc[1], 16)-start
                target = next((r for r in reversed(rows) if r['offset'] == offset), None)
                if target is not None:
                    target['relocs'].append(reloc[2]+' '+reloc[3].strip())
    if not rows:
        raise HarnessError(f'objdump did not contain instructions for {symbol}')
    data = local_data(dump)
    for row in rows:
        rebase(row, data)
    if length and len(rows) > length and all(r['asm'] == 'nop' and not r['relocs'] for r in rows[length:]):
        rows = rows[:length]
    return rows


def score(reference, candidate):
    def keys(rows):
        return [(r['asm'], tuple(r['relocs'])) for r in rows]
    a, b = keys(reference), keys(candidate)
    matcher = SequenceMatcher(None, a, b, autojunk=False)
    equal = sum(block.size for block in matcher.get_matching_blocks())
    denominator = max(len(a), len(b), 1)
    differences = []
    for tag, a0, a1, b0, b1 in matcher.get_opcodes():
        if tag != 'equal':
            differences.append({'kind': tag, 'reference_index': a0, 'candidate_index': b0,
                                'expected': reference[a0:min(a1, a0+8)],
                                'actual': candidate[b0:min(b1, b0+8)],
                                'reference_count': a1-a0, 'candidate_count': b1-b0})
    return {'score': round(100*equal/denominator, 4), 'different_instructions': denominator-equal,
            'first_diff': differences[0] if differences else None, 'last_diffs': differences[-4:],
            'diffs': differences, 'object_identical': reference == candidate,
            'relocation_only': relocation_only(reference, candidate), 'exact': False}


def relocation_only(reference, candidate):
    """Only address bits may differ; the linker, never this predicate, proves equality."""
    if len(reference) != len(candidate):
        return False
    changed = False
    for expected, actual in zip(reference, candidate):
        if (expected['asm'], expected['relocs']) == (actual['asm'], actual['relocs']):
            continue
        kinds = [r.split()[0] for r in expected['relocs']]
        if len(kinds) != 1 or kinds[0] not in ('R_MIPS_HI16', 'R_MIPS_LO16'):
            return False
        if kinds != [r.split()[0] for r in actual['relocs']]:
            return False
        # The upper half contains the opcode and every register operand.
        if int(expected['word'], 16) >> 16 != int(actual['word'], 16) >> 16:
            return False
        if IMMEDIATE.sub('ADDRESS', expected['asm']) != IMMEDIATE.sub('ADDRESS', actual['asm']):
            return False
        changed = True
    return changed


def worth_rom_check(comparison):
    """The expensive full-ROM check only runs when the object can plausibly match."""
    return (comparison['different_instructions'] == 0 or comparison['score'] >= 99
            or comparison.get('relocation_only', False))


def render(comparison, limit=12):
    """Compact expected/actual listing for workers; offsets are function-relative."""
    lines = [f"score {comparison['score']:.2f}, {comparison['different_instructions']} differing instructions"]
    for diff in comparison['diffs'][:limit]:
        lines.append(f"- {diff['kind']} at instruction {diff['reference_index']}"
                     f" (expected {diff['reference_count']}, got {diff['candidate_count']}):")
        expected, actual = diff['expected'][:4], diff['actual'][:4]
        for i in range(max(len(expected), len(actual))):
            left = expected[i] if i < len(expected) else None
            right = actual[i] if i < len(actual) else None
            show = lambda r: (r['asm'] + (' [' + ', '.join(r['relocs']) + ']' if r['relocs'] else '')) if r else '-'
            lines.append(f'    {show(left):<44} | {show(right)}')
    if len(comparison['diffs']) > limit:
        lines.append(f"... {len(comparison['diffs']) - limit} more difference blocks")
    return '\n'.join(lines)
