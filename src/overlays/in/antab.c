#include "common.h"

void inantab_entrypoint_0()
{
    func_800BF744();
}

void _anseq_entrypoint_2(s16 *, f32, void *, s32, s32);
void _anseq_entrypoint_3(s16 *, f32, void *, s32, s32, s32);
void _chanim_entrypoint_4(s16 *, f32, s32, s32, s32);
void _inantab_entrypoint_0();
void _inantab_entrypoint_3();
void _indrv_audio_entrypoint_0();
void _indrv_fx_entrypoint_0();
void _indrv_lights_entrypoint_0();
void func_800BFCD0();

extern f32 D_80806F80_inantab[3];
extern f32 D_80806F8C_inantab[3];
extern f32 D_80806F98_inantab[3];
extern f32 D_80806FA4_inantab[3];
extern f32 D_80806FD8_inantab[2];
extern f32 D_80807038_inantab[2];
extern f32 D_80807040_inantab[3];
extern f32 D_8080704C_inantab[3];
extern f32 D_80807058_inantab[3];
extern f32 D_80807064_inantab[3];
extern f32 D_80807070_inantab[3];
extern f32 D_8080707C_inantab[3];
extern f32 D_80807088_inantab[3];
extern f32 D_80807094_inantab[3];
extern f32 D_808070C8_inantab[2];
extern f32 D_808070D0_inantab[1];
extern f32 D_808070D4_inantab[9];
extern f32 D_808070F8_inantab[10];
extern f32 D_80807120_inantab[9];
extern f32 D_80807144_inantab[10];
extern f32 D_8080716C_inantab[9];
extern f32 D_80807190_inantab[10];
extern f32 D_808071B8_inantab[2];
extern f32 D_808071C0_inantab[2];
extern f32 D_808071C8_inantab[28];
extern f32 D_80807238_inantab[4];
extern f32 D_80807248_inantab[2];
extern f32 D_80807250_inantab[4];
extern f32 D_80807260_inantab[3];
extern f32 D_8080726C_inantab[2];
extern f32 D_80807274_inantab[3];
extern f32 D_80807280_inantab[3];
extern f32 D_8080728C_inantab[3];
extern f32 D_80807298_inantab[3];
extern f32 D_808072A4_inantab[3];
extern f32 D_808072D8_inantab[2];
extern f32 D_808072E0_inantab[11];
extern f32 D_8080730C_inantab[18];
extern f32 D_80807354_inantab[21];
extern f32 D_808073A8_inantab[44];
extern f32 D_80807458_inantab[21];
extern f32 D_808074AC_inantab[12];
extern f32 D_808074DC_inantab[3];
extern f32 D_808074E8_inantab[19];
extern f32 D_80807534_inantab[10];
extern f32 D_8080755C_inantab[1];
extern f32 D_80807560_inantab[3];
extern f32 D_8080756C_inantab[3];
extern f32 D_80807578_inantab[3];
extern f32 D_80807584_inantab[3];
extern f32 D_808075B8_inantab[2];
extern f32 D_808075C0_inantab[3];
extern f32 D_808075CC_inantab[9];
extern f32 D_808075F0_inantab[9];
extern f32 D_80807614_inantab[1];
extern f32 D_80807618_inantab[1];
extern f32 D_8080761C_inantab[9];
extern f32 D_80807640_inantab[9];
extern f32 D_80807664_inantab[8];

/* Keep each table walk on one preprocessed line: IDO's scheduling depends on it. */
#define INANTAB_ANSEQ2(sequence, times, callback, a, b) \
    { s32 i; for (i = 0; i < ARRLEN(times); i++) { \
        _anseq_entrypoint_2(sequence, times[i], callback, a, b); \
    } }
#define INANTAB_ANSEQ3(sequence, times, callback, a, b, c) \
    { s32 i; for (i = 0; i < ARRLEN(times); i++) { \
        _anseq_entrypoint_3(sequence, times[i], callback, a, b, c); \
    } }
#define INANTAB_CHANIM4(sequence, times, actor, part, value) \
    { s32 i; for (i = 0; i < ARRLEN(times); i++) { \
        _chanim_entrypoint_4(sequence, times[i], actor, part, value); \
    } }

/* Sequence callbacks carry the actor pointer as an untyped 32-bit argument. */
#define INANTAB_ARG(actor) (*(s32 *)&(actor))

s32 func_80800020_inantab(s32 arg0, s16 *arg1, Actor *arg2) {
    switch (arg0) {
    case 0x1:
        INANTAB_ANSEQ2(arg1, D_80806F80_inantab, func_800BFCD0, 1, 1);
        INANTAB_ANSEQ2(arg1, D_80806F8C_inantab, func_800BFCD0, 1, 0);
        INANTAB_ANSEQ2(arg1, D_80806F80_inantab, func_800BFCD0, 2, 1);
        INANTAB_ANSEQ2(arg1, D_80806F8C_inantab, func_800BFCD0, 2, 0);
        INANTAB_ANSEQ2(arg1, D_80806F80_inantab, func_800BFCD0, 3, 1);
        INANTAB_ANSEQ2(arg1, D_80806F8C_inantab, func_800BFCD0, 3, 0);
        INANTAB_ANSEQ2(arg1, D_80806F98_inantab, func_800BFCD0, 4, 1);
        INANTAB_ANSEQ2(arg1, D_80806FA4_inantab, func_800BFCD0, 4, 0);
        INANTAB_ANSEQ2(arg1, D_80806F98_inantab, func_800BFCD0, 5, 1);
        INANTAB_ANSEQ2(arg1, D_80806FA4_inantab, func_800BFCD0, 5, 0);
        INANTAB_ANSEQ2(arg1, D_80806F98_inantab, func_800BFCD0, 6, 1);
        INANTAB_ANSEQ2(arg1, D_80806FA4_inantab, func_800BFCD0, 6, 0);
        INANTAB_ANSEQ3(arg1, D_80806F80_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806F8C_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F98_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806FA4_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F80_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806F8C_inantab, _indrv_lights_entrypoint_0, 0x20000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F98_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806FA4_inantab, _indrv_lights_entrypoint_0, 0x20000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F80_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806F8C_inantab, _indrv_lights_entrypoint_0, 0x30000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F98_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806FA4_inantab, _indrv_lights_entrypoint_0, 0x30000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F80_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806F8C_inantab, _indrv_lights_entrypoint_0, 0x40000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F98_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806FA4_inantab, _indrv_lights_entrypoint_0, 0x40000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F80_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806F8C_inantab, _indrv_lights_entrypoint_0, 0x70000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806F98_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80806FA4_inantab, _indrv_lights_entrypoint_0, 0x70000, 0, 0x19);
        INANTAB_ANSEQ3(arg1, D_80806FD8_inantab, _indrv_audio_entrypoint_0, INANTAB_ARG(arg2), 1, -2);
    case 0x2:
    case 0x3:
    case 0x4:
    case 0x5:
    case 0x6:
    case 0x39:
        break;
    case 0x2B:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 0);
        break;
    case 0x2C:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 0);
        break;
    case 0x2D:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 0);
        break;
    case 0x2E:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 0);
        break;
    case 0x2F:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 0);
        break;
    case 0x30:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 1);
        break;
    case 0x31:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 1);
        break;
    case 0x32:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 1);
        break;
    case 0x33:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 1);
        break;
    case 0x5A:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 9, 1);
        _chanim_entrypoint_4(arg1, 0.98f, INANTAB_ARG(arg2), 9, 0);
        break;
    case 0x5B:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 9, 0);
        break;
    case 0x7:
        INANTAB_ANSEQ3(arg1, D_80807038_inantab, _indrv_audio_entrypoint_0, INANTAB_ARG(arg2), 2, -2);
        break;
    case 0x8:
        INANTAB_CHANIM4(arg1, D_80807040_inantab, INANTAB_ARG(arg2), 1, 1);
        INANTAB_CHANIM4(arg1, D_8080704C_inantab, INANTAB_ARG(arg2), 1, 0);
        INANTAB_CHANIM4(arg1, D_80807058_inantab, INANTAB_ARG(arg2), 1, 1);
        INANTAB_CHANIM4(arg1, D_80807064_inantab, INANTAB_ARG(arg2), 1, 0);
        break;
    case 0x9:
        INANTAB_ANSEQ2(arg1, D_80807070_inantab, func_800BFCD0, 1, 1);
        INANTAB_ANSEQ2(arg1, D_8080707C_inantab, func_800BFCD0, 1, 0);
        INANTAB_ANSEQ2(arg1, D_80807070_inantab, func_800BFCD0, 2, 1);
        INANTAB_ANSEQ2(arg1, D_8080707C_inantab, func_800BFCD0, 2, 0);
        INANTAB_ANSEQ2(arg1, D_80807070_inantab, func_800BFCD0, 3, 1);
        INANTAB_ANSEQ2(arg1, D_8080707C_inantab, func_800BFCD0, 3, 0);
        INANTAB_ANSEQ2(arg1, D_80807070_inantab, func_800BFCD0, 4, 1);
        INANTAB_ANSEQ2(arg1, D_8080707C_inantab, func_800BFCD0, 4, 0);
        INANTAB_ANSEQ2(arg1, D_80807070_inantab, func_800BFCD0, 5, 1);
        INANTAB_ANSEQ2(arg1, D_8080707C_inantab, func_800BFCD0, 5, 0);
        INANTAB_ANSEQ2(arg1, D_80807070_inantab, func_800BFCD0, 6, 1);
        INANTAB_ANSEQ2(arg1, D_8080707C_inantab, func_800BFCD0, 6, 0);
        INANTAB_ANSEQ2(arg1, D_80807088_inantab, func_800BFCD0, 1, 1);
        INANTAB_ANSEQ2(arg1, D_80807094_inantab, func_800BFCD0, 1, 0);
        INANTAB_ANSEQ2(arg1, D_80807088_inantab, func_800BFCD0, 2, 1);
        INANTAB_ANSEQ2(arg1, D_80807094_inantab, func_800BFCD0, 2, 0);
        INANTAB_ANSEQ2(arg1, D_80807088_inantab, func_800BFCD0, 3, 1);
        INANTAB_ANSEQ2(arg1, D_80807094_inantab, func_800BFCD0, 3, 0);
        INANTAB_ANSEQ2(arg1, D_80807088_inantab, func_800BFCD0, 4, 1);
        INANTAB_ANSEQ2(arg1, D_80807094_inantab, func_800BFCD0, 4, 0);
        INANTAB_ANSEQ2(arg1, D_80807088_inantab, func_800BFCD0, 5, 1);
        INANTAB_ANSEQ2(arg1, D_80807094_inantab, func_800BFCD0, 5, 0);
        INANTAB_ANSEQ2(arg1, D_80807088_inantab, func_800BFCD0, 6, 1);
        INANTAB_ANSEQ2(arg1, D_80807094_inantab, func_800BFCD0, 6, 0);
        INANTAB_ANSEQ3(arg1, D_80807070_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080707C_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807088_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807094_inantab, _indrv_lights_entrypoint_0, 0x10000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807070_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080707C_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807088_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807094_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807070_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080707C_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807088_inantab, _indrv_lights_entrypoint_0, 0x30000, 0xAECBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807094_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807070_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080707C_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807088_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807094_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807070_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080707C_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807088_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807094_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807070_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080707C_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807088_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807094_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807070_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080707C_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807088_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807094_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_808070C8_inantab, _indrv_audio_entrypoint_0, INANTAB_ARG(arg2), 1, -2);
        break;
    case 0xA:
        INANTAB_ANSEQ3(arg1, D_808070D0_inantab, _indrv_lights_entrypoint_0, 0x60000, 0xFF0000, 0x100);
        break;
    case 0x19:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 6, -1);
        break;
    case 0xB:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 9, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xA, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xB, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 0);
        break;
    case 0x34:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 9, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xA, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xB, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 0);
        break;
    case 0x35:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 9, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xA, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xB, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 0);
        break;
    case 0x38:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 9, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xA, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xB, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 0);
        break;
    case 0x36:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 9, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xA, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xB, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 0);
        break;
    case 0x62:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 9, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 0xA, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 0xB, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 6, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 1);
        break;
    case 0x6A:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0x32, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0x33, 1);
        break;
    case 0x6B:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 9, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xA, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 0xB, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 0);
        break;
    case 0xC:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        break;
    case 0x5C:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        break;
    case 0x5D:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        INANTAB_ANSEQ3(arg1, D_808070D4_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x17, 6);
        INANTAB_ANSEQ3(arg1, D_808070F8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x17, 6);
        _anseq_entrypoint_3(arg1, 0.9152f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 3, -1);
        break;
    case 0x1D:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        INANTAB_ANSEQ3(arg1, D_80807120_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 5);
        INANTAB_ANSEQ3(arg1, D_80807120_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 6);
        INANTAB_ANSEQ3(arg1, D_80807144_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 5);
        INANTAB_ANSEQ3(arg1, D_80807144_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 6);
        break;
    case 0x1E:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        INANTAB_ANSEQ3(arg1, D_8080716C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 5);
        INANTAB_ANSEQ3(arg1, D_8080716C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 6);
        INANTAB_ANSEQ3(arg1, D_80807190_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 5);
        INANTAB_ANSEQ3(arg1, D_80807190_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xD, 6);
        break;
    case 0x56:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 2);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        break;
    case 0x59:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 0);
        _chanim_entrypoint_4(arg1, 0.08f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.97f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x57:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 6, 1);
        break;
    case 0x64:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 6, 1);
        INANTAB_ANSEQ3(arg1, D_808071B8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x19, 4);
        break;
    case 0x4A:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 1, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 2, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 6, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 8, 0);
        break;
    case 0x4B:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 1, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 2, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 6, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 7, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 8, 1);
        break;
    case 0x53:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 2);
        break;
    case 0x65:
        INANTAB_ANSEQ3(arg1, D_808071C0_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x19, 4);
        break;
    case 0x66:
        _anseq_entrypoint_2(arg1, 0.66f, _inantab_entrypoint_0, 4, 1);
        _anseq_entrypoint_2(arg1, 0.66f, _inantab_entrypoint_0, 3, 0);
        break;
    case 0xD:
        INANTAB_ANSEQ3(arg1, D_808071C8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 1, 4);
        INANTAB_ANSEQ3(arg1, D_808071C8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 1, 0xD);
        INANTAB_ANSEQ3(arg1, D_808071C8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 3, 5);
        INANTAB_ANSEQ3(arg1, D_80807238_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 2, 7);
        INANTAB_ANSEQ3(arg1, D_80807248_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 2, 8);
        INANTAB_ANSEQ3(arg1, D_80807250_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 2, 9);
        INANTAB_ANSEQ3(arg1, D_80807260_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 2, 0xA);
        INANTAB_ANSEQ3(arg1, D_8080726C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 2, 0xB);
        INANTAB_ANSEQ3(arg1, D_80807274_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 2, 0xC);
        break;
    case 0xE:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x60:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x63:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        _anseq_entrypoint_3(arg1, 0.001f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 1, -1);
        break;
    case 0xF:
        INANTAB_ANSEQ2(arg1, D_80807280_inantab, func_800BFCD0, 1, 1);
        INANTAB_ANSEQ2(arg1, D_8080728C_inantab, func_800BFCD0, 1, 0);
        INANTAB_ANSEQ2(arg1, D_80807280_inantab, func_800BFCD0, 2, 1);
        INANTAB_ANSEQ2(arg1, D_8080728C_inantab, func_800BFCD0, 2, 0);
        INANTAB_ANSEQ2(arg1, D_80807280_inantab, func_800BFCD0, 3, 1);
        INANTAB_ANSEQ2(arg1, D_8080728C_inantab, func_800BFCD0, 3, 0);
        INANTAB_ANSEQ2(arg1, D_80807280_inantab, func_800BFCD0, 4, 1);
        INANTAB_ANSEQ2(arg1, D_8080728C_inantab, func_800BFCD0, 4, 0);
        INANTAB_ANSEQ2(arg1, D_80807280_inantab, func_800BFCD0, 5, 1);
        INANTAB_ANSEQ2(arg1, D_8080728C_inantab, func_800BFCD0, 5, 0);
        INANTAB_ANSEQ2(arg1, D_80807280_inantab, func_800BFCD0, 6, 1);
        INANTAB_ANSEQ2(arg1, D_8080728C_inantab, func_800BFCD0, 6, 0);
        INANTAB_ANSEQ2(arg1, D_80807298_inantab, func_800BFCD0, 1, 1);
        INANTAB_ANSEQ2(arg1, D_808072A4_inantab, func_800BFCD0, 1, 0);
        INANTAB_ANSEQ2(arg1, D_80807298_inantab, func_800BFCD0, 2, 1);
        INANTAB_ANSEQ2(arg1, D_808072A4_inantab, func_800BFCD0, 2, 0);
        INANTAB_ANSEQ2(arg1, D_80807298_inantab, func_800BFCD0, 3, 1);
        INANTAB_ANSEQ2(arg1, D_808072A4_inantab, func_800BFCD0, 3, 0);
        INANTAB_ANSEQ2(arg1, D_80807298_inantab, func_800BFCD0, 4, 1);
        INANTAB_ANSEQ2(arg1, D_808072A4_inantab, func_800BFCD0, 4, 0);
        INANTAB_ANSEQ2(arg1, D_80807298_inantab, func_800BFCD0, 5, 1);
        INANTAB_ANSEQ2(arg1, D_808072A4_inantab, func_800BFCD0, 5, 0);
        INANTAB_ANSEQ2(arg1, D_80807298_inantab, func_800BFCD0, 6, 1);
        INANTAB_ANSEQ2(arg1, D_808072A4_inantab, func_800BFCD0, 6, 0);
        INANTAB_ANSEQ3(arg1, D_80807280_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080728C_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807298_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_808072A4_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807280_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080728C_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807298_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_808072A4_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807280_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080728C_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807298_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_808072A4_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807280_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080728C_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807298_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_808072A4_inantab, _indrv_lights_entrypoint_0, 0x70000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807280_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080728C_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807298_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_808072A4_inantab, _indrv_lights_entrypoint_0, 0x80000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_808072D8_inantab, _indrv_audio_entrypoint_0, INANTAB_ARG(arg2), 1, -2);
        break;
    case 0x10:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        _anseq_entrypoint_3(arg1, 0.001f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 2, -1);
        INANTAB_ANSEQ3(arg1, D_808072E0_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 4, 4);
        INANTAB_ANSEQ3(arg1, D_8080730C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 4, 5);
        INANTAB_ANSEQ3(arg1, D_80807354_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 4, 6);
        INANTAB_ANSEQ3(arg1, D_808073A8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 5, 7);
        break;
    case 0x11:
        _anseq_entrypoint_3(arg1, 0.697f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 3, -1);
        _anseq_entrypoint_3(arg1, 0.99f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 3, -1);
        INANTAB_ANSEQ3(arg1, D_80807458_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 5, 8);
        INANTAB_ANSEQ3(arg1, D_808074AC_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 5, 8);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        break;
    case 0x12:
        INANTAB_ANSEQ3(arg1, D_808074DC_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 5, 8);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        break;
    case 0x1A:
        INANTAB_ANSEQ3(arg1, D_808074E8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xA, 0xA);
        INANTAB_ANSEQ3(arg1, D_808074E8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xA, 0xB);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        break;
    case 0x13:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x14:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x15:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 1);
        _anseq_entrypoint_3(arg1, 0.44f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 4, -1);
        break;
    case 0x51:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x52:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x16:
        INANTAB_ANSEQ3(arg1, D_80807534_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x15, 4);
        _anseq_entrypoint_3(arg1, 0.8f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 5, -1);
        INANTAB_ANSEQ3(arg1, D_8080755C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 8, 4);
        INANTAB_ANSEQ3(arg1, D_8080755C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 8, 4);
        break;
    case 0x17:
        INANTAB_ANSEQ2(arg1, D_80807560_inantab, func_800BFCD0, 1, 1);
        INANTAB_ANSEQ2(arg1, D_8080756C_inantab, func_800BFCD0, 1, 0);
        INANTAB_ANSEQ2(arg1, D_80807560_inantab, func_800BFCD0, 2, 1);
        INANTAB_ANSEQ2(arg1, D_8080756C_inantab, func_800BFCD0, 2, 0);
        INANTAB_ANSEQ2(arg1, D_80807560_inantab, func_800BFCD0, 3, 1);
        INANTAB_ANSEQ2(arg1, D_8080756C_inantab, func_800BFCD0, 3, 0);
        INANTAB_ANSEQ2(arg1, D_80807560_inantab, func_800BFCD0, 4, 1);
        INANTAB_ANSEQ2(arg1, D_8080756C_inantab, func_800BFCD0, 4, 0);
        INANTAB_ANSEQ2(arg1, D_80807560_inantab, func_800BFCD0, 5, 1);
        INANTAB_ANSEQ2(arg1, D_8080756C_inantab, func_800BFCD0, 5, 0);
        INANTAB_ANSEQ2(arg1, D_80807560_inantab, func_800BFCD0, 6, 1);
        INANTAB_ANSEQ2(arg1, D_8080756C_inantab, func_800BFCD0, 6, 0);
        INANTAB_ANSEQ2(arg1, D_80807578_inantab, func_800BFCD0, 1, 1);
        INANTAB_ANSEQ2(arg1, D_80807584_inantab, func_800BFCD0, 1, 0);
        INANTAB_ANSEQ2(arg1, D_80807578_inantab, func_800BFCD0, 2, 1);
        INANTAB_ANSEQ2(arg1, D_80807584_inantab, func_800BFCD0, 2, 0);
        INANTAB_ANSEQ2(arg1, D_80807578_inantab, func_800BFCD0, 3, 1);
        INANTAB_ANSEQ2(arg1, D_80807584_inantab, func_800BFCD0, 3, 0);
        INANTAB_ANSEQ2(arg1, D_80807578_inantab, func_800BFCD0, 4, 1);
        INANTAB_ANSEQ2(arg1, D_80807584_inantab, func_800BFCD0, 4, 0);
        INANTAB_ANSEQ2(arg1, D_80807578_inantab, func_800BFCD0, 5, 1);
        INANTAB_ANSEQ2(arg1, D_80807584_inantab, func_800BFCD0, 5, 0);
        INANTAB_ANSEQ2(arg1, D_80807578_inantab, func_800BFCD0, 6, 1);
        INANTAB_ANSEQ2(arg1, D_80807584_inantab, func_800BFCD0, 6, 0);
        INANTAB_ANSEQ3(arg1, D_80807560_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080756C_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807578_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x7CCBFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807584_inantab, _indrv_lights_entrypoint_0, 0x20000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807560_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080756C_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807578_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807584_inantab, _indrv_lights_entrypoint_0, 0x30000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807560_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080756C_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807578_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807584_inantab, _indrv_lights_entrypoint_0, 0x40000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807560_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080756C_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807578_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807584_inantab, _indrv_lights_entrypoint_0, 0x50000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807560_inantab, _indrv_lights_entrypoint_0, 0x60000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_8080756C_inantab, _indrv_lights_entrypoint_0, 0x60000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_80807578_inantab, _indrv_lights_entrypoint_0, 0x60000, 0x95AFFF00, 0);
        INANTAB_ANSEQ3(arg1, D_80807584_inantab, _indrv_lights_entrypoint_0, 0x60000, 0x6D87FF00, 0x19);
        INANTAB_ANSEQ3(arg1, D_808075B8_inantab, _indrv_audio_entrypoint_0, INANTAB_ARG(arg2), 1, -2);
        break;
    case 0x18:
        INANTAB_ANSEQ3(arg1, D_808075C0_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 9, 4);
        break;
    case 0x1B:
        INANTAB_ANSEQ3(arg1, D_808075CC_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xB, 4);
        break;
    case 0x28:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 7, -1);
        break;
    case 0x29:
        INANTAB_ANSEQ3(arg1, D_808075F0_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x10, 4);
        break;
    case 0x2A:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 3, -1);
        break;
    case 0x3A:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 8, -1);
        break;
    case 0x3B:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 9, -1);
        break;
    case 0x3C:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 0xA, -1);
        break;
    case 0x3D:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 0xB, -1);
        break;
    case 0x3E:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 0xC, -1);
        break;
    case 0x44:
        _anseq_entrypoint_3(arg1, 0.01f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 0xD, -1);
        break;
    case 0x45:
        INANTAB_ANSEQ3(arg1, D_80807614_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x11, 4);
        break;
    case 0x46:
        INANTAB_ANSEQ3(arg1, D_80807618_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x12, 4);
        break;
    case 0x1C:
        INANTAB_ANSEQ3(arg1, D_8080761C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xC, 4);
        break;
    case 0x58:
        INANTAB_ANSEQ3(arg1, D_80807640_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x16, 4);
        break;
    case 0x5E:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 2);
        break;
    case 0x5F:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x1F:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _anseq_entrypoint_3(arg1, 0.33f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 3, -1);
        _anseq_entrypoint_3(arg1, 0.669f, _inantab_entrypoint_3, INANTAB_ARG(arg2), 3, -1);
        break;
    case 0x20:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x21:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x22:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.03f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.426f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.934f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.934f, INANTAB_ARG(arg2), 4, 0);
        break;
    case 0x23:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x24:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        INANTAB_ANSEQ3(arg1, D_80807664_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xE, 4);
        INANTAB_ANSEQ3(arg1, D_80807664_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xE, 5);
        break;
    default:
        return 0;
    }
    return 1;
}

void _anseq_entrypoint_4(s16 *, f32, void *, s32, s32, s32, s32);
void _chanim_entrypoint_5(s16 *, f32, s32, s32, s32);
void _inantab_entrypoint_1();
extern f32 D_80807684_inantab[21];
extern f32 D_808076D8_inantab[17];
extern f32 D_8080771C_inantab[9];
extern f32 D_80807740_inantab[9];
extern f32 D_80807764_inantab[1];
extern f32 D_80807768_inantab[1];
extern f32 D_8080776C_inantab[1];
extern f32 D_80807770_inantab[3];
extern f32 D_8080777C_inantab[1];

s32 func_808057BC_inantab(s32 arg0, s16 *arg1, Actor *arg2) {
    switch (arg0) {
    case 0x26:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        INANTAB_ANSEQ3(arg1, D_80807684_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xE, 4);
        INANTAB_ANSEQ3(arg1, D_80807684_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xE, 5);
        INANTAB_ANSEQ3(arg1, D_808076D8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xE, 4);
        INANTAB_ANSEQ3(arg1, D_808076D8_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xE, 5);
        break;
    case 0x37:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 0);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.03f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.426f, INANTAB_ARG(arg2), 4, 1);
        _chanim_entrypoint_4(arg1, 0.934f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.934f, INANTAB_ARG(arg2), 4, 0);
        break;
    case 0x25:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.0348f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.418f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x67:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.0312f, INANTAB_ARG(arg2), 3, 1);
        break;
    case 0x27:
        INANTAB_ANSEQ3(arg1, D_8080771C_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0xF, 4);
        _anseq_entrypoint_3(arg1, 0.1f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.15f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.2f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.25f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.3f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.35f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.4f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.45f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.5f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.55f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.6f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.65f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.7f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.75f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.8f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.85f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.9f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.95f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        _anseq_entrypoint_3(arg1, 0.99f, _indrv_lights_entrypoint_0, 0x70006, INANTAB_ARG(arg2), 4);
        break;
    case 0x3F:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 2, 3);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 1);
        break;
    case 0x40:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 2, 1);
        break;
    case 0x41:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 4, 2);
        break;
    case 0x42:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 2);
        break;
    case 0x43:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 2, 2);
        break;
    case 0x47:
        _anseq_entrypoint_4(arg1, 0.0f, _inantab_entrypoint_1, INANTAB_ARG(arg2), 0, 0x100, 0x200);
        _anseq_entrypoint_4(arg1, 0.5f, _inantab_entrypoint_1, INANTAB_ARG(arg2), 0, 0x100, 0x200);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 1, 0);
        _chanim_entrypoint_4(arg1, 0.5f, INANTAB_ARG(arg2), 1, 1);
        _chanim_entrypoint_5(arg1, -1.0f, INANTAB_ARG(arg2), 2, 4);
        break;
    case 0x48:
        INANTAB_ANSEQ3(arg1, D_80807740_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x13, -1);
        break;
    case 0x49:
        INANTAB_ANSEQ3(arg1, D_80807764_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x14, -1);
        INANTAB_ANSEQ3(arg1, D_80807768_inantab, _indrv_lights_entrypoint_0, 0x30000, -0x100, 0);
        INANTAB_ANSEQ3(arg1, D_8080776C_inantab, _indrv_lights_entrypoint_0, 0x30000, 0, 0x4C);
        break;
    case 0x4C:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x4D:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x4E:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x4F:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 0);
        break;
    case 0x50:
        _chanim_entrypoint_4(arg1, 0.01f, INANTAB_ARG(arg2), 3, 1);
        INANTAB_ANSEQ3(arg1, D_80807770_inantab, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x18, 4);
        break;
    case 0x54:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        break;
    case 0x55:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 1);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 0);
        break;
    case 0x61:
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 3, 0);
        _chanim_entrypoint_4(arg1, 0.0f, INANTAB_ARG(arg2), 5, 1);
        break;
    case 0x68:
        _anseq_entrypoint_3(arg1, 0.1f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1A, 4);
        _anseq_entrypoint_3(arg1, 0.2f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1B, 5);
        _anseq_entrypoint_3(arg1, 0.3f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1C, 6);
        _anseq_entrypoint_3(arg1, 0.4f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1D, 7);
        _anseq_entrypoint_3(arg1, 0.5f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1E, 8);
        _anseq_entrypoint_3(arg1, 0.15f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1A, 6);
        _anseq_entrypoint_3(arg1, 0.25f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1B, 9);
        _anseq_entrypoint_3(arg1, 0.35f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1C, 0xA);
        _anseq_entrypoint_3(arg1, 0.6f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1D, 0xB);
        _anseq_entrypoint_3(arg1, 0.7f, _indrv_fx_entrypoint_0, INANTAB_ARG(arg2), 0x1E, 0xC);
        INANTAB_ANSEQ3(arg1, D_8080777C_inantab, _indrv_audio_entrypoint_0, INANTAB_ARG(arg2), 0xB5, -2);
        break;
    default:
        return 0;
    }
    return 1;
}

#undef INANTAB_ANSEQ2
#undef INANTAB_ANSEQ3
#undef INANTAB_CHANIM4
#undef INANTAB_ARG


/* extern */

void func_808064DC_inantab(s32 arg0, s16 *arg1, Actor *arg2) {
    s32 func_808057BC_inantab(s32, s16 *, Actor *);
    if (func_80800020_inantab(arg0, arg1, arg2) == 0) {
        func_808057BC_inantab(arg0, arg1, arg2);
    }
}

/* extern */

void inantab_entrypoint_1(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 func_800DC178(f32, f32);
    void func_80101CDC(Actor *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp1C;
    s32 pad;

    sp1C = func_80106790(arg0);
    if (arg1 == 0) {
        func_80101CDC(sp1C, func_800DC178((f32) arg2 * 0.00390625f, (f32) arg3 * 0.00390625f));
    }
}

void inantab_entrypoint_2(s32 arg0,s32 arg1)
{
    func_8010114C(arg0,0x5A,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/in/antab/inantab_entrypoint_3.s")

void inantab_entrypoint_4(s32 arg0, Actor *arg1, s16 *arg2, s16 arg3) {
    extern s16 *D_80806D5C_inantab[];
    s16 var_s0;
    s16 *var_v0;

    var_v0 = D_80806D5C_inantab[arg0];
    var_s0 = var_v0[1];
    if (var_s0 != 0) {
loop_1:
        if (arg3 == var_v0[0]) {
            func_808064DC_inantab((s32) var_s0, arg2, arg1);
            return;
        }
        var_s0 = var_v0[3];
        var_v0 += 2;
        if (var_s0 == 0) {

        } else {
            goto loop_1;
        }
    }
}
