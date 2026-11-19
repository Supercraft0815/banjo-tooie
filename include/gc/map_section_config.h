#ifndef GC_MAP_SECTION_CONFIG_H
#define GC_MAP_SECTION_CONFIG_H
#include <ultra64.h>

typedef struct {
    f32 position[3], minimum[3], maximum[3];
    s16 height;
    u16 assets[2];
} MapSectionConfig;

#endif
