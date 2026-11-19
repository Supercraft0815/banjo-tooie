#ifndef BT_GL_INTROSYNC_STATE_H
#define BT_GL_INTROSYNC_STATE_H
#include "common.h"
#ifdef BT_NATIVE
typedef struct {
    u32 count;
    s32 index;
    f32 time, rate;
    u8 active;
    u8 padding[7];
} IntroSyncState;
extern IntroSyncState D_801275D0;
_Static_assert(sizeof(IntroSyncState) == 0x18, "intro clock layout");
#endif
#endif
