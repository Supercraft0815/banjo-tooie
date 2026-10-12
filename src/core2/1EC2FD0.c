#include "common.h"

void func_800E96E0()
{
    func_800EA3A0();
    func_800EBB6C();
}

void func_800E9708()
{
    func_800EA370();
}

void func_800E9728(void) {
    s32 func_800B42FC(s32, s32);
    s32 func_800EA390();
    s32 func_800EB70C();
    extern s32 D_80132DB0;
    extern s32 D_80132DB4;
    func_800EA390();
    func_800EB70C();
    D_80132DB0 = func_800B42FC(0x14, 0xA);
    D_80132DB4 = func_800B42FC(0xC, 0xA);
}

void func_800E9774(void) {
    s32 func_800B42DC(s32);
    s32 func_800EA398();
    s32 func_800EB750();
    extern s32 D_80132DB0;
    extern s32 D_80132DB4;
    func_800EA398();
    func_800EB750();
    func_800B42DC(D_80132DB0);
    D_80132DB0 = 0;
    func_800B42DC(D_80132DB4);
    D_80132DB4 = 0;
}

/* extern */

void func_800E97C0(void) {
    s32 func_800A5CFC();
    s32 func_800EA09C();
    s32 func_800EA45C();
    s32 func_800EA51C();
    if (func_800EA09C() != 1) {
        func_800EA45C();
        func_800A5CFC();
        func_800EA51C();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9804.s")

void func_800E9898(s32 arg0) {
    s32 func_800B3CDC(s32 *, s32);
    extern s32 D_80132DB0;
    func_800B3CDC(&D_80132DB0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E98C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E99E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9CF4.s")

void func_800E9D68(s32 arg0) {
    s32 func_800B42A0(s32, s32);
    extern s32 D_80132DB0;
    func_800B42A0(D_80132DB0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9D90.s")

s32 func_800E9DC4(s16 *arg0) {
    return arg0[1];
}

s32 func_800E9DCC(s16 *arg0) {
    return arg0[3];
}

/* extern */

u8 func_800E9DD4(void) {
    u8 *func_800BE5C4();
    return *func_800BE5C4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9DF8.s")

/* extern */

void func_800E9E4C(u8 *arg0, s32 arg1) {
    void func_800B4290(void *arg0);
    u8 *func_800BE5C4();
    func_800B4290(arg0 + 4);
    func_800B4290(arg0);
    *func_800BE5C4(arg0) = 0;
}

void func_800E9E88(s32 arg0) {
    extern s32 D_80132DB4;
    s32 func_800B42A0(s32, s32);
    func_800B42A0(D_80132DB4, arg0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9EB4.s")

/* extern */

void func_800E9EE8(s32 arg0) {
    s32 _gccubesearch_entrypoint_17(s32, s32);
    s32 func_800E9B74(s32, s32);
    s32 temp_v0;
    s32 sp18;

    temp_v0 = _gccubesearch_entrypoint_17(arg0, (s32) &sp18);
    if (temp_v0 != 0) {
        func_800E9B74(sp18, temp_v0);
    }
}
