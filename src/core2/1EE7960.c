#include "common.h"

extern s32 D_80137074;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E070.s")

void func_8010E204(void *arg0, s32 arg1, f32 arg2) {
    void func_80019224(f32 *, f32 *);
    void func_800B237C(void *, f32 *, f32 *);
    void func_800B3494(s32, f32 *, f32);
    void func_800B3748(s32);
    void func_800B388C(u8 *, s32);
    void func_800B38C8(s32);
    s32 func_800DF8B4(s32 *);
    f32 func_800DF8C4(f32 *);
    extern s32 D_80137074;
    f32 sp24[3];
    f32 sp20;
    f32 sp1C;
    func_800B388C(D_80137074, arg1 < 0 ? -arg1 : arg1);
    func_800B237C(func_800DF8B4(arg0), sp24, &sp20);
    sp1C = func_800DF8C4(arg0);
    func_80019224(sp24, sp24);
    sp20 *= sp1C;
    func_800B3494(D_80137074, sp24, sp20);
    if (arg1 < 0) {
        func_800B3748(D_80137074);
    }
    func_800B38C8(D_80137074);
}

void func_8010E2C4(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 func_800B37E4(s32, s32);
    int func_800DF8D4(s32 *);
    s32 func_8010E070();
    extern s32 D_80137060;
    (*(s32 **)((s8 *)(&D_80137060) + (0))) = arg0;
    (*(s8 *)((s8 *)(&D_80137060) + (0x10))) = func_800DF8D4(arg0);
    if (arg2 != 0) {
        func_800B37E4((*(s32 *)((s8 *)(&D_80137060) + (0x14))), arg2);
    } else {
        func_8010E204(arg0, arg1, arg3);
    }
    func_8010E070();
}

/* extern */

void func_8010E334(void) {
    s32 func_800B3310(s32);
    D_80137074 = func_800B3310(0x4);
}

/* extern */

void func_8010E358(void) {
    s32 func_800B38E8(s32);
    if (D_80137074 != 0) {
        D_80137074 = func_800B38E8(D_80137074);
    }
}

void func_8010E390(void) {
    s32 func_800B3370(s32);
    extern s32 D_80137074;
    func_800B3370(D_80137074);
    D_80137074 = 0;
}

s32 func_8010E3B8()
{
    return D_80137074;
}

void func_8010E3C4(f32 *arg0, s32 *arg1, f32 *arg2) {
    s32 i;
    f32 length;
    f32 vec[3];

    for (i = 0; i < 3; i++) {
        vec[i] = (arg2[0] * arg0[i * 4] + arg2[1] * arg0[i * 4 + 1]) + arg2[2] * arg0[i * 4 + 2];
    }
    length = sqrtf((vec[0] * vec[0] + vec[1] * vec[1]) + vec[2] * vec[2]);
    if (length > 0.0f) {
        length = 256.0f / length;
        arg1[0] = (s32)(vec[0] * length);
        arg1[1] = (s32)(vec[1] * length);
        arg1[2] = (s32)(vec[2] * length);
    } else {
        arg1[2] = 0;
        arg1[1] = 0;
        arg1[0] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7960/func_8010E4C4.s")

void func_8010E7F4(void) {
    extern s32 D_80137060;
    (*(s32 *)((s8 *)(&D_80137060) + (0))) = 0;
    (*(s32 *)((s8 *)(&D_80137060) + (0x18))) = 0;
    (*(s32 *)((s8 *)(&D_80137060) + (0x1C))) = 0;
}
