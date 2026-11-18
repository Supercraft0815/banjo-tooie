"""Two-controller replays from the title screen through the real Multiplayer menu."""

from save_editor import START_ABILITIES

# Move the hand from file 1 down to the bin, then right to the N64 on the table.
CONSOLE = ('0:0,10:1000,10.2:0,14:1000,14.2:0,18:1000,18.2:0,22:1000,22.2:0,'
           '30:b0000000,30.45:0,32:00500000,32.2:0,35:8000,35.15:0')
A, START, DOWN = '8000', '1000', 'b0000000'
GAMES = (
    ('temple-shootout', 0x166), ('mayan-kickball', 0x17F), ('ordnance-shootout', 0x165),
    ('dodgems', 0x186), ('hoop-hurry', 0x17C), ('balloons', 0x17B),
    ('submarine', 0x182), ('chompas-belly', 0x183), ('clinkers-cavern', 0x164),
    ('packing', 0x17D), ('colosseum-kickball', 0x180), ('trashcan', 0x185),
    ('bee-hive', 0x188), ('quiz', 0x189),
)


def tap(time, mask):
    return f',{time}:{mask},{time + 0.15:g}:0'


def round_case(menu, seconds, map_id, second='0:0'):
    # Both players move and act after play begins. The trace checks both player records.
    return {'seconds': seconds, 'flags': START_ABILITIES, 'expected_map': map_id,
            'expected_players': 2, 'dump_every': 120,
            'press': CONSOLE + menu + tap(seconds - 10, '00502000') + tap(seconds - 6, A),
            'press2': second + tap(seconds - 10, '00b02000') + tap(seconds - 6, A)}


def single_game(index, map_id):
    menu = tap(39, A) + tap(43, A)
    if index == 0:
        # Open Pick Characters, have each pad confirm, then start from the options menu.
        return round_case(menu + tap(47, A) + tap(51, A) + tap(55, A) + tap(62, START),
                          93, map_id, '0:0' + tap(56, A))
    select = 48 + index
    menu += ''.join(tap(46 + i, DOWN) for i in range(index)) + tap(select, A)
    if index in (2, 8):  # Shootouts have a separate options page.
        menu += tap(select + 4, START)
    if index in (6, 12, 13):  # Submarine, bees and quiz ask for a game length.
        menu += tap(select + 4, A)
    if index == 5:
        # Fire into the balloon room while the targets are still in view.
        case = round_case(menu, 71, map_id)
        case['press'] += tap(67, '2000') + tap(69, '2000')
        return case
    if index == 13:
        # Both players are present through the first question and answer.
        # The following video question temporarily unloads the player actors.
        case = round_case(menu + tap(77, '4000') + tap(86, A), 104, map_id,
                          '0:0' + tap(92, '4000'))
        case['press'] += tap(100, '4000')
        return case
    duration = {4: 20, 11: 20}.get(index, 30)
    return round_case(menu, select + duration, map_id)


CASES = {
    'mp-menu': {'seconds': 40, 'flags': START_ABILITIES, 'expected_map': 0x158,
                'press': CONSOLE, 'press2': '0:0', 'dump_every': 120},
    **{'mp-' + name: single_game(index, map_id) for index, (name, map_id) in enumerate(GAMES)},
    'mp-some-games': round_case(tap(39, A) + tap(42, DOWN) + tap(45, A) + tap(49, A)
                                + tap(51, DOWN) + tap(53, A) + tap(56, START) + tap(64, START), 89, 0x166),
    'mp-all-games': round_case(tap(39, A) + tap(42, DOWN) + tap(43, DOWN) + tap(46, A)
                               + tap(54, START), 83, 0x166),
}
