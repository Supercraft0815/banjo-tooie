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

s32 func_800EFFB4(f32 point[3], f32 radius, f32 center[3]) {
    void func_800EFB24(f32 *, f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    f32 delta[3];
    func_800EFB24(delta, center, point);
    return func_800EEFD4(delta) <= radius * radius;
}

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

void func_800F03AC(f32 dst[3], f32 point[3], f32 normal[3], f32 position[3]) {
    void func_800EFB24(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFA20(f32 *, f32 *, f32);
    f32 delta[3];
    func_800EFB24(delta, position, point);
    func_800EFA20(delta, normal, func_800EEAA4(normal, delta));
    func_800EFB24(dst, position, delta);
}

void func_800F0410(f32 dst[3], f32 arg2[3][3], f32 arg1[3]){
    void func_800F0274(f32 *, f32 *, f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    func_800F0274(sp40, arg2[0], arg2[1], arg1);
    func_800F0274(sp34, arg2[1], arg2[2], arg1);
    func_800F0274(sp28, arg2[2], arg2[0], arg1);

    sp54 = func_800EEB40(sp40, arg1);
    sp50 = func_800EEB40(sp34, arg1);
    sp4C = func_800EEB40(sp28, arg1);

    if(sp54 < sp50){
        if(sp4C < sp54){
            func_800EE7F8(dst, sp28);
        }
        else{
            func_800EE7F8(dst, sp40);
        }
    }
    else{//L80257868
        if(sp4C < sp50)
            func_800EE7F8(dst, sp28);
        else
            func_800EE7F8(dst, sp34);
    }


}

void func_800F0524(f32 dst[3], f32 vec1[9], f32 vec2[3]) {
    void func_800EFB24(f32 *, f32 *, f32 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    s32 func_800EF2A0(s32);
    void func_800F03AC(f32 *, f32 *, f32 *, f32 *);
    f32 tmp1[3];
    f32 tmp2[3];
    f32 tmp3[3];
    func_800EFB24(tmp1, &vec1[3], vec1);
    func_800EFB24(tmp2, &vec1[6], vec1);
    func_800EE97C(tmp3, tmp1, tmp2);
    func_800EF2A0((s32)tmp3);
    func_800F03AC(dst, vec1, tmp3, vec2);
}

void func_800F059C(f32 dst[3], f32 src[3], f32 normal[3]) {
    void func_800EFA20(f32 *, f32 *, f32);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFB24(f32 *, f32 *, f32 *);
    f32 tmp[3];
    f32 dot;
    func_800EFA20(dst, src, -1.0f);
    dot = func_800EEAA4(dst, normal);
    func_800EFA20(tmp, normal, dot + dot);
    func_800EFB24(dst, tmp, dst);
}

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
