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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/joy/subaddiejoy_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/joy/subaddiejoy_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/joy/subaddiejoy_entrypoint_5.s")

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

void subaddiejoy_entrypoint_8(void *arg0) {
    s32 func_80016068(u32);
    func_80016068((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/joy/subaddiejoy_entrypoint_9.s")

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
