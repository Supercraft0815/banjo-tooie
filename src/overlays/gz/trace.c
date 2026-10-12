#include "common.h"

s32 func_80800000_gztrace(u32 arg0) {
    if ((arg0 < 0x80000000U) || (arg0 >= 0x80800001U) || (arg0 & 3)) {
        return 0;
    }
    return 1;
}

void func_80800038_gztrace(u8 *arg0, u8 *arg1) {
    while ((*arg0++ = *arg1++) != 0) {
    }
}

void func_80800068_gztrace(u8 *arg0, u8 *arg1) {
    u8 *dest;
    s32 c;

    dest = arg0;
    while ((c = *dest++) != 0) {
    }
    dest--;
    while ((c = *arg1, *dest++ = c, arg1++, c != 0)) {
    }
}

s32 func_808000B8_gztrace(u8 *arg0) {
    s32 len;
    u8 *p;

    len = 0;
    p = arg0;
    while (*p != 0) {
        len++;
        p++;
    }
    return len;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808000E8_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_80800290_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808003D0_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808004B0_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808005C4_gztrace.s")

void gztrace_entrypoint_0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/gztrace_entrypoint_1.s")
