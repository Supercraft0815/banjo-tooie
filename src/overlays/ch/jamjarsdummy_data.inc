/* data_to_c.py: from asm/data/overlays/ch/jamjarsdummy.data.s */
extern u8 D_8080030C_chjamjarsdummy[];
void func_80105834(Actor *);
void func_80107C2C();
u8 D_80800300_chjamjarsdummy[12] BT_DATA(4, overlays_ch_jamjarsdummy, 0x0) = {
    0x40, 0xA0, 0x00, 0x00, 0x40, 0xA0, 0x00, 0x00, 0x40, 0xA0, 0x00, 0x00};
u8 D_8080030C_chjamjarsdummy[32] BT_DATA(4, overlays_ch_jamjarsdummy, 0xC) = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3F, 0xE6, 0x66, 0x66, 0x02, 0x99, 0x00, 0x01, 0x3F, 0x4C, 0xCC, 0xCD, 0x02, 0x14, 0x00, 0x01};
JamjarsAnimation D_8080032C_chjamjarsdummy[3] BT_DATA(4, overlays_ch_jamjarsdummy,
                                                      0x2C) = {{0x7AA, 2}, {0x832, 3}, {0x6FB, 1}};
ActorData D_80800338_chjamjarsdummy[1] BT_DATA(4, overlays_ch_jamjarsdummy, 0x38) = {
    {344,
     183,
     2001,
     1,
     (void *)D_8080030C_chjamjarsdummy,
     (void (*)(struct Actor *))func_808000E0_chjamjarsdummy,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808002AC_chjamjarsdummy,
     0,
     0,
     0,
     0,
     0,
     4,
     (void (*)(struct Actor *))func_80800238_chjamjarsdummy,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800240_chjamjarsdummy,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     0,
     0}};
