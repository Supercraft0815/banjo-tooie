/* data_to_c.py: from asm/data/overlays/ch/evilspirit.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80107C2C();
f32 D_808021D0_chevilspirit[4] BT_DATA(4, overlays_ch_evilspirit, 0x0) = {135.0f, 120.0f, 135.0f,
                                                                          40.0f};
s16 D_808021E0_chevilspirit[6] BT_DATA(4, overlays_ch_evilspirit, 0x10) = {19,  1258, 13,
                                                                           243, 268,  0};
s16 D_808021EC_chevilspirit[6] BT_DATA(4, overlays_ch_evilspirit, 0x1C) = {19,  1259, 13,
                                                                           243, 268,  0};
ActorAnimationEntry D_808021F8_chevilspirit[15] BT_DATA(4, overlays_ch_evilspirit, 0x28) = {
    {0.0f, 0x0, 0x0},   {5.0f, 0x49b, 0x1}, {5.0f, 0x49b, 0x1}, {5.0f, 0x49b, 0x1},
    {5.0f, 0x49b, 0x1}, {5.0f, 0x49b, 0x1}, {5.0f, 0x49b, 0x1}, {5.0f, 0x49b, 0x1},
    {5.0f, 0x49b, 0x1}, {5.0f, 0x3ef, 0x1}, {5.0f, 0x3ef, 0x1}, {5.0f, 0x49b, 0x1},
    {5.0f, 0x49b, 0x1}, {5.0f, 0x3ef, 0x1}, {5.0f, 0x3ef, 0x1}};
ActorData D_80802270_chevilspirit[1] BT_DATA(4, overlays_ch_evilspirit, 0xA0) = {
    {394,
     339,
     2319,
     1,
     D_808021F8_chevilspirit,
     (void (*)(struct Actor *))func_80800104_chevilspirit,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80800718_chevilspirit,
     0,
     0,
     0,
     0,
     2048,
     4352,
     (void (*)(struct Actor *))func_808005B4_chevilspirit,
     0,
     88,
     0,
     (void (*)(struct Actor *))func_8080000C_chevilspirit,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1026,
     (void (*)(struct Actor *, long, long))func_808005EC_chevilspirit,
     0}};
s16 D_808022B8_chevilspirit[8] BT_DATA(4, overlays_ch_evilspirit, 0xE8) = {19,  1262, 27, 13,
                                                                           243, 268,  0,  0};
s16 D_808022C8_chevilspirit[6] BT_DATA(4, overlays_ch_evilspirit, 0xF8) = {19,  1261, 13,
                                                                           243, 268,  0};
u8 D_808022D4_chevilspirit[4] BT_DATA(4, overlays_ch_evilspirit, 0x104) = {0xFF, 0, 0, 0xFF};
u8 D_808022D8_chevilspirit[4] BT_DATA(4, overlays_ch_evilspirit, 0x108) = {0xFF, 0xFF, 0, 0xFF};
u8 D_808022DC_chevilspirit[4] BT_DATA(4, overlays_ch_evilspirit, 0x10C) = {0xFF, 0xFF, 0xFF, 0xFF};
u16 D_808022E0_chevilspirit[2] BT_DATA(4, overlays_ch_evilspirit, 0x110) = {0x15F, 0};
u16 D_808022E4_chevilspirit[2] BT_DATA(4, overlays_ch_evilspirit, 0x114) = {0x15F, 0xAF};
s16 D_808022E8_chevilspirit[6] BT_DATA(4, overlays_ch_evilspirit, 0x118) = {19,  1260, 13,
                                                                            294, 320,  0};
s16 D_808022F4_chevilspirit[22] BT_DATA(4, overlays_ch_evilspirit, 0x124) = {
    21, 25, 153, 34, 40, 51, 15, 20, 22, 4096, 43, 51, 102, 44, 0, 70, 0, 0, 90, 0, 0, 0};
u32 D_80802320_chevilspirit[3] BT_DATA(4, overlays_ch_evilspirit, 0x150) = {0xFF, 0x60, 0x20};
u32 D_8080232C_chevilspirit[3] BT_DATA(4, overlays_ch_evilspirit, 0x15C) = {0xFF, 0x80, 0x20};
f32 D_80802338_chevilspirit[3][2] BT_DATA(4, overlays_ch_evilspirit,
                                          0x168) = {{0.0f, 0.0f}, {0.5f, 1.0f}, {1.0f, 0.0f}};
s16 D_80802350_chevilspirit[8] BT_DATA(4, overlays_ch_evilspirit, 0x180) = {19,  1262, 13, 243,
                                                                            268, 0,    0,  0};
