/* data_to_c.py: from asm/data/overlays/ch/digger/boss.data.s */
void func_80102EC0();
void func_80108ED0();
void func_80107C2C();
DiggerBossAttack D_80809C60_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x0) = {2, 0x5A, 1000, 1500, 0, 1.5f, 3.0f};
DiggerBossAttack D_80809C70_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x10) = {2, 0x50, 1200, 1800, 0, 1.25f, 2.5f};
DiggerBossAttack D_80809C80_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x20) = {2, 0x46, 1400, 2100, 0, 1.0f, 2.0f};
DiggerBossAttack D_80809C90_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x30) = {3, 0x3C, 1600, 2400, 0, 0.9f, 1.8f};
DiggerBossAttack D_80809CA0_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x40) = {3, 0x32, 1800, 2700, 0, 0.8f, 1.6f};
DiggerBossAttack D_80809CB0_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x50) = {3, 0x28, 2000, 3000, 0, 0.7f, 1.4f};
DiggerBossAttack D_80809CC0_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x60) = {4, 0x1E, 2000, 3000, 0, 0.6f, 1.2f};
DiggerBossAttack D_80809CD0_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x70) = {4, 0xF, 2000, 3000, 0, 0.5f, 1.0f};
DiggerBossAttack D_80809CE0_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                 0x80) = {4, 1, 2000, 3000, 0, 0.5f, 1.0f};
DiggerBossProjectile D_80809CF0_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                     0x90) = {4, 100, 400, 0, 2.0f, 1000, 1500};
DiggerBossProjectile D_80809D00_chdiggerboss BT_DATA(4, overlays_ch_digger_boss,
                                                     0xA0) = {6, 100, 200, 0, 1.5f, 1000, 1500};
ActorAnimationEntry D_80809D10_chdiggerboss[21] BT_DATA(4, overlays_ch_digger_boss, 0xB0) = {
    {0.0f, 0, 0},      {0.0f, 0, 0},         {0.64f, 0x435, 2}, {1.45f, 0x43B, 2},
    {5.88f, 0x436, 2}, {8.58f, 0x437, 1},    {1.0f, 0x438, 2},  {1.21f, 0x439, 2},
    {6.67f, 0x43F, 1}, {1.05f, 0x43A, 2},    {3.17f, 0x43C, 2}, {4.17f, 0x43D, 1},
    {1.13f, 0x43E, 2}, {4.2f, 0x440, 2},     {1.33f, 0x429, 2}, {0.47f, 0x42A, 0x42},
    {1.33f, 0x42B, 2}, {0.47f, 0x42C, 0x42}, {1.13f, 0x42D, 2}, {1.13f, 0x42E, 2},
    {0.63f, 0x42F, 2}};
s16 D_80809DB8_chdiggerboss[10] BT_DATA(4, overlays_ch_digger_boss,
                                        0x158) = {19, 1366, 13, 243, 268, 1, 1200, 8000, 0, 0};
s16 D_80809DCC_chdiggerboss[12] BT_DATA(4, overlays_ch_digger_boss, 0x16C) = {
    19, 1184, 13, 243, 268, 22, 12000, 1, 1200, 8000, 0, 0};
s16 D_80809DE4_chdiggerboss[12] BT_DATA(4, overlays_ch_digger_boss, 0x184) = {
    19, 1146, 13, 243, 268, 22, 28000, 1, 1200, 8000, 0, 0};
s16 D_80809DFC_chdiggerboss[10] BT_DATA(4, overlays_ch_digger_boss,
                                        0x19C) = {19, 1162, 22, 28000, 1, 1200, 8000, 32, 0, 0};
s16 D_80809E10_chdiggerboss[10] BT_DATA(4, overlays_ch_digger_boss,
                                        0x1B0) = {19, 1159, 22, 28000, 1, 1200, 8000, 32, 0, 0};
s16 D_80809E24_chdiggerboss[10] BT_DATA(4, overlays_ch_digger_boss,
                                        0x1C4) = {19, 1465, 12, 0, 153, 204, 281, 24, 32, 0};
s16 D_80809E38_chdiggerboss[6] BT_DATA(4, overlays_ch_digger_boss, 0x1D8) = {19, 1223, 24,
                                                                             32, 0,    0};
ActorData D_80809E44_chdiggerboss BT_DATA(4, overlays_ch_digger_boss, 0x1E4) = {
    424,
    835,
    2305,
    1,
    (void *)D_80809D10_chdiggerboss,
    (void (*)(struct Actor *))func_80800A4C_chdiggerboss,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_80800508_chdiggerboss,
    0,
    0,
    0,
    0,
    4104,
    9512,
    (void (*)(struct Actor *))func_808019A8_chdiggerboss,
    (BtIntPtr)func_80108ED0,
    268,
    0,
    (void (*)(struct Actor *))func_808008F8_chdiggerboss,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32736,
    0,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_80801A04_chdiggerboss, (void (*)(struct Actor *, long, long))func_80801A04_chdiggerboss),
    0};
ActorData D_80809E8C_chdiggerboss BT_DATA(4, overlays_ch_digger_boss, 0x22C) = {
    60,
    515,
    2302,
    1,
    (void *)D_80809D10_chdiggerboss,
    (void (*)(struct Actor *))func_808023D8_chdiggerboss,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(s32, s32))func_80800650_chdiggerboss,
    0,
    0,
    0,
    0,
    8192,
    15460,
    (void (*)(struct Actor *))func_80802550_chdiggerboss,
    (BtIntPtr)func_80108ED0,
    236,
    0,
    (void (*)(struct Actor *))func_8080233C_chdiggerboss,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk38_func))func_80107C2C, (void (*)(void *, long, void *, long, void *))func_80107C2C),
    -32640,
    2,
    BT_DATA_FIELD((__typeof__(((ActorData *)0)->unk40_func))func_808025D4_chdiggerboss, (void (*)(struct Actor *, long, long))func_808025D4_chdiggerboss),
    0};
s16 D_80809ED4_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x274) = {5, 6,  7, 8,
                                                                             9, 10, 5, 0};
u16 D_80809EE4_chdiggerboss[16] BT_DATA(4, overlays_ch_digger_boss, 0x284) = {
    0x688, 0x689, 0x68A, 0x68B, 0x68C, 0x68D, 0x68E, 0x68F,
    0x690, 0,     0,     0x691, 0x692, 0x693, 0x694, 0};
s16 D_80809F04_chdiggerboss[6] BT_DATA(4, overlays_ch_digger_boss, 0x2A4) = {19,    1193, 22,
                                                                             32000, 2,    0};
f32 D_80809F10_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x2B0) = {-350.0f, -100.0f,
                                                                             -400.0f};
f32 D_80809F1C_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x2BC) = {350.0f, 800.0f,
                                                                             350.0f};
u16 D_80809F28_chdiggerboss[3][2] BT_DATA(4, overlays_ch_digger_boss, 0x2C8) = {
    {0x1C30, 0x1C44}, {0x1C44, 0x1C58}, {0x1C58, 0x1C6C}};
s16 D_80809F34_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x2D4) = {157, 159, -1, 0};
u8 D_80809F3C_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x2DC) = {0x3C, 0x32, 0x40, 0xFE};
u8 D_80809F40_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x2E0) = {0xE0, 0xFF, 0xE0, 0x80};
s16 D_80809F44_chdiggerboss[12] BT_DATA(4, overlays_ch_digger_boss, 0x2E4) = {
    19, 1205, 13, 217, 294, 22, 28000, 1, 1200, 8000, 0, 0};
s16 D_80809F5C_chdiggerboss[12] BT_DATA(4, overlays_ch_digger_boss, 0x2FC) = {
    19, 1169, 13, 307, 332, 22, 28000, 1, 1200, 8000, 0, 0};
s16 D_80809F74_chdiggerboss[10] BT_DATA(4, overlays_ch_digger_boss,
                                        0x314) = {19, 1543, 13, 243, 268, 24, 1, 1200, 8000, 0};
s16 D_80809F88_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x328) = {19, 1043, 22,   28000,
                                                                             1,  1200, 8000, 0};
f32 D_80809F98_chdiggerboss[3][2] BT_DATA(4, overlays_ch_digger_boss,
                                          0x338) = {{0.0f, 0.0f}, {0.5f, 1.0f}, {1.0f, 0.0f}};
s16 D_80809FB0_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x350) = {19,   1520, 24, 1,
                                                                             1200, 8000, 0,  0};
s16 D_80809FC0_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x360) = {19, 1319, 29,   30,
                                                                             1,  1200, 8000, 0};
s16 D_80809FD0_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x370) = {19,   1520, 1, 1200,
                                                                             8000, 24,   0, 0};
s16 D_80809FE0_chdiggerboss[36] BT_DATA(4, overlays_ch_digger_boss, 0x380) = {
    29,  2524, 50, 0,  22, 8704, 34,  128, 128, 512, 640, 39, -120, -120, 120, 120, 45, 500,
    600, 27,   40, 60, 21, 0,    153, 43,  256, 307, 14,  15, 30,   282,  48,  243, 0,  0};
s16 D_8080A028_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x3C8) = {19, 1302, 29,   30,
                                                                             1,  1200, 8000, 0};
f32 D_8080A038_chdiggerboss[2] BT_DATA(4, overlays_ch_digger_boss, 0x3D8) = {150.0f, 300.0f};
s16 D_8080A040_chdiggerboss[12] BT_DATA(4, overlays_ch_digger_boss, 0x3E0) = {
    19, 1247, 14, 204, 256, 128, 22, 6500, 1, 1200, 8000, 0};
s16 D_8080A058_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x3F8) = {4, 5, 6, 13};
s16 D_8080A060_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x400) = {4, 3, 1, 2};
u8 D_8080A068_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x408) = {8, 4, 1, 2};
u32 D_8080A06C_chdiggerboss[2][3] BT_DATA(4, overlays_ch_digger_boss, 0x40C) = {{0xFF, 0xFF, 0xFF},
                                                                                {0x20, 0xC0, 0xFF}};
f32 D_8080A084_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x424) = {-300.0f, 0.0f, 175.0f};
f32 D_8080A090_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x430) = {-300.0f, 0.0f,
                                                                             -375.0f};
f32 D_8080A09C_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x43C) = {300.0f, 0.0f, 175.0f};
f32 D_8080A0A8_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x448) = {300.0f, 0.0f, -375.0f};
s16 D_8080A0B4_chdiggerboss[28] BT_DATA(4, overlays_ch_digger_boss, 0x454) = {
    29,  2530, 22, 512, 6,  0,  4,  153, 7, 3,  21, 0,     204,   43,
    384, 512,  34, 76,  89, 38, 51, 14,  5, 10, 27, -1600, -1200, 0};
s16 D_8080A0EC_chdiggerboss[12] BT_DATA(4, overlays_ch_digger_boss, 0x48C) = {
    19, 1674, 14, 243, 268, 25, 22, 28000, 1, 1200, 8000, 0};
s16 D_8080A104_chdiggerboss[12] BT_DATA(4, overlays_ch_digger_boss, 0x4A4) = {
    774, 33, 13, 243, 268, 24, 1, 1200, 8000, 17, 0, 0};
s16 D_8080A11C_chdiggerboss[2] BT_DATA(4, overlays_ch_digger_boss, 0x4BC) = {1164, 1163};
s16 D_8080A120_chdiggerboss[10] BT_DATA(4, overlays_ch_digger_boss,
                                        0x4C0) = {19, 1162, 22, 28000, 1, 1200, 8000, 32, 0, 0};
f32 D_8080A134_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x4D4) = {100.0f, 7500.0f,
                                                                             100.0f};
s16 D_8080A140_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x4E0) = {19,  1543, 24, 13,
                                                                             243, 268,  0,  0};
u8 D_8080A150_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x4F0) = {0x6E, 0x64, 0x50, 0xE0};
s16 D_8080A154_chdiggerboss[6] BT_DATA(4, overlays_ch_digger_boss, 0x4F4) = {19,  1214, 13,
                                                                             243, 268,  0};
s16 D_8080A160_chdiggerboss[6] BT_DATA(4, overlays_ch_digger_boss, 0x500) = {19, 1244, 24,
                                                                             2,  32,   0};
s16 D_8080A16C_chdiggerboss[32] BT_DATA(4, overlays_ch_digger_boss, 0x50C) = {
    29,   2524, 50,  0,  22,  512, 34, 128, 128, 512, 640, 32,  -192, -8000, 39, -120,
    -120, 120,  120, 45, 250, 350, 21, 25,  153, 43,  256, 358, 14,   15,    30, 0};
f32 D_8080A1AC_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x54C) = {37.5f, -37.5f, 166.0f,
                                                                             -166.0f};
f32 D_8080A1BC_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x55C) = {47.5f, 47.5f, 15.5f,
                                                                             15.5f};
f32 D_8080A1CC_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x56C) = {525.0f, 525.0f, 525.0f,
                                                                             525.0f};
f32 D_8080A1DC_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x57C) = {-300.0f, 0.0f,
                                                                             -100.0f};
f32 D_8080A1E8_chdiggerboss[3] BT_DATA(4, overlays_ch_digger_boss, 0x588) = {300.0f, 0.0f, -100.0f};
u16 D_8080A1F4_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x594) = {0x44, 0x45, 0x46, 0};
u16 D_8080A1FC_chdiggerboss[4] BT_DATA(4, overlays_ch_digger_boss, 0x59C) = {0x47, 0x48, 0x49, 0};
DiggerBossExplosion D_8080A204_chdiggerboss[5] BT_DATA(4, overlays_ch_digger_boss, 0x5A4) = {
    {33, 156, 0.75f}, {35, 157, 0.65f}, {38, 158, 0.55f}, {40, 159, 0.45f}, {30, 160, 3.5f}};
s16 D_8080A22C_chdiggerboss[10] BT_DATA(4, overlays_ch_digger_boss,
                                        0x5CC) = {19, 1224, 22, 28000, 2, 13, 204, 230, 0, 0};
s16 D_8080A240_chdiggerboss[8] BT_DATA(4, overlays_ch_digger_boss, 0x5E0) = {1,  18, 24, 26,
                                                                             10, 12, -1, 0};
s16 D_8080A250_chdiggerboss[6] BT_DATA(4, overlays_ch_digger_boss, 0x5F0) = {19, 1043, 24, 2, 0, 0};
s16 D_8080A25C_chdiggerboss[28] BT_DATA(4, overlays_ch_digger_boss, 0x5FC) = {
    29, 1935, 21,   25, 102, 22,  512,  50,   2,  30,  30,  30, 24, 0,
    0,  3840, 3840, 34, 256, 256, 1024, 1024, 43, 307, 307, 41, 0,  0};
s16 D_8080A294_chdiggerboss[18] BT_DATA(4, overlays_ch_digger_boss, 0x634) = {
    29, 2387, 21, 0, 179, 22, 512, 34, 128, 128, 2048, 2048, 43, 358, 358, 41, 0, 0};
s16 D_8080A2B8_chdiggerboss[36] BT_DATA(4, overlays_ch_digger_boss, 0x658) = {
    29,  2525, 22, 512, 43, 384, 512, 34,  384, 512,    896,    1024, 21, 0, 153, 39, -100, -100,
    100, 100,  25, 0,   7,  45,  250, 350, 32,  -16192, -16256, 282,  41, 0, 0,   0,  0,    0};
