#include "common.h"

typedef struct {
    s16 unk0;
    s16 gain;
    s32 unk4;
    u8 coefficients[0x20];
    s32 flags;
    void *state[2];
} AudioPoleFilter;     

Gfx *func_80028010(s32 *arg0, f32 *arg1, s32 arg2, s32 arg3, Gfx *arg4) {
    Gfx *func_80028328(s32 *, s32, BtUIntPtr, s32, s32, Gfx *);
    f32 func_800287FC(f32 *, s32);
    Gfx *sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    u32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s16 sp2A;

    sp54 = arg4;
    sp48 = 0x2E0;
    sp34 = 0;
    sp2C = 0xB8;
    if (*(void **)(arg1 + 9) != NULL) {
        sp30 = ((s32 *)arg1)[1] - ((s32 *)arg1)[0];
        sp38 = func_800287FC(arg1, sp2C);
        sp38 /= (f32)sp30;
        sp38 = (f32)(s32)(sp38 * 32768.0f);
        sp38 /= 32768.0f;
        sp3C = 1.0f - sp38;
        sp40 = (*(f32 **)(arg1 + 9))[9] + sp3C * (f32)sp2C;
        sp4C = (s32)sp40;
        (*(f32 **)(arg1 + 9))[9] = sp40 - (f32)sp4C;
        sp44 = ((u32)-(((s32 *)arg1)[1] - ((s32 *)arg1)[6]) << 1) + arg0[arg2 + 10];
        sp34 = (s32)(sp44 & 7) >> 1;
        sp54 = func_80028328(arg0, arg2, sp44 - sp34 * 2, sp48, sp4C + sp34, sp54);
        sp50 = (s32)(sp3C * 32768.0f);
        sp2A = arg3 >> 8;
        {
            Gfx *sp24 = sp54++;
            sp24->words.w0 = (osVirtualToPhysical((*(void ***)(arg1 + 9) + arg2)[5]) & 0xFFFFFF) | 0x05000000;
            sp24->words.w1 = (((*(s32 **)(arg1 + 9))[10] & 3) << 30) | ((sp50 & 0xFFFF) << 14) | (((sp48 + sp34 * 2) & 0xFFF) * 4) | (sp2A & 3);
        }
        (*(s32 **)(arg1 + 9))[10] = 0;
        ((s32 *)arg1)[6] += sp4C - sp2C;
    } else {
        sp44 = ((u32)-((s32 *)arg1)[1] << 1) + arg0[arg2 + 10];
        sp54 = func_80028328(arg0, arg2, sp44, arg3, 0xB8, sp54);
    }
    return sp54;
}

Gfx *func_80028328(s32 *arg0, s32 arg1, BtUIntPtr arg2, s32 arg3, s32 arg4, Gfx *arg5) {
    Gfx *cursor;
    s32 firstCount;
    s32 secondCount;
    BtUIntPtr end;
    u32 limit;

    cursor = arg5;
    limit = arg0[0] * 2 + arg0[arg1 + 8];
    if (arg2 < (u32)arg0[arg1 + 8]) {
        arg2 += arg0[0] * 2;
    }
    end = arg4 * 2 + arg2;
    if (end > limit) {
        firstCount = (s32)(end - limit) >> 1;
        secondCount = (s32)(limit - arg2) >> 1;
        {
            Gfx *first = cursor++;
            first->words.w0 = 0x04000000 | (((secondCount * 2) & 0xFFF) << 12) | (arg3 & 0xFFF);
            first->words.w1 = osVirtualToPhysical((void *)arg2);
        }
        {
            Gfx *second = cursor++;
            second->words.w0 = 0x04000000 | (((firstCount * 2) & 0xFFF) << 12) | ((arg3 + secondCount * 2) & 0xFFF);
            second->words.w1 = osVirtualToPhysical((void *)arg0[arg1 + 8]);
        }
    } else {
        Gfx *single = cursor++;
        single->words.w0 = 0x04000000 | (((arg4 * 2) & 0xFFF) << 12) | (arg3 & 0xFFF);
        single->words.w1 = osVirtualToPhysical((void *)arg2);
    }
    return cursor;
}

Gfx *func_80028520(s32 *arg0, s32 arg1, BtUIntPtr arg2, s32 arg3, Gfx *arg4) {
    Gfx *cursor;
    s32 firstCount;
    s32 secondCount;
    BtUIntPtr end;
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
}                   typedef struct { u8 pad0[0x4]; f32 unk4; f32 unk8; } Obj1E3FB40_arg4; /* offsets.py genstruct: fields from raw offsets on arg4; rename once understood */

/* extern */

void func_800288C0(f32 arg0, f32 arg1, f32 arg2, void *arg3, void *arg4) {
    f32 func_80013C48(f32, f32);
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    if (arg1 >= (arg0 - 200.0f)) {
        arg1 = arg0 - 200.0f;
    }
    sp24 = func_80013C48(arg1 * 3.1415927f, arg0);
    sp20 = sp24 * sp24;
    sp1C = (sp24 * 1.4142137f) / arg2;
    (((Vec3f *)arg3)->pos.x) = (f32) (sp20 / (1.0f + sp20 + sp1C));
    (((Vec3f *)arg3)->pos.y) = (f32) ((((Vec3f *)arg3)->pos.x) * 2.0f);
    (((Vec3f *)arg3)->pos.z) = (f32) (((Vec3f *)arg3)->pos.x);
    (((Obj1E3FB40_arg4 *)arg4)->unk4) = (f32) (((sp20 - 1.0f) * 2.0f) / (1.0f + sp20 + sp1C));
    (((Obj1E3FB40_arg4 *)arg4)->unk8) = (f32) (((1.0f + sp20) - sp1C) / (1.0f + sp20 + sp1C));
}

s32 func_80028A24(s16 *arg0) {
    s32 i;
    s32 value;
    s16 coefficient;
    f32 ratio;
    f32 power;
    f32 scale;

    value = (s32)((f32)arg0[0] * 16384.0f);
    coefficient = value >> 15;
    arg0[1] = (s32)(16384.0f - (f32)coefficient);
    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    for (i = 0; i < 8; i++) {
        (arg0 + i)[4] = 0;
    }
    (arg0 + i)[4] = coefficient;
    i++;
    scale = 16384.0f;
    power = ratio = (f32)coefficient / scale;
    for (; i < 16; i++) {
        power *= ratio;
        (arg0 + i)[4] = (s32)(power * scale);
    } BT_NATIVE_ONLY(return 0;)
}

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

void func_80028C04(void *arg0, f32 arg1) {
    s32 i;
    f32 numerator[3];
    f32 denominator[3];

    if (*(s16 *)((u8 *)arg0 + 2) == 0) {
        return;
    }
    if (*(s16 *)((u8 *)arg0 + 2) < 10) {
        *(s16 *)((u8 *)arg0 + 2) = 10;
    }
    func_800288C0(arg1, (f32)*(s16 *)arg0 + 10.0f,
        (f32)*(s16 *)((u8 *)arg0 + 2) / 10.0f, numerator, denominator);
    for (i = 3; i < 8; i++) {
        ((s16 *)((u8 *)arg0 + 8))[i] = 0;
    }
    *(s16 *)((u8 *)arg0 + 8) = (s32)((26768.0f - (f32)*(s16 *)((u8 *)arg0 + 2) * 128.0f) * (*(f32 *)((u8 *)numerator + 0)));
    *(s16 *)((u8 *)arg0 + 10) = (s32)((26768.0f - (f32)*(s16 *)((u8 *)arg0 + 2) * 128.0f) * (*(f32 *)((u8 *)numerator + 4)));
    *(s16 *)((u8 *)arg0 + 12) = 0;
    *(s16 *)((u8 *)arg0 + 24) = (s32)((*(f32 *)((u8 *)denominator + 4)) * -16384.0f);
    *(s16 *)((u8 *)arg0 + 26) = (s32)((*(f32 *)((u8 *)denominator + 8)) * -16384.0f);
    for (i = 10; i < 16; i++) {
        ((s16 *)((u8 *)arg0 + 8))[i] = 0;
    }
}

void func_80028DF0(void *arg0, BtIntPtr arg1, s16 arg2, BtIntPtr arg3) {
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
    BtIntPtr func_80020EE4(s32, s32, void *, s32, s32);
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

void func_800293B4(u8 *arg0, s32 (*arg1)(u8 *), BtIntPtr arg2) {
    BtIntPtr func_80020EE4(s32, s32, void *, s32, s32);
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
