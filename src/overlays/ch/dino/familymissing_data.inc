/* data_to_c.py: from asm/data/overlays/ch/dino/familymissing.data.s */
extern ActorAnimationEntry D_80800660_chdinofamilymissing[];
void func_801018A4();
void func_80107C2C();
ActorAnimationEntry D_80800660_chdinofamilymissing[8] BT_DATA(4, overlays_ch_dino_familymissing, 0x0) = {
    {0.0f, 0, 0},     {0.5f, 0x14C, 1}, {0.35f, 0x14C, 1}, {2.2f, 0x3F8, 1},
    {2.2f, 0x3F8, 1}, {2.2f, 0x3F8, 1}, {2.2f, 0x3F8, 1},  {2.2f, 0x3F8, 1}};
u32 D_808006A0_chdinofamilymissing[3] BT_DATA(4, overlays_ch_dino_familymissing, 0x40) = {0x13044C, 0xA00B3,
                                                                                          0};
u8 D_808006AC_chdinofamilymissing[32] BT_DATA(4, overlays_ch_dino_familymissing, 0x4C) = {
    0,    0, 0, 0, 0x3F, 0x80, 0, 0, 0x3E, 0x80, 0, 0, 0x3F, 0x40, 0, 0,
    0x3F, 0, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x40, 0, 0, 0x3F, 0x40, 0, 0};
s32 D_808006CC_chdinofamilymissing[4] BT_DATA(4, overlays_ch_dino_familymissing,
                                              0x6C) = {1128792064, 1120403456, 1128792064, 1120403456};
ActorData D_808006DC_chdinofamilymissing BT_DATA(4, overlays_ch_dino_familymissing, 0x7C) = {
    299,
    659,
    1740,
    1,
    (void *)D_80800660_chdinofamilymissing,
    (void (*)(struct Actor *))func_80800104_chdinofamilymissing,
    (void (*)(struct Actor *))func_80800104_chdinofamilymissing,
    (void (*)(long, long))func_801018A4,
    327680000,
    1073741824,
    0,
    0,
    132,
    256,
    0,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_80800000_chdinofamilymissing,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    21510,
    (void (*)(struct Actor *, long, long))func_808004A4_chdinofamilymissing,
    0};
