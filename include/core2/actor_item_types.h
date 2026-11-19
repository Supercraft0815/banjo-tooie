#ifndef CORE2_ACTOR_ITEM_TYPES_H
#define CORE2_ACTOR_ITEM_TYPES_H

#include "types.h"

typedef struct {
    void (*create)(void *data, s32 variant, void *model, s32 mesh, s32 flags);
    void (*update)(void *data, void *model, s32 mesh);
    void (*destroy)(void *data);
    void (*defrag)(void *data);
} ActorItemType;

extern ActorItemType D_80124440[11];

#endif
