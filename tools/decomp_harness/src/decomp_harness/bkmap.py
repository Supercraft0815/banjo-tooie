"""Banjo-Kazooie analogues of Banjo-Tooie functions.

`python3 -m decomp_harness.bkmap BK_ROM BK_REPO [BT_REPO]` compares the machine code of
both games and writes tools/decomp_harness/bk_map.json: BT function id -> BK file, BK
function, opcode similarity, evidence. `bk_context` turns that table into worker context
(the analogue's C source and the BK signatures of mapped callees), read live from the BK
decomp repository. Nothing from BK is copied into this repository except names.

BK code comes from the ROM because the finished BK decomp has no asm/ directory; BT code
comes from the decompressed ROM and the linker map of a built workspace.
"""
from __future__ import annotations

import collections
from difflib import SequenceMatcher
from functools import lru_cache
import json
from pathlib import Path
import re
import struct
import sys
import zlib

TABLE = 'tools/decomp_harness/bk_map.json'
BK_CODE_START = 0xF19250          # first compressed code segment in the BK US 1.0 ROM
BK_VRAM = {'core1': 0x8023DA20, 'core2': 0x80286F90}   # every level overlay: 0x803863F0
MASK_IMM = {9, 13, 15} | set(range(32, 47)) | {49, 53, 57, 61}
BRANCHES = {4, 5, 6, 7, 20, 21, 22, 23}
DEFINITION = re.compile(r'^(?![ \t#}])(?!typedef|extern|struct\s+\w+\s*\{|enum|union)[^;{}()=\n]*?\b(\w+)\s*\(([^;{}]*?)\)\s*\{', re.M)


def loose(word):
    """Mnemonic only: what survives changed registers, struct offsets and addresses."""
    op = word >> 26
    if op == 0:
        return word & 0xFC00003F
    if op == 1:
        return word & 0xFC1F0000
    if op in (16, 17):
        return word & 0xFFE0003F if (word >> 21) & 31 >= 16 else word & 0xFFE00000
    return word & 0xFC000000


def split_functions(words):
    """(start index, words) per function: `jr $ra` ends one unless a branch reaches past it."""
    chunks, current, begin, reach, j = [], [], 0, -1, 0
    while j < len(words):
        if not current:
            begin = j
        word = words[j]; op = word >> 26; current.append(word)
        if op in BRANCHES or (op == 1 and (word >> 16) & 31 in (0, 1, 2, 3, 16, 17, 18, 19)) or (op == 17 and (word >> 21) & 31 == 8):
            offset = word & 0xFFFF
            reach = max(reach, j+1+(offset-0x10000 if offset & 0x8000 else offset))
        if word == 0x03E00008 and j+1 < len(words) and reach <= j+1:
            current.append(words[j+1]); j += 1
            chunks.append((begin, current)); current, reach = [], -1
            while j+1 < len(words) and words[j+1] == 0:
                j += 1
        j += 1
    return chunks


@lru_cache(maxsize=256)
def definitions(path):
    """[(name, source text)] of the top-level function definitions of a C file, in order."""
    raw = Path(path).read_text(errors='replace')
    def blank(match):   # comments and literals -> spaces, so braces and layout stay countable
        text = match[0]
        return re.sub(r'[^\n]', ' ', text) if text[0] == '/' else text[0] + re.sub(r'[^\n]', ' ', text[1:-1]) + text[-1]
    text = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', blank, raw, flags=re.S)
    found = []
    for match in DEFINITION.finditer(text):
        if text.count('{', 0, match.start()) != text.count('}', 0, match.start()):
            continue
        depth, end = 0, match.end()-1
        while end < len(text):
            depth += (text[end] == '{') - (text[end] == '}')
            if depth == 0:
                break
            end += 1
        found.append((match[1], raw[match.start():end+1]))
    return found


def bk_functions(rom_path, bk):
    """Every BK C function: file, address, words and, where the order is certain, its name."""
    import yaml
    rom = bytearray(Path(rom_path).read_bytes())
    if rom[:4] == b'\x37\x80\x40\x12':
        rom[0::2], rom[1::2] = rom[1::2], rom[0::2]
    if rom[:4] != b'\x80\x37\x12\x40':
        raise SystemExit('BK ROM must be .z64 or byte-swapped .n64/.v64')
    rom = bytes(rom)
    blobs, position = [], BK_CODE_START   # Rare zip: 0x1172, u32 size, raw deflate
    while (position := rom.find(b'\x11\x72', position)) >= 0:
        size = struct.unpack_from('>I', rom, position+2)[0]
        if 0x10 <= size < 0x200000:
            try:
                data = zlib.decompressobj(-15).decompress(rom[position+6:position+6+size+4096])
                if len(data) >= size:
                    blobs.append(data[:size])
            except zlib.error:
                pass
        position += 2
    functions = []
    for segment in yaml.safe_load((bk/'decompressed.us.v10.yaml').read_text())['segments']:
        if not isinstance(segment, dict) or segment.get('type') != 'code' or segment['start'] < BK_CODE_START:
            continue
        subs = [(s[0], s[1], s[2] if len(s) > 2 else '') for s in segment['subsegments'] if isinstance(s, list) and len(s) > 1]
        last = max(i for i, s in enumerate(subs) if s[1] in ('c', 'asm', 'hasm', 'textbin'))
        size = subs[last+1][0]-segment['start']
        code = next((b for b in blobs if len(b) == size), None) or next(b for b in blobs if 0 <= len(b)-size < 16)
        vram = BK_VRAM.get(segment['name'], 0x803863F0)
        bounds = [s[0]-segment['start'] for s in subs[:last+1]] + [len(code)]
        for (_, kind, name), a, b in zip(subs[:last+1], bounds, bounds[1:]):
            path = bk/'src'/segment.get('dir', segment['name'])/(name+'.c')
            if kind != 'c' or not path.is_file():
                continue
            chunks = split_functions(struct.unpack(f'>{(b-a)//4}I', code[a:a+(b-a)//4*4]))
            defs = definitions(str(path))
            # Names that carry their own address pin the order where the counts disagree.
            at = {vram+a+begin*4: i for i, (begin, _) in enumerate(chunks)}
            anchors = [(d, at[int(m[1], 16)]) for d, (n, _) in enumerate(defs)
                       if (m := re.search(r'_(80[0-9A-Fa-f]{6})$', n)) and int(m[1], 16) in at]
            named = {}
            if len(defs) == len(chunks) and all(d == c for d, c in anchors):
                named = {i: i for i in range(len(defs))}
            else:
                points = [(-1, -1), *anchors, (len(defs), len(chunks))]
                for (d0, c0), (d1, c1) in zip(points, points[1:]):
                    if d0 >= 0:
                        named[c0] = d0
                    if d1-d0 == c1-c0:
                        named.update({c0+k: d0+k for k in range(1, d1-d0)})
            for i, (begin, words) in enumerate(chunks):
                functions.append({'segment': segment['name'], 'file': f"{segment.get('dir', segment['name'])}/{name}",
                                  'address': vram+a+begin*4, 'words': words, 'name': defs[named[i]][0] if i in named else None})
    return functions


def bt_functions(root):
    """Every BT function linked from src/: id, segment, address and words."""
    maps = sorted([*root.glob('.decomp-agent/build-cache/build-*/build/us/banjotooie_decompressed.map'),
                   root/'build/us/banjotooie_decompressed.map'], key=lambda p: p.stat().st_mtime if p.is_file() else 0)
    if not maps[-1].is_file():
        raise SystemExit('No linker map found; build the repository or run the harness once')
    rom = (root/'decompressed.us.z64').read_bytes()
    section = re.compile(r'^\.(\S+)\s+0x([0-9a-f]+)\s+0x([0-9a-f]+) load address 0x([0-9a-f]+)')
    text = re.compile(r'^ \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+) build/us/(src/\S+)\.o')
    symbol = re.compile(r'^\s+0x([0-9a-f]+)\s+([A-Za-z_]\w*)$')
    functions, segment, current = [], None, None
    def flush():
        if not current:
            return
        start, size, source, symbols = current
        symbols = sorted(set(symbols))
        for (address, name), end in zip(symbols, [a for a, _ in symbols[1:]] + [start+size]):
            offset = segment[2] + address - segment[1]
            words = list(struct.unpack(f'>{(end-address)//4}I', rom[offset:offset+(end-address)//4*4]))
            while words and words[-1] == 0:
                words.pop()
            functions.append({'id': f'{source}::{name}', 'source': source, 'segment': segment[0], 'address': address, 'words': words})
    for line in maps[-1].read_text().splitlines():
        if match := section.match(line):
            flush(); current = None; segment = (match[1], int(match[2], 16), int(match[4], 16))
        elif match := text.match(line):
            flush(); current = (int(match[1], 16), int(match[2], 16), match[3], [])
        elif current and (match := symbol.match(line)):
            if current[0] <= int(match[1], 16) < current[0]+current[1]:
                current[3].append((int(match[1], 16), match[2]))
        elif current and not line.startswith('  '):
            flush(); current = None
    flush()
    return functions


def align(bt, bk):
    """{bt index: (bk index, similarity, evidence)} from three independent signals:
    similar (near-identical opcode sequence), position (same place in the aligned file),
    call (callee of an already aligned pair). A lone weak resemblance is not recorded."""
    for f in bt + bk:
        f['loose'] = [loose(w) for w in f['words']]
    grams = collections.defaultdict(set)
    for j, f in enumerate(bk):
        for k in range(len(f['loose'])-3):
            grams[tuple(f['loose'][k:k+4])].add(j)
    grams = {g: v for g, v in grams.items() if len(v) <= 60}   # drop prologue/epilogue boilerplate
    cache = {}
    def similarity(i, j):
        if (i, j) not in cache:
            cache[i, j] = SequenceMatcher(None, bt[i]['loose'], bk[j]['loose'], autojunk=False).ratio()
        return cache[i, j]
    evidence = collections.defaultdict(lambda: collections.defaultdict(set))
    votes = collections.defaultdict(collections.Counter)
    for i, f in enumerate(bt):
        n = len(f['words'])
        if n < 16:
            continue
        shared = collections.Counter(j for k in range(n-3) for j in grams.get(tuple(f['loose'][k:k+4]), ()))
        ranked = sorted(((similarity(i, j), j) for j in
                         [j for j, _ in shared.most_common(80) if abs(len(bk[j]['words'])-n) <= max(6, n//3)][:8]), reverse=True)
        if ranked and ranked[0][0] >= 0.9 and (len(ranked) < 2 or ranked[1][0] < ranked[0][0]-0.03):
            evidence[i][ranked[0][1]].add('similar'); votes[f['source']][bk[ranked[0][1]]['file']] += 1
    by_source, by_file = collections.defaultdict(list), collections.defaultdict(list)
    for i, f in enumerate(bt):
        by_source[f['source']].append(i)
    for j, f in enumerate(bk):
        by_file[f['file']].append(j)
    for source, counter in votes.items():
        for file, count in counter.items():
            if count < 2:
                continue
            A, B = by_source[source], by_file[file]   # order-preserving alignment of two files
            score = [[0.0]*(len(B)+1) for _ in range(len(A)+1)]
            for x in range(1, len(A)+1):
                for y in range(1, len(B)+1):
                    near = abs(len(bt[A[x-1]]['words'])-len(bk[B[y-1]]['words'])) <= max(8, len(bt[A[x-1]]['words']))
                    score[x][y] = max(score[x-1][y-1] + (similarity(A[x-1], B[y-1]) if near else 0.0) - 0.25, score[x-1][y], score[x][y-1])
            x, y = len(A), len(B)
            while x and y:
                if score[x][y] == score[x-1][y]:
                    x -= 1
                elif score[x][y] == score[x][y-1]:
                    y -= 1
                else:
                    if cache.get((A[x-1], B[y-1]), 0.0) >= 0.45:
                        evidence[A[x-1]][B[y-1]].add('position')
                    x -= 1; y -= 1
    core = {f['address']: i for i, f in enumerate(bt) if f['segment'] in ('boot', 'core1', 'core2')}
    bk_at = {(f['segment'] if f['segment'] not in BK_VRAM else '', f['address']): j for j, f in enumerate(bk)}
    for _ in range(4):
        calls = collections.defaultdict(collections.Counter)
        for i, candidates in list(evidence.items()):
            for j in list(candidates):
                if similarity(i, j) < 0.8:
                    continue
                for tag, a0, a1, b0, _ in SequenceMatcher(None, bt[i]['loose'], bk[j]['loose'], autojunk=False).get_opcodes():
                    for k in range(a1-a0 if tag == 'equal' else 0):
                        w, v = bt[i]['words'][a0+k], bk[j]['words'][b0+k]
                        if w >> 26 == 3 and v >> 26 == 3:
                            target = 0x80000000 | (v & 0x3FFFFFF) << 2
                            ti, tj = core.get(0x80000000 | (w & 0x3FFFFFF) << 2), bk_at.get(('', target), bk_at.get((bk[j]['segment'], target)))
                            if ti is not None and tj is not None:
                                calls[ti][tj] += 1
        new = 0
        for ti, counter in calls.items():
            (tj, top), *rest = counter.most_common(2)
            if top >= 2 and (not rest or rest[0][1]*3 <= top) and 'call' not in evidence[ti][tj]:
                evidence[ti][tj].add('call'); new += 1
        if not new:
            break
    result = {}
    for i, candidates in evidence.items():
        candidates = {j: kinds for j, kinds in candidates.items() if kinds}
        if candidates:
            j = max(candidates, key=lambda j: (len(candidates[j]), similarity(i, j)))
            result[i] = (j, similarity(i, j), sorted(candidates[j]))
    return result


def build(rom, bk, root):
    bt, bkf = bt_functions(root), bk_functions(rom, bk)
    table = {bt[i]['id']: [bkf[j]['file'], bkf[j]['name'], round(ratio, 3), '+'.join(kinds)]
             for i, (j, ratio, kinds) in sorted(align(bt, bkf).items()) if bkf[j]['name']}
    (root/TABLE).write_text('{\n' + ',\n'.join(f'{json.dumps(k)}: {json.dumps(v)}' for k, v in sorted(table.items())) + '\n}\n')
    return table


@lru_cache(maxsize=4)
def load(path):
    try:
        table = json.loads(Path(path).read_text())
    except OSError:
        return None
    return table, {key.partition('::')[2]: value for key, value in table.items()}


def bk_context(root, bkroot, identity, calls, limit=5000):
    """Worker context from the table, or None without one (the caller then searches blindly)."""
    loaded = load(str(root/TABLE))
    if loaded is None:
        return None
    table, by_symbol = loaded
    def source(entry):
        path = bkroot/'src'/(entry[0]+'.c')
        return next((text for name, text in definitions(str(path)) if name == entry[1]), '') if path.is_file() else ''
    parts = []
    if (entry := table.get(identity)) and (text := source(entry)):
        parts.append(f"Banjo-Kazooie analogue {entry[1]} (src/{entry[0]}.c, opcode similarity {entry[2]:.2f}, matched there with the\n"
                     f"same compiler). Port it: keep its control flow and expression order, replace names, types and struct\n"
                     f"offsets by what this file and the target ASM use. The target ASM decides where they differ.\n{text[:limit]}\n")
    signatures = [f"{callee} = BK {entry[1]} ({entry[2]:.2f}): {re.sub(r'\s+', ' ', text[:text.index('{')]).strip()}"
                  for callee in calls if (entry := by_symbol.get(callee)) and (text := source(entry))]
    if signatures:
        parts.append('Callees with a Banjo-Kazooie counterpart (opcode similarity): its argument and return types\n' + '\n'.join(signatures[:20]) + '\n')
    return ''.join(parts)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        raise SystemExit(__doc__)
    repository = Path(sys.argv[3] if len(sys.argv) > 3 else '.').resolve()
    entries = build(sys.argv[1], Path(sys.argv[2]).expanduser().resolve(), repository)
    print(f'{len(entries)} BT functions mapped -> {repository/TABLE}')
