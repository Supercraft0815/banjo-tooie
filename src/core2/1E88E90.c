#include "common.h"

s32 func_800AF5A0(s16 *arg0) {
    return arg0[0];
}

s32 func_800AF5A8(s16 *arg0) {
    return arg0[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800AF5B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800AF5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800AF5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800AF5E4.s")

void *func_800AF5F0(void *arg0)
{
    struct OffsetHeader {
        u8 padding[0x18];
        s32 offset;
    };

    return (u8 *)arg0 + ((struct OffsetHeader *)arg0)->offset;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800AF5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800AF614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800B0CFC.s")
