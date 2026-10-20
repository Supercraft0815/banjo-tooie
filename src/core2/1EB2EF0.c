#include "common.h"

void func_800D9600(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) (*(f32 *)((s8 *)(arg1) + (0)));
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (*(f32 *)((s8 *)(arg1) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg1) + (0xC)));
}

void func_800D9624(f32 *arg0, f32 *arg1) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = -arg1[i];
    }
    arg0[3] = arg1[3];
}

void func_800D965C(f32 arg0[4], f32 arg1[16]) {
    f32 s;
    f32 wx;
    f32 wy;
    f32 wz;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 xx;
    f32 xy;
    f32 xz;
    f32 yy;
    f32 yz;
    f32 zz;
    if (arg0[0] == 0.0f && arg0[1] == 0.0f && arg0[2] == 0.0f && arg0[3] == 0.0f) {
    }
    s = 2.0f / (arg0[0] * arg0[0] + arg0[1] * arg0[1] + arg0[2] * arg0[2] + arg0[3] * arg0[3]);
    xs = arg0[0] * s;
    ys = arg0[1] * s;
    zs = arg0[2] * s;
    wx = arg0[3] * xs;
    wy = arg0[3] * ys;
    wz = arg0[3] * zs;
    xx = arg0[0] * xs;
    xy = arg0[0] * ys;
    xz = arg0[0] * zs;
    yy = arg0[1] * ys;
    yz = arg0[1] * zs;
    zz = arg0[2] * zs;
    arg1[0] = 1.0f - (yy + zz);
    arg1[1] = xy + wz;
    arg1[2] = xz - wy;
    arg1[4] = xy - wz;
    arg1[5] = 1.0f - (xx + zz);
    arg1[6] = yz + wx;
    arg1[8] = xz + wy;
    arg1[9] = yz - wx;
    arg1[10] = 1.0f - (xx + yy);
    arg1[15] = 1.0f;
    arg1[3] = 0;
    arg1[7] = 0;
    arg1[11] = 0;
    arg1[12] = 0;
    arg1[13] = 0;
    arg1[14] = 0;
}

int func_800D97E8(f32 a[4], f32 b[4]) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9888.s")

void func_800D9AD4(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3) {
    void func_800D9888(f32 *, f32 *, f32 *, f32);
    f32 var_f0;
    f32 var_f2;
    f32 sp20[4];

    sp20[0] = arg1[0]-arg2[0];
    sp20[1] = arg1[1]-arg2[1];
    sp20[2] = arg1[2]-arg2[2];
    sp20[3] = arg1[3]-arg2[3];
    var_f0 = (sp20[0]*sp20[0] + sp20[1]*sp20[1] + sp20[2]*sp20[2] + sp20[3]*sp20[3]);

    sp20[0] = arg1[0]+arg2[0];
    sp20[1] = arg1[1]+arg2[1];
    sp20[2] = arg1[2]+arg2[2];
    sp20[3] = arg1[3]+arg2[3];
    var_f2 = (sp20[0]*sp20[0] + sp20[1]*sp20[1] + sp20[2]*sp20[2] + sp20[3]*sp20[3]);

    if (var_f0 <= var_f2) {
        func_800D9888(arg0, arg1, arg2, arg3);
        return;
    }
    sp20[0] = -arg2[0];
    sp20[1] = -arg2[1];
    sp20[2] = -arg2[2];
    sp20[3] = -arg2[3];
    func_800D9888(arg0, arg1, sp20, arg3);

}

void func_800D9C34(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (8))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0xC))) = 0x3F800000;
}

int func_800D9C4C(f32 arg0[4]){
    return ((arg0[0] == 0.0f)
        && (arg0[1] == 0.0f)
        && (arg0[2] == 0.0f)
        && (arg0[3] == 1.0f));
}

void func_800D9CE8(f32 arg0[4], f32 arg1[9]) {
    f32 s;
    f32 wx, wy, wz;
    f32 xs, ys, zs;
    f32 xx, xy, xz;
    f32 yy, yz, zz;

    if (arg0[0] == 0.0f && arg0[1] == 0.0f && arg0[2] == 0.0f && arg0[3] == 0.0f) {
    }
    s = 2.0f / (arg0[0] * arg0[0] + arg0[1] * arg0[1] + arg0[2] * arg0[2] + arg0[3] * arg0[3]);
    xs = arg0[0] * s;
    ys = arg0[1] * s;
    zs = arg0[2] * s;
    wx = arg0[3] * xs;
    wy = arg0[3] * ys;
    wz = arg0[3] * zs;
    xx = arg0[0] * xs;
    xy = arg0[0] * ys;
    xz = arg0[0] * zs;
    yy = arg0[1] * ys;
    yz = arg0[1] * zs;
    zz = arg0[2] * zs;
    arg1[0] = 1.0f - (yy + zz);
    arg1[1] = xy + wz;
    arg1[2] = xz - wy;
    arg1[3] = xy - wz;
    arg1[4] = 1.0f - (xx + zz);
    arg1[5] = yz + wx;
    arg1[6] = xz + wy;
    arg1[7] = yz - wx;
    arg1[8] = 1.0f - (xx + yy);
}
