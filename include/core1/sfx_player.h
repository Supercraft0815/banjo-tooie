#ifndef CORE1_SFX_PLAYER_H
#define CORE1_SFX_PLAYER_H
#include "types.h"
typedef struct { s16 active, reserved[7]; } SfxVoiceCount;
extern SfxVoiceCount sfx_voice_count;
typedef struct {
    ALPlayer player;
    ALEventQueue queue;
    u8 pad28[0x1C];
    s32 maxVoices;
    s32 frameTime;
    s32 pad4C;
    s32 currentTime;
    u8 pad54[0x10];
} SfxPlayer;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
typedef char SfxPlayer_n64_size_must_be_0x64[(sizeof(SfxPlayer) == 0x64) ? 1 : -1];
#endif
#endif
