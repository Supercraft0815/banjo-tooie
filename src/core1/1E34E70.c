#include "common.h"

s32 func_8001D340(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8001DA00(s32, s32);
    extern s32 D_8007D160;
    if (D_8007D160 & 1) {
        func_8001DA00(arg1, arg2);
    }
    return 1;
}

void func_8001D37C(s32 arg0, ...) {
    void *args;
    extern s32 D_8007D160;
    s32 _Printf(s32 (*)(s32, s32, s32), s32, s32, void *);
    D_8007D160 = 1;
    args = (void *) (((s32) &arg0 + 7) & ~3);
    _Printf(func_8001D340, 0, arg0, args);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E34E70/func_8001D3D8.s")
