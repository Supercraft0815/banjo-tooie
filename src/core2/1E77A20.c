#include "core2/1E77A20.h"

s32 func_8009E130() 
{
    return 0xF4;
}

f32 func_8009E138(PlayerState *arg0, s32 arg1) {
    typedef struct { f32 value; u8 pad[0x24]; } Entry;
    return (*(Entry **)((u8 *)arg0 + 0x114))[arg1].value;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E154.s")

void func_8009E388(s32 arg0) 
{
}
/* extern */

void func_8009E390(PlayerState *arg0) {
    void func_800EFD24(f32 *);
    s32 var_s0;
    u8 *temp_v0;

    var_s0 = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x114)))) + (0xF0))) = 0;
    for (var_s0 = 0; var_s0 < 3; var_s0++) {
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x114))) + var_s0 * 0x28;
        (*(f32 *)((s8 *)(temp_v0) + (0))) = 0.0;
        (*(s16 *)((s8 *)(temp_v0) + (4))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (8))) = 0;
        (*(f32 *)((s8 *)(temp_v0) + (0x20))) = 0.0;
        (*(f32 *)((s8 *)(temp_v0) + (0x24))) = 0.0;
        (*(f32 *)((s8 *)(temp_v0) + (0x1C))) = 0.0;
        (*(f32 *)((s8 *)(temp_v0) + (0x18))) = 0.0;
        func_800EFD24((f32 *)(temp_v0 + 0xC));
    }
    func_8009E5A4(arg0, 0, 1);
    func_8009E5A4(arg0, 1, 2);
    func_8009E5A4(arg0, 2, 3);
    func_8009E55C(arg0, 0, 32.0f);
    func_8009E55C(arg0, 1, 28.0f);
    func_8009E55C(arg0, 2, 0.0f);
}

void func_8009E474(PlayerState *arg0) {
    s32 rare_memcpy(u8 *, u8 *, s32);
    u8 *temp_a0;

    temp_a0 = (*(u8 **)((s8 *)(arg0) + (0x114)));
    rare_memcpy(temp_a0, temp_a0 + 0x78, 0x78);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x114)))) + (0xF0))) = 0;
}

/* extern */

void func_8009E4AC(PlayerState *arg0) {
    s32 rare_memcpy(u8 *, u8 *, s32);
    u8 *temp_a1;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x114)))) + (0xF0))) = 1;
    temp_a1 = (*(u8 **)((s8 *)(arg0) + (0x114)));
    rare_memcpy(temp_a1 + 0x78, temp_a1, 0x78);
}

void func_8009E4E0(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + (arg1 * 0x28))) + (8))) = arg2;
}

void func_8009E4FC(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 temp_v0;

    temp_v0 = arg1 * 0x28;
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + temp_v0)) + (0x20))) = arg2;
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + temp_v0)) + (0x24))) = arg3;
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + temp_v0)) + (0x1C))) = arg4;
}

void func_8009E53C(PlayerState *arg0, s32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + (arg1 * 0x28))) + (0x18))) = arg2;
}

void func_8009E55C(PlayerState *arg0, s32 arg1, f32 arg2) { (*(f32 *)((s8 *)(*(s32 *)((s8 *)(arg0) + (0x114)) + (arg1 * 0x28)))) = arg2; if (arg2 == 0.0f) { func_8009E4E0(arg0, arg1, 0); } }

void func_8009E5A4(PlayerState *arg0, s32 arg1, s32 arg2) {
    (*(s16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + (arg1 * 0x28))) + (4))) = (s16) arg2;
}

s32 func_8009E5C0() 
{
    return 0x14;
}


void (*func_8009CAAC(PlayerState *, BanjoStateId))(PlayerState *);
void (*func_8009CAF8(PlayerState *, BanjoStateId))(PlayerState *);

void bs_setState(PlayerState *self, BanjoStateId nextState) {
    if (nextState != BS_STATE_0_INVALID) {
        self->state->next = nextState;
        if (func_8009CAAC(self, self->state->current) != NULL) {
            func_8009CAAC(self, self->state->current)(self);
        }
        self->state->previous = self->state->current;
        self->state->current = self->state->next;
        self->state->next = NULL;
        if (func_8009CAF8(self, self->state->current) != NULL) {
            func_8009CAF8(self, self->state->current)(self);
        }
    }
}

s32 func_8009E674(PlayerState *arg0, s32 arg1) {
    s32 func_8009CA70(PlayerState *, s32, s32);
    return func_8009CA70(arg0, arg0->state->current, arg1);
}

s32 func_8009E69C(PlayerState *arg0, s32 arg1) {
    s32 func_8009CA70(PlayerState *, s32, s32);
    return func_8009CA70(arg0, arg0->state->next, arg1);
}

s32 func_8009E6C4(PlayerState *arg0, s32 arg1) {
    s32 func_8009CA70(PlayerState *, s32, s32);
    return func_8009CA70(arg0, arg0->state->previous, arg1);
}

s32 func_8009E6EC(PlayerState *self) {
    return self->state->unkC;
}

s32 bs_getCurrentState(PlayerState *self) {
    return self->state->current;
}

s32 bs_getNextState(PlayerState *self) {
    return self->state->next;
}

s32 bs_getPreviousState(PlayerState *self) {
    return self->state->previous;
}

/* extern */

s32 func_8009E71C(void *arg0, s32 arg1) {
    s32 func_8009CBDC(s32, s32);
    return func_8009CBDC(arg0, (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x120)))) + (4)))) == arg1;
}

s32 func_8009E74C(PlayerState *arg0, s32 arg1) {
    s32 func_8009CBDC(s32, s32);
    return func_8009CBDC((s32)arg0, arg0->state->next) == arg1;
}

s32 func_8009E77C(PlayerState *arg0, s32 arg1) {
    s32 func_8009CBDC(s32, s32);
    return func_8009CBDC((s32)arg0, arg0->state->previous) == arg1;
}

void func_8009E7AC(void *arg0) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x120)))) + (0))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x120)))) + (4))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x120)))) + (8))) = 0;
}

s32 func_8009E7C8(PlayerState *arg0, s32 arg1) {
    void (*func_8009CB44(PlayerState *, s32))(PlayerState *);

    (*(s16 **)((u8 *)arg0 + 0x120))[6] = arg1;
    (*(s16 **)((u8 *)arg0 + 0x120))[7] = 1;
    if (func_8009CB44(arg0, arg0->state->current) != NULL) {
        func_8009CB44(arg0, arg0->state->current)(arg0);
    }
    return (*(s16 **)((u8 *)arg0 + 0x120))[7];
}

void func_8009E830(PlayerState *arg0, s32 arg1) {
    (*(s16 **)((u8 *)arg0 + 0x120))[7] = arg1;
}

/* extern */

void func_8009E83C(PlayerState *arg0) {
    void (*func_8009CB90(PlayerState *, s32))(PlayerState *);
    void (*temp_v0)(PlayerState *);

    temp_v0 = func_8009CB90(arg0, (*(s32 *)((s8 *)arg0->state + 4)));
    if (temp_v0 != NULL) {
        temp_v0(arg0);
    }
}
