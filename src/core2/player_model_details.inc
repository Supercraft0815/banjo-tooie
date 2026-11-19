#include "bt_data.h"
#include "maps.h"

typedef struct {
    f32 distance;
    s32 memoryCredit, normalModel, dragonModel;
} PlayerModelDetail;

typedef struct {
    s16 map, detail;
} PlayerModelMap;

PlayerModelDetail playerModelDetails[2] BT_DATA(4, player_model_details, 0) = {
    {0.0f, 80000, 0x62A, 0x838},
    {800.0f, 70000, 0x62B, 0x839},
};

PlayerModelMap D_80117DF0[10] BT_DATA(2, player_model_details, 0x20) = {
    {MAP_B8_MT_MAYAHEM_TEMPLE, 1},
    {MAP_D6_WW_WITCHYWORLD, 1},
    {MAP_1A7_JRL_JOLLY_ROGERS_LAGOON, 1},
    {MAP_1A8_JRL_ATLANTIS, 1},
    {MAP_1A9_JRL_SEA_BOTTOM, 1},
    {MAP_112_TDL_TERRYDACTYLAND, 1},
    {MAP_127_HP_LAVA_SIDE, 1},
    {MAP_128_HP_ICY_SIDE, 1},
    {MAP_136_CCL_CLOUD_CUCKOOLAND, 1},
    {-1, 0},
};
