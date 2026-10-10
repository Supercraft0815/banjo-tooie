#include "common.h"

/* extern */

void func_80800000_chmumbohealspell(s32 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_800FFA88(s32);
    s32 func_80103110(s32 *, s32);
    if ((func_800DA298(0x15E) != 0) && (func_800EA05C() == 0x155)) {
        func_800FFA88(*arg0);
    } else if (func_800DA298(0x189) == 0) {
        func_800FFA88(*arg0);
    }
    func_80103110(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800074_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_808003A8_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800450_chmumbohealspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800740_chmumbohealspell.s")

/* extern */

void func_80800800_chmumbohealspell(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 _sumumbofx_entrypoint_9(u8 *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _sumumbofx_entrypoint_9(func_80100094(arg0, 0U), arg1);
        _sumumbofx_entrypoint_8(func_80100094(arg0, 0U), arg1);
    }
}

OSThread *chmumbohealspell_entrypoint_0(void)
{
    extern u8 D_80800900_chmumbohealspell[];

    return (OSThread *) D_80800900_chmumbohealspell;
}
