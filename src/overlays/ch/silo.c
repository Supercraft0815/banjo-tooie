#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800000_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800104_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_8080015C_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808001A8_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800210_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800238_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808002E8_chsilo.s")

/* extern */

void func_80800378_chsilo(s32 arg0) {
    s32 func_800903D0(s32);
    func_800903D0(arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800398_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800420_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808004C0_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_8080087C_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808009E8_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800A40_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800B80_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80801080_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808011C8_chsilo.s")

OSThread *chsilo_entrypoint_0(void)
{
    extern u8 D_80801384_chsilo[];

    return (OSThread *) D_80801384_chsilo;
}
