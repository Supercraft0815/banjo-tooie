#include "common.h"

s32 func_808000C4_chfantasydrillfield(void *, s32);
s32 func_80800360_chfantasydrillfield(void);
s32 func_808003C8_chfantasydrillfield(u32);
static Prop props[8];
static const s32 unsorted[] = {65, 20, 12, 48, 41, 22, 10, 16};
static const s32 ids[] = {10, 12, 16, 20, 22, 41, 48, 65};
static const s32 order[] = {6, 2, 7, 4, 0, 3, 1, 5};
static s32 flags[0xA10], clearCount, seed = 123, picks, seedsWritten;

s32 _gccubesearch_entrypoint_9(s32 actor, Prop **out, s32 count) {
    if (actor != 0x40A || count != 8) return 0;
    for (s32 i = 0; i < count; ++i) {
        props[i].unk10 = (unsorted[i] << 5) | 0x1F;
        out[i] = &props[i];
    }
    return count;
}
s32 func_800DA298(s32 flag) { return flags[flag]; }
void func_800DA3B8(s32 flag, s32 value) { flags[flag] = value; }
void func_800DA544(GameFlag flag) { flags[flag] = 1; }
void func_800DA524(GameFlag flag) {
    if (flag == 0xA0F) ++clearCount;
    flags[flag] = 0;
}
s32 func_800DC090(void) { return seed; }
void func_800DC324(s32 value) { seed = value; }
s32 func_800DC128(s32 low, s32 high) {
    if (high == 16) { ++seedsWritten; return 9; }
    if (low || high != 8 || seed != 9) return 0;
    return order[picks++ % 8];
}

int probe(void) {
    for (s32 run = 1; run <= 2; ++run) {
        flags[0xA0F] = 1;
        if (!func_808000C4_chfantasydrillfield(NULL, 0) || seed != 123) return 1;
        if (!func_80800360_chfantasydrillfield() || seedsWritten != 1) return 2;
        if (picks != run * 8 || func_808003C8_chfantasydrillfield(900) || !flags[0xA0F]) return 3;
        for (s32 i = 0; i < 8; ++i) {
            if (func_808003C8_chfantasydrillfield(ids[order[i]]) != i) return 4;
            if (flags[0xA0F] != (i != 7)) return 5;
        }
        if (clearCount != run) return 6;
    }
    return 0;
}
#ifndef BT_ILP32
#include <stdio.h>
int main(void) {
    int failure = probe();
    if (failure) fprintf(stderr, "drill field check %d failed\n", failure);
    return failure;
}
#endif
