#ifndef GC_MAP_DLL_CONFIG_H
#define GC_MAP_DLL_CONFIG_H

#include "common.h"

typedef struct {
    s16 id;
    u16 assets[2];
    s8 padding[6];
    u8 clone[2];
} MapConfig;

#endif
