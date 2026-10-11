#include "common.h"

void idwater_entrypoint_0(s32 arg0, void *arg1, void *arg2, void *arg3) {
    s16 *out = (s16 *)arg2;
    s16 *in1 = (s16 *)arg1;
    s16 *in3 = (s16 *)arg3;
    out[1] = in3[8] + in1[1];
    out[4] = in1[4] + in3[0];
    out[5] = in1[5] + in3[1];
}

s32 idwater_entrypoint_1(s16 *arg0) {
    return arg0[8];
}

void idwater_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/water/idwater_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/water/idwater_entrypoint_4.s")
