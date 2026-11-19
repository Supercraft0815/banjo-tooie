/* data_to_c.py: from asm/data/overlays/ch/floaty.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_801018A4();
void func_80108ED0();
void func_80107C2C();
BtFnWord D_80800E00_chfloaty[2] BT_DATA(4, overlays_ch_floaty, 0x0) = {
    (BtFnWord)func_8080000C_chfloaty, (BtFnWord)func_80800020_chfloaty};
struct {
    ActorAnimationEntry animation[7];
    s16 commands[34];
} D_80800E08_chfloaty BT_DATA(4, overlays_ch_floaty, 0x8) = {
    {{0.0f, 0x0, 0x0},
     {5.5f, 0x1d4, 0x9},
     {0.959999979f, 0x1d5, 0x4a},
     {1.79999995f, 0x426, 0x9},
     {1.79999995f, 0x426, 0x9},
     {1.79999995f, 0x426, 0x9},
     {1.79999995f, 0x426, 0x9}},
    {29, 2534, 27,  200, 350, 22, 4096, 44, 0,   0,   0,  0,  100, 0,  14,  0,   70,
     39, 0,    100, 0,   200, 34, 128,  25, 102, 153, 21, 15, 204, 43, 256, 256, 0}};
f32 D_80800E84_chfloaty[3][3] BT_DATA(4, overlays_ch_floaty, 0x84) = {
    {450.0f, 828.0f, -750.0f}, {-4750.0f, 5538.0f, -3230.0f}, {3800.0f, 7000.0f, 2240.0f}};
s16 D_80800EA8_chfloaty[36] BT_DATA(4, overlays_ch_floaty, 0xA8) = {
    29, 2534, 27, -700, 300, 45, 100, 200, 13,  30,  22, 4098, 39, 0, 100, 0,   200, 34,
    0,  0,    76, 153,  21,  51, 179, 43,  192, 256, 4,  153,  7,  3, 49,  -10, -10, 0};
ActorData D_80800EF0_chfloaty[1] BT_DATA(4, overlays_ch_floaty, 0xF0) = {
    {344,
     1158,
     2340,
     1,
     D_80800E08_chfloaty.animation,
     (void (*)(struct Actor *))func_80800118_chfloaty,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     131072000,
     1065353216,
     0,
     0,
     128,
     292,
     (void (*)(struct Actor *))func_80800C4C_chfloaty,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -31232,
     16384,
     (void (*)(struct Actor *, long, long))func_8080090C_chfloaty,
     0}};
