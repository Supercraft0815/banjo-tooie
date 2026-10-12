#include "common.h"

OSThread *changlerboss_entrypoint_0(void)
{
    extern u8 D_80802EB4_changlerboss[];

    return (OSThread *) D_80802EB4_changlerboss;
}

OSThread *changlerboss_entrypoint_1(void)
{
    extern u8 D_80802EFC_changlerboss[];

    return (OSThread *) D_80802EFC_changlerboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80800018_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808002E0_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80800B7C_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80800F14_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80800FEC_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801070_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808012E0_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808015F4_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808016A8_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_8080170C_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808018E8_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801948_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801A10_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801AF0_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801BC8_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801C50_changlerboss.s")

/* extern */

void func_80801CD8_changlerboss(s32 arg0) {
    s32 func_8001210C(s32);
    s32 func_80108B04(s32, s32);
    if (func_8001210C(3) == 0) {
        func_80108B04(arg0, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801D0C_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801DA0_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801E3C_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801F54_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802108_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808021E4_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802210_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802288_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808022C4_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802340_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802430_changlerboss.s")

/* extern */

s32 func_808025AC_changlerboss(s32 arg0) {
    s32 func_800F54E4();
    s32 func_8010D290(s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_8010D290(0x400);
    var_v1 = temp_v0;
    if (temp_v0 == -1) {
        var_v1 = func_800F54E4();
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808025EC_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802680_changlerboss.s")

/* extern */

void func_808027F8_changlerboss(void *arg0) {
    void func_800EFD24(f32 *);
    f32 func_80102D78(void *, s32 *);
    s32 sp1C[3];
    f32 temp_f0;

    func_800EFD24((f32 *)sp1C);
    temp_f0 = func_80102D78(arg0, sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x48))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x50))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x44))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802844_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802888_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802A90_changlerboss.s")
