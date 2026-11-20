#ifndef BT_BA_THRUST_PHYSICS_H
#define BT_BA_THRUST_PHYSICS_H
#ifdef BT_NATIVE
#include "overlays/ba/playerstate.h"
#include "core2/1E75710.h"
#include "overlays/ba/yaw.h"

typedef struct {
    s32 type;
    f32 position[3];
    f32 velocity[3];
    f32 target[3];
    f32 displacement[3];
    f32 gravity;
    f32 terminal_velocity;
    u8 pad3C[0x48];
    f32 drag;
    f32 unk88;
    f32 thrust;
} ThrustPhysics;
_Static_assert(__builtin_offsetof(ThrustPhysics, velocity) == 0x10 &&
               __builtin_offsetof(ThrustPhysics, gravity) == 0x34 &&
               __builtin_offsetof(ThrustPhysics, thrust) == 0x8C, "player thrust layout");

#define THRUST_PHYSICS(player) ((ThrustPhysics *)((PlayerState *)(player))->physics)
#endif
#endif
