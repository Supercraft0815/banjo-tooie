#!/usr/bin/env python3
"""Which functions of an N64 build changed code? Compares objects of two build trees function by
function (disassembly with relocations, plus data sections) inside the decomp Docker image.

  n64_objdiff.py TREE BASE_BUILD_DIR NEW_BUILD_DIR FILE.c ...   -> prints FILE.c:FUNC per change
                                                                 (FILE.c:<data> for data sections)
  --linked  resolve object differences against linked instruction bytes; keep inventory changes
"""
import re
import subprocess
import sys
from pathlib import Path

IMAGE = 'banjo-tooie-decomp:local'


def dump(tree, build, files):
    objs = ['%s/us/%s.o' % (build, f) for f in files]
    script = 'for o in "$@"; do test -f "$o" || exit 1; echo "@@@ $o"; ' \
             'mips-linux-gnu-objdump -d -r -z "$o" || exit 1; ' \
             'mips-linux-gnu-objdump -s -j .data -j .rodata "$o" 2>/dev/null | sed "s/^/DATA /"; done'
    r = subprocess.run(['docker', 'run', '--rm', '--platform', 'linux/amd64', '--network', 'none',
                        '--mount', 'type=bind,source=%s,target=/work' % tree, '--workdir', '/work',
                        IMAGE, 'sh', '-c', script, 'sh'] + objs, capture_output=True, text=True, check=True)
    out, cur, func = {}, None, None
    for line in r.stdout.splitlines():
        if line.startswith('@@@ '):
            cur = line[4:].split('/us/', 1)[1][:-2]
            func = None
            continue
        if line.startswith('DATA '):
            if 'file format' not in line:
                out.setdefault((cur, '<data>'), []).append(line)
            continue
        m = re.match(r'^[0-9a-f]+ <(.+)>:$', line)
        if m:
            func = m.group(1)
            continue
        if func and line.strip():
            # drop the address column; keep encoding, mnemonic, operands, relocation targets
            out.setdefault((cur, func), []).append(re.sub(r'^\s*[0-9a-f]+:\s*', '', line))
    return out


def linked_dump(tree, build, names):
    script = 'elf=$1; shift; for fn in "$@"; do echo "@@@ $fn"; ' \
             'mips-linux-gnu-objdump -d -z --disassemble="$fn" "$elf" || exit 1; done'
    result = subprocess.run(['docker', 'run', '--rm', '--platform', 'linux/amd64', '--network', 'none',
                             '--mount', 'type=bind,source=%s,target=/work,readonly' % tree,
                             '--workdir', '/work', IMAGE, 'sh', '-c', script, 'sh',
                             '%s/us/banjotooie_decompressed.elf' % build] + sorted(names),
                            capture_output=True, text=True, check=True)
    out, name = {}, None
    for line in result.stdout.splitlines():
        if line.startswith('@@@ '):
            name = line[4:]
            out[name] = []
        match = re.match(r'^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s', line)
        if match and name:
            out[name].append(match.groups())  # addresses and bytes, independent of symbol annotations
    return out


def main():
    args = [arg for arg in sys.argv[1:] if arg != '--linked']
    tree, base, new, files = args[0], args[1], args[2], args[3:]
    a, b = dump(tree, base, files), dump(tree, new, files)
    changed = sorted(k for k in set(a) | set(b) if a.get(k) != b.get(k))
    if '--linked' in sys.argv:
        names = {func for f, func in changed if func != '<data>' and (f, func) in a and (f, func) in b}
        if names:
            old, current = linked_dump(tree, base, names), linked_dump(tree, new, names)
            changed = [(f, func) for f, func in changed if func not in names or (f, func) not in a or (f, func) not in b or
                       not old.get(func) or old[func] != current.get(func)]
    for f, func in changed:
        print('%s:%s' % (f, func))


if __name__ == '__main__':
    main()
