#ifndef CORE2_CAMERA_STATE_CALLBACKS_H
#define CORE2_CAMERA_STATE_CALLBACKS_H

#include "common.h"

struct player_state_s;
typedef void (*CameraStateMethod)(struct player_state_s *);
typedef struct {
    CameraStateMethod enter, update, exit;
    u32 flags;
} CameraStateCallbacks;

extern CameraStateCallbacks D_801247A0[27];
extern s32 (*D_80124950[28])(void);

#endif
