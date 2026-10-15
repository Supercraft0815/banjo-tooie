#include "common.h"

/* extern */

void fxairbub_entrypoint_0(s32 arg0) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

void fxairbub_entrypoint_1(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3) {
    s32 func_800B5BE4(s32);
    void func_800BA544(s32 *, s32);
    void func_800BA568(s16 *, s16);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800100_fxairbub;
    extern s32 _fxairbub_entrypoint_0;
    s32 sp2C;
    s32 temp_f10;
    int temp_f16;
    s32 temp_v0;

    temp_v0 = func_800B5BE4(2);
    sp2C = temp_v0;
    func_800BA568(temp_v0, (s16) (s32) arg2);
    temp_f16 = (s32) arg1;
    temp_f10 = (s32) -arg1;
    func_800BA6B0(sp2C, (s16) temp_f10, 0, (s16) temp_f10, (s32) (s16) temp_f16, 0, (s32) (s16) temp_f16);
    func_800BA544(sp2C, &_fxairbub_entrypoint_0);
    func_800BABB8(sp2C, arg0, 0, arg3, &D_80800100_fxairbub);
}
