#!/usr/bin/env python3
"""Writes overlay_sections.txt (N64Recomp section list) and overlay_ids.inc (game overlay index -> list id)."""
import pathlib
import tomllib

root = pathlib.Path(__file__).resolve().parents[1]
overlays = tomllib.loads((root.parent / "overlays.us.toml").read_text())["overlay"]

names = []
# The game numbers overlays from 1 (the syscall code); index 0 is unused.
ids = [-1]
for ovl in overlays:
    if ovl.get("empty"):
        ids.append(-1)
    else:
        ids.append(len(names))
        names.append("." + ovl["name"])

(root / "overlay_sections.txt").write_text("\n".join(names) + "\n")
(root / "overlay_ids.inc").write_text(", ".join(map(str, ids)) + "\n")
print(f"{len(names)} overlays, highest game index {len(ids) - 1}")
