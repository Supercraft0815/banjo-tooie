#include "common.h"

void susplinet_entrypoint_0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 *temp_v1;
    s16 *temp_v1_2;
    s16 temp_a0;
    u8 *temp_v0;

    temp_v0 = arg0;
    temp_v0 += *(s16 *)((s8 *)arg0 + 0x32);
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
    s32 base = (s32)arg0;
    s16 *ptr;
    base += *(s16 *)((s8 *)arg0 + 0x30);
    ptr = (s16 *)base;
    return (f32)ptr[*(s16 *)((s8 *)arg0 + 0x4E) - 1] <= *(f32 *)((s8 *)arg0 + 0x44);
}

s16 susplinet_entrypoint_3(s8 *arg0) {
    s32 base = (s32)arg0;
    base += *(s16 *)(arg0 + 0x30);
    return ((s16 *)base)[*(s16 *)(arg0 + 0x4E) - 1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_4.s")

s32 susplinet_entrypoint_5(void *arg0, f32 arg1) {
    if (((*(f32 *)((s8 *)(arg0) + (0x48))) <= arg1) && (arg1 < (*(f32 *)((s8 *)(arg0) + (0x44))))) {
        return 1;
    }
    return 0;
}

u32 susplinet_entrypoint_6(u8 *arg0) {
    return arg0[83];
}

void susplinet_entrypoint_7(f32 arg0[][3], s32 arg1, f32 *arg2) {
    s32 func_800EE7F8();
    func_800EE7F8(arg2, arg0[arg1]);
}

f32 susplinet_entrypoint_8(f32 *arg0, s32 arg1) {
    return (arg0 + arg1)[9];
}

f32 susplinet_entrypoint_9(f32 *arg0) {
    return arg0[17];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_10.s")

void susplinet_entrypoint_11(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 72) = arg1;
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

s32 susplinet_entrypoint_15(s32 arg0, s32 arg1) {
    s16 *ptr = (s16 *)((s8 *)arg0 + (arg1 * 2) + 0x3E);
    return arg0 + *ptr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_80800384_susplinet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_80800620_susplinet.s")

f32 func_808007D0_susplinet(u8 *arg0, f32 arg1, s16 *arg2, u8 *arg3) {
    void _mlspline_entrypoint_4(f32, s32, u8 *, f32 *);
    s32 func_800EE7F8(f32 *, f32 *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_80800D3C_susplinet.s")

void susplinet_entrypoint_17(u8 *spline) {
    s32 func_80800D3C_susplinet(u8 *, s32);
    spline[0x58] = 1;
    func_80800D3C_susplinet(spline, *(s32 *)(spline + 0x44));
    spline[0x58] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_8080111C_susplinet.s")

s32 func_808011B8_susplinet(s32 arg0, s32 arg1) {
    return (arg0 * 0xC) + (arg1 * 4) + 6;
}

s32 susplinet_entrypoint_18(s32 arg0, s32 arg1, s32 arg2) {
    register s32 result;
    result = arg0;
    result *= func_808011B8_susplinet(arg1, arg2);
    return result + 0x5C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_19.s")
