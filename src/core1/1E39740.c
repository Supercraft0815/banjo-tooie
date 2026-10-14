#include "common.h"

f32 func_80021C10(s32 arg0) {
    extern f32 D_80041990;
    f32 sp4;
    f32 sp0;

    arg0 &= 0xFF;
    sp4 = D_80041990;
    sp0 = 1.0f;
    if (arg0 != 0) {
        do {
            if (arg0 & 1) {
                sp0 *= sp4;
            }
            sp4 *= sp4;
            arg0 = ((u32)arg0 >> 1) & 0xFF;
        } while (arg0 != 0);
    }
    return sp0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39740/func_80021C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39740/func_80021E1C.s")

void func_80022060(ALLink *arg0) {
    extern ALLink *D_8007EA40;

    arg0->next = D_8007EA40;
    D_8007EA40 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39740/func_80022084.s")
