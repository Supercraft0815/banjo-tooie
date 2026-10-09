#include "core2/1E77A20.h"

s32 func_8009E130() 
{
    return 0xF4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E154.s")

void func_8009E388(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E4AC.s")

void func_8009E4E0(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + (arg1 * 0x28))) + (8))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E4FC.s")

void func_8009E53C(PlayerState *arg0, s32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x114))) + (arg1 * 0x28))) + (0x18))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E55C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E6C4.s")

s16 func_8009E6EC(PlayerState *self) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E71C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E74C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E77C.s")

void func_8009E7AC(void *arg0) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x120)))) + (0))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x120)))) + (4))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x120)))) + (8))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E7C8.s")

void func_8009E830(PlayerState *arg0, s32 arg1) {
    (*(s16 **)((u8 *)arg0 + 0x120))[7] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E77A20/func_8009E83C.s")
