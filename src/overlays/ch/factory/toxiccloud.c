#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800000_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808000F0_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808001B8_chfactorytoxiccloud.s")

/* extern */

void func_80800A34_chfactorytoxiccloud(s32 arg0, void *arg1) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    (*(f32 *)((s8 *)(arg1) + (0))) = func_800DC178(0.5f, 1.0f);
    (*(f32 *)((s8 *)(arg1) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg1) + (0xC))) = (f32) (func_800DC178(0.4f, 0.5f) + 0.2f);
    (*(f32 *)((s8 *)(arg1) + (0x10))) = (f32) (func_800DC178(0.7f, 0.9f) + 0.2f);
    (*(s32 *)((s8 *)(arg1) + (8))) = func_800DC128(0, 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800AD8_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800BF8_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800C7C_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_80800FCC_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808010B8_chfactorytoxiccloud.s")

/* extern */

void func_80801164_chfactorytoxiccloud(void *arg0) {
    s32 func_8010BA80();
    f32 sp1C;

    sp1C = (*(f32 *)((s8 *)(arg0) + (0x48)));
    (*(f32 *)((s8 *)(arg0) + (0x48))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x54)));
    func_8010BA80();
    (*(f32 *)((s8 *)(arg0) + (0x48))) = sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808011A0_chfactorytoxiccloud.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxiccloud/func_808012C4_chfactorytoxiccloud.s")

OSThread *chfactorytoxiccloud_entrypoint_0(void)
{
    extern u8 D_80801568_chfactorytoxiccloud[];

    return (OSThread *) D_80801568_chfactorytoxiccloud;
}
