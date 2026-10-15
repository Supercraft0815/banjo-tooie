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
    void func_800EB70C(void);
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

void *func_800E9898(s32 arg0) {
    s32 func_800B3CDC(s32 *, s32);
    extern s32 D_80132DB0;
    return (void *)func_800B3CDC(&D_80132DB0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E98C0.s")

void func_800E99E0(void) {
    typedef struct {
        u8 pad[0xB];
        u8 reserved : 3;
        u8 flag10 : 1;
        u8 flag8 : 1;
        u8 flag4 : 1;
        u8 reserved2 : 1;
        u8 flag1 : 1;
    } Flags;
    Flags *func_800E9804();
    Flags *p;
    p = func_800E9804();
    p->flag1 = 1;
    p->flag8 = 0;
    p->flag4 = 0;
    p->flag10 = 1;
}

void *func_800E9A24(s32 arg0) {
    typedef struct {
    u8 pad[6];
    u16 value : 9;
    u8 flags7 : 6;
    u8 flag7 : 1;
    u16 value8;
    u8 valueA;
    u8 valueB;
    u32 valueC;
    u8 pad10[2];
    u16 reserved12 : 6;
    u16 flag12b : 1;
    u16 flag12a : 1;
    u16 flag13a : 1;
    u16 flag13b : 1;
    u16 flag13c : 1;
    u16 flag13d : 1;
    u16 flag13e : 2;
    u16 flag13f : 2;
   
    } Data;
    Data *p = func_800E9898(arg0);
    p->value = 0x32;
    p->valueB = 0;
    p->valueA = 0;
    p->value8 = 0;
    p->valueC = 0;
    p->flags7 = 0;
    p->flag7 = 0;
    p->flag12b = 0;
    p->flag12a = 1;
    p->flag13a = 0;
    p->flag13b = 0;
    p->flag13c = 0;
    p->flag13d = 0;
    p->flag13e = 0;
    p->flag13f = 0;
    return p;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9B74.s")

Prop *func_800E9D68(s16 *);
s32 func_800E9BF4(s16 *arg0, s32 arg1) { if ((arg1 < 0) || (arg1 >= arg0[1])) return 0; return (s32)func_800E9D68(arg0) + arg1 * 20; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC2FD0/func_800E9CF4.s")

Prop *func_800E9D68(s16 *arg0) {
    s32 func_800B42A0(s32, s32);
    extern s32 D_80132DB0;
    return (Prop *)func_800B42A0(D_80132DB0, (s32)arg0);
}

u32 func_800E9D90(s16 *arg0) { return arg0[1] * 20 + (u32)func_800E9D68(arg0); }

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

void func_800E9DF8(void) {
    s32 defrag(s32);
    s32 func_800BE4C4(s32 *);
    extern s32 D_80132DB0;
    extern s32 D_80132DB4;
    s32 temp_v0;
    s32 *ptr;

    D_80132DB0 = defrag(D_80132DB0);
    temp_v0 = defrag(D_80132DB4);
    ptr = (s32 *)((u32)&D_80132DB4 | 0);
    if (temp_v0 != *ptr) {
        *ptr = temp_v0;
        func_800BE4C4(ptr);
    }
}

/* extern */

void func_800E9E4C(u8 *arg0, s32 arg1) {
    void func_800B4290(void *arg0);
    u8 *func_800BE5C4();
    func_800B4290(arg0 + 4);
    func_800B4290(arg0);
    *func_800BE5C4(arg0) = 0;
}

s32 func_800E9E88(s32 arg0) {
    extern s32 D_80132DB4;
    s32 func_800B42A0(s32, s32);
    return func_800B42A0(D_80132DB4, arg0 + 4);
}

u32 func_800E9EB4(s16 *arg0) { return arg0[3] * 12 + (u32)func_800E9E88((s32)arg0); }

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
