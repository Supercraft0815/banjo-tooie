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

void func_80022084(void *arg0, s32 arg1) {
    s32 func_80020EE4(s32, s32, void *, s32, s32);
    extern ALLink *D_8007EA40;
    extern ALLink *D_8007EA44;
    extern s32 func_80021C8C;
    extern s32 func_80021E1C;
    ALLink *sp24;
    s32 sp20;

    D_8007EA44 = (ALLink *)func_80020EE4(0, 0, *(void **)((s8 *)arg0 + 0xC), arg1, 0x2C);
    D_8007EA40 = D_8007EA44;
    D_8007EA40 = D_8007EA44;
    sp24 = D_8007EA44;
    for (sp20 = 0; sp20 < arg1 - 1; sp20++) {
        sp24->next = (ALLink *)(sp20 * 0x2C + (s8 *)D_8007EA44 + 0x2C);
        sp24 = sp24->next;
    }
    sp24->next = NULL;
    (*(s32 **)((s8 *)(arg0) + (0x10))) = &func_80021C8C;
    (*(s32 **)((s8 *)(arg0) + (0x14))) = &func_80021E1C;
    (*(void (**)(ALLink *))((s8 *)arg0 + 0x18)) = func_80022060;
}
