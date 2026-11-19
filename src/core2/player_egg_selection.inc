#include "bt_data.h"

/* The preceding model-map object ends eight bytes before this N64 section boundary. */
#ifndef BT_NATIVE
u32 playerModelMapAlignment[2] = {0, 0};
#endif

u8 D_80117E20[8] BT_DATA(4, player_egg_selection, 0x0) = {1, 2, 4, 3, 5, 0};
u8 D_80117E28[4] BT_DATA(4, player_egg_selection, 0x8) = {1, 0};
u8 D_80117E2C[4] BT_DATA(4, player_egg_selection, 0xC) = {7, 0};

u8 *D_80117E30[3] BT_DATA(4, player_egg_selection, 0x10) = {
    D_80117E20, D_80117E28, D_80117E2C
};

typedef struct { u8 shotCount, repeat; } EggFirePolicy;
EggFirePolicy eggFirePolicies[8] BT_DATA(1, player_egg_selection, 0x1C) = {
    {0, 0},
    {3, 0},
    {2, 0},
    {2, 0},
    {1, 0},
    {1, 0},
    {1, 0},
    {0, 1},
};

/* The five regular egg inventories also appear in the gcegg definitions. */
s16 playerEggInventoryItems[6] BT_DATA(2, player_egg_selection, 0x2C) = {
    0x40, 0x41, 0x42, 0x43, 0x44, -1
};

#ifdef BT_NATIVE
#define PLAYER_EGG_STATE(p) (((PlayerState *)(p))->eggSelection.slot)
#else
#define PLAYER_EGG_STATE(p) (*(PlayerEggSelection **)((u8 *)(p) + 0x64))
#endif
