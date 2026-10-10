#include "core2/1E7AB30.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1364.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1658.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A16BC.s")

void func_800A16F4(s32 arg0) {
    s32 _batimer_set(s32, s32, s32);
    _batimer_set(arg0, 0xE, 0x40400000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A17A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A1870.s")

/* extern */

void func_800A18C8(void *arg0) {
    s32 func_800F9F74(s32);
    func_800F9F74((*(s32 *)((s8 *)(arg0) + (0x184))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7AB30/func_800A18E8.s")
