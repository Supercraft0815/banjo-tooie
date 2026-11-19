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


# For a retry, the game reads its permanent retry flag when it loads the arena.
# The second dragon entrance spawns on the upper platform and Terry's third
# entrance is inside the nest. The actor and state come from each boss overlay.
retry_press = battle_press(attack_at=68, attacks=50)
_BOSSES = (
    # name, map, entrance, seconds, save flags, controller inputs, active actor state
    ('targitzan', 0x17A, 1, 64, (), fast_battle_press(), (0x7F4, 5)),
    ('old-king-coal', 0xD1, 1, 64, (), battle_press(), (0x650, 4)),
    ('mr-patch', 0xF9, 1, 64, (0x17F,), battle_press(approach=True), (0x794, 6)),
    ('lord-woo-fak-fak', 0xFC, 1, 120, (), battle_press(attack_at=100, attacks=32), (0x7F9, 8)),
    ('terry', 0x113, 3, 95, (0x172,), retry_press, (0x6DA, 10)),
    ('weldar', 0x110, 1, 95, (0x174,), retry_press, (0x817, 17)),
    ('chilli-billi', 0x12B, 2, 95, (0x1D4,), retry_press, (0x7FC, 10)),
    ('chilly-willy', 0x12C, 2, 95, (0x1D3,), retry_press, (0x7FD, 10)),
    ('hag-1', 0x19A, 1, 95, (0x39B, 0x44), retry_press, (0x901, 6)),
)

CASES = {
    name: {
        'flags': FLAGS + flags, 'seconds': seconds, 'press': press, 'dump_every': 300,
        'warp': f'34:{map_id:X}:{entrance}', 'expected_map': map_id,
        'boss': name, 'expected_actor_state': actor_state,
    }
    for name, map_id, entrance, seconds, flags, press, actor_state in _BOSSES
}
CASES['hag-1']['expected_spawns'] = {0x901: (0, 7500, 0), 0x8FE: (0, 7500, 0)}
