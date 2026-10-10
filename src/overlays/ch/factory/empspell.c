#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800000_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800630_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800A08_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800C7C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801038_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/chfactoryempspell_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801130_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_808012C0_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_808016AC_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801844_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801AB4_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801B2C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801C00_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801E48_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801E9C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801F30_chfactoryempspell.s")

/* extern */

void func_80801FE0_chfactoryempspell(void *arg0) {
    s32 _subaddieaudioloop_entrypoint_2();
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    s32 func_80801AB4_chfactoryempspell(void *);
    _subaddieaudioloop_entrypoint_2();
    (*(u8 *)((s8 *)(arg0) + (0x28))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x28))));
    func_80801AB4_chfactoryempspell(arg0);
    if ((*(s16 *)((s8 *)(arg0) + (0x82))) != 0) {
        _sumumbofx_entrypoint_1(arg0, 0);
    }
}

OSThread *chfactoryempspell_entrypoint_1(void)
{
    extern u8 D_80802414_chfactoryempspell[];

    return (OSThread *) D_80802414_chfactoryempspell;
}
