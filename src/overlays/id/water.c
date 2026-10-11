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

void idwater_entrypoint_4(void *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_2(s32, s32, s32 *, void *);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    f32 func_800D8FF8();
    extern s32 _idwater_entrypoint_0;
    f32 temp_f18;
    f32 sp30;
    f32 scroll[2];
    f32 var_f0;
    f32 sp20;
    f32 temp_f0;
    f32 temp_f12;
    s16 temp_v0;

    temp_f0 = func_800D8FF8();
    sp30 = temp_f0;
    (*(f32 *)((s8 *)arg0 + 4)) = (f32) ((*(f32 *)((s8 *)arg0 + 4)) + temp_f0);
    sp20 = func_800138D0((*(f32 *)((s8 *)arg0 + 4)) * 0.2f * 180.0f);
    scroll[0] = ((func_80013970((*(f32 *)((s8 *)arg0 + 4)) * 0.08f * 180.0f) * 100.0f) + (150.0f * sp20)) * 0.8f;
    sp20 = func_80013970((*(f32 *)((s8 *)arg0 + 4)) * 0.5f * 180.0f);
    scroll[1] = ((func_800138D0((*(f32 *)((s8 *)arg0 + 4)) * 0.22f * 180.0f) * 100.0f) + (50.0f * sp20)) * 0.8f;
    if (scroll[0] >= 0.0f) {
        (*(s16 *)((s8 *)arg0 + 0)) = (s32) (scroll[0] + 0.5f);
    } else {
        (*(s16 *)((s8 *)arg0 + 0)) = (s32) (scroll[0] - 0.5f);
    }
    if (scroll[1] >= 0.0f) {
        (*(s16 *)((s8 *)arg0 + 2)) = (s32) (scroll[1] + 0.5f);
    } else {
        (*(s16 *)((s8 *)arg0 + 2)) = (s32) (scroll[1] - 0.5f);
    }
    sp20 = func_800138D0((*(f32 *)((s8 *)arg0 + 4)) * 0.5f * 180.0f);
    temp_f18 = ((*(f32 *)((s8 *)arg0 + 8)) * 0.75f * sp20) + (((*(f32 *)((s8 *)arg0 + 8)) * 0.25f) * func_80013970((*(f32 *)((s8 *)arg0 + 4)) * 0.11f * 180.0f));
    if ((*(f32 *)((s8 *)arg0 + 0x14)) < (*(f32 *)((s8 *)arg0 + 0x1C))) {
        (*(f32 *)((s8 *)arg0 + 0x18)) = (*(f32 *)((s8 *)arg0 + 0x14));
        (*(f32 *)((s8 *)arg0 + 0x14)) = (f32) ((*(f32 *)((s8 *)arg0 + 0x14)) + sp30);
        if ((*(f32 *)((s8 *)arg0 + 0x1C)) < (*(f32 *)((s8 *)arg0 + 0x14))) {
            (*(f32 *)((s8 *)arg0 + 0x14)) = (*(f32 *)((s8 *)arg0 + 0x1C));
        }
    }
    if ((*(f32 *)((s8 *)arg0 + 0x14)) < (*(f32 *)((s8 *)arg0 + 0x1C))) {
        temp_v0 = (*(s16 *)((s8 *)arg0 + 0xC));
        var_f0 = (f32) temp_v0;
        var_f0 += ((*(f32 *)((s8 *)arg0 + 0x14)) / (*(f32 *)((s8 *)arg0 + 0x1C))) * (f32) ((*(s16 *)((s8 *)arg0 + 0xE)) - temp_v0);
    } else {
        var_f0 = (f32) (*(s16 *)((s8 *)arg0 + 0xE));
    }
    var_f0 += temp_f18;
    if (var_f0 >= 0.0f) {
        (*(s16 *)((s8 *)arg0 + 0x10)) = (s32) (var_f0 + 0.5f);
    } else {
        (*(s16 *)((s8 *)arg0 + 0x10)) = (s32) (var_f0 - 0.5f);
    }
    _glid_entrypoint_2(arg1, arg2, &_idwater_entrypoint_0, arg0);
}
