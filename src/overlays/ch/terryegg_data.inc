/* data_to_c.py: from asm/data/overlays/ch/terryegg.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_801018A4();
void func_80107C2C();

void func_80101870();
void func_80108ED0();
TerryEggTaxi D_80801260_chterryegg BT_DATA(4, overlays_ch_terryegg, 0x0) = {
    func_80800E0C_chterryegg, func_80800D20_chterryegg, {0x14, 0x10, 0xD, 0x4E}};
s16 D_8080126C_chterryegg[10] BT_DATA(4, overlays_ch_terryegg, 0xC) = {19, 1378, 13,   243, 268,
                                                                       1,  400,  1500, 0,   0};
ActorAnimationEntry D_80801280_chterryegg[8] BT_DATA(4, overlays_ch_terryegg, 0x20) = {
    {0.0f, 0x0, 0x0},   {0.0f, 0x0, 0x0},   {0.0f, 0x0, 0x0},           {0.0f, 0x0, 0x0},
    {5.5f, 0x1d4, 0x1}, {5.5f, 0x1d4, 0x1}, {0.959999979f, 0x1d5, 0x2}, {0.0f, 0x0, 0x0}};
ActorAnimationEntry D_808012C0_chterryegg[13] BT_DATA(4, overlays_ch_terryegg, 0x60) = {
    {0.0f, 0x0, 0x0},          {0.0f, 0x0, 0x0},          {1.5f, 0x1f9, 0x2},
    {3.93000007f, 0x1fb, 0x1}, {8.60000038f, 0x1fa, 0x1}, {0.400000006f, 0x168, 0x1},
    {8.60000038f, 0x1fa, 0x1}, {8.60000038f, 0x1fa, 0x1}, {8.60000038f, 0x1fa, 0x1},
    {3.93000007f, 0x1fb, 0x1}, {8.60000038f, 0x1fa, 0x1}, {3.93000007f, 0x1fb, 0x1},
    {8.60000038f, 0x1fa, 0x1}};
ActorData D_80801328_chterryegg[1] BT_DATA(4, overlays_ch_terryegg, 0xC8) = {
    {786,
     938,
     1794,
     1,
     D_80801280_chterryegg,
     (void (*)(struct Actor *))func_808000A8_chterryegg,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     65536000,
     1061997773,
     0,
     1981,
     16384,
     2056,
     0,
     0,
     0,
     2064,
     (void (*)(struct Actor *))func_80800030_chterryegg,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32255,
     9218,
     (void (*)(struct Actor *, long, long))func_8080023C_chterryegg,
     0}};
ActorData D_80801370_chterryegg[1] BT_DATA(4, overlays_ch_terryegg, 0x110) = {
    {158,
     982,
     1795,
     1,
     D_808012C0_chterryegg,
     (void (*)(struct Actor *))func_808005C4_chterryegg,
     (void (*)(struct Actor *))func_808009B4_chterryegg,
     (void (*)(long, long))func_80101870,
     131072000,
     1053609165,
     0,
     0,
     16388,
     260,
     0,
     (BtIntPtr)func_80108ED0,
     4,
     0,
     (void (*)(struct Actor *))func_8080057C_chterryegg,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     16,
     (void (*)(struct Actor *, long, long))func_80800A2C_chterryegg,
     0}};
ActorData D_808013B8_chterryegg[1] BT_DATA(4, overlays_ch_terryegg, 0x158) = {
    {158,
     983,
     1795,
     11,
     D_808012C0_chterryegg,
     (void (*)(struct Actor *))func_80800C48_chterryegg,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     131072000,
     1053609165,
     0,
     0,
     20608,
     8448,
     0,
     0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32256,
     9234,
     (void (*)(struct Actor *, long, long))func_80800C70_chterryegg,
     0}};
s16 D_80801400_chterryegg[8] BT_DATA(4, overlays_ch_terryegg, 0x1A0) = {19,  1023, 13,    294,
                                                                        320, 22,   12000, 0};
s16 D_80801410_chterryegg[10] BT_DATA(4, overlays_ch_terryegg, 0x1B0) = {19, 1379, 13,   243,   268,
                                                                         1,  400,  1500, 23045, 0};
s16 D_80801424_chterryegg[10] BT_DATA(4, overlays_ch_terryegg, 0x1C4) = {19, 1379, 13,   243, 268,
                                                                         1,  400,  1500, 0,   0};
f32 D_80801438_chterryegg[6] BT_DATA(4, overlays_ch_terryegg, 0x1D8) = {0.1f, 0.15f, 0.21f,
                                                                        0.6f, 0.96f, -1.0f};
s16 D_80801450_chterryegg[6] BT_DATA(4, overlays_ch_terryegg, 0x1F0) = {19, 1377, 2, 24, 0, 0};
