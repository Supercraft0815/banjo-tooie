/* data_to_c.py: from asm/data/overlays/ch/factory/magnet.data.s */
void func_80105834(Actor *);
void func_80107C2C();
void func_80101870(Actor *, void *);
void func_801018A4();
f32 D_80802910_chfactorymagnet[3] BT_DATA(4, overlays_ch_factory_magnet, 0x0) = {-250.0f, 0.0f,
                                                                                 -1100.0f};
struct MagnetStartData D_8080291C_chfactorymagnet BT_DATA(4, overlays_ch_factory_magnet, 0xC) = {
    {{0.0f, 0.0f, 0.0f}}, {19, 1320, 10, 192, 0, 0}};
s16 D_80802934_chfactorymagnet[6] BT_DATA(4, overlays_ch_factory_magnet, 0x24) = {19,  1184, 10,
                                                                                  153, 0,    0};
s16 D_80802940_chfactorymagnet[6] BT_DATA(4, overlays_ch_factory_magnet, 0x30) = {19,  1215, 10,
                                                                                  307, 0,    0};
s16 D_8080294C_chfactorymagnet[4] BT_DATA(4, overlays_ch_factory_magnet, 0x3C) = {19, 0x4C7, 0, 0};
s16 D_80802954_chfactorymagnet[28] BT_DATA(4, overlays_ch_factory_magnet, 0x44) = {
    29, 2505, 43, 512, 768, 34, 512, 640, 1536, 2048, 21,    0,     51, 25,
    0,  7,    44, -20, 20,  20, 20,  40,  20,   32,   24672, 24704, 0,  0};
f32 D_8080298C_chfactorymagnet[3] BT_DATA(4, overlays_ch_factory_magnet, 0x7C) = {-250.0f, 150.0f,
                                                                                  -1700.0f};
f32 D_80802998_chfactorymagnet[3] BT_DATA(4, overlays_ch_factory_magnet, 0x88) = {-250.0f, 150.0f,
                                                                                  -1100.0f};
struct MagnetVector D_808029A4_chfactorymagnet BT_DATA(4, overlays_ch_factory_magnet,
                                                       0x94) = {{-400.0f, 200.0f, -700.0f}};
struct MagnetVector D_808029B0_chfactorymagnet BT_DATA(4, overlays_ch_factory_magnet,
                                                       0xA0) = {{-75.0f, 200.0f, -700.0f}};
s16 D_808029BC_chfactorymagnet[36] BT_DATA(4, overlays_ch_factory_magnet, 0xAC) = {
    29, 2520, 27,  -2000, -1500, 22, 2, 39, -500, -500,  500, 500, 36,  102, 102, 21,  0, 192,
    43, 512,  640, 4,     128,   7,  4, 3,  1577, 24000, 8,   332, 358, 5,   30,  282, 0, 0};
ActorData D_80802A04_chfactorymagnet[1] BT_DATA(4, overlays_ch_factory_magnet, 0xF4) = {
    {344,
     1013,
     1802,
     1,
     0,
     (void (*)(struct Actor *))func_80800224_chfactorymagnet,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80800EF0_chfactorymagnet,
     0,
     0,
     0,
     0,
     8320,
     3136,
     (void (*)(struct Actor *))func_80801E84_chfactorymagnet,
     0,
     0,
     848,
     (void (*)(struct Actor *))func_80800000_chfactorymagnet,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     1026,
     (void (*)(struct Actor *, long, long))func_80800B20_chfactorymagnet,
     0}};
ActorData D_80802A4C_chfactorymagnet[1] BT_DATA(4, overlays_ch_factory_magnet, 0x13C) = {
    {344,
     1014,
     1803,
     1,
     0,
     (void (*)(struct Actor *))func_80801EBC_chfactorymagnet,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     8320,
     10244,
     0,
     0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     2,
     0,
     0}};
s16 D_80802A94_chfactorymagnet[8] BT_DATA(4, overlays_ch_factory_magnet,
                                          0x184) = {19, 1558, 22, 32000, 10, 256, 0, 0};
s16 D_80802AA4_chfactorymagnet[8] BT_DATA(4, overlays_ch_factory_magnet,
                                          0x194) = {19, 1326, 22, 25000, 10, 256, 0, 0};
ActorData D_80802AB4_chfactorymagnet[1] BT_DATA(4, overlays_ch_factory_magnet, 0x1A4) = {
    {344,
     1295,
     2190,
     1,
     0,
     (void (*)(struct Actor *))func_80801FB8_chfactorymagnet,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     262144000,
     0,
     0,
     0,
     2,
     4100,
     0,
     0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     (void (*)(struct Actor *, long, long))func_808022D8_chfactorymagnet,
     0}};
s16 D_80802AFC_chfactorymagnet[42] BT_DATA(4, overlays_ch_factory_magnet, 0x1EC) = {
    29, 2509, 24, 0,  1,  3840, 7680, 27, -700, -600, 45, 353,  657, 14,
    0,  25,   34, 25, 38, 12,   25,   21, 0,    230,  43, 179,  307, 47,
    0,  153,  0,  0,  0,  0,    87,   49, -30,  -30,  22, 4096, 0,   0};
f32 D_80802B50_chfactorymagnet[2] BT_DATA(4, overlays_ch_factory_magnet, 0x240) = {200.0f, 300.0f};
s16 D_80802B58_chfactorymagnet[8] BT_DATA(4, overlays_ch_factory_magnet,
                                          0x248) = {19, 1326, 13, 217, 294, 22, 22000, 0};
ActorData D_80802B68_chfactorymagnet[1] BT_DATA(4, overlays_ch_factory_magnet, 0x258) = {
    {344,
     1327,
     2361,
     1,
     0,
     (void (*)(struct Actor *))func_80802390_chfactorymagnet,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     0,
     0,
     0,
     0,
     2,
     0,
     (void (*)(struct Actor *))func_8080281C_chfactorymagnet,
     0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32704,
     1026,
     (void (*)(struct Actor *, long, long))func_808025B4_chfactorymagnet,
     0}};
