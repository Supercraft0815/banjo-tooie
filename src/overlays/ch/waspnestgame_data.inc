/* data_to_c.py: from asm/data/overlays/ch/waspnestgame.data.s */
void func_80102EC0();
void func_8010A730();
void func_80107C2C();
#include "core2/actor_animation_entry.h"
void func_801018A4();
void func_80108ED0();
ActorAnimationEntry D_80801F30_chwaspnestgame[8] BT_DATA(4, overlays_ch_waspnestgame, 0x0) = {
    {0.0f, 0x0, 0x0},           {0.649999976f, 0x3cb, 0x1}, {0.0f, 0x0, 0x0},
    {0.200000003f, 0x3cd, 0x1}, {1.0f, 0x3ce, 0x2},         {0.0f, 0x0, 0x0},
    {0.649999976f, 0x3cb, 0x1}, {1.0f, 0x3ce, 0x84}};
u16 D_80801F70_chwaspnestgame[8] BT_DATA(4, overlays_ch_waspnestgame,
                                         0x40) = {0x85F, 0x76B, 0x76C, 0x76D, 0x18, 0x14, 0x10, 0};
ActorData D_80801F80_chwaspnestgame[1] BT_DATA(4, overlays_ch_waspnestgame, 0x50) = {
    {344,
     483,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_8080047C_chwaspnestgame,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_8010A730,
     0,
     0,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800400_chwaspnestgame,
     0,
     96,
     0,
     (void (*)(struct Actor *))func_808002EC_chwaspnestgame,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9218,
     (void (*)(struct Actor *, long, long))func_80800724_chwaspnestgame,
     0}};
ActorData D_80801FC8_chwaspnestgame[1] BT_DATA(4, overlays_ch_waspnestgame, 0x98) = {
    {450,
     484,
     2143,
     1,
     (void *)D_80801F30_chwaspnestgame,
     (void (*)(struct Actor *))func_80801A10_chwaspnestgame,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_801018A4,
     0,
     1065353216,
     0,
     0,
     0,
     260,
     (void (*)(struct Actor *))func_808019D4_chwaspnestgame,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80801954_chwaspnestgame,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32736,
     0,
     (void (*)(struct Actor *, long, long))func_80801B9C_chwaspnestgame,
     0}};
s16 D_80802010_chwaspnestgame[10] BT_DATA(4, overlays_ch_waspnestgame,
                                          0xE0) = {518, 19, 1179, 1, 1000, 6000, 22, 10000, 7, 0};
s16 D_80802024_chwaspnestgame[10] BT_DATA(4, overlays_ch_waspnestgame,
                                          0xF4) = {19, 1550, 1, 1000, 6000, 13, 409, 435, 0, 0};
s16 D_80802038_chwaspnestgame[6] BT_DATA(4, overlays_ch_waspnestgame, 0x108) = {19,   1055, 1,
                                                                                1000, 6000, 0};
s16 D_80802044_chwaspnestgame[18] BT_DATA(4, overlays_ch_waspnestgame, 0x114) = {
    272, 29, 2081, 43, 512, 640, 34, 384, 512, 1152, 1280, 21, 0, 128, 51, 3, 0, 0};
s16 D_80802068_chwaspnestgame[10] BT_DATA(4, overlays_ch_waspnestgame,
                                          0x138) = {19, 1551, 1, 1000, 6000, 13, 217, 243, 0, 0};
s16 D_8080207C_chwaspnestgame[10] BT_DATA(4, overlays_ch_waspnestgame,
                                          0x14C) = {19, 1552, 1, 1000, 6000, 13, 243, 281, 0, 0};
