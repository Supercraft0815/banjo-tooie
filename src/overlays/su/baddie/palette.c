#include "common.h"

/* extern */

void subaddiepalette_entrypoint_0(Actor *arg0, u8 *arg1, u16 arg2) {
    void *func_800D674C(s32);
    s32 func_800D6CEC(s32);
    s32 func_801032B0(Actor *, u16, u16);
    void rare_memcpy(void *, void *, int);
    void subaddiepalette_entrypoint_4(void *, void *);
    rare_memcpy(arg1 + 0x10, func_800D674C(arg2), 0x800);
    func_800D6CEC(arg2);
    (*(u16 *)(arg1 + 0)) = arg2;
    (*(s16 *)(arg1 + 4)) = 0;
    subaddiepalette_entrypoint_4(arg0, arg1);
    func_801032B0(arg0, arg0->unk0->unk14, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/palette/subaddiepalette_entrypoint_1.s")

s32 subaddiepalette_entrypoint_2(void **arg0, void *arg1, u16 arg2, f32 arg3) {
    u16 old;
    old = *(u16 *)arg1;
    if (old == arg2) return 0;
    *(s16 *)((s8 *)arg1 + 4) = 1;
    *(f32 *)((s8 *)arg1 + 12) = arg3;
    *(f32 *)((s8 *)arg1 + 8) = arg3;
    *(u16 *)((s8 *)arg1 + 2) = old;
    *(u16 *)arg1 = arg2;
    *(u16 *)((s8 *)*arg0 + 22) = arg2;
    return 1;
}

/* extern */

void subaddiepalette_entrypoint_3(Actor *arg0, u8 *arg1, s32 arg2) {
    typedef struct VertexListView VertexListView;
    void func_800B25D8(VertexListView *, VertexListView *, s32);
    s32 func_800B2840(s32);
    void func_800DF720(s32);
    s32 func_80100AC4(s16);
    void func_80100F0C(s16, u8 *);
    s32 func_80103C94(Actor *);
    s32 pad[2];
    s32 sp24;
    s16 temp_a0;
    s16 var_v0;
    u8 *temp_s0;

    var_v0 = *(s16 *)(arg1 + 6);
    temp_s0 = arg1;
    if (var_v0 != 0) {
        temp_a0 = *(s16 *)&arg0->pad60;
        if (temp_a0 != 0 && arg0->pad7A_7 != 0) {
            func_80100F0C(temp_a0, arg1 + 0x10);
            func_800DF720(func_80100AC4(*(s16 *)&arg0->pad60));
        } else {
            sp24 = func_80103C94(arg0);
            func_800B25D8(sp24, func_800B2840(arg2), temp_s0 + 0x10);
        }
        var_v0 = *(s16 *)(temp_s0 + 6);
    }
    if (var_v0 != 0) {
        *(s16 *)(temp_s0 + 6) = var_v0 - 1;
    }
}

void subaddiepalette_entrypoint_4(void *arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (6))) = 1;
    if ((((*(s16 *)((s8 *)(arg0) + (0x60))) == 0) || ((((u32) (*(u8 *)((s8 *)(arg0) + (0x7B)))) >> 6) == 0)) && ((*(u8 *)((s8 *)(arg0) + (0x70))) & 1)) {
        (*(s16 *)((s8 *)(arg1) + (6))) = (s16) ((*(s16 *)((s8 *)(arg1) + (6))) + 1);
    }
}
