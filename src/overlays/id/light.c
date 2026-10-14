#include "common.h"

void idlight_entrypoint_0(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, f32 *arg4) {
    f32 scale = *arg4;
    u8 *end = arg1 + arg3 * 0x10;

    for (; arg1 < end; arg1 += 0x10, arg2 += 0x10) {
        arg2[12] = (u32)((f32)(u32)arg1[12] * scale);
        arg2[13] = (u32)((f32)(u32)arg1[13] * scale);
        arg2[14] = (u32)((f32)(u32)arg1[14] * scale);
    }
}

void idlight_entrypoint_1(s32 arg0) 
{
}
void idlight_entrypoint_2(f32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *arg0 = 1.0f;
}

void idlight_entrypoint_3(f32 *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, f32 *);
    f32 func_800DC264(f32, f32);
    extern s32 _idlight_entrypoint_0;
    f32 temp_f2;

    *arg0 += func_800DC264(-0.04f, 0.04f);
    temp_f2 = *arg0;
    if (temp_f2 > 1.0f) {
        *arg0 = 1.0f;
    } else {
        *arg0 = temp_f2;
    }
    temp_f2 = *arg0;
    if (temp_f2 < 0.8f) {
        *arg0 = 0.8f;
    } else {
        *arg0 = temp_f2;
    }
    _glid_entrypoint_0(arg1, arg2, &_idlight_entrypoint_0, arg0);
}
