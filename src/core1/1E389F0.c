#include "common.h"

void func_80020EC0(ALHeap *hp, u8 *base, s32 len) {
    hp->base = base;
    hp->len = len;
    hp->cur = hp->base;
    hp->count = 0;
}

BtIntPtr func_80020EE4(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4) {
#ifdef BT_NATIVE
    ALHeap *heap = (ALHeap *)arg2;
    size_t bytes;
    if (arg3 < 0 || arg4 < 0 ||
        (arg4 != 0 && (size_t)arg3 > (SIZE_MAX - 0xF) / (size_t)arg4)) {
        return 0;
    }
    bytes = ((size_t)arg3 * (size_t)arg4 + 0xF) & ~(size_t)0xF;
    if (heap->cur < heap->base || heap->cur > heap->base + heap->len ||
        bytes > (size_t)((heap->base + heap->len) - heap->cur)) {
        return 0;
    }
    {
        u8 *result = heap->cur;
        heap->cur += bytes;
        return (BtIntPtr)result;
    }
#else
    s32 sp4;
    s32 sp0;

    sp0 = 0;
    sp4 = ((arg3 * arg4) + 0xF) & ~0xF;
    if ((u32) ((*(s32 *)((s8 *)(arg2) + (4))) + sp4) <= (u32) ((((ALHeap *)arg2)->len) + (*(s32 *)((s8 *)(arg2) + (0))))) {
        sp0 = (*(s32 *)((s8 *)(arg2) + (4)));
        (*(s32 *)((s8 *)(arg2) + (4))) = (s32) ((*(s32 *)((s8 *)(arg2) + (4))) + sp4);
    } else {
    }
    return sp0;
#endif
}
