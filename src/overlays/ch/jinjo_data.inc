/* data_to_c.py: from asm/data/overlays/ch/jinjo.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80101870();
void func_80108ED0();
void func_80107C2C();
ActorAnimationEntry D_808012B0_chjinjo[10] BT_DATA(4, overlays_ch_jinjo, 0x0) = {
    {0.0f, 0x0, 0x0},          {1.5f, 0x2d, 0x44}, {1.5f, 0x2d, 0x42},         {1.5f, 0x2f, 0x42},
    {0.75f, 0x31, 0x42},       {1.5f, 0x2d, 0x44}, {0.400000006f, 0x31, 0x41}, {1.75f, 0x1f, 0x42},
    {2.13333011f, 0x24, 0x42}, {0.0f, 0x0, 0x0}};
JinjoMapColor D_80801300_chjinjo[9] BT_DATA(4, overlays_ch_jinjo, 0x50) = {
    {325, 4}, {326, 8}, {327, 2}, {328, 6}, {330, 3}, {331, 1}, {332, 7}, {333, 5}, {334, 0}};
s16 D_80801324_chjinjo[6] BT_DATA(4, overlays_ch_jinjo, 0x74) = {19, 1006, 22, 26000, 0, 0};
s16 D_80801330_chjinjo[6] BT_DATA(4, overlays_ch_jinjo, 0x80) = {19, 1050, 22, 22000, 0, 0};
s16 D_8080133C_chjinjo[6] BT_DATA(4, overlays_ch_jinjo, 0x8C) = {19, 1039, 22, 22000, 0, 0};
s16 D_80801348_chjinjo[8] BT_DATA(4, overlays_ch_jinjo, 0x98) = {19, 1082,  10, 384,
                                                                 22, 32767, 0,  0};
s16 D_80801358_chjinjo[8] BT_DATA(4, overlays_ch_jinjo, 0xA8) = {19, 1028,  10, 460,
                                                                 22, 18000, 0,  0};
s16 D_80801368_chjinjo[10] BT_DATA(4, overlays_ch_jinjo, 0xB8) = {114, 21, 17, 116, 18,
                                                                  112, 19, 20, 115, 0};
s16 D_8080137C_chjinjo[10] BT_DATA(4, overlays_ch_jinjo, 0xCC) = {774, 27,   19, 1040,  1,
                                                                  500, 2000, 22, 10000, 0};
u16 D_80801390_chjinjo[10] BT_DATA(4, overlays_ch_jinjo, 0xE0) = {
    0x1525, 0x1526, 0x1527, 0x1528, 0x1529, 0x152A, 0x152B, 0x152C, 0x152D, 0};
ActorData D_808013A4_chjinjo[1] BT_DATA(4, overlays_ch_jinjo, 0xF4) = {
    {90,
     500,
     1603,
     2,
     D_808012B0_chjinjo,
     (void (*)(struct Actor *))func_808002E0_chjinjo,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     163840000,
     1061997773,
     0,
     0,
     128,
     292,
     (void (*)(struct Actor *))func_80800120_chjinjo,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80800000_chjinjo,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -31728,
     24576,
     (void (*)(struct Actor *, long, long))func_80800C10_chjinjo,
     0}};
ActorData D_808013EC_chjinjo[1] BT_DATA(4, overlays_ch_jinjo, 0x13C) = {
    {884,
     1167,
     1603,
     2,
     D_808012B0_chjinjo,
     (void (*)(struct Actor *))func_808002E0_chjinjo,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     163840000,
     1061997773,
     0,
     0,
     128,
     288,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800000_chjinjo,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -31728,
     25602,
     (void (*)(struct Actor *, long, long))func_80800C10_chjinjo,
     0}};
