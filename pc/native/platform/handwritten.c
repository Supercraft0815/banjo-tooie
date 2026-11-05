// Native equivalents of handwritten assembly functions in src/*.s.
#include <ultra64.h>

// src/core1/1E35D40.s: reads one big-endian ROM word through the PI.
s32 rom_read_word(u32 address, u32 *value) {
    osPiReadIo(address, value);
    return 0;
}
