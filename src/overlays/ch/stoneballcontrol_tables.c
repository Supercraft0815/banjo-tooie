#include "common.h"

/* data_to_c.py: from asm/data/overlays/ch/stoneballcontrol.data.s */
u16 D_80804FC0_chstoneballcontrol[10] BT_DATA(4, overlays_ch_stoneballcontrol, 0x0) = {
    0x13, 0x4B1, 0xA, 0xA6, 0x16, 0x4E20, 1, 0x1F4, 0x1388, 0};
u16 D_80804FD4_chstoneballcontrol[10] BT_DATA(4, overlays_ch_stoneballcontrol, 0x14) = {
    0x13, 0x413, 0xA, 0x100, 0x16, 0x7D00, 1, 0x1F4, 0x1388, 0};
u16 D_80804FE8_chstoneballcontrol[10] BT_DATA(4, overlays_ch_stoneballcontrol, 0x28) = {
    0x13, 0x4F4, 0xA, 0x100, 0x16, 0x4E20, 1, 0x1F4, 0x1388, 0};
f32 D_80804FFC_chstoneballcontrol[5] BT_DATA(4, overlays_ch_stoneballcontrol,
                                             0x3C) = {100.0f, 150.0f, 200.0f, 0.0f, 400.0f};
f32 D_80805010_chstoneballcontrol[5][2] BT_DATA(4, overlays_ch_stoneballcontrol, 0x50) = {
    {1.0f, 0.0f}, {0.75f, 1.0f}, {0.75f, 1.0f}, {0.3333f, 0.6666f}, {0.3333f, 0.6666f}};
s32 D_80805038_chstoneballcontrol[5][4] BT_DATA(4, overlays_ch_stoneballcontrol, 0x78) = {
    {2, 0, 0, 0}, {3, 1, 1, 0}, {4, 1, 0, 1}, {4, 0, 0, 2}, {5, 2, 1, 1}};
s32 D_80805088_chstoneballcontrol[5] BT_DATA(4, overlays_ch_stoneballcontrol, 0xC8) = {45, 45, 45,
                                                                                       0, 60};
s32 D_8080509C_chstoneballcontrol[5] BT_DATA(4, overlays_ch_stoneballcontrol, 0xDC) = {4, 4, 4, 1,
                                                                                       4};
