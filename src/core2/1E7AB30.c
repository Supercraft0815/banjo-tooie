#include "core2/1E7AB30.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1294.s")

/* extern */

void func_800A1364(void) {
    extern s8 D_80127090;
    u32 func_8009E958(void);
    s32 func_800A1240(u32);
    s32 func_800D517C();
    (*(s8 *)((s8 *)(&D_80127090) + (1))) = 0;
    (*(s8 *)((s8 *)(&D_80127090) + (0))) = 0;
    func_800D517C();
    func_800A1240(func_8009E958());
}

void func_800A13A0(void) {
    extern s8 D_80127090;
    D_80127090 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A13B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1450.s")

void func_800A1618(s32 arg0) {
    extern s8 D_80127092;
    *(s8 *)((u8 *)&D_80127092 + 0) = arg0;
}

/* extern */

void func_800A1624(s32 arg0) {
    s32 func_800A1294(s32);
    s32 func_800D284C(s32);
    if (arg0 != 0) {
        func_800A1294(0);
        return;
    }
    func_800D284C(0xCF);
}

void func_800A1658(s32 arg0) {
    extern s8 D_80127090;
    if ((arg0 != (*(u8 *)((s8 *)(&D_80127090) + (6)))) || (((*(u8 *)((s8 *)(&D_80127090) + (8))) != 0) && (arg0 != (*(u8 *)((s8 *)(&D_80127090) + (8)))))) {
        (*(s8 *)((s8 *)(&D_80127090) + (7))) = 1;
        (*(u8 *)((s8 *)(&D_80127090) + (8))) = (u8) arg0;
    }
}

void func_800A1694(void) {
    extern u8 D_80127097;
    D_80127097 = 2;
}

u32 func_800A16A4(void) {
    extern u8 D_80127097;
    return *(u8 *)((u8 *)&D_80127097 + 0);
}

u32 func_800A16B0(void) {
    extern u8 D_80127099;
    return *(u8 *)((u8 *)&D_80127099 + 0);
}

void func_800A16BC(s32 arg0) {
    extern s8 D_80127090;
    if (arg0 != 0) {
        (*(u8 *)((s8 *)(&D_80127090) + (5))) = (u8) ((*(u8 *)((s8 *)(&D_80127090) + (5))) + 1);
        return;
    }
    (*(u8 *)((s8 *)(&D_80127090) + (5))) = (u8) ((*(u8 *)((s8 *)(&D_80127090) + (5))) - 1);
}

void func_800A16F4(s32 arg0) {
    s32 _batimer_set(s32, s32, s32);
    _batimer_set(arg0, 0xE, 0x40400000);
}

/* extern */

s32 func_800A1718(PlayerState *arg0) {
    s32 func_800F9F04(s32);
    s32 func_800A3274(PlayerState *);
    s32 func_800D4E7C(s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) != 0) {
        return func_800F9F04(arg0->unk184);
    }
    return func_800D4E7C(func_800A3274(arg0));
}

/* extern */

s32 func_800A1760(PlayerState *arg0) {
    s32 func_800F9F18(s32);
    s32 func_800A3274(PlayerState *);
    s32 func_800D4EB8(s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x158))) != 0) {
        return func_800F9F18(arg0->unk184);
    }
    return func_800D4EB8(func_800A3274(arg0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A17A8.s")

/* extern */

void func_800A1870(PlayerState *arg0, s32 arg1) {
    s32 func_800A1294(s32);
    void func_800F9F2C(s32, s32);
    s32 func_800A3274(PlayerState *);
    s32 func_800D4FB8(s32, s32);
    if ((*(s32 *)((s8 *)arg0 + 0x158)) != 0) {
        func_800F9F2C(arg0->unk184, arg1);
        return;
    }
    func_800D4FB8(func_800A3274(arg0), arg1);
    func_800A1294(1);
}

/* extern */

void func_800A18C8(void *arg0) {
    s32 func_800F9F74(s32);
    func_800F9F74((*(s32 *)((s8 *)(arg0) + (0x184))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A18E8.s")
