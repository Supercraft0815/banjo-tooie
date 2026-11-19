#include "y_tables.h"

/* data_to_c.py: from asm/data/overlays/ch/mole/y.data.s */
u16 D_80800A90_chmoley[12] BT_DATA(4, overlays_ch_mole_y, 0x0) = {
    0x13, 0x614, 0xD, 0x173, 0x18C, 0x16, 0x6D60, 1, 0x1F4, 0x9C4, 0, 0};
u16 D_80800AA8_chmoley[12] BT_DATA(4, overlays_ch_mole_y, 0x18) = {
    0x13, 0x5A4, 0xD, 0x173, 0x18C, 0x16, 0x3A98, 1, 0x1F4, 0x9C4, 0, 0};
u16 D_80800AC0_chmoley[12] BT_DATA(4, overlays_ch_mole_y, 0x30) = {
    0x13, 0x449, 0xD, 0x166, 0x18C, 0x16, 0x1F40, 1, 0x1F4, 0x9C4, 0, 0};
u16 D_80800AD8_chmoley[12] BT_DATA(4, overlays_ch_mole_y, 0x48) = {
    0x13, 0x449, 0xD, 0x159, 0x180, 0x16, 0x1F40, 1, 0x1F4, 0x9C4, 0, 0};
u16 D_80800AF0_chmoley[12] BT_DATA(4, overlays_ch_mole_y, 0x60) = {
    0x13, 0x402, 0xD, 0xF3, 0x10C, 0x16, 0x5DC0, 1, 0x1F4, 0x9C4, 0, 0};
u16 D_80800B08_chmoley[12] BT_DATA(4, overlays_ch_mole_y, 0x78) = {
    0x13, 0x62D, 0xD, 0xF3, 0x10C, 0x16, 0x55F0, 1, 0x1F4, 0x9C4, 0, 0};
u16 D_80800B20_chmoley[12] BT_DATA(4, overlays_ch_mole_y, 0x90) = {
    0x13, 0x62E, 0xD, 0xF3, 0x10C, 0x16, 0x55F0, 1, 0x1F4, 0x9C4, 0, 0};
u16 D_80800B38_chmoley[10] BT_DATA(4, overlays_ch_mole_y, 0xA8) = {0x13,  0x653, 0x16, 0x6D60, 1,
                                                                   0x1F4, 0x9C4, 0x20, 0,      0};
u16 D_80800B4C_chmoley[10] BT_DATA(4, overlays_ch_mole_y, 0xBC) = {
    0x13, 0x679, 0xA, 0x133, 0x16, 0x4650, 1, 0x5DC, 0x9C4, 0};
ActorAnimationEntry D_80800B60_chmoley[14] BT_DATA(4, overlays_ch_mole_y, 0xD0) = {
    {0.0f, 0, 0},     {1.7f, 0x2BE, 0x44}, {1.7f, 0x2BE, 2}, {1.6f, 0x2C1, 2},    {4.7f, 0x2BF, 2},
    {0.7f, 0x2BC, 1}, {1.3f, 0x2BB, 2},    {0.8f, 0x2C2, 2}, {0.9f, 0x2C3, 2},    {4.0f, 0x2C4, 1},
    {9.5f, 0x2C8, 1}, {6.0f, 0x2C9, 2},    {4.0f, 0x2C4, 1}, {9.5f, 0x2C8, 0x201}};
f32 D_80800BD0_chmoley[4] BT_DATA(4, overlays_ch_mole_y, 0x140) = {150.0f, 65.0f, 65.0f, 25.0f};
MoleYTimes D_80800BE0_chmoley BT_DATA(4, overlays_ch_mole_y,
                                      0x150) = {{0.6999f, 0.7399f, 0.7699f, -1.0f}};
MoleYTimes D_80800BF0_chmoley BT_DATA(4, overlays_ch_mole_y,
                                      0x160) = {{0.8799f, 0.8999f, 0.9175f, -1.0f}};
MoleYTimes D_80800C00_chmoley BT_DATA(4, overlays_ch_mole_y,
                                      0x170) = {{0.1899f, 0.2399f, 0.2699f, -1.0f}};
