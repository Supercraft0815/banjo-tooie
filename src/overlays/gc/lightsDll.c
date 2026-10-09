#include "common.h"

void func_80800000_gclightsDll(s32 arg0)
{
    gclightsDll_entrypoint_1();
    _gclightsDll_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/lightsDll/gclightsDll_entrypoint_4.s")

/* extern */

void gclightsDll_entrypoint_5(s32 arg0) {
    s32 func_800C911C();
    s32 func_800EE830(s32, s32);
    func_800EE830(func_800C911C() + 0x10, arg0);
}
