#include "common.h"

typedef struct {
    s16 unk0;
    s16 gain;
    s32 unk4;
    u8 coefficients[0x20];
    s32 flags;
    void *state[2];
} AudioPoleFilter;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_800272B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_80027AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_80028010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_80028328.s")

Gfx *func_80028520(s32 *arg0, s32 arg1, u32 arg2, s32 arg3, Gfx *arg4) {
    Gfx *cursor;
    s32 firstCount;
    s32 secondCount;
    u32 end;
    u32 limit;

    cursor = arg4;
    limit = arg0[0] * 2 + arg0[arg1 + 8];
    if (arg2 < (u32)arg0[arg1 + 8]) {
        arg2 += arg0[0] * 2;
    }
    end = arg2 + 0x170;
    if (end > limit) {
        firstCount = (s32)(end - limit) >> 1;
        secondCount = (s32)(limit - arg2) >> 1;
        {
            Gfx *first = cursor++;
            first->words.w0 = 0x06000000 | (((secondCount * 2) & 0xFFF) << 12) | (arg3 & 0xFFF);
            first->words.w1 = osVirtualToPhysical((void *)arg2);
        }
        {
            Gfx *second = cursor++;
            second->words.w0 = 0x06000000 | (((firstCount * 2) & 0xFFF) << 12) | ((arg3 + secondCount * 2) & 0xFFF);
            second->words.w1 = osVirtualToPhysical((void *)arg0[arg1 + 8]);
        }
    } else {
        Gfx *single = cursor++;
        single->words.w0 = 0x06170000 | (arg3 & 0xFFF);
        single->words.w1 = osVirtualToPhysical((void *)arg2);
    }
    return cursor;
}

Gfx *func_800286FC(AudioPoleFilter *arg0, s32 arg1, s32 arg2, Gfx *arg3) {
    Gfx *cursor;
    s16 segment;

    cursor = arg3;
    segment = arg2 >> 8;
    {
        Gfx *first = cursor++;
        first->words.w0 = 0x0B000020;
        first->words.w1 = osVirtualToPhysical(arg0->coefficients);
    }
    {
        Gfx *second = cursor++;
        second->words.w0 = _SHIFTL(0xE, 24, 8) | _SHIFTL(arg0->flags, 16, 8) | _SHIFTL(arg0->gain, 0, 16);
        second->words.w1 = _SHIFTL(segment, 24, 8) | _SHIFTL(osVirtualToPhysical(arg0->state[arg1]), 0, 24);
    }
    arg0->flags = 0;
    return cursor;
}

f32 func_800287FC(f32 *arg0, s32 arg1) {
    f32 value;

    arg0[5] += arg0[4] * arg1;
    if (arg0[5] > 2.0f) {
        arg0[5] -= 4.0f;
    } else {
        arg0[5] = arg0[5];
    }
    value = arg0[5];
    value = value < 0.0f ? -value : value;
    value -= 1.0f;
    return arg0[7] * value;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_800288C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_80028A24.s")

f32 func_80028B74(s32 arg0) {
    f32 x;
    f32 ratio = 1.0f;

    if (arg0 >= 0) {
        x = 1.0594631433486938f;
    } else {
        x = 0.9438742995262146f;
        arg0 = -arg0;
    }
    while (arg0 != 0) {
        if (arg0 & 1) {
            ratio *= x;
        }
        x *= x;
        arg0 >>= 1;
    }
    return ratio;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_80028C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_80028DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3EDE0/func_800293B4.s")
