#include "common.h"

/* extern */

int func_800B46B0(void *arg0, s32 arg1, f32 arg2[3], f32 arg3[3]) {
    struct Bounds {
        u16 flags;
        u8 pad2[0xAA];
        s16 lower;
        s16 upper;
    };
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    f32 sp2C[3];
    s32 var_a3;
    f32 temp_f0;
    s16 temp_v0;

    if ((((struct Bounds *)arg0)->lower == -0x8000) && (((struct Bounds *)arg0)->upper == 0x7FFF)) {
        if (((struct Bounds *)arg0)->flags & 0x100) {
            var_a3 = 0x420021;
        } else {
            var_a3 = 0x400000;
        }
        return func_800BEF00(arg2, arg3, sp2C, var_a3);
    } else {
    temp_v0 = ((struct Bounds *)arg0)->upper;
    if (temp_v0 != 0x7FFF) {
        temp_f0 = (f32) temp_v0;
        if (temp_f0 < arg3[1]) {
            arg3[1] = temp_f0;
            return 1;
        }
    }
    if (((struct Bounds *)arg0)->lower != -0x8000) {
        temp_f0 = (f32) ((struct Bounds *)arg0)->lower;
        if (arg3[1] < temp_f0) {
            arg3[1] = temp_f0;
            return 1;
        }
    }
    return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B4790.s")

void func_800B5028(void) {
    s32 heap_alloc(s32);
    extern s32 D_80127F10;
    extern s16 D_80127F18;
    D_80127F10 = heap_alloc(0);
    D_80127F18 = 0;
}

void func_800B5054(void) {
    s32 func_800BA2C4(void *);
    void heap_free(void *);
    extern s32 D_80127F10;
    extern s16 D_80127F18;
    extern u8 D_80127F1D;
    s32 i;
    for (i = 0; i < D_80127F18; i++) {
        func_800BA2C4(((void **)D_80127F10)[i]);
    }
    heap_free((void *)D_80127F10);
    D_80127F10 = 0;
    D_80127F18 = 0;
    D_80127F1D = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B50F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B525C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B52EC.s")

void func_800B537C(s32 arg0)
{
    func_800B525C();
    func_800B52EC(arg0);
}
s32 func_800B53A4(s32 arg0) {
    s32 func_800BA2E8(s32);
    void *heap_realloc(void *, s32);
    extern s32 D_80127F10;
    extern s16 D_80127F18;
    D_80127F10 = (s32)heap_realloc((void *)D_80127F10, ++D_80127F18 * 4);
    (*(s32 *)((s8 *)((D_80127F10 + (D_80127F18 * 4))) + (-4))) = func_800BA2E8(arg0);
    (*(s8 *)((s8 *)((*(void **)((s8 *)((D_80127F10 + (D_80127F18 * 4))) + (-4)))) + (9))) = 1;
    return ((s32 *)D_80127F10 + D_80127F18)[-1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B5450.s")

void func_800B5534(s8 *arg0)
{
    arg0[9] = 0;
}

void func_800B553C(s8 *arg0)
{
    arg0[9] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B5548.s")

void func_800B562C(void) {
    s32 defrag(s32);
    extern s32 D_80127F10;
    D_80127F10 = defrag(D_80127F10);
}

void func_800B5654(s32 arg0, s32 arg1) {
    extern s8 D_80127F1C;
    if (arg1 == 2) {
        D_80127F1C = 1;
        return;
    }
    D_80127F1C = 0;
}

void func_800B5680(s32 arg0) {
    extern s16 D_80127F1A;
    extern u8 D_80127F1D;
    D_80127F1D = 1;
    D_80127F1A = arg0;
}

s32 func_800B5698(s16 *arg0) {
    extern s16 D_80127F1A;
    extern u8 D_80127F1D;
    if (D_80127F1D != 0) {
        *arg0 = D_80127F1A;
        return 1;
    }
    return 0;
}
