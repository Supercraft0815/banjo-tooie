#include "common.h"

s32 func_80800000_gztrace(u32 arg0) {
    if ((arg0 < 0x80000000U) || (arg0 >= 0x80800001U) || (arg0 & 3)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_80800038_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_80800068_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808000B8_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808000E8_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_80800290_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808003D0_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808004B0_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808005C4_gztrace.s")

void gztrace_entrypoint_0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/gztrace_entrypoint_1.s")
