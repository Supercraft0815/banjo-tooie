/* data_to_c.py: from asm/data/overlays/ch/masterjiggy.data.s */
#include "core2/actor_animation_entry.h"

void func_80102EC0();
void func_80101870(Actor *, void *);
void func_80107C2C();
ActorAnimationEntry D_808015C0_chmasterjiggy[12] BT_DATA(4, overlays_ch_masterjiggy, 0x0) = {
    {0.0f, 0x0, 0x0},          {19.2000008f, 0x4c1, 0x0}, {19.2000008f, 0x4c1, 0x0},
    {19.2000008f, 0x4c1, 0x0}, {19.2000008f, 0x4c1, 0x0}, {19.2000008f, 0x4c1, 0x0},
    {2.625f, 0x4ca, 0x4a},     {1.0f, 0x4cb, 0x9},        {19.2000008f, 0x4c1, 0x0},
    {19.2000008f, 0x4c1, 0xa}, {2.625f, 0x4ca, 0xa},      {1.0f, 0x4cb, 0x9}};
s16 D_80801620_chmasterjiggy[11][2] BT_DATA(4, overlays_ch_masterjiggy, 0x60) = {
    {5366, 76}, {5367, 11}, {5432, 11}, {5368, 0},  {5372, 0}, {5393, 0},
    {5392, 76}, {5467, 11}, {5468, 11}, {5469, 11}, {5470, 11}};
MasterJiggyConfig D_8080164C_chmasterjiggy BT_DATA(4, overlays_ch_masterjiggy, 0x8C) = {
    {344,
     481,
     2357,
     1,
     D_808015C0_chmasterjiggy,
     (void (*)(struct Actor *))func_808004FC_chmasterjiggy,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     264,
     (void (*)(struct Actor *))func_808001A8_chmasterjiggy,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080000C_chmasterjiggy,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9218,
     (void (*)(struct Actor *, long, long))func_808007F0_chmasterjiggy,
     0},
    {0.0f, 0.0f, 5.0f, 0.5f, 0.5f, 1.5f, 0.0f}};
f32 D_808016B0_chmasterjiggy[7][2] BT_DATA(4, overlays_ch_masterjiggy, 0xF0) = {
    {0.0f, 0.0f},    {0.1666f, 0.25f}, {0.3333f, 0.0f}, {0.5f, 0.5f},
    {0.6667f, 0.0f}, {0.8333f, 0.75f}, {1.0f, 0.0f}};
f32 D_808016E8_chmasterjiggy[2][2] BT_DATA(4, overlays_ch_masterjiggy, 0x128) = {{0.0f, 1.0f},
                                                                                 {1.0f, 0.0f}};
ActorData D_808016F8_chmasterjiggy[1] BT_DATA(4, overlays_ch_masterjiggy, 0x138) = {
    {344,
     1201,
     2075,
     1,
     0,
     (void (*)(struct Actor *))func_80800A40_chmasterjiggy,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_80800C08_chmasterjiggy,
     0,
     0,
     0,
     0,
     2,
     1024,
     (void (*)(struct Actor *))func_80800DDC_chmasterjiggy,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080095C_chmasterjiggy,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1026,
     (void (*)(struct Actor *, long, long))func_80801030_chmasterjiggy,
     0}};
s16 D_80801740_chmasterjiggy[8] BT_DATA(4, overlays_ch_masterjiggy, 0x180) = {19, 1651, 32, 2,
                                                                              10, 217,  0,  0};
s16 D_80801750_chmasterjiggy[8] BT_DATA(4, overlays_ch_masterjiggy, 0x190) = {19, 1193, 22, 24000,
                                                                              10, 256,  0,  0};
f32 D_80801760_chmasterjiggy[2][2] BT_DATA(4, overlays_ch_masterjiggy, 0x1A0) = {{0.0f, 0.0f},
                                                                                 {1.0f, 1.0f}};
f32 D_80801770_chmasterjiggy[4][2] BT_DATA(4, overlays_ch_masterjiggy, 0x1B0) = {
    {0.0f, 0.0f}, {0.2f, 0.0f}, {0.8f, 1.0f}, {1.0f, 1.0f}};
s32 D_80801790_chmasterjiggy[3] BT_DATA(4, overlays_ch_masterjiggy, 0x1D0) = {255, 255, 255};
s16 D_8080179C_chmasterjiggy[34] BT_DATA(4, overlays_ch_masterjiggy, 0x1DC) = {
    29, 2533, 27, -200, -300, 45,  700, 1200, 11, 130, 190, 50,  0, 22, 514, 36, 51,
    89, 21,   0,  76,   30,   100, 100, 42,   0,  25,  128, 192, 4, 76, 7,   2,  0};
f32 D_808017E0_chmasterjiggy[3] BT_DATA(4, overlays_ch_masterjiggy, 0x220) = {0.0f, -330.0f, 0.0f};
