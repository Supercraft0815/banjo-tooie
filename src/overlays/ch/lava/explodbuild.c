#include "ch/lavaexplodbuild.h"

/* extern */

void func_80800000_chlavaexplodbuild(s32 arg0) {
    s32 func_800EFA4C(void *, s32, s32, s32);
    s32 func_80103014(s32);
    void *temp_a0;

    temp_a0 = arg0 + 4;
    (*(f32 *)((s8 *)(temp_a0) + (0x44))) = 45.0f;
    func_800EFA4C(temp_a0, 0xC6115000, 0x42480000, 0xC3FA0000);
    func_80103014(arg0);
}

/* extern */

void func_80800048_chlavaexplodbuild(s32 arg0) {
    s32 func_8010CB0C(s32, s32, s32, s32);
    func_800DA3B8(FLAG3_A24_UNK, func_8010CB0C(arg0 + 4, 0x708, 0x7D0, -0x1F4));
}

void func_80800084_chlavaexplodbuild(s32 arg0)
{
    func_800DA524(FLAG3_A24_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/explodbuild/func_808000A8_chlavaexplodbuild.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/explodbuild/func_80800138_chlavaexplodbuild.s")

OSThread *chlavaexplodbuild_entrypoint_0(void)
{
    extern u8 D_808002E0_chlavaexplodbuild[];

    return (OSThread *) D_808002E0_chlavaexplodbuild;
}
