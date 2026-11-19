#include "common.h"

s32 func_800D2F20(void) {
    s32 func_800BDC5C();
    return func_800BDC5C() * 4;
}

s32 func_800D2F44(BtIntPtr arg0, s32 *arg1, s32 arg2, f32 *arg3) {
    s32 func_800E3D0C(f32 *, f32 *);
    f32 func_800E42C0(void);

    f32 min[3];
    f32 max[3];
    f32 delta[3];
    f32 radius;
    f32 scale;
    s32 i;

    scale = func_800E42C0();
    delta[0] = (f32)(arg1[0] * arg2 + arg2 / 2) - arg3[0];
    delta[1] = (f32)(arg1[1] * arg2 + arg2 / 2) - arg3[1];
    delta[2] = (f32)(arg1[2] * arg2 + arg2 / 2) - arg3[2];
    radius = scale * 4.0f * (1.4142135f * (f32)arg2);
    if (radius * radius < delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]) {
        return 0;
    }
    scale = arg2 + 300;
    for (i = 0; i < 3; i++) {
        min[i] = arg1[i] * arg2 - 150;
        max[i] = min[i] + scale;
    }
    return func_800E3D0C(min, max);
}

s32 func_800D3104(BtIntPtr arg0, s32 *arg1) {
    int func_800BCC58(void);
    void func_800BD64C(s32 *, f32 *);
    s32 func_800BDC5C(void);
    void func_800E3958(BtIntPtr);
    void func_800E3980(f32 *);
    f32 func_800E42C0(void);
    s32 func_800E9DCC(s16 *);
    void func_800EB5E0(BtIntPtr, BtIntPtr);
    void func_800EB800(void);
    void func_800EFA88(void *, s32, s32, s32);
    void func_800EFB58(void *, void *, void *);
    void func_800EFD3C(s32 *);
    s32 func_800F0E28(s32, s32);
    f32 mlAbsF(f32);
    f32 pos[3];
    f32 dir[3];
    s32 axis;
    s32 center[3];
    s32 min[3];
    s32 max[3];
    f32 largest;
    register f32 value;
    BtIntPtr cell;
    s32 size;
    s32 x, y, z;
    s32 coord[3];

    func_800EB800();
    func_800E3980(pos);
    func_800E3958((BtIntPtr)dir);
    func_800BD64C(center, pos);
    func_800EFB58(center, center, arg1 + 1);
    func_800EFD3C(min);
    func_800EFA88(max, arg1[10] - 1, arg1[11] - 1, arg1[12] - 1);
    if (!func_800BCC58()) {
        axis = 0;
        largest = mlAbsF(dir[0]);
        value = mlAbsF(dir[1]);
        if (largest < value) {
            largest = value;
            axis = 1;
        }
        if (largest < mlAbsF(dir[2])) {
            axis = 2;
        }
        if (dir[axis] < 0.0f) {
            max[axis] = center[axis];
        } else {
            cell = (BtIntPtr)((f32 *)(&dir + 1) - 2);
            if ((f32 *)cell == &dir[axis]) {
                min[axis] = func_800F0E28(0, center[axis] - 1);
            } else {
                min[axis] = center[axis];
            }
        }
    }
    for (axis = 0; axis != 3; axis++) {
        if (func_800E42C0() * 4.0f < (f32)(center[axis] - min[axis])) {
            min[axis] = (s32)((f32)center[axis] - func_800E42C0() * 4.0f);
        }
        if (func_800E42C0() * 4.0f < (f32)(max[axis] - center[axis])) {
            max[axis] = (s32)((f32)center[axis] + func_800E42C0() * 4.0f);
        }
    }
    func_800EB5E0((BtIntPtr)(arg1 + 13), arg0);
    size = func_800BDC5C();
    for (x = min[0]; x <= max[0]; x++) {
        for (y = min[1]; y <= max[1]; y++) {
            for (z = min[2]; z <= max[2]; z++) {
                cell = arg1[0] + x * 8 + y * arg1[7] * 8 + arg1[8] * z * 8;
                coord[0] = arg1[1] + x;
                coord[1] = arg1[2] + y;
                coord[2] = arg1[3] + z;
                if (func_800E9DCC((s16 *)cell) && func_800D2F44(cell, coord, size, pos)) {
                    func_800EB5E0(cell, arg0);
                }
            }
        }
    } BT_NATIVE_ONLY(return 0;)
}
