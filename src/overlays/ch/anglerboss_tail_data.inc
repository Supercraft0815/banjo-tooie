/* Sound and emitter command streams use signed halfwords and a zero terminator. */

s16 D_80802F50_changlerboss[8] BT_DATA(4, tail_ch_anglerboss, 0x0) = {
    19, 1507,
    24,
    2,
    13, 320, 345,
    0
};

s16 D_80802F60_changlerboss[8] BT_DATA(4, tail_ch_anglerboss, 0x10) = {
    19, 1508,
    24,
    2,
    13, 320, 345,
    0
};

s16 D_80802F70_changlerboss[8] BT_DATA(4, tail_ch_anglerboss, 0x20) = {
    19, 1551,
    13, 192, 217,
    24,
    2,
    0
};

s16 D_80802F80_changlerboss[5] BT_DATA(4, tail_ch_anglerboss, 0x30) = {
    19, 1505,
    24,
    2,
    0
};

s16 D_80802F8C_changlerboss[6][3][3] BT_DATA(4, tail_ch_anglerboss, 0x3C) = {
    {{3, 6, -1}, {4, 7, -1}, {5, 8, -1}},
    {{9, -1, 0}, {10, -1, 0}, {11, -1, 0}},
    {{12, 15, -1}, {13, 16, -1}, {14, 17, -1}},
    {{18, -1, 0}, {19, -1, 0}, {20, -1, 0}},
    {{21, -1, 0}, {22, -1, 0}, {23, -1, 0}},
    {{24, -1, 0}, {25, -1, 0}, {26, -1, 0}}
};

s16 D_80802FF8_changlerboss[7] BT_DATA(4, tail_ch_anglerboss, 0xA8) = {
    19, 1021,
    13, 166, 192,
    2,
    0
};

s16 D_80803008_changlerboss[37] BT_DATA(4, tail_ch_anglerboss, 0xB8) = {
    29, 2521,
    22, 4608,
    1, 0, 35, 0, 0, 50, 0,
    27, 150, 200,
    7, 1,
    21, 0, 204,
    14, 50, 60,
    43, 384, 1152,
    32, -1, -257,
    47, 64, 64, 0, 0, 25, 0, 51,
    0
};

s16 D_80803054_changlerboss[6] BT_DATA(4, tail_ch_anglerboss, 0x104) = {
    4, 5, 6, 7, 8, 9
};

s16 D_80803060_changlerboss[27] BT_DATA(4, tail_ch_anglerboss, 0x110) = {
    29, 2515,
    34, 204, 256, 25, 38,
    22, 8704,
    45, 800, 1000,
    21, 0, 192,
    14, 20, 80,
    43, 320, 448,
    48, 240,
    27, 150, 200,
    0
};

u32 D_80803098_changlerboss[3] BT_DATA(4, tail_ch_anglerboss, 0x148) = {
    255, 255, 96
};
