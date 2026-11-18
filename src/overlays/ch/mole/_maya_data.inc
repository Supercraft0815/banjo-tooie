/* data_to_c.py: from asm/data/overlays/ch/mole/_maya.data.s */
void func_8010A730();
#ifndef BT_NATIVE
void func_80107C2C();
#endif
void func_80105834(Actor *);
MoveData D_808001E0_chmole_maya[3] BT_DATA(4, overlays_ch_mole__maya, 0x0) = {
    {1, 0xD44, 3394, 0xD43, 20, 0xFF, 0x23, 0xE, 0},
    {1, 0xD47, 3397, 0xD46, 21, 0xFF, 0x1E, 0xF, 0},
    {1, 0xD4A, 3400, 0xD49, 22, 0xFF, 0x19, 0x10, 0}};
ActorData D_80800210_chmole_maya BT_DATA(4, overlays_ch_mole__maya, 0x30) = {
    746,
    423,
    0,
    1,
    0,
    (void (*)(struct Actor *))func_80800090_chmole_maya,
    0,
    (void (*)(long, long))func_8010A730,
    32768000,
    0,
    0,
    0,
    8,
    4,
    0,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_80800024_chmole_maya,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    8706,
    (void (*)(struct Actor *, long, long))func_80800000_chmole_maya,
    0};
ActorData D_80800258_chmole_maya[1] BT_DATA(4, overlays_ch_mole__maya, 0x78) = {
    {344,
     779,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_808000C0_chmole_maya,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8010A730,
     327680000,
     0,
     0,
     0,
     8,
     5,
     (void (*)(struct Actor *))func_80800144_chmole_maya,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080014C_chmole_maya,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     (void (*)(struct Actor *, long, long))func_80800180_chmole_maya,
     0}};
