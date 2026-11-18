/* data_to_c.py: from asm/data/overlays/ch/iciclebits.data.s */
void func_80105834(Actor *);
void func_80101870();
void func_80108ED0();
void func_80107C2C();
ActorData D_808003A0_chiciclebits[1] BT_DATA(4, overlays_ch_iciclebits, 0x0) = {
    {175,
     1052,
     1969,
     1,
     0,
     (void (*)(struct Actor *))func_808000D0_chiciclebits,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     2048,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_8080000C_chiciclebits,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     3072,
     (void (*)(struct Actor *, long, long))func_80800240_chiciclebits,
     0}};
IcicleEntry D_808003E8_chiciclebits[7] BT_DATA(4, overlays_ch_iciclebits, 0x48) = {
    {{53, 20, -18}, 0x1ED, 0x7B1}, {{53, 21, -14}, 0x1EE, 0x7B2}, {{53, 22, -9}, 0x1EF, 0x7B3},
    {{53, 23, -5}, 0x1F0, 0x7B4},  {{53, 24, -1}, 0x1F1, 0x7B5},  {{53, 25, 2}, 0x1F2, 0x7B6},
    {{53, 26, 8}, 0x1F3, 0x7B7}};
s16 D_80800430_chiciclebits[28] BT_DATA(4, overlays_ch_iciclebits, 0x90) = {
    29,  2525, 32,  -32513, -16256, 22, 520, 34, 409, 460, 640, 768, 21, 51,
    153, 43,   307, 358,    11,     60, 80,  20, 0,   45,  100, 150, 0,  0};
s16 D_80800468_chiciclebits[32] BT_DATA(4, overlays_ch_iciclebits, 0xC8) = {
    29,    1886, 22, 512, 43,  307, 358, 39, 200, 200, 400, 400, 45, 350, 450, 27,
    -1000, -800, 34, 384, 512, 192, 256, 21, 0,   204, 11,  60,  80, 20,  0,   0};
s16 D_808004A8_chiciclebits[8] BT_DATA(4, overlays_ch_iciclebits, 0x108) = {19,  1464, 13, 243,
                                                                            268, 24,   2,  0};
s16 D_808004B8_chiciclebits[8] BT_DATA(4, overlays_ch_iciclebits, 0x118) = {19, 1323, 24,  2,
                                                                            13, 230,  281, 0};
s16 D_808004C8_chiciclebits[12] BT_DATA(4, overlays_ch_iciclebits,
                                        0x128) = {19, 1031, 2, 13, 332, 358, 0, 0, 0, 0, 0, 0};
