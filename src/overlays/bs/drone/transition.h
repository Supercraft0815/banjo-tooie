#ifndef BS_DRONE_TRANSITION_H
#define BS_DRONE_TRANSITION_H
#include "overlays/ba/playerstate.h"

typedef struct {
    PlayerState player;
    s32 unused18C;
    s32 step;
    s32 finish_handled;
    s32 saved_collision;
} PlayerDroneTransition;
#ifdef BT_ILP32
_Static_assert(__builtin_offsetof(PlayerDroneTransition, step) == 0x190, "drone transition step");
#endif
#endif
