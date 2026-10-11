#include "common.h"

void func_800EFE50(f32 dst[3], f32 start[3], f32 end[3], f32 t) {
    int i;
    for (i = 0; i < 3; i++) {
        dst[i] = start[i] + (end[i] - start[i]) * t;
    }
}

int func_800EFED0(f32 min[3], f32 max[3], f32 vec[3])
{
    return vec[0] > min[0] && vec[0] < max[0]
        && vec[1] > min[1] && vec[1] < max[1]
        && vec[2] > min[2] && vec[2] < max[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800EFFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F00A4.s")

int func_800F0130(s32 vec2[3], s32 distance, s32 vec1[3])
{
    s32 diff[3];

    diff[0] = vec1[0] - vec2[0];
    diff[2] = vec1[2] - vec2[2];

    return (diff[0] * diff[0] + diff[2] * diff[2]) < distance * distance;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F018C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F03AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F059C.s")

s32 func_800F05F8(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4) {
    f32 delta[3];
    f32 a, b, c;
    f32 root, dot, discriminant;
    f32 b2[1], ac[1];
    s32 result;

    delta[0] = arg0[0] - arg2[0];
    delta[2] = arg0[2] - arg2[2];
    a = arg1[0] * arg1[0] + arg1[2] * arg1[2];
    if (a == 0.0f) {
        return 0;
    }
    b = 2.0f * (arg1[0] * delta[0] + arg1[2] * delta[2]);
    c = delta[0] * delta[0] + delta[2] * delta[2] - arg3 * arg3;
    b2[0] = b * b;
    ac[0] = 4.0f * a * c;
    if (b2[0] < ac[0]) {
        return 0;
    }
    discriminant = b2[0] - ac[0];
    root = sqrtf(discriminant);
    a = 0.5f / a;
    arg4[0] = (root - b) * a;
    if (root != 0.0f) {
        arg4[1] = -(b + root) * a;
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0734.s")

s32 func_800F0AA4(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 a, b, c;
    f32 d, e;

    a = arg1[2] - arg0[2];
    b = arg0[0] - arg1[0];
    c = arg1[0] * arg0[2] - arg0[0] * arg1[2];
    d = a * arg2[0] + b * arg2[2] + c;
    e = a * arg3[0] + b * arg3[2] + c;
    if (d * e > 0.0f) {
        return 0;
    }
    a = arg3[2] - arg2[2];
    b = arg2[0] - arg3[0];
    c = arg3[0] * arg2[2] - arg2[0] * arg3[2];
    d = a * arg0[0] + b * arg0[2] + c;
    e = a * arg1[0] + b * arg1[2] + c;
    if (d * e > 0.0f) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0BD0.s")

/* extern */

f32 func_800F0C68(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 func_800EF2A0(s32);
    func_800EF2A0(arg1);
    return arg2 / sqrtf((arg2 * arg2) + (arg3 * arg3));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0CB4.s")
