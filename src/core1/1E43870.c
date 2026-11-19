#include "common.h"
s32 *func_8002BD40(s32 arg0, s32 *arg1, s32 arg2, s32 *arg3) {
    void *func_8002AD60(void *, s32, void *);
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
