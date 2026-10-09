#include "common.h"

OSThread *chbadjinjo_entrypoint_0(void)
{
    extern u8 D_80801288_chbadjinjo[];

    return (OSThread *) D_80801288_chbadjinjo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_8080000C_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_8080010C_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_808001B0_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800278_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800358_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_808003EC_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_8080059C_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800C90_chbadjinjo.s")

void func_80800DF0_chbadjinjo(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800DF8_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800E28_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800F7C_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80801054_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80801090_chbadjinjo.s")

/* extern */

void func_80801118_chbadjinjo(void *arg0) {
    s32 func_800C2FDC(u8);
    s32 func_800C3D78(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x5F)));
    if ((temp_a1 != 0) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0)) {
        func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x5F))));
        (*(u8 *)((s8 *)(arg0) + (0x5F))) = 0U;
    }
}
