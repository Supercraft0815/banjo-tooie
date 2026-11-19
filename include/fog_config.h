#ifndef FOG_CONFIG_H
#define FOG_CONFIG_H

#include "common.h"

typedef struct {
    s16 map;
    u8 flags, padding;
    f32 start, end;
    u8 color[4];
} NativeFogConfig;

#endif
