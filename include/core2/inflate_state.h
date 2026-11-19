#ifndef CORE2_INFLATE_STATE_H
#define CORE2_INFLATE_STATE_H

#include <ultra64.h>

typedef struct {
    u64 random_seed;
    u64 padding;
    s32 *workspace;
    u32 reserved[2];
    s32 *input_buffer;
} Core2InflateState;

extern Core2InflateState core2_inflate_state;
#endif
