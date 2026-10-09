#include "core2/1ECA640.h"

f32 func_800F0D50(f32 value, f32 min, f32 max) {
    if (value < min) {
        return min;
    }
    if (max < value) {
        return max;
    }
    return value;
}

s32 func_800F0D90(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 < arg1) {
        return arg1;
    }
    if (arg2 < arg0) {
        return arg2;
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0DC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F101C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F10B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1198.s")

f32 func_800F11E4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return (((arg0 - arg1) / (arg2 - arg1)) * (arg4 - arg3)) + arg3;
}

f32 func_800F1214(f32 value, f32 min, f32 max) {
    return ((max - min) * value) + min;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F122C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F12D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F130C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1344.s")

f32 func_800F13C4(f32 arg0, f32 arg1) {
    f32 temp_f2;

    temp_f2 = arg0 / arg1;
    return (temp_f2 - (f32) (s32) temp_f2) * arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F13F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1434.s")

/* extern */

void func_800F1480(f32 arg0) {
    s32 func_80013970(f32);
    func_80013970(arg0 * 90.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F14AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F14D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F14FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F15C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F15F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F16AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1738.s")
