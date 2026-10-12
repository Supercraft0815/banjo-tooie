#include "common.h"

void func_80020EC0(ALHeap *hp, u8 *base, s32 len) {
    hp->base = base;
    hp->len = len;
    hp->cur = hp->base;
    hp->count = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E389F0/func_80020EE4.s")
