#ifndef CORE2_REFLECTION_PLANES_H
#define CORE2_REFLECTION_PLANES_H

#include <ultra64.h>

typedef struct {
    s16 map, model, alpha, water;
    f32 point[3], normal[3];
} ReflectionPlane;

extern ReflectionPlane D_8011A760[3];

#endif
