/* Original Klungo sound, timing and particle tables. */

s16 D_80803BC0_chklungo[8] BT_DATA(4, tail_ch_klungo, 0x0) = {
    19, 1557,
    13, 243, 268,
    24,
    2,
    0
};

s16 D_80803BD0_chklungo[7] BT_DATA(4, tail_ch_klungo, 0x10) = {
    19, 1272,
    10, 179,
    24,
    2,
    0
};

s16 D_80803BE0_chklungo[5] BT_DATA(4, tail_ch_klungo, 0x20) = {
    19, 1186,
    24,
    2,
    0
};

s16 D_80803BEC_chklungo[7] BT_DATA(4, tail_ch_klungo, 0x2C) = {
    19, 1180,
    10, 179,
    24,
    2,
    0
};

s16 D_80803BFC_chklungo[7] BT_DATA(4, tail_ch_klungo, 0x3C) = {
    19, 1076,
    10, 179,
    24,
    2,
    0
};

s16 D_80803C0C_chklungo[8] BT_DATA(4, tail_ch_klungo, 0x4C) = {
    19, 1466,
    13, 243, 268,
    24,
    2,
    0
};

f32 D_80803C1C_chklungo[4] BT_DATA(4, tail_ch_klungo, 0x5C) = {
    0.43f, 0.5f, 0.6f, -1.0f
};

f32 D_80803C2C_chklungo[4] BT_DATA(4, tail_ch_klungo, 0x6C) = {
    0.81f, 0.88f, 0.95f, -1.0f
};

s16 D_80803C3C_chklungo[11] BT_DATA(4, tail_ch_klungo, 0x7C) = {
    19, 1047,
    22, 18000,
    13, 243, 268,
    1, 800, 7500,
    0
};

f32 D_80803C54_chklungo[6] BT_DATA(4, tail_ch_klungo, 0x94) = {
    0.06f, 0.15f, 0.24f, 0.53f, 0.61f, -1.0f
};

s16 D_80803C6C_chklungo[4] BT_DATA(4, tail_ch_klungo, 0xAC) = {
    19, 1047,
    2,
    0
};

s16 D_80803C74_chklungo[7] BT_DATA(4, tail_ch_klungo, 0xB4) = {
    19, 1556,
    10, 179,
    24,
    2,
    0
};

s16 D_80803C84_chklungo[10] BT_DATA(4, tail_ch_klungo, 0xC4) = {
    774,
    19, 1271,
    13, 140, 166,
    24,
    2,
    17,
    0
};

s16 D_80803C98_chklungo[8] BT_DATA(4, tail_ch_klungo, 0xD8) = {
    19, 1272,
    13, 192, 217,
    24,
    2,
    0
};

s16 D_80803CA8_chklungo[7] BT_DATA(4, tail_ch_klungo, 0xE8) = {
    19, 1261,
    13, 192, 217,
    2,
    0
};

s16 D_80803CB8_chklungo[4] BT_DATA(4, tail_ch_klungo, 0xF8) = {
    19, 1047,
    2,
    0
};

s16 D_80803CC0_chklungo[26] BT_DATA(4, tail_ch_klungo, 0x100) = {
    29, 2525,
    43, 384, 512,
    34, 384, 512, 896, 1024,
    21, 0, 153,
    39, -100, -100, 100, 100,
    25, 0, 7,
    45, 250, 350,
    282,
    0
};

#define KLUNGO_CUE_PREFIX 19, 0x413, 24, 13, 192, 217
/* On N64 the last command and terminator also form potion order zero. */
KlungoPotionLayout D_80803CF4_chklungo = {
    {KLUNGO_CUE_PREFIX}, 0,
    {{2, 0, 0}, {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 2, 1}, {3, 1, 2}},
    {0, 0}
};
#ifdef BT_NATIVE
s16 klungoPotionCue[8] = {KLUNGO_CUE_PREFIX, 2, 0};
#endif
#undef KLUNGO_CUE_PREFIX

s16 D_80803D18_chklungo[8] BT_DATA(4, tail_ch_klungo, 0x158) = {
    19, 1535,
    13, 217, 243,
    24,
    2,
    0
};

s16 D_80803D28_chklungo[7] BT_DATA(4, tail_ch_klungo, 0x168) = {
    19, 1200,
    13, 243, 268,
    2,
    0
};

f32 D_80803D38_chklungo[3] BT_DATA(4, tail_ch_klungo, 0x178) = {
    0.0f, 0.5f, -1.0f
};
