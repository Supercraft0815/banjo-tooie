#!/usr/bin/env python3
"""Audit Phase-1 data ownership. Run after build.py; output contains metadata, not ROM bytes."""
import argparse
import json
from pathlib import Path
import re
import subprocess

import build
import data
import irtypes


def classify_label(name, size, c_type=None):
    """Name-based media candidates only; never claims that opaque bytes are decoded."""
    if size <= 1024:
        return None
    if c_type and re.search(r'\bGfx\b', c_type):
        return {'kind': 'display-list-type', 'evidence': c_type}
    if c_type and re.search(r'(?:Texture|Texel|uObjTxtr|Image)', c_type, re.I):
        return {'kind': 'texture-type', 'evidence': c_type}
    if re.search(r'(?:display.?list|(?:^|[_.$])dl(?:[_0-9.$]|$)|glist|gfx)', name, re.I):
        return {'kind': 'display-list-candidate', 'evidence': 'symbol name'}
    if re.search(r'(?:texture|texel|tlut|(?:^|[_.$])tex(?:[_0-9.$]|$)|(?:^|[_.$])(?:rgba|ci|ia|i)\d+)', name, re.I):
        return {'kind': 'texture-candidate', 'evidence': 'symbol name'}
    if re.search(r'(?:sound|audio|sample|sequence|rsp)', name, re.I):
        return {'kind': 'audio-candidate', 'evidence': 'symbol name'}
    if re.search(r'(?:font|dialog|message|\btext\b|string)', name, re.I):
        return {'kind': 'text-candidate', 'evidence': 'symbol name'}
    return {'kind': 'unclassified-large', 'evidence': 'label spans > 1 KiB; payload not decoded'}


def external_c_types(objects):
    """Preserve named LLVM C types for data labels; sizes alone do not identify media."""
    global_decl = re.compile(r'^@(?:"([^"]+)"|([^ ]+)) = external global (.+?)(?:, align \d+)?$')
    out = {}
    for obj in objects:
        types = Path(obj).with_suffix('.types')
        if not types.is_file():
            continue
        for line in types.read_text(errors='replace').splitlines():
            match = global_decl.match(line)
            if not match:
                continue
            name = match.group(1) or match.group(2)
            candidates = re.findall(r'%([\w.$]+)', match.group(3))
            if candidates:
                out[name] = candidates[-1]
    return out


def compiled_large_labels(lines, symbols):
    """Read the types of initialized game globals that have moved out of assembly."""
    named = {}
    labels = []
    global_decl = re.compile(r'^@("?[^" =]+"?) = [^=]*?\b(?:global|constant) ')
    for line in lines:
        typedef = irtypes.TYPEDEF.match(line)
        if typedef and typedef[2] != 'opaque':
            named[typedef[1]] = irtypes.parse_type(typedef[2])[0]
        match = global_decl.match(line)
        if not match or (name := match[1].strip('"')) not in symbols:
            continue
        ty, end = irtypes.parse_type(line, match.end())
        initializer = line[end:].lstrip()
        if initializer.startswith(('zeroinitializer', ',', 'undef')) or not initializer:
            continue
        size = irtypes.layout(ty, named)[0]
        if size <= 1024:
            continue
        spelling = line[match.end():end]
        labels.append({'name': name, 'bytes': size, 'c_type': spelling,
                       'media_candidate': classify_label(name, size, spelling)})
    return sorted(labels, key=lambda item: item['name'])


def scan(files, definitions, declarations, c_types=None):
    c_types = c_types or {}
    sections = []
    for path in files:
        for section, labels, items in data.parse_file(path):
            if section == 'text' or not labels:
                continue
            base, end = data.span(labels, items)
            ordered = sorted((address, name) for name, address in labels.items())
            label_sizes = {}
            for i, (address, name) in enumerate(ordered):
                stop = next((a for a, _ in ordered[i + 1:] if a > address), end)
                label_sizes[name] = max(0, stop - address)
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
                                         'bytes': label_sizes[name],
                                         'c_type': c_types.get(name),
                                         'defined_in_c': name in definitions,
                                         'declaration_known': name in declarations,
                                         'media_candidate': classify_label(name, label_sizes[name], c_types.get(name))}
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
    type_names = external_c_types(objects)
    files = build.data_files()
    sections = scan(files, definitions, declarations, type_names)
    for section in sections:
        section['file'] = str(Path(section['file']).relative_to(build.ROOT))
    labels = [label for section in sections for label in section['labels']]
    remaining = sorted({label['name'] for label in labels if not label['defined_in_c']})
    large = [dict(file=s['file'], section=s['section'], **label)
             for s in sections for label in s['labels'] if label['bytes'] > 1024]
    with subprocess.Popen([build.tool('llvm-dis'), str(build.OUT / 'game.linked.bc'), '-o', '-'],
                          stdout=subprocess.PIPE, text=True) as ir:
        compiled = compiled_large_labels(ir.stdout, definitions - {label['name'] for label in labels})
    if ir.returncode:
        parser.exit(2, 'Could not read the linked game bitcode.\n')
    large.extend(dict(file='game.linked.bc', section='initialized C data', **label) for label in compiled)
    candidates = [label for label in large if label['media_candidate'] and
                  label['media_candidate']['kind'] != 'unclassified-large']
    report = {'format': 'bt-data-inventory-1', 'summary': {
        'build_input_files': len(files), 'files_with_data_labels': len({row['file'] for row in sections}),
        'sections': len(sections),
        'labels': len(labels), 'remaining_asm_labels': len(remaining),
        'remaining_R_labels': len([name for name in remaining if name.startswith('R_')]),
        'R_defined_in_c': sum(name.startswith('R_') for name in definitions),
        'unresolved_R_references': sorted(name for name in undefined if name.startswith('R_') and name not in definitions),
        'declared_but_not_defined': sum(label['declaration_known'] and not label['defined_in_c'] for label in labels),
        'raw_syscall_pointer_sections': sum(bool(row['raw_syscall_pointers']) for row in sections),
        'labels_over_1kib': len(large), 'compiled_labels_over_1kib': len(compiled),
        'named_media_candidates_over_1kib': len(candidates)},
        'remaining_R_labels': [name for name in remaining if name.startswith('R_')],
        'sections': sections,
        'large_labels_over_1kib': large,
        'large_media_candidates': candidates,
        'warning': 'Declarations and directive widths do not prove complete types or cross-symbol safety.'}
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['summary'], indent=2))


if __name__ == '__main__':
    main()
