#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E36640/func_8001EB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E36640/func_8001ED68.s")

typedef struct {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
} SfxKeyMap;
typedef struct {
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 attackVolume;
    u8 decayVolume;
    u8 padE[2];
    SfxKeyMap key;
    u8 pad16[0xBE];
    u8 pan;
    u8 volume;
} SfxSound;
typedef struct SfxState {
    struct SfxState *next;
    struct SfxState *prev;
    SfxSound *sound;
    ALVoice voice;
    f32 pitch;
    f32 pitchRatio;
    s32 handle;
    s32 retries;
    s16 volume;
    s16 envelopeVolume;
    s32 endTime;
    u8 priority;
    u8 pan;
    u8 fxMix;
    u8 fxBus;
    u8 flags;
    u8 phase;
    u8 pad46[2];
} SfxState;
typedef struct {
    u16 type;
    SfxState *state;
    union { s32 data; f32 pitch; } value;
    s32 padC;
} SfxEvent;
typedef struct {
    u8 pad0[0x14];
    ALEventQueue queue;
    u8 pad28[0x1C];
    s32 maxVoices;
    s32 frameTime;
    s32 pad4C;
    s32 currentTime;
} SfxPlayer;
extern SfxState *D_800411D4;
extern SfxPlayer *D_800411DC;
extern s16 D_800411E0;
extern struct {u8 pad0[0x3C];s32 numFxBusses;} *D_800411F4;
extern s16 *D_8007EA24;
void func_8001EE34(SfxEvent *);
void func_800200B8(SfxState *);
void func_80020128(SfxState *);
void func_800201A4(ALEventQueue *, SfxState *, s32);
s32 func_80020298(u16 *, u16 *);
SfxState *func_80020790(s16, s16, u8, f32, u8, u8, s32);
void func_80026500(ALEventQueue *, SfxEvent *, s32, s32);
s32 func_800268D0(ALVoice *, ALVoiceConfig *);
void func_80026BE0(ALVoice *, s16, s32);
void func_80026CB0(ALVoice *, ALWaveTable *, f32, s16, u8, u8, u8, f32, u8, s32);
void func_80026DE0(ALVoice *, u8);
void func_80026E90(ALVoice *, f32);
void func_80026F40(ALVoice *, u8);

void func_8001EE34(SfxEvent *arg0) {
    ALVoiceConfig config;
    SfxSound *sound;
    SfxKeyMap *key;
    u8 pan;
    SfxEvent event;
    SfxEvent chainEvent;
    s32 time;
    s32 fxMix;
    s32 volume;
    s32 panValue;
    s32 atLimit;
    s32 mask;
    s32 first;
    s32 allocated;
    SfxState *state;
    SfxState *next;
    u16 free;
    u16 used;
    SfxState *stealState;
    SfxEvent stealEvent;

    first = 1;
    allocated = 0;
    state = NULL;
    next = NULL;
    do {
    if (next != NULL) {
        chainEvent.state = state;
        chainEvent.type = arg0->type;
        chainEvent.value.data = arg0->value.data;
        arg0 = &chainEvent;
    }
    state = arg0->state;
    sound = state->sound;
    if (sound == NULL) {
        func_80020298(&free, &used);
        return;
    }
    key = &sound->key;
    next = state->next;
    switch (arg0->type) {
    case 0x1:
        if ((state->phase != 5) && (state->phase != 4)) {
            return;
        }
        config.fxBus = (s16) state->fxBus;
        config.priority = (s16) state->priority;
        config.unityPitch = 0;
        atLimit = D_800411E0 >= D_800411DC->maxVoices;
        if ((atLimit == 0) || (state->flags & 0x10)) {
            allocated = func_800268D0(&state->voice, &config);
        }
        if (allocated == 0) {
            if ((state->flags & 0x12) || (state->retries > 0)) {
                state->phase = 4;
                state->retries -= 1;
                func_80026500(&D_800411DC->queue, arg0, 0x8235, 0);
            } else if (atLimit != 0) {
                stealState = D_800411D4;
                do {
                if (!(stealState->flags & 0x12) && (stealState->flags & 4) && (stealState->phase != 3)) {
                    atLimit = 0;
                    stealEvent.type = 0x80;
                    stealEvent.state = stealState;
                    stealState->phase = 3;
                    func_80026500(&D_800411DC->queue, &stealEvent, 0x3E8, 0);
                    func_80026BE0(&stealState->voice, 0, 0x3E8);
                }
                stealState = stealState->prev;
                } while ((atLimit != 0) && (stealState != NULL));
                if (atLimit == 0) {
                    state->retries = 2;
                    func_80026500(&D_800411DC->queue, arg0, 0x3E9, 0);
                } else {
                    func_800200B8(state);
                }
            } else {
                func_800200B8(state);
            }
            return;
        }
        state->flags |= 4;
        state->envelopeVolume = (s16) sound->attackVolume;
        state->fxBus = (u8) config.fxBus;
        time = (s32) (((f32) sound->attackTime / state->pitchRatio) / state->pitch);
        state->endTime = D_800411DC->currentTime + time;
        if (((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) <= 0) {
            volume = 0;
        } else {
            volume = ((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) - 1;
        }
        panValue = (state->pan + sound->pan) - 0x40;
        pan = (panValue > 0 ? panValue : 0) < 127 ? (panValue > 0 ? panValue : 0) : 127;
        fxMix = (state->fxMix & 0x7F) + ((key->keyMax & 0xF) * 8);
        fxMix = (fxMix < 0 ? 0 : fxMix) >= 128 ? 127 : (fxMix < 0 ? 0 : fxMix);
        fxMix |= state->fxMix & 0x80;
        func_80026CB0(&state->voice, (ALWaveTable *) &sound->pad16[2], state->pitchRatio * state->pitch, (s16) volume, (u8) (s32) pan, (u8) fxMix, 0U, 0.0f, 0U, time);
        state->phase = 1;
        D_800411E0 += 1;
        if (!(state->flags & 2)) {
            if (time == 0) {
                state->envelopeVolume = (s16) sound->decayVolume;
                if (((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) <= 0) {
                    volume = 0;
                } else {
                    volume = ((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) - 1;
                }
                time = (s32) (((f32) sound->decayTime / state->pitch) / state->pitchRatio);
                state->endTime = D_800411DC->currentTime + time;
                func_80026BE0(&state->voice, (s16) volume, time);
                event.type = 2;
                event.state = state;
                func_80026500(&D_800411DC->queue, (SfxEvent *) &event, time, 0);
                if (state->flags & 0x20) {
                    func_80020128(state);
                }
            } else {
                event.type = 0x40;
                event.state = state;
                time = (s32) (((f32) sound->attackTime / state->pitchRatio) / state->pitch);
                func_80026500(&D_800411DC->queue, (SfxEvent *) &event, time, 0);
            }
        }
        break;
    case 0x2:
    case 0x400:
    case 0x1000:
        if ((arg0->type != 0x1000) || (state->flags & 2)) {
            switch (state->phase) {
            case 1:
                func_800201A4(&D_800411DC->queue, state, 0x40);
                time = (s32) (((f32) sound->releaseTime / state->pitch) / state->pitchRatio);
                func_80026BE0(&state->voice, 0, time);
                if (time != 0) {
                    event.type = 0x80;
                    event.state = state;
                    func_80026500(&D_800411DC->queue, (SfxEvent *) &event, time, 0);
                    state->phase = 2;
                } else {
                    func_800200B8(state);
                }
                break;
            case 4:
            case 5:
                func_800200B8(state);
                break;
            default:
                break;
            }
            if (arg0->type == 2) {
                arg0->type = 0x1000;
            }
        }
        break;
    case 0x4:
        state->pan = (u8) arg0->value.data;
        if (state->phase == 1) {
            panValue = (state->pan + sound->pan) - 0x40;
            pan = (panValue > 0 ? panValue : 0) < 127 ? (panValue > 0 ? panValue : 0) : 127;
            func_80026DE0(&state->voice, pan);
        }
        break;
    case 0x10:
        state->pitchRatio = arg0->value.pitch;
        if (state->phase == 1) {
            func_80026E90(&state->voice, state->pitchRatio * state->pitch);
            if (state->flags & 0x20) {
                func_80020128(state);
            }
        }
        break;
    case 0x100:
        state->fxMix = (u8) arg0->value.data;
        if (state->phase == 1) {
            fxMix = (state->fxMix & 0x7F) + ((key->keyMax & 0xF) * 8);
            fxMix = (fxMix < 0 ? 0 : fxMix) >= 128 ? 127 : (fxMix < 0 ? 0 : fxMix);
            fxMix |= state->fxMix & 0x80;
            func_80026F40(&state->voice, (u8) fxMix);
        }
        break;
    case 0x2000:
        state->fxBus = (u8) arg0->value.data;
        if ((s32) state->fxBus >= D_800411F4->numFxBusses) {
            state->fxBus = 0;
        }
        if (state->phase == 1) {
            state->voice.fxBus = (s16) state->fxBus;
        }
        break;
    case 0x8:
        state->volume = (s16) arg0->value.data;
        if (state->phase == 1) {
            if (((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) <= 0) {
                volume = 0;
            } else {
                volume = ((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) - 1;
            }
            func_80026BE0(&state->voice, volume, (state->endTime - D_800411DC->currentTime) < 1000 ? 1000 : (state->endTime - D_800411DC->currentTime));
        }
        break;
    case 0x800:
        if (state->phase == 1) {
            time = (s32) (((f32) sound->releaseTime / state->pitch) / state->pitchRatio);
            if (((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) <= 0) {
                volume = 0;
            } else {
                volume = ((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) - 1;
            }
            func_80026BE0(&state->voice, (s16) volume, time);
        }
        break;
    case 0x40:
        if (!(state->flags & 2)) {
            state->envelopeVolume = (s16) sound->decayVolume;
            if (((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) <= 0) {
                volume = 0;
            } else {
                volume = ((s32) (D_8007EA24[key->keyMin & 0x1F] * ((s32) (state->envelopeVolume * state->volume * sound->volume) / 16129)) / 32767) - 1;
            }
            time = (s32) (((f32) sound->decayTime / state->pitch) / state->pitchRatio);
            state->endTime = D_800411DC->currentTime + time;
            func_80026BE0(&state->voice, (s16) volume, time);
            event.type = 2;
            event.state = state;
            func_80026500(&D_800411DC->queue, &event, time, 0);
            if (state->flags & 0x20) {
                func_80020128(state);
            }
        }
        break;
    case 0x80:
        func_800200B8(state);
        break;
    case 0x200:
        if (state->flags & 0x10) {
            func_80020790((s16) arg0->value.data, state->volume, state->pan, state->pitchRatio, (u8) (s32) state->fxMix, (u8) (s32) state->fxBus, state->handle);
        }
        break;
    default:
        break;
    }
        mask = arg0->type & 0x2D1;
        if (((state = next) != NULL) && (mask == 0)) {
            first = state->flags & 1;
        }
    } while ((first == 0) && (state != NULL) && (mask == 0));
}


/* extern */

void func_800200B8(SfxState *arg0) {
    s32 func_800205D0(SfxState *);
    s32 func_80026FF0(ALVoice *);
    s32 func_80027090(ALVoice *);
    if (arg0->flags & 4) {
        func_80026FF0(&arg0->voice);
        func_80027090(&arg0->voice);
    }
    func_800205D0(arg0);
    func_800201A4(&D_800411DC->queue, arg0, 0xFFFF);
}

/* extern */

void func_80020128(SfxState *arg0) {
    f32 func_80027170(s32);
    SfxEvent event;
    f32 sp1C;

    sp1C = func_80027170(arg0->sound->key.detune) * arg0->pitchRatio;
    event.type = 0x10;
    event.state = arg0;
    event.value.data = *(s32 *)&sp1C;
    func_80026500(&D_800411DC->queue, &event, 0x8235, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E36640/func_800201A4.s")

s32 func_80020298(u16 *arg0, u16 *arg1) {
    extern SfxState *D_800411D0;
    extern SfxState *D_800411D8;
    u32 sp2C;
    u16 sp2A;
    u16 sp28;
    u16 sp26;
    SfxState *sp20;
    SfxState *sp1C;
    SfxState *sp18;

    sp2C = osSetIntMask(1U);
    sp20 = D_800411D0;
    sp1C = D_800411D8;
    sp18 = D_800411D4;
    for (sp2A = 0; sp20 != NULL; sp2A++, sp20 = sp20->next) {}
    for (sp28 = 0; sp1C != NULL; sp28++, sp1C = sp1C->next) {}
    for (sp26 = 0; sp18 != NULL; sp26++, sp18 = sp18->prev) {}
    *arg0 = sp28;
    *arg1 = sp2A;
    osSetIntMask(sp2C);
    return (s32) sp26;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E36640/func_8002039C.s")
