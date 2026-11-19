#ifndef __CORE2_1ED68A0_H__
#define __CORE2_1ED68A0_H__

#include "common.h"
#include "core2/1EB3750.h"

typedef struct {
    f32 volume;
    f32 tempoScale;
    s16 track;
    s16 trackVolume;
    s16 flags;
    u8 mode, retry;
    u8 lastMode, area, unk12, audible, volumeChanged, mixChanged;
    u8 active, frozen, changed;
    u8 pad19[3];
    s32 unk1C;
    s16 areaEnabled, settingsIndex, appliedVolume;
    u8 pad26[2];
    s32 region;
    union { f32 value; s32 bits; } distance;
    f32 volumeScale;
    u8 instrumentHandles[2];
    s16 instrumentPresets[2];
    u8 pad3A[2];
    f32 timer;
    u8 overrideMode, locked;
} MusicRegionState;

u32 func_800FDC28(u32);
s32 func_800FE4E4(void);
void func_800FE734(u32);
void func_800FE844(u32);
void func_800FEC60(u32);
void func_800FECB8(u32);
void func_800FF01C(f32);
#endif // __CORE2_1ED68A0_H__
