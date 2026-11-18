/* data_to_c.py: from asm/data/overlays/ch/factory/toxicpools.data.s */
extern u8 D_8011A270[];
void func_80102EC0();
void func_80101870();
void func_80107C2C();
void _chswitch_entrypoint_0();
void func_8010A730();
ActorData D_80800940_chfactorytoxicpools[1] BT_DATA(4, overlays_ch_factory_toxicpools, 0x0) = {
    {835,
     964,
     1985,
     1,
     (void *)D_8011A270,
     (void (*)(struct Actor *))func_808000D0_chfactorytoxicpools,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     16384,
     2056,
     0,
     0,
     0,
     8,
     (void (*)(struct Actor *))func_80800024_chfactorytoxicpools,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     11282,
     (void (*)(struct Actor *, long, long))func_80800190_chfactorytoxicpools,
     0}};
ActorData D_80800988_chfactorytoxicpools[1] BT_DATA(4, overlays_ch_factory_toxicpools, 0x48) = {
    {835,
     965,
     1865,
     1,
     (void *)((u8 *)D_8011A270 + 0x28),
     (void (*)(struct Actor *))func_80800338_chfactorytoxicpools,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     2060,
     0,
     (BtIntPtr)_chswitch_entrypoint_0,
     0,
     8,
     (void (*)(struct Actor *))func_808002B8_chfactorytoxicpools,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     9232,
     (void (*)(struct Actor *, long, long))func_808003DC_chfactorytoxicpools,
     0}};
ActorData D_808009D0_chfactorytoxicpools[1] BT_DATA(4, overlays_ch_factory_toxicpools, 0x90) = {
    {52,
     1074,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_80800670_chfactorytoxicpools,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_8010A730,
     0,
     0,
     0,
     0,
     0,
     4,
     0,
     0,
     228,
     0,
     (void (*)(struct Actor *))func_8080057C_chfactorytoxicpools,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9730,
     0,
     0}};
s16 D_80800A18_chfactorytoxicpools[16] BT_DATA(4, overlays_ch_factory_toxicpools, 0xD8) = {
    19, 1386, 24, 10, 192, 12, 0, 1843, 192, 268, 21, 51, 1868, 128, 20, 0};
s16 D_80800A38_chfactorytoxicpools[30] BT_DATA(4, overlays_ch_factory_toxicpools, 0xF8) = {
    29, 2396, 44, 0,  30,  0,  0,  60,  0,  27, 10, 20,  34,  25, 51,
    12, 25,   21, 51, 204, 11, 20, 120, 20, -5, 43, 460, 563, 0,  0};
s16 D_80800A74_chfactorytoxicpools[30] BT_DATA(4, overlays_ch_factory_toxicpools, 0x134) = {
    29,     2525, 27,  43, 70, 45,  29, 48,  11,  18, 45,  30,  0,   32,  -14593,
    -26715, 22,   512, 21, 51, 179, 43, 514, 616, 34, 204, 307, 460, 563, 0};
s16 D_80800AB0_chfactorytoxicpools[12] BT_DATA(4, overlays_ch_factory_toxicpools, 0x170) = {
    19, 1244, 13, 256, 332, 21, 0, 128, 102, 2, 0, 0};
f32 D_80800AC8_chfactorytoxicpools[3] BT_DATA(4, overlays_ch_factory_toxicpools,
                                              0x188) = {0.0f, -130.0f, 0.0f};
