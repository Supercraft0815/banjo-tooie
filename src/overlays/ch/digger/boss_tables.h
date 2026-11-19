#include "core2/actor_animation_entry.h"

typedef struct {
    u8 count, minimumHealth;
    s16 minimumDistance, maximumDistance, padding;
    f32 shotDelay, volleyDelay;
} DiggerBossAttack;

typedef struct {
    s16 count, minimumRadius, maximumRadius, padding;
    f32 delay;
    s16 minimumSpeed, maximumSpeed;
} DiggerBossProjectile;

typedef struct {
    s16 part, sound;
    f32 delay;
} DiggerBossExplosion;

extern ActorAnimationEntry D_80809D10_chdiggerboss[21];

BT_IDO_ONLY(extern s16 D_80809EE0_chdiggerboss;)
BT_IDO_ONLY(extern s16 D_80809EE2_chdiggerboss;)
