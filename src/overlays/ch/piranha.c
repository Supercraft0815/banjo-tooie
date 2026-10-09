#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800000_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080003C_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800218_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800280_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_808002A0_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800CAC_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800CEC_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800DD0_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80800EFC_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080106C_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80801210_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80801250_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80801420_chpiranha.s")

/* extern */

void func_80801508_chpiranha(s32 arg0) {
    s32 func_8010C500();
    s32 func_8010C9B0(s32, s32);
    s32 func_80800218_chpiranha(s32, s32);
    if ((func_8010C500() != 0) && (func_8010C9B0(arg0 + 4, 0x384) != 0)) {
        func_80800218_chpiranha(arg0, 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080154C_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_80801638_chpiranha.s")

void func_80801690_chpiranha(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80801B10_chpiranha;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_80801B10_chpiranha);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_808016D0_chpiranha.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/piranha/func_8080182C_chpiranha.s")

OSThread *chpiranha_entrypoint_0(void)
{
    extern u8 D_80801B60_chpiranha[];

    return (OSThread *) D_80801B60_chpiranha;
}

OSThread *chpiranha_entrypoint_1(void)
{
    extern u8 D_80801BA8_chpiranha[];

    return (OSThread *) D_80801BA8_chpiranha;
}

OSThread *chpiranha_entrypoint_2(void)
{
    extern u8 D_80801BF0_chpiranha[];

    return (OSThread *) D_80801BF0_chpiranha;
}
