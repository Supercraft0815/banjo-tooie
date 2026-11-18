/* data_to_c.py: from asm/data/overlays/ch/uffy.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80108EE8();
void func_80107C2C();
void func_8010A73C();
void func_80108ED0();
s16 D_80802320_chchuffy[10] BT_DATA(4, overlays_ch_uffy, 0x0) = {19,    1217, 10,  153,  22,
                                                                 32000, 1,    500, 5000, 0};
s16 D_80802334_chchuffy[10] BT_DATA(4, overlays_ch_uffy, 0x14) = {19,    1217, 10,  102,  22,
                                                                  32000, 1,    500, 5000, 0};
s16 D_80802348_chchuffy[10] BT_DATA(4, overlays_ch_uffy, 0x28) = {19,    1217, 10,  102,  22,
                                                                  28000, 1,    500, 5000, 0};
s16 D_8080235C_chchuffy[12] BT_DATA(4, overlays_ch_uffy, 0x3C) = {19,    1185,  13, 128,  179,   25,
                                                                  18000, 22000, 1,  5000, 10000, 0};
s16 D_80802374_chchuffy[12] BT_DATA(4, overlays_ch_uffy, 0x54) = {19,    1185,  13, 128,  179,   25,
                                                                  18000, 22000, 1,  5000, 10000, 0};
s16 D_8080238C_chchuffy[10] BT_DATA(4, overlays_ch_uffy, 0x6C) = {19, 1256, 10,   204, 24,
                                                                  1,  500,  5000, 0,   0};
s16 D_808023A0_chchuffy[20] BT_DATA(4, overlays_ch_uffy, 0x80) = {
    19, 1255, 10, 243, 22, 32000, 1, 500, 5000, 0, 19, 1255, 10, 256, 22, 32000, 1, 500, 5000, 0};
s16 D_808023C8_chchuffy[10] BT_DATA(4, overlays_ch_uffy, 0xA8) = {19,    1217, 10,  102,  22,
                                                                  32000, 1,    500, 5000, 0};
s16 D_808023DC_chchuffy[8] BT_DATA(4, overlays_ch_uffy, 0xBC) = {518, 19, 1257, 7, 1, 500, 8000, 0};
ActorAnimationEntry D_808023EC_chchuffy[9] BT_DATA(4, overlays_ch_uffy, 0xCC) = {
    {0.0f, 0x0, 0x0},    {14.0f, 0x97, 0x44}, {14.0f, 0x97, 0x44},
    {14.0f, 0x97, 0x4a}, {14.0f, 0x99, 0x44}, {14.0f, 0x99, 0x244},
    {14.0f, 0x99, 0x44}, {14.0f, 0x99, 0x4a}, {14.0f, 0x9a, 0x4a}};
ActorData D_80802434_chchuffy[1] BT_DATA(4, overlays_ch_uffy, 0x114) = {
    {517,
     677,
     1705,
     1,
     (void *)D_808023EC_chchuffy,
     (void (*)(struct Actor *))func_808009CC_chchuffy,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808019A4_chchuffy,
     0,
     0,
     0,
     0,
     136,
     1124,
     (void (*)(struct Actor *))func_80801C78_chchuffy,
     (BtIntPtr)func_80108EE8,
     684,
     0,
     (void (*)(struct Actor *))func_80801B8C_chchuffy,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32640,
     2,
     (void (*)(struct Actor *, long, long))func_80800864_chchuffy,
     0}};
struct Entry D_8080247C_chchuffy[7] BT_DATA(4, overlays_ch_uffy, 0x15C) = {
    {{1261, 1641}, 2, 4}, {{1262, 1642}, 0, 2},   {{1267, 1740}, 14, 12}, {{1264, 1706}, 2, 0},
    {{1263, 1705}, 2, 0}, {{1266, 1724}, 15, 13}, {{1265, 1723}, 6, 1}};
u32 D_808024B4_chchuffy[7] BT_DATA(4, overlays_ch_uffy, 0x194) = {
    0x9500CB8, 0x964, 0x5400C68, 0xDAE0CC8, 0x68A, 0xAF60CC0, 0xAF60B74};
f32 D_808024D0_chchuffy[6] BT_DATA(4, overlays_ch_uffy, 0x1B0) = {0.01f, 0.08f, 0.15f,
                                                                  0.28f, 0.55f, -1.0f};
f32 D_808024E8_chchuffy[5] BT_DATA(4, overlays_ch_uffy, 0x1C8) = {0.045f, 0.115f, 0.215f, 0.415f,
                                                                  -1.0f};
f32 D_808024FC_chchuffy[14] BT_DATA(4, overlays_ch_uffy,
                                    0x1DC) = {0.01f, 0.16f, 0.21f, 0.24f, 0.26f, 0.28f, 0.31f,
                                              0.39f, 0.51f, 0.63f, 0.75f, 0.87f, 0.97f, -1.0f};
f32 D_80802534_chchuffy[13] BT_DATA(4, overlays_ch_uffy, 0x214) = {
    0.085f, 0.185f, 0.225f, 0.25f, 0.27f, 0.295f, 0.35f, 0.45f, 0.57f, 0.69f, 0.81f, 0.92f, -1.0f};
ChuffyPair D_80802568_chchuffy BT_DATA(4, overlays_ch_uffy, 0x248) = {{1500.0f, 2500.0f}};
ChuffyVector D_80802570_chchuffy BT_DATA(4, overlays_ch_uffy,
                                         0x250) = {{-700.0f, 1000.0f, -150.0f}};
ChuffyIntVector D_8080257C_chchuffy BT_DATA(4, overlays_ch_uffy, 0x25C) = {{0, 255, 0}};
ChuffyVector D_80802588_chchuffy BT_DATA(4, overlays_ch_uffy, 0x268) = {{0.0f, 0.0f, 0.0f}};
ChuffyVector D_80802594_chchuffy BT_DATA(4, overlays_ch_uffy, 0x274) = {{0.0f, 0.0f, 0.0f}};
s16 D_808025A0_chchuffy[34] BT_DATA(4, overlays_ch_uffy, 0x280) = {
    29,  2525, 25, 0,  7,  10, -25, -50, -5,   -5,   25, 5,  44,  -55, 300, -25,   -15,
    600, 25,   27, 10, 20, 34, 128, 384, 1024, 1280, 42, 12, 192, 384, 640, 25602, 0};
s16 D_808025E4_chchuffy[38] BT_DATA(4, overlays_ch_uffy, 0x2C4) = {
    29, 2525, 25, 0,  7,   10,  -5,   -5,   80, 5,  5,   0,   44,  -60, 200, -60, 60,    400, 60,
    27, 5,    10, 34, 128, 512, 1024, 1280, 42, 12, 192, 384, 640, 21,  0,   217, 25602, 0,   0};
s16 D_80802630_chchuffy[38] BT_DATA(4, overlays_ch_uffy, 0x310) = {
    29, 2525, 25, 0,  7,   10,  -5,   -5,   80, 5,  5,   0,   44,  -60, 200, -60, 60,    400, 60,
    27, 5,    10, 34, 128, 768, 1536, 2048, 42, 12, 192, 384, 640, 21,  0,   217, 25602, 0,   0};
s16 D_8080267C_chchuffy[10] BT_DATA(4, overlays_ch_uffy, 0x35C) = {518, 19, 1244, 7,    22,
                                                                   0,   1,  500,  5000, 0};
s16 D_80802690_chchuffy[10] BT_DATA(4, overlays_ch_uffy, 0x370) = {19,  1216, 22,  32000, 10,
                                                                   230, 1,    500, 5000,  0};
s32 D_808026A4_chchuffy[2] BT_DATA(4, overlays_ch_uffy, 0x384) = {1275, -1};
f32 D_808026AC_chchuffy[3] BT_DATA(4, overlays_ch_uffy, 0x38C) = {-750.0f, 100.0f, -858.0f};
f32 D_808026B8_chchuffy[3] BT_DATA(4, overlays_ch_uffy, 0x398) = {-750.0f, 220.0f, -858.0f};
f32 D_808026C4_chchuffy[3] BT_DATA(4, overlays_ch_uffy, 0x3A4) = {-870.0f, 324.0f, -1035.0f};
f32 D_808026D0_chchuffy[3] BT_DATA(4, overlays_ch_uffy, 0x3B0) = {-650.0f, 770.0f, -835.0f};
f32 D_808026DC_chchuffy[3] BT_DATA(4, overlays_ch_uffy, 0x3BC) = {115.0f, 303.0f, -1292.0f};
f32 D_808026E8_chchuffy[3] BT_DATA(4, overlays_ch_uffy, 0x3C8) = {465.0f, 760.0f, -851.0f};
ActorData D_808026F4_chchuffy[1] BT_DATA(4, overlays_ch_uffy, 0x3D4) = {
    {731,
     790,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_80802164_chchuffy,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8010A73C,
     0,
     0,
     0,
     0,
     0,
     3076,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80801F84_chchuffy,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     (void (*)(struct Actor *, long, long))func_80801FA4_chchuffy,
     0}};
