/* data_to_c.py: from asm/data/overlays/ch/bottles/family.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_801018A4();
void func_80107C2C();

ActorAnimationEntry D_80800D50_chbottlesfamily[6] BT_DATA(4, overlays_ch_bottles_family, 0x0) = {
    {0.0f, 0x0, 0x0}, {9.10000038f, 0x445, 0x1}, {9.10000038f, 0x445, 0x1},
    {0.0f, 0x0, 0x0}, {0.0f, 0x0, 0x0},          {9.10000038f, 0x445, 0x1}};
ActorAnimationEntry D_80800D80_chbottlesfamily[6] BT_DATA(4, overlays_ch_bottles_family, 0x30) = {
    {0.0f, 0x0, 0x0},           {6.5999999f, 0x4b1, 0x0},   {6.5999999f, 0x4b1, 0x0},
    {0.800000012f, 0x4b0, 0x0}, {0.800000012f, 0x4b0, 0x0}, {6.5999999f, 0x4b1, 0x0}};
ActorAnimationEntry D_80800DB0_chbottlesfamily[6] BT_DATA(4, overlays_ch_bottles_family, 0x60) = {
    {0.0f, 0x0, 0x0}, {6.5999999f, 0x4b7, 0x0}, {6.5999999f, 0x4b7, 0x0},
    {0.0f, 0x0, 0x0}, {0.0f, 0x0, 0x0},         {6.5999999f, 0x4b7, 0x0}};
ActorData D_80800DE0_chbottlesfamily[1] BT_DATA(4, overlays_ch_bottles_family, 0x90) = {
    {344,
     1083,
     2315,
     1,
     (void *)D_80800D50_chbottlesfamily,
     (void (*)(struct Actor *))func_80800080_chbottlesfamily,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     0,
     1065353216,
     0,
     0,
     0,
     296,
     (void (*)(struct Actor *))func_8080086C_chbottlesfamily,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800024_chbottlesfamily,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1026,
     (void (*)(struct Actor *, long, long))func_80800720_chbottlesfamily,
     0}};
ActorData D_80800E28_chbottlesfamily[1] BT_DATA(4, overlays_ch_bottles_family, 0xD8) = {
    {344,
     1084,
     2329,
     1,
     (void *)D_80800D80_chbottlesfamily,
     (void (*)(struct Actor *))func_808001B0_chbottlesfamily,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     0,
     1065353216,
     0,
     0,
     4,
     289,
     (void (*)(struct Actor *))func_8080086C_chbottlesfamily,
     0,
     16,
     0,
     (void (*)(struct Actor *))func_80800124_chbottlesfamily,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1042,
     (void (*)(struct Actor *, long, long))func_8080046C_chbottlesfamily,
     0}};
ActorData D_80800E70_chbottlesfamily[1] BT_DATA(4, overlays_ch_bottles_family, 0x120) = {
    {344,
     1085,
     2330,
     1,
     (void *)D_80800DB0_chbottlesfamily,
     (void (*)(struct Actor *))func_80800630_chbottlesfamily,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     0,
     1065353216,
     0,
     0,
     0,
     288,
     (void (*)(struct Actor *))func_8080086C_chbottlesfamily,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800600_chbottlesfamily,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1026,
     (void (*)(struct Actor *, long, long))func_80800720_chbottlesfamily,
     0}};
s16 D_80800EB8_chbottlesfamily[10] BT_DATA(4, overlays_ch_bottles_family,
                                           0x168) = {19, 1345, 1, 300, 1000, 13, 243, 268, 0, 0};
f32 D_80800ECC_chbottlesfamily[4] BT_DATA(4, overlays_ch_bottles_family, 0x17C) = {0.43f, 0.62f,
                                                                                   0.68f, -1.0f};
subaddiedialog_UnkStruct0 D_80800EDC_chbottlesfamily BT_DATA(4, overlays_ch_bottles_family,
                                                             0x18C) = {
    0x1A7, 0x15E, 0x14FF, 0x1500, 0x201, 0x1208, 0, 175, 0, 0xC, 6, 0x3C, 2};
s16 D_80800EF8_chbottlesfamily[6] BT_DATA(4, overlays_ch_bottles_family, 0x1A8) = {19,  1317, 13,
                                                                                   217, 243,  0};
subaddiedialog_UnkStruct0 D_80800F04_chbottlesfamily BT_DATA(4, overlays_ch_bottles_family,
                                                             0x1B4) = {
    0x1A8, 0x15E, 0x1501, 0x1502, 0x201, 0x1208, 0, 176, 0, 0xC, 2, 0x3C, 2};
s16 D_80800F20_chbottlesfamily[6] BT_DATA(4, overlays_ch_bottles_family, 0x1D0) = {19,  1082, 13,
                                                                                   294, 320,  0};
subaddiedialog_UnkStruct0 D_80800F2C_chbottlesfamily BT_DATA(4, overlays_ch_bottles_family,
                                                             0x1DC) = {
    0x1A9, 0x15E, 0x1503, 0x1504, 0x201, 0x1208, 0, 177, 0, 0xC, 6, 0x3C, 2};
s16 D_80800F48_chbottlesfamily[8] BT_DATA(4, overlays_ch_bottles_family,
                                          0x1F8) = {774, 19, 1661, 13, 243, 268, 17, 0};
s16 D_80800F58_chbottlesfamily[8] BT_DATA(4, overlays_ch_bottles_family,
                                          0x208) = {19, 1482, 13, 243, 268, 22, 25000, 0};
f32 D_80800F68_chbottlesfamily[4] BT_DATA(4, overlays_ch_bottles_family, 0x218) = {0.82f, 0.87f,
                                                                                   0.9f, -1.0f};
f32 D_80800F78_chbottlesfamily[4] BT_DATA(4, overlays_ch_bottles_family, 0x228) = {0.49f, 0.58f,
                                                                                   0.74f, -1.0f};
f32 D_80800F88_chbottlesfamily[4] BT_DATA(4, overlays_ch_bottles_family, 0x238) = {90.0f, 100.0f,
                                                                                   100.0f, 50.0f};
f32 D_80800F98_chbottlesfamily[4] BT_DATA(4, overlays_ch_bottles_family, 0x248) = {120.0f, 120.0f,
                                                                                   80.0f, 50.0f};
f32 D_80800FA8_chbottlesfamily[4] BT_DATA(4, overlays_ch_bottles_family, 0x258) = {140.0f, 110.0f,
                                                                                   80.0f, 50.0f};
u8 D_80800FA8_chbottlesfamily__gap[8] BT_DATA(4, overlays_ch_bottles_family, 0x268) = {0};
