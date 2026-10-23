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

s32 func_80021E1C(void *arg0, f32 *arg1) {
    f32 func_8001395C(f32);
    f32 func_80027170(s32);
    extern f32 D_80041994;
    extern f32 D_80041998;
    f32 sp2C;
    void *sp28;
    s32 sp24;

    sp28 = arg0;
    sp24 = 0x3E80;
    switch (*(u8 *)((s8 *)sp28 + 4)) {
        case 1:
            (*(u16 *)((s8 *)sp28 + 0x24))++;
            if (*(u16 *)((s8 *)sp28 + 0x24) >= *(u16 *)((s8 *)sp28 + 0x22)) {
                *(u16 *)((s8 *)sp28 + 0x24) = 0;
            }
            sp2C = (f32)*(u16 *)((s8 *)sp28 + 0x24) / (f32)*(u16 *)((s8 *)sp28 + 0x22);
            sp2C = func_8001395C(sp2C * D_80041994);
            sp2C = (f32)*(u8 *)((s8 *)sp28 + 0x28) * sp2C;
            *arg1 = (f32)*(u8 *)((s8 *)sp28 + 0x29) + sp2C;
            break;
        case 0x80:
            (*(u16 *)((s8 *)sp28 + 0x24))++;
            if (*(u16 *)((s8 *)sp28 + 0x24) >= *(u16 *)((s8 *)sp28 + 0x22)) {
                *(u16 *)((s8 *)sp28 + 0x24) = 0;
            }
            sp2C = (f32)*(u16 *)((s8 *)sp28 + 0x24) / (f32)*(u16 *)((s8 *)sp28 + 0x22);
            sp2C = *(f32 *)((s8 *)sp28 + 0x28) * func_8001395C(sp2C * D_80041998);
            *arg1 = func_80027170((s32)sp2C);
            break;
        default:
            break;
    }
    return sp24;
}

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
    extern s32 func_80021E1C(void *, f32 *);
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
