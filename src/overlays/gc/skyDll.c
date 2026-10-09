#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/func_80800000_gcskyDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_2.s")

/* extern */

s32 gcskyDll_entrypoint_3(void) {
    s32 func_800EA05C();
    s32 func_80800000_gcskyDll(s32);
    return func_80800000_gcskyDll(func_800EA05C()) != 0;
}
