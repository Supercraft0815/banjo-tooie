"""Board the handcart and flying saucer using the normal single-player controls."""
import math

from corpus_worlds import FLAGS, START_PRESS, pad_at_retrace, retrace_seconds

HANDCART = (
    (2242, 0x0BC70000), (2251, 0x0EC80000), (2260, 0x18CB0000), (2269, 0x20D00000),
    (2278, 0x27D50000), (2287, 0x2EDD0000), (2296, 0x34E60000), (2305, 0x36EB0000),
    (2314, 0x37EE8000), (2323, 0x37EC0000), (2332, 0x36EA0000), (2341, 0x35E70000),
    (2350, 0x2FDE0000), (2377, 0x2FDE8000), (2386, 0x2FDE0000), (2395, 0x2FDE8000),
    (2404, 0x2FDE0000),
)

SAUCER = (
    (2242, 0x3A010000), (2260, 0x3A020000), (2269, 0x3A030000), (2278, 0x3A050000),
    (2287, 0x390A8000), (2296, 0x380D0000), (2305, 0x00000000), (2323, 0x00008000),
    (2332, 0x00000000), (2359, 0x00008000), (2368, 0x00000000),
)

def ride_case(approach, boarding_frame, origin, destination, flags, actor_state):
    # On the cart, tap A to accelerate. On the saucer, dismiss the instructions
    # with A and fire Z at the targets that pass the crosshair.
    events = [START_PRESS, *(pad_at_retrace(frame, mask) for frame, mask in approach)]
    boarded = retrace_seconds(boarding_frame)
    seconds = math.floor(boarded + 36)
    events.append(f'{boarded:.9f}:0')
    for i in range(180):
        at = boarded + .2 + i * .2
        button = '8000' if approach is HANDCART or i < 55 else '2000'
        events.extend((f'{at:.5f}:{button}', f'{at + .1:.5f}:0'))
    return {'flags': FLAGS + flags, 'seconds': seconds, 'press': ','.join(events),
            'warp': origin, 'expected_map': destination, 'expected_actor_state': actor_state,
            'dump_every': 180}


CASES = {
    'canary-mary-race': ride_case(HANDCART, 2413, '34:C7:21', 0x16F,
                                  (0x66, 0x507, 0x508, 0x57A), (0x67C, 6)),
    'saucer-of-peril': ride_case(SAUCER, 2377, '34:D6:8', 0x124,
                                 (0x94, 0xEB, 0x414), (0x690, 5)),
}
