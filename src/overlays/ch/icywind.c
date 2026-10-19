#include "common.h"

OSThread *chicywind_entrypoint_0(void)
{
    extern u8 D_80800300_chicywind[];

    return (OSThread *) D_80800300_chicywind;
}

/* extern */

void func_8080000C_chicywind(s32 arg0) {
    s32 func_800D0B68(s32, s32);
    s32 func_800FFAB0(s32);
    if (func_800D0B68(0x21, 0) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icywind/func_80800044_chicywind.s")

void func_808001AC_chicywind(f32 *arg0) {
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F48BC(s32, f32 *);
    s32 func_800F5410(s32);
    u32 func_800F54E4(void);
    s32 func_800F5578(s32);
    s32 func_800F55A4(s32);
    void func_800F5A00(s32, f32 *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 pad;
    f32 sp38;
    f32 scale;
    s32 sp30;

    sp30 = func_800F54E4();
    switch (func_800F5410(sp30)) {
        default:
            scale = 0.85f;
            break;
        case 11:
        case 17:
            scale = 0.65f;
            break;
        case 2:
            scale = func_800F10B4((f32)func_800F5578(sp30), 1.0f, (f32)func_800F55A4(sp30), 0.6f, 1.0f);
            break;
    }
    func_800F5A00(sp30, sp40);
    sp38 = func_800F10B4(func_800EEAD4(sp40, arg0 + 1), 1000.0f, 1800.0f, 1200.0f, 300.0f) * (1.0f / scale);
    func_800EEB9C(sp4C, func_800F1DF4(arg0 + 1, sp40), sp38);
    func_800F48BC(sp30, sp4C);
}
