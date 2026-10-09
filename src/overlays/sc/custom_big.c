#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_big/func_80800000_sccustom_big.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_big/func_80800044_sccustom_big.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_big/func_808000B4_sccustom_big.s")

/* extern */

void sccustom_big_entrypoint_0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800000_sccustom_big(s32);
    s32 func_808000B4_sccustom_big(s32, s32, s32, s32, s32);
    func_808000B4_sccustom_big(arg0, arg1, arg2, arg3, func_80800000_sccustom_big(arg1));
}

/* extern */

void sccustom_big_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800044_sccustom_big(s32, s32);
    s32 func_808000B4_sccustom_big(s32, s32, s32, s32, s32);
    func_808000B4_sccustom_big(arg0, arg1, arg2, arg3, func_80800044_sccustom_big(arg1, 0x2F));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_big/func_80800314_sccustom_big.s")

/* extern */

void sccustom_big_entrypoint_2(s32 arg0) {
    s32 func_80800000_sccustom_big();
    s32 func_80800314_sccustom_big(s32, s32);
    func_80800314_sccustom_big(arg0, func_80800000_sccustom_big());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_big/sccustom_big_entrypoint_3.s")
