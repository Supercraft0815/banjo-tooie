#!/usr/bin/env python3
"""Syntax-checks every game C file with the native flags, one log per file.

Usage: pc/native/audit.py [build/native] [--only SUBSTR] [--write-list]
Writes <build>/audit/<src path>.log and prints the pass count plus the files
sorted by error count. Needs a configured native build (compile_commands.json).
--write-list stores the passing files not already in bt_native_core in
pc/native/game_sources.txt, the source list of the bt_native_game executable.
"""
import json, os, shlex, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
argv = sys.argv[1:]
only = argv[argv.index("--only") + 1] if "--only" in argv else ""
args = [a for i, a in enumerate(argv) if not a.startswith("--") and (i == 0 or argv[i - 1] != "--only")]
build = Path(args[0]) if args else ROOT / "build/native"
out = build / "audit"

seen, core = {}, set()
for entry in json.load(open(build / "compile_commands.json")):
    src = Path(entry["file"])
    rel = src.relative_to(ROOT).as_posix() if src.is_relative_to(ROOT) else ""
    # The all-sources target is the one compiling every src/*.c; keep its flags.
    if "bt_native_core.dir" in entry.get("output", ""):
        core.add(rel)
    if rel.startswith("src/") and rel.endswith(".c") and "bt_native_all_sources" in entry.get("output", entry["command"]):
        seen[rel] = entry
files = sorted(f for f in seen if only in f)


def check(rel):
    entry = seen[rel]
    cmd = shlex.split(entry["command"])
    # Replace "-o obj -c src" with a syntax-only run.
    if "-o" in cmd:
        i = cmd.index("-o"); del cmd[i:i + 2]
    cmd = [c for c in cmd if c != "-c"] + ["-fsyntax-only", "-ferror-limit=0", "-fno-color-diagnostics"]
    r = subprocess.run(cmd, cwd=entry["directory"], capture_output=True, text=True)
    log = out / (rel + ".log")
    log.parent.mkdir(parents=True, exist_ok=True)
    log.write_text(r.stderr)
    return rel, r.returncode, r.stderr.count(": error:")


with ThreadPoolExecutor(os.cpu_count()) as pool:
    results = list(pool.map(check, files))
ok = [r for r in results if r[1] == 0]
bad = sorted((r for r in results if r[1] != 0), key=lambda r: r[2])
if not only:
    (out / "summary.txt").write_text("".join(f"{n}\t{f}\n" for f, _, n in bad))
for f, _, n in bad[-15:]:
    print(f"{n:5}  {f}")
print(f"{len(ok)} / {len(results)} files compile; {sum(r[2] for r in bad)} errors in {len(bad)} files")
print(f"logs: {out}")
if "--write-list" in sys.argv and not only:
    replaced = {l.strip() for l in (ROOT / "pc/native/replaced_sources.txt").read_text().splitlines()
                if l.strip() and not l.startswith("#")}
    ported = sorted(f for f, rc, _ in ok if f not in core and f not in replaced)
    (ROOT / "pc/native/game_sources.txt").write_text("".join(f + "\n" for f in ported))
    print(f"game_sources.txt: {len(ported)} files")
