#include "common.h"

OSThread *chloggo_entrypoint_0(void)
{
    extern u8 D_80800648_chloggo[];

    return (OSThread *) D_80800648_chloggo;
}

OSThread *chloggo_entrypoint_1(void)
{
    extern u8 D_80800690_chloggo[];

    return (OSThread *) D_80800690_chloggo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_80800018_chloggo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_808000AC_chloggo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_808001B8_chloggo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_80800398_chloggo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_80800460_chloggo.s")

/* extern */

void func_808004F8_chloggo(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800FFAB0(s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/loggo/func_80800528_chloggo.s")
