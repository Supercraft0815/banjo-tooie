#include "core2/1EAAD80.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1490.s")

/* extern */

void func_800D1510(void) {
    extern s32 D_8012B250;
    void* heap_alloc_sided(s32 size, s32 alloc_side);
    s32 func_800D1490();
    s32 *state = &D_8012B250;
    state[1] = 0;
    D_8012B250 = heap_alloc_sided(0x2A, state[1]);
    func_800D1490();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D154C.s")

void func_800D15CC(void) {
    s32 defrag(s32);
    extern s32 D_8012B250;
    if (D_8012B250 != 0) {
        D_8012B250 = defrag(D_8012B250);
    }
}

void func_800D1604(void) {
    s32 heap_free(s32);
    extern s32 D_8012B250;
    heap_free(D_8012B250);
    D_8012B250 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D162C.s")

s32 func_800D16C4(s32 arg0)
{
    return arg0 - 0x40;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D16CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D175C.s")

void func_800D1804(s32 arg0) {
    func_800D175C(arg0, -1);
}

void func_800D1824(s32 arg0)
{
    func_800D175C(arg0,0);
}

void func_800D1844(s32 arg0)
{
    func_800D175C(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1864.s")

void func_800D192C(s32 arg0, u32 arg1) {
    func_800D1864((u32) arg0, func_800D1A04(arg0), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1960.s")

s32 func_800D1A04(s32 a0) {
    extern struct { s16 value; s16 padding; } D_8011AF52[];
    extern s32 D_8012B250;
    s32 index;

    index = func_800D16C4(a0);
    if (D_8011AF52[index].value == -2) {
        return 0x3E7;
    }
    return ((s16 *)D_8012B250)[index] ^ ((s16 *)&func_800D1A04)[index * 4];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1ACC.s")

s32 func_800D1B34(s32 arg0) {
    switch (arg0) {
    case 0x29F:
        return 0x48;
    case 0x523:
        return 0x54;
    case 0x1D9:
        return 0x4F;
    case 0x3CA:
        return 0x4B;
    case 0x3CB:
        return 0x4C;
    case 0x40D:
    case 0x481:
        return 0x50;
    case 0x4E2:
        return 0x4D;
    case 0x4E3:
        return 0x4A;
    case 0x4E4:
        return 0x4E;
    case 0x4BA:
    case 0x4D7:
        return 0x51;
    case 0x515:
    case 0x516:
        return 0x52;
    case 0x4B7:
        return 0x49;
    default:
        return 0;
    }
}

s32 func_800D1C38(s32 arg0) {
    return func_800D1A04(arg0) == 0;
}

s32 func_800D1C5C(u32 arg0) {
    extern s16 D_8011AE50[];
    return *(s16 *)((u8 *)D_8011AE50 + (arg0 << 2));
}

s32 func_800D1C70() 
{
    return 0x2A;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAAD80/func_800D1F34.s")
