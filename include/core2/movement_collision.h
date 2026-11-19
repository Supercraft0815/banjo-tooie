#ifndef CORE2_MOVEMENT_COLLISION_H
#define CORE2_MOVEMENT_COLLISION_H

#include "common.h"

typedef struct {
    s16 vertices[3], pad;
    u32 flags;
} MovementTriangle;

typedef struct MovementCollision {
    f32 *object;
    f32 height, radius;
    void (*onContact)(BtUIntPtr, BtUIntPtr);
    void (*resetContact)(struct MovementCollision *);
    u32 flags;
    u8 previous;
    MovementTriangle *triangle;
    f32 matrix[3][3], normal[3];
    BtIntPtr contact;
    u8 blocked, count, flag;
} MovementCollision;

typedef struct PlayerCollisionState {
    MovementCollision response;
    f32 delta[3], targetHeight, targetRadius;
    MovementTriangle triangleCopy;
    f32 position[3], oldPosition[3], movement[3];
    s32 mode;
    u8 flagA0, flagA1, flagA2, flagA3, flagA4;
    s32 status;
} PlayerCollisionState;

#if !defined(BT_NATIVE) || defined(BT_ILP32)
typedef char bt_player_collision_size[(sizeof(PlayerCollisionState) == 0xAC) ? 1 : -1];
#endif

#endif
