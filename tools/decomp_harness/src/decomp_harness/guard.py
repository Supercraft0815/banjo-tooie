from __future__ import annotations

import difflib
import hashlib
import os
from pathlib import Path
import re
import shutil
import stat
import tempfile

from .common import HarnessError, atomic_write, digest, git
from .scanner import global_asms, uncomment


def manifest(root: Path):
    result = {}
    for folder, directories, files in os.walk(root, followlinks=False):
        if Path(folder) == root:
            directories[:] = [d for d in directories if d != 'build']
        for name in files + [d for d in directories if (Path(folder)/d).is_symlink()]:
            path = Path(folder)/name
            rel = path.relative_to(root).as_posix()
            mode = path.lstat().st_mode
            result[rel] = (stat.S_IFMT(mode), stat.S_IMODE(mode),
                           os.readlink(path) if path.is_symlink() else digest(path))
    return result


def repository_stamp(root):
    files = git(root, 'ls-files', '--recurse-submodules', '-z').split('\0')
    h = hashlib.sha256()
    for name in sorted(n for n in files if n):
        path = root/name
        h.update(name.encode())
        if path.is_file():
            h.update(digest(path).encode())
        elif not path.exists():
            h.update(b'MISSING')
    return {'head': git(root, 'rev-parse', 'HEAD'), 'status': git(root, 'status', '--porcelain=v1'),
            'tracked_sha256': h.hexdigest(),
            'rom': digest(root/'baserom.us.z64'), 'decompressed': digest(root/'decompressed.us.z64')}


def worker_copy(root: Path, function, native=False):
    target = Path(tempfile.mkdtemp(prefix='decomp-worker-')).resolve()
    try:
        for directory in ('src', 'include', 'lib/ultralib/include'):
            shutil.copytree(root/directory, target/directory)
        path = target/function['asm']
        path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(root/function['asm'], path)
        if native:
            for macro in global_asms((root/function['source']).read_text()):
                path = target/macro['asm']
                path.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(root/macro['asm'], path)
            for directory in ('tools/ido', 'tools/asm-processor'):
                shutil.copytree(root/directory, target/directory, ignore=shutil.ignore_patterns('.git', '__pycache__'))
            for name in ('Makefile', 'overlays.us.toml', 'tools/list_overlays.py'):
                path = target/name
                path.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(root/name, path)
        (target/'build/us').mkdir(parents=True)
        (target/'.harness-worker').write_text(function['id'])
        return target
    except BaseException:
        shutil.rmtree(target)
        raise


def candidate_guard(original: str, candidate: str, symbol: str):
    macros = [m for m in global_asms(original) if m['symbol'] == symbol]
    if len(macros) != 1:
        raise HarnessError('Target must have exactly one active GLOBAL_ASM')
    macro = macros[0]
    prefix, suffix = original[:macro['start']], original[macro['end']:]
    if not candidate.startswith(prefix) or suffix and not candidate.endswith(suffix):
        raise HarnessError('Worker changed bytes outside the target directive')
    end = len(candidate)-len(suffix) if suffix else len(candidate)
    replacement = candidate[len(prefix):end]
    code = uncomment(replacement)
    if re.search(r'\b(?:GLOBAL_ASM|asm|__asm__|__asm)\b|^\s*#|[.]incbin', code, re.M):
        raise HarnessError('ASM/preprocessor workaround refused')
    if not re.search(rf'\b{re.escape(symbol)}\s*\([^;{{}}]*\)\s*{{', code):
        raise HarnessError('Worker did not define the target C function')
    # A single top-level definition; no unrelated helper functions or global data.
    literal_free = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', '""', code)
    depth, bodies, trailing = 0, 0, ''
    for char in literal_free:
        if char == '{':
            if depth == 0:
                bodies += 1
            depth += 1
        elif char == '}':
            depth -= 1
            if depth < 0:
                raise HarnessError('Unbalanced C braces')
        elif bodies and depth == 0:
            trailing += char
    if depth or bodies != 1 or trailing.strip():
        raise HarnessError('Replacement must contain only the single target function')
    return replacement


def verify_worker_changes(worker, before, source):
    after = manifest(worker)
    changed = {p for p in before.keys() | after.keys() if before.get(p) != after.get(p)}
    if changed - {source}:
        raise HarnessError('Worker changed forbidden files: ' + ', '.join(sorted(changed)[:20]))
    if source not in after or (worker/source).is_symlink() or before[source][:2] != after[source][:2]:
        raise HarnessError('Source type/mode changed')


def source_diff(before, after, source):
    return ''.join(difflib.unified_diff(before.splitlines(True), after.splitlines(True), 'a/'+source, 'b/'+source))


def publish(root, state, function, before: bytes, after: bytes):
    path = root/function['source']
    if path.read_bytes() != before or git(root, 'status', '--porcelain=v1', '--', function['source']):
        raise HarnessError('Target has user changes; validated candidate retained, no overwrite')
    branch = git(root, 'symbolic-ref', '--short', 'HEAD')
    if branch in ('main', 'master'):
        raise HarnessError('Refusing automatic match commits on main/master; create a dedicated branch')
    head = git(root, 'rev-parse', 'HEAD')
    with state.db:
        state.db.execute('INSERT INTO publication VALUES (?,?,?,?,?,?)',
                         (function['id'], function['source'], before, after, head, __import__('time').time()))
    atomic_write(path, after)
    try:
        git(root, '-c', 'core.hooksPath=/dev/null', '-c', 'commit.gpgsign=false', 'commit', '--only',
            '-m', f"decomp: match {function['symbol']}\n\nDecomp-Function: {function['id']}", '--', function['source'])
    except HarnessError:
        if path.read_bytes() == after and git(root, 'rev-parse', 'HEAD') == head:
            atomic_write(path, before)
            with state.db:
                state.db.execute('DELETE FROM publication WHERE function_id=?', (function['id'],))
        raise
    commit = git(root, 'rev-parse', 'HEAD')
    with state.db:
        state.db.execute("UPDATE functions SET status='matched',commit_sha=?,best_score=100,last_error=NULL WHERE id=?", (commit, function['id']))
        state.db.execute('DELETE FROM publication WHERE function_id=?', (function['id'],))
    return commit


def recover_publications(root, state):
    for row in state.db.execute('SELECT * FROM publication').fetchall():
        path = root/row['source']
        head = git(root, 'rev-parse', 'HEAD')
        message = git(root, 'log', '-1', '--format=%B')
        if head != row['head'] and f"Decomp-Function: {row['function_id']}" in message and path.read_bytes() == row['after']:
            state.update(row['function_id'], status='matched', commit_sha=head, best_score=100)
        elif head == row['head'] and path.read_bytes() in (row['before'], row['after']):
            if path.read_bytes() == row['after']:
                atomic_write(path, row['before'])
            state.update(row['function_id'], status='pending', last_error='Recovered interrupted publication')
        else:
            state.update(row['function_id'], status='needs_human', last_error='Interrupted publication conflicts with user changes; inspect publication journal')
            raise HarnessError('Publication recovery needs human review; user changes were preserved')
        with state.db:
            state.db.execute('DELETE FROM publication WHERE function_id=?', (row['function_id'],))
