#ifndef BT_NATIVE_DRONE_STATES_H
#define BT_NATIVE_DRONE_STATES_H

#include "overlays/ba/playerstate.h"

typedef struct {
    u8 type;
    void (*init)(PlayerState *);
    void (*update)(PlayerState *);
    void (*end)(PlayerState *);
    void (*interrupt)(PlayerState *);
} NativeDroneState;

extern const NativeDroneState D_80800180_bsdrone[16];

#endif
