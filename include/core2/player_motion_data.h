#ifndef CORE2_PLAYER_MOTION_DATA_H
#define CORE2_PLAYER_MOTION_DATA_H

#include <ultra64.h>

typedef struct {
    s16 height;
    u8 severity, damage;
} FallThreshold;

typedef struct {
    s16 index, node;
} PlayerNodeMapping;

extern FallThreshold D_80117E60[12];
extern s32 D_80117EB0[4];
extern s16 D_80117EC0[24];
extern PlayerNodeMapping player_node_mapping[11];

#endif
