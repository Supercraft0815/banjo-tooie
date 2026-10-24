#include "common.h"

typedef struct {
    u8 pad0[0x34];
    void *busses;
    u8 pad38[8];
    s32 outputRate;
} AudioGlobals;

extern AudioGlobals *D_800411F4;

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
    sp78 = ((Bus *)D_800411F4->busses)[arg2].effect;
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

s32 func_80027AF0(void *arg0, s32 arg1, void *arg2)
{
    typedef struct {
        u32 input;
        u32 output;
        s16 ffcoef;
        s16 fbcoef;
        s16 gain;
        s16 padE;
        f32 rsinc;
        u8 pad14[8];
        f32 rsdelta;
        s16 *lp;
        void *rs;
    } Delay;
    typedef struct {
        u32 length;
        Delay *delay;
        u8 sectionCount;
    } Fx;


    extern s32 func_80028A24(s16 *);
    Fx *fx = arg0;
    s32 param = arg1 & 7;
    s32 section = arg1 >> 3;
    int value = *(s32 *)arg2;
    f32 depth;

    if (section >= fx->sectionCount) {
        return 0;
    }
    switch (param) {
        case 0:
            fx->delay[section].input = ((value * D_800411F4->outputRate) / 1000) & ~7;
            break;
        case 1:
            fx->delay[section].output = ((value * D_800411F4->outputRate) / 1000) & ~7;
            break;
        case 2:
            fx->delay[section].fbcoef = value;
            break;
        case 3:
            fx->delay[section].ffcoef = value;
            break;
        case 4:
            fx->delay[section].gain = value;
            break;
        case 5:
            fx->delay[section].rsinc = ((f32)value / 1000.0f) * 2.0f / (f32)D_800411F4->outputRate;
            break;
        case 6:
            depth = value;
            break;
        case 7:
            if (fx->delay[section].lp) {
                *fx->delay[section].lp = value;
                func_80028A24(fx->delay[section].lp);
            }
            break;
    }
    if (fx->delay[section].input >= fx->length - 16) {
        fx->delay[section].input = fx->length - 16;
    }
    if (fx->delay[section].input >= fx->length - 8) {
        fx->delay[section].input = fx->length - 8;
    }
    if (fx->delay[section].input >= fx->delay[section].output) {
        fx->delay[section].output = fx->delay[section].input + 8;
    }
    if (fx->delay[section].rs) {
        if (param != 6) {
            if (fx->delay[section].output - fx->delay[section].input) {
                depth = fx->delay[section].rsdelta / (f32)(fx->delay[section].output - fx->delay[section].input) * 173123.40625f;
            } else {
                depth = 0.0f;
            }
        }
        fx->delay[section].rsdelta = (f32)(fx->delay[section].output - fx->delay[section].input) * (depth / 173123.40625f);
    }
    return 0;
}
