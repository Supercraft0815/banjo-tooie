#include "common.h"

/* extern */

void fxsplash_entrypoint_0(s32 arg0) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

void fxsplash_entrypoint_1(f32 arg0[3]) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 fxsplash_entrypoint_2(f32[3], f32);
    extern s32 D_80800130_fxsplash;
    func_800BABB8(fxsplash_entrypoint_2(arg0, 20.0f), 0, 0, 1.0f, &D_80800130_fxsplash);
}

s32 fxsplash_entrypoint_2(f32 arg0[3], f32 arg1) {
    s32 func_800B5BE4(s32);
    void func_800BA4D0(s16 *, s16);
    void func_800BA544(s32 *, s32);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800144_fxsplash;
    extern s32 _fxsplash_entrypoint_0;
    s32 sp2C;
    s32 temp_f6;
    s32 temp_f8;
    s32 temp_v0;

    temp_v0 = func_800B5BE4(1);
    sp2C = temp_v0;
    temp_f8 = (s32) arg1;
    temp_f6 = (s32) -arg1;
    func_800BA6B0(temp_v0, (s16) temp_f6, 0, (s16) temp_f6, (s16) temp_f8, 0, (s16) temp_f8);
    func_800BA4D0(sp2C, (s16) (s32) arg0[1]);
    func_800BA544(sp2C, &_fxsplash_entrypoint_0);
    return func_800BABB8(sp2C, arg0, 0, 1.0f, &D_80800144_fxsplash);
}
