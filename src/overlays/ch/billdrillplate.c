#include "common.h"

OSThread *chbilldrillplate_entrypoint_0(void)
{
    extern u8 D_808010DC_chbilldrillplate[];

    return (OSThread *) D_808010DC_chbilldrillplate;
}

OSThread *chbilldrillplate_entrypoint_1(void)
{
    extern u8 D_80801124_chbilldrillplate[];

    return (OSThread *) D_80801124_chbilldrillplate;
}

OSThread *chbilldrillplate_entrypoint_2(void)
{
    extern u8 D_8080116C_chbilldrillplate[];

    return (OSThread *) D_8080116C_chbilldrillplate;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800024_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_808000B0_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800240_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_808002A0_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800358_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800408_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800738_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800924_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800978_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800B9C_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800C98_chbilldrillplate.s")

/* extern */

void func_80800D5C_chbilldrillplate(s32 arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 func_800DA298(u16);
    s32 func_800FFAB0(s32);
    void *func_80800FCC_chbilldrillplate();
    if (func_800DA298((*(u16 *)((s8 *)(func_80800FCC_chbilldrillplate()) + (0xC)))) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    _subaddiefade_entrypoint_14(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800DA4_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800F24_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800FCC_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80801020_chbilldrillplate.s")
