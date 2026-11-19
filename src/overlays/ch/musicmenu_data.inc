/* data_to_c.py: from asm/data/overlays/ch/musicmenu.data.s */
#include "core2/actor_animation_entry.h"
void func_80105834(Actor *);
void func_80107C2C();
s32 func_80101870(void *, BtIntPtr);

s16 D_808012A0_chmusicmenu[48] BT_DATA(4, overlays_ch_musicmenu, 0x0) = {
    50, 51, 85, 57, 56, 62, 66,  72, 64, 73, 71,  76,  69,  75,  79,  80,
    83, 59, 82, 78, 63, 99, 65,  86, 87, 97, 118, 117, 126, 130, 122, 88,
    89, 90, 91, 92, 93, 98, 127, 94, 95, 31, 32,  101, 102, 100, 84,  154};
struct MusicMenuTrack D_80801300_chmusicmenu[5] BT_DATA(4, overlays_ch_musicmenu, 0x60) = {
    {50, 0, 1}, {50, 0xFF, 1}, {50, 0, 2}, {51, 0, -1}, {85, 0, -1}};
struct MusicMenuTrack D_80801314_chmusicmenu[6] BT_DATA(4, overlays_ch_musicmenu, 0x74) = {
    {57, 0, 3}, {57, 1, 3}, {57, 0, 8}, {57, 0, 5}, {57, 0, 6}, {56, 0, -1}};
struct MusicMenuTrack D_8080132C_chmusicmenu[7] BT_DATA(4, overlays_ch_musicmenu, 0x8C) = {
    {62, 0, 11}, {62, 1, 11}, {62, 0, 12}, {62, 0, 17}, {62, 0, 13}, {66, 0, -1}, {72, 0, -1}};
struct MusicMenuTrack D_80801348_chmusicmenu[7] BT_DATA(4, overlays_ch_musicmenu, 0xA8) = {
    {64, 0, 19}, {64, 0, 20}, {64, 0, 21}, {64, 0, 22}, {73, 0, -1}, {71, 0, -1}, {76, 0, -1}};
struct MusicMenuTrack D_80801364_chmusicmenu[11] BT_DATA(4, overlays_ch_musicmenu, 0xC4) = {
    {69, 0, 29}, {69, 1, 29}, {69, 0, 31}, {75, 1, 34}, {75, 0, 32}, {75, 1, 35},
    {75, 0, 37}, {79, 0, -1}, {80, 0, -1}, {83, 0, -1}, {59, 0, -1}};
struct MusicMenuTrack D_80801390_chmusicmenu[4] BT_DATA(4, overlays_ch_musicmenu, 0xF0) = {
    {82, 0, 38}, {82, 1, 38}, {82, 0, 39}, {78, 0, -1}};
struct MusicMenuTrack D_808013A0_chmusicmenu[4] BT_DATA(4, overlays_ch_musicmenu, 0x100) = {
    {63, 0, 41}, {63, 0, 42}, {63, 0, 43}, {99, 0, -1}};
struct MusicMenuTrack D_808013B0_chmusicmenu[6] BT_DATA(4, overlays_ch_musicmenu, 0x110) = {
    {65, 0, 44}, {65, 1, 44}, {65, 0, 45}, {65, 0, 47}, {65, 0, 48}, {86, 0, -1}};
struct MusicMenuTrack D_808013C8_chmusicmenu[8] BT_DATA(4, overlays_ch_musicmenu, 0x128) = {
    {87, 0, 50}, {87, 1, 50}, {87, 0, 51},  {87, 0, 52},
    {87, 0, 53}, {87, 0, 54}, {118, 0, -1}, {97, 0, -1}};
struct MusicMenuTrack D_808013E8_chmusicmenu[5] BT_DATA(4, overlays_ch_musicmenu, 0x148) = {
    {117, 0, 57}, {117, 0, 58}, {126, 0, -1}, {130, 0, -1}, {122, 0, -1}};
struct MusicMenuTrack D_808013FC_chmusicmenu[23] BT_DATA(4, overlays_ch_musicmenu, 0x15C) = {
    {88, 0, 59},  {88, 1, 59},  {88, 0, 60}, {88, 0, 61}, {88, 0, 62}, {88, 0, 63},
    {88, 0, 65},  {88, 0, 67},  {88, 0, 64}, {88, 0, 66}, {88, 0, 68}, {89, 0, 55},
    {89, 0, 56},  {90, 0, -1},  {91, 0, -1}, {92, 0, -1}, {93, 0, -1}, {98, 0, -1},
    {154, 0, -1}, {127, 0, -1}, {95, 0, -1}, {94, 0, -1}, {131, 0, -1}};
struct MusicMenuTrack D_80801458_chmusicmenu[9] BT_DATA(4, overlays_ch_musicmenu, 0x1B8) = {
    {125, 0, -1}, {103, 0, -1}, {36, 0, -1},  {31, 0, -1}, {32, 0, -1},
    {101, 0, -1}, {102, 0, -1}, {100, 0, -1}, {84, 0, -1}};
ActorAnimationEntry D_8080147C_chmusicmenu[15] BT_DATA(4, overlays_ch_musicmenu, 0x1DC) = {
    {0.0f, 0x0, 0x0},          {3.5f, 0x1b6, 0x1},         {3.20000005f, 0x2f, 0x1},
    {1.0f, 0x85, 0x1},         {0.75f, 0x8f, 0x1},         {1.0f, 0x157, 0x1},
    {1.35000002f, 0x15a, 0x1}, {4.1500001f, 0x16c, 0x101}, {2.0f, 0x16d, 0x1},
    {4.0f, 0x17b, 0x101},      {4.69999981f, 0x189, 0x1},  {5.0f, 0x1e7, 0x1},
    {3.25f, 0x2d3, 0x1},       {1.5f, 0x2fa, 0x1},         {5.5f, 0x32c, 0x1}};
struct MusicMenuEntry D_808014F4_chmusicmenu[12] BT_DATA(4, overlays_ch_musicmenu, 0x254) = {
    {D_80801300_chmusicmenu, 5, 0xF, 0},     {D_80801314_chmusicmenu, 6, 0x31, 0},
    {D_8080132C_chmusicmenu, 7, 0x3F, 0},    {D_80801348_chmusicmenu, 7, 0x50, 0},
    {D_80801364_chmusicmenu, 0xB, 0x6E, 0},  {D_80801390_chmusicmenu, 4, 0xA6, 0},
    {D_808013A0_chmusicmenu, 4, 0xAD, 0},    {D_808013B0_chmusicmenu, 6, 0xA8, 0},
    {D_808013C8_chmusicmenu, 8, 0x69, 0},    {D_808013E8_chmusicmenu, 5, 0x22, 0},
    {D_808013FC_chmusicmenu, 0x17, 0x7E, 0}, {D_80801458_chmusicmenu, 9, 0x6F, 0}};
struct MusicMenuColor D_80801554_chmusicmenu BT_DATA(4, overlays_ch_musicmenu,
                                                     0x2B4) = {{255, 255, 255}};
struct MusicMenuColor D_8080155C_chmusicmenu BT_DATA(4, overlays_ch_musicmenu, 0x2BC) = {{0, 0, 100}};
f32 D_80801564_chmusicmenu[2][3] BT_DATA(4, overlays_ch_musicmenu, 0x2C4) = {
    {-500.0f, 0.0f, -2000.0f}, {-320.0f, 250.0f, -1650.0f}
};
ActorData D_8080157C_chmusicmenu BT_DATA(4, overlays_ch_musicmenu, 0x2DC) = {
    344,
    421,
    2460,
    6,
    0,
    (void (*)(struct Actor *))func_80800DA4_chmusicmenu,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(long, long))func_80800F98_chmusicmenu,
    0,
    0,
    0,
    0,
    0,
    3073,
    (void (*)(struct Actor *))func_80800F50_chmusicmenu,
    0,
    0,
    0,
    (void (*)(struct Actor *))func_80800CBC_chmusicmenu,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    9218,
    (void (*)(struct Actor *, long, long))func_80801040_chmusicmenu,
    0};
ActorData D_808015C4_chmusicmenu BT_DATA(4, overlays_ch_musicmenu, 0x324) = {
    344,
    1329,
    2467,
    1,
    0,
    0,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(long, long))func_80101870,
    0,
    0,
    0,
    0,
    0,
    6152,
    0,
    0,
    0,
    0,
    0,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32768,
    11266,
    0,
    0};
ActorData D_8080160C_chmusicmenu BT_DATA(4, overlays_ch_musicmenu, 0x36C) = {
    344,
    1332,
    1750,
    1,
    D_8080147C_chmusicmenu,
    0,
    (void (*)(struct Actor *))func_80105834,
    (void (*)(long, long))func_80101870,
    0,
    1067030938,
    0,
    0,
    0,
    256,
    0,
    0,
    0,
    0,
    0,
    (void (*)(void *, long, void *, long, void *))func_80107C2C,
    -32256,
    11522,
    (void (*)(struct Actor *, long, long))func_808010C4_chmusicmenu,
    0};
