#include "common.h"

s32 func_8002C5C0(s32 *arg0) {
    if (arg0[1] == arg0[0]) {
        return 0;
    } else {
        return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E440F0/func_8002C5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E440F0/func_8002CC9C.s")

Acmd *func_8002CE70(Acmd *arg0, void *arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    s32 sp2C;
    s32 sp28;

    if (arg3 > 0) {
        sp28 = (*(s32 (**)(s32, s32, s32))((s8 *)(arg1) + (0x28)))((*(s32 *)((s8 *)(arg1) + (0x3C))), arg3, (*(s32 *)((s8 *)(arg1) + (0x2C))));
        sp2C = sp28 & 7;
        arg3 += sp2C;
        {
        Acmd *sp24 = arg0++;
        (*(s32 *)((s8 *)(sp24) + (0))) = ((((arg3 - (arg3 & 7)) + 8) & 0xFFF) << 0xC) | 0x04000000 | (arg5 & 0xFFF);
        (*(s32 *)((s8 *)(sp24) + (4))) = (s32) (sp28 - sp2C);
        }
    } else {
        sp2C = 0;
    }
    if (arg6 & 2) {
        Acmd *sp20 = arg0++;
        (*(s32 *)((s8 *)(sp20) + (0))) = 0x0F000000;
        (*(s32 *)((s8 *)(sp20) + (4))) = (s32) ((*(s32 *)((s8 *)(arg1) + (0x10))) & 0x1FFFFFFF);
    }
    {
    Acmd *sp1C = arg0++;
    *(s32 *)sp1C = ((*(s32 *)((s8 *)(arg1) + (0xC))) & 0x1FFFFFFF & 0xFFFFFF) | 0x01000000;
    (*(s32 *)((s8 *)(sp1C) + (4))) = (s32) (((arg6 & 0xF) << 0x1C) | (((arg2 * 2) & 0xFFF) << 0x10) | ((sp2C & 0xF) << 0xC) | (arg4 & 0xFFF));
    }
    (*(s32 *)((s8 *)(arg1) + (0x38))) = 0;
    return arg0;
}
