#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_0.s")

void idtwinklecolour_entrypoint_1(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    if ((*(s16 *)((s8 *)(arg3) + (0x1E))) == (*(s16 *)((s8 *)(arg3) + (0x1C)))) {
        (*(s16 *)((s8 *)(arg3) + (0xE))) = (s16) (*(s16 *)((s8 *)(arg1) + (0)));
        (*(s16 *)((s8 *)(arg3) + (0x10))) = (s16) (*(s16 *)((s8 *)(arg1) + (2)));
        (*(s16 *)((s8 *)(arg3) + (0x12))) = (s16) (*(s16 *)((s8 *)(arg1) + (4)));
    }
    (*(s16 *)((s8 *)(arg3) + (0x1C))) = (s16) ((*(s16 *)((s8 *)(arg3) + (0x1C))) + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/func_80800574_idtwinklecolour.s")

/* extern */

void idtwinklecolour_entrypoint_3(void *arg0) {
    s32 heap_free(s32);
    heap_free((*(s32 *)((s8 *)(arg0) + (0x24))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_5.s")
