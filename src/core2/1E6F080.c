#include "core2/1E6F080.h"

s32 func_80095790() 
{
    return 0xAC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80095798.s")

void func_80095870(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (4)));
    *arg2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (8)));
}

s32 func_8009588C(s32 *arg0)
{
    return ((s32 *)arg0[37])[5];
}

u32 func_80095898(s32 *arg0)
{
    return ((u8 *)arg0[37])[162];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800958A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_8009590C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80095964.s")

void func_800959C8(PlayerState *arg0, f32 arg1, f32 arg2) {
    void *temp_v0;

    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0x64))) = arg1;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x94)));
    (*(f32 *)((s8 *)(temp_v0) + (4))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x64)));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0x68))) = arg2;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x94)));
    (*(f32 *)((s8 *)(temp_v0) + (8))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x68)));
}

void func_800959FC(s32 *arg0, s32 arg1) {
    ((s32 *) arg0[37])[5] = arg1;
}

void func_80095A08(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x94)));
        (*(s32 *)((s8 *)(temp_v0) + (0x14))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x14))) | arg1);
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x94)));
    (*(s32 *)((s8 *)(temp_v0_2) + (0x14))) = (s32) ((*(s32 *)((s8 *)(temp_v0_2) + (0x14))) & ~arg1);
}

void func_80095A40(PlayerState *arg0) {
    func_800959C8(arg0, 80.0f, 35.0f);
}

void func_80095A64(s32 *arg0) {
    arg0[20] = 0;
}

void func_80095A6C(s32 *arg0, s32 *arg1) {
    arg1[20] = (s32) arg0;
}

/* extern */

void func_80095A74(void *arg0, s32 arg1) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0xB8) {
        if (arg1 != 0) {
            func_80095A08(arg0, 8, 1);
            return;
        }
        func_80095A08(arg0, 8, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80095AD0.s")

/* extern */

void func_80095C10(void *arg0) {
    s32 func_800C5BA4(s32);
    func_800C5BA4(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80095C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80095C94.s")

s32 func_800961A0(s32 *arg0, s32 arg1)
{
    ((u8 *) arg0[0x25])[0xA2] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800961AC.s")

void func_80096254(s32 *arg0, s32 arg1)
{
    ((s32 *) arg0[0x25])[0x2A] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80096260.s")

void func_800962B0(PlayerState *arg0, s32 arg1) {
    void func_800C68D4(s8 *arg0, s32 arg1);
    func_800C68D4(*(*(s8 ***)((s8 *)(arg0) + (0x94))), arg1);
}

/* extern */

f32 func_800962D4(void *arg0) {
    f32 func_8009C150();
    f32 func_800C6784(s32);
    f32 sp1C;

    sp1C = func_8009C150();
    return sp1C - func_800C6784(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_8009630C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80096364.s")

s32 func_80096388(PlayerState *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[39];
}

/* extern */

void func_80096394(PlayerState *arg0, f32 *arg1) {
    s32 func_800EE7F8(f32 *, s32);
    func_800EE7F8(arg1, (*(s32 *)((s8 *)(arg0) + (0x94))) + 0x90);
}

void func_800963C0(PlayerState *arg0, f32 *arg1) {
    void func_800C675C(void *arg0, f32 *arg1);
    func_800C675C(*(*(u8 ***)((s8 *)(arg0) + (0x94))), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800963E4.s")

int func_8009640C(PlayerState *arg0) {
    u8 *ptr;

    ptr = *(u8 **)((u8 *)arg0 + 0x94);
    return ptr[0x18] == 0 && ptr[0x56] != 0;
}

s32 func_80096434(PlayerState *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[29];
}

/* extern */

void func_80096440(PlayerState *arg0, f32 *arg1) {
    s32 func_800EE7F8(f32 *, s32);
    func_800EE7F8(arg1, (*(s32 *)((s8 *)(arg0) + (0x94))) + 0x44);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_8009646C.s")

s32 func_800964D0(PlayerState *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[42];
}

f32 func_800964DC(PlayerState *arg0) {
    f32 func_800C67D8(f32 *arg0);
    return func_800C67D8(*(*(f32 ***)((s8 *)arg0 + 0x94)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80096500.s")

s32 func_8009650C(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0x55];
}

u32 func_80096518(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0x56];
}

u32 func_80096524(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0xA0];
}

s32 func_80096530(void *arg0) {
    return (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0xA3))) == 3;
}

/* extern */

s32 func_80096544(PlayerState *arg0) {
    s32 func_800C670C(s32);
    return func_800C670C(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

s32 func_80096568(void *arg0, s32 arg1) {
    s32 func_800C6744(s32);
    return arg1 == (func_800C6744(*(*(s32 **)((s8 *)(arg0) + (0x94)))) & 0x1F00);
}

/* extern */

s32 func_8009659C(void *arg0, s32 arg1) {
    s32 func_800C6744(s32);
    return func_800C6744(*(*(s32 **)((s8 *)(arg0) + (0x94)))) & arg1;
}

u8 func_800965C8(void *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0xA4];
}

s32 func_800965D4(void *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[0x14];
}

/* extern */

void func_800965E0(void *arg0) {
    s32 func_800C67F8(s32);
    func_800C67F8(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096604(void *arg0) {
    s32 func_800C6840(s32);
    func_800C6840(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

s32 func_80096628(PlayerState *arg0) {
    s32 func_800C6744(s32);
    return func_800C6744(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_8009664C(void *arg0) {
    s32 func_800C674C(s32);
    func_800C674C(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096670(void *arg0) {
    s32 func_800C67C8(s32);
    func_800C67C8(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

void func_80096694(PlayerState* a0)
{
    func_800C84B0(func_80096628(a0));
}

/* extern */

void func_800966BC(void *arg0) {
    s32 func_800C67E0(s32);
    func_800C67E0(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_800966E0(void *arg0) {
    s32 func_800C67E8(s32);
    func_800C67E8(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096704(void *arg0) {
    s32 func_800C5B84(s32);
    func_800C5B84(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096728(void *arg0) {
    s32 func_800C5BC4(s32);
    s32 temp_a1;

    temp_a1 = *(*(s32 **)((s8 *)(arg0) + (0x94)));
    if (temp_a1 != 0) {
        *(*(s32 **)((s8 *)(arg0) + (0x94))) = func_800C5BC4(temp_a1);
    }
}

/* extern */

void func_80096768(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800D4D5C(s32, void *);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_800D4D5C((s32) sp1C, *(void **)((s8 *)arg0 + 0x94));
}

/* extern */

void func_8009679C(void *arg0) {
    s32 func_800C68DC(s32);
    func_800C68DC(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

s32 func_800967C0() 
{
    return 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800967C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80096ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80096DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80096E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_8009700C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800970A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80097104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800972BC.s")

/* extern */

f32 func_800974FC(PlayerState *arg0) {
    s32 func_800F1EA4(s32, f32 *);
    f32 sp1C;

    func_800F1EA4((*(s32 *)((s8 *)(arg0) + (0x98))), &sp1C);
    return sp1C;
}

s32 func_80097524(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x98))[0x25];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80097530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800976DC.s")

/* extern */

void func_80097858(void *arg0) {
    s32 bastatetimer_set(void *, s32, f32);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x98)))) + (0x24))) = 1;
    bastatetimer_set(arg0, 7, 0.2f);
}

void func_8009788C(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x98)))) + (0x24))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x98)))) + (0x26))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_800978A4.s")
