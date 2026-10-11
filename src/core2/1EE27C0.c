#include "common.h"

OSThread *func_80108ED0(void)
{
    extern u8 D_801245D0[];

    return (OSThread *) D_801245D0;
}

OSThread *func_80108EDC(void)
{
    extern u8 D_801245E4[];

    return (OSThread *) D_801245E4;
}

OSThread *func_80108EE8(void)
{
    extern u8 D_801245F8[];

    return (OSThread *) D_801245F8;
}

s32 func_80108EF4(void *arg0, s32 arg1) {
    return (*(u16 *)((s8 *)(arg0) + (8))) == 0x23A;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80108F08.s")

void func_801094E0(f32 *arg0, f32 arg1) {
    void func_800BBCB8(f32[3], s32, f32, s32, s32 *);
    extern s32 D_8012461C;
    func_800BBCB8(arg0, (s32) arg0, arg1, 3, &D_8012461C);
}

OSThread *func_80109518(void)
{
    extern u8 D_8012464C[];

    return (OSThread *) D_8012464C;
}

s32 func_80109524(s32 arg0) {
    extern s16 D_801245A0[8][8];
    return D_801245A0[arg0][0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010963C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010965C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801096C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801098D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_801099D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109C20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_80109CC4.s")

s32 func_80109EE0(void *arg0, s32 arg1) {
    return (*(u16 *)((s8 *)(arg0) + (0x66))) & arg1;
}

void func_80109EEC(s16 *arg0, s32 arg1) {
    arg0[51] = arg1;
}

void func_80109EF4(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x66))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x66))) & ~arg1);
}

void func_80109F08(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x66))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x66))) | arg1);
}

/* extern */

void func_80109F18(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x3E, arg1);
}

/* extern */

void func_80109F40(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x3F, arg1);
}

/* extern */

void func_80109F68(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x40, arg1);
}

/* extern */

void func_80109F90(s32 arg0, volatile s32 arg1) {
    s32 func_8010114C(s32, s32, s32);
    func_8010114C(arg0, 0x41, arg1);
}

/* extern */

void func_80109FB8(s32 arg0, volatile s32 arg1) {
    void *func_80106790(s32);
    (*(s32 *)((s8 *)(func_80106790(*(s32 *)&arg1)) + (0x3C))) = arg0;
}

void func_80109FE8(void **arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1B];
        u8 other : 7;
        u8 enabled : 1;
    };
    if (arg1 != 0) {
        ((struct Flags *) *arg0)->enabled = 0;
        return;
    }
    ((struct Flags *) *arg0)->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A2FC.s")

void func_8010A3E8(void *arg0, f32 arg1) {
    (*(s16 *)((s8 *)(arg0) + (0x92))) = (s16) (s32) (256.0f * arg1);
}

f32 func_8010A40C(void *arg0) {
    return (f32) (*(s16 *)((s8 *)(arg0) + (0x92))) * 0.00390625f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A430.s")

void func_8010A570(s32 arg0)
{
    func_8010A5B0(arg0,0);
}

void func_8010A590(s32 arg0)
{
    func_8010A5B0(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A5B0.s")

u32 func_8010A610(void **arg0) {
    return (u32) ((*(s32 *)((s8 *)(*arg0) + (0x28))) << 0x16) >> 0x1F;
}

void func_8010A624(void ***arg0) {
    void *temp_v0;

    temp_v0 = **arg0;
    (*(u8 *)((s8 *)(temp_v0) + (0xB))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0xB))) & 0xFFF7);
}

void func_8010A63C(void ***arg0) {
    struct Flags {
        u8 pad[8];
        u32 upper : 28;
        u32 enabled : 1;
        u32 lower : 3;
    } *flags;

    flags = **arg0;
    flags->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A654.s")

u32 func_8010A698(void ***arg0) {
    return (u32) ((*(s32 *)((s8 *)(**arg0) + (8))) << 0x1C) >> 0x1F;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE27C0/func_8010A6B0.s")
