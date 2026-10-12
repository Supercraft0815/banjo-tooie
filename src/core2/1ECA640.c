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

f32 func_800F0DC0(f32 arg0, f32 arg1) {
    f32 temp_f2;

    if (arg1 < arg0) {
        return arg1;
    }
    temp_f2 = -arg1;
    if (arg0 < temp_f2) {
        return temp_f2;
    }
    return arg0;
}

f32 func_800F0E00(f32 arg0, f32 arg1) {
    f32 result;
    if (arg1 < arg0) {
        result = arg0;
    } else {
        result = arg1;
    }
    return result;
}

s32 func_800F0E28(s32 arg0, s32 arg1) {
    s32 result;
    if (arg1 < arg0) {
        result = arg0;
    } else {
        result = arg1;
    }
    return result;
}

s32 func_800F0E44(s32 arg0) {
    if (arg0 < 0) {
        do {
            arg0 += 0x168;
        } while (arg0 < 0);
    }
    if (arg0 >= 0x168) {
        do {
            arg0 -= 0x168;
        } while (arg0 >= 0x168);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F0EF0.s")

f32 func_800F0F9C(f32 val1, f32 val2)
{
    f32 func_800F13C4(f32 arg0, f32 arg1);

    return func_800F13C4(val1, val2) / val2;
}

f32 func_800F0FC4(f32 value, f32 period) {
    f32 func_80013970(f32);
    f32 func_800F13C4(f32, f32);
    f32 phase = func_800F13C4(value, period) / period;
    return (func_80013970(phase * 360.0f) + 1.0f) / 2.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F101C.s")

f32 func_800F1074(f32 value, f32 period) {
    f32 func_800F13C4(f32, f32);
    f32 func_80013970(f32);
    return func_80013970((func_800F13C4(value, period) / period) * 360.0f);
}

f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max) {
    f32 var_f16;

    if (in_max != in_min) {
        if (out_min < out_max) {
            var_f16 = (((value - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;
            if (out_max < var_f16) {
                return out_max;
            }
            if (var_f16 < out_min) {
                return out_min;
            }
            goto block_10;
        }
        var_f16 = (((value - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;
        if (var_f16 < out_max) {
            return out_max;
        }
        if (out_min < var_f16) {
            return out_min;
        }
block_10:
        return var_f16;
    }
    return out_max;
}

f32 func_800F1198(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    if (arg2 != arg1) {
        return (((arg0 - arg1) / (arg2 - arg1)) * (arg4 - arg3)) + arg3;
    }
    return arg4;
}

f32 func_800F11E4(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return (((arg0 - arg1) / (arg2 - arg1)) * (arg4 - arg3)) + arg3;
}

f32 func_800F1214(f32 value, f32 min, f32 max) {
    return ((max - min) * value) + min;
}

/* extern */

f32 func_800F122C(f32 arg0, f32 arg1, f32 arg2) {
    f32 func_800F2108();
    f32 temp_f0;

    temp_f0 = func_800F2108();
    arg0 *= temp_f0;
    { f32 temp_f1 = ((arg2 - arg1) * arg0) + arg1; return temp_f0 * temp_f1; }
}

f32 func_800F1274(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 (*arg5)(f32)) {
    return func_800F10B4(arg5(func_800F10B4(arg0, arg1, arg2, 0.0f, 1.0f)), 0.0f, 1.0f, arg3, arg4);
}

f32 func_800F12D4(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    f32 func_800F1274(f32 a, f32 b, f32 c, f32 d, f32 e, f32 (*func)(f32));

    f32 func_800F1434(f32);
    return func_800F1274(a, b, c, d, e, func_800F1434);
}

f32 func_800F130C(f32 a, f32 b, f32 c, f32 d, f32 e)
{
    f32 func_800F1274(f32 a, f32 b, f32 c, f32 d, f32 e, f32 (*func)(f32));
    f32 func_800F14AC(f32 val);

    return func_800F1274(a, b, c, d, e, func_800F14AC);
}

void func_800F1344(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    if (arg0 < 0.0f) {
        func_800F10B4(arg0, -arg1, -arg2, -arg3, -arg4);
        return;
    }
    func_800F10B4(arg0, arg1, arg2, arg3, arg4);
}

f32 func_800F13C4(f32 arg0, f32 arg1) {
    f32 temp_f2;

    temp_f2 = arg0 / arg1;
    return (temp_f2 - (f32) (s32) temp_f2) * arg1;
}

f32 func_800F13F0(f32 arg0, f32 arg1) {
    f32 result;
    if (arg0 < arg1) {
        result = arg0;
        goto done;
    }
    result = arg1;
done:
    return result;
}

s32 func_800F1418(s32 arg0, s32 arg1) {
    return arg0 < arg1 ? arg0 : arg1;
}

f32 func_800F1434(f32 arg0) {
    f32 func_8001395C(f32);
    extern f32 D_80125EC0;
    extern f32 D_80125EC4;
    return (func_8001395C((arg0 * D_80125EC0) + D_80125EC4) + 1.0f) * 0.5f;
}

/* extern */

void func_800F1480(f32 arg0) {
    f32 func_80013970(f32);
    func_80013970(arg0 * 90.0f);
}

f32 func_800F14AC(f32 arg0) {
    return func_800F1434(func_800F1434(arg0));
}

f32 func_800F14D4(f32 arg0, f32 arg1) {
    f32 result;
    if (arg0 <= arg1) {
        result = arg0;
    } else {
        result = arg1;
    }
    return result;
}

f32 func_800F14FC(f32 arg0, f32 arg1, f32 arg2) {
    f32 temp_f2;

    if (arg2 < arg0) {
        return 0.0f;
    }
    if (arg1 <= arg2) {
        return 1.0f;
    }
    temp_f2 = (arg2 - arg0) / (arg1 - arg0);
    return temp_f2 * temp_f2 * (3.0f - (2.0f * temp_f2));
}

s32 func_800F1574(f32 *timer, f32 delta) {
    if (*timer > 0) {
        *timer -= delta;

        if (*timer <= 0) {
            *timer = 0;
            return 1;
        }
    }

    return 0;
}

f32 func_800F15C4(f32 arg0, s32 arg1) {
    f32 var_f2;
    s32 temp_t7;

    var_f2 = 1.0f;
    if (arg1 != 0) do {
        if (arg1 & 1) var_f2 *= arg0;
        temp_t7 = arg1 >> 1;
        arg0 *= arg0;
        arg1 = temp_t7;
    } while (arg1 != 0);
    return var_f2;
}

f32 func_800F15F8(f32 arg0, f32 arg1, f32 arg2) {
    if (arg0 < arg1) {
        return func_800F13F0(arg0 + arg2, arg1);
    }
    if (arg1 < arg0) {
        return func_800F0E00(arg0 - arg2, arg1);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F16AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ECA640/func_800F1738.s")
