#include "gc/introtext.h"

void gcintrotext_entrypoint_0()
{
    func_800DA544(FLAG2_6CB_UNK);
}

s32 gcintrotext_entrypoint_1(void) {
    if (func_800DA9E4(FLAG2_6CB_UNK, 0) != 0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/introtext/gcintrotext_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/introtext/func_808000C8_gcintrotext.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/introtext/func_808001AC_gcintrotext.s")
