from __future__ import annotations

from array import array
import os
from pathlib import Path
import re
import shutil
import sys
import tempfile
import uuid

from .common import (Control, HarnessError, ROM_SHA1, DECOMPRESSED_SHA1, command,
                     digest, run_logged)


LINK_OUTPUTS = ('build/us/banjotooie_decompressed.elf', 'build/us/banjotooie_decompressed_prelim.elf',
                'build/us/banjotooie_decompressed.z64', 'build/us/banjotooie.z64')


BASELINE = '.baseline'

# Tool-level failures no candidate can cause (the guard refuses preprocessor and ASM
# lines): the toolchain itself is missing or cannot run.
# ponytail: message signatures, not a toolchain check; a vanished header still reads as
# a compile error. Fingerprint the lane's inputs on failure if that ever happens.
BROKEN = re.compile(r"^(?:(?:python3|make|/bin/sh|sh): .*(?:No such file or directory|not found"
                    r"|No rule to make target|Permission denied)"
                    r"|FileNotFoundError: |Error response from daemon|OCI runtime).*", re.M)


def object_path(source):
    return 'build/us/' + source + '.o'


def verify_rom(root: Path, decompressed=False):
    path = root / ('decompressed.us.z64' if decompressed else 'baserom.us.z64')
    expected = DECOMPRESSED_SHA1 if decompressed else ROM_SHA1
    if not path.is_file():
        raise HarnessError(f'Missing {path.name}. Provide your own NTSC-U ROM; use decomp-agent init --rom PATH. No ROM download is supported.')
    actual = digest(path, 'sha1')
    if actual != expected:
        raise HarnessError(f'{path.name}: SHA1 {actual}, expected {expected}')
    return actual


def import_rom(source: Path, root: Path):
    data = source.read_bytes()
    header = data[:4].hex()
    if len(data) != 33554432:
        raise HarnessError('Expected a 32 MiB Banjo-Tooie NTSC-U ROM')
    if header == '37804012':
        words = array('H'); words.frombytes(data); words.byteswap(); data = words.tobytes()
    elif header == '40123780':
        words = array('I'); words.frombytes(data); words.byteswap(); data = words.tobytes()
    elif header != '80371240':
        raise HarnessError('Unknown ROM byte order; expected .z64, .n64 or .v64')
    import hashlib
    if hashlib.sha1(data).hexdigest() != ROM_SHA1:
        raise HarnessError('ROM does not match the required NTSC-U SHA1; no file written')
    target = root / 'baserom.us.z64'
    if target.exists():
        verify_rom(root)
    else:
        from .common import atomic_write
        atomic_write(target, data)
    return target


class Builder:
    def __init__(self, root: Path, config, control: Control):
        self.root, self.config, self.control = root, config, control
        self.container = None

    def start(self):
        """One offline container per owned workspace, explicitly closed by its owner."""
        if self.container or self.config['build']['backend'] == 'native':
            return
        name = 'decomp-build-' + uuid.uuid4().hex
        args = self.argv(['sleep', 'infinity'])
        args[2:2] = ['-d', '--init', '--name', name]
        self.container = name
        try:
            command(args, self.root, timeout=90)
        except BaseException:
            self.close()
            raise

    def close(self):
        if self.container:
            command(['docker', 'rm', '-f', self.container], timeout=30)
            self.container = None

    def argv(self, args, network=False):
        build = self.config['build']
        if build['backend'] == 'native':
            return args
        if self.container and not network:
            return ['docker', 'exec', self.container, *args]
        # Only the disposable build directory is exposed to the compiler container.
        docker = ['docker', 'run', '--rm', '--platform', build['platform'],
                  '--mount', f'type=bind,source={self.root},target=/work', '--workdir', '/work',
                  '--user', f'{os.getuid()}:{os.getgid()}', '--env', 'HOME=/tmp',
                  '--cap-drop', 'ALL', '--security-opt', 'no-new-privileges']
        if not network:
            docker += ['--network', 'none']
        return docker + [build['image'], *args]

    def invoke(self, args, log: Path, network=False):
        try:
            return run_logged(self.argv(args, network), self.root, log,
                              self.config['build_timeout'], self.control)
        except BaseException:
            # Killing docker exec alone leaves the compiler running in the container.
            self.close()
            raise

    def build(self, log: Path, source=None):
        if source:
            # Makefile lacks complete header deps; a fresh baseline handles headers,
            # and every changed translation unit is forcibly recompiled.
            (self.root / self.object_path(source)).unlink(missing_ok=True)
        return self.invoke(['make', f'-j{self.config["build"]["jobs"]}', 'build/us/banjotooie_decompressed.z64'], log)

    def regression(self, log: Path):
        if self.invoke(['make', f'-j{self.config["build"]["jobs"]}', 'check'], log):
            return False
        verify_rom(self.root)
        verify_rom(self.root, True)
        return digest(self.root/'build/us/banjotooie_decompressed.z64', 'sha1') == DECOMPRESSED_SHA1

    def object_build(self, source, log):
        (self.root/self.object_path(source)).unlink(missing_ok=True)
        code = self.invoke(['make', f'-j{self.config["build"]["jobs"]}', self.object_path(source)], log)
        broken = code and BROKEN.search(log.read_text(errors='replace'))
        if broken:
            # Stop the run instead of charging candidates and their attempt budget.
            raise HarnessError(f'Build environment is broken, not the candidate: {broken[0][:200]} (see {log})')
        return code

    @staticmethod
    def object_path(source):
        return object_path(source)

    def save_baseline(self, source, log: Path):
        """Keep the verified object next to it; inside the build environment, like make.

        Build outputs are only ever written by the container: host-side writes or deletes
        under build/ can leave Docker Desktop's file sharing with a stale view, after
        which `ld` fails to create its outputs (observed: every later ROM check failed)."""
        obj = self.object_path(source)
        if not (self.root/obj).is_file():
            return False
        if self.invoke(['cp', '-p', obj, obj + BASELINE], log):
            raise HarnessError(f'Could not save baseline object for {source}; see {log}')
        return True

    def restore(self, source, original: bytes, saved: bool, log: Path):
        """Return a translation unit to its verified baseline without rebuilding.

        Exact source bytes, the saved baseline object, and no linked outputs: the next
        `make check` must relink instead of trusting timestamps."""
        from .common import atomic_write
        atomic_write(self.root/source, original)
        obj = self.object_path(source)
        args = (['sh', '-c', 'cp -p "$1" "$2" && shift 2 && rm -f "$@"', 'restore', obj + BASELINE, obj, *LINK_OUTPUTS]
                if saved else ['rm', '-f', obj, *LINK_OUTPUTS])
        if self.invoke(args, log):
            raise HarnessError(f'Could not restore the baseline object for {source}; see {log}')

    def disassemble(self, source, symbol):
        # -t: the symbol table lets scoring rebase named rodata labels to section offsets.
        try:
            result = command(self.argv(['mips-linux-gnu-objdump', '-m', 'mips:4300', '-drzt', f'--disassemble={symbol}', self.object_path(source)]), self.root, timeout=90)
        except BaseException:
            self.close()
            raise
        return result.stdout.decode()

    def invalidate(self, sources, log):
        """Headers have no complete make dependencies; rebuild all objects for repairs."""
        if any(p.endswith('.h') for p in sources):
            if self.invoke(['find', 'build/us', '-name', '*.o', '-delete'], log):
                raise HarnessError('Could not invalidate objects after header repair')
        objects = [self.object_path(p) for p in sources if p.endswith('.c')]
        if self.invoke(['rm', '-f', *objects, *LINK_OUTPUTS], log):
            raise HarnessError('Could not invalidate dependency repair outputs')

    def dependencies(self, log):
        code = 'import sqlite3, yaml, spimdisasm, rabbitizer, mapfile_parser, n64img, pygfxd; print("Python build dependencies OK")'
        return self.invoke(['python3', '-c', code], log) == 0


def scratch(root: Path, prefix='decomp-build-') -> Path:
    """A build tree under .decomp-agent/, never $TMPDIR: macOS purges files there once
    their atime is three days old (daily at 03:35), and copies keep the atimes of their
    sources; a live run lost tools/ scripts that way and every later compile failed."""
    base = root/'.decomp-agent/build-tmp'
    base.mkdir(parents=True, exist_ok=True, mode=0o700)
    return Path(tempfile.mkdtemp(prefix=prefix, dir=base)).resolve()


def snapshot(root: Path, prefix='decomp-build-') -> Path:
    """Independent copies, never hardlinks/symlinks to writable original data."""
    target = scratch(root, prefix)
    ignored = shutil.ignore_patterns('.git', '.codex', '.agents', '__pycache__', '.decomp-agent', '*.egg-info')
    try:
        for name in ('src', 'include', 'tools', 'lib', 'asm', 'assets'):
            if (root/name).exists():
                shutil.copytree(root/name, target/name, ignore=ignored)
        library_build = target/'lib/ultralib/build'
        if library_build.exists():
            shutil.rmtree(library_build)
        for path in root.iterdir():
            if path.is_file() and path.suffix in ('.toml', '.txt', '.yaml', '.ld', '.py') or path.name == 'Makefile':
                if path.is_file():
                    shutil.copy2(path, target/path.name)
        for name in ('baserom.us.z64', 'decompressed.us.z64'):
            shutil.copy2(root/name, target/name)
        (target/'build/us').mkdir(parents=True)
        (target/'.harness-snapshot').write_text(str(root))
    except BaseException:
        shutil.rmtree(target)
        raise
    return target


def clone(workspace: Path) -> Path:
    """Private build lane: an independent copy of a built workspace, mtimes kept so make
    only recompiles what changes. APFS clones on macOS cost no space or copy time.
    It lives next to the workspace, for the reason given in scratch()."""
    target = Path(tempfile.mkdtemp(prefix='decomp-lane-', dir=workspace.parent)).resolve()
    try:
        if sys.platform == 'darwin':
            command(['cp', '-cRp', f'{workspace}/.', str(target)], timeout=600)
        else:
            shutil.copytree(workspace, target, symlinks=True, dirs_exist_ok=True)
    except BaseException:
        shutil.rmtree(target)
        raise
    return target
