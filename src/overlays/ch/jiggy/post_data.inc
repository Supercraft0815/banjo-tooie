/* data_to_c.py: from asm/data/overlays/ch/jiggy/post.data.s */
void func_80102EC0();
void func_80101870();
void func_80107C2C();
ActorData D_80800380_chjiggypost BT_DATA(4, overlays_ch_jiggy_post, 0x0) = {
    344,
    1199,
    2423,
    1,
    0,
    (void (*)(struct Actor *))func_80800068_chjiggypost,
    (void (*)(struct Actor *))func_80102EC0,
    (void (*)(long, long))func_80101870,
    16384000,
    0,
    0,
    0,
    16384,
    2048,
    0,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_8080000C_chjiggypost,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32760,
    9298,
    (void (*)(struct Actor *, long, long))func_808002DC_chjiggypost,
    0};
f32 D_808003C8_chjiggypost[6] BT_DATA(4, overlays_ch_jiggy_post, 0x48) = {260.0f, 175.0f, 175.0f,
                                                                          75.0f,  0.0f,   0.0f};
