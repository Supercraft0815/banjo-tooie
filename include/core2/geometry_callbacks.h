#ifndef CORE2_GEOMETRY_CALLBACKS_H
#define CORE2_GEOMETRY_CALLBACKS_H

#include "common.h"

typedef struct {
    LookAt buffer[32];
    LookAt *current;
    LookAt *end;
    f32 position[3];
} LookAtBuffer;

struct GeometryRenderData;
typedef void (*GeometryBegin)(struct GeometryRenderData *, s32, void *, const f32 *);
typedef void (*GeometryVertex)(f32 *, s32 *, s32);
typedef struct {
    GeometryBegin begin;
    GeometryVertex vertex;
    void (*finish)(void);
} GeometryCallbacks;

extern GeometryCallbacks D_80123030[5];
extern GeometryVertex D_8012CEC4;

#endif
