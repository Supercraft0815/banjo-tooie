#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinkle/idtwinkle_entrypoint_0.s")

void idtwinkle_entrypoint_1(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    if ((*(s16 *)((s8 *)(arg3) + (0x26))) == (*(s16 *)((s8 *)(arg3) + (0x24)))) {
        (*(s16 *)((s8 *)(arg3) + (0xE))) = (s16) (*(s16 *)((s8 *)(arg1) + (0)));
        (*(s16 *)((s8 *)(arg3) + (0x10))) = (s16) (*(s16 *)((s8 *)(arg1) + (2)));
        (*(s16 *)((s8 *)(arg3) + (0x12))) = (s16) (*(s16 *)((s8 *)(arg1) + (4)));
    }
    (*(s16 *)((s8 *)(arg3) + (0x24))) = (s16) ((*(s16 *)((s8 *)(arg3) + (0x24))) + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinkle/idtwinkle_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinkle/func_80800478_idtwinkle.s")

/* extern */

void idtwinkle_entrypoint_3(void *arg0) {
    s32 heap_free(s32);
    heap_free((*(s32 *)((s8 *)(arg0) + (0x2C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinkle/idtwinkle_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinkle/idtwinkle_entrypoint_5.s")

void idtwinkle_entrypoint_6(u8 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = *(s32 *)(arg0 + 0x2C);
    *arg2 = (*(s16 *)(arg0 + 0x28) << 4) + *(s32 *)(arg0 + 0x2C);
}
