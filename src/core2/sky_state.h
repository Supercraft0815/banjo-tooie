#ifndef CORE2_SKY_STATE_H
#define CORE2_SKY_STATE_H

#ifdef BT_NATIVE
#include <stddef.h>
#endif
#include "common.h"

typedef struct SkyLayerConfig {
    u16 asset_id;
    u16 pad02;
    f32 scale;
    f32 rate;
    s32 dynamic_vertices;
} SkyLayerConfig;

typedef struct SkyMapConfig {
    s16 map_id;
    u16 pad02;
    SkyLayerConfig layers[2];
} SkyMapConfig;

#ifdef BT_NATIVE
_Static_assert(sizeof(SkyLayerConfig) == 0x10, "Sky layer configuration stride");
_Static_assert(offsetof(SkyMapConfig, layers) == 4, "Sky map configuration prefix");
_Static_assert(offsetof(SkyMapConfig, layers[1]) == 0x14, "Second sky level offset");
_Static_assert(sizeof(SkyMapConfig) == 0x24, "Sky map configuration stride");
#endif

typedef struct SkyState {
    BT_NATIVE_ONLY(void *controllers[2];) BT_IDO_ONLY(s32 controllers[2];)
    BT_NATIVE_ONLY(void *handles[2];) BT_IDO_ONLY(s32 handles[2];)
    BT_NATIVE_ONLY(void *models[2];) BT_IDO_ONLY(s32 models[2];)
    BT_NATIVE_ONLY(void *textures[2];) BT_IDO_ONLY(s32 textures[2];)
    BT_NATIVE_ONLY(void *vertices[2][2];) BT_IDO_ONLY(s32 vertices[2][2];)
    s32 render_switches[60];
    f32 rates[2];
    f32 scales[2];
    f32 distance;
    f32 age;
    s32 index[2];
} SkyState;

#if defined(BT_NATIVE) && defined(BT_ILP32)
_Static_assert(sizeof(SkyState) == 0x140, "ILP32 SkyState size");
_Static_assert(offsetof(SkyState, handles) == 0x08, "ILP32 SkyState handles");
_Static_assert(offsetof(SkyState, models) == 0x10, "ILP32 SkyState models");
_Static_assert(offsetof(SkyState, textures) == 0x18, "ILP32 SkyState textures");
_Static_assert(offsetof(SkyState, vertices) == 0x20, "ILP32 SkyState vertices");
_Static_assert(offsetof(SkyState, render_switches) == 0x30, "ILP32 SkyState switches");
_Static_assert(offsetof(SkyState, rates) == 0x120, "ILP32 SkyState rates");
_Static_assert(offsetof(SkyState, age) == 0x134, "ILP32 SkyState age");
_Static_assert(offsetof(SkyState, index) == 0x138, "ILP32 SkyState indices");
#elif defined(BT_NATIVE)
_Static_assert(sizeof(SkyState) == 0x170, "LP64 SkyState size");
_Static_assert(offsetof(SkyState, handles) == 0x10, "LP64 SkyState handles");
_Static_assert(offsetof(SkyState, models) == 0x20, "LP64 SkyState models");
_Static_assert(offsetof(SkyState, textures) == 0x30, "LP64 SkyState textures");
_Static_assert(offsetof(SkyState, vertices) == 0x40, "LP64 SkyState vertices");
_Static_assert(offsetof(SkyState, rates) == 0x150, "LP64 SkyState rates");
_Static_assert(offsetof(SkyState, scales) == 0x158, "LP64 SkyState scales");
_Static_assert(offsetof(SkyState, distance) == 0x160, "LP64 SkyState distance");
_Static_assert(offsetof(SkyState, index) == 0x168, "LP64 SkyState indices");
_Static_assert(offsetof(SkyState, render_switches) == 0x60, "LP64 SkyState switches");
_Static_assert(offsetof(SkyState, age) == 0x164, "LP64 SkyState age");
#endif

#endif
