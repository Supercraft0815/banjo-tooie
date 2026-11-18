/* data_to_c.py: from asm/data/overlays/ch/dino/familysmall.data.s */
extern ActorAnimationEntry D_80800E90_chdinofamilysmall[];
void func_80105834(Actor *);
void func_80107C2C();
ActorAnimationEntry D_80800E90_chdinofamilysmall[11] BT_DATA(4, overlays_ch_dino_familysmall, 0x0) = {
    {0.0f, 0, 0},     {5.0f, 0x14D, 1}, {5.0f, 0x14D, 1}, {5.0f, 0x14D, 1},
    {5.0f, 0x14D, 1}, {5.0f, 0x14D, 1}, {5.0f, 0x14D, 1}, {2.2f, 0x3F8, 0x41},
    {2.2f, 0x3F8, 1}, {2.2f, 0x3F8, 1}, {2.2f, 0x3F8, 1}};
s32 D_80800EE8_chdinofamilysmall[5] BT_DATA(4, overlays_ch_dino_familysmall,
                                            0x58) = {1246237, 655488, 1469792, 68536, 393216000};
s32 D_80800EFC_chdinofamilysmall[5] BT_DATA(4, overlays_ch_dino_familysmall,
                                            0x6C) = {1246238, 655616, 1469792, 68536, 393216000};
s32 D_80800F10_chdinofamilysmall[4] BT_DATA(4, overlays_ch_dino_familysmall, 0x80) = {1128792064, 1120403456,
                                                                                      1128792064, 1120403456};
ActorData D_80800F20_chdinofamilysmall[1] BT_DATA(4, overlays_ch_dino_familysmall, 0x90) = {
    {298,
     658,
     2202,
     2,
     (void *)D_80800E90_chdinofamilysmall,
     (void (*)(struct Actor *))func_80800090_chdinofamilysmall,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80800C10_chdinofamilysmall,
     327680000,
     1073741824,
     0,
     0,
     128,
     256,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800000_chdinofamilysmall,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     21510,
     (void (*)(struct Actor *, long, long))func_80800AF4_chdinofamilysmall,
     0}};
