#include "common.h"

typedef struct { s32 flags, category; } LightCategory;
typedef struct { LightCategory rows[17]; u32 padding[2]; } LightCategoryList;

LightCategoryList D_8011A930 BT_DATA(4, light_defaults, 0) = {
    {
        {0x0100, 1},
        {0x0200, 10},
        {0x0300, 9},
        {0x0400, 6},
        {0x0500, 5},
        {0x0600, 3},
        {0x0700, 7},
        {0x0800, 8},
        {0x0900, 2},
        {0x0A00, 11},
        {0x0B00, 16},
        {0x0C00, 17},
        {0x0D00, 18},
        {0x0E00, 20},
        {0x0F00, 21},
        {0x1000, 24},
        {0x1100, 25},
    },
    {0, 0}
};

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_lights.h"
typedef NativeLightPredicate LightPredicate;
#else
typedef s32 (*LightPredicate)(u32, s32);
u32 func_800C8594(u8 *, u32);
u32 func_800C8588(u8 *, s32);
int func_800C8560(void *, s32);
#endif

LightPredicate D_8011A9C0[3] BT_DATA(4, light_defaults, 0x90) = {
    (LightPredicate)func_800C8594,
    (LightPredicate)func_800C8588,
    (LightPredicate)func_800C8560,
};

f32 D_8011A9CC[3] BT_DATA(4, light_defaults, 0x9C) = {0.0f, 0.0f, 0.0f};

f32 D_8011A9D8[2] BT_DATA(4, light_defaults, 0xA8) = {150.0f, 3000.0f};

u32 D_8011A9E0[3] BT_DATA(4, light_defaults, 0xB0) = {255, 255, 255};

f32 D_8011A9EC[3] BT_DATA(4, light_defaults, 0xBC) = {0.0f, -16000.0f, 0.0f};

f32 D_8011A9F8[2] BT_DATA(4, light_defaults, 0xC8) = {0.0f, 1.0f};

u32 D_8011AA00[3] BT_DATA(4, light_defaults, 0xD0) = {0, 0, 0};
