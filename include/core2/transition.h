#ifndef BT_CORE2_TRANSITION_H
#define BT_CORE2_TRANSITION_H

#include "types.h"

typedef struct {
    u8 kind;
    u8 start_state;
    u8 next_state;
    u8 pad;
    f32 duration;
    s32 asset;
    s32 animation;
    f32 scale;
} TransitionData;

typedef struct {
    s32 id;
    s32 draw_count;
    TransitionData data;
    u8 state;
    u8 intro_sync;
    u8 pad1E[2];
    s32 asset;
    f32 rotation;
    f32 timer;
    struct anctrl_s *control;
    s32 update_count;
} Transition;

#if !defined(BT_NATIVE) || defined(BT_ILP32)
typedef char bt_assert_transition_size[(sizeof(Transition) == 0x34) ? 1 : -1];
#endif

#endif
