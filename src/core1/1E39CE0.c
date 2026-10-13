#include "common.h"

typedef struct {
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 attackVolume;
    u8 decayVolume;
    u8 padE[2];
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
    ALWaveTable wavetable;
} MusicSound;

typedef struct MusicVoiceState {
    struct MusicVoiceState *next;
    ALVoice voice;
    MusicSound *sound;
    s16 unk24;
    s16 unk26;
    s32 envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;
    void *tremOscState;
    void *vibOscState;
} MusicVoiceState;

typedef struct {
    s16 bendRange;
    u8 unk2;
    u8 pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 fxBus;
    u8 sustain;
    u8 fadeVolume;
    u8 fadeTarget;
    u8 fadeRate;
    f32 fadeStep;
    u8 notifyFlags;
    u8 filterType;
    u8 filterPitch;
    u8 filterResonance;
    f32 pitchBend;
    s32 attackTime;
    s32 decayTime;
    s32 releaseTime;
    u8 customEnvelope;
    u8 attackVolume;
    u8 decayVolume;
    s8 detune;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    u8 unk30;
    u8 oscParam;
    u8 bank;
    u8 instrument;
    u8 unk34;
    u8 pad35[3];
} MusicChannel;

typedef struct {
    s32 ticks;
    u8 status;
    u8 channel;
    u8 byte1;
    u8 byte2;
    u32 duration;
} MusicMIDIEvent;

typedef struct {
    s16 type;
    union {
        MusicMIDIEvent midi;
        ALVolumeEvent vol;
        struct {
            MusicVoiceState *vs;
            void *oscState;
            u8 chan;
        } osc;
    } msg;
} MusicEvent;

typedef struct {
    ALPlayer node;
    void *drvr;
    ALCSeq *target;
    s32 curTime;
    void *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u32 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    MusicEvent nextEvent;
    ALEventQueue evtq;
    s32 frameTime;
    MusicChannel *chanState;
    MusicVoiceState *vAllocHead;
    MusicVoiceState *vAllocTail;
    MusicVoiceState *vFreeList;
    s32 (*initOsc)(void **, f32 *, u8, u8, u8, u8, u8);
    ALOscUpdate updateOsc;
    ALOscStop stopOsc;
    u8 pad7C[8];
    OSMesgQueue *msgQueue;
} MusicPlayer;

void func_80022E20(MusicPlayer *, u8);
void func_80022ECC(MusicPlayer *, u8);
void func_80024D90(MusicPlayer *, f32);
void func_80026500(ALEventQueue *, MusicEvent *, s32, s32);
void func_800268D0(ALVoice *, ALVoiceConfig *);
void func_80026BE0(ALVoice *, s16, s32);
void func_80026CB0(ALVoice *, ALWaveTable *, f32, s16, u8, u8, u8, f32, u8, s32);
void func_80026DE0(ALVoice *, u8);
void func_80026E90(ALVoice *, f32);
void func_80026F40(ALVoice *, u8);
f32 func_80027170(s16);
f32 func_80028B74(s32);
void func_8002976C(MusicPlayer *, ALVoice *, s32);
MusicVoiceState *func_80029A04(MusicPlayer *, u8, u8, u8, MusicSound *);
MusicVoiceState *func_80029B18(MusicPlayer *, u8, u8);
MusicSound *func_80029BA0(MusicPlayer *, u8, u8, u8);
s16 func_80029D54(MusicVoiceState *, MusicPlayer *);
u8 func_80029E64(MusicVoiceState *, MusicPlayer *);
s32 func_80029F5C(MusicVoiceState *, s32);
u8 func_80029FA0(MusicVoiceState *, MusicPlayer *);
void func_8002A318(MusicPlayer *, s32, u8);
void func_8002A7E0(ALVoice *, f32);
void func_8002AB30(ALVoice *, u8);
s32 func_800E9048(void);
ALInstrument *func_800E93AC(u8);
extern struct {
    u8 pad0[0x3C];
    s32 numFxBusses;
} *D_800411F4;
extern s32 D_8007EA50[];


#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_800221B0.s")

s32 func_8002241C(MusicPlayer *arg0) {
    s32 func_80022D1C(MusicPlayer *);
    void func_80023008(MusicPlayer *, MusicEvent *);
    s32 func_80024A5C(MusicPlayer *, MusicEvent *);
    s32 func_80024DD8(MusicPlayer *);
    s32 func_8002645C(ALEventQueue *, MusicEvent *);
    s32 func_800266B0(ALEventQueue *, s32);
    s32 func_80026FF0(ALVoice *);
    s32 func_80027090(ALVoice *);
    s32 func_80029670(MusicPlayer *, ALVoice *);
    s32 func_800298E4(MusicPlayer *, ALVoice *, s32);
    s32 func_8002A024(MusicPlayer *, u8 *);
    s32 func_8002A6A4(MusicPlayer *, MusicVoiceState *);
    s32 func_8002A940(u8);
    s32 func_8002A9B8(u8);
    s32 func_8002AA30(s32, s32, u8 *);
    s32 func_8002AA74(s32, u8, u8 *);
    MusicPlayer *p;
    MusicEvent event;
    ALVoice *voice;
    s32 delta;
    MusicVoiceState *vs;
    void *osc;
    f32 value;
    u8 chan;
    s32 param1;
    s32 param2;

    p = arg0;
    do {
        switch (*(u16 *)&p->nextEvent.type) {
        case 0:
            func_80022D1C(p);
            break;
        case 9:
            event.type = 9;
            func_80026500(&p->evtq, &event, p->frameTime, 1);
            break;
        case 5:
            voice = p->nextEvent.msg.vol.voice;
            func_80026FF0(voice);
            func_80027090(voice);
            vs = voice->clientPrivate;
            if (vs->flags != 0) {
                func_8002A6A4(p, vs);
            }
            func_80029670(p, voice);
            break;
        case 6:
            voice = p->nextEvent.msg.vol.voice;
            vs = voice->clientPrivate;
            if (vs->envPhase == 0) {
                vs->envPhase = 1;
            }
            delta = p->nextEvent.msg.vol.delta;
            vs->envEndTime = p->curTime + delta;
            vs->envGain = p->nextEvent.msg.vol.vol;
            func_80026BE0(voice, func_80029D54(vs, p), delta);
            break;
        case 22:
            vs = p->nextEvent.msg.osc.vs;
            osc = p->nextEvent.msg.osc.oscState;
            delta = p->updateOsc(osc, &value);
            vs->tremelo = (u32)value;
            func_80026BE0(&vs->voice, func_80029D54(vs, p), func_80029F5C(vs, p->curTime));
            event.type = 22;
            event.msg.osc.vs = vs;
            event.msg.osc.oscState = osc;
            func_80026500(&p->evtq, &event, delta, 0);
            break;
        case 23:
            vs = p->nextEvent.msg.osc.vs;
            osc = p->nextEvent.msg.osc.oscState;
            chan = p->nextEvent.msg.osc.chan;
            delta = p->updateOsc(osc, &value);
            vs->vibrato = value;
            func_80026E90(&vs->voice, p->chanState[chan].pitchBend * (vs->pitch * vs->vibrato));
            if (p->chanState[chan].filterType != 0) {
                func_8002A7E0(&vs->voice, (440.0f * func_80028B74(p->chanState[chan].filterPitch + (vs->key - vs->sound->keyBase) - 64)) * p->chanState[chan].pitchBend * vs->vibrato);
            }
            event.type = 23;
            event.msg.osc.vs = vs;
            event.msg.osc.oscState = osc;
            event.msg.osc.chan = chan;
            func_80026500(&p->evtq, &event, delta, 0);
            break;
        case 2:
        case 21:
            func_80023008(p, &p->nextEvent);
            break;
        case 7:
            func_80024A5C(p, &p->nextEvent);
            break;
        case 10:
            p->vol = *(s16 *)&p->nextEvent.msg;
            if ((vs = p->vAllocHead) != NULL) {
                do {
                    func_80026BE0(&vs->voice, func_80029D54(vs, p), func_80029F5C(vs, p->curTime));
                } while ((vs = vs->next) != NULL);
            }
            break;
        case 24:
            *(f32 *)&p->pad7C[0] = *(f32 *)&p->nextEvent.msg;
            *(f32 *)&p->pad7C[4] = *(f32 *)&p->nextEvent.msg.vol.delta;
            if ((vs = p->vAllocHead) != NULL) {
                do {
                    if (vs->envPhase != 3) {
                        func_80026F40(&vs->voice, func_80029E64(vs, p));
                    }
                    vs = vs->next;
                } while (vs != NULL);
            }
            break;
        case 25:
            if (((u8 *)&p->nextEvent.msg)[1] < 8) {
                param1 = func_8002A940(((u8 *)&p->nextEvent.msg)[0]);
                if (param1 != 0) {
                    func_8002AA30(param1, (((u8 *)&p->nextEvent.msg)[1] & 7) | (((u8 *)&p->nextEvent.msg)[2] << 3), &p->nextEvent.msg.midi.status);
                }
            } else {
                param2 = func_8002A9B8(((u8 *)&p->nextEvent.msg)[0]);
                if (param2 != 0) {
                    func_8002AA74(param2, ((u8 *)&p->nextEvent.msg)[1], &p->nextEvent.msg.midi.status);
                }
            }
            break;
        case 15:
            if (p->state != 1) {
                p->state = 1;
                func_80024DD8(p);
            }
            break;
        case 16:
            if (p->state == 2) {
                if ((vs = p->vAllocHead) != NULL) {
                    do {
                        func_80026FF0(&vs->voice);
                        func_80027090(&vs->voice);
                        if (vs->flags != 0) {
                            func_8002A6A4(p, vs);
                        }
                        func_80029670(p, &vs->voice);
                    } while ((vs = p->vAllocHead) != NULL);
                }
                p->state = 0;
            }
            break;
        case 17:
            if (p->state == 1) {
                func_800266B0(&p->evtq, 0);
                func_800266B0(&p->evtq, 21);
                func_800266B0(&p->evtq, 2);
                if ((vs = p->vAllocHead) != NULL) {
                    do {
                        if (func_800298E4(p, &vs->voice, 50000)) {
                            func_8002976C(p, &vs->voice, 50000);
                        }
                    } while ((vs = vs->next) != NULL);
                }
                chan = 0;
                do {
                    p->chanState[chan].fadeVolume = p->chanState[chan].fadeTarget;
                    if (p->chanState[chan].fadeVolume == 0) {
                        p->chanMask &= (1 << chan) ^ -1;
                    } else {
                        p->chanMask |= 1 << chan;
                    }
                } while (++chan < 32);
                p->state = 2;
                event.type = 16;
                func_80026500(&p->evtq, &event, 0x7FFFFFFF, 0);
            }
            break;
        case 12:
            chan = ((u8 *)&p->nextEvent.msg)[0];
            p->chanState[chan].priority = ((u8 *)&p->nextEvent.msg)[1];
            break;
        case 13:
            p->target = (ALCSeq *)p->nextEvent.msg.midi.ticks;
            p->chanMask = -1;
            func_8002A024(p, p->bank);
            break;
        case 14:
            break;
        case 1:
        case 3:
        case 4:
            break;
        }
        p->nextDelta = func_8002645C(&p->evtq, &p->nextEvent);
    } while (p->nextDelta == 0);
    p->curTime += p->nextDelta;
    return p->nextDelta;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_80022D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_80022E20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_80022ECC.s")

void func_80023008(MusicPlayer *seqp, MusicEvent *event) {
    ALVoice *voice;
    MusicVoiceState *vs;
    s32 status;
    u8 chan;
    u8 key;
    u8 vel;
    u8 byte1;
    u8 byte2;
    MusicMIDIEvent *midi = &event->msg.midi;
    s16 vol;
    MusicEvent evt;
    s32 deltaTime;
    MusicVoiceState *vstate;
    u8 pan;
    MusicChannel *cstate;
    s32 instParam;

    status = midi->status & 0xF0;
    chan = midi->channel;
    byte1 = key = midi->byte1;
    byte2 = vel = midi->byte2;

    switch (status) {
    case 0x90:
        if (vel != 0) {
            ALVoiceConfig config;
            MusicSound *sound;
            s16 cents;
            f32 pitch, oscValue;
            u8 fxmix;
            u8 filterType;
            f32 filterFreq;
            void *oscState = NULL;
            ALInstrument *inst;

            if (seqp->state != 1 || !(seqp->chanMask & (1 << chan))) {
                if (midi->duration) {
                    evt.type = 0x15;
                    evt.msg.midi.status = 0x80;
                    evt.msg.midi.channel = chan;
                    evt.msg.midi.byte1 = key;
                    evt.msg.midi.byte2 = 0;
                    deltaTime = seqp->uspt * midi->duration;
                    D_8007EA50[chan] = deltaTime;
                    func_80026500(&seqp->evtq, &evt, deltaTime, 0);
                }
                break;
            }
            cstate = &seqp->chanState[chan];
            sound = func_80029BA0(seqp, key, vel, chan);
            if (!sound) {
                return;
            }
            config.priority = cstate->priority;
            config.fxBus = cstate->fxBus;
            config.unityPitch = 0;
            vstate = func_80029A04(seqp, key, vel, chan, sound);
            if (!vstate) {
                return;
            }
            voice = &vstate->voice;
            func_800268D0(voice, &config);
            vstate->unk26 = seqp->chanState[chan].instrument;
            vstate->unk24 = seqp->chanState[chan].unk34;
            vstate->sound = sound;
            vstate->envPhase = 0;
            if (cstate->sustain >= 0x40) {
                vstate->phase = 2;
            } else {
                vstate->phase = 0;
            }
            cents = (key - sound->keyBase) * 100 + sound->detune;
            if (cstate->customEnvelope) {
                cents += cstate->detune;
            }
            vstate->pitch = func_80027170(cents);
            if (cstate->customEnvelope) {
                vstate->envGain = cstate->attackVolume;
                vstate->envEndTime = seqp->curTime + cstate->attackTime;
            } else {
                vstate->envGain = sound->attackVolume;
                vstate->envEndTime = seqp->curTime + sound->attackTime;
            }
            vstate->flags = 0;
            if (cstate->customEnvelope) {
                instParam = cstate->tremType;
            } else {
                inst = func_800E93AC(seqp->chanState[chan].instrument);
                instParam = inst->tremType;
            }
            oscValue = 127.0f;
            if (instParam && seqp->initOsc) {
                if (cstate->customEnvelope) {
                    deltaTime = seqp->initOsc(&oscState, &oscValue, cstate->tremType, cstate->tremRate,
                                              cstate->tremDepth, cstate->tremDelay, cstate->oscParam);
                } else {
                    deltaTime = seqp->initOsc(&oscState, &oscValue, inst->tremType, inst->tremRate,
                                              inst->tremDepth, inst->tremDelay, cstate->oscParam);
                }
                if (deltaTime) {
                    evt.type = 0x16;
                    evt.msg.osc.vs = vstate;
                    evt.msg.osc.oscState = oscState;
                    func_80026500(&seqp->evtq, &evt, deltaTime, 0);
                    vstate->flags |= 1;
                    vstate->tremOscState = oscState;
                }
            }
            vstate->tremelo = (u8) oscValue;
            oscValue = 1.0f;
            if (cstate->customEnvelope) {
                instParam = cstate->vibType;
            } else {
                instParam = inst->vibType;
            }
            if (instParam && seqp->initOsc) {
                if (cstate->customEnvelope) {
                    deltaTime = seqp->initOsc(&oscState, &oscValue, cstate->vibType, cstate->vibRate,
                                              cstate->vibDepth, cstate->vibDelay, cstate->oscParam);
                } else {
                    deltaTime = seqp->initOsc(&oscState, &oscValue, inst->vibType, inst->vibRate,
                                              inst->vibDepth, inst->vibDelay, cstate->oscParam);
                }
                if (deltaTime) {
                    evt.type = 0x17;
                    evt.msg.osc.vs = vstate;
                    evt.msg.osc.oscState = oscState;
                    evt.msg.osc.chan = chan;
                    func_80026500(&seqp->evtq, &evt, deltaTime, 0);
                    vstate->flags |= 2;
                    vstate->vibOscState = oscState;
                }
            }
            vstate->vibrato = oscValue;
            pitch = vstate->pitch * cstate->pitchBend * vstate->vibrato;
            fxmix = func_80029E64(vstate, seqp);
            filterType = cstate->filterType;
            if (filterType) {
                filterFreq = func_80028B74(cents / 100 + cstate->filterPitch - 0x40)
                    * 440.0f * cstate->pitchBend;
            } else {
                filterFreq = 127.0f;
            }
            pan = func_80029FA0(vstate, seqp);
            vol = func_80029D54(vstate, seqp);
            if (cstate->customEnvelope) {
                deltaTime = cstate->attackTime;
            } else {
                deltaTime = sound->attackTime;
            }
            func_80026CB0(voice, &sound->wavetable, pitch, vol, pan, fxmix,
                          filterType, filterFreq, cstate->filterResonance, deltaTime);
            evt.type = 6;
            evt.msg.vol.voice = voice;
            if (cstate->customEnvelope) {
                evt.msg.vol.vol = cstate->decayVolume;
                evt.msg.vol.delta = cstate->decayTime;
            } else {
                evt.msg.vol.vol = sound->decayVolume;
                evt.msg.vol.delta = sound->decayTime;
            }
            func_80026500(&seqp->evtq, &evt, deltaTime, 0);
            if (midi->duration) {
                evt.type = 0x15;
                evt.msg.midi.status = 0x80;
                evt.msg.midi.channel = chan;
                evt.msg.midi.byte1 = key;
                evt.msg.midi.byte2 = 0;
                deltaTime = seqp->uspt * midi->duration;
                D_8007EA50[chan] = deltaTime;
                func_80026500(&seqp->evtq, &evt, deltaTime, 0);
            }
            if ((cstate->notifyFlags & 1) && seqp->msgQueue) {
                osSendMesg(seqp->msgQueue, (OSMesg)((D_8007EA50[chan] & ~0xFF) |
                           (cstate->notifyFlags >> 2)), OS_MESG_NOBLOCK);
            }
            break;
        }
        /* A note-on with zero velocity is a note-off. */
    case 0x80:
        vstate = func_80029B18(seqp, key, chan);
        if (!vstate) {
            return;
        }
        cstate = &seqp->chanState[chan];
        if (vstate->phase == 2) {
            vstate->phase = 4;
        } else {
            vstate->phase = 3;
            if (cstate->customEnvelope) {
                func_8002976C(seqp, &vstate->voice, cstate->releaseTime);
            } else {
                func_8002976C(seqp, &vstate->voice, vstate->sound->releaseTime);
            }
        }
        if ((cstate->notifyFlags & 2) && seqp->msgQueue) {
            osSendMesg(seqp->msgQueue, (OSMesg)((key << 16) | 8 |
                       (cstate->notifyFlags >> 2)), OS_MESG_NOBLOCK);
        }
        break;
    case 0xA0:
        vstate = func_80029B18(seqp, key, chan);
        if (!vstate) {
            return;
        }
        vstate->velocity = byte2;
        func_80026BE0(&vstate->voice,
                      func_80029D54(vstate, seqp),
                      func_80029F5C(vstate, seqp->curTime));
        break;
    case 0xD0:
        for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
            if (vs->channel == chan) {
                vs->velocity = byte1;
                func_80026BE0(&vs->voice,
                              func_80029D54(vs, seqp),
                              func_80029F5C(vs, seqp->curTime));
            }
        }
        break;
    case 0xB0:
        switch (byte1) {
        case 0x0A:
            seqp->chanState[chan].pan = byte2;
            for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
                if (vs->channel == chan) {
                    pan = func_80029FA0(vs, seqp);
                    func_80026DE0(&vs->voice, pan);
                }
            }
            break;
        case 0xFD:
            seqp->chanState[chan].fadeRate = byte2;
            break;
        case 0xFF: {
            f32 distance;
            f32 step;

            if (seqp->chanState[chan].fadeRate == 0) {
                seqp->chanState[chan].fadeRate = 0x88;
            }
            if (seqp->chanState[chan].fadeTarget != byte2) {
                distance = byte2 - seqp->chanState[chan].fadeVolume;
                step = distance / (seqp->chanState[chan].fadeRate & 0x7F);
                if (step < 0.0f) {
                    step = -step;
                }
                seqp->chanState[chan].fadeStep = step;
                if (seqp->chanState[chan].fadeTarget == seqp->chanState[chan].fadeVolume) {
                    seqp->chanState[chan].fadeTarget = byte2;
                } else {
                    seqp->chanState[chan].fadeTarget = byte2;
                    break;
                }
            } else {
                break;
            }
            midi->byte1 = 0xFE;
        }
        /* Fall through to the first fade step. */
        case 0xFE: {
            u8 current;
            u8 target;
            s32 difference;
            s32 increment;
            f32 step;
            f32 delay;

            current = seqp->chanState[chan].fadeVolume;
            target = seqp->chanState[chan].fadeTarget;
            step = seqp->chanState[chan].fadeStep;
            vel = seqp->chanState[chan].fadeRate;
            difference = target - current;
            if (difference > 0) {
                if (seqp->chanState[chan].fadeRate & 0x80) {
                    step *= 2.0f;
                }
                increment = step;
                if (increment == 0) {
                    increment = 1;
                    delay = 1.0f / step;
                } else {
                    delay = increment / step;
                }
                if (difference > increment) {
                    difference = increment;
                }
            } else {
                increment = step;
                if (increment == 0) {
                    increment = 1;
                    delay = step;
                } else {
                    delay = increment / step;
                }
                increment = -increment;
                if (difference < increment) {
                    difference = increment;
                }
            }
            current += difference;
            seqp->chanState[chan].fadeVolume = current;
            if (current != target) {
                func_80026500(&seqp->evtq, event, seqp->uspt * 100 * delay, 0);
            }
            if (current) {
                seqp->chanMask |= 1 << chan;
            } else {
                seqp->chanMask &= ~(1 << chan);
            }
            func_80022E20(seqp, chan);
            break;
        }
        case 0xFC:
            seqp->chanState[chan].fadeVolume = byte2;
            seqp->chanState[chan].fadeTarget = byte2;
            if (byte2 == 0) {
                seqp->chanMask &= (1 << chan) ^ -1;
            } else {
                seqp->chanMask |= 1 << chan;
            }
            func_80022E20(seqp, chan);
            break;
        case 0x21:
            seqp->chanState[chan].filterType = byte2;
            func_80022ECC(seqp, chan);
            break;
        case 0x22:
            seqp->chanState[chan].filterPitch = byte2;
            func_80022ECC(seqp, chan);
            break;
        case 0x23:
            seqp->chanState[chan].filterResonance = byte2;
            for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
                if (vs->channel == chan) {
                    func_8002AB30(&vs->voice, byte2);
                }
            }
            break;
        case 0x1E:
            if (seqp->msgQueue) {
                osSendMesg(seqp->msgQueue, (OSMesg)((byte2 & 7) | 0x10 |
                           ((seqp->node.samplesLeft << 5) & ~0xFF)), OS_MESG_NOBLOCK);
            }
            break;
        case 7:
            seqp->chanState[chan].vol = byte2;
            for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
                if (vs->channel == chan && vs->envPhase != 3) {
                    vol = func_80029D54(vs, seqp);
                    func_80026BE0(&vs->voice, vol, func_80029F5C(vs, seqp->curTime));
                }
            }
            break;
        case 0x10:
            seqp->chanState[chan].priority = byte2;
            break;
        case 0x40:
            seqp->chanState[chan].sustain = byte2;
            for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
                if (vs->channel == chan && vs->phase != 3) {
                    if (byte2 >= 0x40) {
                        if (vs->phase == 0) {
                            vs->phase = 2;
                        }
                    } else {
                        if (vs->phase == 2) {
                            vs->phase = 0;
                        } else if (vs->phase == 4) {
                            vs->phase = 3;
                            if (cstate->customEnvelope) {
                                func_8002976C(seqp, &vs->voice,
                                    seqp->chanState[chan].releaseTime < 16000 ? 16000 : seqp->chanState[chan].releaseTime);
                            } else {
                                func_8002976C(seqp, &vs->voice,
                                    vstate->sound->releaseTime < 16000 ? 16000 : vstate->sound->releaseTime);
                            }
                        }
                    }
                }
            }
            break;
        case 0x5B:
            seqp->chanState[chan].fxmix = (seqp->chanState[chan].fxmix & 0x80) | byte2;
            byte2 = seqp->chanState[chan].fxmix >> 7;
            /* Fall through to update active voices. */
        case 0x41:
            seqp->chanState[chan].fxmix = (seqp->chanState[chan].fxmix & 0x7F) | (byte2 << 7);
            for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
                if (vs->channel == chan && vs->envPhase != 3) {
                    func_80026F40(&vs->voice, seqp->chanState[chan].fxmix);
                }
            }
            break;
        case 0x5C:
            if (byte2 < D_800411F4->numFxBusses) {
                seqp->chanState[chan].fxBus = byte2;
            }
            break;
        case 0x1A:
            break;
        case 0x20:
            seqp->chanState[chan].bank = byte2;
            break;
        case 0x29: {
            s32 tempo;

            tempo = seqp->uspt / seqp->target->qnpt;
            tempo = 60000000 / tempo;
            tempo += byte2 - 0x40;
            func_80024D90(seqp, 60000000 / tempo);
            break;
        }
        default:
            break;
        }
        break;
    case 0xC0:
        instParam = (seqp->chanState[chan].bank << 7) + key;
        if (instParam < func_800E9048()) {
            func_8002A318(seqp, instParam, chan);
        } else {
        }
        break;
    case 0xE0: {
        s32 bendVal;
        f32 bendRatio;
        s32 cents;

        bendVal = (byte2 << 7) + byte1 - 8192;
        cents = (seqp->chanState[chan].bendRange * bendVal) / 8192;
        bendRatio = func_80027170(cents);
        seqp->chanState[chan].pitchBend = bendRatio;
        for (vs = seqp->vAllocHead; vs != NULL; vs = vs->next) {
            if (vs->channel == chan) {
                func_80026E90(&vs->voice, vs->pitch * bendRatio * vs->vibrato);
                if (seqp->chanState[chan].filterType) {
                    func_8002A7E0(&vs->voice,
                        func_80028B74(seqp->chanState[chan].filterPitch + (vs->key - vs->sound->keyBase) - 0x40)
                        * 440.0f * bendRatio * vs->vibrato);
                }
            }
        }
        break;
    }
    default:
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_80024A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_80024C9C.s")

void func_80024D90(MusicPlayer *arg0, f32 arg1) {
    if (arg0->target != NULL) {
        arg0->uspt = (s32) ((arg1 = arg1) * arg0->target->qnpt);
    } else {
        arg0->uspt = 0x1E8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_80024DD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E39CE0/func_80024E70.s")
