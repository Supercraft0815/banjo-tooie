/* data_to_c.py: from asm/data/overlays/ch/toxicroombits.data.s */
void func_80105834(Actor *);
void func_80108ED0();
void func_80107C2C();
Vec3f D_80800F00_chtoxicroombits BT_DATA(4, overlays_ch_toxicroombits,
                                         0x0) = {{-400.0f, 400.0f, 2000.0f}};
s16 D_80800F0C_chtoxicroombits[36] BT_DATA(4, overlays_ch_toxicroombits, 0xC) = {
    29, 2525, 43, 2048, 3072, 34, 512,    640,    2048, 2560, 21,  12,  153, 25, 0,  7,  44, 0,
    0,  -200, 0,  100,  -100, 32, -24416, -24448, 10,   -20,  -50, -20, 20,  50, 20, 22, 4,  0};
s16 D_80800F54_chtoxicroombits[38] BT_DATA(4, overlays_ch_toxicroombits, 0x54) = {
    29,   2525, 43,  1280, 1792, 34,  512,  640,   5120, 7680, 21,  12,  153, 25, 0,  7,  44, 0, 0,
    -200, 0,    100, -100, 31,   255, 2560, 20482, 10,   -20,  -50, -20, 20,  50, 20, 22, 4,  0, 0};
s16 D_80800FA0_chtoxicroombits[8] BT_DATA(4, overlays_ch_toxicroombits,
                                          0xA0) = {19, 1184, 22, 28000, 1, 200, 6000, 0};
ToxicRoomData D_80800FB0_chtoxicroombits BT_DATA(4, overlays_ch_toxicroombits, 0xB0) = {
    {270,
     1002,
     2180,
     1,
     0,
     0,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808001D4_chtoxicroombits,
     0,
     0,
     0,
     0,
     8320,
     68,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2048,
     (void (*)(struct Actor *, long, long))func_80800000_chtoxicroombits,
     0},
    {{4, 0x4B}, {3, 0x44}, {2, 0x3D}, {2, 0x36}, {1, 0x2F}, {1, 0x28}},
    {19, 1319, 1, 1000, 4000, 0}};
Vec3f D_80801010_chtoxicroombits BT_DATA(4, overlays_ch_toxicroombits,
                                         0x110) = {{-400.0f, 395.0f, -2000.0f}};
Vec3f D_8080101C_chtoxicroombits BT_DATA(4, overlays_ch_toxicroombits,
                                         0x11C) = {{0.0f, 0.0f, 0.0f}};
f32 D_80801028_chtoxicroombits[3] BT_DATA(4, overlays_ch_toxicroombits, 0x128) = {-400.0f, 397.0f,
                                                                                  2000.0f};
ActorData D_80801034_chtoxicroombits[1] BT_DATA(4, overlays_ch_toxicroombits, 0x134) = {
    {344,
     1003,
     -1,
     1,
     0,
     (void (*)(struct Actor *))func_80800630_chtoxicroombits,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80800A2C_chtoxicroombits,
     0,
     0,
     0,
     0,
     0,
     3072,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800540_chtoxicroombits,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1026,
     (void (*)(struct Actor *, long, long))func_80800CB0_chtoxicroombits,
     0}};
