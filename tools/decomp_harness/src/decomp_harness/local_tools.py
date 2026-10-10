"""Inference-free helpers in the trusted build environment: m2c drafts and the permuter.

Both only produce candidates. Every candidate still passes the source guard, the
original compiler and, for a match, the full ROM check.
"""
from __future__ import annotations

import hashlib
from pathlib import Path
import re
import shutil
import uuid

from .common import atomic_write, command, digest
from .guard import extract_function

M2C = '''import subprocess, sys
sys.path.insert(0, "tools")
import m2ctx
open("/tmp/m2c-ctx.c", "w").write(m2ctx.import_c_file(sys.argv[1]))
sys.exit(subprocess.call([sys.executable, "tools/m2c/m2c.py", "--valid-syntax", "--target", "mips-ido-c",
                          "--context", "/tmp/m2c-ctx.c", sys.argv[2]]))
'''
UNSUPPORTED = re.compile(r'\?|M2C_(?!FIELD\b|BITWISE\b|UNK)|saved_reg|unksp|/\*\s*irregular')
# Expansions from tools/m2c/m2c_macros.h: the source guard forbids #define in a candidate.
MACROS = {'M2C_FIELD': lambda e, t, o: f'(*({t})((s8 *)({e}) + ({o})))',
          'M2C_BITWISE': lambda t, e: f'(({t})({e}))'}
UNKNOWN = {'M2C_UNK': 's32', 'M2C_UNK8': 's8', 'M2C_UNK16': 's16', 'M2C_UNK32': 's32', 'M2C_UNK64': 's64'}


def expand(code):
    """Replace m2c valid-syntax macros by their definitions, innermost first."""
    code = re.sub(r'\bM2C_UNK(?:8|16|32|64)?\b', lambda m: UNKNOWN[m[0]], code)
    while True:
        match = None
        for found in re.finditer(r'\b(M2C_FIELD|M2C_BITWISE)\(', code):
            match = found  # The last opening is the innermost or a later sibling: both safe.
        if not match:
            return code
        depth, args, start = 1, [], match.end()
        for index in range(match.end(), len(code)):
            char = code[index]
            if char == '(':
                depth += 1
            elif char == ')':
                depth -= 1
                if depth == 0:
                    args.append(code[start:index].strip())
                    break
            elif char == ',' and depth == 1:
                args.append(code[start:index].strip())
                start = index + 1
        else:
            return code
        try:
            replacement = MACROS[match[1]](*args)
        except TypeError:
            return code
        code = code[:match.start()] + replacement + code[index+1:]


def m2c_draft(root: Path, workspace: Path, builder, function, cache: Path):
    """Deterministic C draft for the target; cached per ASM and source content."""
    if not (workspace/'tools/m2c/m2c.py').is_file():
        return None
    key = hashlib.sha256(f"{function['asm_sha']}:{digest(root/function['source'])}".encode()).hexdigest()[:24]
    path = cache/f'{key}.c'
    if path.is_file():
        return path.read_text() or None
    if not function['asm_sha']:
        return None
    result = command(builder.argv(['python3', '-c', M2C, function['source'], function['asm']]),
                     workspace, timeout=120, check=False)
    text = '\n'.join(l for l in result.stdout.decode(errors='replace').splitlines()
                     if not l.startswith('/* Warning: struct'))
    if result.returncode or not extract_function(text, function['symbol']):
        text = ''
    atomic_write(path, text)
    return text or None


def m2c_candidate(draft, symbol):
    """Turn a clean m2c draft into a self-contained function, or None.

    m2c emits file-scope externs; the source guard only allows the target function,
    so they move into the body. Unknown parameter lists become unprototyped calls.
    """
    body = extract_function(draft, symbol)
    if not body or UNSUPPORTED.search(body):
        return None
    prefix, body = draft[:draft.find(body)], expand(body)
    declarations = []
    for line in prefix.splitlines():
        line = re.sub(r'/\*.*?\*/', '', line).strip()
        if not line:
            continue
        if not line.endswith(';') or line.startswith(('static', 'typedef', 'struct', 'union', 'enum')):
            return None
        call = re.match(r'(.+?)\b(\w+)\((.*)\);$', line)
        if call and '?' in call[3]:
            line = f"{call[1].replace('?', 's32')}{call[2]}();"
        declarations.append('    ' + expand(line.replace('?', 's32')))
    if not declarations:
        return body
    brace = body.index('{') + 1
    return body[:brace] + '\n' + '\n'.join(declarations) + body[brace:]


def m2c_candidates(draft, symbol):
    """The m2c candidate, plus a variant with byte pointers: m2c relies on GCC's
    `void *` arithmetic, which IDO rejects. Same registers either way."""
    code = m2c_candidate(draft, symbol)
    if not code:
        return []
    variant = re.sub(r'\bvoid(\s*\*)', r'u8\1', code)
    return [code] if variant == code else [code, variant]


def run_permuter(builder, workspace: Path, function, candidate: bytes, original: bytes,
                 gate, seconds, log_dir: Path):
    """Search compiler-equivalent rewrites of the best candidate for `seconds`.

    Import runs under the build gate with the candidate in the trusted workspace;
    the long search only reads the toolchain. Returns (score, function text) of the
    best result, where score 0 means the permuter found an object match.
    """
    if not (workspace/'tools/decomp-permuter/permuter.py').is_file():
        return None
    name = 'perm-' + uuid.uuid4().hex[:12]
    folder = workspace/'.permuter'/name
    folder.mkdir(parents=True)
    try:
        relative = Path('..')/'..'
        with gate:
            atomic_write(workspace/function['source'], candidate)
            try:
                code = builder.invoke(['env', '-C', f'.permuter/{name}', 'python3',
                                       str(relative/'tools/decomp-permuter/import.py'),
                                       str(relative/function['source']), str(relative/function['asm'])],
                                      log_dir/'permuter-import.log')
            finally:
                atomic_write(workspace/function['source'], original)
        imported = folder/'nonmatchings'/function['symbol']
        if code or not imported.is_dir():
            return None
        builder.invoke(['timeout', str(int(seconds)), 'python3', 'tools/decomp-permuter/permuter.py',
                        f'.permuter/{name}/nonmatchings/{function["symbol"]}', '--stop-on-zero', '--quiet',
                        '-j', str(builder.config['build']['jobs'])], log_dir/'permuter.log')
        results = []
        for output in imported.glob('output-*'):
            match = re.fullmatch(r'output-(\d+)-\d+', output.name)
            if match and (output/'source.c').is_file():
                results.append((int(match[1]), output/'source.c'))
        if not results:
            return None
        best, path = min(results)
        code = extract_function(path.read_text(errors='replace'), function['symbol'])
        return (best, code) if code else None
    finally:
        shutil.rmtree(folder, ignore_errors=True)
        try:
            (workspace/'.permuter').rmdir()
        except OSError:
            pass
