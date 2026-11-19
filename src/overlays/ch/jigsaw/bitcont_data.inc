/* data_to_c.py: from asm/data/overlays/ch/jigsaw/bitcont.data.s */
void func_80105834(Actor *);
void func_8010A730();
void func_80107C2C();
void func_80101870();
s16 D_808009A0_chjigsawbitcont[4] BT_DATA(4, overlays_ch_jigsaw_bitcont, 0x0) = {19, 1001, 24, 0};
BitConfig D_808009A8_chjigsawbitcont[1] BT_DATA(4, overlays_ch_jigsaw_bitcont,
                                                0x8) = {{17, 3, {0.5f, 2.5f}, 1039, 1040}};
ActorData D_808009B8_chjigsawbitcont[1] BT_DATA(4, overlays_ch_jigsaw_bitcont, 0x18) = {
    {612,
     384,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_80800214_chjigsawbitcont,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8010A730,
     0,
     0,
     0,
     0,
     8,
     4,
     0,
     0,
     40,
     0,
     (void (*)(struct Actor *))func_808002E4_chjigsawbitcont,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     514,
     (void (*)(struct Actor *, long, long))func_80800084_chjigsawbitcont,
     0}};
s16 D_80800A00_chjigsawbitcont[20] BT_DATA(4, overlays_ch_jigsaw_bitcont, 0x60) = {
    29, 2530, 12, 20, 34, 76, 102, 25, 12, 42, 0, 2, 128, 192, 21, 0, 2, 22, 4, 0};
ActorData D_80800A28_chjigsawbitcont[1] BT_DATA(4, overlays_ch_jigsaw_bitcont, 0x88) = {
    {611,
     383,
     1701,
     1,
     0,
     (void (*)(struct Actor *))func_808006D8_chjigsawbitcont,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     98304000,
     1061997773,
     0,
     0,
     0,
     4,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800868_chjigsawbitcont,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     0,
     0}};
