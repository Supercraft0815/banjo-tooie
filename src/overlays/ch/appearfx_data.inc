/* data_to_c.py: from asm/data/overlays/ch/appearfx.data.s */
void func_80105834(Actor *);
void func_80107C2C();
AppearImage D_80800970_chappearfx[4] BT_DATA(4, overlays_ch_appearfx, 0x0) = {
    {2531, 0.3f}, {2529, 0.3f}, {2532, 0.3f}, {2537, 0.3f}};
ActorData D_80800990_chappearfx[1] BT_DATA(4, overlays_ch_appearfx, 0x20) = {
    {160,
     985,
     -1,
     1,
     0,
     (void (*)(struct Actor *))func_80800014_chappearfx,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808003A0_chappearfx,
     0,
     0,
     0,
     0,
     2,
     0,
     (void (*)(struct Actor *))func_8080031C_chappearfx,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080000C_chappearfx,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1026,
     (void (*)(struct Actor *, long, long))func_80800360_chappearfx,
     0}};
s16 D_808009D8_chappearfx[9] BT_DATA(4, overlays_ch_appearfx,
                                     0x68) = {0x13, 0x480, 0x18, 0xd, 0xe6, 0x119, 0x2, 0x1b, 0};
