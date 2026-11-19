"""Guest views of the contiguous RSP program and constant sections in US core1."""

PROGRAMS = ('n_aspMain', 'rspboot', 'gspF3DEX2.NoN.fifo', 'gspF3DEX2.fifo', 'gspL3DEX2.fifo')


def linker_views(addresses):
    views = []
    sizes = {}
    for section, programs in [('Text', PROGRAMS), ('Data', [p for p in PROGRAMS if p != 'rspboot'])]:
        storage = 'bt_rsp_' + section.lower()
        start = addresses['n_aspMain' + section + 'Start']
        end = start
        for program in programs:
            label = program.replace('.', '_') + section
            if addresses[label + 'Start'] != end or addresses[label + 'End'] <= end:
                raise ValueError(f'noncontiguous RSP section at {label}')
            end = addresses[label + 'End']
            for edge in ('Start', 'End'):
                symbol = label + edge
                views.append(f'{symbol} {storage} {addresses[symbol] - start}')
        sizes[section] = end - start
    return views, sizes


def wrapper_paths(root):
    paths = set()
    for program in PROGRAMS:
        path = root / 'asm/data/core1' / (program + '.s')
        if path.exists():
            symbol = program.replace('.', '_')
            expected = ['.include "macro.inc"']
            for section, edge, kind, flags in [('text', 'Text', 'textbin', 'ax'),
                                                ('rodata', 'Data', 'rodatabin', 'a')]:
                if program == 'rspboot' and edge == 'Data':
                    continue
                expected += [f'.section .{section}, "{flags}"', f'glabel {symbol}{edge}Start',
                             f'.incbin "assets/core1/{program}.{kind}.bin"', f'glabel {symbol}{edge}End']
            if [line.strip() for line in path.read_text().splitlines() if line.strip()] != expected:
                raise ValueError(f'{path}: unexpected data alongside the RSP binary')
        paths.add(str(path))
    return paths
