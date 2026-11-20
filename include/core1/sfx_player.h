#ifndef CORE1_SFX_PLAYER_H
#define CORE1_SFX_PLAYER_H
#include "types.h"
typedef struct {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
} SfxKeyMap;
typedef struct SfxSound {
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
    struct SfxState **handle;
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
/* The shared audio queue copies sixteen bytes on both word sizes. */
typedef struct {
    u16 type;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    union { s32 data; f32 pitch; } value;
    SfxState *state;
#else
    SfxState *state;
    union { s32 data; f32 pitch; } value;
    s32 padC;
#endif
} SfxEvent;

typedef struct { s16 active, reserved[7]; } SfxVoiceCount;
extern SfxVoiceCount sfx_voice_count;
typedef struct {
    ALPlayer player;
    ALEventQueue queue;
    SfxEvent nextEvent;
    s32 reserved38;
    SfxState *lastStarted;
    SfxState *states;
    s32 maxVoices;
    s32 frameTime;
    s32 nextDelta;
    s32 currentTime;
    u8 pad54[0x10];
} SfxPlayer;
typedef struct {
    s32 stateCount;
    s32 eventCount;
    s32 maxVoices;
    void *heap;
    u16 channelCount;
} SfxConfig;

#ifdef BT_NATIVE
typedef SfxState *SfxVoiceRef;
#else
typedef s32 SfxVoiceRef;
#endif
#ifdef BT_NATIVE
_Static_assert(sizeof(SfxEvent) == 0x10, "sound queue payload");
#endif
#if defined(BT_NATIVE) && defined(BT_ILP32)
_Static_assert(sizeof(SfxState) == 0x48, "O32 sound voice");
_Static_assert(__builtin_offsetof(SfxState, handle) == 0x30, "O32 voice owner");
_Static_assert(__builtin_offsetof(SfxPlayer, states) == 0x40, "O32 voice pool");
_Static_assert(__builtin_offsetof(SfxConfig, channelCount) == 0x10, "O32 sound channels");
#endif
#if !defined(BT_NATIVE) || defined(BT_ILP32)
typedef char SfxPlayer_n64_size_must_be_0x64[(sizeof(SfxPlayer) == 0x64) ? 1 : -1];
#endif
#endif
