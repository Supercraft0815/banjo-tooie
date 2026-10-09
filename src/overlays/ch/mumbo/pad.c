#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/chmumbopad_entrypoint_0.s")

/* extern */

void func_80800014_chmumbopad(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gccubesearch_entrypoint_1(s32);
    s32 _gspropctrl_entrypoint_11(s32, s32);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(arg2), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800048_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800098_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800140_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_8080044C_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800514_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_8080063C_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_80800674_chmumbopad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/pad/func_808008CC_chmumbopad.s")

OSThread *chmumbopad_entrypoint_1(void)
{
    extern u8 D_80801110_chmumbopad[];

    return (OSThread *) D_80801110_chmumbopad;
}
