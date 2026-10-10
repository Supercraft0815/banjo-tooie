#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_80800000_chsunlightspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_80800048_chsunlightspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_80800404_chsunlightspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_80800668_chsunlightspell.s")

/* extern */

void func_80800704_chsunlightspell(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_14(u8 *);
    s32 _sumumbofx_entrypoint_7(u8 *, s32, s32, s32, f32 *, s32, s32);
    _sumumbofx_entrypoint_7(func_80100094(arg0, 1U), arg1, 0, 0x2E, arg0->position, 0, 0);
    _sumumbofx_entrypoint_14(func_80100094(arg0, 1U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_80800768_chsunlightspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sunlightspell/func_808007CC_chsunlightspell.s")

OSThread *chsunlightspell_entrypoint_0(void)
{
    extern u8 D_808008BC_chsunlightspell[];

    return (OSThread *) D_808008BC_chsunlightspell;
}
