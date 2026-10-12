#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8B70/func_8010F280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8B70/func_8010F384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8B70/func_8010F68C.s")

void func_8010F950(s32 *arg0, s32 arg1, volatile s32 arg2, s32 arg3) {
    s32 func_800DF8B4(s32 *);
    s32 func_800DF8BC(s32 *);
    void func_8010F384(s32 *, s32, s32);
    void func_8010F68C(s32, s32);
    extern s32 *D_80137240[3];
    extern s32 D_80137250;
    s32 temp;
    s32 sp18;

    D_80137240[0] = arg0;
    D_80137240[2] = &D_80137250;
    func_8010F384(arg0, arg1, arg3);
    sp18 = func_800DF8B4(D_80137240[0]); temp = func_800DF8BC(D_80137240[0]);
    func_8010F68C(sp18, temp);
}
