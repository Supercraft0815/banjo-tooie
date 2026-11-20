#!/usr/bin/env python3
"""Verify a release crash report and optionally stderr on normal exit."""
import argparse
import os
from pathlib import Path
import subprocess
import tempfile

def normal_exit_log(exe, rom, directory, env):
    """Hold stderr full until the short game exits or waits to drain its final log."""
    read_fd, write_fd = os.pipe()
    with os.fdopen(read_fd, 'rb', buffering=0) as reader, os.fdopen(write_fd, 'wb', buffering=0) as writer:
        os.set_blocking(write_fd, False)
        fill = 0
        while True:
            try:
                written = os.write(write_fd, bytes(4096))
            except BlockingIOError:
                break
            if not written:
                break
            fill += written
        os.set_blocking(write_fd, True)
        run_env = dict(env, BT_EXIT_AFTER='.05', BT_RENDER_STATS='1')
        with subprocess.Popen([exe, rom], cwd=directory, env=run_env, stderr=writer) as child:
            writer.close()
            try:
                # The release host exits after 50 ms of gameplay; hold back its output until then.
                try:
                    child.wait(2)
                except subprocess.TimeoutExpired:
                    pass
                remaining = fill
                while remaining:
                    chunk = reader.read(remaining)
                    if not chunk or any(chunk):
                        raise AssertionError('unexpected bytes before stderr output')
                    remaining -= len(chunk)
                if child.wait(30) or b'video: skipped total=' not in reader.read():
                    raise AssertionError('last stderr output lost on successful exit')
            finally:
                if child.poll() is None:
                    child.kill()


parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--exe', type=Path, required=True)
parser.add_argument('--rom', type=Path, help='also check normal exit with a private cartridge')
args = parser.parse_args()
with tempfile.TemporaryDirectory(prefix='bt-crash-report-') as tmp:
    directory = Path(tmp)
    report = directory / 'crash.txt'
    missing = directory / 'missing-cartridge.z64'
    env = {k: v for k, v in os.environ.items() if not k.startswith('BT_')}
    env.update(BT_HEADLESS='1', BT_CRASH_REPORT=str(report), BT_VERSION='release-report-smoke',
               BT_SAVE=str(directory / 'test.eep'))
    result = subprocess.run([str(args.exe.resolve()), str(missing)], cwd=directory, env=env,
                            capture_output=True, timeout=30)
    body = report.read_text(errors='replace') if report.exists() else ''
    for term in ('Type: bt_fatal', 'Version: release-report-smoke', missing.name, 'Last captured log lines:'):
        if term not in body or not result.returncode:
            raise SystemExit(f'crash report check failed at {term!r}, exit {result.returncode}')
    print('PASS release crash report')
    if args.rom:
        normal_exit_log(args.exe.resolve(), args.rom.resolve(), directory, env)
        print('PASS final stderr output')
