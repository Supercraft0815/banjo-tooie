#ifndef CORE2_WORLD_EFFECT_H
#define CORE2_WORLD_EFFECT_H

#include "core2/mesh_effect.h"

struct Vector;
extern struct Vector *D_80127EF8;

typedef struct {
    BtIntPtr owner;
    s16 id;
    u8 type;
    s8 active;
    BT_NATIVE_ONLY(_Alignas(void *)) u8 data[sizeof(MeshEffect)];
} WorldEffect;

typedef struct {
    u8 pad0[0xC];
    s16 unkC, unkE, unk10, unk12;
    s32 unk14;
    s16 unk18, unk1A;
    f32 timer, interval;
    s16 unk24, unk26, count;
    u8 *particles;
} TwinkleEffect;

typedef struct {
    u8 pad0[0xC];
    s16 unkC;
    u8 padE[6];
    s32 unk14;
    s16 unk18, unk1A, unk1C, unk1E, unk20, unk22;
    u8 *particles;
} TwinkleColorEffect;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[0x14];
    f32 unk1C, unk20;
    f32 *begin, *cursor, *end;
    f32 unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    f32 unk50, unk54, unk58, unk5C;
} BounceEffect;

typedef struct { u8 *begin, *end; } TwinkleRange;

typedef void (*WorldEffectDefrag)(void *);
extern WorldEffectDefrag D_80123590[16];

#endif
