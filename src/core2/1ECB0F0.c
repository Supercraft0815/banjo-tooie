#include "core2/1ECB0F0.h"

f32 func_800F1800(f32 arg0) {
    f32 func_80013AAC(f32);
    f32 mlAbsF(f32);
    return mlAbsF(func_80013AAC(arg0));
}

/* extern */

f32 func_800F1828(f32 *arg0, f32 *arg1) {
    f32 func_80013B7C(f32, f32);
    f32 sp18[2];
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = (((Vec3f *)arg1)->pos.x) - (((Vec3f *)arg0)->pos.x);
    sp18[0] = (((Vec3f *)arg1)->pos.y) - (((Vec3f *)arg0)->pos.y);
    temp_f2 = (((Vec3f *)arg1)->pos.z) - (((Vec3f *)arg0)->pos.z);
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

int func_800F1988(f32 *arg0, f32 *arg1, f32 *arg2) {

    f32 length;

    *arg1 = 0.0f;
    *arg2 = 0.0f;
    length = sqrtf(arg0[2] * arg0[2] + arg0[0] * arg0[0]);
    if (length < 0.01f) {
        return 0;
    }
    *arg2 = func_800F1800(arg0[0] / length);
    if (arg0[2] < 0.0f) {
        *arg2 = 180.0f - *arg2;
    }
    if (arg0[0] < 0) {
        *arg2 = 360.0f - *arg2;
    }
    *arg1 = func_800F1800(length);
    return 1;
}

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

/* extern */

s32 func_800F1B78(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3) {
    void func_800EFD24(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_800F1988(f32 *, f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    s32 sp2C;

    func_800EFD24(arg0);
    sp2C = func_800F1988(arg1, &sp3C, &sp38);
    sp3C *= arg3;
    if (sp2C != 0) {
        sp30 = func_800F1DCC(arg2, sp38);
        sp34 = mlAbsF(sp30);
        arg0[0] = func_800F10B4(sp34, 0.0f, 180.0f, sp3C, -sp3C);
        if (sp34 < 90.0f) {
            arg0[2] = func_800F10B4(sp34, 0.0f, 90.0f, 0.0f, sp3C);
        } else {
            arg0[2] = func_800F10B4(sp34, 90.0f, 180.0f, sp3C, 0.0f);
        }
        if (sp30 < 0.0f) {
            arg0[2] = -arg0[2];
        }
    }
    return sp2C;
}

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
    if (0.000001f < denominator) {
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
}    typedef struct { f32 unk0; s16 unk4; } Obj1ECB0F0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { f32 unk0; s16 unk4; } Obj1ECB0F0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

f32 func_800F1DF4(f32 *arg0, f32 *arg1) {
    f32 func_80013B7C(f32, f32);
    return ((f32)(func_80013B7C((((Obj1ECB0F0_arg1 *)arg1)->unk0) - (((Obj1ECB0F0_arg0 *)arg0)->unk0), arg1[2] - arg0[2])));
}

/* extern */

void func_800F1E28(void *arg0, void *arg1) {
    f32 func_80013B7C(f32, f32);
    func_80013B7C((f32) ((*(s16 *)((s8 *)(arg1) + (0))) - (*(s16 *)((s8 *)(arg0) + (0)))), (f32) ((((Obj1ECB0F0_arg1 *)arg1)->unk4) - (((Obj1ECB0F0_arg0 *)arg0)->unk4)));
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

f32 func_800F1F0C(f32 *arg0, f32 *arg1, f32 arg2) {
    return func_800F1DCC(func_800F1DF4(arg0, arg1), arg2);
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
