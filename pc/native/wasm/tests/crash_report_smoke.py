#!/usr/bin/env python3
"""Exercise the release host's fatal path with a missing ROM in an isolated directory."""
import argparse
import os
from pathlib import Path
import subprocess
import tempfile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--exe', type=Path, required=True)
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
