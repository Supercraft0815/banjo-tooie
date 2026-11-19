#include "common.h"

/* extern */

typedef struct { u8 pad0[0x4]; f32 unk4; f32 unk8; f32 unkC; f32 unk10; f32 unk14; u8 pad18[0x8]; f32 unk20; f32 unk24; s16 unk28; s16 unk2A; } Objwave_arg4; /* offsets.py genstruct: fields from raw offsets on arg4; rename once understood */ typedef struct { s16 unk0; u8 pad2[0x2]; s16 unk4; } Objwave_idwave_entrypoint_0_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */ void idwave_entrypoint_0(s32 arg0, u32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s32 pad[3];
    f32 func_800136D0(f32);
    f32 func_800138BC(f32);
    f32 func_8001395C(f32);
    f32 sp70;
    f32 sp6C;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f30;
    s16 temp_s4;
    s16 temp_s5;
    s32 temp_f16;
    u32 temp_s6;
    BtUIntPtr var_s1;
    u8 *var_s0;

    temp_f26 = (((Objwave_arg4 *)arg4)->unk4);
    temp_f28 = (((Objwave_arg4 *)arg4)->unk8);
    temp_f30 = (((Objwave_arg4 *)arg4)->unk10);
    sp70 = (((Objwave_arg4 *)arg4)->unk14);
    sp6C = (((Objwave_arg4 *)arg4)->unkC);
    var_s0 = arg2;
    var_s1 = arg1;
    temp_s4 = (((Objwave_arg4 *)arg4)->unk28);
    temp_s5 = (((Objwave_arg4 *)arg4)->unk2A);
    temp_s6 = (arg3 * 0x10) + arg1;
    if (arg1 < temp_s6) {
        do {
            temp_f20 = func_800136D0((((f32) (((Objwave_idwave_entrypoint_0_var_s0 *)var_s0)->unk0) - temp_f30) * 200.0f) + temp_f26);
            temp_f22 = func_800136D0((((f32) (((Objwave_idwave_entrypoint_0_var_s0 *)var_s0)->unk4) - sp70) * 200.0f) + temp_f28);
            temp_f20_2 = func_8001395C(temp_f20);
            temp_f2 = func_800138BC(temp_f22) + temp_f20_2;
            temp_f2 *= (((Objwave_arg4 *)arg4)->unk20);
            var_s1 += 0x10;
            var_s0 += 0x10;
            (*(s16 *)((s8 *)(var_s0) + (-0xE))) = (s16) (s32) (sp6C + temp_f2);
            temp_f16 = (s32) (((temp_f2 / (((Objwave_arg4 *)arg4)->unk24)) * 50.0f) + 205.0f);
            (*(s8 *)((s8 *)(var_s0) + (-4))) = (s8) ((s32) ((*(u8 *)((s8 *)(var_s1) + (-4))) * temp_f16) / 255);
            (*(s8 *)((s8 *)(var_s0) + (-3))) = (s8) ((s32) ((*(u8 *)((s8 *)(var_s1) + (-3))) * temp_f16) / 255);
            (*(s8 *)((s8 *)(var_s0) + (-2))) = (s8) ((s32) ((*(u8 *)((s8 *)(var_s1) + (-2))) * temp_f16) / 255);
            (*(s16 *)((s8 *)(var_s0) + (-8))) = (s16) ((*(s16 *)((s8 *)(var_s1) + (-8))) + temp_s4);
            (*(s16 *)((s8 *)(var_s0) + (-6))) = (s16) ((*(s16 *)((s8 *)(var_s1) + (-6))) + temp_s5);
        } while (var_s1 < temp_s6);
    }
}

void idwave_entrypoint_1(void *arg0)
{
}
void idwave_entrypoint_2(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 flags) {
    void _glidmake_entrypoint_2(BtIntPtr, s32, u8 *, u8 *);
    struct Wave { f32 f[10]; s16 a; s16 b; f32 c; };
    s16 sp28[3];
    s16 sp20[3];

    _glidmake_entrypoint_2(arg2, arg3, (u8 *)sp28, (u8 *)sp20);
    ((struct Wave *)arg0)->f[1] = 0.0f;
    ((struct Wave *)arg0)->f[2] = 0.0f;
    ((struct Wave *)arg0)->f[0] = 1.0f;
    ((struct Wave *)arg0)->f[3] = sp28[1] + (sp20[1] - sp28[1]) * 0.5f;
    ((struct Wave *)arg0)->f[4] = sp28[0];
    ((struct Wave *)arg0)->f[5] = sp28[2];
    ((struct Wave *)arg0)->f[8] = (sp20[1] - sp28[1]) * 0.25f;
    ((struct Wave *)arg0)->a = 0;
    ((struct Wave *)arg0)->b = 0;
    ((struct Wave *)arg0)->c = 0.0f;
    ((struct Wave *)arg0)->f[9] = 2.0f * ((struct Wave *)arg0)->f[8];
    if (arg1 >= 0 && arg1 < 11) {
        ((struct Wave *)arg0)->f[0] = arg1 * 0.1f;
    }
}

void idwave_entrypoint_3(void *arg0, void *arg1, s32 arg2) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
#ifndef BT_NATIVE
    extern s32 _idwave_entrypoint_0;
#endif
    struct Wave { f32 f[10]; s16 a; s16 b; f32 c; };
    f32 pad;
    f32 sp28[1];
    f32 sp24[1];
    f32 sp20;
    f32 dt;
    f32 speed;

    dt = func_800D8FF8();
    speed = ((struct Wave *)arg0)->f[0];
    ((struct Wave *)arg0)->c += dt;
    ((struct Wave *)arg0)->f[1] += dt * speed * 3.0f;
    ((struct Wave *)arg0)->f[2] += dt * (speed + 0.01f) * 3.0f;
    sp20 = func_800138D0(((struct Wave *)arg0)->c * 0.2f * 180.0f);
    sp24[0] = (func_80013970(((struct Wave *)arg0)->c * 0.08f * 180.0f) * 100.0f + 150.0f * sp20) * 0.8f;
    sp20 = func_80013970(((struct Wave *)arg0)->c * 0.5f * 180.0f);
    sp28[0] = (func_800138D0(((struct Wave *)arg0)->c * 0.22f * 180.0f) * 100.0f + 50.0f * sp20) * 0.8f;
    if (sp24[0] >= 0.0f) {
        ((struct Wave *)arg0)->a = (s32)(sp24[0] + 0.5f);
    } else {
        ((struct Wave *)arg0)->a = (s32)(sp24[0] - 0.5f);
    }
    if (sp28[0] >= 0.0f) {
        ((struct Wave *)arg0)->b = (s32)(sp28[0] + 0.5f);
    } else {
        ((struct Wave *)arg0)->b = (s32)(sp28[0] - 0.5f);
    }
    _glid_entrypoint_0(arg1, arg2, &_idwave_entrypoint_0, (BtIntPtr)arg0);
}
