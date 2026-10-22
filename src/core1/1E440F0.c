#include "common.h"

s32 func_8002C5C0(s32 *arg0) {
    if (arg0[1] == arg0[0]) {
        return 0;
    } else {
        return 1;
    }
}

void *func_8002C5F8(void *arg0, s16 *arg1, s32 arg2, void *arg3) {
    typedef struct {
        u32 address;
        u32 length;
    } Sample;
    typedef struct {
        u32 pad0[5];
        u32 loopStart;
        u32 loopEnd;
        s32 loopCount;
        Sample *sample;
        u32 bookSize;
        u32 pad28[2];
        u32 position;
        u32 offset;
        s32 flags;
        u32 address;
    } State;
    typedef struct {
        u32 w0;
        u32 w1;
    } Command;
    Acmd *func_8002CE70(Acmd *arg0, void *arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6);
    Command *sp7C;
    s16 sp7A;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    State *sp44;

    sp7C = arg3;
    sp4C = 0;
    sp48 = 0;
    sp44 = arg0;
    if (arg2 == 0) {
        return sp7C;
    }
    sp7A = 0;
    {
        Command *sp40 = sp7C++;
        sp40->w0 = (sp44->bookSize & 0xFFFFFF) | 0x0B000000;
        sp40->w1 = ((u32)sp44->sample + 0x38) & 0x1FFFFFFF;
    }
    sp48 = (sp44->position + arg2 > sp44->loopEnd) && sp44->loopCount;
    if (sp48) {
        sp5C = sp44->loopEnd - sp44->position;
    } else {
        sp5C = arg2;
    }
    if (sp44->offset) {
        sp54 = 0x10 - sp44->offset;
    } else {
        sp54 = 0;
    }
    sp74 = sp5C - sp54;
    if (sp74 < 0) {
        sp74 = 0;
    }
    sp70 = (sp74 + 0xF) >> 4;
    sp6C = sp70 * 9;
    if (sp48) {
        sp7C = func_8002CE70(sp7C, sp44, sp74, sp6C, *arg1, sp7A, sp44->flags);
        if (sp44->offset) {
            *arg1 += sp44->offset * 2;
        } else {
            *arg1 += 0x20;
        }
        sp44->offset = sp44->loopStart & 0xF;
        sp44->address = sp44->sample->address + (sp44->loopStart >> 4) * 9 + 9;
        sp44->position = sp44->loopStart;
        sp50 = *arg1;
        while (arg2 > sp5C) {
            arg2 -= sp5C;
            sp58 = (((sp70 + 1) << 5) + sp50 + 0x10) & ~0x1F;
            sp50 += sp5C * 2;
            if (sp44->loopCount != -1 && sp44->loopCount != 0) {
                sp44->loopCount--;
            }
            sp5C = arg2 < sp44->loopEnd - sp44->loopStart ? arg2 : sp44->loopEnd - sp44->loopStart;
            sp74 = sp5C + sp44->offset - 0x10;
            if (sp74 < 0) {
                sp74 = 0;
            }
            sp70 = (sp74 + 0xF) >> 4;
            sp6C = sp70 * 9;
            sp7C = func_8002CE70(sp7C, sp44, sp74, sp6C, sp58, sp7A, sp44->flags | 2);
            {
                Command *sp3C = sp7C++;
                sp3C->w0 = ((sp44->offset * 2 + sp58) & 0xFFFFFF) | 0x0A000000;
                sp3C->w1 = ((sp50 & 0xFFFF) << 16) | ((sp5C * 2) & 0xFFFF);
            }
        }
        sp44->offset = (sp44->offset + arg2) & 0xF;
        sp44->position += arg2;
        sp44->address += sp70 * 9;
        return sp7C;
    }
    {
        sp5C = sp70 * 0x10;
        sp68 = sp44->address + sp6C - (sp44->sample->address + sp44->sample->length);
        if (sp68 < 0) {
            sp68 = 0;
        }
        sp60 = (sp68 / 9) * 0x10;
        if (sp60 > sp5C + sp54) {
            sp60 = sp5C + sp54;
        }
        sp6C -= sp68;
        if (sp60 - (sp60 & 0xF) < arg2) {
            sp4C = 1;
            sp7C = func_8002CE70(sp7C, sp44, sp5C - sp60, sp6C, *arg1, sp7A, sp44->flags);
            if (sp44->offset) {
                *arg1 += sp44->offset * 2;
            } else {
                *arg1 += 0x20;
            }
            sp44->offset = (sp44->offset + arg2) & 0xF;
            sp44->position += arg2;
            sp44->address += sp70 * 9;
        } else {
            sp44->offset = 0;
            sp44->address += sp70 * 9;
        }
        if (sp60) {
            sp44->offset = 0;
            if (sp4C) {
                sp64 = (sp54 + sp5C - sp60) * 2;
            } else {
                sp64 = 0;
            }
            {
                Command *sp38 = sp7C++;
                sp38->w0 = ((*arg1 + sp64) & 0xFFFFFF) | 0x02000000;
                sp38->w1 = sp60 * 2;
            }
        }
        return sp7C;
    }
}

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
