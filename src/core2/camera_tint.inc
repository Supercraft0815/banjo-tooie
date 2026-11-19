#include "common.h"

typedef struct {
    u8 map, red, green, blue, alpha;
} CameraTintPreset;
typedef union {
    CameraTintPreset rows[1];
    u32 alignment;
} CameraTintTable;

CameraTintTable D_80124A50 BT_DATA(4, camera_tint, 0) = {{{0, 30, 80, 239, 32}}};
s16 D_80124A58[7] BT_DATA(2, camera_tint, 8) = {
    0x181, 0x1A7, 0x1A8, 0x1A9, 0xFC, 0x1A6, 0,
};

typedef struct {
    void *controller;
    s32 preset;
    f32 depth;
    u8 submerged, oscillating, draw;
    f32 phase;
} CameraTintEffect;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define TINT_FIELD(effect, field, retail) (((CameraTintEffect *)(effect))->field)
#else
#define TINT_FIELD(effect, field, retail) (retail)
#endif
