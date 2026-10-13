#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/func_80800000_sueggmove.s")

/* extern */

void sueggmove_entrypoint_0(s32 arg0, volatile s32 arg1) {
    void *func_80106790(s32);
    (*(s32 *)((s8 *)(func_80106790(*(s32 *)&arg1)) + (0x3C))) = arg0;
}

/* extern */

s32 sueggmove_entrypoint_1(void) {
    void *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x3C)));
}

s32 sueggmove_entrypoint_2(void) {
    void* func_80100094(Actor*, u32);
    void *func_80106790();
    return (*(s32 *)((s8 *)(func_80100094(func_80106790(), 0U)) + (0x34)));
}

void func_80800108_sueggmove(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (0xD))) == 0) {
        (*(s8 *)((s8 *)(arg0) + (0xC))) = 1;
        (*(u8 *)((s8 *)(arg0) + (0xD))) = 8U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/func_8080012C_sueggmove.s")

u8 sueggmove_entrypoint_3(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0xC)));
}

void sueggmove_entrypoint_4(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EFD24(f32 *);
    void sueggmove_entrypoint_8(Actor *, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    arg0->unk54 = 0.0f;
    ((f32 *)arg0->actorData)[7] = 0.0f;
    func_800EFD24((f32 *)arg0->actorData);
    sp1C[0xC] = 0;
    sp1C[0xE] = 0;
    sp1C[0xF] = 0;
    sp1C[0xD] = 0;
    sueggmove_entrypoint_8(arg0, 1);
}

void sueggmove_entrypoint_5(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0xE))) = (s8) arg1;
}

void sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x34))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = arg2;
}

/* extern */

void sueggmove_entrypoint_7(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x28);
}

void sueggmove_entrypoint_8(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0xF))) = (s8) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_9.s")

/* extern */

void sueggmove_entrypoint_10(f32 *arg0, f32 *arg1) { void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32); f32 sp24[3]; func_800FAB50(arg0, arg1, sp24, 0x024200A0, 15.0f); }
