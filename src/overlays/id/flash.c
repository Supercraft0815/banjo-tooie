#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flash/idflash_entrypoint_0.s")

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
