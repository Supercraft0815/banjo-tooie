#include "common.h"

/* extern */

void func_8002ACE0(BtIntPtr arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
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

void *func_8002AD60(void *arg0, s32 arg1, void *arg2) {
    typedef struct Event Event;
    typedef struct Voice Voice;
    struct Event {
        Event *next;
        s32 time;
        s16 type;
        s16 unity;
        union {
            s32 integer;
            f32 pitch;
            Voice *voice;
            struct { s16 hi, lo; } halves;
        } value;
        union {
            s32 duration;
            struct { s16 volume; u8 pan, mix; } start;
        } settings;
        u8 priority;
        u8 mode;
        s16 pad16;
        f32 rate;
        s32 duration;
        void *sound;
    };
    struct Voice {
        u8 pad0[0x44];
        f32 pitch;
        s32 unity;
        u8 pad4C[0xC];
        s16 pan, volume, left, right;
        s16 mixLeft, mixRight;
        u16 leftRate;
        s16 leftFraction, leftTarget;
        u16 rightRate;
        s16 rightFraction, rightTarget;
        s32 elapsed, duration, dirty;
        Event *head, *tail;
        s32 active, allocated;
        u8 priority;
        u8 pad8D[3];
        s16 rate, mode;
        u8 pad94[0x24];
        s32 changed;
    };
    extern s16 D_80041290[], D_8004138E[];
    extern u8 D_8007EA30, D_8007EA31, D_8007EA32;
    extern s32 func_8002CC9C(BtIntPtr arg0, s32 arg1, BtIntPtr arg2);
    extern void *func_8002B7C8(void *, s16 *, s16 *, s32, void *);
    extern s16 func_8002BCBC(s16, s32, s16, u16);
    extern s32 func_8002B684(void *, s32, void *);
    extern void func_80021884(void *);
    extern void func_800217F4(void *);
    void *output;
    Voice *voice;
    s16 flags;
    s32 previousTime;
    s32 time;
    s32 count;
    s16 offset;
    s32 volume;
    Event *event;
    s32 remaining;

    output = arg2;
    voice = arg0;
    time = arg1;
    offset = 0;
    remaining = 184;
    flags = 0;
    while (voice->head) {
        previousTime = time;
        time = voice->head->time;
        count = ((time - previousTime + 183) / 184) * 184;
        if (count == 0) {
            time = previousTime;
        }
        if (count > remaining) {
            break;
        }
        switch (voice->head->type) {
            case 13: {
                Event *start;
                s32 startVolume;
                start = voice->head;
                if (start->unity) {
                    voice->unity = 1;
                }
                func_8002CC9C(voice, 5, start->sound);
                voice->active = 1;
                voice->dirty = 1;
                voice->elapsed = 0;
                voice->duration = ((start->duration + 183) / 184) * 184;
                startVolume = (start->settings.start.volume + start->settings.start.volume) / 2;
                voice->volume = startVolume;
                voice->pan = start->settings.start.pan;
                voice->mixLeft = (D_80041290[start->settings.start.mix & 0x7F] & 0xFFFE) | (start->settings.start.mix >> 7);
                if (!D_8007EA30) {
                    voice->mixLeft &= 0xFFFE;
                }
                voice->mixRight = D_8004138E[-(start->settings.start.mix & 0x7F)] & 0xFFFE;
                if (D_8007EA32) {
                    voice->pan = (voice->pan >> 1) + 32;
                } else if (D_8007EA31) {
                    voice->pan = 64;
                }
                if (start->duration) {
                    voice->left = 1;
                    voice->right = 1;
                } else {
                    voice->left = (D_80041290[voice->pan] * voice->volume) >> 15;
                    voice->right = (D_8004138E[-voice->pan] * voice->volume) >> 15;
                }
                voice->pitch = start->value.pitch;
                voice->mode = start->mode;
                voice->rate = start->rate;
                voice->changed = 1;
                voice->priority = start->priority;
                break;
            }
            case 11:
            case 12:
            case 16:
                output = func_8002B7C8(voice, &flags, &offset, count, output);
                if (voice->elapsed >= voice->duration) {
                    voice->leftTarget = (D_80041290[voice->pan] * voice->volume) >> 15;
                    voice->rightTarget = (D_8004138E[-voice->pan] * voice->volume) >> 15;
                    voice->elapsed = voice->duration;
                    voice->left = voice->leftTarget;
                    voice->right = voice->rightTarget;
                } else {
                    voice->left = func_8002BCBC(voice->left, voice->elapsed, voice->leftFraction, voice->leftRate);
                    voice->right = func_8002BCBC(voice->right, voice->elapsed, voice->rightFraction, voice->rightRate);
                }
                if (voice->left == 0) {
                    voice->left = 1;
                }
                if (voice->right == 0) {
                    voice->right = 1;
                }
                if (voice->head->type == 12) {
                    if (D_8007EA32) {
                        voice->pan = (voice->head->value.halves.lo >> 1) + 32;
                    } else if (D_8007EA31) {
                        voice->pan = 64;
                    } else {
                        voice->pan = voice->head->value.integer;
                    }
                }
                if (voice->head->type == 11) {
                    voice->elapsed = 0;
                    volume = voice->head->value.integer;
                    volume = (volume + volume) / 2;
                    voice->volume = volume;
                    voice->duration = ((voice->head->settings.duration + 183) / 184) * 184;
                }
                if (voice->head->type == 16) {
                    if ((((voice->mixLeft ^ voice->mixRight) & 1) ^ ((voice->head->value.integer + 1) >> 7)) && D_8007EA30) {
                        if (voice->pan > 64) {
                            voice->mixLeft ^= 1;
                        } else {
                            voice->mixRight ^= 1;
                        }
                    }
                    voice->mixLeft = (D_80041290[voice->head->value.integer & 0x7F] & 0xFFFE) | (voice->mixLeft & 1);
                    voice->mixRight = (D_8004138E[-(voice->head->value.integer & 0x7F)] & 0xFFFE) | (voice->mixRight & 1);
                }
                voice->dirty = 1;
                break;
            case 14: {
                Event *start;
                start = voice->head;
                if (start->unity) {
                    voice->unity = 1;
                }
                func_8002CC9C(voice, 5, (void *) start->value.integer);
                voice->active = 1;
                break;
            }
            case 15:
                output = func_8002B7C8(voice, &flags, &offset, count, output);
                func_8002B684(voice, 4, 0);
                break;
            case 0: {
                Event *freeEvent;
                freeEvent = voice->head;
                freeEvent->value.voice->allocated = 0;
                func_80021884(freeEvent->value.voice);
                break;
            }
            case 7:
                output = func_8002B7C8(voice, &flags, &offset, count, output);
                voice->pitch = voice->head->value.pitch;
                break;
            case 8:
                output = func_8002B7C8(voice, &flags, &offset, count, output);
                voice->unity = 1;
                break;
            case 5:
                output = func_8002B7C8(voice, &flags, &offset, count, output);
                func_8002CC9C(voice, 5, (void *) voice->head->value.integer);
                break;
            default:
                output = func_8002B7C8(voice, &flags, &offset, count, output);
                func_8002B684(voice, voice->head->type, (void *) voice->head->value.integer);
                break;
        }
        offset += count * 2;
        remaining -= count;
        event = voice->head;
        voice->head = voice->head->next;
        if (!voice->head) {
            voice->tail = NULL;
        }
        func_800217F4(event);
    }
    output = func_8002B7C8(voice, &flags, &offset, remaining, output);
    if (voice->elapsed > voice->duration) {
        voice->elapsed = voice->duration;
    }
    return output;
}    typedef struct { u8 pad0[0x48]; s32 unk48; f32 unk4C; s32 unk50; u8 pad54[0x6]; s16 unk5A; u8 pad5C[0x18]; s32 unk74; s32 unk78; void * unk7C; void * unk80; s32 unk84; } Obj1E42810_func_8002B684_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

s32 func_8002B684(void *arg0, s32 arg1, void *arg2) {
    s32 func_8002D328(u8 *arg0, s32 arg1, BtIntPtr arg2);
    void *sp24;

    sp24 = arg0;
    switch (arg1) {
        case 3:
            if (((Obj1E42810_func_8002B684_sp24 *)sp24)->unk80 != NULL) {
                **(void ***)((s8 *)sp24 + 0x80) = arg2;
            } else {
                ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk7C = arg2;
            }
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk80 = arg2;
            break;
        case 4:
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk78 = 1;
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk84 = 0;
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk5A = 1;
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk74 = 0;
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk4C = 0.0f;
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk50 = 1;
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk48 = 0;
            func_8002D328(sp24, 4, arg2);
            break;
        case 9:
            ((Obj1E42810_func_8002B684_sp24 *)sp24)->unk84 = 1;
            break;
        default:
            func_8002D328(sp24, arg1, arg2);
            break;
    }
    return 0;
}

void *func_8002B7C8(void *arg0, s16 *arg1, s16 *arg2, s32 arg3, void *arg4) {
    s16 func_8002BAAC(f32, f32, s32, u16 *);
    Acmd *func_8002D030(u8 *, s16 *, s32, Acmd *);
    extern s16 D_80041290[], D_8004138E[];
    Acmd *sp34;
    u8 *sp30;
    Acmd *sp2C;
    Acmd *sp28;
    Acmd *sp24;

    sp34 = arg4;
    sp30 = arg0;
    if (*(s32 *)(sp30 + 0x84) != 1 || arg3 == 0) {
        return sp34;
    }
    sp34 = func_8002D030(sp30, arg1, arg3, arg4);
    if (*(s32 *)(sp30 + 0x78) != 0) {
        *(s32 *)(sp30 + 0x78) = 0;
        *(s16 *)(sp30 + 0x68) = (s16)((s32)(*(s16 *)(sp30 + 0x5A) * D_80041290[*(s16 *)(sp30 + 0x58)]) >> 15);
        *(s16 *)(sp30 + 0x66) = func_8002BAAC((f32)*(s16 *)(sp30 + 0x5C), (f32)*(s16 *)(sp30 + 0x68), *(s32 *)(sp30 + 0x74), (u16 *)(sp30 + 0x64));
        *(s16 *)(sp30 + 0x6E) = (s16)((s32)(*(s16 *)(sp30 + 0x5A) * D_8004138E[-*(s16 *)(sp30 + 0x58)]) >> 15);
        *(s16 *)(sp30 + 0x6C) = func_8002BAAC((f32)*(s16 *)(sp30 + 0x5E), (f32)*(s16 *)(sp30 + 0x6E), *(s32 *)(sp30 + 0x74), (u16 *)(sp30 + 0x6A));
        sp2C = sp34++;
        sp2C->words.w0 = (*(s16 *)(sp30 + 0x5C) & 0xFFFF) | 0x09060000;
        sp2C->words.w1 = (*(s16 *)(sp30 + 0x62) & 0xFFFF) | ((*(s16 *)(sp30 + 0x60) & 0xFFFF) << 16);
        sp28 = sp34++;
        sp28->words.w0 = (*(s16 *)(sp30 + 0x6E) & 0xFFFF) | 0x09040000;
        sp28->words.w1 = (*(u16 *)(sp30 + 0x6A) & 0xFFFF) | ((*(s16 *)(sp30 + 0x6C) & 0xFFFF) << 16);
        sp24 = sp34++;
        sp24->words.w0 = (*(s16 *)(sp30 + 0x68) & 0xFFFF) | 0x09000000;
        sp24->words.w1 = (*(u16 *)(sp30 + 0x64) & 0xFFFF) | ((*(s16 *)(sp30 + 0x66) & 0xFFFF) << 16);
        {
            Acmd *sp20;
            sp20 = sp34++;
            sp20->words.w0 = (*(s16 *)(sp30 + 0x5E) & 0xFFFF) | 0x03010000;
            sp20->words.w1 = osVirtualToPhysical(*(void **)(sp30 + 0x54));
        }
    } else {
        Acmd *sp1C;
        sp1C = sp34++;
        sp1C->words.w0 = 0x03000000;
        sp1C->words.w1 = osVirtualToPhysical(*(void **)(sp30 + 0x54));
    }
    *arg1 += 0x170;
    *(s32 *)(sp30 + 0x70) += 0xB8;
    return sp34;
}

s16 func_8002BAAC(f32 arg0, f32 arg1, s32 arg2, u16 *arg3) {
    s16 spE;
    s16 spC;
    f32 sp8;
    f32 sp4;
    f32 sp0;
    if (arg2 == 0) {
        if (arg0 <= arg1) {
            *arg3 = 0xFFFF;
            return 0x7FFF;
        } else {
            *arg3 = 0;
            return -0x8000;
        }
    }
    sp8 = 1.0f / (f32) arg2;
    if (arg1 < 1.0f) {
        arg1 = 1.0f;
    }
    if (arg0 <= 0.0f) {
        arg0 = 1.0f;
    }
    sp4 = (arg1 - arg0) * sp8 * 8.0f;
    spE = (s16) (s32) sp4;
    sp0 = sp4 - (f32) spE;
    spE -= 1;
    sp0 += 1.0f;
    spC = (s16) (s32) sp0;
    spE += spC;
    sp0 -= (f32) spC;
    *arg3 = (u32) (65535.0f * sp0);
    return spE;
}

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
    extern const f32 D_80041D90;
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
            scale = (u32) (D_80041D90 / sqrtf((f32) maximum));
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
