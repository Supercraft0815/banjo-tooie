#include "common.h"

OSThread *chjadestatue_entrypoint_0(void)
{
    extern u8 D_80800310_chjadestatue[];

    return (OSThread *) D_80800310_chjadestatue;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_8080000C_chjadestatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_80800098_chjadestatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_80800104_chjadestatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_80800140_chjadestatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_808001C0_chjadestatue.s")

/* extern */

void func_8080026C_chjadestatue(s32 arg0) {
    s32 func_800D035C(s32);
    s32 func_800FFAB0(s32);
    if (func_800D035C(5) >= 0x14) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_808002A4_chjadestatue.s")

OSThread *chjadestatue_entrypoint_1(void)
{
    extern u8 D_80800358_chjadestatue[];

    return (OSThread *) D_80800358_chjadestatue;
}
