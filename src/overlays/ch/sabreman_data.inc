/* data_to_c.py: from asm/data/overlays/ch/sabreman.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80108ED0();
void func_80107C2C();

BtFnWord D_80801BE0_chsabreman[2] BT_DATA(4, overlays_ch_sabreman, 0x0) = {
    (BtFnWord)func_80800F74_chsabreman, (BtFnWord)func_80800F04_chsabreman};
f32 D_80801BE8_chsabreman[4] BT_DATA(4, overlays_ch_sabreman, 0x8) = {260.0f, 245.0f, 245.0f,
                                                                      180.0f};
subaddiedialog_UnkStruct1 D_80801BF8_chsabreman[5] BT_DATA(4, overlays_ch_sabreman,
                                                           0x18) = {{1, 4722, 2, 0},
                                                                    {0x200, 4722, 2, 0},
                                                                    {0x400, 4722, 2, 0},
                                                                    {0x1000, 4722, 2, 0},
                                                                    {0xFFFEDFFF, 4619, 3, 0}};
subaddiedialog_UnkStruct1 D_80801C20_chsabreman[4] BT_DATA(4, overlays_ch_sabreman, 0x40) = {
    {0x401, 4724, 2, 0}, {0x200, 4826, 2, 0}, {0x1000, 4827, 2, 0}, {0xFFFEDFFF, 4619, 3, 0}};
ActorAnimationEntry D_80801C40_chsabreman[26] BT_DATA(4, overlays_ch_sabreman, 0x60) = {
    {0.0f, 0x0, 0x0},          {5.36000013f, 0x2f7, 0x20}, {5.36000013f, 0x2f7, 0x20},
    {5.36000013f, 0x2f7, 0x2}, {1.01999998f, 0x2f8, 0x2},  {5.6500001f, 0x2f9, 0x1},
    {5.6500001f, 0x2f9, 0x1},  {1.20000005f, 0x2fa, 0x2},  {7.80000019f, 0x2fc, 0x1},
    {2.67000008f, 0x2fb, 0x2}, {7.80000019f, 0x2fc, 0x1},  {7.80000019f, 0x2fc, 0x1},
    {7.80000019f, 0x2fc, 0x1}, {7.80000019f, 0x2fc, 0x1},  {7.80000019f, 0x2fc, 0x1},
    {7.80000019f, 0x2fc, 0x1}, {7.80000019f, 0x2fc, 0x1},  {7.80000019f, 0x2fc, 0x1},
    {7.80000019f, 0x2fc, 0x1}, {1.39999998f, 0x2fd, 0x1},  {1.39999998f, 0x2fd, 0x1},
    {1.39999998f, 0x2fd, 0x1}, {0.699999988f, 0x2fe, 0x2}, {1.92999995f, 0x2ff, 0x1},
    {1.92999995f, 0x2ff, 0x1}, {7.80000019f, 0x2fc, 0x1}};
ActorAnimationEntry D_80801D10_chsabreman[4] BT_DATA(4, overlays_ch_sabreman,
                                                     0x130) = {{0.0f, 0x0, 0x0},
                                                               {5.36000013f, 0x2ec, 0x20},
                                                               {5.36000013f, 0x2ec, 0x2},
                                                               {5.36000013f, 0x2ec, 0x84}};
ActorData D_80801D30_chsabreman[1] BT_DATA(4, overlays_ch_sabreman, 0x150) = {
    {176,
     838,
     2031,
     1,
     (void *)D_80801C40_chsabreman,
     (void (*)(struct Actor *))func_80800218_chsabreman,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80800CDC_chsabreman,
     196608000,
     1073741824,
     0,
     0,
     132,
     356,
     0,
     (BtIntPtr)func_80108ED0,
     2084,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -31744,
     16,
     (void (*)(struct Actor *, long, long))func_808008C8_chsabreman,
     0}};
ActorData D_80801D78_chsabreman[1] BT_DATA(4, overlays_ch_sabreman, 0x198) = {
    {176,
     839,
     2031,
     23,
     (void *)D_80801C40_chsabreman,
     (void (*)(struct Actor *))func_808015D4_chsabreman,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80801620_chsabreman,
     196608000,
     0,
     0,
     2033,
     132,
     32,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080158C_chsabreman,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -31744,
     9234,
     0,
     0}};
ActorData D_80801DC0_chsabreman[1] BT_DATA(4, overlays_ch_sabreman, 0x1E0) = {
    {344,
     510,
     2029,
     1,
     (void *)D_80801D10_chsabreman,
     (void (*)(struct Actor *))func_808018DC_chsabreman,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8080193C_chsabreman,
     0,
     0,
     0,
     0,
     0,
     2060,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80801864_chsabreman,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     10754,
     (void (*)(struct Actor *, long, long))func_808019A4_chsabreman,
     0}};
subaddiedialog_UnkStruct2 D_80801E08_chsabreman BT_DATA(4, overlays_ch_sabreman, 0x228) = {
    0, 0, 0x12C, 170, 0, 0xE, 6, 0x3C, 0};
AudioTimes D_80801E18_chsabreman BT_DATA(4, overlays_ch_sabreman, 0x238) = {{0.24f, 0.28f, -1.0f}};
AudioTimes D_80801E24_chsabreman BT_DATA(4, overlays_ch_sabreman, 0x244) = {{0.1f, 0.6f, -1.0f}};
s16 D_80801E30_chsabreman[8] BT_DATA(4, overlays_ch_sabreman, 0x250) = {19,  1028, 13,    243,
                                                                        268, 22,   10000, 0};
s16 D_80801E40_chsabreman[8] BT_DATA(4, overlays_ch_sabreman, 0x260) = {19,  1023, 13,    243,
                                                                        268, 22,   18000, 0};
s16 D_80801E50_chsabreman[8] BT_DATA(4, overlays_ch_sabreman, 0x270) = {19,  1387, 13,    217,
                                                                        243, 22,   18000, 0};
s16 D_80801E60_chsabreman[22] BT_DATA(4, overlays_ch_sabreman, 0x280) = {
    1040, 29, 2525, 34, 51, 64, 76, 89, 21, 51, 179, 45, 30, 40, 42, 12, 51, 256, 384, 15, 0, 0};
s16 D_80801E8C_chsabreman[8] BT_DATA(4, overlays_ch_sabreman, 0x2AC) = {19,  1482, 13, 243,
                                                                        268, 24,   0,  0};
f32 D_80801E9C_chsabreman[10] BT_DATA(4, overlays_ch_sabreman, 0x2BC) = {
    0.25999999f,  0.289999992f, 0.319999993f, 0.349999994f, 0.5f,
    0.529999971f, 0.560000002f, 0.589999974f, 0.620000005f, -1.0f};
s16 D_80801EC4_chsabreman[8] BT_DATA(4, overlays_ch_sabreman, 0x2E4) = {19,  1477, 24, 13,
                                                                        243, 268,  0,  0};
s16 D_80801ED4_chsabreman[20] BT_DATA(4, overlays_ch_sabreman, 0x2F4) = {
    29, 2525, 34, 76, 89, 102, 115, 21, 51, 179, 42, 12, 51, 256, 384, 14, 5, 15, 0, 0};
s16 D_80801EFC_chsabreman[6] BT_DATA(4, overlays_ch_sabreman, 0x31C) = {19, 1186, 22, 14000, 0, 0};
s16 D_80801F08_chsabreman[6] BT_DATA(4, overlays_ch_sabreman, 0x328) = {19, 1047, 22, 14000, 0, 0};
s16 D_80801F14_chsabreman[12] BT_DATA(4, overlays_ch_sabreman, 0x334) = {
    19, 1480, 13, 243, 268, 22, 14000, 1, 60, 900, 0, 0};
s16 D_80801F2C_chsabreman[12] BT_DATA(4, overlays_ch_sabreman, 0x34C) = {
    19, 1481, 13, 243, 268, 22, 14000, 1, 60, 900, 0, 0};
s16 D_80801F44_chsabreman[12] BT_DATA(4, overlays_ch_sabreman, 0x364) = {
    19, 1097, 13, 217, 243, 22, 12000, 1, 60, 900, 0, 0};
f32 D_80801F5C_chsabreman[4] BT_DATA(4, overlays_ch_sabreman, 0x37C) = {0.300000012f, 0.360000014f,
                                                                        0.419999987f, -1.0f};
s16 D_80801F6C_chsabreman[6] BT_DATA(4, overlays_ch_sabreman, 0x38C) = {19, 1047, 22, 14000, 0, 0};
s16 D_80801F78_chsabreman[8] BT_DATA(4, overlays_ch_sabreman, 0x398) = {774, 1,  60,    900,
                                                                        7,   22, 14000, 0};
s16 D_80801F88_chsabreman[8] BT_DATA(4, overlays_ch_sabreman, 0x3A8) = {19,  1478, 13, 243,
                                                                        268, 17,   0,  0};
s16 D_80801F98_chsabreman[12] BT_DATA(4, overlays_ch_sabreman, 0x3B8) = {19, 1479, 13, 243, 268, 17,
                                                                         0,  0,    0,  0,   0,   0};
