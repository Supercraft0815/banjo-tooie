#ifndef CORE2_REFLECTION_PLANES_H
#define CORE2_REFLECTION_PLANES_H

#include "core1/mlmtx.h"

typedef struct {
    s16 map, model, alpha, water;
    f32 point[3], normal[3];
} ReflectionPlane;

typedef struct {
    Gfx *buffers[2], *saved_gfx;
    u8 index, active, bounds_valid, bounds_cached, cull_enabled, alpha;
    s16 model;
    MtxF matrix;
    Mtx fixed;
    f32 point[3], normal[3], minimum[3], maximum[3];
    Gfx restore[2][6];
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    Gfx *saved_end;
    Mtx *saved_mtx;
    struct NativeGraphicsContext *frame;
#endif
} NativeReflection;

extern ReflectionPlane D_8011A760[3];

#endif
