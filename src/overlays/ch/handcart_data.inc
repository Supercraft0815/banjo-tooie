/* data_to_c.py: from asm/data/overlays/ch/handcart.data.s */
#include "core2/actor_animation_entry.h"

#ifndef BT_NATIVE
void func_80107C2C();
#endif

s16 D_808046C0_chhandcart[10] BT_DATA(4, overlays_ch_handcart, 0x0) = {19, 1023,  13,    204, 230,
                                                                       25, 16000, 18000, 0,   0};
s16 D_808046D4_chhandcart[10] BT_DATA(4, overlays_ch_handcart, 0x14) = {19, 1632,  13,    230, 281,
                                                                        25, 16000, 18000, 0,   0};
s16 D_808046E8_chhandcart[6] BT_DATA(4, overlays_ch_handcart, 0x28) = {19, 1028, 22, 20000, 0, 0};
s16 D_808046F4_chhandcart[8] BT_DATA(4, overlays_ch_handcart, 0x34) = {19,  1217, 13,    243,
                                                                       268, 22,   28000, 0};
s16 D_80804704_chhandcart[8] BT_DATA(4, overlays_ch_handcart, 0x44) = {19,  1078, 13, 243,
                                                                       268, 24,   0,  0};
HandcartSounds D_80804714_chhandcart BT_DATA(4, overlays_ch_handcart, 0x54) = {
    {19, 1668, 13, 217, 243, 22, 15000, 0},
    {(const char *)R_808043C0_chhandcart, (const char *)R_808043C8_chhandcart,
     (const char *)R_808043D0_chhandcart}};
ActorAnimationEntry D_80804730_chhandcart[27] BT_DATA(4, overlays_ch_handcart,
                                                      0x70) = {{0.0f, 0x0, 0x0},
                                                               {6.0f, 0x80, 0x1},
                                                               {6.0f, 0x80, 0x1},
                                                               {6.0f, 0x80, 0x1},
                                                               {6.0f, 0x80, 0x1},
                                                               {0.400000006f, 0x7d, 0x1},
                                                               {0.400000006f, 0x7d, 0x1},
                                                               {0.400000006f, 0x7d, 0x1},
                                                               {0.400000006f, 0x7d, 0x1},
                                                               {1.0f, 0x89, 0x1},
                                                               {2.0f, 0x8a, 0x42},
                                                               {1.0f, 0x85, 0x1},
                                                               {1.0f, 0x89, 0x1},
                                                               {2.0f, 0x8a, 0x42},
                                                               {1.0f, 0x85, 0x1},
                                                               {1.0f, 0x85, 0x1},
                                                               {0.400000006f, 0x7d, 0x1},
                                                               {1.0f, 0x85, 0x1},
                                                               {0.400000006f, 0x7d, 0x201},
                                                               {0.400000006f, 0x7d, 0x1},
                                                               {0.400000006f, 0x7d, 0x1},
                                                               {1.0f, 0x89, 0x1},
                                                               {2.0f, 0x8a, 0x42},
                                                               {6.0f, 0x80, 0x1},
                                                               {4.0f, 0x7e, 0x0},
                                                               {4.0f, 0x7e, 0x0},
                                                               {0.400000006f, 0x7d, 0x201}};
ActorAnimationEntry D_80804808_chhandcart[24] BT_DATA(4, overlays_ch_handcart, 0x148) = {
    {0.0f, 0x0, 0x0},   {1.0f, 0x84, 0x44}, {1.0f, 0x84, 0x44}, {1.0f, 0x84, 0x44},
    {1.0f, 0x84, 0x44}, {1.0f, 0x84, 0x44}, {1.0f, 0x84, 0x1},  {1.0f, 0x84, 0x4},
    {1.0f, 0x84, 0x4},  {1.0f, 0x84, 0x1},  {1.0f, 0x84, 0x1},  {1.0f, 0x84, 0x1},
    {1.0f, 0x84, 0x4},  {1.0f, 0x84, 0x4},  {1.0f, 0x84, 0x4},  {1.0f, 0x84, 0x4},
    {1.0f, 0x84, 0x4},  {1.0f, 0x84, 0x4},  {1.0f, 0x84, 0x4},  {1.0f, 0x84, 0x44},
    {1.0f, 0x84, 0x44}, {1.0f, 0x84, 0x44}, {1.0f, 0x84, 0x44}, {1.0f, 0x84, 0x44}};
unk80804B84 D_808048C8_chhandcart[9] BT_DATA(4, overlays_ch_handcart, 0x208) = {
    {{15.0f, 40.0f, 0.0f, 1200.0f}, 0, 0},     {{15.0f, 25.0f, 0.0f, 1000.0f}, 330, 0},
    {{15.0f, 25.0f, 0.0f, 1000.0f}, 380, 0},   {{25.0f, -160.0f, 0.0f, 1200.0f}, 510, 0},
    {{25.0f, -160.0f, 0.0f, 1200.0f}, 600, 0}, {{10.0f, 175.0f, 0.0f, 450.0f}, 670, 0},
    {{10.0f, 175.0f, 0.0f, 450.0f}, 850, 0},   {{15.0f, 25.0f, 0.0f, 750.0f}, 900, 0},
    {{15.0f, 25.0f, 0.0f, 750.0f}, 1000, 0}};
unk80804B84 D_8080497C_chhandcart[8] BT_DATA(4, overlays_ch_handcart, 0x2BC) = {
    {{15.0f, 205.0f, 0.0f, 500.0f}, 0, 0},   {{15.0f, 205.0f, 0.0f, 500.0f}, 330, 0},
    {{15.0f, 205.0f, 0.0f, 500.0f}, 380, 0}, {{15.0f, 205.0f, 0.0f, 500.0f}, 440, 0},
    {{15.0f, 205.0f, 0.0f, 500.0f}, 660, 0}, {{15.0f, 205.0f, 0.0f, 500.0f}, 850, 0},
    {{15.0f, 205.0f, 0.0f, 500.0f}, 900, 0}, {{15.0f, 205.0f, 0.0f, 500.0f}, 1000, 0}};
unk80804B84 D_80804A1C_chhandcart[10] BT_DATA(4, overlays_ch_handcart, 0x35C) = {
    {{15.0f, 0.0f, 0.0f, 750.0f}, 0, 0},      {{20.0f, 0.0f, 0.0f, 750.0f}, 230, 0},
    {{15.0f, 0.0f, 0.0f, 500.0f}, 380, 0},    {{15.0f, 30.0f, 0.0f, 1000.0f}, 410, 0},
    {{15.0f, 30.0f, 0.0f, 1000.0f}, 490, 0},  {{10.0f, -160.0f, 0.0f, 900.0f}, 610, 0},
    {{10.0f, -160.0f, 0.0f, 900.0f}, 800, 0}, {{15.0f, -60.0f, 0.0f, 1000.0f}, 850, 0},
    {{15.0f, -60.0f, 0.0f, 1000.0f}, 900, 0}, {{15.0f, -60.0f, 0.0f, 1000.0f}, 1000, 0}};
unk80804B84 D_80804AE4_chhandcart[8] BT_DATA(4, overlays_ch_handcart, 0x424) = {
    {{15.0f, -25.0f, 0.0f, 500.0f}, 0, 0},   {{15.0f, -25.0f, 0.0f, 500.0f}, 330, 0},
    {{15.0f, -25.0f, 0.0f, 500.0f}, 380, 0}, {{15.0f, -25.0f, 0.0f, 500.0f}, 440, 0},
    {{15.0f, -25.0f, 0.0f, 500.0f}, 660, 0}, {{15.0f, -25.0f, 0.0f, 500.0f}, 850, 0},
    {{15.0f, -25.0f, 0.0f, 500.0f}, 900, 0}, {{15.0f, -25.0f, 0.0f, 500.0f}, 1000, 0}};
unk80804B84 *D_80804B84_chhandcart[4] BT_DATA(4, overlays_ch_handcart, 0x4C4) = {
    D_808048C8_chhandcart, D_8080497C_chhandcart, D_80804A1C_chhandcart, D_80804AE4_chhandcart};
s32 D_80804B94_chhandcart[4] BT_DATA(4, overlays_ch_handcart, 0x4D4) = {9, 8, 10, 8};
unk80804D84 D_80804BA4_chhandcart[15] BT_DATA(4, overlays_ch_handcart, 0x4E4) = {
    {0.119999997f, 0.0f, 0.0f, 2, 12}, {0.180000007f, 0.0f, 0.0f, 2, 2},
    {0.25f, 0.0f, 0.0f, 1, 0},         {0.300000012f, 0.0f, 0.0f, 2, 11},
    {0.379999995f, 0.0f, 0.0f, 2, 3},  {0.430000007f, 0.0f, 0.0f, 2, 14},
    {0.469999999f, 0.0f, 0.0f, 2, 15}, {0.524999976f, 0.0f, 0.0f, 1, 0},
    {0.560000002f, 0.0f, 0.0f, 2, 5},  {0.680000007f, 0.0f, 0.0f, 1, 0},
    {0.75999999f, 0.0f, 0.0f, 2, 6},   {0.790000021f, 0.0f, 0.0f, 2, 7},
    {0.819999993f, 0.0f, 0.0f, 2, 8},  {0.839999974f, 0.0f, 0.0f, 2, 9},
    {0.899999976f, 0.0f, 0.0f, 2, 10}};
unk80804D84 D_80804C94_chhandcart[15] BT_DATA(4, overlays_ch_handcart, 0x5D4) = {
    {0.150000006f, 0.0f, 0.0f, 2, 2}, {0.180000007f, 0.0f, 0.0f, 2, 3},
    {0.209999993f, 0.0f, 0.0f, 2, 4}, {0.239999995f, 0.0f, 0.0f, 1, 0},
    {0.300000012f, 0.0f, 0.0f, 2, 5}, {0.349999994f, 0.0f, 0.0f, 2, 6},
    {0.389999986f, 0.0f, 0.0f, 2, 7}, {0.419999987f, 0.0f, 0.0f, 1, 0},
    {0.479999989f, 0.0f, 0.0f, 2, 8}, {0.560000002f, 0.0f, 0.0f, 2, 9},
    {0.620000005f, 0.0f, 0.0f, 1, 0}, {0.699999988f, 0.0f, 0.0f, 2, 10},
    {0.75f, 0.0f, 0.0f, 2, 11},       {0.790000021f, 0.0f, 0.0f, 2, 12},
    {0.860000014f, 0.0f, 0.0f, 1, 0}};
unk80804D84 *(D_80804D84_chhandcart[4])BT_DATA(4, overlays_ch_handcart, 0x6C4) = {
    D_80804BA4_chhandcart, 0, D_80804C94_chhandcart, 0};
s32 D_80804D94_chhandcart[4] BT_DATA(4, overlays_ch_handcart, 0x6D4) = {15, 0, 15, 0};
s16 D_80804DA4_chhandcart[10] BT_DATA(4, overlays_ch_handcart, 0x6E4) = {518, 19,  1215, 22, 18000,
                                                                         1,   500, 2500, 0,  0};
f32 D_80804DB8_chhandcart[3] BT_DATA(4, overlays_ch_handcart, 0x6F8) = {0.0f, 0.0f, 0.0f};
ActorData D_80804DC4_chhandcart BT_DATA(4, overlays_ch_handcart, 0x704) = {
    344,
    906,
    1660,
    2,
    D_80804808_chhandcart,
    (void (*)(struct Actor *))func_80801D50_chhandcart,
    (void (*)(struct Actor *))func_80801D50_chhandcart,
    (void (*)(long, long))func_8080256C_chhandcart,
    98304000,
    0,
    0,
    0,
    8,
    100,
    (void (*)(struct Actor *))func_80801FF4_chhandcart,
    0,
    2368,
    0,
    (void (*)(struct Actor *))func_80802120_chhandcart,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    2,
    (void (*)(struct Actor *, long, long))func_80802468_chhandcart,
    0};
f32 D_80804E0C_chhandcart[3] BT_DATA(4, overlays_ch_handcart, 0x74C) = {0.14f, 0.65f, -1.0f};
f32 D_80804E18_chhandcart[5] BT_DATA(4, overlays_ch_handcart, 0x758) = {0.07f, 0.3f, 0.56f, 0.82f,
                                                                        -1.0f};
f32 D_80804E2C_chhandcart[3] BT_DATA(4, overlays_ch_handcart, 0x76C) = {0.0f, 0.5f, -1.0f};
f32 D_80804E38_chhandcart[5] BT_DATA(4, overlays_ch_handcart, 0x778) = {0.65f, 0.75f, 0.8f, 0.85f,
                                                                        -1.0f};
f32 D_80804E4C_chhandcart[4] BT_DATA(4, overlays_ch_handcart, 0x78C) = {140.0f, 217.0f, 217.0f,
                                                                        0.0f};
f32 D_80804E5C_chhandcart[4] BT_DATA(4, overlays_ch_handcart, 0x79C) = {217.0f, 217.0f, 217.0f,
                                                                        108.5f};
ActorData D_80804E6C_chhandcart BT_DATA(4, overlays_ch_handcart, 0x7AC) = {
    344,
    1310,
    1659,
    2,
    D_80804730_chhandcart,
    (void (*)(struct Actor *))func_80803794_chhandcart,
    (void (*)(struct Actor *))func_80803794_chhandcart,
    (void (*)(long, long))func_8080436C_chhandcart,
    163850000,
    0,
    0,
    0,
    136,
    1380,
    (void (*)(struct Actor *))func_80802B74_chhandcart,
    0,
    16,
    0,
    (void (*)(struct Actor *))func_808028F0_chhandcart,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -31744,
    2,
    (void (*)(struct Actor *, long, long))func_80803FC4_chhandcart,
    0};
