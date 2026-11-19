#ifndef __BS_DRONE_H__
#define __BS_DRONE_H__

#include "common.h"
#include "overlays/ba/playerstate.h"

typedef void (*DroneCallback)(PlayerState *);

typedef struct {
    u8 type;
    DroneCallback init;
    DroneCallback update;
    DroneCallback end;
    DroneCallback interrupt;
} NativeDroneState;

extern BT_LP64_ONLY(const) NativeDroneState D_80800180_bsdrone[16];

extern void _bsdrone_entrypoint_0(PlayerState *self);
extern void _bsdrone_entrypoint_1(PlayerState *self);
extern void _bsdrone_entrypoint_2(PlayerState *self);
extern void _bsdrone_entrypoint_3(PlayerState *self);

#endif // __BS_DRONE_H__
