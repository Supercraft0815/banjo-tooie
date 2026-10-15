#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/3d/subaddie3d_entrypoint_0.s")

/* extern */

s32 subaddie3d_entrypoint_1(f32 arg0[3], f32 arg1, f32 arg2, f32 *arg3) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp28, arg0);
    sp28[1] += arg1;
    func_800EE7F8(sp1C, arg0);
    sp1C[1] += arg2;
    if (func_800BEF00(sp28, sp1C, sp34, 0x1F00) != 0) {
        *arg3 = sp1C[1];
        return 1;
    }
    return 0;
}
