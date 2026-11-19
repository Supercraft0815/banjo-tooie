/* data_to_c.py: from asm/data/overlays/ch/dino/familysick.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_801018A4();
void func_80108ED0();
void func_80107C2C();

BtFnWord D_80800E60_chdinofamilysick[2] BT_DATA(4, overlays_ch_dino_familysick, 0x0) = {
    (BtFnWord)func_80800368_chdinofamilysick, (BtFnWord)func_8080030C_chdinofamilysick};
ActorAnimationEntry D_80800E68_chdinofamilysick[6] BT_DATA(4, overlays_ch_dino_familysick, 0x8) = {
    {0.0f, 0x0, 0x0},          {8.39999962f, 0x3f7, 0x1}, {8.39999962f, 0x3f7, 0x1},
    {8.39999962f, 0x3f7, 0x1}, {8.39999962f, 0x3f7, 0x1}, {8.39999962f, 0x3f7, 0x1}};
f32 D_80800E98_chdinofamilysick[4] BT_DATA(4, overlays_ch_dino_familysick, 0x38) = {200.0f, 100.0f,
                                                                                    200.0f, 100.0f};
ActorData D_80800EA8_chdinofamilysick[1] BT_DATA(4, overlays_ch_dino_familysick, 0x48) = {
    {297,
     657,
     2203,
     1,
     (void *)D_80800E68_chdinofamilysick,
     (void (*)(struct Actor *))func_8080000C_chdinofamilysick,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     327680000,
     1073741824,
     0,
     0,
     132,
     288,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     21508,
     (void (*)(struct Actor *, long, long))func_808003B0_chdinofamilysick,
     0}};
ActorAnimationEntry D_80800EF0_chdinofamilysick[8] BT_DATA(4, overlays_ch_dino_familysick, 0x90) = {
    {0.0f, 0x0, 0x0},          {8.39999962f, 0x3f7, 0x1}, {8.39999962f, 0x3f7, 0x1},
    {2.20000005f, 0x3f8, 0x1}, {0.5f, 0x14c, 0x1},        {0.349999994f, 0x14c, 0x1},
    {2.20000005f, 0x3f8, 0x1}, {2.20000005f, 0x3f8, 0x1}};
Color D_80800F30_chdinofamilysick BT_DATA(4, overlays_ch_dino_familysick, 0xD0) = {{0, 0xFF, 0}};
Color D_80800F3C_chdinofamilysick BT_DATA(4, overlays_ch_dino_familysick,
                                          0xDC) = {{0xFF, 0xFF, 0xFF}};
f32 D_80800F48_chdinofamilysick[4][2] BT_DATA(4, overlays_ch_dino_familysick, 0xE8) = {
    {0.0f, 1.0f}, {0.25f, 0.75f}, {0.5f, 1.0f}, {0.75f, 0.75f}};
f32 D_80800F68_chdinofamilysick[4] BT_DATA(4, overlays_ch_dino_familysick,
                                           0x108) = {200.0f, 100.0f, 200.0f, 100.0f};
ActorData D_80800F78_chdinofamilysick[1] BT_DATA(4, overlays_ch_dino_familysick, 0x118) = {
    {344,
     1325,
     2203,
     1,
     (void *)D_80800EF0_chdinofamilysick,
     (void (*)(struct Actor *))func_80800768_chdinofamilysick,
     (void (*)(struct Actor *))func_80800768_chdinofamilysick,
     (void (*)(long, long))func_801018A4,
     131072000,
     1073741824,
     0,
     0,
     132,
     288,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_808005F8_chdinofamilysick,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     21510,
     (void (*)(struct Actor *, long, long))func_80800AB0_chdinofamilysick,
     0}};
