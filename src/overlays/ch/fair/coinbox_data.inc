/* data_to_c.py: from asm/data/overlays/ch/fair/coinbox.data.s */
void func_80101870();
void func_80107C2C();
s32 D_80800470_chfaircoinbox[3][2] BT_DATA(4, overlays_ch_fair_coinbox,
                                           0x0) = {{1685, 164}, {1686, 165}, {1687, 166}};
s16 D_80800488_chfaircoinbox[3] BT_DATA(4, overlays_ch_fair_coinbox, 0x18) = {2531, 2532, 2533};
DialogRecord D_80800490_chfaircoinbox BT_DATA(4, overlays_ch_fair_coinbox, 0x20) = {
    0, 0x12C, 0, 0, 0x8000, 0x10B4, 0x9E1, 140, 0, 6, 7, 0x32, 0};
s32 D_808004AC_chfaircoinbox[3] BT_DATA(4, overlays_ch_fair_coinbox, 0x3C) = {4277, 4278, 4279};
f32 D_808004B8_chfaircoinbox[4] BT_DATA(4, overlays_ch_fair_coinbox, 0x48) = {40.0f, 50.0f, 40.0f,
                                                                              0.0f};
ActorData D_808004C8_chfaircoinbox[1] BT_DATA(4, overlays_ch_fair_coinbox, 0x58) = {
    {631,
     357,
     2003,
     1,
     0,
     (void (*)(struct Actor *))func_808001C8_chfaircoinbox,
     0,
     (void (*)(long, long))func_80101870,
     39321600,
     0,
     0,
     0,
     16384,
     0,
     (void (*)(struct Actor *))func_8080016C_chfaircoinbox,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800174_chfaircoinbox,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     1042,
     (void (*)(struct Actor *, long, long))func_808003C4_chfaircoinbox,
     0}};
