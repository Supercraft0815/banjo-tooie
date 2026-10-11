#include "common.h"

OSThread *chpumproomswitch_entrypoint_0(void)
{
    extern u8 D_80800380_chpumproomswitch[];

    return (OSThread *) D_80800380_chpumproomswitch;
}

OSThread *chpumproomswitch_entrypoint_1(void)
{
    extern u8 D_808003C8_chpumproomswitch[];

    return (OSThread *) D_808003C8_chpumproomswitch;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pumproomswit/func_80800018_chpumproomswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pumproomswit/func_808000BC_chpumproomswitch.s")

s32 func_8080016C_chpumproomswitch(u8 *arg0) {
    u32 value = *(u16 *)((u8 *)arg0 + 0x76);
    s32 result = 0x9E7;
    return ((value & 0xFFFF) >> 7 == 0x32) ? 0x9E6 : result;
}

/* extern */

void func_80800194_chpumproomswitch(void *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    s32 func_80101FDC(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.0f;
    if ((func_800DA298(0xB2) != 0) || (_glcutDll_entrypoint_19(0x20) != 0)) {
        func_80101FDC(arg0, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pumproomswit/func_808001E4_chpumproomswitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/pumproomswit/func_808002A0_chpumproomswitch.s")
