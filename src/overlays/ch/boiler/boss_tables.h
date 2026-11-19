#include "core2/actor_animation_entry.h"

typedef union {
    struct {
        ActorAnimationEntry states[16];
        f32 nextDuration;
    } prefix;
#ifdef BT_NATIVE
    ActorAnimationEntry states[18];
#endif
} BoilerBossAnimations;
