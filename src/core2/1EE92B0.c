#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010F9C0.s")

s32 func_8010FAE4(s16 *arg0) {
    return arg0[11];
}

/* extern */

void func_8010FAEC(s32 arg0, void *arg1) {
    s32 func_800A9420(s32);
    s32 func_80114FA4(s32, s32, void *);
    if (((*(s32 *)((s8 *)(arg1) + (0xC))) != 0) && (func_800A9420((*(s32 *)((s8 *)(arg1) + (0x1C)))) != 0)) {
        func_80114FA4(arg0, (*(s32 *)((s8 *)(arg1) + (0xC))), arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010FB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010FBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010FC38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010FD08.s")

void func_8010FD38(s32 arg0, f32 arg1) {
    void func_80114CB0(void *arg0, f32 arg1);
    func_80114CB0((*(u8 **)((s8 *)(arg0) + (0x10))), arg1);
}

void func_8010FD60(s32 arg0, f32 arg1) {
    void func_80114CC0(void *arg0, f32 arg1);
    func_80114CC0((*(u8 **)((s8 *)(arg0) + (0x10))), arg1);
}

void func_8010FD88()
{
    func_8010FD08();
}

void func_8010FDA8(u8 *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    (*(s8 *)((s8 *)(arg0) + (0x20))) = 0x28;
    func_800EE7F8(arg0 + 0x24, arg1);
    func_800EE7F8(arg0 + 0x30, arg2);
}

void func_8010FDEC(void *arg0, f32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x20))) = 0x29;
    (*(f32 *)((s8 *)(arg0) + (0x3C))) = arg1;
}

void func_8010FE00(void *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg0) + (0x18))) = (s8) (arg2 == 2);
}

/* extern */

void func_8010FE14(s32 *arg0) {
    s32 func_800CA628(s32);
    func_800CA628(*arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_8010FE34.s")

s32 func_8010FF80(s32 *arg0) {
    return arg0[0];
}

/* extern */

void func_8010FF88(void *arg0) {
    void func_80114C9C();
    func_80114C9C((*(void **)((s8 *)(arg0) + (0x10))));
}

s32 func_8010FFA8(s16 *arg0) {
    return arg0[11];
}

/* extern */

void func_8010FFB0(s32 *arg0) {
    s32 func_800CA8B4(s32);
    func_800CA8B4(*arg0);
}

u32 func_8010FFD0(u8 *arg0) {
    return arg0[25];
}

/* extern */

s32 func_8010FFD8(s32 arg0) {
    u32 func_801150F0(u8 *);
    u8 *temp_a1;
    s32 var_v1;

    temp_a1 = (*(u8 **)((s8 *)(arg0) + (0xC)));
    if (temp_a1 != 0) {
        var_v1 = func_801150F0(temp_a1);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 func_80110014(s32 *arg0) {
    return arg0[1];
}

s32 func_8011001C(s32 *arg0) {
    return arg0[2];
}

s32 func_80110024(s16 *arg0) {
    s32 _ncpod_entrypoint_2(s16);
    s16 temp;
    s32 result;
    temp = arg0[10];
    result = 0;
    if (temp != 0) {
        return _ncpod_entrypoint_2(temp);
    }
    return result;
}

s32 func_80110060(s32 *arg0) {
    return arg0[4];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_80110068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE92B0/func_801100E4.s")

/* extern */

void func_80110164(u8 *arg0) {
    void func_800CA6C0(void *arg0, f32 arg1, f32 arg2);
    void func_80114C9C(void *arg0, f32 *arg1, f32 *arg2);
    s32 func_8011490C(s32, u8 *, s32);
    f32 sp1C;
    f32 sp18;

    func_8011490C((*(s32 *)((s8 *)(arg0) + (0x10))), arg0, (*(s32 *)((s8 *)(arg0) + (0x1C))));
    func_80114C9C((*(u8 **)((s8 *)(arg0) + (0x10))), &sp1C, &sp18);
    func_800CA6C0((*(u8 **)((s8 *)(arg0) + (0))), sp1C, sp18);
}
