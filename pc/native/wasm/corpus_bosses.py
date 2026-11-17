"""Q2 boss encounter cases for corpus.record; boss-completion flags stay clear."""

from corpus_worlds import FLAGS, START_PRESS


def fast_battle_press():
    events = [START_PRESS]
    # Start at the standard file-select entry point, then warp at 34 s into
    # the encounter map. Alternate forward/turning movement with jump, attack
    # and egg controls so the actor receives live combat input after its intro.
    actions = (0x5000E000, 0x0050E000, 0xB000E000, 0x00B0E000,
               0x5000A000, 0x0050A000, 0xB000A000, 0x00B0A000)
    for index in range(48):
        events.append(f'{36 + index / 2:g}:{actions[index % len(actions)]:08X}')
    return ','.join(events)


def battle_press(approach=False, attack_at=56, attacks=16):
    events = [START_PRESS]
    if approach:
        for index in range(16):
            mask = 0x50008000 if index % 2 == 0 else 0x50000000
            events.append(f'{36 + index / 2:g}:{mask:08X}')
    for t in range(44 if approach else 36, attack_at, 2):
        events.extend((f'{t}:8000', f'{t}.2:0'))
    for index in range(attacks):
        events.append(f'{attack_at + index / 2:g}:{0xE000 if index % 2 == 0 else 0:08X}')
    return ','.join(events)


# The longer dialogue in Woo Fak Fak's encounter needs a later attack sequence.
_BOSSES = (
    ('targitzan', 0x17A, 64, (), fast_battle_press()),
    ('old-king-coal', 0xD1, 64, (0x86, 0x179), battle_press()),
    ('mr-patch', 0xF9, 64, (0x9C, 0x17F), battle_press(approach=True)),
    ('lord-woo-fak-fak', 0xFC, 120, (0x1AF, 0x377), battle_press(attack_at=100, attacks=32)),
    ('terry', 0x113, 64, (0xE5, 0x172), battle_press(approach=True)),
)

CASES = {
    name: {
        'flags': FLAGS, 'seconds': seconds, 'press': press,
        'warp': f'34:{map_id:X}:1', 'expected_map': map_id,
        'boss': name, 'source_flags_left_clear': list(boss_flags),
    }
    for name, map_id, seconds, boss_flags, press in _BOSSES
}

# Separate later-game encounter: source has the arena and defeat/retry flags,
# but no mapped Hag 1 actor routine is present in the C overlays.
OPEN_COVERAGE = {
    'hag-1': {'expected_map': 0x19A, 'defeated_flag': 0x043, 'retry_flag': 0x044,
              'reason': 'arena is named; no matching Hag 1 overlay/setup source found'},
    'weldar': {'tested_maps': [0x10A, 0x109], 'retry_flag': 0x174,
               'reason': 'both traces repeat, but screenshots show only wall/ceiling; no active encounter verified'},
    'chilly-willy': {'entry_map': 0x12C, 'attempted_expected_map': 0x128,
                     'retry_flag': 0x1D3, 'reason': 'trace ended on 0x12C; no dragon visible'},
    'chilli-billi': {'entry_map': 0x12B, 'attempted_expected_map': 0x127,
                     'retry_flag': 0x1D4, 'reason': 'trace ended on 0x12B; no dragon visible'},
    'mingy-jongo': {'entry_map': 0x13F, 'flags': [0x296, 0x408],
                    'reason': 'trace repeats, but visible actor not yet matched to actor opcode/model'},
}
