/* data_to_c.py: from asm/data/overlays/ch/bottles/party.data.s */
void func_80105834(Actor *);
void func_80101870();
void func_80107C2C();
ActorData D_80800410_chbottlesparty[1] BT_DATA(4, overlays_ch_bottles_party, 0x0) = {
    {172,
     1272,
     1921,
     1,
     0,
     (void (*)(struct Actor *))func_8080005C_chbottlesparty,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     2052,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800018_chbottlesparty,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     9218,
     (void (*)(struct Actor *, long, long))func_8080009C_chbottlesparty,
     0}};
ActorData D_80800458_chbottlesparty[1] BT_DATA(4, overlays_ch_bottles_party, 0x48) = {
    {344,
     1273,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_80800330_chbottlesparty,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     4,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800234_chbottlesparty,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9218,
     (void (*)(struct Actor *, long, long))func_808003E4_chbottlesparty,
     0}};
s32 D_808004A0_chbottlesparty[4] BT_DATA(4, overlays_ch_bottles_party, 0x90) = {1132822528, 1132822528,
                                                                                1132822528, 1124433920};
s32 D_808004B0_chbottlesparty[7] BT_DATA(4, overlays_ch_bottles_party,
                                         0xA0) = {108790260, 357433344, 1537, 0, 983040, 786432, 33554432};
s32 D_808004CC_chbottlesparty[4][3] BT_DATA(4, overlays_ch_bottles_party,
                                            0xBC) = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}};
s32 D_808004FC_chbottlesparty[3] BT_DATA(4, overlays_ch_bottles_party, 0xEC) = {32, 32, 32};
f32 D_80800508_chbottlesparty[3][2] BT_DATA(4, overlays_ch_bottles_party,
                                            0xF8) = {{0.0f, 0.0f}, {0.5f, 1.0f}, {1.0f, 0.0f}};
