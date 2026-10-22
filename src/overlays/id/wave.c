#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wave/idwave_entrypoint_0.s")

void idwave_entrypoint_1(s32 arg0) 
{
}
void idwave_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void _glidmake_entrypoint_2(s32, s32, u8 *, u8 *);
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

void idwave_entrypoint_3(void *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    extern s32 _idwave_entrypoint_0;
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
    _glid_entrypoint_0(arg1, arg2, &_idwave_entrypoint_0, (s32)arg0);
}
