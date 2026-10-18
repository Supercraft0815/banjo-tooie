#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/tr/angler/func_80800000_trangler.s")

void trangler_entrypoint_0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct state {
        s32 *actor;
        s32 data[3];
        s8 value;
        u8 pad[3];
        s32 *start;
        s32 *end;
        s32 entries[1];
    };
    void *func_8010E810(void);
    int func_800DF8D4(s32 *);
    void func_80800000_trangler(s32 *, s32, s32, s32);
    void func_800C87B8(s32 *);
    s32 func_800DF8B4(s32 *);
    s32 func_800DF8CC(s32 *);
    s32 func_800DF8BC(s32 *);
    void func_8010EBE4(s32, s32, s32);
    struct state *state;
    s32 third;
    s32 second;
    s32 first;

    state = func_8010E810();
    state->actor = arg0;
    state->value = func_800DF8D4(arg0);
    state->start = state->entries;
    func_80800000_trangler(arg0, (arg1 >> 16) & 0xFFFF, arg1 & 0xFFFF, arg3);
    func_800C87B8(state->data);
    first = func_800DF8B4(arg0);
    second = func_800DF8CC(arg0);
    third = func_800DF8BC(arg0);
    func_8010EBE4(first, second, third);
}
