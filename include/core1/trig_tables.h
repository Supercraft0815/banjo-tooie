#ifndef CORE1_TRIG_TABLES_H
#define CORE1_TRIG_TABLES_H

#include <ultra64.h>

typedef struct {
    s32 base, first, shift, padding;
} ArcsineRange;

typedef struct {
    s8 range_offsets[132];
    ArcsineRange ranges[7];
    s16 sample_indices[774];
} ArcsineLookup;

extern f32 D_8003CC90[4];
extern ArcsineLookup D_8003CCA0;
extern f32 D_8003D3A0[2052];

#endif
