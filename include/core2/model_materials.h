#ifndef CORE2_MODEL_MATERIALS_H
#define CORE2_MODEL_MATERIALS_H

#include <ultra64.h>

typedef struct {
    Gfx *opaque, *translucent;
} ModelMaterialModes;

extern ModelMaterialModes model_material_modes[5];
extern Gfx D_80122DB0[3], D_80122DF0[24], D_80122EB0[24], D_80122F70[24];

#endif
