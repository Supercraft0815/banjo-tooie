from __future__ import annotations

from difflib import SequenceMatcher
import re

from .common import HarnessError


def instructions(dump: str, symbol: str):
    """Normalize objdump addresses, retain opcodes/registers/immediates/relocations.

    This is a guidance metric only. A score of 100 never proves a match: the
    trusted full linked decompressed ROM must compare byte for byte as well.
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
            'diffs': differences, 'object_identical': reference == candidate, 'exact': False}
