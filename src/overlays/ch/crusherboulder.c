#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800000_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800100_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_808001CC_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800210_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800338_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_8080087C_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_808009C0_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800A1C_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800D3C_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800ED0_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800F38_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80801064_chcrusherboulder.s")

void func_808010EC_chcrusherboulder(void) {
    s32 func_800BBCB8(s32 *, s32, s32, s32, s32 *);
    extern s32 D_80801464_chcrusherboulder;
    extern s32 D_80801470_chcrusherboulder;
    func_800BBCB8(&D_80801464_chcrusherboulder, 0, 0x3F800000, 3, &D_80801470_chcrusherboulder);
}

void func_80801128_chcrusherboulder(s32 arg0, s32 arg1) {
    s32 func_800BA22C(s32, s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808014BC_chcrusherboulder;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800BABB8(0, arg0, 0, 0x3F800000, &D_808014BC_chcrusherboulder);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, 0x9DD);
    func_800BA22C(sp24, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80801184_chcrusherboulder.s")

OSThread *chcrusherboulder_entrypoint_0(void)
{
    extern u8 D_808014EC_chcrusherboulder[];

    return (OSThread *) D_808014EC_chcrusherboulder;
}
