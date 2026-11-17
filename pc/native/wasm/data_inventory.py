#!/usr/bin/env python3
"""Audit Phase-1 data ownership. Run after build.py; output contains metadata, not ROM bytes."""
import argparse
import json
from pathlib import Path
import re

import build
import data


def scan(files, definitions, declarations):
    sections = []
    for path in files:
        for section, labels, items in data.parse_file(path):
            if section == 'text' or not labels:
                continue
            base, end = data.span(labels, items)
            refs, raw_stubs = set(), set()
            for _, _, kind, value in items:
                if kind not in ('word', 'float'):
                    continue
                text, raw = value
                match = data.SYMREF.fullmatch(text)
                if match:
                    refs.add(match[1])
                elif raw and int(raw, 16) in data.STUBS:
                    raw_stubs.add(data.STUBS[int(raw, 16)])
            sections.append({'file': str(path), 'section': section, 'bytes': end - base,
                             'labels': [{'name': name, 'offset': address - base,
                                         'defined_in_c': name in definitions,
                                         'declaration_known': name in declarations}
                                        for name, address in sorted(labels.items(), key=lambda row: (row[1], row[0]))],
                             'symbol_references': sorted(refs), 'raw_syscall_pointers': sorted(raw_stubs)})
    return sections


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    tag = build.guest_object_tag()
    objects = [build.OUT / 'obj' / tag / (source.replace('/', '__') + '.o') for source in build.sources()]
    missing = [str(obj) for obj in objects if not obj.exists()]
    if missing:
        parser.exit(2, 'Run build.py first; missing objects: ' + ', '.join(missing[:5]) + '\n')
    definitions, undefined = build.nm(objects)
    definitions = {name for name, kind in definitions.items() if kind.upper() in 'DBRCV'}
    declarations = build.c_types(objects)
    files = build.data_files()
    sections = scan(files, definitions, declarations)
    for section in sections:
        section['file'] = str(Path(section['file']).relative_to(build.ROOT))
    labels = [label for section in sections for label in section['labels']]
    remaining = sorted({label['name'] for label in labels if not label['defined_in_c']})
    report = {'format': 'bt-data-inventory-1', 'summary': {
        'build_input_files': len(files), 'files_with_data_labels': len({row['file'] for row in sections}),
        'sections': len(sections),
        'labels': len(labels), 'remaining_asm_labels': len(remaining),
        'remaining_R_labels': len([name for name in remaining if name.startswith('R_')]),
        'R_defined_in_c': sum(name.startswith('R_') for name in definitions),
        'unresolved_R_references': sorted(name for name in undefined if name.startswith('R_') and name not in definitions),
        'declared_but_not_defined': sum(label['declaration_known'] and not label['defined_in_c'] for label in labels),
        'raw_syscall_pointer_sections': sum(bool(row['raw_syscall_pointers']) for row in sections)},
        'remaining_R_labels': [name for name in remaining if name.startswith('R_')],
        'sections': sections,
        'warning': 'Declarations and directive widths do not prove complete types or cross-symbol safety.'}
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['summary'], indent=2))


if __name__ == '__main__':
    main()
