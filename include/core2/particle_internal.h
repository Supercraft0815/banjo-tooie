#ifndef BT_PARTICLE_INTERNAL_H
#define BT_PARTICLE_INTERNAL_H

#include "types.h"

/* One particle of a ParticleEmitter; positions and ranges are s16, scales and frames 8.8 fixed point. */
typedef struct particle_s {
    /* 0x00 */ s16 acceleration[3];
    /* 0x06 */ s16 position[3];
    /* 0x0C */ f32 fade;
    /* 0x10 */ f32 rotation[3];
    /* 0x1C */ f32 age;
    /* 0x20 */ s16 angular_velocity[3];
    /* 0x26 */ s16 velocity[3];
    /* 0x2C */ s16 frame;
    /* 0x2E */ s16 framerate;
    /* 0x30 */ s16 scale;
    /* 0x32 */ s16 start_scale;
    /* 0x34 */ s16 scale_delta;
    /* 0x36 */ s16 lifetime;
    /* 0x38 */ s8 unk38;
    /* 0x39 */ BT_BITFIELD_ORDER(u8 active:1, u8 unk39 : 7);
    BT_BITFIELD_ORDER(u8 unk39:7, u8 active : 1);
} Particle;

/* Particle emitter; the particle array follows the header (see func_800BA2E8). Ranges are {min, max}. */
typedef struct particle_emitter_s {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 asset_id;
    /* 0x04 */ u8 velocity_mode; // which member of velocity is used
    /* 0x05 */ u8 spawn_mode; // which member of spawn is used
    u8 pad6;
    /* 0x07 */ u8 state;
    u8 remove_when_empty;
    u8 managed;
    /* 0x0A */ s8 asset_kind;
    /* 0x0B */ s8 unkB;
    /* 0x0C */ s16 unkC[3];
    /* 0x12 */ s16 position[3];
    /* 0x18 */ f32 fade_in;
    /* 0x1C */ f32 fade_out;
    /* 0x20 */ f32 spawn_timer;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ union {
        struct { s16 min[3]; s16 max[3]; } box; // spawn_mode 0
        struct { s16 radius[2]; } sphere; // spawn_mode 1
        struct { s16 radius[2]; s16 height[2]; } ring; // spawn_mode 2
    } spawn;
    /* 0x34 */ s16 acceleration_min[3];
    /* 0x3A */ s16 acceleration_max[3];
    /* 0x40 */ s16 angular_velocity_min[3];
    /* 0x46 */ s16 angular_velocity_max[3];
    /* 0x4C */ s16 rotation[3];
    /* 0x52 */ u8 unk52;
    /* 0x53 */ u8 unk53;
    /* 0x54 */ f32 spawn_interval[2];
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ f32 unk60[3];
    /* 0x6C */ f32 unk6C[3];
    /* 0x78 */ f32 framerate[2];
    /* 0x80 */ u8 color[4];
    /* 0x84 */ s16 start_frame[2];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ Particle *begin;
    /* 0x90 */ Particle *end;
    /* 0x94 */ Particle *capacity;
    /* 0x98 */ s16 unk98;
    /* 0x9A */ s16 start_scale[2];
    /* 0x9E */ s16 final_scale[2];
    /* 0xA2 */ s16 lifetime[2];
    u8 padA6[2];
    /* 0xA8 */ s16 unkA8;
    /* 0xAA */ s16 unkAA;
    /* 0xAC */ s16 min_y;
    /* 0xAE */ s16 max_y;
    /* 0xB0 */ f32 unkB0;
    /* 0xB4 */ f32 unkB4;
    /* 0xB8 */ f32 unkB8;
    /* 0xBC */ s32 unkBC;
    /* 0xC0 */ void (*on_bounce)(struct particle_emitter_s *, f32 *);
    /* 0xC4 */ union {
        struct { s16 min[3]; s16 max[3]; } box; // velocity_mode 0
        struct { s16 pitch[2]; s16 yaw[2]; s16 speed[2]; } sphere; // velocity_mode 1
        struct { s16 speed[2]; s16 point[3]; } toward; // velocity_mode 2
    } velocity;
    /* 0xD0 */ f32 unkD0;
    /* 0xD4 */ Particle particles[1];
} ParticleEmitter;

#endif
