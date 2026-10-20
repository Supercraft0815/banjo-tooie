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

void func_80800044_chicywind(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800D0B68(s32, s32);
    s32 func_800FFAB0(s32);
    s32 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 func_8010C9B0(f32 *, s32);
    void func_808001AC_chicywind(f32 *);
    extern u32 D_80800348_chicywind[];
    extern s32 D_80800358_chicywind[];
    s32 active;
    f32 sp30[3];

    active = arg0->unk70_10 == 2;
    if (active || (!active && arg0->unk5F)) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, active, D_80800348_chicywind);
    }
    if (func_800D0B68(0x21, 0)) {
        func_800FFAB0(arg0);
        return;
    }
    switch (arg0->unk70_10) {
        case 1:
            if (func_8010C9B0(arg0->position, 1000)) {
                func_80101FDC(arg0, 2);
                arg0->unk58 = func_800DC178(0.15f, 0.2f);
            }
            break;
        case 2:
            if (func_800D9078(&arg0->unk58)) {
                func_800EE7F8(sp30, arg0->position);
                func_800EF1B8(sp30, arg0->rotation[1], -200.0f);
                func_800BBCB8(arg0->position, sp30, 1.0f, 1, D_80800358_chicywind);
                arg0->unk58 = func_800DC178(0.15f, 0.2f);
            }
            func_808001AC_chicywind((f32 *)arg0);
            if (!func_8010C9B0(arg0->position, 1800)) {
                func_80101FDC(arg0, 1);
            }
            break;
    }
}

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
