#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/func_80800000_glsplineDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/glsplineDll_entrypoint_0.s")

s16 func_80800C70_glsplineDll(void) {
    extern u8 D_8012762C;
    extern struct { s16 level; s16 result; } D_80800FC8_glsplineDll[];
    s32 i = 0;
    while (D_8012762C != D_80800FC8_glsplineDll[i].level && D_80800FC8_glsplineDll[i].level != -1) {
        i++;
    }
    return D_80800FC8_glsplineDll[i].result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/glsplineDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/Dll/glsplineDll_entrypoint_2.s")
