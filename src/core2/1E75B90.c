#include "common.h"

void func_8009C2A0(BtIntPtr arg0, s32 arg1, BtIntPtr arg2) {
    void func_800DBEFC(s32 *, s32, BtIntPtr);
    extern s16 D_80117F02[2];
    func_800DBEFC((s32 *) arg0, *(s16 *)((u8 *)D_80117F02 + arg1 * 4), arg2);
}
