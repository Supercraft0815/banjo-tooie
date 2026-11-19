/* data_to_c.py: from asm/data/overlays/ch/humba.data.s */
void func_80105834(Actor *);
void func_801018A4();
void func_80107C2C();
void func_80101870();
s16 D_80802590_chhumba[10] BT_DATA(4, overlays_ch_humba, 0x0) = {19,    1033, 10,  256,  22,
                                                                 18000, 1,    500, 5000, 0};
HumbaTables D_808025A4_chhumba BT_DATA(4, overlays_ch_humba, 0x14) = {
    {{{0.0f, 0, 0},     {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0},
      {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0},
      {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0},
      {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0}, {9.0f, 0x111, 0},
      {9.0f, 0x111, 0}},
     {8, 15, 16, 12, 18, 7, 2, 6, 16},
     {4517, 4518, 4520, 4519, 4521, 4523, 4524, 4525, 4535},
     0}};
f32 D_80802684_chhumba[4] BT_DATA(4, overlays_ch_humba, 0xF4) = {1200.0f, 600.0f, 400.0f, 600.0f};
f32 D_80802694_chhumba[3] BT_DATA(4, overlays_ch_humba, 0x104) = {0.0f, 0.0f, 0.0f};
s16 D_808026A0_chhumba[40] BT_DATA(4, overlays_ch_humba, 0x110) = {
    29,  2537, 22, 4352, 46, 255, 0,  350, 305, 359, 450, 27, -150, -300, 7, 1,  21, 0,  204, 43,
    640, 896,  34, 30,   38, 20,  25, 21,  0,   192, 47,  64, 64,   0,    0, 25, 0,  51, 0,   0};
struct HumbaVector D_808026F0_chhumba BT_DATA(4, overlays_ch_humba,
                                              0x160) = {{0.0f, -750.0f, 0.0f}};
f32 D_808026FC_chhumba[4][3] BT_DATA(4, overlays_ch_humba, 0x16C) = {{321.0f, -30.0f, -407.0f},
                                                                     {-354.0f, -30.0f, -407.0f},
                                                                     {-640.0f, -70.0f, 245.0f},
                                                                     {640.0f, -70.0f, 245.0f}};
f32 D_8080272C_chhumba[3] BT_DATA(4, overlays_ch_humba, 0x19C) = {0.0f, 0.0f, 0.0f};
ActorData D_80802738_chhumba BT_DATA(4, overlays_ch_humba, 0x1A8) = {
    513,
    673,
    1653,
    1,
    D_808025A4_chhumba.data.animations,
    (void (*)(struct Actor *))func_808015DC_chhumba,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(long, long))func_801018A4,
    0,
    0,
    0,
    0,
    8,
    1388,
    (void (*)(struct Actor *))func_808021F4_chhumba,
    0,
    0,
    0,
    0,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    2,
    (void (*)(struct Actor *, long, long))func_80800450_chhumba,
    0};
ActorData D_80802780_chhumba BT_DATA(4, overlays_ch_humba, 0x1F0) = {
    344,
    897,
    2084,
    1,
    0,
    0,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(long, long))func_80101870,
    0,
    0,
    0,
    0,
    0,
    7180,
    0,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_80802234_chhumba,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    2050,
    0,
    0};
