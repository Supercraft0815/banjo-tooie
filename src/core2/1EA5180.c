#include "common.h"

extern s32 D_8012AE80;

s32 func_800CB890(s16 *arg0) {
    extern u8 *D_8012AF60;
    s32 func_800B42A0(u8 *, s16 *);
    return func_800B42A0(D_8012AF60, arg0 + 12);
}

s32 func_800CB8BC(s16 *arg0) {
    return arg0[13] * 0x18 + func_800CB890(arg0);
}

s32 func_800CB8F0(s16 *arg0)
{
    return func_800CB890(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CB910.s")

void *func_800CB948()
{
    func_800CB910();
}

void func_800CB968(s16 *arg0)
{
    func_800CB8BC(arg0);
}

void func_800CB988()
{
    _gcboundDll_entrypoint_0(&D_8012AE80);
}

void func_800CB9AC(void) {
}

void func_800CB9B4()
{
    _gcboundDll_entrypoint_1(&D_8012AE80);
}

void func_800CB9D8()
{
    _gcboundDll_entrypoint_2(&D_8012AE80);
}

void func_800CB9FC()
{
    _gcboundDll_entrypoint_6(&D_8012AE80);
}

void func_800CBA20()
{
    _gcboundDll_entrypoint_7(&D_8012AE80);
}

void func_800CBA44()
{
    _gcboundDll_entrypoint_8(&D_8012AE80);
}

/* extern */

void func_800CBA68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 _gcboundDll_entrypoint_3(s32 *, s32, s32, s32, s32, s32, s32, s32);
    _gcboundDll_entrypoint_3(&D_8012AE80, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

/* extern */

void func_800CBAC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _gcboundDll_entrypoint_4(s32 *, s32, s32, s32, s32, s32);
    _gcboundDll_entrypoint_4(&D_8012AE80, arg0, arg1, arg2, arg3, arg4);
}

/* extern */

void func_800CBB18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 _gcboundDll_entrypoint_5(s32 *, s32, s32, s32, s32, s32, s32);
    _gcboundDll_entrypoint_5(&D_8012AE80, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_800CBB70(s32 arg0, s32 arg1) {
    extern s32 D_8012AE98;
    *(s8 *)((u8 *)&D_8012AE98 + arg0) = arg1;
}

void func_800CBB80(s32 arg0, s32 arg1) {
    extern s32 D_8012AE8C;
    struct Entry {
        u16 prefix;
        u8 other : 7;
        u8 flag : 1;
        u8 rest[25];
    } *entry;

    entry = (struct Entry *)(D_8012AE8C + arg0 * 0x1C);
    if (arg1 != 0) {
        entry->flag = 1;
        return;
    }
    entry->flag = 0;
}

s32 func_800CBBC0(s32 arg0) {
    extern s32 D_8012AE8C;
    s32 *entry;
    entry = (s32 *)(D_8012AE8C + arg0 * 0x1C);
    return entry[5];
}

s32 func_800CBBE0(s32 arg0) {
    extern s32 D_8012AE94;
    s32 *entry;
    entry = (s32 *)(D_8012AE94 + arg0 * 0x1C);
    return entry[5];
}

s32 func_800CBC00(s32 arg0) {
    extern s32 D_8012AE94;
    return (*(u16 *)((s8 *)(func_800CB8F0((arg0 * 0x1C) + D_8012AE94)) + (0x14))) & 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CBC3C.s")

/* extern */

s32 func_800CBD84(s32 arg0) {
    s32 func_800CBC3C();
    s32 func_800CC4D4(s32, s32);
    s32 sp1C;
    s32 var_a1;

    var_a1 = func_800CBC3C();
    if (var_a1 != -1) {
        if (func_800CC4D4(arg0, (sp1C = var_a1)) != -1) {
            return -1;
        }
        var_a1 = sp1C;
    }
    return var_a1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CBDD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CC078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CC338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CC4D4.s")

s32 func_800CC5E8()
{
    return D_8012AE80;
}

u32 func_800CC5F4(s32 arg0) { extern s32 D_8012AE84; return (u32)*(u32 *)(D_8012AE84 + arg0 * 0x1C) >> 9; }

u8 func_800CC61C(s32 arg0) {
    extern s32 D_8012AE84;
    return (*(u8 *)((s8 *)(((arg0 * 0x1C) + D_8012AE84)) + (3)));
}

void *func_800CC63C(s32 arg0, s32 arg1)
{
    extern s32 D_8012AE84;
    return (s8 *)func_800CB8F0((arg0 * 0x1C) + D_8012AE84) + (arg1 * 0x18);
}

void *func_800CC684(s32 arg0, s32 arg1)
{
    extern s32 D_8012AE84;
    return (s8 *)func_800CB948((arg0 * 0x1C) + D_8012AE84) + (arg1 * 0x18);
}

/* extern */

s32 func_800CC6CC(void) {
    void *func_800CC63C();
    return (*(u16 *)((s8 *)(func_800CC63C()) + (0x14))) & 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CC6F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CCAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CCDF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CCEF4.s")

void func_800CCFEC(void) {
    s32 defrag(s32);
    extern s32 D_8012AE80;
    if ((*(s32 *)((s8 *)(&D_8012AE80) + (4))) != 0) {
        (*(s32 *)((s8 *)(&D_8012AE80) + (4))) = defrag((*(s32 *)((s8 *)(&D_8012AE80) + (4))));
    }
    if ((*(s32 *)((s8 *)(&D_8012AE80) + (0xC))) != 0) {
        (*(s32 *)((s8 *)(&D_8012AE80) + (0xC))) = defrag((*(s32 *)((s8 *)(&D_8012AE80) + (0xC))));
    }
    if ((*(s32 *)((s8 *)(&D_8012AE80) + (0x14))) != 0) {
        (*(s32 *)((s8 *)(&D_8012AE80) + (0x14))) = defrag((*(s32 *)((s8 *)(&D_8012AE80) + (0x14))));
    }
    if ((*(s32 *)((s8 *)(&D_8012AE80) + (0xE0))) != 0) {
        (*(s32 *)((s8 *)(&D_8012AE80) + (0xE0))) = defrag((*(s32 *)((s8 *)(&D_8012AE80) + (0xE0))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA5180/func_800CD08C.s")

/* extern */

void func_800CD1E0(s32 arg0, u8 *arg1, f32 arg2) {
    func_800CD08C(arg0, arg1);
    if ((*(f32 *)((s8 *)(arg1) + (4))) < arg2) {
        (*(f32 *)((s8 *)(arg1) + (4))) = arg2;
    }
}
