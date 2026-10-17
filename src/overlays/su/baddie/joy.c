#include "common.h"

/* extern */

s32 subaddiejoy_entrypoint_0(void *arg0, s32 arg1) {
    f32 func_800136E4(f32);
    s32 func_80016A74(u32, s32);
    f32 func_800E3A80(void);
    s32 var_v1;

    var_v1 = func_80016A74((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E, 0);
    if (var_v1 == -1) {
        var_v1 = arg1;
    } else {
        var_v1 = (s32) func_800E3A80() + var_v1 + 0x5A;
    }
    return (s32) func_800136E4((f32) var_v1);
}

/* extern */

s32 subaddiejoy_entrypoint_1(void *arg0) {
    void func_80015F28(s32, void *);
    s32 sp1C[3];

    func_80015F28((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E, sp1C);
    return sp1C[0] == 1;
}

/* extern */

s32 subaddiejoy_entrypoint_2(void *arg0, s32 arg1, s32 arg2) {
    f32 func_800136E4(f32);
    s32 func_80016A74(u32, s32);
    f32 func_800E3A80(void);
    s32 var_v1;

    var_v1 = func_80016A74((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E, arg2);
    if (var_v1 == -1) {
        var_v1 = arg1;
    } else {
        var_v1 = (s32) func_800E3A80() + var_v1 + 0x5A;
    }
    return (s32) func_800136E4((f32) var_v1);
}

f32 subaddiejoy_entrypoint_3(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013B70(f32, f32, f32);
    void func_80016068(u32, f32 *);
    f32 func_800E3A80(void);
    f32 func_800F13F0(f32, f32);
    f32 sqrtf(f32);
    struct { f32 x; f32 y; } stick;
    f32 y;
    f32 length;
    f32 angle;

    func_80016068((u32) ((*(s32 *)((s8 *)arg0 + 0x64)) * 8) >> 30, &stick.x);
    y = stick.y;
    length = sqrtf(y * y + stick.x * stick.x);
    if (length != 0.0f) {
        angle = func_80013B70(stick.y, stick.x, length);
        *(f32 *)((s8 *)arg0 + 0x54) = func_800136E4(func_800E3A80() + angle + 90.0f);
        length = func_800F13F0(1.0f, length);
    }
    return length;
}

int subaddiejoy_entrypoint_4(void *arg0) {
    void func_80015F28(s32, void *);
    void func_80015E80(s32, void *);
    s32 side[3];
    s32 face[6];

    func_80015F28((u32) ((*(s32 *)((s8 *)arg0 + 0x64)) * 8) >> 30, side);
    if (side[0] != 0) {
        return 1;
    }
    func_80015E80((u32) ((*(s32 *)((s8 *)arg0 + 0x64)) * 8) >> 30, face);
    if ((face[0] != 0) || (face[1] != 0)) {
        return 1;
    }
    return 0;
}

int subaddiejoy_entrypoint_5(void *arg0) {
    void func_80015F28(s32, void *);
    void func_80015E80(s32, void *);
    s32 side[3];
    s32 face[6];

    func_80015F28((u32) ((*(s32 *)((s8 *)arg0 + 0x64)) * 8) >> 30, side);
    if (side[0] == 1) {
        return 1;
    }
    func_80015E80((u32) ((*(s32 *)((s8 *)arg0 + 0x64)) * 8) >> 30, face);
    if ((face[0] == 1) || (face[1] == 1)) {
        return 1;
    }
    return 0;
}

/* extern */

void subaddiejoy_entrypoint_6(void *arg0) {
    s32 func_80016B30(u32);
    func_80016B30((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E);
}

/* extern */

void subaddiejoy_entrypoint_7(void *arg0) {
    s32 func_80016B54(u32);
    func_80016B54((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E);
}

/* extern */

void subaddiejoy_entrypoint_8(void *arg0, f32 *arg1) {
    void func_80016068(u32, f32 *);
    func_80016068((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E, arg1);
}

f32 subaddiejoy_entrypoint_9(void *arg0, f32 *arg1, s32 arg2) {
    f32 func_800136E4(f32);
    f32 func_80013B70(f32, f32, f32);
    void func_80016068(u32, f32 *);
    f32 func_800E3A80(void);
    f32 func_800F13F0(f32, f32);
    f32 sqrtf(f32);
    f32 stick[2];
    f32 magnitude;

    func_80016068((u32) ((*(s32 *)((s8 *)arg0 + 0x64)) * 8) >> 30, stick);
    magnitude = sqrtf(stick[0] * stick[0] + stick[1] * stick[1]);
    if (magnitude != 0.0f) {
        f32 angle;
        angle = func_800136E4(func_80013B70(stick[1], stick[0], magnitude) + func_800E3A80() + 90.0f);
        magnitude = func_800F13F0(1.0f, magnitude);
        if (arg2 & 1) {
            *arg1 = angle;
        }
    } else if (arg2 & 2) {
        *arg1 = *(f32 *)((s8 *)arg0 + 0x48);
    }
    return magnitude;
}

void subaddiejoy_entrypoint_10(u8 *arg0, f32 arg1, f32 arg2) {
    void func_80018820(s32, f32, f32);
    union {
        s32 word;
        struct {
            u32 unused : 2;
            u32 enabled : 1;
            u32 controller : 2;
            u32 remaining : 27;
        } bits;
    } flags;

    flags.word = *(s32 *)(arg0 + 0x64);
    if (flags.bits.enabled) {
        func_80018820(flags.bits.controller, arg1, arg2);
    }
}
