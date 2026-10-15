#include "core2/1E6F080.h"

s32 func_80095790() 
{
    return 0xAC;
}

/* extern */

void func_80095798(void *arg0) {
    void func_80098590(f32 **, f32 *);
    f32 func_800985B8(f32 **);
    f32 func_8009864C(void *);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    f32 mlAbsF(f32);
    void yaw_applyIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    f32 sp3C[3];
    f32 sp38;
    f32 temp_f0;
    f32 sp30;

    sp38 = func_800985B8(arg0);
    temp_f0 = func_8009864C(arg0);
    if (temp_f0 < (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C))) {
        (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C)) = temp_f0;
    }
    if ((*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C)) < sp38) {
        (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C)) = sp38;
    }
    func_80098590(arg0, sp3C);
    func_800F1E6C((f32 *)((*(u8 **)((s8 *)(arg0) + (0x94))) + 0x78), sp3C, &sp30);
    if (mlAbsF(func_800F1DCC(sp30, yaw_get(arg0))) > 1.0f) {
        yaw_setIdeal(arg0, sp30);
        yaw_applyIdeal(arg0);
    }
}

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

/* extern */

s32 func_800958A4(PlayerState *arg0, f32 arg1, f32 arg2) {
    void func_8009C128(PlayerState *, f32[3]);
    void *func_800C6C94(f32[3], f32, f32[3], u32);
    s32 pad;
    f32 sp28[3];
    f32 sp1C[3];
    s32 var_v1;

    func_8009C128(arg0, sp28);
    sp28[1] += arg1;
    if (func_800C6C94(sp28, arg2, sp1C, (*(u32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0x14)))) != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_8009590C(PlayerState *arg0, f32 arg1) {
    void func_800C68A0(void *arg0, f32 arg1);
    if (arg1 == 0.0f) {
        func_800C68A0(*(*(void ***)((s8 *)(arg0) + (0x94))), 56.0f);
        return;
    }
    func_800C68A0(*(*(void ***)((s8 *)(arg0) + (0x94))), arg1);
}

void func_80095964(void *arg0, s32 arg1) {
    void func_80095A08(void *arg0, s32 arg1, s32 arg2);
    if (arg1 != 0) {
        func_80095A08(arg0, 8, 1);
        func_80095A08(arg0, 4, 0);
        return;
    }
    func_80095A08(arg0, 8, 0);
    func_80095A08(arg0, 4, 1);
}

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

f32 func_80095C34(f32 arg0, f32 arg1, f32 arg2) {
    f32 func_800F13F0(f32, f32);
    f32 func_800F0E00(f32, f32);
    if (arg1 < arg0) {
        arg1 = func_800F13F0(arg0, arg1 + arg2);
    } else if (arg0 < arg1) {
        arg1 = func_800F0E00(arg0, arg1 - arg2);
    }
    return arg1;
}

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

void func_80096260(PlayerState *arg0) {
    if (func_800C84B0(func_80096628(arg0)) == 0x18) {
        func_80096254((s32 *) arg0, 4);
        return;
    }
    func_80096254((s32 *) arg0, 2);
}

void func_800962B0(PlayerState *arg0, s32 arg1) {
    void func_800C68D4(s8 *arg0, s32 arg1);
    func_800C68D4(*(*(s8 ***)((s8 *)(arg0) + (0x94))), arg1);
}

/* extern */

f32 func_800962D4(void *arg0) {
    f32 func_8009C150();
    f32 func_800C6784(void *);
    f32 sp1C;

    sp1C = func_8009C150();
    return sp1C - func_800C6784(*(*(void ***)((s8 *)(arg0) + (0x94))));
}

/* extern */

f32 func_8009630C(PlayerState *arg0) {
    f32 func_8009C150(PlayerState *);
    f32 func_800C6784(void *);
    f32 func_800C67D8(f32 *);
    f32 func_800F0E00(f32, f32);
    s32 pad;
    f32 sp20;
    f32 sp1C;

    sp1C = func_8009C150(arg0);
    sp20 = func_800C6784(*(*(void ***)((s8 *)arg0 + 0x94)));
    return sp1C - func_800F0E00(sp20, func_800C67D8(*(*(f32 ***)((s8 *)arg0 + 0x94))));
}

f32 func_80096364(PlayerState *arg0) {
    f32 func_800C6784(void *);
    return func_800C6784(*(*(void ***)((u8 *)arg0 + 0x94)));
}

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

void func_800963E4(PlayerState *arg0) {
    f32 func_80013A7C(f32);
    s32 pad;
    f32 sp1C[2];
    func_800963C0(arg0, sp1C);
    func_80013A7C(sp1C[1]);
}

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

void func_8009646C(u8 *arg0, f32 *arg1) {
    s32 func_800EE7F8(f32 *, s32);
    f32 *var_s1;
    s32 var_s0;

    var_s0 = 0;
    var_s1 = arg1;
    do {
        func_800EE7F8(var_s1, (*(s32 *)((s8 *)(arg0) + (0x94))) + var_s0 + 0x20);
        var_s0 += 0xC;
        var_s1 += 3;
    } while (var_s0 != 0x24);
}

s32 func_800964D0(PlayerState *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[42];
}

f32 func_800964DC(PlayerState *arg0) {
    f32 func_800C67D8(f32 *arg0);
    return func_800C67D8(*(*(f32 ***)((s8 *)arg0 + 0x94)));
}

s32 func_80096500(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0xA1];
}

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

s32 func_800966E0(void *arg0) {
    s32 func_800C67E8(s32);
    return func_800C67E8(*(*(s32 **)((s8 *)(arg0) + (0x94))));
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

/* extern */

s32 func_80096DD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800EE7F8(f32 *, s32);
    s32 func_80096ACC(f32 *, f32 *, s32, s32);
    f32 sp24[5];
    f32 sp18;

    func_800EE7F8(sp24 + 2, arg2);
    func_800EE7F8(&sp18, arg3);
    if (func_80096ACC(sp24 + 2, &sp18, arg0, arg1) == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_80096E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6F080/func_8009700C.s")

/* extern */

s32 func_800970A4(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EE7B4(f32 dst[3], f32 a[3], f32 b[3], f32 scale);
    void *func_800C6A7C(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 flags);
    s32 var_v1;
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7B4(sp28, arg0, arg1, arg2);
    if (func_800C6A7C(arg0, sp28, sp1C, 0x420025) != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

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
