#include "common.h"

void func_800D5250()
{
    func_800D52B0();
}

void func_800D5270(void)
{
    extern u8 D_8012B431;

    D_8012B431 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAEB40/func_800D527C.s")

u32 func_800D5298(void) {
    extern u8 D_8012B431;
    return *(u8 *)((u8 *)&D_8012B431 + 0);
}

u32 func_800D52A4(void) {
    extern u8 D_8012B430;
    return *(u8 *)((u8 *)&D_8012B430 + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAEB40/func_800D52B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAEB40/func_800D52CC.s")

s32 func_800D52F4(void) {
    extern s16 D_8012B432;
    return *(s16 *)((u8 *)&D_8012B432 + 0);
}

void func_800D5300(s32 arg0, s32 arg1) {
}
void func_800D530C(s32 arg0, s32 arg1) {
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAEB40/func_800D5318.s")

s32 func_800D5424(s32 arg0) {
    return arg0 - 0x16;
}

s32 func_800D542C(s32 arg0) {
    return arg0 + 0x9A;
}
