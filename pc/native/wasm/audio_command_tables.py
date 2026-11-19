#!/usr/bin/env python3
"""Propose line-neutral C declarations for audio streams used by func_800C4350.

Run from a split checkout with its normal data_to_c.py dependencies. The patch
contains just reader/declaration edits. Run data_to_c.py apply and the normal
IDO, ROM, IR and trace checks separately on each proposed module.
"""
import argparse
from collections import defaultdict
import difflib
import json
import os
from pathlib import Path
import re
import struct
import sys

# Argument index through which each checked wrapper supplies the command list.
READERS = {
    "func_800C4350": 2,
    "func_800C4AF0": 1,
    "_subaddieaudioquick_entrypoint_2": 2,
    "_subaddieaudioquick_entrypoint_3": 2,
    "_subaddieaudioquick_entrypoint_4": 2,
    "_subaddieaudioloop_entrypoint_4": 3,
    "_subaddieaudioloop_entrypoint_5": 4,
    "_subaddieaudioloop_entrypoint_6": 4,
    "_subaddieaudioloop_entrypoint_7": 3,
}
# 1E9A960.c uses the command's low eight bits and a signed halfword cursor.
# 3 and 4 return immediately. Accept only lists ending in the ordinary zero.
OPERANDS = {
    1: 2, 2: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 1, 11: 3, 12: 4,
    13: 2, 14: 3, 15: 0, 16: 0, 17: 0, 18: 0, 19: 1, 20: 0, 21: 3, 22: 1,
    23: 3, 24: 0, 25: 2, 26: 2, 27: 0, 28: 0, 29: 0, 30: 0, 31: 0,
    32: 0, 33: 0, 34: 0, 35: 6, 36: 0,
}
SYMBOL = r"D_[0-9A-Fa-f]{8}_\w+"
NAME = re.compile(r"\b(" + SYMBOL + r")\b")
DECL = re.compile(r"extern\s+(?:[su](?:8|16|32)|f32)\s+(" + SYMBOL + r")(?:\s*\[\s*\d*\s*\])?\s*;")


def decode(data):
    if len(data) % 2:
        return None
    words = [w for w, in struct.iter_unpack(">H", data)]
    pos = 0
    while pos < len(words):
        code = words[pos]
        if code == 0:
            return pos + 1 if not any(words[pos + 1:]) else None
        operands = OPERANDS.get(code & 255)
        if operands is None:
            return None
        pos += 1 + operands
    return None


def site_index(root):
    sites = defaultdict(set)
    suffixes = {".c", ".cc", ".cpp", ".h", ".hpp", ".inc", ".s", ".S"}
    for folder in ("src", "include", "pc/native", "asm"):
        for path in (root / folder).rglob("*"):
            if path.suffix not in suffixes or not path.is_file():
                continue
            if {"nonmatchings", "matchings", "third_party"} & set(path.relative_to(root).parts):
                continue
            text = path.read_text(errors="replace")
            for symbol in set(NAME.findall(text)):
                sites[symbol].add(path)
            # Include assembly bodies that this build actually includes. Most
            # files in asm/{nonmatchings,matchings} only preserve old output.
            if path.suffix in {".c", ".inc"}:
                for include in re.findall(r'GLOBAL_ASM\(\s*"([^"]+)"', text):
                    body = root / include
                    if body.is_file():
                        for symbol in set(NAME.findall(body.read_text(errors="replace"))):
                            sites[symbol].add(body)
    return sites


def reader_args(source, data_to_c):
    ci = data_to_c.ci
    tu = ci.Index.create().parse(str(source), data_to_c.offsets.ARGS)
    # UTF-8 byte extents from libclang are used with byte strings.
    content = source.read_bytes()
    args = defaultdict(list)
    for cur in tu.cursor.walk_preorder():
        if cur.kind != data_to_c.K.CALL_EXPR or cur.spelling not in READERS:
            continue
        if not cur.location.file or Path(cur.location.file.name) != source:
            continue
        pos = READERS[cur.spelling]
        arglist = list(cur.get_arguments())
        if len(arglist) <= pos:
            continue
        arg = arglist[pos]
        start, end = arg.extent.start.offset, arg.extent.end.offset
        raw = content[start:end].decode()
        m = re.fullmatch(r"&?\s*(" + SYMBOL + ")", raw)
        if not m or not cur.referenced:
            continue
        params = list(cur.referenced.get_arguments())
        if len(params) <= pos:
            continue
        ty = params[pos].type.get_canonical()
        if ty.kind == data_to_c.T.POINTER:
            ty = ty.get_pointee()
        elif ty.kind in {data_to_c.T.INCOMPLETEARRAY, data_to_c.T.CONSTANTARRAY}:
            ty = ty.element_type
        else:
            continue
        casts = {"void": "", "short": "", "int": "(s32 *)", "long": "(s32 *)",
                 "unsigned int": "(u32 *)", "unsigned long": "(u32 *)"}
        if ty.spelling not in casts:
            continue
        args[m[1]].append((start, end, casts[ty.spelling] + m[1], cur.spelling))
    return args


def candidates(source, asm, sites, d):
    labels, image, relocs = d.image(asm)
    before = source.read_bytes()
    asm_text = asm.read_text()
    calls = reader_args(source, d)
    edits, report = [], []
    order = sorted(labels.items(), key=lambda pair: pair[1])
    declarations = defaultdict(list)
    # Latin-1 preserves byte offsets for symbols in UTF-8 source text.
    text = before.decode("latin1")
    for decl in DECL.finditer(text):
        declarations[decl[1]].append(decl)
    for i, (name, offset) in enumerate(order):
        if name not in calls or sites[name] != {source, asm} or asm_text.count(name) != 1:
            continue
        end = order[i + 1][1] if i + 1 < len(order) else len(image)
        if any(offset <= loc < end for loc in relocs):
            continue
        consumed = decode(image[offset:end])
        if not consumed or not declarations[name]:
            continue
        # Every reader and every declaration must be accounted for. This also
        # excludes unhandled pointer arithmetic, indirect users and macro use.
        used = [t[:2] for t in calls[name]] + [m.span() for m in declarations[name]]
        refs = list(re.finditer(r"\b" + name + r"\b", text))
        if any(sum(start <= ref.start() < stop for start, stop in used) != 1 for ref in refs):
            continue
        if len(refs) != len(used):
            continue
        decl = f"extern s16 {name}[{(end-offset)//2}];"
        if any("\n" in m[0] for m in declarations[name]):
            continue
        local_edits = [(m.start(), m.end(), decl) for m in declarations[name]]
        local_edits += [t[:3] for t in calls[name]]
        if all(before[a:b] == new.encode() for a,b,new in local_edits):
            continue
        edits.extend(local_edits)
        report.append(dict(symbol=name, offset=offset, bytes=end-offset,
                           command_halfwords=consumed, padding_halfwords=(end-offset)//2-consumed,
                           calls=sorted({t[3] for t in calls[name]})))
    result = before
    limit = len(before)
    for start, end, repl in sorted(edits, reverse=True):
        assert end <= limit
        result = result[:start] + repl.encode() + result[end:]
        limit = start
    assert before.count(b"\n") == result.count(b"\n")
    return result, report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--tree", type=Path, default=Path.cwd())
    parser.add_argument("--patch", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    parser.add_argument("modules", nargs="*", help="Optional repository-relative C paths")
    opts = parser.parse_args()
    root, patch, report_path = opts.tree.resolve(), opts.patch.resolve(), opts.report.resolve()
    os.chdir(root)
    sys.path.insert(0, str(root / "pc/native/wasm"))
    import data_to_c as d
    index = site_index(root)
    reports, diff = {}, []
    for _, _, _, asm, source in d.modules():
        rel = str(source.relative_to(root))
        if opts.modules and rel not in opts.modules:
            continue
        if not any(n in source.read_text() for n in READERS):
            continue
        new, found = candidates(source, asm, index, d)
        if found:
            reports[rel] = found
            lines = difflib.unified_diff(source.read_text().splitlines(True),
                                         new.decode().splitlines(True), "a/"+rel, "b/"+rel)
            diff.extend(l if l.endswith("\n") else l+"\n\\ No newline at end of file\n" for l in lines)
    patch.write_text("".join(diff))
    report_path.write_text(json.dumps(reports, indent=2)+"\n")
    print(f"{len(reports)} modules, {sum(map(len,reports.values()))} tables")


if __name__ == "__main__":
    main()
