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

void func_8001D3D8(s16 arg0, s16 arg1, s32 arg2, ...) {
    void *args;
    extern s32 D_8007D160;
    void func_8001D9CC(u16, u16);
    s32 _Printf(s32 (*)(s32, s32, s32), s32, s32, void *);
    D_8007D160 = 1;
    func_8001D9CC(arg0, arg1);
    args = (void *) (((s32) &arg2 + 7) & ~3);
    _Printf(func_8001D340, 0, arg2, args);
}
