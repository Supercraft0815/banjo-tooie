#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/scroll/vpscroll_entrypoint_0.s")

void vpscroll_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/scroll/vpscroll_entrypoint_2.s")

void vpscroll_entrypoint_3(s16 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    s16 offset = arg0[2];
    u8 *end = arg2 + (arg3 << 4);
    if (arg2 < end) {
        do {
        *(s16 *)(arg2 + 10) += offset;
        arg2 += 16;
        } while (arg2 < end);
    }
}
