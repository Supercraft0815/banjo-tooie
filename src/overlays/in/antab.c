#include "common.h"

void inantab_entrypoint_0(BT_NATIVE_ONLY(s32 bt_a0 BT_PASS2(, s32 bt_a1)))
{
    BT_NATIVE_ONLY(void func_800BF744(s32, s32);)
    func_800BF744(BT_PASS2(bt_a0, bt_a1));
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
typedef struct { f32 volume; f32 pitch; f32 duration; f32 pan; u8 *data; u8 priority; u8 sound; u8 pad[2]; } SoundEntry;
void inantab_entrypoint_3(s32 arg0, s32 arg1, s32 arg2) {










    void func_800E13F0(s32, f32);
    void func_800E1410(s32, f32, f32);
    void func_800E144C(s32, f32);
    s32 func_800E1540(s32);
    s32 func_800E1664(s32, f32, f32, f32 *, u8 *, s16);
    extern SoundEntry D_80806E30_inantab[];
    s32 sound;
    s32 handle;

    sound = D_80806E30_inantab[arg1].sound;
    if (D_80806E30_inantab[arg1].data != NULL) {
        func_800E1664(D_80806E30_inantab[arg1].sound, D_80806E30_inantab[arg1].volume, D_80806E30_inantab[arg1].duration, NULL, D_80806E30_inantab[arg1].data, D_80806E30_inantab[arg1].priority);
    } else {
        handle = func_800E1540(sound);
        if (-1.0f != D_80806E30_inantab[arg1].volume) {
            func_800E13F0(handle, D_80806E30_inantab[arg1].volume);
        }
        if (-1.0f != D_80806E30_inantab[arg1].pitch) {
            func_800E1410(handle, D_80806E30_inantab[arg1].pitch, D_80806E30_inantab[arg1].duration);
        }
        if (-1.0f != D_80806E30_inantab[arg1].pan) {
            func_800E144C(handle, D_80806E30_inantab[arg1].pan);
        }
    }
}

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
/* data_to_c.py: from asm/data/overlays/in/antab.data.s */
extern u8 D_80806AB8_inantab[];
extern u8 D_80806AC0_inantab[];
extern u8 D_80806AC8_inantab[];
extern u8 D_80806AB0_inantab[];
extern u8 D_80806AA8_inantab[];
extern u8 D_80806AD0_inantab[];
extern u8 D_80806AD8_inantab[];
extern u8 D_80806B20_inantab[];
extern u8 D_80806B28_inantab[];
extern u8 D_80806B30_inantab[];
extern u8 D_80806B40_inantab[];
extern u8 D_80806B48_inantab[];
extern u8 D_80806B90_inantab[];
extern u8 D_80806C0C_inantab[];
extern u8 D_80806C14_inantab[];
extern u8 D_80806C24_inantab[];
extern u8 D_80806C38_inantab[];
extern u8 D_80806C5C_inantab[];
extern u8 D_80806C68_inantab[];
extern u8 D_80806C70_inantab[];
extern u8 D_80806C78_inantab[];
extern u8 D_80806CB8_inantab[];
extern u8 D_80806CC0_inantab[];
extern u8 D_80806CE4_inantab[];
extern u8 D_80806CF0_inantab[];
extern u8 D_80806CF8_inantab[];
extern u8 D_80806D10_inantab[];
extern u8 D_80806A90_inantab[];
extern u8 D_80806D20_inantab[];
extern u8 D_80806D38_inantab[];
extern u8 D_80806D40_inantab[];
extern u8 D_80806D48_inantab[];
extern u8 D_80806D50_inantab[];
extern u8 D_80806D58_inantab[];
extern u8 D_80806E00_inantab[];
extern u8 D_80806DE8_inantab[];
extern u8 D_80806E18_inantab[];
u8 D_80806A90_inantab[24] BT_DATA(4, overlays_in_antab, 0x0) = { 0x04, 0xDD, 0x00, 0x4C, 0x04, 0xEC, 0x00, 0x4D, 0x04, 0xED, 0x00, 0x50, 0x04, 0xEE, 0x00, 0x4E, 0x04, 0xEF, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806AA8_inantab[8] BT_DATA(4, overlays_in_antab, 0x18) = { 0x03, 0x88, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806AB0_inantab[8] BT_DATA(4, overlays_in_antab, 0x20) = { 0x03, 0x88, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806AB8_inantab[8] BT_DATA(4, overlays_in_antab, 0x28) = { 0x03, 0x88, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806AC0_inantab[8] BT_DATA(4, overlays_in_antab, 0x30) = { 0x03, 0x88, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806AC8_inantab[8] BT_DATA(4, overlays_in_antab, 0x38) = { 0x03, 0x88, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806AD0_inantab[8] BT_DATA(4, overlays_in_antab, 0x40) = { 0x03, 0x88, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806AD8_inantab[72] BT_DATA(4, overlays_in_antab, 0x48) = { 0x03, 0x88, 0x00, 0x06, 0x04, 0x19, 0x00, 0x2B, 0x00, 0xB4, 0x00, 0x2C, 0x04, 0x4B, 0x00, 0x2D, 0x04, 0x61, 0x00, 0x2E, 0x04, 0x62, 0x00, 0x2F, 0x04, 0x67, 0x00, 0x30, 0x04, 0x65, 0x00, 0x31, 0x04, 0x68, 0x00, 0x32, 0x04, 0x6A, 0x00, 0x33, 0x05, 0x1F, 0x00, 0x5A, 0x04, 0xF5, 0x00, 0x5B, 0x04, 0xF6, 0x00, 0x5B, 0x05, 0x0F, 0x00, 0x5B, 0x05, 0x14, 0x00, 0x5B, 0x04, 0x73, 0x00, 0x5B, 0x00, 0xB5, 0x00, 0x5B, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806B20_inantab[8] BT_DATA(4, overlays_in_antab, 0x90) = { 0x03, 0x88, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806B28_inantab[8] BT_DATA(4, overlays_in_antab, 0x98) = { 0x03, 0xA5, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806B30_inantab[16] BT_DATA(4, overlays_in_antab, 0xA0) = { 0x03, 0x88, 0x00, 0x09, 0x03, 0x8F, 0x00, 0x0F, 0x04, 0x08, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806B40_inantab[8] BT_DATA(4, overlays_in_antab, 0xB0) = { 0x04, 0x08, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806B48_inantab[72] BT_DATA(4, overlays_in_antab, 0xB8) = { 0x00, 0x0C, 0x00, 0x36, 0x04, 0x09, 0x00, 0x0B, 0x04, 0x72, 0x00, 0x34, 0x04, 0x71, 0x00, 0x35, 0x04, 0x90, 0x00, 0x36, 0x04, 0x8E, 0x00, 0x38, 0x00, 0x6F, 0x00, 0x36, 0x00, 0xAE, 0x00, 0x36, 0x00, 0xA4, 0x00, 0x6A, 0x05, 0x2D, 0x00, 0x36, 0x05, 0x2E, 0x00, 0x36, 0x05, 0x2F, 0x00, 0x36, 0x05, 0x30, 0x00, 0x36, 0x05, 0x20, 0x00, 0x36, 0x05, 0x21, 0x00, 0x36, 0x05, 0x22, 0x00, 0x36, 0x05, 0x36, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806B90_inantab[124] BT_DATA(4, overlays_in_antab, 0x100) = { 0x04, 0x0B, 0x00, 0x0C, 0x04, 0x6B, 0x00, 0x0C, 0x04, 0x6C, 0x00, 0x0C, 0x04, 0x6D, 0x00, 0x0C, 0x04, 0x6E, 0x00, 0x0C, 0x04, 0x6F, 0x00, 0x0C, 0x04, 0x5F, 0x00, 0x1D, 0x04, 0x60, 0x00, 0x1E, 0x05, 0x10, 0x00, 0x56, 0x05, 0x17, 0x00, 0x5C, 0x05, 0x18, 0x00, 0x5C, 0x05, 0x19, 0x00, 0x5D, 0x05, 0x1A, 0x00, 0x59, 0x05, 0x1D, 0x00, 0x5C, 0x05, 0x11, 0x00, 0x56, 0x05, 0x12, 0x00, 0x56, 0x05, 0x13, 0x00, 0x64, 0x05, 0x15, 0x00, 0x57, 0x05, 0x16, 0x00, 0x57, 0x02, 0xC8, 0x00, 0x4A, 0x05, 0x1E, 0x00, 0x4A, 0x05, 0x24, 0x00, 0x4A, 0x05, 0x25, 0x00, 0x4A, 0x05, 0x26, 0x00, 0x4A, 0x05, 0x27, 0x00, 0x4A, 0x05, 0x37, 0x00, 0x4A, 0x05, 0x38, 0x00, 0x4B, 0x05, 0x0A, 0x00, 0x53, 0x05, 0x0B, 0x00, 0x53, 0x05, 0x0C, 0x00, 0x53, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C0C_inantab[8] BT_DATA(4, overlays_in_antab, 0x17C) = { 0x03, 0xAB, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C14_inantab[16] BT_DATA(4, overlays_in_antab, 0x184) = { 0x03, 0x88, 0x00, 0x0E, 0x00, 0x4F, 0x00, 0x60, 0x04, 0x75, 0x00, 0x63, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C24_inantab[20] BT_DATA(4, overlays_in_antab, 0x194) = { 0x04, 0x0F, 0x00, 0x10, 0x04, 0x11, 0x00, 0x11, 0x04, 0x12, 0x00, 0x12, 0x04, 0x48, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C38_inantab[36] BT_DATA(4, overlays_in_antab, 0x1A8) = { 0x04, 0x15, 0x00, 0x13, 0x04, 0x14, 0x00, 0x14, 0x04, 0x17, 0x00, 0x15, 0x04, 0xF0, 0x00, 0x51, 0x04, 0xF1, 0x00, 0x52, 0x04, 0x5A, 0x00, 0x13, 0x04, 0x5E, 0x00, 0x13, 0x05, 0x0E, 0x00, 0x51, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C5C_inantab[12] BT_DATA(4, overlays_in_antab, 0x1CC) = { 0x04, 0x22, 0x00, 0x16, 0x04, 0x74, 0x00, 0x39, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C68_inantab[8] BT_DATA(4, overlays_in_antab, 0x1D8) = { 0x04, 0x13, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C70_inantab[8] BT_DATA(4, overlays_in_antab, 0x1E0) = { 0x03, 0x88, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806C78_inantab[64] BT_DATA(4, overlays_in_antab, 0x1E8) = { 0x03, 0x88, 0x00, 0x1B, 0x03, 0x8F, 0x00, 0x28, 0x03, 0x90, 0x00, 0x29, 0x04, 0x0C, 0x00, 0x2A, 0x00, 0x8F, 0x00, 0x3A, 0x03, 0x9B, 0x00, 0x3B, 0x03, 0x9C, 0x00, 0x3C, 0x03, 0xA2, 0x00, 0x3D, 0x03, 0xA5, 0x00, 0x3E, 0x00, 0x53, 0x00, 0x44, 0x04, 0x17, 0x00, 0x45, 0x04, 0x18, 0x00, 0x46, 0x04, 0x19, 0x00, 0x58, 0x03, 0xAA, 0x00, 0x5F, 0x04, 0x52, 0x00, 0x5E, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806CB8_inantab[8] BT_DATA(4, overlays_in_antab, 0x228) = { 0x03, 0x88, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806CC0_inantab[36] BT_DATA(4, overlays_in_antab, 0x230) = { 0x04, 0x46, 0x00, 0x1F, 0x04, 0x49, 0x00, 0x20, 0x04, 0x4A, 0x00, 0x21, 0x04, 0x51, 0x00, 0x22, 0x04, 0x4F, 0x00, 0x23, 0x04, 0x50, 0x00, 0x24, 0x04, 0x92, 0x00, 0x37, 0x04, 0x54, 0x00, 0x26, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806CE4_inantab[12] BT_DATA(4, overlays_in_antab, 0x254) = { 0x04, 0x52, 0x00, 0x25, 0x05, 0x41, 0x00, 0x67, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806CF0_inantab[8] BT_DATA(4, overlays_in_antab, 0x260) = { 0x03, 0x88, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806CF8_inantab[24] BT_DATA(4, overlays_in_antab, 0x268) = { 0x03, 0x88, 0x00, 0x3F, 0x03, 0x8F, 0x00, 0x40, 0x03, 0x90, 0x00, 0x41, 0x02, 0x5C, 0x00, 0x42, 0x02, 0x64, 0x00, 0x43, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806D10_inantab[16] BT_DATA(4, overlays_in_antab, 0x280) = { 0x03, 0x88, 0x00, 0x47, 0x03, 0x8F, 0x00, 0x48, 0x03, 0x90, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806D20_inantab[24] BT_DATA(4, overlays_in_antab, 0x290) = { 0x04, 0xFD, 0x00, 0x54, 0x05, 0x02, 0x00, 0x55, 0x05, 0x09, 0x00, 0x54, 0x05, 0x35, 0x00, 0x61, 0x05, 0x33, 0x00, 0x61, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806D38_inantab[8] BT_DATA(4, overlays_in_antab, 0x2A8) = { 0x04, 0xF4, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806D40_inantab[8] BT_DATA(4, overlays_in_antab, 0x2B0) = { 0x05, 0x40, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806D48_inantab[8] BT_DATA(4, overlays_in_antab, 0x2B8) = { 0x03, 0x88, 0x00, 0x68, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806D50_inantab[8] BT_DATA(4, overlays_in_antab, 0x2C0) = { 0x03, 0x88, 0x00, 0x69, 0x00, 0x00, 0x00, 0x00 };
u8 D_80806D58_inantab[4] BT_DATA(4, overlays_in_antab, 0x2C8) = { 0x00, 0x6F, 0x00, 0x6B };
s16 * D_80806D5C_inantab [35] BT_DATA(4, overlays_in_antab, 0x2CC) = { 0, (short *)D_80806AB8_inantab, (short *)D_80806AC0_inantab, (short *)D_80806AC8_inantab, (short *)D_80806AB0_inantab, (short *)D_80806AA8_inantab, (short *)D_80806AD0_inantab, (short *)D_80806AD8_inantab, (short *)D_80806B20_inantab, (short *)D_80806B28_inantab, (short *)D_80806B30_inantab, (short *)D_80806B40_inantab, (short *)D_80806B48_inantab, (short *)D_80806B90_inantab, (short *)D_80806C0C_inantab, (short *)D_80806C14_inantab, (short *)D_80806C24_inantab, (short *)D_80806C38_inantab, (short *)D_80806C5C_inantab, (short *)D_80806C68_inantab, (short *)D_80806C70_inantab, (short *)D_80806C78_inantab, (short *)D_80806CB8_inantab, (short *)D_80806CC0_inantab, (short *)D_80806CE4_inantab, (short *)D_80806CF0_inantab, (short *)D_80806CF8_inantab, (short *)D_80806D10_inantab, (short *)D_80806A90_inantab, (short *)D_80806D20_inantab, (short *)D_80806D38_inantab, (short *)D_80806D40_inantab, (short *)D_80806D48_inantab, (short *)D_80806D50_inantab, (short *)D_80806D58_inantab };
u8 D_80806DE8_inantab[24] BT_DATA(4, overlays_in_antab, 0x358) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x33, 0x33, 0x33, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00 };
u8 D_80806E00_inantab[24] BT_DATA(4, overlays_in_antab, 0x370) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x33, 0x33, 0x33, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00 };
u8 D_80806E18_inantab[24] BT_DATA(4, overlays_in_antab, 0x388) = { 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00 };
SoundEntry D_80806E30_inantab [14] BT_DATA(4, overlays_in_antab, 0x3A0) = { { 3.5f, 0.02f, 20.0f, 0.001f, 0, 0, 0, { 0, 0 } }, { 0.9f, 0.001f, 40.0f, 0.001f, 0, 0, 0, { 0, 0 } }, { 2.2f, 0.001f, 17.7f, 0.9f, 0, 0, 0, { 0, 0 } }, { 1.8f, 0.001f, 0.28f, 0.8f, 0, 0, 0, { 0, 0 } }, { 4.8f, 0.001f, 0.28f, 0.8f, 0, 0, 0, { 0, 0 } }, { 24.8f, 0.001f, 0.75f, 0.7f, 0, 0, 2, { 0, 0 } }, { 0.8f, 0.0f, 20.0f, 0.0f, (unsigned char *)D_80806E00_inantab, 3, 0, { 0, 0 } }, { 0.2f, 0.0f, 4.0f, 0.0f, (unsigned char *)D_80806E00_inantab, 3, 0, { 0, 0 } }, { 2.2f, 0.0f, 16.0f, 0.0f, (unsigned char *)D_80806DE8_inantab, 3, 0, { 0, 0 } }, { 70.8f, 0.001f, 0.35f, 0.5f, 0, 0, 2, { 0, 0 } }, { 5.5f, 0.0f, 9.0f, 0.0f, (unsigned char *)D_80806E18_inantab, 3, 0, { 0, 0 } }, { 8.6f, 0.0f, 9.0f, 0.0f, (unsigned char *)D_80806E18_inantab, 3, 0, { 0, 0 } }, { 5.5f, 0.0f, 30.0f, 0.0f, (unsigned char *)D_80806E18_inantab, 3, 0, { 0, 0 } }, { 1.5f, 0.0f, 8.0f, 0.0f, (unsigned char *)D_80806E18_inantab, 3, 0, { 0, 0 } } };
f32 D_80806F80_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x4F0) = { 0.2f, 0.24f, 0.26f };
f32 D_80806F8C_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x4FC) = { 0.22f, 0.25f, 0.27f };
f32 D_80806F98_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x508) = { 0.3f, 0.33f, 0.35f };
f32 D_80806FA4_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x514) = { 0.31f, 0.34f, 0.36f };
u8 D_80806FB0_inantab[40] BT_DATA(4, overlays_in_antab, 0x520) = { 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x54, 0x7A, 0xE1, 0x3F, 0x59, 0x99, 0x9A, 0x3F, 0x4F, 0x5C, 0x29, 0x3F, 0x57, 0x0A, 0x3D, 0x3F, 0x5C, 0x28, 0xF6, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x6E, 0x14, 0x7B, 0x3F, 0x68, 0xF5, 0xC3, 0x3F, 0x6E, 0x14, 0x7B };
f32 D_80806FD8_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x548) = { 0.265f, 0.865f };
u8 D_80806FE0_inantab[88] BT_DATA(4, overlays_in_antab, 0x550) = { 0x3E, 0x4C, 0xCC, 0xCD, 0x3E, 0x75, 0xC2, 0x8F, 0x3E, 0x85, 0x1E, 0xB8, 0x3E, 0x61, 0x47, 0xAE, 0x3E, 0x80, 0x00, 0x00, 0x3E, 0x8A, 0x3D, 0x71, 0x3E, 0x99, 0x99, 0x9A, 0x3E, 0xA8, 0xF5, 0xC3, 0x3E, 0xB3, 0x33, 0x33, 0x3E, 0x9E, 0xB8, 0x52, 0x3E, 0xAE, 0x14, 0x7B, 0x3E, 0xB8, 0x51, 0xEC, 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x54, 0x7A, 0xE1, 0x3F, 0x59, 0x99, 0x9A, 0x3F, 0x4F, 0x5C, 0x29, 0x3F, 0x57, 0x0A, 0x3D, 0x3F, 0x5C, 0x28, 0xF6, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x6E, 0x14, 0x7B, 0x3F, 0x68, 0xF5, 0xC3, 0x3F, 0x6E, 0x14, 0x7B };
f32 D_80807038_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x5A8) = { 0.265f, 0.865f };
f32 D_80807040_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x5B0) = { 0.2f, 0.24f, 0.26f };
f32 D_8080704C_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x5BC) = { 0.22f, 0.25f, 0.27f };
f32 D_80807058_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x5C8) = { 0.3f, 0.33f, 0.35f };
f32 D_80807064_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x5D4) = { 0.31f, 0.34f, 0.36f };
f32 D_80807070_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x5E0) = { 0.2f, 0.24f, 0.26f };
f32 D_8080707C_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x5EC) = { 0.22f, 0.25f, 0.27f };
f32 D_80807088_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x5F8) = { 0.3f, 0.33f, 0.35f };
f32 D_80807094_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x604) = { 0.31f, 0.34f, 0.36f };
u8 D_808070A0_inantab[40] BT_DATA(4, overlays_in_antab, 0x610) = { 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x54, 0x7A, 0xE1, 0x3F, 0x59, 0x99, 0x9A, 0x3F, 0x4F, 0x5C, 0x29, 0x3F, 0x57, 0x0A, 0x3D, 0x3F, 0x5C, 0x28, 0xF6, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x6E, 0x14, 0x7B, 0x3F, 0x68, 0xF5, 0xC3, 0x3F, 0x6E, 0x14, 0x7B };
f32 D_808070C8_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x638) = { 0.265f, 0.865f };
f32 D_808070D0_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0x640) = { 0.33f };
f32 D_808070D4_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0x644) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_808070F8_inantab [ 10 ] BT_DATA(4, overlays_in_antab, 0x668) = { 0.05f, 0.15f, 0.25f, 0.35f, 0.45f, 0.55f, 0.65f, 0.75f, 0.85f, 0.95f };
f32 D_80807120_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0x690) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807144_inantab [ 10 ] BT_DATA(4, overlays_in_antab, 0x6B4) = { 0.05f, 0.15f, 0.25f, 0.35f, 0.45f, 0.55f, 0.65f, 0.75f, 0.85f, 0.95f };
f32 D_8080716C_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0x6DC) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807190_inantab [ 10 ] BT_DATA(4, overlays_in_antab, 0x700) = { 0.05f, 0.15f, 0.25f, 0.35f, 0.45f, 0.55f, 0.65f, 0.75f, 0.85f, 0.95f };
f32 D_808071B8_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x728) = { 0.25f, 0.75f };
f32 D_808071C0_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x730) = { 0.25f, 0.75f };
f32 D_808071C8_inantab [ 28 ] BT_DATA(4, overlays_in_antab, 0x738) = { 0.33f, 0.34f, 0.35f, 0.36f, 0.37f, 0.38f, 0.39f, 0.4f, 0.41f, 0.42f, 0.43f, 0.44f, 0.45f, 0.46f, 0.47f, 0.48f, 0.49f, 0.5f, 0.51f, 0.52f, 0.53f, 0.54f, 0.55f, 0.56f, 0.57f, 0.58f, 0.59f, 0.6f };
f32 D_80807238_inantab [ 4 ] BT_DATA(4, overlays_in_antab, 0x7A8) = { 0.2805f, 0.2937f, 0.3076f, 0.3336f };
f32 D_80807248_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x7B8) = { 0.1247f, 0.1561f };
f32 D_80807250_inantab [ 4 ] BT_DATA(4, overlays_in_antab, 0x7C0) = { 0.2551f, 0.2702f, 0.2877f, 0.3055f };
f32 D_80807260_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x7D0) = { 0.375f, 0.3806f, 0.4063f };
f32 D_8080726C_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x7DC) = { 0.2145f, 0.2459f };
f32 D_80807274_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x7E4) = { 0.3536f, 0.373f, 0.393f };
f32 D_80807280_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x7F0) = { 0.2f, 0.24f, 0.26f };
f32 D_8080728C_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x7FC) = { 0.22f, 0.25f, 0.27f };
f32 D_80807298_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x808) = { 0.3f, 0.33f, 0.35f };
f32 D_808072A4_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0x814) = { 0.31f, 0.34f, 0.36f };
u8 D_808072B0_inantab[40] BT_DATA(4, overlays_in_antab, 0x820) = { 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x54, 0x7A, 0xE1, 0x3F, 0x59, 0x99, 0x9A, 0x3F, 0x4F, 0x5C, 0x29, 0x3F, 0x57, 0x0A, 0x3D, 0x3F, 0x5C, 0x28, 0xF6, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x6E, 0x14, 0x7B, 0x3F, 0x68, 0xF5, 0xC3, 0x3F, 0x6E, 0x14, 0x7B };
f32 D_808072D8_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0x848) = { 0.265f, 0.865f };
f32 D_808072E0_inantab [ 11 ] BT_DATA(4, overlays_in_antab, 0x850) = { 0.01f, 0.01f, 0.03f, 0.05f, 0.07f, 0.09f, 0.11f, 0.13f, 0.15f, 0.17f, 0.19f };
f32 D_8080730C_inantab [ 18 ] BT_DATA(4, overlays_in_antab, 0x87C) = { 0.01f, 0.19f, 0.21f, 0.23f, 0.25f, 0.27f, 0.29f, 0.31f, 0.33f, 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f };
f32 D_80807354_inantab [ 21 ] BT_DATA(4, overlays_in_antab, 0x8C4) = { 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f, 0.53f, 0.55f, 0.57f, 0.59f, 0.61f, 0.63f, 0.65f, 0.67f, 0.69f, 0.71f, 0.73f, 0.75f };
f32 D_808073A8_inantab [ 44 ] BT_DATA(4, overlays_in_antab, 0x918) = { 0.01f, 0.01f, 0.03f, 0.05f, 0.07f, 0.09f, 0.11f, 0.13f, 0.15f, 0.17f, 0.19f, 0.21f, 0.23f, 0.25f, 0.27f, 0.29f, 0.31f, 0.33f, 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f, 0.53f, 0.55f, 0.57f, 0.59f, 0.61f, 0.63f, 0.65f, 0.67f, 0.69f, 0.71f, 0.73f, 0.75f, 0.77f, 0.79f, 0.81f, 0.83f, 0.85f };
f32 D_80807458_inantab [ 21 ] BT_DATA(4, overlays_in_antab, 0x9C8) = { 0.35f, 0.37f, 0.39f, 0.41f, 0.43f, 0.45f, 0.47f, 0.49f, 0.51f, 0.53f, 0.55f, 0.57f, 0.59f, 0.61f, 0.63f, 0.65f, 0.67f, 0.69f, 0.71f, 0.73f, 0.75f };
f32 D_808074AC_inantab [ 12 ] BT_DATA(4, overlays_in_antab, 0xA1C) = { 0.77f, 0.79f, 0.81f, 0.83f, 0.85f, 0.87f, 0.89f, 0.91f, 0.93f, 0.95f, 0.97f, 0.99f };
f32 D_808074DC_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0xA4C) = { 0.3f, 0.6f, 0.9f };
f32 D_808074E8_inantab [ 19 ] BT_DATA(4, overlays_in_antab, 0xA58) = { 0.05f, 0.1f, 0.15f, 0.2f, 0.25f, 0.3f, 0.35f, 0.4f, 0.45f, 0.5f, 0.55f, 0.6f, 0.65f, 0.7f, 0.75f, 0.8f, 0.85f, 0.9f, 0.95f };
f32 D_80807534_inantab [ 10 ] BT_DATA(4, overlays_in_antab, 0xAA4) = { 0.3f, 0.35f, 0.4f, 0.45f, 0.5f, 0.55f, 0.6f, 0.65f, 0.7f, 0.75f };
f32 D_8080755C_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0xACC) = { 0.8f };
f32 D_80807560_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0xAD0) = { 0.2f, 0.24f, 0.26f };
f32 D_8080756C_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0xADC) = { 0.22f, 0.25f, 0.27f };
f32 D_80807578_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0xAE8) = { 0.3f, 0.33f, 0.35f };
f32 D_80807584_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0xAF4) = { 0.31f, 0.34f, 0.36f };
u8 D_80807590_inantab[40] BT_DATA(4, overlays_in_antab, 0xB00) = { 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x54, 0x7A, 0xE1, 0x3F, 0x59, 0x99, 0x9A, 0x3F, 0x4F, 0x5C, 0x29, 0x3F, 0x57, 0x0A, 0x3D, 0x3F, 0x5C, 0x28, 0xF6, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x6E, 0x14, 0x7B, 0x3F, 0x68, 0xF5, 0xC3, 0x3F, 0x6E, 0x14, 0x7B };
f32 D_808075B8_inantab [ 2 ] BT_DATA(4, overlays_in_antab, 0xB28) = { 0.265f, 0.865f };
f32 D_808075C0_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0xB30) = { 0.3f, 0.6f, 0.9f };
f32 D_808075CC_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0xB3C) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_808075F0_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0xB60) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807614_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0xB84) = { 0.01f };
f32 D_80807618_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0xB88) = { 0.01f };
f32 D_8080761C_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0xB8C) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807640_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0xBB0) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807664_inantab [ 8 ] BT_DATA(4, overlays_in_antab, 0xBD4) = { 0.68f, 0.69f, 0.7f, 0.71f, 0.72f, 0.73f, 0.74f, 0.75f };
f32 D_80807684_inantab [ 21 ] BT_DATA(4, overlays_in_antab, 0xBF4) = { 0.24f, 0.26f, 0.28f, 0.3f, 0.32f, 0.34f, 0.36f, 0.38f, 0.4f, 0.42f, 0.44f, 0.46f, 0.48f, 0.5f, 0.52f, 0.54f, 0.56f, 0.58f, 0.6f, 0.62f, 0.64f };
f32 D_808076D8_inantab [ 17 ] BT_DATA(4, overlays_in_antab, 0xC48) = { 0.66f, 0.68f, 0.7f, 0.72f, 0.74f, 0.76f, 0.78f, 0.8f, 0.82f, 0.84f, 0.86f, 0.88f, 0.9f, 0.92f, 0.94f, 0.96f, 0.98f };
f32 D_8080771C_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0xC8C) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807740_inantab [ 9 ] BT_DATA(4, overlays_in_antab, 0xCB0) = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f };
f32 D_80807764_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0xCD4) = { 0.1f };
f32 D_80807768_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0xCD8) = { 0.1f };
f32 D_8080776C_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0xCDC) = { 0.15f };
f32 D_80807770_inantab [ 3 ] BT_DATA(4, overlays_in_antab, 0xCE0) = { 0.7f, 0.7025f, 0.705f };
f32 D_8080777C_inantab [ 1 ] BT_DATA(4, overlays_in_antab, 0xCEC) = { 0.1f };
