#include "common.h"

typedef struct {
    s16 d_tc[2];
    f32 unk4;
    f32 unk8;
    s16 unkC;
    s16 unkE;
    s16 dy;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} WaterEffect;

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
void idwater_entrypoint_3(WaterEffect *arg0, s32 arg1, void *arg2, s32 arg3) {
    f32 func_800DC264(f32, f32);
    arg0->d_tc[0] = 0;
    arg0->d_tc[1] = 0;
    arg0->unk4 = func_800DC264(0.0f, 1.0f);
    arg0->unk8 = arg1;
    arg0->unkC = 0;
    arg0->unkE = 0;
    arg0->dy = 0;
    arg0->unk14 = 0.0f;
    arg0->unk18 = 0.0f;
    arg0->unk1C = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/water/idwater_entrypoint_4.s")
