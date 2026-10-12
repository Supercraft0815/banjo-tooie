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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/item/func_80800224_subaddieitem.s")
