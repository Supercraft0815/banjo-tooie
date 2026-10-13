#include "common.h"
#include "core2/1EBB4F0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E1C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E1DF4.s")

void func_800E204C(u8 *arg0, u8 *arg1) {
    void func_800F26B0(f32 (*)[4], f32, f32, f32);
    extern s32 D_8012D470;
    extern f32 D_8012D4A8[4];
    s16 width;
    s16 globalWidth;
    Gfx *ptr;

    width = *(s16 *)(arg1 + 4);
    globalWidth = *(s16 *)&D_8012D470;
    if ((globalWidth != width && globalWidth != 0) ||
        (*(s16 *)((u8 *)&D_8012D470 + 2) != *(s16 *)(arg1 + 6) && *(s16 *)((u8 *)&D_8012D470 + 2) != 0) ||
        *(f32 *)((u8 *)&D_8012D470 + 0x2C) != 1.0f || *(f32 *)((u8 *)&D_8012D470 + 0x30) != 1.0f) {
        func_800F26B0((f32 (*)[4])D_8012D4A8,
            (f32)globalWidth * *(f32 *)((u8 *)&D_8012D470 + 0x2C) / (f32)width,
            *(f32 *)((u8 *)&D_8012D470 + 0x30) * (f32)*(s16 *)((u8 *)&D_8012D470 + 2) / (f32)*(s16 *)(arg1 + 6), 1.0f);
        guMtxF2L((f32 (*)[4])D_8012D4A8, *(Mtx **)(arg0 + 4));
        ptr = (*(Gfx **)arg0)++;
        ptr->words.w0 = 0xDA380000;
        ptr->words.w1 = (u32)*(Mtx **)(arg0 + 4);
        *(Mtx **)(arg0 + 4) = *(Mtx **)(arg0 + 4) + 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E22F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E23A4.s")

void func_800E2434(s32 arg0) {
    extern s8 D_8012D490;
    *(s8 *)((u8 *)&D_8012D490 + 0) = arg0;
}

void func_800E2440(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800F31DC(s32 *, s32, s32, s32);
    extern s32 D_8012D474;
    func_800F31DC(&D_8012D474, arg0, arg1, arg2);
}

void func_800E2478(s32 arg0) { void func_800E24F8(s32, s32, s32); func_800E24F8(arg0, arg0, arg0); }

void func_800E249C(s32 arg0) {
    extern s32 D_8012D494;
    *(s32 *)((u8 *)&D_8012D494 + 0) = arg0;
}

void func_800E24A8(f32 arg0) {
    extern f32 D_8012D4A4;
    *(f32 *)((u8 *)&D_8012D4A4 + 0) = arg0;
}

void func_800E24B4(s32 arg0) {
    extern u8 D_8012D48F;
    D_8012D48F = arg0;
}

void func_800E24C0(s32 arg0) {
    extern u8 D_8012D492;
    D_8012D492 = arg0;
}

void func_800E24CC(s32 arg0) {
    extern u8 D_8012D493;
    D_8012D493 = arg0;
}

void func_800E24D8(s32 arg0) {
    extern u8 D_8012D491;
    D_8012D491 = arg0;
}

void func_800E24E4(s32 arg0, s32 arg1) {
    extern s32 D_8012D470;
    (*(s32 *)((s8 *)(&D_8012D470) + (0x78))) = arg0;
    (*(s32 *)((s8 *)(&D_8012D470) + (0x7C))) = arg1;
}

void func_800E24F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800F31DC(s32 *, s32, s32, s32);
    extern s32 D_8012D480;
    func_800F31DC(&D_8012D480, arg0, arg1, arg2);
}

void func_800E2530(f32 arg0) {
    extern f32 D_8012D498;
    *(f32 *)((u8 *)&D_8012D498 + 0) = arg0;
}

void func_800E253C(f32 arg0) {
    extern s32 D_8012D470;
    (*(f32 *)((s8 *)(&D_8012D470) + (0x30))) = arg0;
    (*(f32 *)((s8 *)(&D_8012D470) + (0x2C))) = (f32) (*(f32 *)((s8 *)(&D_8012D470) + (0x30)));
}

void func_800E2554(f32 arg0, f32 arg1) {
    extern s32 D_8012D470;
    (*(f32 *)((s8 *)(&D_8012D470) + (0x2C))) = arg0;
    (*(f32 *)((s8 *)(&D_8012D470) + (0x30))) = arg1;
}

void func_800E2568(s32 arg0, s32 arg1) {
    extern s32 D_8012D470;
    (*(s16 *)((s8 *)(&D_8012D470) + (0))) = (s16) arg0;
    (*(s16 *)((s8 *)(&D_8012D470) + (2))) = (s16) arg1;
}

void func_800E257C(s32 arg0) {
    extern s16 D_8012D48C;
    *(s16 *)((u8 *)&D_8012D48C + 0) = arg0;
}

void func_800E2588(u32 arg0) {
    extern s8 D_8012D48E;
    D_8012D48E = (s8) arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E28A4.s")

void func_800E2A14(s32 arg0) {
    s32 func_800E22F0(s32, s32);
    extern s32 D_8012D4F0;
    func_800E22F0(arg0, D_8012D4F0);
    D_8012D4F0 = 0;
}

/* extern */

void func_800E2A3C(u8 *arg0, u8 *arg1, s32 arg2) { void func_800E1DF4(void); void func_800E2180(u8 *, u8 *, s32); void func_800E2260(u8 *, u8 *); s32 func_800E22F0(s32, s32); u8 *a = arg0; u8 *b = arg1; arg0 = NULL; arg1 = NULL; func_800E1DF4(); func_800E204C(a, b); func_800E2180(a, b, arg2); func_800E2260(a, b); func_800E22F0(a, b); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2C54.s")

f32 func_800E2DF0(void) {
    s32 func_800A89F8();
    f32 func_800A8AF0(s32);
    extern f32 D_80125D98;
    extern s32 D_8012D470;
    f32 var_f2;

    var_f2 = (*(f32 *)((s8 *)(&D_8012D470) + (0x2C)));
    if ((*(u8 *)((s8 *)(&D_8012D470) + (0x23))) != 0) {
        var_f2 *= D_80125D98 / func_800A8AF0(func_800A89F8());
    }
    return var_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E2E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E30E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E3220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E32CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EBB4F0/func_800E35E0.s")

void func_800E368C(s32 arg0) { s32 func_800E22F0(s32, s32); extern s32 D_8012D4F4;
    func_800E22F0(arg0, D_8012D4F4);
    D_8012D4F4 = 0;
    func_800E4640((Gfx **)arg0);
}
