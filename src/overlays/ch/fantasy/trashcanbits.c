#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/trashcanbits/func_80800000_chfantasytrashcanbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/trashcanbits/func_808000EC_chfantasytrashcanbits.s")

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
