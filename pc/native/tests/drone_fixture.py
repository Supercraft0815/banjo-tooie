"""Generate test callbacks and expectations from the original drone data table."""

import re
import sys
from pathlib import Path


def main():
    source, output = map(Path, sys.argv[1:])
    entries = re.findall(r"\.(byte|word)\s+(\w+)", source.read_text())
    if entries[:4] != [("byte", "0x01")] + [("byte", "0x00")] * 3:
        raise ValueError("unexpected initial drone type/padding")
    if len(entries) != 83 or any(kind != "word" for kind, _ in entries[4:]):
        raise ValueError("expected 16 original 20-byte drone entries")
    words = ["0x01000000"] + [value for _, value in entries[4:]]
    rows = [words[i:i + 5] for i in range(0, len(words), 5)]
    if [int(row[0], 16) for row in rows] != [i << 24 for i in range(1, 16)] + [0]:
        raise ValueError("unexpected drone state order")
    names = list(dict.fromkeys(name for row in rows for name in row[1:]
                               if name != "0x00000000"))
    ids = {name: i + 1 for i, name in enumerate(names)}
    ids["0x00000000"] = 0
    code = ['#include "overlays/bs/drone.h"', '#include "overlays/ba/drone.h"',
            '#include "native_drone_states.h"', '#include <stdlib.h>',
            'static PlayerState *expected_player;', 'static int called;',
            'static void check(int condition) { if (!condition) abort(); }',
            'int func_80800000_bsdrone(PlayerState *);']
    for name in names:
        code.append(f'void {name}(PlayerState *self) {{ '
                    f'check(self == expected_player); called = {ids[name]}; }}')
    code.append('static const int expected[16][4] = {')
    code.extend('    {' + ', '.join(str(ids[name]) for name in row[1:]) + '},'
                for row in rows)
    code.append('};')
    code.append('''
int main(void) {
    PlayerState players[2] = {0};
    BaDrone drones[2] = {0};
    void (*dispatch[4])(PlayerState *) = {
        _bsdrone_entrypoint_0, _bsdrone_entrypoint_1,
        _bsdrone_entrypoint_2, _bsdrone_entrypoint_3
    };
    for (int player = 0; player < 2; player++) {
        expected_player = &players[player];
        expected_player->drone = &drones[player];
        for (int type = 0; type < 256; type++) {
            int row = type > 0 && type < 16 ? type - 1 : 0;
            expected_player->drone->type = type;
            expected_player->drone->pending_type = type;
            check(func_80800000_bsdrone(expected_player) == row);
            for (int phase = 0; phase < 4; phase++) {
                if (type == 5 && phase != 3) continue;
                called = 0;
                if (phase == 0) expected_player->drone->type = 2;
                dispatch[phase](expected_player);
                check(called == expected[row][phase]);
            }
        }
    }
    for (int row = 0; row < 16; row++) {
        const NativeDroneState *state = &D_80800180_bsdrone[row];
        check(state->type == (row == 15 ? 0 : row + 1));
        check((state->init == NULL) == (expected[row][0] == 0));
        check((state->update == NULL) == (expected[row][1] == 0));
        check((state->end == NULL) == (expected[row][2] == 0));
        check((state->interrupt == NULL) == (expected[row][3] == 0));
    }
    return 0;
}
''')
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(code))


if __name__ == "__main__":
    main()
