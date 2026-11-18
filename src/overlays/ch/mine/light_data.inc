/* data_to_c.py: from asm/data/overlays/ch/mine/light.data.s */
void func_80105834(Actor *);
void func_8010A730();
void func_80107C2C();
s16 D_80800660_chminelight[9] BT_DATA(4, overlays_ch_mine_light, 0x0) = {19, 1276,  13, 243, 268,
                                                                         22, 12000, 2,  0};
s16 D_80800674_chminelight[9] BT_DATA(4, overlays_ch_mine_light, 0x14) = {19, 1276, 13, 243, 268,
                                                                          22, 6000, 2,  0};
s32 D_80800688_chminelight[9] BT_DATA(4, overlays_ch_mine_light, 0x28) = {3, 4, 5,  6, 7,
                                                                          8, 9, 10, 11};
ActorData D_808006AC_chminelight[1] BT_DATA(4, overlays_ch_mine_light, 0x4C) = {
    {712,
     771,
     0,
     4,
     0,
     (void (*)(struct Actor *))func_8080011C_chminelight,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8010A730,
     0,
     0,
     0,
     0,
     8,
     4,
     (void (*)(struct Actor *))func_808004CC_chminelight,
     0,
     27,
     0,
     (void (*)(struct Actor *))func_808004D4_chminelight,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     (void (*)(struct Actor *, long, long))func_80800000_chminelight,
     0}};
