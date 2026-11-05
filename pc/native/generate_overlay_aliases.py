#!/usr/bin/env python3
"""Bind the original syscall names directly to native C overlay entrypoints."""
import pathlib
import re
import sys
import tomllib


def generate(manifest):
    entries = [name for overlay in manifest["overlay"]
               for name in overlay.get("entrypoints", [])]
    if any(not isinstance(name, str) or not re.fullmatch(r"[A-Za-z_][A-Za-z_0-9]*", name)
           for name in entries):
        raise ValueError("Overlay entrypoints must be C identifiers")
    if len(set(entries)) != len(entries):
        raise ValueError("Duplicate overlay entrypoint")
    if set(entries) & {"_" + name for name in entries}:
        raise ValueError("Overlay entrypoint collides with a syscall alias")
    lines = ["/* Generated from overlays.us.toml; native C calls, no MIPS trampolines. */",
             "#ifndef BT_NATIVE_OVERLAY_ALIASES_H", "#define BT_NATIVE_OVERLAY_ALIASES_H",
             "#ifndef BT_NATIVE", '#error "Native overlay aliases require BT_NATIVE"', "#endif"]
    lines.extend(f"#define _{name} {name}" for name in entries)
    return "\n".join(lines + ["#endif", ""])


if __name__ == "__main__":
    manifest_path, output_path = map(pathlib.Path, sys.argv[1:])
    header = generate(tomllib.loads(manifest_path.read_text()))
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(header)
