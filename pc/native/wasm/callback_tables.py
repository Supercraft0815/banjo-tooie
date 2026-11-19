#!/usr/bin/env python3
"""Propose BtFnWord for callback arrays returned by overlay entry points.

Use the original linked MIPS ELF. Tables must contain only relocations to
defined functions, and every C use must be a declaration or a direct return.
"""
import argparse
import difflib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

from audio_command_tables import site_index


def original_functions(elf, readelf):
    """Read externally linkable STT_FUNC symbols from the linked big-endian MIPS ELF32."""
    result = subprocess.run([readelf, "--file-header", "--symbols", "--wide", str(elf)],
                            capture_output=True, text=True)
    if result.returncode:
        raise ValueError(result.stderr.strip())
    header = dict(re.findall(r"^\s*(Class|Data|Machine|Type):\s*(.+)$", result.stdout, re.M))
    if (header.get("Class") != "ELF32" or header.get("Data") != "2's complement, big endian"
            or not header.get("Machine", "").startswith("MIPS")
            or not header.get("Type", "").startswith("EXEC ")):
        raise ValueError("Expected the original linked big-endian MIPS ELF32")
    functions = set()
    for line in result.stdout.splitlines():
        fields = line.split()
        if (len(fields) == 8 and fields[0].endswith(":") and fields[0][:-1].isdigit()
                and fields[3] == "FUNC" and fields[4] in {"GLOBAL", "WEAK"} and fields[6].isdigit()):
            functions.add(fields[7])
    return functions


def callback_entries(start, end, relocations, functions):
    if start % 4 or end <= start or (end - start) % 4:
        return None
    if any((offset - start) % 4 for offset in relocations if start <= offset < end):
        return None
    entries = []
    for offset in range(start, end, 4):
        target = relocations.get(offset)
        if not target or target[0] not in functions or target[1] != 0:
            return None
        entries.append(target[0])
    return entries


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--tree", type=Path, default=Path.cwd())
    parser.add_argument("--elf", type=Path, required=True)
    parser.add_argument("--patch", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()
    root, elf, out, report = [p.resolve() for p in (args.tree, args.elf, args.patch, args.report)]
    os.chdir(root)
    sys.path.insert(0, str(root / "pc/native/wasm"))
    from build import tool
    import data_to_c

    functions = original_functions(elf, tool("llvm-readelf"))
    sites = site_index(root)
    accepted, diff = {}, []
    for _, _, _, asm, src in data_to_c.modules():
        before = src.read_text()
        labels, data, relocations = data_to_c.image(asm)
        asm_text = asm.read_text()
        after = before
        for label, start in sorted(labels.items(), key=lambda pair: pair[1]):
            if sites[label] != {src, asm} or asm_text.count(label) != 1:
                continue
            declaration = re.compile(r"extern [su]8 " + label + r"\[\];")
            returned = re.compile(r"return\s+\(OSThread\s*\*\)\s*" + label + r"\s*;")
            if not declaration.search(before) or not returned.search(before):
                continue
            if before.count(label) != len(declaration.findall(before)) + len(returned.findall(before)):
                continue
            end = min((offset for offset in labels.values() if offset > start), default=len(data))
            entries = callback_entries(start, end, relocations, functions)
            if entries:
                after = declaration.sub(f"extern BtFnWord {label}[{len(entries)}];", after)
                accepted.setdefault(str(src.relative_to(root)), {})[label] = entries
        if after != before:
            path = str(src.relative_to(root))
            lines = difflib.unified_diff(before.splitlines(True), after.splitlines(True),
                                         "a/" + path, "b/" + path)
            diff.extend(l if l.endswith("\n") else l + "\n\\ No newline at end of file\n" for l in lines)
    report.write_text(json.dumps(accepted, indent=2) + "\n")
    out.write_text("".join(diff))
    print(f"{sum(map(len, accepted.values()))} tables, {len(accepted)} modules")


if __name__ == "__main__":
    main()
