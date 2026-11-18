/* data_to_c.py: from asm/data/overlays/ch/mrsicecube.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80108ED0();
void func_80107C2C();
subaddiedialog_UnkStruct1 D_808008F0_chmrsicecube[4] BT_DATA(4, overlays_ch_mrsicecube, 0x0) = {
    {0x401, 4716, 1, 0}, {0x601, 4717, 2, 0}, {0x200, 4824, 1, 0}, {0xFFFEDFFF, 4619, 3, 0}};
u16 D_80800910_chmrsicecube[17][2] BT_DATA(4, overlays_ch_mrsicecube, 0x20) = {
    {0x1F4, 0x1E}, {0x229, 3},    {0x136, 0x1E}, {0x4A6, 6},    {0x1C9, 0x15}, {0x1CA, 0x16},
    {0x1CB, 0x16}, {0x1CC, 0x17}, {0x1CE, 0x16}, {0x1CF, 0x16}, {0x1D7, 0x1E}, {0x211, 6},
    {0x19C, 0},    {0x1D8, 0x1E}, {0x1E9, 6},    {0x210, 1},    {0x2B0, 1}};
ActorAnimationEntry D_80800954_chmrsicecube[9] BT_DATA(4, overlays_ch_mrsicecube, 0x64) = {
    {0.0f, 0x0, 0x0},           {1.29999995f, 0x4a8, 0x44}, {1.29999995f, 0x4a8, 0x44},
    {1.29999995f, 0x4a8, 0x2},  {1.29999995f, 0x4a9, 0x1},  {1.29999995f, 0x4a8, 0x92},
    {1.29999995f, 0x4a8, 0x44}, {1.29999995f, 0x4a8, 0x2},  {1.29999995f, 0x4a9, 0x1}};
ActorData D_8080099C_chmrsicecube[1] BT_DATA(4, overlays_ch_mrsicecube, 0xAC) = {
    {167,
     993,
     2326,
     2,
     (void *)D_80800954_chmrsicecube,
     (void (*)(struct Actor *))func_808000BC_chmrsicecube,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808003BC_chmrsicecube,
     65536000,
     0,
     0,
     0,
     0,
     2336,
     0,
     (BtIntPtr)func_80108ED0,
     12,
     0,
     (void (*)(struct Actor *))func_80800018_chmrsicecube,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32640,
     25602,
     (void (*)(struct Actor *, long, long))func_80800260_chmrsicecube,
     0}};
ActorData D_808009E4_chmrsicecube[1] BT_DATA(4, overlays_ch_mrsicecube, 0xF4) = {
    {168,
     994,
     1964,
     1,
     0,
     (void (*)(struct Actor *))func_808000BC_chmrsicecube,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808003BC_chmrsicecube,
     0,
     0,
     0,
     0,
     0,
     2176,
     0,
     (BtIntPtr)func_80108ED0,
     12,
     0,
     (void (*)(struct Actor *))func_80800018_chmrsicecube,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32640,
     10240,
     (void (*)(struct Actor *, long, long))func_80800260_chmrsicecube,
     0}};
f32 D_80800A2C_chmrsicecube[4] BT_DATA(4, overlays_ch_mrsicecube, 0x13C) = {480.0f, 300.0f, 284.0f,
                                                                            120.0f};
s32 D_80800A3C_chmrsicecube[2] BT_DATA(4, overlays_ch_mrsicecube, 0x14C) = {-1, -1};
subaddiedialog_UnkStruct2 D_80800A44_chmrsicecube BT_DATA(4, overlays_ch_mrsicecube, 0x154) = {
    0x1C5, 0, 0x258, 167, 0, 0xC, 0, 0, 3};
s16 D_80800A54_chmrsicecube[8] BT_DATA(4, overlays_ch_mrsicecube, 0x164) = {19,  1176, 24, 10,
                                                                            422, 32,   0,  0};
s16 D_80800A64_chmrsicecube[8] BT_DATA(4, overlays_ch_mrsicecube, 0x174) = {19,  1165, 24, 13,
                                                                            307, 332,  0,  0};
s16 D_80800A74_chmrsicecube[34] BT_DATA(4, overlays_ch_mrsicecube, 0x184) = {
    29,   1886, 22,  5510, 43,  640, 768, 39, 200, 200, 400, 400, 45, 500, 600, 27,  -1000,
    -800, 34,   640, 1024, 256, 384, 21,  0,  204, 14,  80,  120, 7,  2,   4,   102, 0};
s16 D_80800AB8_chmrsicecube[6] BT_DATA(4, overlays_ch_mrsicecube, 0x1C8) = {19,  1151, 13,
                                                                            243, 268,  0};
