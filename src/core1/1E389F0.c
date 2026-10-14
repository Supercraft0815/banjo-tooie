#include "common.h"

void func_80020EC0(ALHeap *hp, u8 *base, s32 len) {
    hp->base = base;
    hp->len = len;
    hp->cur = hp->base;
    hp->count = 0;
}

s32 func_80020EE4(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4) {
    s32 sp4;
    s32 sp0;

    sp0 = 0;
    sp4 = ((arg3 * arg4) + 0xF) & ~0xF;
    if ((u32) ((*(s32 *)((s8 *)(arg2) + (4))) + sp4) <= (u32) ((*(s32 *)((s8 *)(arg2) + (8))) + (*(s32 *)((s8 *)(arg2) + (0))))) {
        sp0 = (*(s32 *)((s8 *)(arg2) + (4)));
        (*(s32 *)((s8 *)(arg2) + (4))) = (s32) ((*(s32 *)((s8 *)(arg2) + (4))) + sp4);
    } else {
    }
    return sp0;
}
