/* data_to_c.py: from asm/data/overlays/ch/secreteggs.data.s */
void func_80105834(Actor *);
void func_80108ED0();
void func_80107C2C();
ActorAnimationEntry D_80800490_chsecreteggs[3] BT_DATA(4, overlays_ch_secreteggs, 0x0) = {
    {0.0f, 0, 0}, {5.5f, 0x1D4, 9}, {1.5f, 0x1D5, 0x4A}};
s16 D_808004A8_chsecreteggs[34] BT_DATA(4, overlays_ch_secreteggs, 0x18) = {
    27, -800, -600, 45, 450, 650, 13, 60,   22,   4098, 39,  0, 300, 0,  600,  34,   76,
    76, 0,    179,  21, 12,  217, 43, 1024, 1280, 4,    179, 7, 4,   49, -150, -150, 0};
f32 D_808004EC_chsecreteggs[5] BT_DATA(4, overlays_ch_secreteggs, 0x5C) = {0.0f, 0.08f, 0.38f,
                                                                           0.45f, -1.0f};
f32 D_80800500_chsecreteggs[3] BT_DATA(4, overlays_ch_secreteggs, 0x70) = {0.78f, 0.84f, -1.0f};
ActorData D_8080050C_chsecreteggs BT_DATA(4, overlays_ch_secreteggs, 0x7C) = {
    344,
    1303,
    2422,
    1,
    D_80800490_chsecreteggs,
    (void (*)(struct Actor *))func_80800118_chsecreteggs,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(long, long))func_801018A4,
    131072000,
    1065353216,
    0,
    0,
    0,
    2056,
    0,
    (BtIntPtr)func_80108ED0,
    0,
    0,
    (void (*)(struct Actor *))func_808000C0_chsecreteggs,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    1026,
    (void (*)(struct Actor *, long, long))func_80800328_chsecreteggs,
    0};
