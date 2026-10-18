#include "common.h"

/* extern */

void func_80800000_sueggmove(Actor *arg0, f32 *arg1, f32 *arg2) {
    f32 func_800D8FF8(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    f32 *velocity;
    f32 sp20[3];
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_800D8FF8();
    velocity = (f32 *)&arg0->actorData[4];
    velocity[1] += ((f32 *)arg0->actorData)[7] * temp_f0;
    temp_f2 = arg0->unk54 * temp_f0;
    if (velocity[1] < temp_f2) {
        velocity[1] = temp_f2;
    }
    func_800EFA20(sp20, velocity, temp_f0);
    func_800EE780(arg2, arg1, sp20);
}

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

void func_8080012C_sueggmove(Actor *arg0) {
    f32 func_800136E4(f32);
    void func_800EA600(s32, s32);
    void func_800EA614(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800F059C(f32 *, f32 *, f32 *);
    f32 func_800F0E00(f32, f32);
    void func_800F1988(f32 *, f32 *, f32 *);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    void *func_80100094(Actor *, u32);
    extern s32 _sueggmove_entrypoint_0;
    u8 *state;
    f32 sp40[3];
    f32 sp34[3];
    void *sp30;

    state = func_80100094(arg0, 0U);
    state[0xC] = 0;
    func_80800000_sueggmove(arg0, arg0->position, sp34);
    func_800EA600((s32)&_sueggmove_entrypoint_0, (s32)arg0->unk0);
    sp30 = func_800FAB50(arg0->position, sp34, sp40, 0x024200A0, 15.0f);
    func_800EA614();
    if (sp30 != NULL) {
        if (state[0xE] == 0) {
            func_800EFD24((f32 *)&arg0->actorData[4]);
            func_800F1988(sp40, arg0->rotation, &arg0->rotation[1]);
            arg0->rotation[0] = func_800136E4(arg0->rotation[0] - 90.0f);
        } else {
            func_800F059C((f32 *)&arg0->actorData[4], (f32 *)&arg0->actorData[4], sp40);
            ((f32 *)arg0->actorData)[5] = func_800F0E00(((f32 *)arg0->actorData)[5], 250.0f);
            func_80800108_sueggmove(state);
        }
        ((s32 *)state)[0xD] = ((s32 *)sp30)[2];
    }
    func_800EE7F8(arg0->position, sp34);
    ((f32 *)state)[4] = -9000.0f;
}

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
    void func_800EE7F8();
    func_800EE7F8(arg0 + 0x28);
}

void sueggmove_entrypoint_8(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0xF))) = (s8) arg1;
}

void sueggmove_entrypoint_9(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    u8 *data;
    f32 position[3];

    data = func_80100094(arg0, 0);
    if (data[0xD] != 0) {
        data[0xD]--;
    }
    func_800EE7F8(position, arg0->position);
    if (data[0xF] == 1) {
        func_8080012C_sueggmove(arg0);
    }
    func_800EFB24(arg0->actorData, arg0->position, position);
}

/* extern */

void sueggmove_entrypoint_10(f32 *arg0, f32 *arg1) { void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32); f32 sp24[3]; func_800FAB50(arg0, arg1, sp24, 0x024200A0, 15.0f); }
