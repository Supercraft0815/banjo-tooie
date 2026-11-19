#ifndef CORE2_MESH_EFFECT_H
#define CORE2_MESH_EFFECT_H

#include "types.h"

typedef struct {
    u8 unk0;
    f32 unk4;
    f32 unk8;
    void (*unkC)(void *);
    void (*unk10)(void *);
    s16 unk14[3];
    s16 unk1A[3];
    f32 unk20;
    f32 unk24;
    u8 unk28;
    u8 unk29;
    u8 pad2A[2];
    f32 unk2C[3];
    f32 unk38[3];
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    s16 unk4E;
    f32 unk50[4];
    f32 unk60[4];
    f32 unk70;
    f32 unk74;
    f32 unk78[3];
    f32 unk84;
    f32 unk88[3];
    f32 unk94;
    f32 unk98;
    f32 unk9C;
} MeshEffect;

#endif
