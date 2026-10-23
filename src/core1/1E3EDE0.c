#include "common.h"

typedef struct {
    s16 unk0;
    s16 gain;
    s32 unk4;
    u8 coefficients[0x20];
    s32 flags;
    void *state[2];
} AudioPoleFilter;

void *func_800272B0(s32 arg0, void *arg1, s32 arg2) {
    typedef struct {
        u32 w0;
        u32 w1;
    } Command;
    typedef struct {
        s32 input;
        s32 output;
        s16 feedback;
        s16 feedforward;
        s16 gain;
        u8 pad[0x12];
        void *filter;
        void *resampler;
    } Section;
    typedef struct {
        s32 length;
        Section *sections;
        u8 count;
        u8 pad[0x17];
        s16 *base[2];
        s16 *position[2];
    } Effect;
    typedef struct {
        u8 pad0[0x20];
        Effect *effect;
        u8 pad24[0x24];
    } Bus;
    extern struct {
        u8 pad[0x34];
        Bus *busses;
    } *D_800411F4;
    extern u8 D_8007EA33;
    extern u8 D_8007EA34;

    extern s32 *func_8002BD40(s32, s32 *, s32, s32 *);
    extern Gfx *func_80028520(s32 *, s32, u32, s32, Gfx *);
    extern void *func_80028328(void *, u32, s16 *, s16, s32, void *);
    extern void *func_80028010(void *, void *, u32, s16, void *);
    extern Gfx *func_800286FC(AudioPoleFilter *, s32, s32, Gfx *);
    Command *sp7C;
    Effect *sp78;
    s16 sp76;
    s16 sp74;
    s16 sp72;
    s16 sp70;
    s16 sp6E;
    s16 *sp68;
    s16 *sp64;
    s16 *sp60;
    Section *sp5C;
    s32 flags;
    u32 sp54;

    sp7C = arg1;
    sp78 = D_800411F4->busses[arg2].effect;
    sp60 = 0;
    flags = 1;
    sp7C = func_8002BD40(arg0, arg1, arg2, &flags);
    sp70 = 0x7C0;
    sp6E = 0x930;
    sp74 = 0;
    sp72 = 0x170;
    if ((&D_8007EA33)[arg2] == 0) {
        {
            Command *command = sp7C++;
            command->w0 = 0x0C00C000;
            command->w1 = (sp70 & 0xFFFF) | 0x07C00000;
        }
        {
            Command *command = sp7C++;
            command->w0 = 0x0C004000;
            command->w1 = (sp70 & 0xFFFF) | 0x09300000;
        }
    }
    sp7C = func_80028520(sp78, 0, sp78->position[0], sp70, sp7C);
    if ((&D_8007EA33)[arg2] != 0) {
        sp7C = func_80028520(sp78, 1, sp78->position[1], 0x930, sp7C);
    }
    for (sp54 = 0; sp54 <= (&D_8007EA33)[arg2]; sp54++) {
        {
            Command *command = sp7C++;
            command->w0 = (sp6E & 0xFFFFFF) | 0x02000000;
            command->w1 = 0x170;
        }
        for (sp76 = 0; sp76 < sp78->count; sp76++) {
            sp5C = &sp78->sections[sp76];
            sp68 = sp78->position[sp54] + -sp5C->input;
            sp64 = sp78->position[sp54] + -sp5C->output;
            if ((&D_8007EA34)[arg2] && (&D_8007EA33)[arg2]) {
                sp5C->feedback = -sp5C->feedback;
                sp5C->feedforward = -sp5C->feedforward;
            }
            if (sp68 == sp60) {
                s16 swap;
                swap = sp72;
                sp72 = sp74;
                sp74 = swap;
            } else {
                sp7C = func_80028328(sp78, sp54, sp68, sp74, 0xB8, sp7C);
            }
            sp7C = func_80028010(sp78, sp5C, sp54, sp72, sp7C);
            if (sp5C->feedback != 0) {
                {
                    Command *command = sp7C++;
                    command->w0 = ((u16)sp5C->feedback & 0xFFFF) | 0x0C000000;
                    command->w1 = ((sp74 & 0xFFFF) << 16) | (sp72 & 0xFFFF);
                }
                if (sp5C->resampler == 0 && sp5C->filter == 0) {
                    sp7C = func_80028520(sp78, sp54, sp64, sp72, sp7C);
                }
            }
            if (sp5C->feedforward != 0) {
                {
                    Command *command = sp7C++;
                    command->w0 = ((u16)sp5C->feedforward & 0xFFFF) | 0x0C000000;
                    command->w1 = ((sp72 & 0xFFFF) << 16) | (sp74 & 0xFFFF);
                }
                sp7C = func_80028520(sp78, sp54, sp68, sp74, sp7C);
            }
            if (sp5C->filter != 0) {
                sp7C = func_800286FC(sp5C->filter, sp54, sp72, sp7C);
            }
            if (sp5C->resampler == 0) {
                sp7C = func_80028520(sp78, sp54, sp64, sp72, sp7C);
            }
            if (sp5C->gain != 0) {
                if ((&D_8007EA33)[arg2] != 0) {
                    Command *command = sp7C++;
                    command->w0 = ((u16)sp5C->gain & 0xFFFF) | 0x0C000000;
                    command->w1 = ((sp72 & 0xFFFF) << 16) | (sp6E & 0xFFFF);
                } else {
                    u32 gain;
                    gain = (f32)sp5C->gain * 1.414199948310852f;
                    if (gain >= 0x8000) {
                        gain = 0x7FFF;
                    }
                    {
                        Command *command = sp7C++;
                        command->w0 = ((u16)gain & 0xFFFF) | 0x0C000000;
                        command->w1 = ((sp72 & 0xFFFF) << 16) | (sp6E & 0xFFFF);
                    }
                }
            }
            sp60 = sp78->position[sp54] + sp5C->output;
        }
        if ((&D_8007EA33)[arg2] && sp54 == 0) {
            sp7C = func_80028328(sp78, 1, sp78->position[1], sp70, 0xB8, sp7C);
            if ((&D_8007EA34)[arg2]) {
                Command *command = sp7C++;
                command->w0 = 0x0C005A82;
                command->w1 = ((sp6E & 0xFFFF) << 16) | 0x650;
            } else {
                Command *command = sp7C++;
                command->w0 = 0x0C005A82;
                command->w1 = ((sp6E & 0xFFFF) << 16) | 0x4E0;
            }
        } else {
        }
        {
            Command *command = sp7C++;
            command->w0 = (sp6E & 0xFFFFFF) | 0x0A000000;
            command->w1 = 0x07C00170;
        }
        sp78->position[sp54] += 0xB8;
        if (sp78->position[sp54] > sp78->base[sp54] + sp78->length) {
            sp78->position[sp54] -= sp78->length;
        }
    }
    return sp7C;
}

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
