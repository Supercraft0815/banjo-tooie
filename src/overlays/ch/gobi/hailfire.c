#include "common.h"

OSThread *chgobihailfire_entrypoint_0(void)
{
    extern u8 D_80800788_chgobihailfire[];

    return (OSThread *) D_80800788_chgobihailfire;
}

OSThread *chgobihailfire_entrypoint_1(void)
{
    extern u8 D_808007D0_chgobihailfire[];

    return (OSThread *) D_808007D0_chgobihailfire;
}

/* extern */

void func_80800018_chgobihailfire(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    void func_8010573C(Actor *, f32);
    void func_80105A9C(Actor *, f32);
    struct {
        u32 unused : 15;
        u32 enabled : 1;
        u32 unused2 : 16;
    } *flags;
    if (_glcutDll_entrypoint_20() != 0) {
        if (func_800EA05C() != 0x129) {
            func_800FFAB0(arg0);
        }
        func_80102424(arg0, 4);
        func_8010573C(arg0, 1.0f);
        goto block_6;
    }
    if (func_800DA298(0x97) == 0) {
        func_800FFAB0(arg0);
        return;
    }
block_6:
    func_80105A9C(arg0, 500.0f);
    func_80102FDC(arg0, 0.25f);
    flags = (void *)&arg0->pad94;
    flags->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_808000C8_chgobihailfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/hailfire/func_8080032C_chgobihailfire.s")

s32 func_80800538_chgobihailfire(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _glcutDll_entrypoint_20(void);
    s32 func_800DA298(s32);
    int func_800DB9B0(void);
    s32 func_800EA05C(void);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80104E78(Actor *);
    void func_801056EC(Actor *, f32);
    s32 cutscene;
    s32 complete;
    s32 active;
    u32 flags;

    complete = func_800DA298(0x1C6);
    cutscene = _glcutDll_entrypoint_19(0x47);
    switch (func_800EA05C()) {
        case 0x127:
            active = func_800DA298(0x97) && !complete && !func_800DB9B0();
            if (_glcutDll_entrypoint_20()) {
                func_800FFAB0(arg0);
                return 0;
            }
            func_80102424(arg0, 1);
            if (cutscene) {
                arg0->unk64_20 = 1;
            } else {
                arg0->unk64_20 = 0;
            }
            if (cutscene || active) {
                flags = 0x830;
                if (cutscene) {
                    flags = 0x2830;
                }
                arg0->unk58 = 5.0f;
                _capod_entrypoint_13(arg0->unk0, NULL, 0, flags);
                return 1;
            }
            func_800FFAB0(arg0);
            return 0;
        case 0x129:
            if (_glcutDll_entrypoint_20()) {
                return 0;
            }
            if (cutscene) {
                func_80102424(arg0, 2);
                func_801056EC(arg0, 0.0f);
                _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x2900);
                return 1;
            }
            if (complete) {
                func_80102424(arg0, 5);
                func_801056EC(arg0, 1.0f);
                func_80104E78(arg0);
            } else {
                func_800FFAB0(arg0);
            }
            break;
    }
    return 0;
}
