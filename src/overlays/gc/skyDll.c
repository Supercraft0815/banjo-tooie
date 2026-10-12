#include "common.h"

s32 func_80800000_gcskyDll(s32 arg0) {
    extern s16 D_80800510_gcskyDll[];
    s16 *p = D_80800510_gcskyDll;
    while (*p != 0) {
        if (arg0 == *p) return (s32) p;
        p += 18;
    }
    return (s32) p;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_2.s")

/* extern */

s32 gcskyDll_entrypoint_3(void) {
    s32 func_800EA05C();
    s32 func_80800000_gcskyDll(s32);
    return func_80800000_gcskyDll(func_800EA05C()) != 0;
}
