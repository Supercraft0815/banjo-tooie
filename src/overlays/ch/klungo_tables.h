#include "core2/actor_animation_entry.h"

typedef struct {
    s32 action, options;
} KlungoRound;
typedef struct {
    s16 map, defeatedFlag, reward;
    u16 model;
    KlungoRound rounds[10];
    f32 spawnSpeed, spawnScale, unk60, unk64, unk68, unk6C, speed;
    s16 dialog[4], range;
    u8 color[4], padding[2];
} KlungoEncounter;
extern KlungoEncounter D_808038A0_chklungo[3];

typedef union {
    struct {
        ActorAnimationEntry states[34];
        f32 nextDuration;
    } prefix;
#ifdef BT_NATIVE
    ActorAnimationEntry states[36];
#endif
} KlungoAnimations;
