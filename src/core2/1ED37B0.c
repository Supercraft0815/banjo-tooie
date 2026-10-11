#include "common.h"

/* extern */

void func_800F9EC0(s32 arg0, s32 arg1) {
    s32 func_800F9F04(s32);
    s32 func_800F9F2C(s32, s32);
    s32 func_800FC660(s32);
    if (arg1 < 0) {
        func_800FC660(0x74);
    }
    func_800F9F2C(arg0, func_800F9F04(arg0) + arg1);
}

s32 func_800F9F04(s32 arg0) {
    extern s32 D_80135530[];
    return *(s16 *)((char *)D_80135530 + (arg0 << 2));
}

s32 func_800F9F18(s32 arg0) {
    extern s16 D_80135532[];
    return *(s16 *)((char *)D_80135532 + (arg0 << 2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED37B0/func_800F9F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED37B0/func_800F9F74.s")
