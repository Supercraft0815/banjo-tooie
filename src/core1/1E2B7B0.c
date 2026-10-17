#include "common.h"

void func_80013C80(Mtx *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800F2984(f32 [4][4], s32, f32 *, f32 *, f32 *);
    f32 sp48[4][4];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EFA4C(sp3C, arg2, arg3, arg4);
    func_800EFA4C(sp30, arg5, arg6, arg7);
    func_800EFA4C(sp24, arg8, arg9, arg10);
    func_800F2984(sp48, arg1, sp3C, sp30, sp24);
    guMtxF2L(sp48, arg0);
}
