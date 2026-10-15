#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/trashcanbits/func_80800000_chfantasytrashcanbits.s")

/* extern */

void func_808000EC_chfantasytrashcanbits(Actor *arg0) {
    s32 _chdoor_entrypoint_0();
    s32 _subaddieDll_entrypoint_4(void *, s32);
    f32 func_800EFC7C(void *, void *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_8010108C();
    f32 sp2C[3];
    u32 temp_t6;

    temp_t6 = arg0->unk70_10;
    if (temp_t6 != 1) {
        if (temp_t6 == 4) {
            func_800F5A00(func_800F54E4(), sp2C);
            _subaddieDll_entrypoint_4(arg0, 1);
            if (func_800EFC7C(arg0->position, sp2C) > 4000000.0f) {
                func_8010108C(arg0, 8, 0);
            }
        }
    } else {
        _subaddieDll_entrypoint_4(arg0, 0);
    }
    _chdoor_entrypoint_0(arg0);
}

OSThread *chfantasytrashcanbits_entrypoint_0(void)
{
    extern u8 D_80800240_chfantasytrashcanbits[];

    return (OSThread *) D_80800240_chfantasytrashcanbits;
}

/* extern */

void func_808001A8_chfantasytrashcanbits(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    _chswitch_entrypoint_7(arg0, 0x9FF);
    _chswitch_entrypoint_8(arg0, 0x400);
}

/* extern */

void func_808001D8_chfantasytrashcanbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32);
    if (arg1 == 7) {
        func_80101180(0x40C);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chfantasytrashcanbits_entrypoint_1(void)
{
    extern u8 D_80800288_chfantasytrashcanbits[];

    return (OSThread *) D_80800288_chfantasytrashcanbits;
}
