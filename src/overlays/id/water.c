#include "core2/model_mesh.h"

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

void idwater_entrypoint_0 BT_IDO_ONLY((s32 arg0, void *arg1, void *arg2, void *arg3)) BT_NATIVE_ONLY((s32 arg0, s16 *arg1, u8 *arg2, u8 *arg3)) {
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

void idwater_entrypoint_2(void *arg0)
{
}
void idwater_entrypoint_3(void *data, s32 arg1, void *arg2, s32 arg3, s32 flags) {
    WaterEffect *arg0 = data;
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
}             typedef struct { s16 unk0; s16 unk2; f32 unk4; f32 unk8; s16 unkC; s16 unkE; s16 unk10; u8 pad12[0x2]; f32 unk14; f32 unk18; f32 unk1C; } Objwater_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void idwater_entrypoint_4(void *arg0, void *arg1, s32 arg2) {
    BT_IDO_ONLY(void _glid_entrypoint_2(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s32), BtIntPtr arg3);)
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    f32 func_800D8FF8();
#ifndef BT_NATIVE
    extern s32 _idwater_entrypoint_0;
#endif
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
    (((Objwater_arg0 *)arg0)->unk4) = (f32) ((((Objwater_arg0 *)arg0)->unk4) + temp_f0);
    sp20 = func_800138D0((((Objwater_arg0 *)arg0)->unk4) * 0.2f * 180.0f);
    scroll[0] = ((func_80013970((((Objwater_arg0 *)arg0)->unk4) * 0.08f * 180.0f) * 100.0f) + (150.0f * sp20)) * 0.8f;
    sp20 = func_80013970((((Objwater_arg0 *)arg0)->unk4) * 0.5f * 180.0f);
    scroll[1] = ((func_800138D0((((Objwater_arg0 *)arg0)->unk4) * 0.22f * 180.0f) * 100.0f) + (50.0f * sp20)) * 0.8f;
    if (scroll[0] >= 0.0f) {
        (((Objwater_arg0 *)arg0)->unk0) = (s32) (scroll[0] + 0.5f);
    } else {
        (((Objwater_arg0 *)arg0)->unk0) = (s32) (scroll[0] - 0.5f);
    }
    if (scroll[1] >= 0.0f) {
        (((Objwater_arg0 *)arg0)->unk2) = (s32) (scroll[1] + 0.5f);
    } else {
        (((Objwater_arg0 *)arg0)->unk2) = (s32) (scroll[1] - 0.5f);
    }
    sp20 = func_800138D0((((Objwater_arg0 *)arg0)->unk4) * 0.5f * 180.0f);
    temp_f18 = ((((Objwater_arg0 *)arg0)->unk8) * 0.75f * sp20) + (((((Objwater_arg0 *)arg0)->unk8) * 0.25f) * func_80013970((((Objwater_arg0 *)arg0)->unk4) * 0.11f * 180.0f));
    if ((((Objwater_arg0 *)arg0)->unk14) < (((Objwater_arg0 *)arg0)->unk1C)) {
        (((Objwater_arg0 *)arg0)->unk18) = (((Objwater_arg0 *)arg0)->unk14);
        (((Objwater_arg0 *)arg0)->unk14) = (f32) ((((Objwater_arg0 *)arg0)->unk14) + sp30);
        if ((((Objwater_arg0 *)arg0)->unk1C) < (((Objwater_arg0 *)arg0)->unk14)) {
            (((Objwater_arg0 *)arg0)->unk14) = (((Objwater_arg0 *)arg0)->unk1C);
        }
    }
    if ((((Objwater_arg0 *)arg0)->unk14) < (((Objwater_arg0 *)arg0)->unk1C)) {
        temp_v0 = (((Objwater_arg0 *)arg0)->unkC);
        var_f0 = (f32) temp_v0;
        var_f0 += ((((Objwater_arg0 *)arg0)->unk14) / (((Objwater_arg0 *)arg0)->unk1C)) * (f32) ((((Objwater_arg0 *)arg0)->unkE) - temp_v0);
    } else {
        var_f0 = (f32) (((Objwater_arg0 *)arg0)->unkE);
    }
    var_f0 += temp_f18;
    if (var_f0 >= 0.0f) {
        (((Objwater_arg0 *)arg0)->unk10) = (s32) (var_f0 + 0.5f);
    } else {
        (((Objwater_arg0 *)arg0)->unk10) = (s32) (var_f0 - 0.5f);
    }
    _glid_entrypoint_2(BT_NATIVE_ONLY((u8 *))arg1, arg2, &_idwater_entrypoint_0, BT_NATIVE_ONLY((u8 *))arg0);
}
