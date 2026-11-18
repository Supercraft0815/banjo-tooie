/* data_to_c.py: from asm/data/overlays/ch/eatopage.data.s */
void func_80105834(Actor *);
void func_80108ED0();
void func_80107C2C();
ActorData D_80800330_chcheatopage[1] BT_DATA(4, overlays_ch_eatopage, 0x0) = {
    {391,
     310,
     2035,
     1,
     0,
     (void (*)(struct Actor *))func_80800070_chcheatopage,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808002A0_chcheatopage,
     0,
     1061997773,
     0,
     0,
     16384,
     4,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_8080000C_chcheatopage,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -31728,
     8208,
     (void (*)(struct Actor *, long, long))func_80800124_chcheatopage,
     0}};
u8 D_80800378_chcheatopage[1] BT_DATA(4, overlays_ch_eatopage, 0x48) = {0x18};
