#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/func_80800000_fxleaves.s")

void func_80800288_fxleaves(s8 *arg0, s32 arg1) {
    arg0[34] = arg1;
}

/* extern */

void fxleaves_entrypoint_0(void *arg0) {
    s32 vector_clear(s32);
    vector_clear((*(s32 *)((s8 *)(arg0) + (0x1C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_1.s")

/* extern */

int fxleaves_entrypoint_2(void *arg0) {
    s32 vector_size(s32);
    return *(u8 *)((s8 *)arg0 + 0x22) != 1 &&
        vector_size(*(s32 *)((s8 *)arg0 + 0x1C)) == 0;
}

/* extern */

void fxleaves_entrypoint_3(void *arg0) {
    s32 heap_free(void *);
    s32 vector_free(s32);
    vector_free((*(s32 *)((s8 *)(arg0) + (0x1C))));
    heap_free(arg0);
}

/* extern */

void *fxleaves_entrypoint_4(s32 arg0) {
    void *heap_alloc(s32);
    s32 vector_new(s32, s32);
    void *sp1C;
    void *temp_v0;

    temp_v0 = heap_alloc(0x3C);
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(f32 *)((s8 *)(temp_v0) + (8))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0x14))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = 0.0f;
    sp1C = temp_v0;
    (*(s32 *)((s8 *)(sp1C) + (0x1C))) = vector_new(0x38, arg0);
    (*(s16 *)((s8 *)(sp1C) + (0x20))) = (s16) arg0;
    (*(s8 *)((s8 *)(sp1C) + (0x22))) = 0;
    (*(s32 *)((s8 *)(sp1C) + (0x24))) = 0x9ED;
    (*(s32 *)((s8 *)(sp1C) + (0x28))) = 0x9EE;
    (*(s32 *)((s8 *)(sp1C) + (0x2C))) = 0x9EF;
    (*(s32 *)((s8 *)(sp1C) + (0x30))) = 0x9F0;
    (*(s8 *)((s8 *)(sp1C) + (0x34))) = 0;
    (*(f32 *)((s8 *)(sp1C) + (0x38))) = 0.1f;
    return sp1C;
}

void fxleaves_entrypoint_5(s32 arg0)
{
    func_80800288_fxleaves(arg0,1);
}

void fxleaves_entrypoint_6(s32 arg0)
{
    func_80800288_fxleaves(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_7.s")
