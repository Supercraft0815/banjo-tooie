#include "common.h"

s32 func_80027220(s16 arg0, s32 arg1, s32 arg2) {
    void func_80028DF0(void *, s32, s16, s32);
    extern s32 *D_800411F4;

    func_80028DF0((u8 *)D_800411F4[13] + arg0 * 0x48 + 0x24, arg1, arg0, arg2);
    return *(s32 *)((u8 *)D_800411F4[13] + arg0 * 0x48 + 0x24);
}
