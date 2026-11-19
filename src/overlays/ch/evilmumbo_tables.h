#include "core2/actor_animation_entry.h"

typedef union {
#ifndef BT_NATIVE
    const void *originalWord;
#endif
    s16 bones[2];
} EvilMumboBonePair;
