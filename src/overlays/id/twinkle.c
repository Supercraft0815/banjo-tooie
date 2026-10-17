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

void func_80800478_idtwinkle(void *arg0, s32 arg1, s32 arg2) {
    s32 _glid_entrypoint_2(s32, s32, s32 *, void *);
    s32 func_800DC214(s32, s32);
    f32 func_800DC264(f32, f32);
    extern s32 _idtwinkle_entrypoint_0;
    extern s32 _idtwinkle_entrypoint_1;
    s32 temp;
    s32 offset;
    s32 i;

    *(s16 *)((u8 *)arg0 + 0x26) = func_800DC214(0, *(s16 *)((u8 *)arg0 + 0xC));
    *(s16 *)((u8 *)arg0 + 0x24) = 0;
    _glid_entrypoint_2(arg1, arg2, &_idtwinkle_entrypoint_1, arg0);
    temp = func_800DC214(*(s16 *)((u8 *)arg0 + 0x18), *(s16 *)((u8 *)arg0 + 0x1A));
    *(s32 *)((u8 *)arg0 + 0x14) = temp * temp;
    *(s16 *)((u8 *)arg0 + 0x28) = 0;
    _glid_entrypoint_2(arg1, arg2, &_idtwinkle_entrypoint_0, arg0);
    i = 0;
    offset = 0;
    while (i < *(s16 *)((u8 *)arg0 + 0x28)) {
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0x2C) + offset) = 0.0f;
        *(*(u8 **)((u8 *)arg0 + 0x2C) + offset + 0xF) = 0xA;
        *(*(u8 **)((u8 *)arg0 + 0x2C) + offset + 0xE) = 0;
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0x2C) + offset + 4) = func_800DC264(0.0f, 1.0f);
        i++;
        offset += 0x10;
    }
}

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
