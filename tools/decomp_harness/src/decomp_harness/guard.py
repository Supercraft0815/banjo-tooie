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
from .scanner import LEX, global_asms, uncomment

IPC = '.decomp-ipc'


def manifest(root: Path):
    result = {}
    for folder, directories, files in os.walk(root, followlinks=False):
        if Path(folder) == root:
            # build/ is scratch; .decomp-ipc/ carries compile requests to the parent.
            directories[:] = [d for d in directories if d not in ('build', IPC)]
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


def worker_copy(root: Path, function, worktree=False):
    """Sources and headers only: workers compile through the parent's ./decomp-compile."""
    owner = Path(tempfile.mkdtemp(prefix='decomp-worker-')).resolve()
    target = owner/'seed' if worktree else owner
    target.mkdir(exist_ok=True)
    try:
        for directory in ('src', 'include', 'lib/ultralib/include'):
            shutil.copytree(root/directory, target/directory)
        path = target/function['asm']
        path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(root/function['asm'], path)
        (target/'build/us').mkdir(parents=True)
        (target/'.harness-worker').write_text(function['id'])
        if worktree:
            # Private Git database: workers never get a link to the user's .git.
            git(target, 'init', '-q', '-b', 'isolated')
            git(target, 'add', 'src', 'include', 'lib', 'asm', '.harness-worker')
            git(target, '-c', 'user.name=Decomp Worker', '-c', 'user.email=worker@example.invalid',
                '-c', 'core.hooksPath=/dev/null', '-c', 'commit.gpgsign=false', 'commit', '-qm', 'Isolated source snapshot')
            checkout = owner/'checkout'
            git(target, '-c', 'core.hooksPath=/dev/null', 'worktree', 'add', '--detach', str(checkout), 'HEAD')
            (owner/'.harness-private-worktree').write_text(function['id'])
            (checkout/'build/us').mkdir(parents=True)
            target = checkout
        return target
    except BaseException:
        shutil.rmtree(owner)
        raise


def dispose_worker(worker):
    owner = worker.parent if worker.name == 'checkout' and (worker.parent/'.harness-private-worktree').is_file() else worker
    if not owner.name.startswith('decomp-worker-'):
        raise HarnessError('Refusing to clean an unowned worker directory')
    shutil.rmtree(owner)


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


def target_markers(symbol):
    return f'/* decomp-target-begin {symbol} */', f'/* decomp-target-end {symbol} */'


def mark_targets(original: str, symbols):
    """Wrap each batch target directive in comment markers the worker must keep."""
    macros = sorted((m for m in global_asms(original) if m['symbol'] in symbols), key=lambda m: m['start'])
    if len(macros) != len(set(symbols)):
        raise HarnessError('Each batch target needs exactly one active GLOBAL_ASM')
    result, position = [], 0
    for m in macros:
        begin, end = target_markers(m['symbol'])
        result += [original[position:m['start']], begin, '\n', original[m['start']:m['end']], '\n', end]
        position = m['end']
    return ''.join(result + [original[position:]])


def split_targets(original: str, worked: str, symbols):
    """Map each batch target to its edited replacement (None if untouched).

    Everything outside the marked regions must be byte-identical to the original.
    Each replacement is checked like a single-target candidate.
    """
    macros = sorted((m for m in global_asms(original) if m['symbol'] in symbols), key=lambda m: m['start'])
    if len(macros) != len(set(symbols)):
        raise HarnessError('Each batch target needs exactly one active GLOBAL_ASM')
    result, read, position = {}, 0, 0
    for m in macros:
        begin, end = target_markers(m['symbol'])
        expected = original[position:m['start']] + begin
        if worked[read:read+len(expected)] != expected:
            raise HarnessError(f"Changed bytes outside the marked target regions (before {m['symbol']}), or a marker was removed")
        read += len(expected)
        stop = worked.find(end, read)
        if stop < 0:
            raise HarnessError(f"End marker for {m['symbol']} was removed")
        code = worked[read:stop].strip()
        read, position = stop + len(end), m['end']
        directive = original[m['start']:m['end']].strip()
        if code != directive:
            replacement = original[:m['start']] + code + original[m['end']:]
            candidate_guard(original, replacement, m['symbol'])
            result[m['symbol']] = code
        else:
            result[m['symbol']] = None
    if worked[read:] != original[position:]:
        raise HarnessError('Changed bytes after the last marked target region')
    return result


def extract_function(text: str, symbol: str):
    """Text of the top-level definition of symbol (return type to closing brace)."""
    clean = LEX.sub(lambda m: ' '*len(m[0]), text)
    depth = 0
    for match in re.finditer(r'[{}]|\b'+re.escape(symbol)+r'\s*\([^;{}]*\)\s*{', clean):
        if match[0] in '{}':
            depth = depth+1 if match[0] == '{' else max(0, depth-1)
            continue
        if depth:
            continue
        before = clean[:match.start()]
        directives = [m.end() for m in re.finditer(r'(?m)^[ \t]*#.*$', before)]
        begin = max(before.rfind(';')+1, before.rfind('}')+1, *directives, 0)
        depth = 0
        for index in range(match.end()-1, len(clean)):
            depth += {'{': 1, '}': -1}.get(clean[index], 0)
            if depth == 0:
                return text[begin:index+1].strip()
        return None
    return None


def verify_worker_changes(worker, before, source, support=()):
    after = manifest(worker)
    changed = {p for p in before.keys() | after.keys() if before.get(p) != after.get(p)}
    if changed - {source, *support}:
        raise HarnessError('Worker changed forbidden files: ' + ', '.join(sorted(changed)[:20]))
    for path in {source, *changed}:
        if path not in after or (worker/path).is_symlink() or before[path][:2] != after[path][:2]:
            raise HarnessError('Source type/mode changed')
    return changed


def source_diff(before, after, source):
    return ''.join(difflib.unified_diff(before.splitlines(True), after.splitlines(True), 'a/'+source, 'b/'+source))


def publish(root, state, function, before: bytes, after: bytes, support=None):
    files = {function['source']: (before, after), **(support or {})}
    for source, (original, _) in files.items():
        if (root/source).read_bytes() != original or git(root, 'status', '--porcelain=v1', '--', source):
            raise HarnessError('Target/dependency has user changes; validated candidate retained, no overwrite')
    branch = git(root, 'symbolic-ref', '--short', 'HEAD')
    if branch in ('main', 'master'):
        raise HarnessError('Refusing automatic match commits on main/master; create a dedicated branch')
    head = git(root, 'rev-parse', 'HEAD')
    with state.db:
        state.db.execute('INSERT INTO publication VALUES (?,?,?,?,?,?)',
                         (function['id'], function['source'], before, after, head, __import__('time').time()))
        state.db.executemany('INSERT INTO publication_files VALUES (?,?,?,?)',
                             [(function['id'], p, a, b) for p, (a, b) in (support or {}).items()])
    try:
        for source, (_, updated) in files.items():
            atomic_write(root/source, updated)
        git(root, '-c', 'core.hooksPath=/dev/null', '-c', 'commit.gpgsign=false', 'commit', '--only',
            '-m', f"decomp: match {function['symbol']}\n\nDecomp-Function: {function['id']}", '--', *files)
    except (HarnessError, OSError):
        # Recovery checks the entire journal before restoring any file.
        recover_publications(root, state)
        raise
    commit = git(root, 'rev-parse', 'HEAD')
    with state.db:
        state.db.execute("UPDATE functions SET status='matched',present=0,commit_sha=?,best_score=100,last_error=NULL WHERE id=?", (commit, function['id']))
        state.db.execute('DELETE FROM publication WHERE function_id=?', (function['id'],))
    return commit


def recover_publications(root, state):
    for row in state.db.execute('SELECT * FROM publication').fetchall():
        files = [row, *state.db.execute('SELECT * FROM publication_files WHERE function_id=?', (row['function_id'],))]
        actual = [(root/f['source']).read_bytes() if (root/f['source']).is_file() else None for f in files]
        head = git(root, 'rev-parse', 'HEAD')
        message = git(root, 'log', '-1', '--format=%B')
        if (head != row['head'] and f"Decomp-Function: {row['function_id']}" in message
                and all(content == f['after'] for content, f in zip(actual, files))):
            state.update(row['function_id'], status='matched', present=0, commit_sha=head, best_score=100)
        elif head == row['head'] and all(content in (f['before'], f['after']) for content, f in zip(actual, files)):
            for f in files:
                atomic_write(root/f['source'], f['before'])
            state.update(row['function_id'], status='pending', last_error='Recovered interrupted publication')
        else:
            state.update(row['function_id'], status='needs_human', last_error='Interrupted publication conflicts with user changes; inspect publication journal')
            raise HarnessError('Publication recovery needs human review; user changes were preserved')
        with state.db:
            state.db.execute('DELETE FROM publication WHERE function_id=?', (row['function_id'],))
