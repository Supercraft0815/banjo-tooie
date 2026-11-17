// Compare real n_aspMain command handlers with native audio, using synthetic samples and filter history.
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "guest.h"
#include "mixer.h"

static const char *sections[2];

w2c_bt bt_inst;
u8 *bt_mem;

_Noreturn void bt_fatal(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fputc('\n', stderr);
    exit(1);
}

void bt_rom_audio(int text, u8 *bytes) {
    size_t size = text ? BT_AUDIO_TEXT_BYTES : BT_AUDIO_DATA_BYTES;
    FILE *f = fopen(sections[text], "rb");
    if (!f || fread(bytes, 1, size, f) != size) bt_fatal("missing n_aspMain section");
    fclose(f);
}

int main(int argc, char **argv) {
    if (argc != 3) return 1;
    sections[0] = argv[1];
    sections[1] = argv[2];
    const u32 task = 0x80001000u, commands = 0x80002000u, coeff = 0x80003000u;
    const u32 input = 0x80004000u, history = 0x80005000u;
    bt_inst.w2c_memory.size = 0x81000000u;
    bt_mem = calloc(1, bt_inst.w2c_memory.size);
    if (!bt_mem) return 1;
    gw32(task + 0x30, commands);
    for (unsigned i = 0; i < 200; i++) gw16(input + 2 * i, (i * 13873u + 0x6000) & 0xffff);
    for (unsigned i = 0; i < 4; i++) gw16(history + 2 * i, i * 9181u + 65);
    for (unsigned mode = 0; mode < 3; mode++) {
        for (unsigned i = 0; i < 16; i++) gw16(coeff + 2 * i, 0);
        if (mode != 1) {
            gw16(coeff, 0x3400);
            gw16(coeff + 2, mode ? 0 : 0x2040);
            gw16(coeff + 16, 0x8120);
            gw16(coeff + 18, 0x2400);
        } else {
            for (unsigned i = 0; i < 8; i++) gw16(coeff + 16 + 2 * i, i * 719 + 0x2000);
        }
        for (unsigned init = 0; init < 2; init++) {
            u32 list[][2] = {
                {0x0b000020, coeff},
                {0x04170000, input},
                {0x04170650, input},
                {0x0e000000u | init << (mode == 1 ? 14 : 16) | (mode == 1 ? 0x350u : 0x650u), history & 0xffffff},
                {0x00000650, 0x60000002},
                {0x0c004000, 0x00000010},
                {0x08000123, 0x456},
                {0x06050000, 0x6000},
            };
            gw32(task + 0x34, sizeof list);
            for (unsigned i = 0; i < sizeof list / sizeof *list; i++) {
                gw32(commands + 8 * i, list[i][0]);
                gw32(commands + 8 * i + 4, list[i][1]);
            }
            bt_audio_task(task);
        }
    }
    free(bt_mem);
    puts("audio mixer: filter and gain commands match RSP DMEM and DMA");
    return 0;
}
