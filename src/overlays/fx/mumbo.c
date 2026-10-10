#include "common.h"

void fxmumbo_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800B5BE4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800060_fxmumbo;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B5BE4(0xD);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg0, 0, 0x3F800000, &D_80800060_fxmumbo);
    func_800BA22C(sp24, arg1);
}
