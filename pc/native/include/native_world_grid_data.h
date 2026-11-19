#ifndef BT_NATIVE_WORLD_GRID_DATA_H
#define BT_NATIVE_WORLD_GRID_DATA_H
#include "common.h"
typedef struct { s16 models[2], dynamic[2]; } NativeWorldCell;
typedef struct {
    NativeWorldCell *cells;
    s32 lower[3], upper[3];
    s32 row_stride, plane_stride, count;
    s32 dimensions[3];
    NativeWorldCell fallback;
    s16 cell_size;
    u8 fallback_models, padding;
    f32 scale;
    u8 *model_counts;
} NativeWorldGrid;
#endif
