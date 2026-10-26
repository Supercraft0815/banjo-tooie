#include "common.h"

typedef struct {
    s16 id;
    u8 size;
    u8 pad;
    s32 value;
} EntryData;

EntryData D_8011B560[4] = {
    {0x0C21, 8, 0, 0},
    {0x0C22, 16, 0, 0},
    {0x0C20, 16, 0, 0},
    {0x0C23, 6, 0, 0}
};

/* extern */

s32 func_800D2F20(void) {
    s32 func_800BDC5C();
    return func_800BDC5C() * 4;
}

s32 func_800D2F44(s32 arg0, s32 *arg1, s32 arg2, f32 *arg3) {
    s32 func_800E3D0C(f32 *, f32 *);
    f32 func_800E42C0(void);
    extern f32 D_80125B00;
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
    radius = scale * 4.0f * (D_80125B00 * (f32)arg2);
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

s32 func_800D3104(s32 arg0, s32 *arg1) {
    int func_800BCC58(void);
    void func_800BD64C(s32 *, f32 *);
    s32 func_800BDC5C(void);
    void func_800E3958(s32);
    void func_800E3980(f32 *);
    f32 func_800E42C0(void);
    s32 func_800E9DCC(s16 *);
    void func_800EB5E0(s32, s32);
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
    s32 cell;
    s32 size;
    s32 x, y, z;
    s32 coord[3];

    func_800EB800();
    func_800E3980(pos);
    func_800E3958((s32)dir);
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
            cell = (s32)((f32 *)(&dir + 1) - 2);
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
    func_800EB5E0((s32)(arg1 + 13), arg0);
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
    }
}

void func_800D34A0(void) {
    s32 func_800E7188(u8 *);
    extern u8 D_8011B580[];
    extern s8 D_8012B370[];
    s32 temp_v0;
    s32 var_a1;
    int var_a0;

    temp_v0 = func_800E7188(D_8011B580);
    for (var_a1 = 0; var_a1 < 0x80; var_a1++) {
        for (var_a0 = 0; var_a0 < temp_v0; var_a0++) {
            if (var_a1 == D_8011B580[var_a0]) {
                D_8012B370[var_a1] = var_a0;
                break;
            }
        }
        if (var_a0 == temp_v0) {
            D_8012B370[var_a1] = -1;
        }
    }
}

s16 *func_800D3524(s32 arg0) {
    s32 func_800D674C(s32);

    if (D_8011B560[arg0].value == 0) {
        D_8011B560[arg0].value = func_800D674C(D_8011B560[arg0].id);
    }
    return (s16 *) D_8011B560[arg0].value;
}

int func_800D3574(s32 arg0) {
    extern f32 D_80125B10;
    return (s32) ((f32) (u32) D_8011B560[arg0].size * D_80125B10);
}

u8 func_800D35BC(s32 arg0) {
    return D_8011B560[arg0].size;
}

s32 func_800D35D0(s32 arg0, s32 arg1) {
    extern s8 D_8012B370[];
    s32 temp;

    if ((arg0 != 2) && (arg0 != 0) && (arg1 >= 0x61) && (arg1 < 0x7B)) {
        arg1 -= 0x20;
    }
    switch (arg0) {
        case 0:
            if ((arg1 >= 0x21) && (arg1 < 0x7B)) {
                return arg1 - 0x21;
            }
            break;
        case 1:
            if (arg1 < 0x80) {
                temp = D_8012B370[arg1];
                if (temp >= 0) {
                    return temp;
                }
            }
            break;
        case 2:
            if ((arg1 > 0) && (arg1 < 0xFD)) {
                return arg1;
            }
            break;
        case 3:
            if ((arg1 >= 0x30) && (arg1 < 0x3B)) {
                return arg1 - 0x30;
            }
            return 0xB;
    }
    return -1;
}

void func_800D36A8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_8011B560[i].value = 0;
    }
}

/* extern */

int func_800D36C4(s32 arg0, s32 arg1) {
    void *func_800B0D6C(void *, s32);
    s16 *func_800D3524(s32);
    s32 func_800D35D0(s32, s32);
    s32 pad;
    s32 sp18;
    s16 *temp_v0;

    sp18 = func_800D35D0(arg0, arg1);
    temp_v0 = func_800D3524(arg0);
    if ((sp18 < 0) || (temp_v0 == 0)) {
        return func_800D3574(arg0);
    }
    return (*(u8 *)((s8 *)(func_800B0D6C(temp_v0, sp18)) + (2)));
}

s32 func_800D3724(s32 arg0) {
    s32 func_800D6C34(s16);
    s32 var_v1;
    u8 *temp_v0;

    temp_v0 = (u8 *)D_8011B560 + arg0 * 8;
    if ((*(s32 *)((s8 *)temp_v0 + 4)) != 0) {
        var_v1 = func_800D6C34(*(s16 *)(temp_v0 + 0));
    } else {
        var_v1 = 1;
    }
    return var_v1;
}
