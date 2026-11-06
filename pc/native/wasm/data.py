"""Converts the N64 link's asm data files (spimdisasm output) into one LLVM IR module.

Under the ILP32 model the game's data keeps its N64 layout, so every asm data
file becomes one packed block with its labels as aliases at their N64 offsets.
Cross-symbol arithmetic inside a file keeps working. Words that name a symbol
become real (32-bit) pointers; everything else keeps its big-endian value,
stored little-endian per element: the C declaration's element width where one
exists (irtypes.py), else the directive's.
"""
import re

import irtypes

ITEM = re.compile(r'^\s*/\*\s*([0-9A-Fa-f ]+?)\s*\*/\s*\.(word|short|half|byte|float|double|asciz|ascii|space)\s+(.*?)\s*$')
LABEL = re.compile(r'^\s*(?:dlabel|glabel|jlabel)\s+(\S+)')
SECTION = re.compile(r'^\s*\.section\s+\.?(\w+)')
SYMREF = re.compile(r'^([A-Za-z_.$][\w.$]*)(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?$')
ESCAPES = {'n': 10, 't': 9, 'r': 13, '0': 0, '\\': 92, '"': 34, "'": 39, 'a': 7, 'b': 8, 'f': 12, 'v': 11}


def decode_string(s):
    """Bytes of a GNU as string literal (with its quotes)."""
    s = s.strip()
    assert s[0] == '"' and s[-1] == '"', s
    s, out, i = s[1:-1], bytearray(), 0
    while i < len(s):
        c = s[i]
        if c != '\\':
            out += c.encode('latin-1')
            i += 1
            continue
        n = s[i + 1]
        if n == 'x':
            m = re.match(r'[0-9A-Fa-f]{1,2}', s[i + 2:])
            out.append(int(m.group(0), 16))
            i += 2 + len(m.group(0))
        elif n in '01234567':
            m = re.match(r'[0-7]{1,3}', s[i + 1:])
            out.append(int(m.group(0), 8) & 0xFF)
            i += 1 + len(m.group(0))
        else:
            out.append(ESCAPES[n])
            i += 2
    return bytes(out)


def parse_file(path):
    """Yields (section, labels {name: addr}, items [(addr, size, kind, value)])."""
    blocks, section, pending, last_end = [], None, [], None
    cur = None

    def flush():
        nonlocal cur
        if cur and (cur[1] or cur[2]):
            blocks.append(cur)
        cur = None

    for line in open(path, encoding='utf-8', errors='replace'):
        m = SECTION.match(line)
        if m:
            flush()
            section, last_end = m.group(1), None
            cur = (section, {}, [])
            continue
        m = LABEL.match(line)
        if m:
            pending.append(m.group(1))
            continue
        if '.incbin' in line:
            # RSP microcode: the HLE renderer never reads it, so the labels only need distinct addresses.
            base = last_end if last_end is not None else 0
            cur[2].append((base, 16, 'space', 16))
            for name in pending:
                cur[1][name] = base
            pending, last_end = [], base + 16
            continue
        m = ITEM.match(line)
        if not m:
            continue
        fields, kind, arg = m.group(1).split(), m.group(2), m.group(3)
        if kind == 'space':
            addr, raw = int(fields[0], 16), None
        else:
            addr, raw = int(fields[1], 16), (fields[2] if len(fields) > 2 else None)
        if kind == 'space':
            size, value = int(arg, 0), int(arg, 0)
        elif kind in ('asciz', 'ascii'):
            value = decode_string(arg) + (b'\0' if kind == 'asciz' else b'')
            size = len(value)
        elif kind == 'word':
            size, value = 4, (arg, raw)
        elif kind == 'float':
            size, value = 4, ('0x' + raw, raw)
        elif kind == 'double':
            size, value = 8, int(raw, 16)
        elif kind in ('short', 'half'):
            size, value, kind = 2, int(arg, 0) & 0xFFFF, 'short'
        else:
            size, value = 1, int(arg, 0) & 0xFF
        for name in pending:
            cur[1][name] = addr
        pending, last_end = [], addr + size
        cur[2].append((addr, size, kind, value))
    if pending and cur is not None:
        for name in pending:
            cur[1][name] = last_end if last_end is not None else 0
    flush()
    return blocks


def q(name):
    return '@"%s"' % name


class Fields:
    """Packed struct fields; runs of plain words/bytes are merged into arrays."""

    def __init__(self):
        self.types, self.values = [], []
        self.run_kind, self.run = None, []

    def end_run(self):
        if not self.run:
            return
        if self.run_kind == 'i8':
            self.types.append('[%d x i8]' % len(self.run))
            self.values.append('c"%s"' % ''.join('\\%02X' % b for b in self.run))
        else:
            self.types.append('[%d x %s]' % (len(self.run), self.run_kind))
            self.values.append('[%s]' % ', '.join('%s %d' % (self.run_kind, v) for v in self.run))
        self.run_kind, self.run = None, []

    def plain(self, kind, value):
        if self.run_kind != kind:
            self.end_run()
            self.run_kind = kind
        self.run.append(value)

    def zeros(self, n):
        self.end_run()
        self.types.append('[%d x i8]' % n)
        self.values.append('zeroinitializer')

    def pointer(self, expr):
        self.end_run()
        self.types.append('ptr')
        self.values.append(expr)


def to_signed(v, bits):
    v &= (1 << bits) - 1
    return v - (1 << bits) if v >> (bits - 1) else v


def generate(files, skip, is_function, out_path, alias, ctypes):
    """Writes the IR module; returns (defined names, referenced names, unknown words)."""
    lines = ['target datalayout = "e-m:e-p:32:32-p10:8:8-p20:8:8-i64:64-i128:128-n32:64-S128-ni:1:10:20"',
             'target triple = "wasm32-unknown-unknown"', '']
    defined, refs, unresolved = set(), set(), []
    labels_all = {}
    parsed = []
    for path in files:
        for section, labels, items in parse_file(path):
            parsed.append((path, section, labels, items))
            labels_all.update(labels)
    for bi, (path, section, labels, items) in enumerate(parsed):
        if (not items and not labels) or (section == 'text' and not items):
            continue  # code (handwritten asm functions have C versions)
        starts = [a for a, *_ in items] + list(labels.values())
        base = min(starts)
        end = max([a + s for a, s, *_ in items] + list(labels.values()))
        blk = '__bt_data_%d' % bi
        if section == 'bss' or all(k == 'space' for _, _, k, _ in items):
            size = max(end - base, 1)
            body = '[%d x i8] zeroinitializer' % size
        else:
            # Big-endian bytes plus the width of each element: the directive's, or the C type's.
            n = end - base
            raw, width, zero, syms = bytearray(n), [1] * n, [False] * n, {}
            for addr, size, kind, value in sorted(items, key=lambda x: x[0]):
                o = addr - base
                if kind == 'space':
                    zero[o:o + size] = [True] * size
                    continue
                if kind in ('asciz', 'ascii'):
                    raw[o:o + len(value)] = value
                    continue
                if kind in ('word', 'float'):
                    arg, rawhex = value
                    m = SYMREF.match(arg)
                    sym = m and alias.get(m.group(1), m.group(1))
                    off = int(m.group(2), 0) if m and m.group(2) else 0
                    if sym and not sym.startswith('.') and off % 4 == 0:
                        refs.add(sym)
                        syms[addr] = 'getelementptr (i8, ptr %s, i32 %d)' % (q(sym), off) if off else q(sym)
                        continue
                    if sym:
                        unresolved.append((path, sym))
                    value = int(rawhex if rawhex else arg, 16 if rawhex else 0)
                raw[o:o + size] = (value & ((1 << 8 * size) - 1)).to_bytes(size, 'big')
                width[o:o + size] = [size] + [0] * (size - 1)
            sym_byte = [False] * n
            for a in syms:
                sym_byte[a - base:a - base + 4] = [True] * 4
            names = sorted(labels.items(), key=lambda x: x[1])
            for k, (name, addr) in enumerate(names):
                if name not in ctypes:
                    continue
                # A C array runs over labels the C code never names (splat's guesses).
                stop = next((a for nm, a in names[k + 1:] if nm in ctypes and a > addr), end)
                for a, size in sorted(irtypes.label_units(ctypes[name], addr, stop).items()):
                    o = a - base
                    if o < 0 or o + size > n or any(zero[o:o + size]) or any(sym_byte[o:o + size]):
                        continue
                    p = o
                    while width[p] == 0:  # split the element this one starts inside
                        p -= 1
                    for q_ in range(p, max(p + width[p], o + size)):
                        width[q_] = 1
                    width[o:o + size] = [size] + [0] * (size - 1)
            f, o = Fields(), 0
            while o < n:
                if base + o in syms:
                    f.pointer(syms[base + o])
                    o += 4
                elif zero[o]:
                    z = o
                    while z < n and zero[z] and base + z not in syms:
                        z += 1
                    f.zeros(z - o)
                    o = z
                else:
                    size = width[o] or 1
                    v = int.from_bytes(raw[o:o + size], 'big')
                    f.plain('i%d' % (8 * size), v if size == 1 else to_signed(v, 8 * size))
                    o += size
            f.end_run()
            body = '<{ %s }> <{ %s }>' % (', '.join(f.types), ', '.join('%s %s' % tv for tv in zip(f.types, f.values)))
        align = 16
        while align > 1 and base % align:
            align //= 2
        lines.append('%s = global %s, align %d ; %s' % (q(blk), body, align, path))
        for name, addr in sorted(labels.items(), key=lambda x: x[1]):
            if name in skip:
                continue
            defined.add(name)
            off = addr - base
            target = 'ptr getelementptr (i8, ptr %s, i32 %d)' % (q(blk), off) if off else 'ptr ' + q(blk)
            lines.append('%s = alias i8, %s' % (q(name), target))
    lines.append('')
    for sym in sorted(refs - defined):
        lines.append('declare void %s()' % q(sym) if is_function(sym) else '%s = external global i8' % q(sym))
    open(out_path, 'w').write('\n'.join(lines) + '\n')
    return defined, refs, unresolved
