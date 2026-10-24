#include "common.h"

typedef struct {
    s16 unk0;
    s16 gain;
    s32 unk4;
    u8 coefficients[0x20];
    s32 flags;
    void *state[2];
} AudioPoleFilter;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3FB40/func_80028010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3FB40/func_80028328.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3FB40/func_800288C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3FB40/func_80028A24.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3FB40/func_80028C04.s")

void func_80028DF0(void *arg0, s32 arg1, s16 arg2, s32 arg3) {
    typedef struct Input {
        u8 pad00[0x18];
        s32 rate;
        u8 types[4];
        s32 *data[4];
    } Input;
    typedef struct Effect {
        s16 type;
        u8 pad02[0x12];
        s16 *unk14;
        s16 *unk18;
        u8 pad1C[8];
        f32 unk24;
        s32 unk28;
        s16 *unk2C;
        s16 *unk30;
        s32 unk34;
    } Effect;
    typedef struct Entry {
        u32 start;
        u32 end;
        s16 unk08;
        s16 unk0A;
        s16 unk0C;
        s16 pad0E;
        f32 unk10;
        f32 unk14;
        s32 unk18;
        f32 unk1C;
        Effect *unk20;
        Effect *unk24;
    } Entry;
    typedef struct Header {
        u32 count;
        Entry *entries;
        u8 entryCount;
        u8 pad09[0x17];
        s16 *unk20;
        s16 *unk24;
        s16 *unk28;
        s16 *unk2C;
    } Header;
    s32 func_80020EE4(s32, s32, void *, s32, s32);
    s32 func_80028A24(s16 *);
    extern s32 D_80041268;

    u16 i;
    u16 cursor;
    u16 j;
    s32 *data;
    Entry *entry;
    Header *header;

    data = NULL;
    header = (Header *)func_80020EE4(0, 0, (void *)arg3, 1, 0x30);
    *(Header **)arg0 = header;
    switch (((Input *)arg1)->types[arg2]) {
        case 6:
            data = ((Input *)arg1)->data[arg2];
            break;
        default:
            data = &D_80041268;
            break;
    }
    cursor = 0;
    header->entryCount = data[cursor];
    ++cursor;
    header->count = data[cursor];
    ++cursor;
    header->entries = (Entry *)func_80020EE4(0, 0, (void *)arg3, header->entryCount, 0x28);
    header->unk20 = (s16 *)func_80020EE4(0, 0, (void *)arg3, header->count, 2);
    header->unk28 = header->unk20;
    header->unk24 = (s16 *)func_80020EE4(0, 0, (void *)arg3, header->count, 2);
    header->unk2C = header->unk24;
    for (j = 0; j < header->count; j++) {
            header->unk24[j] = 0;
            header->unk20[j] = header->unk24[j];
    }
    for (i = 0; i < header->entryCount; i++) {
        entry = &header->entries[i];
        entry->start = data[cursor];
        ++cursor;
        entry->end = data[cursor];
        ++cursor;
        entry->unk0A = data[cursor];
        ++cursor;
        entry->unk08 = data[cursor];
        ++cursor;
        entry->unk0C = data[cursor];
        ++cursor;
        if (data[cursor] != 0) {
            entry->unk10 = ((f32)data[cursor] / 1000.0f) * 2.0f / ((Input *)arg1)->rate;
            ++cursor;
            entry->unk1C = ((f32)data[cursor] / 173123.40625f) * (entry->end - entry->start);
            ++cursor;
            entry->unk14 = 1.0f;
            entry->unk18 = 0;
            entry->unk24 = (Effect *)func_80020EE4(0, 0, (void *)arg3, 1, 0x38);
            entry->unk24->unk14 = (s16 *)func_80020EE4(0, 0, (void *)arg3, 1, 0x20);
            entry->unk24->unk18 = (s16 *)func_80020EE4(0, 0, (void *)arg3, 1, 0x20);
            entry->unk24->unk24 = 0.0f;
            entry->unk24->unk28 = 1;
        } else {
            entry->unk24 = NULL;
            ++cursor;
            ++cursor;
        }
        if (data[cursor] != 0) {
            entry->unk20 = (Effect *)func_80020EE4(0, 0, (void *)arg3, 1, 0x38);
            entry->unk20->unk2C = (s16 *)func_80020EE4(0, 0, (void *)arg3, 1, 8);
            entry->unk20->unk30 = (s16 *)func_80020EE4(0, 0, (void *)arg3, 1, 8);
            entry->unk20->type = data[cursor];
            ++cursor;
            func_80028A24((s16 *)entry->unk20);
        } else {
            entry->unk20 = NULL;
            ++cursor;
        }
    }
}

/* extern */

void func_800293B4(u8 *arg0, s32 (*arg1)(u8 *), s32 arg2) {
    s32 func_80020EE4(s32, s32, void *, s32, s32);
    (*(s32 *)((s8 *)(arg0) + (0xC))) = func_80020EE4(0, 0, (void *)arg2, 1, 0x20);
    (*(s32 *)((s8 *)(arg0) + (0x10))) = func_80020EE4(0, 0, (void *)arg2, 1, 0x20);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = arg1(arg0 + 0x2C);
    (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x38))) = 1;
    (*(s32 *)((s8 *)(arg0) + (0x3C))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x40))) = func_80020EE4(0, 0, (void *)arg2, 1, 0x20);
    (*(f32 *)((s8 *)(arg0) + (0x4C))) = 0.0f;
    (*(s32 *)((s8 *)(arg0) + (0x50))) = 1;
    (*(f32 *)((s8 *)(arg0) + (0x44))) = 1.0f;
    (*(s32 *)((s8 *)(arg0) + (0x48))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x54))) = func_80020EE4(0, 0, (void *)arg2, 1, 0x50);
    (*(s32 *)((s8 *)(arg0) + (0x78))) = 1;
    (*(s32 *)((s8 *)(arg0) + (0x84))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x5A))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x68))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x6E))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x5C))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x5E))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x60))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x62))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x66))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x64))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x66))) = 1;
    (*(s16 *)((s8 *)(arg0) + (0x64))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x70))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x74))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x58))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x7C))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x80))) = 0;
    (*(s8 *)((s8 *)(arg0) + (0x8C))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x92))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x90))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0xBC))) = func_80020EE4(0, 0, (void *)arg2, 1, 8);
    (*(s32 *)((s8 *)(arg0) + (0xB8))) = 0;
}
