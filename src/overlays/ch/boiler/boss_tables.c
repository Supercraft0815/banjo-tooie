#include "boss_tables.h"

/* data_to_c.py: from asm/data/overlays/ch/boiler/boss.data.s */
f32 D_80802AA0_chboilerboss[4] BT_DATA(4, overlays_ch_boiler_boss, 0x0) = {380.0f, 600.0f, 200.0f,
                                                                           180.0f};
s32 D_80802AB0_chboilerboss[7] BT_DATA(4, overlays_ch_boiler_boss, 0x10) = {
    1902482, 1310754, 3014720, 2490411, 2949520, 39321612, 4915200};
s32 D_80802ACC_chboilerboss[15] BT_DATA(4, overlays_ch_boiler_boss, 0x2C) = {
    1903069, 1442304, 2143412, -1262485461, 16777523, 2228275,  4981120, 33554453,
    204,     1638400, 458796,  100,         0,        13107200, 0};
u16 D_80802B08_chboilerboss[6] BT_DATA(4, overlays_ch_boiler_boss, 0x68) = {0x13, 0x4F8, 0x18,
                                                                            2,    0,     0};
u16 D_80802B14_chboilerboss[6] BT_DATA(4, overlays_ch_boiler_boss, 0x74) = {0x13, 0x4B5, 0x18,
                                                                            2,    0,     0};
u16 D_80802B20_chboilerboss[10] BT_DATA(4, overlays_ch_boiler_boss, 0x80) = {
    0x13, 0x417, 0x16, 0x36B0, 0xD, 0xC0, 0xD9, 2, 0, 0};
u16 D_80802B34_chboilerboss[6] BT_DATA(4, overlays_ch_boiler_boss, 0x94) = {0x13, 0x4F5, 0x18,
                                                                            2,    0,     0};
u16 D_80802B40_chboilerboss[6] BT_DATA(4, overlays_ch_boiler_boss, 0xA0) = {0x13, 0x4F6, 0x18,
                                                                            2,    0,     0};
f32 D_80802B4C_chboilerboss[4] BT_DATA(4, overlays_ch_boiler_boss, 0xAC) = {300.0f, 400.0f, 500.0f,
                                                                            600.0f};
f32 D_80802B5C_chboilerboss[4][2] BT_DATA(4, overlays_ch_boiler_boss, 0xBC) = {
    {14.0f, 16.0f}, {12.0f, 14.0f}, {10.0f, 12.0f}, {8.0f, 10.0f}};
BoilerBossAnimations D_80802B7C_chboilerboss BT_DATA(4, overlays_ch_boiler_boss, 0xDC) = {
#ifdef BT_NATIVE
    .states =
        {
#else
    {{
#endif
            {0.0f, 0x0, 0x0},
            {1.0f, 0xC5, 0x44},
            {4.6f, 0xC5, 0x2},
            {1.7f, 0x2C5, 0x2},
            {1.2f, 0x2C6, 0x1},
            {0.75f, 0xC6, 0x1},
            {0.75f, 0xC7, 0x2},
            {3.0f, 0xC3, 0x2},
            {3.0f, 0xC2, 0x2},
            {3.0f, 0xBF, 0x2},
            {3.0f, 0xC4, 0x2},
            {1.2f, 0x2C6, 0x1},
            {0.0f, 0x0, 0x0},
            {0.0f, 0x0, 0x0},
            {1.5f, 0xC1, 0x2},
            {1.5f, 0xC0, 0x2},
#ifdef BT_NATIVE
            {1.6f, 0xBE, 0x2},
            {1.2f, 0x2C6, 0x1}}
#else
     },
     1.6f}
#endif
};
