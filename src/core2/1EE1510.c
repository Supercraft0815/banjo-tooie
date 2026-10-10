#include "common.h"

OSThread *func_80107C20(void)
{
    extern u8 D_80124580[];

    return (OSThread *) D_80124580;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80107C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_801084B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_8010856C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_801085CC.s")

/* extern */

s32 func_80108618(s32 arg0, s32 arg1) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    if (func_800DA298(arg1) != 0) {
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_801088A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108944.s")

void func_80108A30(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    extern s32 func_80108A8C;
    _chbaddiesetup_entrypoint_6(&func_80108A8C, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108A8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108B44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE1510/func_80108DC0.s")
