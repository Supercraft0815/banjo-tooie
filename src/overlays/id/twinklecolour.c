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

void func_80800574_idtwinklecolour(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _glid_entrypoint_2(s32, s32, s32 *, void *);
    s16 func_800DC214(s16, s16);
    extern s32 _idtwinklecolour_entrypoint_0;
    extern s32 _idtwinklecolour_entrypoint_1;
    s16 temp_v0;

    (*(s16 *)((s8 *)(arg0) + (0x1E))) = func_800DC214(0, (*(s16 *)((s8 *)(arg0) + (0xC))));
    (*(s16 *)((s8 *)(arg0) + (0x1C))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x20))) = (s16) arg3;
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_1, arg0);
    temp_v0 = func_800DC214((*(s16 *)((s8 *)(arg0) + (0x18))), (*(s16 *)((s8 *)(arg0) + (0x1A))));
    (*(s32 *)((s8 *)(arg0) + (0x14))) = (s32) (temp_v0 * temp_v0);
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_0, arg0);
}

/* extern */

void idtwinklecolour_entrypoint_3(void *arg0) {
    s32 heap_free(s32);
    heap_free((*(s32 *)((s8 *)(arg0) + (0x24))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_5.s")
