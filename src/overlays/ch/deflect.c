#include "common.h"

/* extern */

void func_80800000_chdeflect(s32 arg0) {
    s32 func_800C6E38(s32);
    s32 func_800FFAB0(s32);
    if (func_800C6E38(0x14) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/deflect/func_80800034_chdeflect.s")

OSThread *chdeflect_entrypoint_0(void)
{
    extern u8 D_80800090_chdeflect[];

    return (OSThread *) D_80800090_chdeflect;
}
