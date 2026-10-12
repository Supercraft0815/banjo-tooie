#include "common.h"

/* extern */

void func_800F9EC0(s32 arg0, s32 arg1) {
    s32 func_800F9F04(s32);
    void func_800F9F2C(s32, s32);
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

void func_800F9F2C(s32 arg0, s32 arg1) {
    extern s32 D_80135530[];
    s16 *var_v0;
    s16 temp_v1;
    if (arg1 < 0) {
        var_v0 = (s16 *)((char *)D_80135530 + (arg0 << 2));
        arg1 = 0;
    } else {
        var_v0 = (s16 *)((char *)D_80135530 + (arg0 << 2));
        temp_v1 = (*(s16 *)((s8 *)(var_v0) + 2));
        if (temp_v1 < arg1) {
            arg1 = temp_v1;
        }
    }
    *var_v0 = arg1;
}

void func_800F9F74(s32 arg0, s32 arg1) {
    extern s16 D_80135532[];
    *(s16 *)((char *)D_80135532 + (arg0 << 2)) = arg1;
}
