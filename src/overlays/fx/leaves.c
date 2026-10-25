#include "common.h"

void func_80800000_fxleaves(void *arg0) {
    void func_8008FE68(f32 *);
    void func_800E3958(f32 *);
    void func_800E3A58(f32 *);
    s32 func_800E3F8C(f32, f32, f32);
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    void *vector_push_back(void **);
    s32 vector_size(s32);
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 distance;
    f32 x;
    f32 *sp50;
    f32 sp44[3];
    f32 y;
    s32 i;

    if (vector_size(*(s32 *)((u8 *)arg0 + 0x1C)) < *(s16 *)((u8 *)arg0 + 0x20)) {
        func_8008FE68(sp74);
        func_800E3958(sp68);
        func_800E3A58(sp5C);
        sp50 = vector_push_back((void **)((u8 *)arg0 + 0x1C));
        distance = func_800DC178(50.0f, 1200.0f);
        func_800EFA4C(sp44, 0.0f, func_800DC178(200.0f, 500.0f), -distance);
        if (func_800EEFD4((f32 *)((u8 *)arg0 + 0xC)) < 25.0f) {
            func_800EF934(sp44, sp44, func_800DC178(0.0f, 360.0f));
        } else {
            func_800EF934(sp44, sp44, sp5C[1] + func_800DC178(-70.0f, 70.0f));
        }
        func_800EE780(sp44, sp74, sp44);
        if (distance < 600.0f) {
            for (i = 0; i < 10 && func_800E3F8C(sp44[0], sp44[1] - 10.0f, sp44[2]); i++) {
                sp44[1] += 100.0f;
            }
        }
        func_800EE7F8(sp50 + 1, sp44);
        func_800EFA4C(sp50 + 4, 0.0f, -100.0f, 0.0f);
        func_800EFD24(sp50 + 7);
        x = func_800DC178(-300.0f, 300.0f);
        y = func_800DC178(-300.0f, 300.0f);
        func_800EFA4C(sp50 + 10, x, y, func_800DC178(-300.0f, 300.0f));
        if (++*((u8 *)arg0 + 0x34) >= 4) {
            *((u8 *)arg0 + 0x34) = 0;
        }
        *(s32 *)sp50 = ((s32 *)((u8 *)arg0 + 0x24))[*((u8 *)arg0 + 0x34)];
    }
}

void func_80800288_fxleaves(s8 *arg0, s32 arg1) {
    arg0[34] = arg1;
}

/* extern */

void fxleaves_entrypoint_0(void *arg0) {
    s32 vector_clear(s32);
    vector_clear((*(s32 *)((s8 *)(arg0) + (0x1C))));
}

void fxleaves_entrypoint_1(void *arg0) {
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    s32 func_800DF350(void);
    void func_800DF830(s32);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    u32 sp34;
    u32 temp_v0;
    u32 var_s0;

    sp34 = vector_begin(*(s32 *)((s8 *)arg0 + 0x1C));
    temp_v0 = vector_end(*(s32 *)((s8 *)arg0 + 0x1C));
    var_s0 = sp34;
    if (var_s0 < temp_v0) {
        do {
            func_800DF830(2);
            func_800DE448((f32 *)(var_s0 + 4), (f32 *)(var_s0 + 0x1C), 1.0f, NULL, func_800D674C(*(s32 *)var_s0));
            *(s8 *)(var_s0 + 0x34) = func_800DF350();
            var_s0 += 0x38;
        } while (var_s0 < temp_v0);
    }
}

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
