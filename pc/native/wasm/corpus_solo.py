"""Use the two split-up pads in Terrydactyland's Oogle Boogle cave."""
import math
import struct

from corpus_worlds import FLAGS, START_PRESS, pad_at_retrace, retrace_seconds


SPLIT = (
    (2242, 0x36F90000), (2272, 0x35F80000), (2302, 0x35F50000), (2332, 0x35F70000),
    (2362, 0x35F50000), (2392, 0x33ED0000), (2422, 0xCA000000), (2452, 0xCA030000),
    (2482, 0x340F0000), (2512, 0x35090000), (2542, 0x35070000), (2572, 0x350B0000),
    (2602, 0x34100000), (2632, 0x36F90000), (2662, 0x35F40000), (2692, 0x34F30000),
    (2722, 0x30E80000), (2752, 0xCB080000), (2782, 0xCC0E0000), (2812, 0x36040000),
    (2842, 0x36FE0000), (2872, 0x36FD0000), (2902, 0x35F80000), (2932, 0x35F50000),
    (3172, 0x34F20000), (3202, 0x35F60000), (3232, 0x22D60000), (3262, 0xCE160000),
    (3292, 0x00000000), (3472, 0x00008000), (3473, 0x00000000), (3953, 0x00008000),
    (3954, 0x00000000), (4434, 0x00008000), (4435, 0x00000000),
)

BANJO = (
    (4915, 0xF5CD0000),
    (4945, 0x0CCD0000), (4975, 0xEF310000), (5005, 0xF8330000), (5035, 0x24260000),
    (5065, 0xE0D70000), (5095, 0xDFD80000), (5125, 0x00000000), (5245, 0x00000000),
)

KAZOOIE = ((4900, 0x8000), (4901, 0), (4930, 0xF5CD0000), (4990, 0))

CASES = {
    name: {
        'flags': FLAGS + (0x109,), 'warp': '34:112:2', 'expected_map': 0x115,
        'press': ','.join([START_PRESS, *(pad_at_retrace(t, mask) for t, mask in SPLIT + movement)]),
        'seconds': retrace_seconds(5245), 'expected_players': 2, 'solo_slot': slot,
        'dump_every': 300,
    }
    for slot, (name, movement) in enumerate((('solo-banjo', BANJO), ('solo-kazooie', KAZOOIE)))
}


class SplitMovement:
    def __init__(self, active_slot):
        self.active = active_slot
        self.origin = None
        self.moved = False

    def observe(self, row):
        players = row['players'][:2]
        if self.moved or len(players) != 2 or not all(p['present'] for p in players):
            return
        points = [struct.unpack('>3f', struct.pack('>3I', *p['position'])) for p in players]
        if self.origin is None:
            split_pads = {a['id'] for a in row['actors'] if (a['health_flags'][5] >> 10 & 63) == 2}
            if ({0x7E1, 0x7E2} <= split_pads and
                    math.dist(points[0], (840, 0, -124)) <= 50 and
                    math.dist(points[1], (841, 15, 124)) <= 10):
                self.origin = points
        else:
            parked = 1 - self.active
            self.moved = (math.dist(points[self.active], self.origin[self.active]) >= 100 and
                          math.dist(points[parked], self.origin[parked]) <= 12)
