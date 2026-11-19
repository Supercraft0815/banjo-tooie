/* data_to_c.py: from asm/data/overlays/ch/billdrillplate.data.s */
void func_80105834(Actor *);
void func_80101870(Actor *arg0, void *arg1);
void func_80108ED0();
void func_80107C2C();
DrillPlateEntry D_808010A0_chbilldrillplate[3] BT_DATA(4, overlays_ch_billdrillplate, 0x0) = {
    {0x106, 0x101, {0x3E8, 0x7A8, 9, 0x19, 0x1C2, 0x3D, 0}, {1, 0}},
    {0x10E, 0x10B, {0x1A4, 0x7A9, 7, 8, 0x1C3, 0x3E, 0x210}, {0, 1}},
    {0x109, 0x107, {0x2BC, 0x7A9, 0xE, 0xC, 0x1C4, 0x3F, 0x2B0}, {0, 0}}};
ActorData D_808010DC_chbilldrillplate[1] BT_DATA(4, overlays_ch_billdrillplate, 0x3C) = {
    {162,
     988,
     1951,
     1,
     0,
     (void (*)(struct Actor *))func_808000B0_chbilldrillplate,
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
     (void (*)(struct Actor *))func_80800024_chbilldrillplate,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     3088,
     (void (*)(struct Actor *, long, long))func_80800240_chbilldrillplate,
     0}};
ActorData D_80801124_chbilldrillplate[1] BT_DATA(4, overlays_ch_billdrillplate, 0x84) = {
    {163,
     989,
     1961,
     1,
     0,
     (void (*)(struct Actor *))func_80800408_chbilldrillplate,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80800924_chbilldrillplate,
     0,
     0,
     0,
     0,
     0,
     2048,
     0,
     0,
     12,
     0,
     (void (*)(struct Actor *))func_80800358_chbilldrillplate,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     3090,
     (void (*)(struct Actor *, long, long))func_80800738_chbilldrillplate,
     0}};
ActorData D_8080116C_chbilldrillplate[1] BT_DATA(4, overlays_ch_billdrillplate, 0xCC) = {
    {164,
     990,
     1965,
     1,
     0,
     (void (*)(struct Actor *))func_80800DA4_chbilldrillplate,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     2048,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800D5C_chbilldrillplate,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     3090,
     (void (*)(struct Actor *, long, long))func_80800F24_chbilldrillplate,
     0}};
s16 D_808011B4_chbilldrillplate[8] BT_DATA(4, overlays_ch_billdrillplate,
                                           0x114) = {19, 1586, 13, 243, 268, 22, 25000, 0};
s16 D_808011C4_chbilldrillplate[8] BT_DATA(4, overlays_ch_billdrillplate,
                                           0x124) = {19, 1587, 13, 243, 268, 22, 25000, 0};
s16 D_808011D4_chbilldrillplate[6] BT_DATA(4, overlays_ch_billdrillplate, 0x134) = {19,  1185, 13,
                                                                                    243, 268,  0};
s16 D_808011E0_chbilldrillplate[8] BT_DATA(4, overlays_ch_billdrillplate,
                                           0x140) = {19, 1184, 13, 192, 217, 24, 2, 0};
s16 D_808011F0_chbilldrillplate[24] BT_DATA(4, overlays_ch_billdrillplate, 0x150) = {
    29, 2525, 32,  -16192, -16256, 22,  8,  34,  307, 358, 460, 563,
    21, 0,    153, 43,     256,    307, 45, 200, 300, 282, 0,   0};
s16 D_80801220_chbilldrillplate[10] BT_DATA(4, overlays_ch_billdrillplate,
                                            0x180) = {19, 1576, 13, 243, 268, 2, 22, 28000, 0, 0};
s16 D_80801234_chbilldrillplate[8] BT_DATA(4, overlays_ch_billdrillplate,
                                           0x194) = {19, 1224, 13, 217, 243, 24, 2, 0};
s16 D_80801244_chbilldrillplate[30] BT_DATA(4, overlays_ch_billdrillplate, 0x1A4) = {
    29, 2525, 32,  -16192, -16256, 22,  8,   34, 307, 358, 460, 563, 21, 0, 153,
    43, 256,  307, 45,     200,    300, 282, 0,  0,   0,   0,   0,   0,  0, 0};
