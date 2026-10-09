#include "common.h"

OSThread *chballoonburst_entrypoint_0(void)
{
    extern u8 D_80801C40_chballoonburst[];

    return (OSThread *) D_80801C40_chballoonburst;
}

OSThread *chballoonburst_entrypoint_1(void)
{
    extern u8 D_80801C88_chballoonburst[];

    return (OSThread *) D_80801C88_chballoonburst;
}

OSThread *chballoonburst_entrypoint_2(void)
{
    extern u8 D_80801CD0_chballoonburst[];

    return (OSThread *) D_80801CD0_chballoonburst;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800024_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800098_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808001FC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808003C4_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_8080066C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800704_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800790_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808008F0_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800970_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800A7C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800BE8_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800EDC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80800F4C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808010D8_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_8080110C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808011A8_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801254_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801290_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801338_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_8080154C_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808015D4_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_808017A4_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801948_chballoonburst.s")

void func_80801A10_chballoonburst(u8 *arg0) {
    s32 func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    extern s32 D_80801D28_chballoonburst;
    u8 *temp_a0;

    temp_a0 = arg0 + 4;
    func_800BBCB8(temp_a0, temp_a0, (*(s32 *)((s8 *)(arg0) + (0x38))), 8, &D_80801D28_chballoonburst);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801A50_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801ABC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801AFC_chballoonburst.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonburst/func_80801B6C_chballoonburst.s")
