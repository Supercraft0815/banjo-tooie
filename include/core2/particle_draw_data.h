#ifndef CORE2_PARTICLE_DRAW_DATA_H
#define CORE2_PARTICLE_DRAW_DATA_H

#include <ultra64.h>

typedef struct {
    u8 id, capacity;
} ParticleEmitterSetting;

extern ParticleEmitterSetting particle_emitter_settings[41];
extern u8 D_80128150[41];

#endif
