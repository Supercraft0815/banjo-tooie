#include "common.h"

void subaddieitem_entrypoint_0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _subaddielink_entrypoint_0(u8 *, u8 *);
    u8 *temp_a0;

    (*(s8 *)((s8 *)(arg0) + (0))) = 0;
    (*(s16 *)((s8 *)(arg0) + (4))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (6))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (1))) = arg3;
    (*(s8 *)((s8 *)(arg0) + (2))) = 0;
    (*(s8 *)((s8 *)(arg0) + (3))) = 0;
    temp_a0 = arg0 + 8;
    (*(f32 *)(temp_a0 + 8)) = 0.0f;
    _subaddielink_entrypoint_0(temp_a0, (u8 *) arg1);
}

void subaddieitem_entrypoint_1(s8 *arg0, s32 arg1) {
    arg0[2] = arg1;
}

/* extern */

void subaddieitem_entrypoint_2(u8 *arg0) {
    s32 _subaddielink_entrypoint_0(u8 *, u8 *);
    s32 func_80090658(s32, u8 *);
    func_80090658(1, arg0);
    (*(s8 *)((s8 *)(arg0) + (3))) = 1;
    (*(s8 *)((s8 *)(arg0) + (0))) = 1;
    (*(f32 *)((s8 *)(arg0) + (0x10))) = 0.0f;
    _subaddielink_entrypoint_0(arg0 + 8, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/item/subaddieitem_entrypoint_3.s")

void func_80800224_subaddieitem(Actor *arg0, u8 *arg1, Actor *arg2) {
    s32 _subaddielink_entrypoint_0();
    void func_800D175C(s32, s32);
    s32 func_800D1B34(s32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    s32 func_8010108C(Actor *, s32, s32);
    u32 flags;

    flags = arg1[1];
    if (flags & 2) {
        func_800FC660(0xE);
        flags = arg1[1];
    }
    if ((flags & 1) && arg2 != NULL) {
        func_800FFAB0(arg2);
    }
    _subaddielink_entrypoint_0(arg1 + 8);
    if (arg1[2] != 0) {
        func_800D175C(func_800D1B34(*(s16 *)(arg1 + 4)), -(s32)arg1[2]);
    }
    func_8010108C(arg0, 0x2D, *(s16 *)(arg1 + 4));
    arg1[0] = 3;
}
