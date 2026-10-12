#include "common.h"

OSThread *chshockjump_entrypoint_0(void)
{
    extern u8 D_808002B0_chshockjump[];

    return (OSThread *) D_808002B0_chshockjump;
}

OSThread *chshockjump_entrypoint_1(void)
{
    extern u8 D_808002F8_chshockjump[];

    return (OSThread *) D_808002F8_chshockjump;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/shockjump/func_80800018_chshockjump.s")

s32 func_808000AC_chshockjump(s32 arg0, s32 arg1, s32 arg2) {
    void func_800F7B9C(s32, u32);
    switch (arg1) {
    case 0x91:
        func_800F7B9C(arg2, 0x4AU);
        break;
    default:
        return 0;
    }
    return 1;
}

void chshockjump_entrypoint_2(void) {
    s32 _chexploder_entrypoint_5(u8 *, s32, u8 *, s32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    u8 *func_80106790();
    extern s32 D_80800340_chshockjump;
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80106790();
    sp24 = temp_v0;
    _chexploder_entrypoint_5(temp_v0, 0x756, temp_v0 + 4, (*(s32 *)((s8 *)(temp_v0) + (0x48))), (*(f32 *)((s8 *)(temp_v0) + (0x38))), 0xC);
    _subaddieaudioquick_entrypoint_2(sp24, sp24 + 4, &D_80800340_chshockjump);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/shockjump/func_80800148_chshockjump.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/shockjump/func_80800228_chshockjump.s")
