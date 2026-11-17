#include "common.h"

s32 func_80027220(s16 arg0, BtIntPtr arg1, BtIntPtr arg2) {
    void func_80028DF0(void *, BtIntPtr, s16, BtIntPtr);
    extern s32 *D_800411F4;

    func_80028DF0((u8 *)D_800411F4[13] + arg0 * 0x48 + 0x24, arg1, arg0, arg2);
    return *(s32 *)((u8 *)D_800411F4[13] + arg0 * 0x48 + 0x24);
}
