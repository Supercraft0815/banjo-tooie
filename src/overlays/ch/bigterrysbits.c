#include "common.h"

OSThread *chbigterrysbits_entrypoint_0(void)
{
    extern u8 D_80800380_chbigterrysbits[];

    return (OSThread *) D_80800380_chbigterrysbits;
}

OSThread *chbigterrysbits_entrypoint_1(void)
{
    extern u8 D_808003C8_chbigterrysbits[];

    return (OSThread *) D_808003C8_chbigterrysbits;
}

OSThread *chbigterrysbits_entrypoint_2(void)
{
    extern u8 D_80800410_chbigterrysbits[];

    return (OSThread *) D_80800410_chbigterrysbits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bigterrysbits/func_80800024_chbigterrysbits.s")

/* extern */

void func_80800130_chbigterrysbits(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800FFAB0(s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bigterrysbits/func_80800160_chbigterrysbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bigterrysbits/func_808001A8_chbigterrysbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bigterrysbits/func_8080022C_chbigterrysbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bigterrysbits/func_8080029C_chbigterrysbits.s")
