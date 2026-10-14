#include "common.h"

void func_8008B610(void) {
    s32 func_8008BBC0(s32, s32);
    s32 heap_alloc(s32);
    extern s32 D_80126CC0;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = heap_alloc(0x3C);
    temp_a1 = temp_v0 + 0x3C;
    (*(s32 *)((s8 *)(&D_80126CC0) + (0))) = temp_v0;
    (*(s32 *)((s8 *)(&D_80126CC0) + (4))) = temp_a1;
    func_8008BBC0(temp_v0, temp_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B64C.s")

void func_8008B6E0(void) {
    void func_800DFCC0(s16);
    extern s32 D_80126CC0;
    s16 temp_a0;
    s16 *var_s0;

    var_s0 = (s16 *)D_80126CC0;
    while (var_s0 < *(s16 **)((s8 *)&D_80126CC0 + 4)) {
            if (var_s0[2] != 0) {
                temp_a0 = var_s0[0];
                if ((temp_a0 != 0) && (var_s0[1] < 0x3B)) {
                    func_800DFCC0(temp_a0);
                    var_s0[0] = 0;
                }
            }
            var_s0 += 3;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B850.s")

s16 func_8008B8E0(void) {
    s16 func_8008BAC0(s32 *);
    s32 sp1C;
    s16 *temp_v0;

    temp_v0 = (s16 *)func_8008BAC0(&sp1C);
    temp_v0[1] = 0;
    temp_v0[0] = 0;
    return *(s16 *)((s8 *)&sp1C + 2);
}

s32 func_8008B90C(s16 arg0) {
    extern s32 D_80126CC0;
    s16 *entry;
    entry = (s16 *)(D_80126CC0 + arg0 * 6 - 6);
    return entry[0] ? 1 : 0;
}

void func_8008B954(s16 arg0) {
    extern s32 D_80126CC0;
    void func_800DFCC0(s16 arg0);
    s16 *entry;
    entry = (s16 *)(D_80126CC0 + arg0 * 6 - 6);
    if (entry[0] != 0) {
        func_800DFCC0(entry[0]);
        entry[0] = 0;
    }
    entry[2] = 0;
    entry[1] = entry[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008B9C4.s")

void func_8008BA5C(void) {
    s32 defrag(s32);
    extern s32 D_80126CC0;
    s32 sp1C;
    s32 temp_v0;

    sp1C = (s32) ((*(s32 *)((s8 *)(&D_80126CC0) + (4))) - (*(s32 *)((s8 *)(&D_80126CC0) + (0)))) / 6;
    temp_v0 = defrag((*(s32 *)((s8 *)(&D_80126CC0) + (0))));
    (*(s32 *)((s8 *)(&D_80126CC0) + (0))) = temp_v0;
    (*(s32 *)((s8 *)(&D_80126CC0) + (4))) = (sp1C * 6) + D_80126CC0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BAC0.s")

 s32 func_8008BBC0(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = arg0;
    if ((u32) arg0 < (u32) arg1) {
        do {
            (*(s16 *)((s8 *)var_v0)) = 0;
            (*(s16 *)((s8 *)var_v0 + 2)) = ((*(s16 *)((s8 *)var_v0 + 4)) = 0);
            var_v0 += 6;
        } while ((u32) var_v0 < (u32) arg1);
    }
}

/* extern */

void func_8008BBF0(s32 arg0, s32 arg1) {
    s32 func_800DFAD0(s32 *);
    s32 func_8008B9C4(s16, s32 *);
    s32 sp1C;

    if (func_8008B9C4((*(s16 *)((s8 *)arg0 + (arg1 << 1) + 0xA)), &sp1C) == 0) {
        func_800DFAD0((s32 *)sp1C);
    }
}

void func_8008BC2C(u8 *arg0) {
    func_8008BBF0(arg0, arg0[8]);
}

void func_8008BC4C(s32 arg0)
{
    func_8008BBF0(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BC6C.s")

/* extern */

void func_8008BC94(u8 *arg0) {
    s32 func_8008BC6C(u8 *, u8);
    func_8008BC6C(arg0, arg0[8]);
}

void func_8008BCB4(u8 *arg0) {
    s32 func_8008BC6C(u8 *, u8);
    u8 value;

    value = arg0[8] ? 0 : 1;
    func_8008BC6C(arg0, value);
}

/* extern */

s32 func_8008BCEC(s32 arg0, s32 arg1) {
    s32 func_8008B9C4(s16, s32 *);
    s32 sp1C;

    func_8008B9C4((*(s16 *)((s8 *)arg0 + 0xA + (arg1 << 1))), &sp1C);
    return sp1C;
}

s32 func_8008BD1C(s32 arg0) {
    return func_8008BCEC(arg0, *(u8 *)(arg0 + 8));
}

void func_8008BD3C(s32 arg0) {
    s32 value;

    value = *(u8 *)(arg0 + 8) ? 0 : 1;
    func_8008BCEC(arg0, value);
}

void func_8008BD74(s32 arg0)
{
    func_8008BCEC(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008BEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008C038.s")

void func_8008C0AC(s8 *arg0)
{
    arg0[0x1B] = 1;
}

s32 func_8008C0B8(void)
{
	return 0x20;
}

s32 func_8008C0C0(s16 *arg0)
{
    return arg0[12];
}

f32 func_8008C0C8(f32 *arg0)
{
    return arg0[4];
}

f32 func_8008C0D0(f32 *arg0)
{
    return arg0[5];
}

/* extern */

void func_8008C0D8(void *arg0) {
    void func_8008B954(s16);
    func_8008B954((*(s16 *)((s8 *)(arg0) + (0xA))));
    func_8008B954((*(s16 *)((s8 *)(arg0) + (0xC))));
    if ((*(u8 *)((s8 *)(arg0) + (0x1C))) == 1) {
        func_8008B954((*(s16 *)((s8 *)(arg0) + (0xE))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E64F00/func_8008C124.s")

void func_8008C1B8(s16 *arg0, s32 arg1) {
    arg0[12] = arg1;
}

void func_8008C1C0(f32 *arg0, f32 arg1) {
    arg0[4] = arg1;
}

void func_8008C1CC(s8 *arg0, s32 arg1) {
    arg0[30] = arg1;
}

void func_8008C1D4(s32 *arg0, s32 arg1) {
    arg0[0] = arg1;
}

void func_8008C1DC(s32 *arg0, s32 arg1) {
    arg0[1] = arg1;
}

void func_8008C1E4(f32 *arg0, f32 arg1) {
    arg0[5] = arg1;
}

void func_8008C1F0(void *arg0, s32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x1A))) = 1;
}

/* extern */

void func_8008C200(s16 arg0, s32 arg1, s32 arg2) {
    s32 func_8008BD1C(s32);
    s32 func_800AE1E8(s16, s32, s32);
    func_800AE1E8(arg0, arg1, func_8008BD1C(arg2));
}

/* extern */

void func_8008C238(s16 arg0, s32 arg1, s32 arg2) {
    s32 func_8008BD1C(s32);
    s32 func_800AE290(s16, s32, s32);
    func_800AE290(arg0, arg1, func_8008BD1C(arg2));
}

void func_8008C270(s8 *arg0) {
    arg0[0x1B] = 2;
}

/* extern */

void func_8008C27C(void) {
    s32 func_8008BD1C();
    func_8008BD1C();
}
