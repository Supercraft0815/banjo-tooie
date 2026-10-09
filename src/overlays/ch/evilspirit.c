#include "common.h"

OSThread *chevilspirit_entrypoint_0(void)
{
    extern u8 D_80802270_chevilspirit[];

    return (OSThread *) D_80802270_chevilspirit;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_8080000C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800104_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808005B4_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808005EC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800718_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808007B4_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800A4C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800BFC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800E20_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800F8C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80800FF8_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_8080104C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808012CC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801344_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801398_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808013DC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801458_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801534_chevilspirit.s")

/* extern */

void func_808015A4_chevilspirit(s32 arg0) {
    s32 func_80102424(s32, s32);
    s32 func_80801458_chevilspirit();
    s32 func_808015E0_chevilspirit(s32, s32);
    func_80801458_chevilspirit();
    if (func_808015E0_chevilspirit(arg0, 0x42C80000) != 0) {
        func_80102424(arg0, 6);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808015E0_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801684_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801840_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_808018DC_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801988_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801A6C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801B00_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801C04_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801E18_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801EC4_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80801F1C_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80802024_chevilspirit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/evilspirit/func_80802090_chevilspirit.s")

/* extern */

void func_80802118_chevilspirit(void *arg0) {
    s32 func_800C2FDC(u8);
    s32 func_800C3D78(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x5F)));
    if ((temp_a1 != 0) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0)) {
        func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x5F))));
        (*(u8 *)((s8 *)(arg0) + (0x5F))) = 0U;
    }
}
