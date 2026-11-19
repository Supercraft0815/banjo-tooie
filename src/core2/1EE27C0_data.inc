#include "overlays/ba/assets.h"
#include "marker_hit_callbacks.h"
#include "core2/1EDA900.h"
#include "core2/particle_colors.h"

typedef struct {
    s16 sprite;
    s16 unused[7];
} HitSpritePreset;

HitSpritePreset D_801245A0[3] BT_DATA(4, hit_animation_ids, 0) = {
    {RED_SPARKLE}, {LIGHT_BLUE_SPARKLE}, {GOLD_SPARKLE}
};

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define HIT_SPRITE_TYPE(marker) (((Unk80132ED0 *)(marker))->unk24 >> 22)
#else
#define HIT_SPRITE_TYPE(marker) (((Obj1EE27C0_arg2 *)(marker))->unk24 >> 22)
#endif

void func_80108F08(void *, void *, s32);
void func_80109F18(void *, void *volatile), func_80109F40(void *, void *volatile), func_80109F68(void *, void *volatile);
s32 func_80109F90(void *, void *volatile);

MarkerHitMethods D_801245D0 BT_DATA(4, hit_animation_ids, 0x30) = {
    {func_80109F18, func_80109F40, func_80109F68}, func_80108F08, NULL
};

MarkerHitMethods D_801245E4 BT_DATA(4, hit_animation_ids, 0x44) = {
    {func_80109F18, func_80109F40, func_80109F68}, func_80108F08, func_80109F90
};

MarkerHitMethods D_801245F8 BT_DATA(4, hit_animation_ids, 0x58) = {
    {func_80109F18, func_80109F40, func_80109F68}, NULL, NULL
};

s16 D_8012460C[8] BT_DATA(4, hit_animation_ids, 0x6C) = {
    33, 22, 26000, 1, 800, 5000, 0, 0
};

s16 D_8012461C[24] BT_DATA(4, hit_animation_ids, 0x7C) = {
    29, 2525, 43, 102, 128, 34, 204, 307, 358,
    409, 21, 25, 153, 25, 0, 7, 45, 50,
    80, -32766, 14, 10, 20, 0
};

s16 D_8012464C[30] BT_DATA(4, hit_animation_ids, 0xAC) = {
    21, 102, 204, 39, 0, 200, 0, 240, 22,
    4096, 21, 25, 102, 34, 102, 128, 64, 89,
    43, 102, 128, 45, 300, 400, 14, 10, 20,
    2586, 0, 0
};

u8 D_80124688[8] BT_DATA(4, hit_animation_ids, 0xE8) = {135, 135, 135, 160};
