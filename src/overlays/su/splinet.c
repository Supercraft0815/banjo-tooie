#include "common.h"

typedef struct { u8 pad0[0x30]; s16 unk30; s16 unk32; s16 unk34; u8 pad36[0xE]; f32 unk44; f32 unk48; u8 pad4C[0x2]; s16 unk4E; u8 pad50[0x1]; u8 unk51; u8 unk52; u8 pad53[0x1]; s32 unk54; } Objsplinet_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void susplinet_entrypoint_0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 *temp_v1;
    s16 *temp_v1_2;
    s16 temp_a0;
    u8 *temp_v0;

    temp_v0 = arg0;
    temp_v0 += ((Objsplinet_arg0 *)arg0)->unk32;
    if (arg3 != 0) {
        temp_v1 = (s16 *)((s8 *)temp_v0 + (arg1 * 2));
        *temp_v1 |= arg2;
        return;
    }
    temp_v1_2 = (s16 *)((s8 *)temp_v0 + (arg1 * 2));
    temp_a0 = *temp_v1_2;
    if (temp_a0 & arg2) {
        *temp_v1_2 = temp_a0 - arg2;
    }
}

s32 func_80800048_susplinet(s16 *arg0, s32 arg1) {
    s8 *base = (s8 *)arg0;
    s16 *ptr;
    base += arg0[0x19];
    ptr = (s16 *)base;
    return ptr[arg1] & 4;
}

s32 func_80800068_susplinet(s16 *arg0, s32 arg1) {
    s8 *base = (s8 *)arg0;
    s16 *ptr;
    base += arg0[0x19];
    ptr = (s16 *)base;
    return ptr[arg1] & 2;
}

void susplinet_entrypoint_1(u8 *array, s32 index, s32 value) {
    u8 *ptr;
    if (value) {
        ptr = array + 0x50;
        *(ptr += index / 8) |= (1 << (index & 7));
    } else {
        ptr = array + 0x50;
        *(ptr += index / 8) &= ~(1 << (index & 7));
    }
}

int func_808000FC_susplinet(u8 *array, s32 index) {
    return ((array + 0x50)[index / 8] & (1 << (index & 7))) ? 1 : 0;
}

int susplinet_entrypoint_2(u8 *arg0) {
    BtIntPtr base = (BtIntPtr)arg0;
    s16 *ptr;
    base += ((Objsplinet_arg0 *)arg0)->unk30;
    ptr = (s16 *)base;
    return (f32)ptr[((Objsplinet_arg0 *)arg0)->unk4E - 1] <= ((Objsplinet_arg0 *)arg0)->unk44;
}

s16 susplinet_entrypoint_3(s8 *arg0) {
    BtIntPtr base = (BtIntPtr)arg0;
    base += *(s16 *)(arg0 + 0x30);
    return ((s16 *)base)[*(s16 *)(arg0 + 0x4E) - 1];
}

/* extern */

s32 susplinet_entrypoint_4(void *arg0, f32 arg1) {
    f32 func_800D8FF8(void);
    if ((((Objsplinet_arg0 *)arg0)->unk48 <= arg1) &&
        (arg1 < ((Objsplinet_arg0 *)arg0)->unk44 + func_800D8FF8() * 100.0f)) {
        return 1;
    }
    return 0;
}

s32 susplinet_entrypoint_5(void *arg0, f32 arg1) {
    if (((((Objsplinet_arg0 *)arg0)->unk48) <= arg1) && (arg1 < (((Objsplinet_arg0 *)arg0)->unk44))) {
        return 1;
    }
    return 0;
}

u32 susplinet_entrypoint_6(u8 *arg0) {
    return arg0[83];
}

void susplinet_entrypoint_7(f32 arg0[][3], s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg2, arg0[arg1]);
}

f32 susplinet_entrypoint_8(f32 *arg0, s32 arg1) {
    return (arg0 + arg1)[9];
}

f32 susplinet_entrypoint_9(f32 *arg0) {
    return arg0[17];
}

/* extern */

void susplinet_entrypoint_10(void *arg0, f32 arg1) {
    f32 temp_f0;
    s32 temp_v0;

    temp_v0 = susplinet_entrypoint_3(arg0);
    if (arg1 < 0.0f) {
        arg1 = 0.0f;
    }
    if ((((Objsplinet_arg0 *)arg0)->unk54) & 2) {
        temp_f0 = (f32) temp_v0;
        if (temp_f0 < arg1) {
            do {
                arg1 -= temp_f0;
            } while (temp_f0 < arg1);
        }
    }
    (((Objsplinet_arg0 *)arg0)->unk44) = arg1;
}

void susplinet_entrypoint_11(void *arg0, f32 arg1) {
    ((Objsplinet_arg0 *)arg0)->unk48 = arg1;
}

u8 *susplinet_entrypoint_12(u8 *arg0) {
    arg0 += *(s16 *)(arg0 + 0x30);
    return arg0;
}

u8 *susplinet_entrypoint_13(u8 *arg0) {
    arg0 += *(s16 *)(arg0 + 0x34);
    return arg0;
}

u8 *susplinet_entrypoint_14(u8 *arg0, s32 arg1) {
    return ((s16 *)(arg0 + 0x36))[arg1] + arg0;
}

BtIntPtr susplinet_entrypoint_15(BtIntPtr arg0, s32 arg1) {
    s16 *ptr = (s16 *)((s8 *)arg0 + (arg1 * 2) + 0x3E);
    return arg0 + *ptr;
}

s16 func_80800384_susplinet(u8 *arg0, s16 arg1) {
    s16 *base;
    s16 index;
    s16 *cursor;
    s32 limit;
    u8 *bytes;

    bytes = arg0;
    bytes += *(s16 *)(arg0 + 0x30);
    base = (s16 *)bytes;
    index = *(s16 *)(arg0 + 0x4C);
    cursor = (s16 *)((BtIntPtr)base + index * 2);
    while (arg1 < *cursor && index > 0) {
        index--;
        cursor = (s16 *)((BtIntPtr)base + index * 2);
    }
    if (cursor[1] < arg1) {
        limit = *(s16 *)(arg0 + 0x4E) - 1;
        while (index < limit) {
            index++;
            if (base[index + 1] >= arg1) {
                break;
            }
        }
    }
    *(s16 *)(arg0 + 0x4C) = index;
    return index;
}

/* extern */

void susplinet_entrypoint_16(u8 *arg0, f32 arg1, f32 arg2) {
    s32 func_800DA9E4(s32, s32);
    u8 *times;
    u8 *flags;
    s16 pad;
    s16 saved;
    s16 next;
    s16 index;

    times = arg0;
    times += *(s16 *)(arg0 + 0x30);
    flags = arg0;
    flags += *(s16 *)(arg0 + 0x32);
    index = func_80800384_susplinet(arg0, (s16)(s32)arg1)
        + 1;
    saved = index;
    next = index + 1;
    if (next >= *(s16 *)(arg0 + 0x4E)) {
        susplinet_entrypoint_10(arg0, arg2);
        return;
    }
    if (((s16 *)times)[index] != ((s16 *)times)[next]) {
        susplinet_entrypoint_10(arg0, arg2);
        return;
    }
    if (arg2 < (f32)((s16 *)times)[index]) {
        susplinet_entrypoint_10(arg0, arg2);
        return;
    }
    if (((s16 *)flags)[index] & 1) {
        if (func_800DA9E4(0x644, 0) == 0) {
            susplinet_entrypoint_10(arg0, (f32)((s16 *)times)[saved]);
            return;
        }
        susplinet_entrypoint_10(arg0, (f32)(((s16 *)times)[next] + 1));
        return;
    }
    susplinet_entrypoint_10(arg0, arg2);
}

f32 func_80800620_susplinet(u8 *arg0, s16 *arg1, f32 arg2) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s16 *times;
    u8 *bytes;
    s32 index;

    bytes = arg0;
    bytes += *(s16 *)(arg0 + 0x30);
    times = (s16 *)bytes;
    arg1[1] = func_80800384_susplinet(arg0, (s16)(s32)arg2);
    arg1[0] = arg1[1] - 1;
    arg1[2] = arg1[1] + 1;
    if (!(*(s32 *)(arg0 + 0x54) & 2)) {
        if (arg1[2] >= *(s16 *)(arg0 + 0x4E)) {
            arg1[2] = *(s16 *)(arg0 + 0x4E) - 1;
        }
        arg1[3] = arg1[2] + 1;
        if (arg1[3] >= *(s16 *)(arg0 + 0x4E)) {
            arg1[3] = *(s16 *)(arg0 + 0x4E) - 1;
        }
        if (arg1[0] < 0) {
            arg1[0] = 0;
        }
    } else {
        if (arg1[2] >= *(s16 *)(arg0 + 0x4E)) {
            arg1[2] = arg1[2] - *(s16 *)(arg0 + 0x4E) + 1;
        }
        arg1[3] = arg1[2] + 1;
        if (arg1[3] >= *(s16 *)(arg0 + 0x4E)) {
            arg1[3] = arg1[3] - *(s16 *)(arg0 + 0x4E) + 1;
        }
        index = arg1[0];
        if (index < 0) {
            arg1[0] = index - (1 - *(s16 *)(arg0 + 0x4E));
        }
    }
    if (func_80800048_susplinet((s16 *)arg0, arg1[1])) {
        arg1[0] = arg1[1];
    }
    if (func_80800068_susplinet((s16 *)arg0, arg1[2])) {
        arg1[3] = arg1[2];
    }
    return func_800F10B4(arg2, (f32)times[arg1[1]], (f32)times[arg1[2]], 0.333f, 0.666f);
}

f32 func_808007D0_susplinet(u8 *arg0, f32 arg1, s16 *arg2, u8 *arg3) {
    void _mlspline_entrypoint_4(f32, s32, u8 *, f32 *);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    f32 func_800EEAD4(f32 *, f32 *);
    s32 func_800EEDE8(u8 *, u8 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u8 *times;
    u8 *speeds;
    s32 index;
    f32 distances[30];
    s32 i;
    f32 current[3];
    f32 previous[3];
    f32 *cursor;
    f32 middle;
    f32 end;
    f32 start;
    f32 duration;
    f32 base;
    f32 fraction;
    f32 speed;
    f32 progress;
    f32 area;
    f32 distance;
    f32 half;

    times = arg0;
    speeds = arg0;
    times += *(s16 *)(arg0 + 0x30);
    speeds += *(s16 *)(arg0 + 0x34);
    if ((f32)((s16 *)times)[arg2[2]] <= arg1) {
        return 0.666f;
    }
    if (arg1 <= (f32)((s16 *)times)[arg2[1]]) {
        return 0.333f;
    }
    if (func_800EEDE8(arg3 + 0xC, arg3 + 0x18, 25.0f)) {
        return func_800F10B4(arg1, (f32)((s16 *)times)[arg2[1]], (f32)((s16 *)times)[arg2[2]], 0.333f, 0.666f);
    }
    for (i = 0; i != 30; i++) {
        _mlspline_entrypoint_4(func_800F10B4((f32)i, 0.0f, 29.0f, 0.333f, 0.666f), 4, arg3, current);
        if (i > 0) {
            distances[i] = func_800EEAD4(previous, current);
            distances[i] += (distances + i)[-1];
        } else {
            distances[i] = 0.0f;
        }
        func_800EE7F8(previous, current);
    }
    start = (f32)((s16 *)speeds)[arg2[1]] * 0.01f;
    end = (f32)((s16 *)speeds)[arg2[2]] * 0.01f;
    duration = (f32)((s16 *)times)[arg2[2]] - (f32)((s16 *)times)[arg2[1]];
    middle = (((distances[29] * 4.0f / duration) - start) - end) * 0.5f;
    fraction = func_800F10B4(arg1, (f32)((s16 *)times)[arg2[1]], (f32)((s16 *)times)[arg2[2]], 0.0f, 1.0f);
    if (fraction < 0.5f) {
        half = 0.5f * duration;
        speed = func_800F10B4(arg1, (f32)((s16 *)times)[arg2[1]], (f32)((s16 *)times)[arg2[1]] + half, start, middle);
        progress = func_800F10B4(arg1, (f32)((s16 *)times)[arg2[1]], (f32)((s16 *)times)[arg2[1]] + half, 0.0f, 1.0f);
        base = start;
    } else {
        half = 0.5f * duration;
        speed = func_800F10B4(arg1, (f32)((s16 *)times)[arg2[1]] + half, (f32)((s16 *)times)[arg2[2]], middle, end);
        progress = func_800F10B4(arg1, (f32)((s16 *)times)[arg2[1]] + half, (f32)((s16 *)times)[arg2[2]], 0.0f, 1.0f);
        base = middle;
    }
    if (speed < base) {
        progress = (base + speed) * 0.25f * duration * progress;
        distance = progress;
    } else {
        progress = (speed + base) * 0.25f * duration * progress;
        distance = progress;
    }
    if (fraction >= 0.5f) {
        distance += 0.25f * duration * (start + middle);
    }
    for (index = 0; index < 28 && (distances + index)[1] < distance; index++) {
    }
    cursor = distances + index;
    return func_800F10B4(func_800F10B4(distance, cursor[0], cursor[1], (f32)index * 0.03448276f, (f32)(index + 1) * 0.03448276f), 0.0f, 1.0f, 0.333f, 0.666f);
}

void func_80800D3C_susplinet(u8 *arg0, f32 time) {
    void _mlspline_entrypoint_4(f32, s32, u8 *, f32 *);
    void _mlspline_entrypoint_8(f32, s32, u8 *, f32 *);
    void _mlspline_entrypoint_9(f32, s32, f32 *, f32 *);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s16 *speeds;
    s16 *times;
    s32 i;
    f32 *vectors[3];
    f32 *scalars[3];
    s32 b;
    s16 indices[4];
    s32 c;
    f32 values[4];
    f32 points[4][3];
    s32 a;
    f32 *scalar_output;
    f32 fraction;

    speeds = (s16 *)(*(s16 *)(arg0 + 0x34) + *(u8 (*)[1])arg0);
    times = (s16 *)(*(s16 *)(arg0 + 0x30) + *(u8 (*)[1])arg0);
    if (times[*(s16 *)(arg0 + 0x4E) - 1] < time) {
        time = times[*(s16 *)(arg0 + 0x4E) - 1];
    } else if (time < times[0]) {
        time = times[0];
    }
    for (i = 0; i < arg0[0x51]; i++) {
        vectors[i] = (f32 *)&arg0[*(s16 *)(arg0 + 0x36 + i * 2)];
    }
    for (i = 0; i < arg0[0x52]; i++) {
        scalars[i] = (f32 *)&arg0[*(s16 *)(arg0 + 0x3E + i * 2)];
    }
    if (*(s16 *)(arg0 + 0x4E) >= 4) {
        s32 d;
        fraction = func_80800620_susplinet(arg0, indices, time);
        if (indices[0] != indices[1] && times[indices[0]] == times[indices[1]] && susplinet_entrypoint_5(arg0, (f32)times[indices[1]])) {
            arg0[0x53] = 1;
        } else {
            arg0[0x53] = 0;
        }
        a = indices[0] * 3;
        b = indices[1] * 3;
        c = indices[2] * 3;
        d = indices[3] * 3;
        for (i = 0; i < arg0[0x51]; i++) {
            func_800EE7F8(points[0], vectors[i] + a);
            func_800EE7F8(points[1], vectors[i] + b);
            func_800EE7F8(points[2], vectors[i] + c);
            func_800EE7F8(points[3], vectors[i] + d);
            if (i == 0 && *speeds != -1) {
                fraction = func_808007D0_susplinet(arg0, time, indices, (u8 *)points);
            }
            if (func_808000FC_susplinet(arg0, i)) {
                func_800F0EF0(4, points[0]);
            }
            _mlspline_entrypoint_4(fraction, 4, (u8 *)points, (f32 *)(arg0 + i * 12));
            if (i == 0) {
                _mlspline_entrypoint_8(fraction, 4, (u8 *)points, (f32 *)(arg0 + i * 12 + 0x18));
            }
        }
        for (i = 0; i < arg0[0x52]; i++) {
            values[0] = scalars[i][indices[0]];
            values[1] = scalars[i][indices[1]];
            values[2] = scalars[i][indices[2]];
            values[3] = scalars[i][indices[3]];
            _mlspline_entrypoint_9(fraction, 4, values, (f32 *)(arg0 + 0x24 + i * 4));
        }
    }
}

void susplinet_entrypoint_17(u8 *spline) {
    void func_80800D3C_susplinet(u8 *, f32);
    spline[0x58] = 1;
    func_80800D3C_susplinet(spline, *(f32 *)(spline + 0x44));
    spline[0x58] = 0;
}    typedef struct { u8 pad0[0x36]; s16 unk36; } Objsplinet_func_8080111C_susplinet_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */ typedef struct { u8 pad0[0x3E]; s16 unk3E; } Objsplinet_func_8080111C_susplinet_var_v1_2; /* offsets.py genstruct: fields from raw offsets on var_v1_2; rename once understood */

void func_8080111C_susplinet(u8 *arg0) {
    s32 var_v0;
    s32 var_a1;
    u8 *var_v1;
    u8 *var_v1_2;

    (((Objsplinet_arg0 *)arg0)->unk30) = 0x5C;
    var_v0 = (((Objsplinet_arg0 *)arg0)->unk4E) * 2 + 0x5C;
    (((Objsplinet_arg0 *)arg0)->unk32) = var_v0;
    var_v0 += (((Objsplinet_arg0 *)arg0)->unk4E) * 2;
    var_a1 = 0;
    if ((s32) (((Objsplinet_arg0 *)arg0)->unk51) > 0) {
        var_v1 = arg0;
        do {
            (((Objsplinet_func_8080111C_susplinet_var_v1 *)var_v1)->unk36) = var_v0;
            var_a1 += 1;
            var_v1 += 2;
            var_v0 += (((Objsplinet_arg0 *)arg0)->unk4E) * 0xC;
        } while (var_a1 < (s32) (((Objsplinet_arg0 *)arg0)->unk51));
        var_a1 = 0;
    }
    var_v1_2 = arg0;
    if ((s32) (((Objsplinet_arg0 *)arg0)->unk52) > 0) {
        do {
            (((Objsplinet_func_8080111C_susplinet_var_v1_2 *)var_v1_2)->unk3E) = var_v0;
            var_a1 += 1;
            var_v1_2 += 2;
            var_v0 += (((Objsplinet_arg0 *)arg0)->unk4E) * 4;
        } while (var_a1 < (s32) (((Objsplinet_arg0 *)arg0)->unk52));
    }
    (((Objsplinet_arg0 *)arg0)->unk34) = var_v0;
}

s32 func_808011B8_susplinet(s32 arg0, s32 arg1) {
    return (arg0 * 0xC) + (arg1 * 4) + 6;
}

s32 susplinet_entrypoint_18(s32 arg0, s32 arg1, s32 arg2) {
    register s32 result;
    result = arg0;
    result *= func_808011B8_susplinet(arg1, arg2);
    return result + 0x5C;
}

/* extern */

void susplinet_entrypoint_19(u8 *arg0, s32 arg1, u32 arg2, u32 arg3) {
    void func_800DA524(s32);
    u8 *values;
    u8 *indices;
    s32 i;

    *(s16 *)(arg0 + 0x4E) = arg1;
    *(u8 *)(arg0 + 0x51) = arg2;
    *(u8 *)(arg0 + 0x52) = arg3;
    *(u8 *)(arg0 + 0x50) = 0;
    *(s16 *)(arg0 + 0x4C) = 0;
    *(u8 *)(arg0 + 0x58) = 0;
    *(f32 *)(arg0 + 0x44) = 0.0f;
    *(f32 *)(arg0 + 0x48) = 0.0f;
    func_8080111C_susplinet(arg0);
    values = arg0;
    indices = arg0;
    values += *(s16 *)(arg0 + 0x32);
    indices += *(s16 *)(arg0 + 0x34);
    for (i = 0; i < arg1; i++) {
        *(s16 *)(values + i * 2) = 0;
        *(s16 *)(indices + i * 2) = -1;
    }
    func_800DA524(0x644);
}
