#include "core2/1ECB0F0.h"

/* extern */

void func_800F1800(void) {
    f32 func_80013AAC();
    f32 mlAbsF(f32);
    mlAbsF(func_80013AAC());
}

/* extern */

f32 func_800F1828(f32 *arg0, f32 *arg1) {
    f32 func_80013B7C(f32, f32);
    f32 sp18[2];
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = (*(f32 *)((s8 *)(arg1) + (0))) - (*(f32 *)((s8 *)(arg0) + (0)));
    sp18[0] = (*(f32 *)((s8 *)(arg1) + (4))) - (*(f32 *)((s8 *)(arg0) + (4)));
    temp_f2 = (*(f32 *)((s8 *)(arg1) + (8))) - (*(f32 *)((s8 *)(arg0) + (8)));
    return func_80013B7C(sp18[0], sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)));
}

s32 func_800F1884(f32 *arg0, f32 *arg1) {
    f32 func_80013B7C(f32, f32);
    f32 z;
    f32 x;
    f32 length;

    z = arg0[2];
    x = arg0[0];
    length = sqrtf(z * z + x * x);
    if (length == 0.0f) {
        *arg1 = 0.0f;
        return 0;
    }
    *arg1 = func_80013B7C(arg0[1], length);
    return 1;
}

/* extern */

void func_800F18FC(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 func_80013B70(f32, f32, f32);
    f32 func_80013B7C(f32, f32);
    f32 x;
    f32 y;
    f32 z;
    f32 length;

    x = arg1[0] - arg0[0];
    y = arg1[1] - arg0[1];
    z = arg1[2] - arg0[2];
    length = sqrtf(x * x + z * z);
    arg2[1] = func_80013B70(x, z, length);
    arg2[0] = func_80013B7C(y, length);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1988.s")

void func_800F1A88(f32 *arg0, f32 *arg1) {
    f32 func_80013B70(f32, f32, f32);
    f32 func_80013B7C(f32, f32);
    f32 sp1C;
    f32 z;
    f32 x;

    z = arg0[2];
    x = arg0[0];
    sp1C = sqrtf(z * z + x * x);
    arg1[1] = func_80013B70(arg0[0], arg0[2], sp1C);
    arg1[0] = func_80013B7C(arg0[1], sp1C);
}

void func_800F1AFC(f32 *arg0, f32 *arg1) {
    f32 func_80013B70(f32, f32, f32);
    f32 func_80013B7C(f32, f32);
    f32 sp1C;
    f32 z;
    f32 x;

    z = arg0[2];
    x = arg0[0];
    sp1C = sqrtf(z * z + x * x);
    arg1[1] = func_80013B70(arg0[0], arg0[2], sp1C);
    arg1[0] = func_80013B7C(arg0[1], sp1C);
    arg1[2] = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECB0F0/func_800F1B78.s")

f32 func_800F1C98(f32 *arg0, f32 *arg1) {
    void func_800EE97C(f32 dst[3], f32 a[3], f32 b[3]);
    f32 func_800EEF94(f32*);
    f32 sp2C;
    f32 sp28;
    f32 sp1C[3];

    sp2C = func_800EEF94(arg0);
    sp28 = func_800EEF94(arg1);
    func_800EE97C(sp1C, arg0, arg1);
    return func_800EEF94(sp1C) / (sp2C * sp28);
}

f32 func_800F1CF0(f32 *arg0, f32 *arg1) {
    f32 mlAbsF(f32);
    f32 sqrtf(f32);
    extern f32 D_80125ED4;
    f32 denominator;
    f32 cross;
    f32 pad;
    f32 length;
    f32 x;
    f32 z;
    f32 secondZ;
    f32 secondX;
    f32 absolute;

    x = arg0[0];
    z = arg0[2];
    length = sqrtf(x * x + z * z);
    secondZ = arg1[2];
    secondX = arg1[0];
    denominator = sqrtf(secondZ * secondZ + secondX * secondX) * length;
    if (D_80125ED4 < denominator) {
        cross = arg0[2] * arg1[0] - arg0[0] * arg1[2];
        absolute = mlAbsF(cross);
        if (denominator < absolute) {
            denominator = absolute;
        }
        return cross / denominator;
    }
    return 0.0f;
}

f32 func_800F1DCC(f32 arg0, f32 arg1) {
    f32 func_80013728(f32);
    return func_80013728(arg0 - arg1);
}

/* extern */

f32 func_800F1DF4(f32 *arg0, f32 *arg1) {
    f32 func_80013B7C(f32, f32);
    return ((f32)(func_80013B7C((*(f32 *)((s8 *)(arg1) + (0))) - (*(f32 *)((s8 *)(arg0) + (0))), arg1[2] - arg0[2])));
}

/* extern */

void func_800F1E28(void *arg0, void *arg1) {
    f32 func_80013B7C(f32, f32);
    func_80013B7C((f32) ((*(s16 *)((s8 *)(arg1) + (0))) - (*(s16 *)((s8 *)(arg0) + (0)))), (f32) ((*(s16 *)((s8 *)(arg1) + (4))) - (*(s16 *)((s8 *)(arg0) + (4)))));
}

s32 func_800F1E6C(f32 *arg0, f32 *arg1, f32 *target_yaw) {
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 sp1C[3];

    func_800EFB24(sp1C, arg1, arg0);
    return func_800F1EA4(sp1C, target_yaw);
}

/* extern */

int func_800F1EA4(f32 *arg0, f32 *arg1) {
    f32 func_80013B7C(f32, f32);

    if (arg0[0] != 0.0f || arg0[2] != 0.0f) {
        *arg1 = func_80013B7C(arg0[0], arg0[2]);
        return 1;
    } else {
        *arg1 = 0.0f;
        return 0;
    }
}

void func_800F1F0C(f32 *arg0, f32 *arg1, f32 arg2) {
    func_800F1DCC(func_800F1DF4(arg0, arg1), arg2);
}

/* extern */

f32 func_800F1F38(f32 arg0, f32 arg1, f32 arg2) {
    f32 func_800136E4(f32);
    f32 func_800F1DCC(f32, f32);
    f32 temp_f2;
    f32 var_f0;
    f32 var_f12;

    if (arg1 == arg0) {
        return arg1;
    }
    var_f0 = func_800F1DCC(arg1, arg0);
    if (var_f0 > 0.0f) {
        if (var_f0 < arg2) {
            temp_f2 = var_f0;
        } else {
            temp_f2 = arg2;
        }
        var_f0 = temp_f2;
    } else {
        temp_f2 = -arg2;
        if (temp_f2 < var_f0) {
            var_f12 = var_f0;
        } else {
            var_f12 = temp_f2;
        }
        var_f0 = var_f12;
    }
    return func_800136E4(arg0 + var_f0);
}

/* extern */

f32 func_800F1FF0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800136E4(f32);
    f32 mlAbsF(f32);
    f32 var_f2;
    f32 temp_f0;

    var_f2 = func_800F1DCC(arg1, arg0) * arg2;
    temp_f0 = mlAbsF(var_f2);
    if (temp_f0 < arg3) {
        return arg1;
    }
    if (arg4 < temp_f0) {
        if (var_f2 < 0.0f) {
            var_f2 = -arg4;
        } else {
            var_f2 = arg4;
        }
    }
    return func_800136E4(arg0 + var_f2);
}

/* extern */

f32 func_800F2094(f32 arg0, f32 arg1) {
    f32 mlAbsF(f32);
    return mlAbsF(func_800F1DCC(arg0, arg1));
}

int func_800F20BC(f32 arg0, f32 arg1, f32 arg2) { return func_800F2094(arg0, arg1) < arg2; }
