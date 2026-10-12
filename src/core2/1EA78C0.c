#include "core2/1EA78C0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CDFD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE21C.s")

void func_800CE2DC(void) {
    s32 func_800DAA8C(s32 *, s32, s32);
    extern s32 D_8012B020;
    func_800DAA8C(&D_8012B020, 7, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE308.s")

void *func_800CE3E0(s32 arg0) {
    extern s32 D_8012B030;
    return (void *) ((arg0 << 5) + (s32) &D_8012B030);
}

void func_800CE3F4(u8 *arg0, s32 arg1) { extern s16 D_8011AA30;
    func_800D2498(*(s16 *)((s8 *)&D_8011AA30 + arg1 * 6), *(s16 *)(arg0 + 0xA), 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE49C.s")

/* extern */

void func_800CE524(void) {
    void *func_800CE3E0(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_800CE3E0(var_s0);
        (*(s16 *)((s8 *)(temp_v0) + (8))) = 0;
        var_s0 += 1;
        (*(f32 *)((s8 *)(temp_v0) + (0))) = 0.0f;
        (*(f32 *)((s8 *)(temp_v0) + (4))) = 0.0f;
        (*(s8 *)((s8 *)(temp_v0) + (0x16))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x15))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x14))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x12))) = 0;
        (*(s8 *)((s8 *)(temp_v0) + (0x13))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0x18))) = 0;
        (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = 0;
        (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) (*(s16 *)((s8 *)(temp_v0) + (8)));
    } while (var_s0 != 9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE59C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE628.s")

void func_800CE7DC(void) {
    s32 func_800C2FDC(u8);
    s32 func_800FC74C(s32);
    extern s32 D_8012B030;
    if ((*(u8 *)((s8 *)(&D_8012B030) + (0x120))) != 0) {
        func_800C2FDC((*(u8 *)((s8 *)(&D_8012B030) + (0x120))));
        (*(u8 *)((s8 *)(&D_8012B030) + (0x120))) = 0U;
    }
    if ((*(u8 *)((s8 *)(&D_8012B030) + (0x121))) != 0) {
        func_800FC74C(0x92);
        (*(u8 *)((s8 *)(&D_8012B030) + (0x121))) = 0U;
    }
}

s32 func_800CE83C(s32 arg0, s32 arg1) {
    void *func_800CE3E0(s32);
    s8 *ptr;

    ptr = func_800CE3E0(arg0);
    ptr[0x13] = arg1;
    return (s32) ptr;
}

/* extern */

void func_800CE864(void) {
    void *func_800CE3E0();
    (*(s8 *)((s8 *)(func_800CE3E0()) + (0x14))) = 1;
}

void func_800CE88C(s32 arg0, s32 arg1) { void *temp_v0; s8 temp_v1; temp_v0 = func_800CE3E0(arg0); if (arg1 != 0) { *(s8 *)((s8 *)temp_v0 + 0x12) = *(s8 *)((s8 *)temp_v0 + 0x12) + 1; } else { temp_v1 = *(s8 *)((s8 *)temp_v0 + 0x12); if (temp_v1 != 0) *(s8 *)((s8 *)temp_v0 + 0x12) = temp_v1 - 1; } }

void func_800CE8D8(s32 arg0, f32 arg1, s32 arg2) {
    void *func_800CE3E0(s32);
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    (*(s8 *)((s8 *)(temp_v0) + (0x15))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x10))) = (s16) arg2;
    (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) arg2;
    (*(s16 *)((s8 *)(temp_v0) + (8))) = (s16) arg2;
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = arg1;
    (*(f32 *)((s8 *)(temp_v0) + (4))) = arg1;
    (*(f32 *)((s8 *)(temp_v0) + (0))) = arg1;
}

void func_800CE928(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = arg1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = arg2;
}

/* extern */

s32 func_800CE95C(void) {
    void *func_800CE3E0();
    return (*(s32 *)((s8 *)(func_800CE3E0()) + (0x18)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE980.s")

s32 func_800CE9E8(s32 arg0, s32 arg1) {
    void *func_800CE3E0();
    s32 func_800CE438(u8 *, s32, s32);
    u8 *temp_v0;

    temp_v0 = func_800CE3E0();
    if ((*(s16 *)((s8 *)(temp_v0) + (0x10))) < arg1) {
        (*(s16 *)((s8 *)(temp_v0) + (0x10))) = (s16) arg1;
    }
    (*(s16 *)((s8 *)(temp_v0) + (8))) = (s16) arg1;
    (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) arg1;
    return func_800CE438(temp_v0, arg0, arg1);
}

void func_800CEA38(s32 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800CE3E0(arg0)) + (0x15))) = (s8) arg1;
}

f32 func_800CEA60(s32 arg0) {
    return *(f32 *) func_800CE3E0(arg0);
}

s16 func_800CEA84(s32 arg0) {
    return (*(s16 *)((s8 *)(func_800CE3E0(arg0)) + (0xA)));
}

/* extern */

s32 func_800CEAA8(void) {
    void *func_800CE3E0();
    return (*(s8 *)((s8 *)(func_800CE3E0()) + (0x12))) > 0;
}

s32 func_800CEAD0(s32 arg0) {
    return func_800CEA60(arg0) == 0.0f;
}

s32 func_800CEB08(void *arg0, f32 arg1) {
    if (((*(s8 *)((s8 *)(arg0) + (0x12))) != 0) && (arg1 <= (*(f32 *)((s8 *)(arg0) + (4)))) && ((*(f32 *)((s8 *)(arg0) + (0))) < arg1)) {
        return 1;
    }
    return 0;
}

void func_800CEB54(s32 arg0, f32 arg1) {
    func_800CEB08(func_800CE3E0(arg0), arg1);
}

s32 func_800CEB80(s32 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_800CE3E0(arg0);
    if (((*(s8 *)((s8 *)(temp_v0) + (0x12))) != 0) && (arg1 < (*(s16 *)((s8 *)(temp_v0) + (8)))) && (arg1 >= (*(s16 *)((s8 *)(temp_v0) + (0xA))))) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEBD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEC94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEF00.s")

f32 func_800CEF48(s32 arg0) {
    extern s16 D_8011AA8E;
    return (f32) *(s16 *) ((u8 *) &D_8011AA8E + arg0 * 20);
}

void func_800CEF6C(void) {
    extern f32 D_8012B170;
    D_8012B170 = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEF7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF01C.s")

void func_800CF160(f32 arg0, s32 arg1) {
    extern s32 D_8012B160;
    (*(s8 *)((s8 *)(&D_8012B160) + (0xC))) = 1;
    (*(f32 *)((s8 *)(&D_8012B160) + (0x14))) = arg0;
    (*(s32 *)((s8 *)(&D_8012B160) + (0x1C))) = arg1;
    (*(f32 *)((s8 *)(&D_8012B160) + (0x18))) = 0.0f;
}

void func_800CF184(void)
{
    extern u8 D_8012B16C;

    D_8012B16C = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF190.s")

void func_800CF264(void) {
    s32 func_800CF01C();
    s32 func_800CF190();
    s32 func_800EA09C();
    extern u8 D_8012B16C;
    if (func_800EA09C() == 2) {
        func_800CF01C();
        if (D_8012B16C != 0) {
            func_800CF190();
        }
    }
}

void func_800CF2B0(void) {
    f32 func_800CEA60(s32);
    extern f32 D_8012B170;
    D_8012B170 = func_800CEA60(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF2D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF40C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF580.s")

s16 func_800CF640(void) {
    s32 func_800CEAA8();
    extern s32 D_8012B15E;
    s16 var_v1;
    s32 temp_v0;

    temp_v0 = func_800CEAA8(1);
    if (temp_v0 != 0) {
        var_v1 = ((s16 *)&D_8012B15E)[temp_v0];
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

f32 func_800CF67C(void) {
    f32 func_800CEF00(s32);
    f32 sp18[2];

    sp18[0] = func_800CEA60(1);
    return sp18[0] / func_800CEF00(func_800CF640());
}

void func_800CF6B0()
{
    func_800CEA84(0x1);
}

/* extern */

s32 func_800CF6D0(void) {
    s32 func_800DA298(s32);
    s32 var_v1;

    if (func_800DA298(0x1BF) != 0) {
        var_v1 = 0xA;
    } else {
        var_v1 = 6;
    }
    return var_v1;
}

/* extern */

void func_800CF700(void) {
    s32 func_800CE9E8(s32, s32);
    s32 func_800DA544(s32);
    func_800DA544(0x1BF);
    func_800CE9E8(1, func_800CF6D0());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF734.s")

/* extern */

void func_800CF7F4(u32 a0) {
    s32 func_800A16A4();
    s32 func_800CEBD8(s32, u32);
    s32 func_800CF580();
    if (((func_800CF580() != 0) && (func_800A16A4() == 0)) || (a0 == 0)) {
        func_800CEBD8(1, a0);
    }
}

/* extern */

void func_800CF840(s32 arg0) {
    s32 func_800CE83C(s32, s32);
    func_800CE83C(1, arg0);
}
