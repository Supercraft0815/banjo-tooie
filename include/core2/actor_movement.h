#ifndef CORE2_ACTOR_MOVEMENT_H
#define CORE2_ACTOR_MOVEMENT_H

#include "common.h"

typedef s32 (*ActorMovementMethod)(Actor *, f32 *, s32, s32);
extern ActorMovementMethod *D_80124714[7];

#endif
