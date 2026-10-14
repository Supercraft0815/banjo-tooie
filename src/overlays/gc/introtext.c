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

s32 func_808001AC_gcintrotext(s32 arg0) {
    extern u16 D_8080056C_gcintrotext;
    extern u16 D_8080056E_gcintrotext;
    extern u16 D_80800570_gcintrotext[24];
    s32 i;

    if (arg0 == D_8080056C_gcintrotext) {
        return 0;
    }
    if (arg0 == D_8080056E_gcintrotext) {
        return 0;
    }
    for (i = 0; i < 24; i++) {
        if (arg0 == D_80800570_gcintrotext[i]) {
            return 0;
        }
    }
    return 1;
}
