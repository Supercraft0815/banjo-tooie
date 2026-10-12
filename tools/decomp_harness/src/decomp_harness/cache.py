"""Reuse only complete, content-verified build snapshots; never trust mtime alone."""
import hashlib
import json
import os
from pathlib import Path
import shutil
import stat
import uuid

from .build import scratch, snapshot
from .common import HarnessError, command, digest, save_json

INPUT_DIRS = ('src', 'include', 'tools', 'lib', 'asm', 'assets')
IGNORED = {'.git', '.codex', '.agents', '__pycache__', '.decomp-agent'}


def tree_fingerprint(root, inputs_only=False):
    """Hash content, relative paths and modes; source inputs also include ignored ASM/tools."""
    result = hashlib.sha256()
    for folder, dirs, files in os.walk(root, followlinks=False):
        relative = Path(folder).relative_to(root)
        dirs.sort()
        if inputs_only:
            dirs[:] = [d for d in dirs if d not in IGNORED and not d.endswith('.egg-info')]
            files = [f for f in files if f not in IGNORED]
            if relative == Path('.'):
                dirs[:] = [d for d in dirs if d in INPUT_DIRS]
                files = [f for f in files if Path(f).suffix in ('.toml', '.txt', '.yaml', '.ld', '.py')
                         or f in ('Makefile', 'baserom.us.z64', 'decompressed.us.z64')]
            if relative == Path('lib/ultralib'):
                dirs[:] = [d for d in dirs if d != 'build']
        for name in sorted(files + [d for d in dirs if (Path(folder)/d).is_symlink()]):
            path = Path(folder)/name
            # A cache must not carry mutable links to reference or user data.
            if path.is_symlink() or not path.is_file():
                raise HarnessError(f'Build-cache input is not a regular file: {relative/name}')
            entry = [str(relative/name), stat.S_IMODE(path.stat().st_mode), digest(path)]
            result.update(json.dumps(entry).encode())
    return result.hexdigest()


def input_key(root, config):
    image = command(['docker', 'image', 'inspect', config['build']['image'], '--format', '{{.Id}}']).stdout.decode().strip()
    return {'schema': 2, 'inputs': tree_fingerprint(root, inputs_only=True),
            'build': config['build'], 'image_id': image}


def cache_path(root, record):
    if not isinstance(record, dict):
        raise HarnessError('Invalid build-cache record')
    name = record.get('directory', '')
    if not isinstance(name, str) or not name.startswith('build-') or Path(name).name != name:
        raise HarnessError('Invalid build-cache directory')
    path = root/'.decomp-agent/build-cache'/name
    if path.is_symlink() or (path/'.harness-snapshot').read_text() != str(root):
        raise HarnessError('Build cache does not belong to this repository')
    return path


def prepare(root, config):
    key = input_key(root, config) if config['build_cache'] and config['build']['backend'] == 'docker' else None
    record_path = root/'.decomp-agent/build-cache/current.json'
    if key is not None and record_path.exists():
        work = None
        try:
            record = json.loads(record_path.read_text())
            if record['key'] == key:
                cache = cache_path(root, record)
                # Copy first, then hash the copy: no TOCTOU trust of cached artifacts.
                work = scratch(root)
                shutil.copytree(cache, work, dirs_exist_ok=True, symlinks=True)
                if tree_fingerprint(work) == record['artifacts']:
                    return work, True
        except (KeyError, TypeError, ValueError, OSError, HarnessError):
            pass  # Cache rejection falls back to a fresh build, never to weaker validation.
        if work:
            shutil.rmtree(work)
    return snapshot(root), False


def retain(root, work, config):
    """Called only after normal completion with an exact/restored build baseline."""
    if not config['build_cache'] or config['build']['backend'] != 'docker':
        return
    base = root/'.decomp-agent/build-cache'
    base.mkdir(parents=True, exist_ok=True, mode=0o700)
    record_path = base/'current.json'
    previous = None
    if record_path.exists():
        try:
            previous = cache_path(root, json.loads(record_path.read_text()))
        except (ValueError, OSError, HarnessError):
            pass
    key = input_key(root, config)
    # Do not cache if a copied compiler/input changed while building the snapshot.
    if tree_fingerprint(work, inputs_only=True) != key['inputs']:
        return
    destination = base/('build-'+uuid.uuid4().hex[:12])
    artifacts = tree_fingerprint(work)
    shutil.move(str(work), destination)
    save_json(record_path, {'directory': destination.name, 'key': key, 'artifacts': artifacts})
    if previous and previous != destination:
        shutil.rmtree(previous)
