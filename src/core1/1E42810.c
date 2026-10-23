#include "common.h"

/* extern */

void func_8002ACE0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    void func_80026500(void *, void *, s32, s32);
    struct { s16 type; s32 value; u8 b0; u8 b1; u8 b2; u8 b3; s32 tail; } event;
    s32 delay;
    event.type = 2;
    event.value = 0;
    event.b0 = arg2;
    event.b1 = arg3;
    event.b2 = arg4;
    event.b3 = arg5;
    event.tail = 0;
    delay = arg1;
    func_80026500((void *)(arg0 + 0x48), (void *)&event, delay, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002AD60.s")

s32 func_8002B684(void *arg0, s32 arg1, void *arg2) {
    void func_8002D328(void *, s32, void *);
    void *sp24;

    sp24 = arg0;
    switch (arg1) {
        case 3:
            if (*(void **)((s8 *)sp24 + 0x80) != NULL) {
                **(void ***)((s8 *)sp24 + 0x80) = arg2;
            } else {
                *(void **)((s8 *)sp24 + 0x7C) = arg2;
            }
            *(void **)((s8 *)sp24 + 0x80) = arg2;
            break;
        case 4:
            *(s32 *)((s8 *)sp24 + 0x78) = 1;
            *(s32 *)((s8 *)sp24 + 0x84) = 0;
            *(s16 *)((s8 *)sp24 + 0x5A) = 1;
            *(s32 *)((s8 *)sp24 + 0x74) = 0;
            *(f32 *)((s8 *)sp24 + 0x4C) = 0.0f;
            *(s32 *)((s8 *)sp24 + 0x50) = 1;
            *(s32 *)((s8 *)sp24 + 0x48) = 0;
            func_8002D328(sp24, 4, arg2);
            break;
        case 9:
            *(s32 *)((s8 *)sp24 + 0x84) = 1;
            break;
        default:
            func_8002D328(sp24, arg1, arg2);
            break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002B7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002BAAC.s")

s16 func_8002BCBC(s16 arg0, s32 arg1, s16 arg2, u16 arg3) {
    s32 delta;

    arg1 >>= 3;
    if (arg1 == 0) {
        return arg0;
    }
    delta = arg3 * arg1;
    delta >>= 16;
    delta += arg2 * arg1;
    arg0 += delta;
    return arg0;
}

s32 *func_8002BD40(s32 arg0, s32 *arg1, s32 arg2, s32 *arg3) {
    typedef struct {
        s32 words[2];
    } Command;
    typedef struct {
        u8 pad[0x8C];
        u8 value;
    } Filter;
    typedef struct {
        u8 pad[8];
        Filter *filter;
        u8 padC[0xC];
        s16 bus;
    } Voice;
    typedef struct {
        u8 pad[8];
        Voice *voice;
    } Source;
    typedef struct {
        u8 pad[0x14];
        u32 count;
        u32 unk18;
        Source **sources;
        u8 pad20[0x28];
    } Bus;
    extern struct {
        u8 pad[0x34];
        Bus *buses;
    } *D_800411F4;

    Command *func_8002AD60(Source *, s32, Command *);
    Command *cmd;
    Bus *bus;
    Source **sources;
    u32 i;
    s32 count;
    u32 maximum;
    u32 scale;
    Command *packet1;
    Command *packet2;
    Command *packet3;
    Command *old;

    cmd = (Command *) arg1;
    bus = &D_800411F4->buses[arg2];
    sources = bus->sources;
    count = 0;
    maximum = 1;
    packet1 = cmd++;
    packet1->words[0] = 0x020007C0;
    packet1->words[1] = 0x2E0;
    *arg3 = 0;
    for (i = 0; i < bus->count; i++) {
        if (sources[i]->voice != NULL && sources[i]->voice->bus == arg2 &&
            sources[i]->voice->filter != NULL && sources[i]->voice->filter->value >= 0x40) {
            cmd = func_8002AD60(sources[i], arg0, cmd);
            *arg3 += 1;
            count += 1;
            if (sources[i]->voice->filter->value > maximum) {
                maximum = sources[i]->voice->filter->value;
            }
        }
    }
    if (count != 0) {
        maximum -= 0x3E;
        if (maximum >= 7U) {
            scale = (u32) (26755.0f / sqrtf((f32) maximum));
        } else {
            scale = (u32) (65536.0f / (f32) maximum);
        }
        packet2 = cmd++;
        packet2->words[0] = 0x4E0;
        packet2->words[1] = ((scale & 0xFFFF) << 16) | (maximum & 0xFFFF);
        packet3 = cmd++;
        packet3->words[0] = 0x650;
        packet3->words[1] = ((scale & 0xFFFF) << 16) | (maximum & 0xFFFF);
    }
    for (i = 0; i < bus->count; i++) {
        if ((sources[i]->voice != NULL && sources[i]->voice->bus == arg2 &&
             (sources[i]->voice->filter == NULL || sources[i]->voice->filter->value < 0x40)) ||
            (sources[i]->voice == NULL && arg2 == 0)) {
            old = cmd;
            cmd = func_8002AD60(sources[i], arg0, cmd);
            if (cmd != old) {
                *arg3 += 1;
            }
        }
    }
    return (s32 *) cmd;
}
