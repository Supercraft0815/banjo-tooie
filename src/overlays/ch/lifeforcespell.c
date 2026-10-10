#include "common.h"

OSThread *chlifeforcespell_entrypoint_0(void)
{
    extern u8 D_80800460_chlifeforcespell[];

    return (OSThread *) D_80800460_chlifeforcespell;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lifeforcespell/func_8080000C_chlifeforcespell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lifeforcespell/func_808000C8_chlifeforcespell.s")

/* extern */

void func_8080028C_chlifeforcespell(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 _sumumbofx_entrypoint_9(u8 *, s32);
    _sumumbofx_entrypoint_9(func_80100094(arg0, 1U), arg1);
    _sumumbofx_entrypoint_8(func_80100094(arg0, 1U), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lifeforcespell/chlifeforcespell_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lifeforcespell/chlifeforcespell_entrypoint_2.s")
