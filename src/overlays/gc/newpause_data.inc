/* data_to_c.py: from asm/data/overlays/gc/newpause.data.s */
Option D_80801FE0_gcnewpause[5] BT_DATA(4, overlays_gc_newpause, 0x0) = {
    {0xC, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {0x13, 2, 1, 1, 0}, {1, 3, 1, 0xE, 0}, {0x9E, 4, 2, 0, 1}};
Option D_80802000_gcnewpause[4] BT_DATA(4, overlays_gc_newpause, 0x20) = {
    {0xC, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {1, 3, 1, 0xE, 0}, {0x9E, 4, 2, 0, 1}};
Option D_80802018_gcnewpause[4] BT_DATA(4, overlays_gc_newpause, 0x38) = {
    {0xC, 0, 0, 0, 0}, {0x13, 2, 1, 1, 0}, {1, 3, 1, 0xE, 0}, {0x9E, 4, 2, 0, 1}};
Option D_80802030_gcnewpause[3] BT_DATA(4, overlays_gc_newpause, 0x50) = {
    {0xC, 0, 0, 0, 0}, {1, 3, 1, 0xE, 0}, {0x9E, 4, 2, 0, 1}};
Option D_80802044_gcnewpause[3] BT_DATA(4, overlays_gc_newpause, 0x64) = {
    {0xC, 0, 0, 0, 0}, {0x10, 1, 3, 0, 1}, {0xD, 2, 4, 0, 1}};
Option D_80802058_gcnewpause[2] BT_DATA(4, overlays_gc_newpause, 0x78) = {{0xC, 0, 0, 0, 0},
                                                                          {0xD, 1, 4, 0, 1}};
Option D_80802064_gcnewpause[2] BT_DATA(4, overlays_gc_newpause, 0x84) = {{0xC, 0, 0, 0, 0},
                                                                          {0xD, 1, 4, 0, 1}};
PauseOption D_80802070_gcnewpause[7] BT_DATA(4, overlays_gc_newpause, 0x90) = {
    {6243, 1, 3, (Option *)D_80802030_gcnewpause}, {6243, 1, 4, (Option *)D_80802000_gcnewpause},
    {6243, 1, 4, (Option *)D_80802018_gcnewpause}, {6243, 1, 5, (Option *)D_80801FE0_gcnewpause},
    {6247, 1, 3, (Option *)D_80802044_gcnewpause}, {6248, 0, 2, (Option *)D_80802058_gcnewpause},
    {6254, 0, 2, (Option *)D_80802064_gcnewpause}};
TotalsFlags D_808020A8_gcnewpause[12] BT_DATA(4, overlays_gc_newpause, 0xC8) = {
    {16, 5},  {15, 6},  {18, 7},  {20, 8}, {21, 9}, {22, 10},
    {23, 11}, {24, 12}, {25, 13}, {26, 4}, {19, 3}, {0, 2}};
InventoryDisplay D_808020D8_gcnewpause[19] BT_DATA(4, overlays_gc_newpause, 0xF8) = {
    {73, 0x11, 0x3C}, {74, 0x12, 0x3C}, {72, 0x13, 0x3C}, {79, 0x14, 0x3C}, {77, 0x15, 0x3C},
    {75, 0x16, 0x3C}, {76, 0x17, 0x3C}, {78, 0x18, 0x3C}, {81, 0x19, 0x3C}, {80, 0x1A, 0x3C},
    {82, 0x2B, 0x3C}, {83, 0x2C, 0x3C}, {64, 4, 0x31},    {65, 5, 0x2C},    {66, 7, 0x2F},
    {67, 6, 0x2D},    {68, 8, 0x2E},    {70, 3, 9},       {71, 9, 0x12}};
PausePageOffsets D_80802124_gcnewpause BT_DATA(4, overlays_gc_newpause, 0x144) = {
    {{21, 17}, {{13, 10, 7, 5}, {3, 2, -1, -1}}, {0, 0}}};
ItemCountDisplay D_80802130_gcnewpause[7] BT_DATA(4, overlays_gc_newpause, 0x150) = {
    {1, 8, 27}, {2, 12, 28}, {4, 59, 29}, {3, 13, 30}, {6, 2, 31}, {0, 22, 32}, {-1, 0, 0}};
AbilityTracking D_8080215C_gcnewpause[26] BT_DATA(4, overlays_gc_newpause, 0x17C) = {
    {16, 0x14}, {16, 0x15}, {16, 0x16}, {15, 0x19}, {15, 0x1A}, {18, 0x1B}, {18, 0x1C},
    {18, 0x29}, {20, 0x1E}, {20, 0x1F}, {20, 0x1D}, {21, 0x26}, {21, 0x27}, {21, 0x28},
    {22, 0x25}, {22, 0x23}, {22, 0x24}, {23, 0x21}, {23, 0x22}, {24, 0x2A}, {26, 0x2C},
    {26, 0x2D}, {26, 0x2E}, {26, 0x2F}, {-1, 0},    {0, 0}};
unk80802190 D_80802190_gcnewpause[6] BT_DATA(4, overlays_gc_newpause, 0x1B0) = {
    {110, 35, 0}, {110, 145, 0}, {35, 35, 0}, {35, 35, 1}, {35, 145, 0}, {35, 145, 1}};
u8 D_808021B4_gcnewpause[12] BT_DATA(4, overlays_gc_newpause, 0x1D4) = {0, 0, 2, 1, 4, 3,
                                                                        0, 5, 4, 0, 0, 5};
s16 D_808021C0_gcnewpause[6] BT_DATA(4, overlays_gc_newpause, 0x1E0) = {19, 1126, 29, 24, 0, 0};
f32 D_808021CC_gcnewpause[3][2] BT_DATA(4, overlays_gc_newpause,
                                        0x1EC) = {{0.0f, 0.0f}, {0.5f, 1.0f}, {1.0f, 0.0f}};
f32 D_808021E4_gcnewpause[3][2] BT_DATA(4, overlays_gc_newpause,
                                        0x204) = {{0.0f, 0.0f}, {0.4f, 1.0f}, {1.0f, 0.0f}};
