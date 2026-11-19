#include "overlays/ba/assets.h"

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
