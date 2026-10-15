#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B46B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B4790.s")

void func_800B5028(void) {
    s32 heap_alloc(s32);
    extern s32 D_80127F10;
    extern s16 D_80127F18;
    D_80127F10 = heap_alloc(0);
    D_80127F18 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8DFA0/func_800B5054.s")

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
