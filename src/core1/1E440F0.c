#include "common.h"

s32 func_8002C5C0(s32 *arg0) {
    if (arg0[1] == arg0[0]) {
        return 0;
    } else {
        return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E440F0/func_8002C5F8.s")

s32 func_8002CC9C(s32 arg0, s32 arg1, s32 arg2) {
    typedef struct {
        s32 start;
        s32 length;
        s32 loop[3];
        s32 state[8];
        s32 count;
        s32 pad[32];
        s32 size;
    } Sample;
    typedef struct {
        s32 pad[4];
        void *state;
        s32 loopStart;
        s32 loopEnd;
        s32 loopCount;
        Sample *sample;
        s32 size;
        s32 pad28[2];
        s32 offset;
        s32 field34;
        s32 field38;
        s32 start;
    } State;
    State *sp24;

    sp24 = (State *)arg0;
    switch (arg1) {
    case 5:
        sp24->sample = (Sample *)arg2;
        sp24->start = sp24->sample->start;
        sp24->offset = 0;
        sp24->sample->length = (sp24->sample->length / 9) * 9;
        sp24->size = sp24->sample->count * 2 * sp24->sample->size * 8;
        if (func_8002C5C0(sp24->sample->loop)) {
            sp24->loopStart = sp24->sample->loop[0];
            sp24->loopEnd = sp24->sample->loop[1];
            sp24->loopCount = sp24->sample->loop[2];
            bcopy(sp24->sample->state, sp24->state, 0x20);
        } else {
            sp24->loopStart = sp24->loopEnd = sp24->loopCount = 0;
        }
        break;
    case 4:
        sp24->field34 = 0;
        sp24->field38 = 1;
        sp24->offset = 0;
        if (sp24->sample != NULL) {
            sp24->start = sp24->sample->start;
            if (func_8002C5C0(sp24->sample->loop)) {
                sp24->loopCount = sp24->sample->loop[2];
            }
        }
        break;
    default:
        break;
    }
    return 0;
}

Acmd *func_8002CE70(Acmd *arg0, void *arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    s32 sp2C;
    s32 sp28;

    if (arg3 > 0) {
        sp28 = (*(s32 (**)(s32, s32, s32))((s8 *)(arg1) + (0x28)))((*(s32 *)((s8 *)(arg1) + (0x3C))), arg3, (*(s32 *)((s8 *)(arg1) + (0x2C))));
        sp2C = sp28 & 7;
        arg3 += sp2C;
        {
        Acmd *sp24 = arg0++;
        (*(s32 *)((s8 *)(sp24) + (0))) = ((((arg3 - (arg3 & 7)) + 8) & 0xFFF) << 0xC) | 0x04000000 | (arg5 & 0xFFF);
        (*(s32 *)((s8 *)(sp24) + (4))) = (s32) (sp28 - sp2C);
        }
    } else {
        sp2C = 0;
    }
    if (arg6 & 2) {
        Acmd *sp20 = arg0++;
        (*(s32 *)((s8 *)(sp20) + (0))) = 0x0F000000;
        (*(s32 *)((s8 *)(sp20) + (4))) = (s32) ((*(s32 *)((s8 *)(arg1) + (0x10))) & 0x1FFFFFFF);
    }
    {
    Acmd *sp1C = arg0++;
    *(s32 *)sp1C = ((*(s32 *)((s8 *)(arg1) + (0xC))) & 0x1FFFFFFF & 0xFFFFFF) | 0x01000000;
    (*(s32 *)((s8 *)(sp1C) + (4))) = (s32) (((arg6 & 0xF) << 0x1C) | (((arg2 * 2) & 0xFFF) << 0x10) | ((sp2C & 0xF) << 0xC) | (arg4 & 0xFFF));
    }
    (*(s32 *)((s8 *)(arg1) + (0x38))) = 0;
    return arg0;
}
