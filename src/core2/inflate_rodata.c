#include "common.h"
#include "core1/inflate_tables.h"

const f32 D_80126630[] = {
    0.007874015719f,
};

const f32 D_80126634[] = {
    0.007874015719f, 0.0f, 0.0f,
};

typedef struct { u8 order[19]; u8 padding; } CoreCodeLengthOrder;
const CoreCodeLengthOrder D_80126640[] = {{BT_INFLATE_CODE_LENGTH_ORDER, 0}};

typedef struct {
    u16 length_base[31];
    u8 length_extra[31];
    u8 padding1;
    u16 distance_base[30];
    u8 distance_extra[30];
    u16 masks[17];
    u16 padding2;
} CoreInflateTables;

const CoreInflateTables D_80126654[] = {{
    BT_INFLATE_LENGTH_BASE,
    BT_INFLATE_LENGTH_EXTRA_BITS,
    0,
    BT_INFLATE_DISTANCE_BASE,
    BT_INFLATE_DISTANCE_EXTRA_BITS,
    BT_INFLATE_MASK_BITS,
    0,
}};
