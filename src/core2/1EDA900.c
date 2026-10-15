#include "core2/1EDA900.h"
extern void *D_80135A80;

void func_80101010(s32 arg0) {
    s32 func_800EE7F8(s32 *, s32);
    extern s32 D_80135A70;
    func_800EE7F8(&D_80135A70, arg0);
}

void func_80101038(s32 *arg0) {
    s32 func_800EE7F8();
    extern s32 D_80135A70;
    func_800EE7F8(arg0, &D_80135A70);
}

void func_8010105C(f32 arg0) {
    extern f32 D_80135A7C;
    *(f32 *)((u8 *)&D_80135A7C + 0) = arg0;
}

f32 func_80101068(void) {
    extern f32 D_80135A7C;
    return *(f32 *)((u8 *)&D_80135A7C + 0);
}

void func_80101074(void *arg0)
{
    D_80135A80 = arg0;
}

void *func_80101080()
{
    return D_80135A80;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_8010108C.s")

s32 func_8010114C(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8010108C();
    return func_8010108C(func_80106790(arg0), arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801012D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801013A8.s")
