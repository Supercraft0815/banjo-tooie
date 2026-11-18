/* data_to_c.py: from asm/data/overlays/ch/biggafoot.data.s */
extern u8 D_8080103C_chbiggafoot[];
void func_80105834(Actor *);
void func_801018A4();
void func_80108ED0();
void func_80107C2C();
void func_80101870();
s16 D_80801030_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x0) = {128, 129, 130, 131};
u8 D_80801038_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x8) = {0x40, 0x80, 0xC0, 0xFF};
u8 D_8080103C_chbiggafoot[88] BT_DATA(4, overlays_ch_biggafoot, 0xC) = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x48, 0xA3, 0xD7, 0x03, 0x89, 0x00,
    0x01, 0x41, 0x48, 0xA3, 0xD7, 0x03, 0x89, 0x00, 0x01, 0x3F, 0x94, 0x7A, 0xE1, 0x03, 0x8A,
    0x00, 0x02, 0x41, 0x48, 0xA3, 0xD7, 0x03, 0x89, 0x00, 0x01, 0x40, 0x65, 0x4F, 0xDF, 0x03,
    0x8B, 0x00, 0x02, 0x40, 0x65, 0x4F, 0xDF, 0x03, 0x8B, 0x00, 0x02, 0x3F, 0x40, 0x00, 0x00,
    0x03, 0x8C, 0x00, 0x01, 0x3F, 0x40, 0x00, 0x00, 0x03, 0x8C, 0x00, 0x01, 0x3F, 0x40, 0x00,
    0x00, 0x03, 0x8C, 0x00, 0x01, 0x41, 0x48, 0xA3, 0xD7, 0x03, 0x89, 0x04, 0x01};
ActorData D_80801094_chbiggafoot[1] BT_DATA(4, overlays_ch_biggafoot, 0x64) = {
    {171,
     998,
     2078,
     1,
     (void *)D_8080103C_chbiggafoot,
     (void (*)(struct Actor *))func_80800100_chbiggafoot,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     131072000,
     1070386381,
     0,
     0,
     388,
     288,
     (void (*)(struct Actor *))func_808004B0_chbiggafoot,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80800018_chbiggafoot,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     29698,
     (void (*)(struct Actor *, long, long))func_808004D4_chbiggafoot,
     0}};
ActorData D_808010DC_chbiggafoot[1] BT_DATA(4, overlays_ch_biggafoot, 0xAC) = {
    {344,
     1102,
     2068,
     1,
     0,
     (void (*)(struct Actor *))func_80800D5C_chbiggafoot,
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
     (void (*)(struct Actor *))func_80800D38_chbiggafoot,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     (void (*)(struct Actor *, long, long))func_80800E2C_chbiggafoot,
     0}};
u8 D_80801124_chbiggafoot[24] BT_DATA(4, overlays_ch_biggafoot, 0xF4) = {
    0, 0, 0, 0, 0, 0, 0, 0, 0x3F, 0, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0, 0, 0, 0, 0};
f32 D_8080113C_chbiggafoot[3] BT_DATA(4, overlays_ch_biggafoot, 0x10C) = {-400.0f, -100.0f, -200.0f};
f32 D_80801148_chbiggafoot[3] BT_DATA(4, overlays_ch_biggafoot, 0x118) = {400.0f, 500.0f, 300.0f};
f32 D_80801154_chbiggafoot[2] BT_DATA(4, overlays_ch_biggafoot, 0x124) = {0.04f, 0.2f};
s32 D_8080115C_chbiggafoot[5] BT_DATA(4, overlays_ch_biggafoot, 0x12C) = {1246721, 655577, 1572865, 65541000,
                                                                          0};
s32 D_80801170_chbiggafoot[6] BT_DATA(4, overlays_ch_biggafoot, 0x140) = {1246231,    852236,   19267606,
                                                                          1703936001, 52433800, 0};
s32 D_80801188_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x158) = {1125056512, 1126367232, 1126367232,
                                                                          1117978624};
s32 D_80801198_chbiggafoot[7] BT_DATA(4, overlays_ch_biggafoot, 0x168) = {
    29819280, 309269104, 513, 302514176, 11010048, 788028, 33554432};
u32 D_808011B4_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x184) = {0x1305EC, 0xD0066, 0x800018, 0};
u32 D_808011C4_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x194) = {0x13049C, 0xD00F3, 0x10C0016,
                                                                          0x2EE00000};
u32 D_808011D4_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x1A4) = {0x1305BB, 0xD00F3, 0x10C0016,
                                                                          0x6D600000};
u32 D_808011E4_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x1B4) = {0x3EB33333, 0x3ECCCCCD, 0x3EEB851F,
                                                                          0xBF800000};
u32 D_808011F4_chbiggafoot[3] BT_DATA(4, overlays_ch_biggafoot, 0x1C4) = {0x3F000000, 0x3F19999A, 0xBF800000};
u32 D_80801200_chbiggafoot BT_DATA(4, overlays_ch_biggafoot, 0x1D0) = 0x1304BE;
u8 D_80801200_chbiggafoot__gap[4] BT_DATA(4, overlays_ch_biggafoot, 0x1D4) = {0};
u32 D_80801208_chbiggafoot[4] BT_DATA(4, overlays_ch_biggafoot, 0x1D8) = {0x13061A, 0x167530, 0xA00CC, 0};
u32 D_80801218_chbiggafoot[3] BT_DATA(4, overlays_ch_biggafoot, 0x1E8) = {0x1305EC, 0xD00C0, 0xD90000};
s32 D_80801224_chbiggafoot[5] BT_DATA(4, overlays_ch_biggafoot, 0x1F4) = {1246746, 17170456, 655564, 196610,
                                                                          0};
u8 D_80801238_chbiggafoot[12] BT_DATA(4, overlays_ch_biggafoot, 0x208) = {0, 0x13, 4, 0x8D, 0, 0xA,
                                                                          0, 0xD9, 0, 2,    0, 0};
s32 D_80801244_chbiggafoot[11] BT_DATA(4, overlays_ch_biggafoot, 0x214) = {
    1903069, 1446400, 1376256, 4980770, 26804736, 20119961, 1769772, 39321623, 8388608, 0, 0};
