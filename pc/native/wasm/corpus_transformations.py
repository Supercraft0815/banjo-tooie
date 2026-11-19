"""Q2 playable transformations in Humba Wumba's wigwams."""
from corpus_worlds import FLAGS, START_PRESS


def wumba_press(dive=False):
    events = [START_PRESS]
    for t in range(36, 45, 2):
        events.extend((f'{t}:8000', f'{t}.5:0'))
    events.extend(('46:0002', '48:0000'))
    for t in (49, 52, 55):
        events.extend((f'{t}:8000', f'{t}.5:0'))
    for t in range(58, 77, 2):
        events.extend((f'{t}:8000', f'{t}.3:0'))
    # The lagoon pool checks the player's depth. B dives from the surface.
    if dive:
        events.extend(('80:50000000', '81:50004000', '81.2:0', '81.6:B0004000', '82:0',
                       '82.2:B0004000', '82.8:0', '83:B0008000', '84.5:0'))
    else:
        events.extend(('80:50000000', '81:50008000', '81.3:50000000', '82:0'))
    for t in range(91, 109, 2):
        events.extend((f'{t}:8000', f'{t}.3:0'))
    events.extend(('110:00500000', '111:0', '112:8000', '112.4:0'))
    return ','.join(events)


SCENES = (
    ('stony', 0xB6, 176),
    ('detonator', 0xE9, 268),
    ('money-van', 0xD5, 282),
    ('submarine', 0x120, 70),
    ('baby-t-rex', 0x11E, 321),
    ('daddy-t-rex', 0x122, 333),
    ('washer', 0x11F, 142),
    ('snowball', 0x135, 388),
    ('bee', 0x140, 133),
    ('dragon-kazooie', 0x157, 1),
)

CASES = {
    f'wumba-{form}': {
        'flags': FLAGS, 'items': [(0x54 if form == 'dragon-kazooie' else 0x48, 1)],
        'seconds': 117, 'press': wumba_press(dive=form == 'submarine'),
        'warp': f'34:{map_id:X}:1', 'expected_map': map_id, 'expected_player_state': state,
        'dump_every': 300,
    }
    for form, map_id, state in SCENES
}

# Dragon Kazooie shares Banjo's movement state. A live read verified that the
# Mega Glowbo payment (0xDE) and Dragon Kazooie ability (0x3EC) are set in this bank.
CASES['wumba-dragon-kazooie']['expected_permanent_flags_hash'] = '9b088606dbde9a78'
