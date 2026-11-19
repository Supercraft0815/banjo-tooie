#include "core2/player_motion_data.h"
#include "bt_data.h"

FallThreshold D_80117E60[12] BT_DATA(4, player_motion, 0) = {
    {1000, 0, 0}, {1500, 0, 0}, {2000, 0, 0},
    {7000, 8, 2}, {6000, 7, 1}, {5000, 6, 1}, {4000, 5, 1},
    {3000, 4, 1}, {2000, 3, 1}, {1000, 2, 1}, {0, 1, 1}, {-1, 0, 0},
};

f32 D_80117E90[3] BT_DATA(4, player_motion, 0x30) = {0, 0, 0};
f32 D_80117E9C[3] BT_DATA(4, player_motion, 0x3C) = {1, 1, 1};
u32 player_vector_padding[2] BT_DATA(4, player_motion, 0x48) = {0};
s32 D_80117EB0[4] BT_DATA(4, player_motion, 0x50) = {0x161, -1, 0, 0};

/* Map ID and bounds expansion on the negative and positive sides of each axis. */
s16 D_80117EC0[24] BT_DATA(2, player_motion, 0x60) = {
    0x136, 1500, 8000, 1500, 1500, 3000, 1500,
    0x155, 2000, 8000, 2000, 2000, 2000, 2000,
    0,      500, 8000,  500,  500, 1000,  500,
};

f32 D_80117EF0 BT_DATA(4, player_motion, 0x90) = -2700.0f;
f32 D_80117EF4 BT_DATA(4, player_motion, 0x94) = -4000.0f;
u32 player_physics_padding[2] BT_DATA(4, player_motion, 0x98) = {0};
PlayerNodeMapping player_node_mapping[11] BT_DATA(2, player_motion, 0xA0) = {
    {0, -1}, {1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 8},
    {6, 13}, {7, 10}, {8, 9}, {9, 11}, {10, 10},
};
