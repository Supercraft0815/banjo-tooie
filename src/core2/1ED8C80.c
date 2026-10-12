#include "core2/1ED8C80.h"

void func_800FF390(void) {
    s32 func_80104170();
    s32 func_80104350();
    s32 func_80105410();
    s32 func_80105C20();
    s32 func_801065E0();
    s32 func_80106A20();
    s32 func_80106DF0();
    s32 func_80107BB0();
    extern s32 D_80135A50;
    D_80135A50 = 0;
    func_801065E0();
    func_80104170();
    func_80104350();
    func_80105410();
    func_80105C20();
    func_80106A20();
    func_80106DF0();
    func_80107BB0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF3EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF4A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFA3C.s")

void func_800FFA88(Unk80132ED0* a0)
{
    func_800FFAB0(func_80106790(a0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFB74.s")

void func_800FFBE4(void) {
}

void func_800FFBEC()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC14()
{
    func_800FFC3C();
    func_8010DEFC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFC3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFDBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFECC.s")

u32* func_80100074(Actor* a0, u32 a1, u32 a2)
{
    return func_800FFECC(a0,a1,a2);
}

void *func_80100094(Actor *arg0, u32 arg1) {
    s32 func_8001B798(s16);
    s16 temp;
    s32 result;
    temp = *(s16 *)((u8 *)arg0 + 0x82 + arg1 * 2);
    result = 0;
    if (temp != 0) {
        return (void *) func_8001B798(temp);
    }
    return (void *) result;
}

s32 func_801000D8(Actor *arg0, s32 arg1, s32 arg2) {
    if (func_80100094(arg0, (u32) arg1) == NULL) {
        func_80100074(arg0, (u32) arg1, (u32) arg2);
    }
    return func_80100094(arg0, (u32) arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_80100120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_801001D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_80100230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_801002C0.s")

void *func_80100368(void *arg0) {
    return (*(void *(**)())((s8 *)(arg0) + (0x10)))();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_8010038C.s")
