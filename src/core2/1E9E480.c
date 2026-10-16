#include "common.h"

void func_800C4B90(s32 arg0, f32 arg1, f32 arg2) {
    f32 func_80015D14(void *);
    s32 func_800A8984(s32);
    void *func_800A89A0(s32);
    f32 func_800A8AD4(s32);
    extern f32 D_80125890;
    extern f32 D_8012A9A0[];
    f32 temp_f8;
    f32 sp20;
    s32 sp1C;
    void *sp18;

    sp1C = func_800A8984(arg0);
    sp18 = func_800A89A0(arg0);
    if ((sp18 != 0) && (sp1C != 0)) {
        sp20 = func_800A8AD4(arg0);
        temp_f8 = func_80015D14(sp18);
        D_8012A9A0[31] += (arg1 * sp20) / 40.0f;
        D_8012A9A0[30] += (arg2 * temp_f8) / D_80125890;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C4C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C4E58.s")

/* extern */

void func_800C5008(s32 arg0, f32 *arg1, f32 *arg2) {
    void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    func_800A8A04(arg0, &sp2C, &sp28, &sp24, &sp20);
    arg2[0] = arg1[0] * ((f32) sp24 / 304.0f);
    arg2[1] = arg1[1] * ((f32) sp20 / 228.0f);
}

void func_800C5094(s32 arg0, f32 arg1) {
    f32 func_800139F8(f32);
    f32 func_80013B7C(f32, f32);
    void func_800A8A44(s32, s32 *, s32 *, s32 *, s32 *);
    void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
    void func_800A8A88(s32, f32);
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    func_800A8A44(arg0, &sp34, &sp30, &sp2C, &sp28);
    func_800A8A04(arg0, &sp34, &sp30, &sp2C, &sp24);
    if (sp28 != sp24) {
        arg1 = 2.0f * func_80013B7C((f32) sp24, (f32) sp28 / func_800139F8(arg1 * 0.5f));
    }
    func_800A8A88(arg0, arg1);
}

/* extern */

void func_800C5148(s32 arg0, f32 arg1) {
    extern f32 D_8012A9F0[];
    void func_800C5094(s32, f32);
    D_8012A9F0[arg0] = arg1;
    func_800C5094(arg0, arg1);
}

f32 func_800C517C(s32 arg0) {
    extern f32 D_8012A9F0[];
    return ((f32 *)&D_8012A9F0)[arg0];
}

f32 func_800C5190(s32 arg0) {
    extern f32 D_8012AA04[];
    return ((f32 *)&D_8012AA04)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C51A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C524C.s")

s32 func_800C52F4(s32 arg0, s32 arg1) {
    void func_800A8A44(s32, s32 *, s32 *, s32 *, s32 *);
    s32 func_800C524C(s32, s32);
    extern f32 D_8012A9A0[];
    void *temp_v0;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 temp_f16;

    temp_v0 = (s8 *)D_8012A9A0 + arg0 * 0x10;
    if ((*(u8 *)((s8 *)temp_v0 + 0xC) == 1) ||
        (*(u8 *)((s8 *)temp_v0 + 0xC) == 2)) {
        return 0;
    }
    (*(u8 *)((s8 *)(temp_v0) + (0xC))) = 1U;
    (*(s32 *)((s8 *)(temp_v0) + (0))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (4))) = arg1;
    func_800A8A44(arg0, &sp38, &sp34, &sp30, &sp2C);
    temp_f16 = (s32) ((f32) sp30 * 0.5625f);
    if (temp_f16 & 1) {
        temp_f16++;
    }
    (*(s32 *)((s8 *)(temp_v0) + (8))) = (sp2C - temp_f16) / 2;
    if (arg1 == 0) {
        (*(s32 *)((s8 *)(temp_v0) + (0))) = (*(s32 *)((s8 *)temp_v0 + 8));
        (*(s8 *)((s8 *)(temp_v0) + (0xC))) = 2;
        func_800C524C(arg0, (*(s32 *)((s8 *)temp_v0 + 8)));
    }
    return 1;
}

s32 func_800C53EC(s32 arg0, s32 arg1) {
    s32 func_800C524C(s32, s32);
    extern f32 D_8012A9A0[];
    void *temp_v0;

    temp_v0 = (s8 *)D_8012A9A0 + arg0 * 0x10;
    if ((*(u8 *)((s8 *)temp_v0 + 0xC) == 0) ||
        (*(u8 *)((s8 *)temp_v0 + 0xC) == 3)) {
        return 0;
    }
    (*(u8 *)((s8 *)(temp_v0) + (0xC))) = 3U;
    (*(s32 *)((s8 *)(temp_v0) + (4))) = arg1;
    func_800C524C(arg0, 0);
    if (arg1 == 0) {
        (*(s32 *)((s8 *)(temp_v0) + (0))) = 0;
    }
    return 1;
}

/* extern */

void func_800C54CC(s32, f32, f32);

void func_800C5464(void) {
    f32 var_f20 = 40.0f;
    f32 var_f22 = 1.0f;
    s32 var_s0;
    for (var_s0 = 0; var_s0 != 5; var_s0++) {
        func_800C54CC(var_s0, var_f20, var_f22);
    }
}

void func_800C54CC(s32 arg0, f32 arg1, f32 arg2) {
    extern f32 D_8012A9A0[];
    f32 *p = D_8012A9A0 + arg0;
    p[20] = arg1;
    p[25] = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9E480/func_800C54F0.s")

void func_800C5668(s32 arg0, Gfx **arg1) {
    void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
    void func_800B9A24(Gfx **, s32, s32 *, s32, s32, s32, s32);
    extern s32 D_8011A880;
    extern f32 D_8012A9A0[];
    s8 *entry;
    s32 alpha;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    f32 ratio;

    entry = (s8 *)D_8012A9A0 + arg0 * 0x10;
    if (((u8 *)entry)[0xC] == 3 || ((u8 *)entry)[0xC] == 1) {
        func_800A8A04(arg0, &sp44, &sp40, &sp3C, &sp38);
        ratio = (f32)*(s32 *)entry / (f32)*(s32 *)(entry + 8);
        sp34 = *(s32 *)entry;
        alpha = (s32)(ratio * 255.0f);
        func_800B9A24(arg1, alpha, &D_8011A880, sp44, sp40, sp3C, sp34);
        func_800B9A24(arg1, alpha, &D_8011A880, sp44, (sp40 + sp38) - sp34, sp3C, sp34);
    }
}
