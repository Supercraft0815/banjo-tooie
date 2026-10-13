#include "common.h"

void idflash_entrypoint_0(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, f32 *arg4) {
    s32 brightness;
    s32 value;
    Vtx *end;

    brightness = (s32)(*arg4 * 50.0f);
    end = arg1 + arg3;
    for (; arg1 < end; arg1++, arg2++) {
        value = arg1->v.cn[0] + brightness;
        if (value >= 0x100) {
            value = 0xFF;
        }
        arg2->v.cn[0] = value;
        value = arg1->v.cn[1] + brightness;
        if (value >= 0x100) {
            value = 0xFF;
        }
        arg2->v.cn[1] = value;
        value = arg1->v.cn[2] + brightness;
        if (value >= 0x100) {
            value = 0xFF;
        }
        arg2->v.cn[2] = value;
    }
}

void idflash_entrypoint_1(s32 arg0) 
{
}
void idflash_entrypoint_2(f32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *arg0 = 0.0f;
}

void idflash_entrypoint_3(f32 *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, f32 *);
    s32 _idflasha_entrypoint_1(s32);
    s32 _idworld_entrypoint_1(s32);
    extern s32 _idflash_entrypoint_0;
    s32 temp_v0;

    temp_v0 = _idworld_entrypoint_1(arg2 - 0x64);
    if (temp_v0 != 0) {
        *arg0 = (f32) _idflasha_entrypoint_1(temp_v0) * 0.003921569f;
    } else {
        *arg0 = 0.0f;
    }
    _glid_entrypoint_0(arg1, arg2, &_idflash_entrypoint_0, arg0);
}
