#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800000_chsilo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_80800104_chsilo.s")

/* extern */

s32 func_8080015C_chsilo(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    if (arg1 == ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)) {
        return 0;
    }
    if (func_800DA298(arg1 + 0x32C) == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/silo/func_808001A8_chsilo.s")

/* extern */

void func_80800210_chsilo(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_32(s32, s32);
    _gcnewoption_entrypoint_32(arg1, 111);
}

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
