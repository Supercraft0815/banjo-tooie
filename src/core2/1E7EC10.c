#include "common.h"

void func_800A5320(void) {
    void func_800EF8BC(f32 dst[3], f32 src[3], f32 pitch);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern f32 D_801255C0;
    extern f32 D_801270A0[3], D_801270B0[3], D_801270C0[3];
    extern f32 D_801270D0[3], D_801270E0[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EFA4C(sp34, 0.0f, -1.0f, 0.0f);
    func_800EF8BC(sp1C, sp34, 68.0f);
    func_800EFA4C(sp28, sp1C[1] * D_801255C0, 0.0f, sp1C[2]);
    D_801270E0[0] = sp1C[0];
    D_801270E0[1] = sp1C[1];
    D_801270E0[2] = sp1C[2];
    D_801270A0[0] = sp28[0] + sp1C[0];
    D_801270A0[1] = sp28[1] + sp1C[1];
    D_801270B0[0] = sp28[0] - sp1C[0];
    D_801270B0[1] = sp28[1] - sp1C[1];
    sp34[0] = -sp28[0];
    sp34[1] = -sp28[1];
    D_801270C0[0] = sp34[0] - sp1C[0];
    D_801270C0[1] = sp34[1] - sp1C[1];
    D_801270D0[0] = sp34[0] + sp1C[0];
    D_801270D0[1] = sp34[1] + sp1C[1];
    D_801270A0[2] = sp1C[2];
    D_801270B0[2] = sp1C[2];
    D_801270C0[2] = sp1C[2];
    D_801270D0[2] = sp1C[2];
}

void func_800A5430(f32 rotation[3], f32 position[3], f32 arg2, f32 dest[3]) {
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 sp24[3];
    func_800EF4E4(sp24, rotation[0], rotation[1], 0.0f, 0.0f, -arg2);
    func_800EE780(dest, sp24, position);
}

/* extern */

void func_800A5490(void) {
    s32 func_8008FFE8();
    s32 func_8010FFD8(s32);
    func_8010FFD8(func_8008FFE8());
}
