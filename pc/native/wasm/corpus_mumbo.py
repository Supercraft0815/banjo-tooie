"""Mumbo's nine playable skulls and the Mingy Jongo encounter in the decoy skull."""
import math

from corpus_worlds import FLAGS, START_PRESS, pad_at_retrace, retrace_seconds


# Each pair holds (NTSC retraces, controller word). Follow the spiral ramp,
# cross the upper floor and walk up to the chair. The three alternate routes
# take the local enemies and camera positions into account.
RAMP = (
    (92, 0x34000000), (46, 0x2CEE0000), (46, 0x30EC0000), (46, 0x34000000),
    (690, 0x30140000), (46, 0x1F1F0000), (138, 0x30140000), (46, 0x34000000),
    (92, 0x11EF0000), (46, 0x00400000), (46, 0x37170000), (46, 0x40000000),
    (18, 0x3BE80000),
)

WITCHYWORLD = (
    (108, 0x34000000), (18, 0x30ED0000), (78, 0x29E00000), (30, 0x31EE0000),
    (40, 0x34FB0000), (120, 0x2E180000), (30, 0x1E2A0000), (46, 0x2C1C0000),
    (20, 0x34060000), (28, 0x33F60000), (8, 0x33090000), (108, 0x2D1A0000),
    (28, 0x330B0000), (56, 0x2C1C0000), (28, 0x320F0000), (28, 0x28210000),
    (30, 0x320E0000), (60, 0x2C1B0000), (44, 0x320E0000), (46, 0x2B1D0000),
    (46, 0x320F0000), (20, 0x3EEC0000), (10, 0x34D90000), (10, 0x1A3C0000),
    (10, 0x0D400000), (10, 0xEB3D0000), (10, 0xFC410000), (10, 0x0D400000),
    (10, 0x26350000), (10, 0x39200000), (30, 0x40080000), (10, 0x3D170000),
    (20, 0x400A0000), (10, 0x38210000), (10, 0x26350000), (10, 0x0F3F0000),
    (10, 0xFB410000), (20, 0xED3E0000), (40, 0x1C3B0000), (10, 0x1C3B8000),
    (40, 0x1C3B0000), (10, 0x1C3B8000), (40, 0x1C3B0000), (10, 0x1C3B8000),
    (40, 0x1C3B0000), (10, 0x1C3B8000), (40, 0x1C3B0000), (10, 0x1C3B8000),
    (30, 0x1C3B0000),
)

FACTORY = (
    (90, 0x34000000), (30, 0x33F60000), (30, 0x2BE30000), (30, 0x30EC0000),
    (30, 0x32F10000), (30, 0x34050000), (30, 0x30140000), (30, 0x2E190000),
    (30, 0x320F0000), (30, 0x2E190000), (30, 0x28210000), (60, 0x30140000),
    (30, 0x25250000), (30, 0x30140000), (30, 0x2B1D0000), (30, 0x2E190000),
    (30, 0x30140000), (30, 0x2E190000), (30, 0x320F0000), (30, 0x2B1D0000),
    (60, 0x2E190000), (30, 0x30140000), (60, 0x320F0000), (30, 0x2B1D0000),
    (30, 0x320F0000), (30, 0x34050000), (30, 0x32F10000), (30, 0xFA3C0000),
    (30, 0x11390000), (60, 0x3D130000), (30, 0x262E0000), (30, 0xED3D0000),
    (30, 0x133D0000), (254, 0x1E380000),
)

CLOUD = (
    (108, 0x34000000), (10, 0x30ED0000), (8, 0x2DE70000), (20, 0x29E00000),
    (10, 0x2EE70000), (10, 0x34FD0000), (10, 0x33070000), (10, 0x320F0000),
    (10, 0x2F160000), (10, 0x2C1C0000), (40, 0x26240000), (10, 0x2B1D0000),
    (10, 0x2E180000), (20, 0x30140000), (10, 0x34FA0000), (10, 0x2FEB0000),
    (18, 0x2EE70000), (10, 0x31EE0000), (18, 0x34060000), (8, 0x30140000),
    (10, 0x34070000), (10, 0x31120000), (28, 0x2C1B0000), (18, 0x31120000),
    (42, 0x320E0000), (10, 0x29200000), (18, 0x23260000), (10, 0x2A1E0000),
    (8, 0xF8330000), (10, 0xE52C0000), (10, 0xD9230000), (40, 0xD41C0000),
    (10, 0xD7200000), (10, 0xDC260000), (10, 0x2C1B0000), (10, 0x33090000),
    (28, 0x34020000), (10, 0x2F160000), (30, 0x27220000), (10, 0x2D190000),
    (20, 0x30150000), (10, 0x31110000), (18, 0x27230000), (8, 0x30140000),
    (10, 0x2C1C0000), (10, 0x320F0000), (10, 0x34030000), (10, 0x30140000),
    (28, 0x2B1D0000), (18, 0x2F160000), (38, 0x31110000), (10, 0x2A1E0000),
    (20, 0x24260000), (10, 0x32100000), (8, 0x34070000), (8, 0x30150000),
    (28, 0x2A1E0000), (10, 0x2F160000), (40, 0x31120000), (30, 0x330C0000),
    (38, 0x2C1C0000), (8, 0x30140000), (18, 0x320F0000), (28, 0x330B0000),
    (10, 0x3EED0000), (10, 0x3CE70000), (10, 0x34D90000), (10, 0x1D3A0000),
    (10, 0x103F0000), (10, 0xEA3D0000), (10, 0xFA410000), (10, 0x0C400000),
    (10, 0x26350000), (10, 0x38200000), (20, 0x40090000), (10, 0x3F0E0000),
    (10, 0x3D160000), (20, 0x400B0000), (10, 0x38210000), (10, 0x26350000),
    (10, 0x0F3F0000), (10, 0xFB410000), (10, 0xED3E0000), (10, 0xE33A0000),
    (40, 0x1C3B0000), (10, 0x1C3B8000), (40, 0x1C3B0000), (10, 0x1C3B8000),
    (40, 0x1C3B0000), (10, 0x1C3B8000), (40, 0x1C3B0000), (10, 0x1C3B8000),
    (40, 0x1C3B0000), (10, 0x1C3B8000), (30, 0x1C3B0000),
)

def skull_case(map_id, route, paid_flags=None):
    events = [START_PRESS]
    frame = 2242
    for duration, mask in route:
        events.append(pad_at_retrace(frame, mask))
        frame += duration
    arrived = retrace_seconds(frame)
    events.append(f'{arrived - 0.00000001:.11f}:0')
    for i in range(25):
        at = arrived + 2 + 2.5 * i
        if paid_flags is None and at >= 120:
            break
        events.extend((f'{at:.6f}:8000', f'{at + .16:.6f}:0'))
    case = {'flags': FLAGS, 'items': [(0x48, 1)], 'warp': f'34:{map_id:X}:1',
            'expected_map': map_id, 'dump_every': 300}
    if paid_flags is None:
        events.extend(('120:5000a000', '120.4:0', '121:0050a000', '121.4:0',
                       '122:b000a000', '122.4:0', '123:8000', '123.3:0', '124:4000', '124.2:0'))
        case.update(seconds=128, boss='mingy-jongo', expected_actor_state=(0x816, 17))
    else:
        # Walk as Mumbo and use the staff. Banjo remains seated in player slot 0.
        walk = 124 if route is RAMP else arrived + 64
        events.extend((f'{walk:.5f}:35000000', f'{walk + .65:.5f}:0',
                       f'{walk + 1.1:.5f}:4000', f'{walk + 1.4:.5f}:0'))
        case.update(seconds=math.ceil(walk + 4), expected_players=2, expected_player_slot=1,
                    expected_player_state=239, expected_permanent_flags_hash=paid_flags)
    return dict(case, press=','.join(events))


SCENES = (
    ('mt', 0xB7, RAMP, '02cae36cc93c20ea'),
    ('ggm', 0xD9, RAMP, '9f5ba2a1e5d643e9'),
    ('ww', 0x176, WITCHYWORLD, '4a51f6539a956ff0'),
    ('jrl', 0xEF, RAMP, 'aa46ebdbd52cefa6'),
    ('tdl', 0x171, RAMP, '188dc62290cb60d2'),
    ('gi', 0x172, FACTORY, '6ba2f7811c950bea'),
    ('hfp', 0x134, RAMP, 'b7a085f7cfbf5e3a'),
    ('ccl', 0x13E, CLOUD, '829fb60e20020c0a'),
    ('ioh', 0x156, RAMP, '5b30b4ebfb3ce92a'),
)
CASES = {f'mumbo-{name}': skull_case(map_id, route, flags) for name, map_id, route, flags in SCENES}
CASES['mingy-jongo'] = skull_case(0x13F, RAMP)
