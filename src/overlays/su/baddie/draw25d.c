#include "common.h"

void subaddiedraw25d_entrypoint_0(void *arg0) {
    struct Flags {
        u8 pad[0x7E];
        u8 high : 3;
        u8 enabled : 1;
        u8 low : 4;
    };
    ((struct Flags *)arg0)->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/draw25d/subaddiedraw25d_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/draw25d/subaddiedraw25d_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/draw25d/subaddiedraw25d_entrypoint_3.s")
