#!/usr/bin/env python3
"""Create/verify compact cross-build digests for real BT_TRACE references.

The manifest contains only SHA-256 digests and retrace counts. It cannot replace a
trace file for diagnosis, but lets private CI verify each full reference trace
without publishing or transferring the ROM-derived JSONL corpus.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys

import trace_tools


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode()


def digest_trace(path):
    digest = hashlib.sha256()
    with Path(path).open() as stream:
        header = trace_tools.read_trace(stream)
        header = dict(header, build=None)  # Same cross_build rule as trace_tools.compare.
        digest.update(canonical(header) + b'\n')
        count = 0
        for count, line in enumerate(stream, 1):
            row = trace_tools.read_retrace(line, count)
            digest.update(canonical(row) + b'\n')
    if not count:
        raise ValueError(f'{path}: empty trace')
    return {'retrace_count': count, 'sha256': digest.hexdigest()}


def generate(reference_dir):
    entries = {}
    for path in sorted(Path(reference_dir).glob('*.jsonl')):
        entries[path.stem] = digest_trace(path)
    if not entries:
        raise ValueError(f'no JSONL references in {reference_dir}')
    return {'format': 'bt-reference-digests-1', 'normalization': 'trace_tools.compare(cross_build=True)',
            'cases': entries}


def verify(trace, case, manifest):
    data = json.loads(Path(manifest).read_text())
    if data.get('format') != 'bt-reference-digests-1':
        raise ValueError('unsupported reference digest manifest')
    expected = data.get('cases', {}).get(case)
    if expected is None:
        raise ValueError(f'case {case!r} missing from reference digest manifest')
    actual = digest_trace(trace)
    if actual != expected:
        raise ValueError(f'{case}: reference digest mismatch (expected {expected}, got {actual})')
    print(f'PASS {case}: {actual["retrace_count"]} retraces match SHA-256 reference digest')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='command', required=True)
    make = sub.add_parser('generate')
    make.add_argument('reference_dir', type=Path)
    make.add_argument('output', type=Path)
    check = sub.add_parser('verify')
    check.add_argument('trace', type=Path)
    check.add_argument('case')
    check.add_argument('manifest', type=Path)
    args = parser.parse_args()
    try:
        if args.command == 'generate':
            result = generate(args.reference_dir)
            args.output.write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
            print(f'{len(result["cases"])} real references digested: {args.output}')
        else:
            verify(args.trace, args.case, args.manifest)
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        parser.exit(1, f'FAIL: {exc}\n')


if __name__ == '__main__':
    main()
