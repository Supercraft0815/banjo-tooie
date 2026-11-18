/* data_to_c.py: from asm/data/overlays/ch/trashcangame.data.s */
extern ActorAnimationEntry D_80802FF0_chtrashcangame[];
void func_80105834(Actor *);
void func_80101870();
void func_80108ED0();
void func_80107C2C();
extern u8 D_80803244_chtrashcangame[];
void _chdoor_entrypoint_0();
void _chdoor_entrypoint_1();
ActorAnimationEntry D_80802FF0_chtrashcangame[20] BT_DATA(4, overlays_ch_trashcangame, 0x0) = {
    {0.0f, 0, 0},      {7.21f, 0x369, 1}, {7.21f, 0x369, 1}, {7.21f, 0x369, 1}, {7.21f, 0x369, 1},
    {7.21f, 0x369, 1}, {7.21f, 0x369, 1}, {7.21f, 0x369, 1}, {7.21f, 0x369, 1}, {6.67f, 0x36A, 1},
    {6.67f, 0x36A, 1}, {4.95f, 0x36B, 1}, {4.95f, 0x36B, 1}, {4.95f, 0x36B, 1}, {4.95f, 0x36B, 1},
    {4.95f, 0x36B, 1}, {4.95f, 0x369, 1}, {4.95f, 0x369, 1}, {4.95f, 0x36B, 1}, {4.95f, 0x36B, 1}};
subaddiedialog_UnkStruct0 D_80803090_chtrashcangame BT_DATA(4, overlays_ch_trashcangame, 0xA0) = {
    0x38E, 0x15E, 0x13EE, 0x13EF, 0x400, 0x1208, 0, 106, 0, 0x4E, 0x26, 0x3C, 3};
s32 D_808030AC_chtrashcangame[4] BT_DATA(4, overlays_ch_trashcangame, 0xBC) = {1133903872, 1120403456,
                                                                               1120403456, 1128792064};
Timing4 D_808030BC_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0xCC) = {{0.191f, 0.765f, 0.845f, -1.0f}};
Timing4 D_808030CC_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0xDC) = {{0.22f, 0.801f, 0.886f, -1.0f}};
Timing4 D_808030DC_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0xEC) = {{0.125f, 0.757f, 0.841f, -1.0f}};
Timing4 D_808030EC_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0xFC) = {{0.191f, 0.765f, 0.845f, -1.0f}};
Timing4 D_808030FC_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0x10C) = {{0.22f, 0.801f, 0.886f, -1.0f}};
Timing4 D_8080310C_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0x11C) = {{0.125f, 0.757f, 0.841f, -1.0f}};
Timing4 D_8080311C_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0x12C) = {{0.145f, 0.229f, 0.321f, -1.0f}};
Timing7 D_8080312C_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0x13C) = {{0.182f, 0.265f, 0.359f, 0.405f, 0.628f, 0.713f, -1.0f}};
Timing7 D_80803148_chtrashcangame BT_DATA(4, overlays_ch_trashcangame,
                                          0x158) = {{0.131f, 0.216f, 0.307f, 0.39f, 0.681f, 0.767f, -1.0f}};
struct ColorTable D_80803164_chtrashcangame BT_DATA(4, overlays_ch_trashcangame, 0x174) = {
    {-1.8439942e-25f, -2.4278304e-25f, 2.2176738e+22f, 1.6843753e+22f}};
s32 D_80803174_chtrashcangame[16] BT_DATA(4, overlays_ch_trashcangame, 0x184) = {
    17825821, 165412888, 2,       201330432, 1769572,  13107222, 100663340, 50,
    0,        6553600,   2228275, 3343360,   83886101, 6684800,  2818816,   67108864};
ActorData D_808031B4_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x1C4) = {
    {344,
     1141,
     2056,
     3,
     (void *)D_80802FF0_chtrashcangame,
     (void (*)(struct Actor *))func_80800180_chtrashcangame,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     1065353216,
     0,
     0,
     0,
     265,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9218,
     (void (*)(struct Actor *, long, long))func_8080093C_chtrashcangame,
     0}};
ActorData D_808031FC_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x20C) = {
    {344,
     1308,
     0,
     1,
     0,
     (void (*)(struct Actor *))func_80801D54_chtrashcangame,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     1,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80801CF0_chtrashcangame,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9730,
     (void (*)(struct Actor *, long, long))func_808020D8_chtrashcangame,
     0}};
u8 D_80803244_chtrashcangame[40] BT_DATA(4, overlays_ch_trashcangame, 0x254) = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x03, 0x61,
    0x00, 0x4A, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x61, 0x00, 0x09, 0x40, 0x40, 0x00, 0x00,
    0x03, 0x62, 0x00, 0x4A, 0x3F, 0x00, 0x00, 0x00, 0x03, 0x61, 0x00, 0x92};
s32 D_8080326C_chtrashcangame[21] BT_DATA(4, overlays_ch_trashcangame, 0x27C) = {
    1903048, 1638400, 196635,  -26149164, 2949320, 26214414, 50,       1446912, 2555904, 9830400, 29491235,
    2490389, 786649,  2818304, 33554481,  -655360, 3080448,  16777216, 3342412, 102,     0};
s32 D_808032C0_chtrashcangame[16] BT_DATA(4, overlays_ch_trashcangame, 0x2D0) = {
    17825821, 165281819, -52363864, 917504,  3932195, 1638421, 786662, 1966130,
    3276822,  268435499, 8388864,   3080217, 3342336, 0,       130,    0};
f32 D_80803300_chtrashcangame[9] BT_DATA(4, overlays_ch_trashcangame, 0x310) = {
    0.025f, 0.05f, 0.075f, 0.1f, 0.15f, 0.2f, 0.25f, 0.3f, -1.0f};
s32 D_80803324_chtrashcangame[16] BT_DATA(4, overlays_ch_trashcangame, 0x334) = {
    1902880, 1834108, -39321555, 32768700, 917504,  1310759, 0,        32768500,
    1446914, 2293849, 2818432,   33554436, 6684679, 196657,  -1310700, 0};
s32 D_80803364_chtrashcangame[12] BT_DATA(4, overlays_ch_trashcangame, 0x374) = {
    101711901, 165281819, -65471364, 2949620, 39321614, 20, 1445888, 2293785, 2818432, 33554481, -3276750, 0};
f32 D_80803394_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x3A4) = {-2.1270897e-07f};
f32 D_80803398_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x3A8) = {2.6621532e+22f};
f32 D_8080339C_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x3AC) = {1.6875599e+22f};
ActorData D_808033A0_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x3B0) = {
    {290,
     1142,
     2054,
     1,
     (void *)D_80803244_chtrashcangame,
     (void (*)(struct Actor *))func_8080223C_chtrashcangame,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     13,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_808021BC_chtrashcangame,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32736,
     4096,
     (void (*)(struct Actor *, long, long))func_8080292C_chtrashcangame,
     0}};
ActorData D_808033E8_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x3F8) = {
    {344,
     1294,
     2258,
     1,
     0,
     (void (*)(struct Actor *))func_80802C40_chtrashcangame,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     2,
     3072,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9216,
     0,
     0}};
ActorData D_80803430_chtrashcangame[1] BT_DATA(4, overlays_ch_trashcangame, 0x440) = {
    {172,
     1331,
     2252,
     4,
     0,
     (void (*)(struct Actor *))_chdoor_entrypoint_0,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     0,
     0,
     0,
     0,
     0,
     2048,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80802CC0_chtrashcangame,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     9218,
     (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1,
     0}};
