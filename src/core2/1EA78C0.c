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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE3E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE3F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE524.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE83C.s")

/* extern */

void func_800CE864(void) {
    void *func_800CE3E0();
    (*(s8 *)((s8 *)(func_800CE3E0()) + (0x14))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE8D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE928.s")

/* extern */

s32 func_800CE95C(void) {
    void *func_800CE3E0();
    return (*(s32 *)((s8 *)(func_800CE3E0()) + (0x18)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CE9E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEA84.s")

/* extern */

s32 func_800CEAA8(void) {
    void *func_800CE3E0();
    return (*(s8 *)((s8 *)(func_800CE3E0()) + (0x12))) > 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEAD0.s")

s32 func_800CEB08(void *arg0, f32 arg1) {
    if (((*(s8 *)((s8 *)(arg0) + (0x12))) != 0) && (arg1 <= (*(f32 *)((s8 *)(arg0) + (4)))) && ((*(f32 *)((s8 *)(arg0) + (0))) < arg1)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEB54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEBD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEC94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CEF48.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA78C0/func_800CF67C.s")

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
