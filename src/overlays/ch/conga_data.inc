/* data_to_c.py: from asm/data/overlays/ch/conga.data.s */
#include "core2/actor_animation_entry.h"

void func_80101870();
void func_80107C2C();
ActorAnimationEntry D_80800670_chconga[6] BT_DATA(4, overlays_ch_conga, 0x0) = {
    {0.0f, 0x0, 0x0},         {6.69999981f, 0xfe, 0x0},   {6.69999981f, 0xfe, 0x0},
    {6.69999981f, 0xfe, 0x0}, {0.800000012f, 0x3ed, 0x0}, {6.69999981f, 0xfe, 0x0}};
ActorData D_808006A0_chconga[1] BT_DATA(4, overlays_ch_conga, 0x30) = {
    {437,
     819,
     1683,
     1,
     (void *)D_80800670_chconga,
     (void (*)(struct Actor *))func_80800118_chconga,
     (void (*)(struct Actor *))func_80800118_chconga,
     (void (*)(long, long))func_80101870,
     0,
     1077936128,
     0,
     0,
     4,
     288,
     (void (*)(struct Actor *))func_80800280_chconga,
     0,
     20,
     0,
     (void (*)(struct Actor *))func_8080000C_chconga,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1042,
     (void (*)(struct Actor *, long, long))func_808002A0_chconga,
     0}};
f32 D_808006E8_chconga[4] BT_DATA(4, overlays_ch_conga, 0x78) = {343.0f, 343.0f, 343.0f, 171.5f};
subaddiedialog_UnkStruct0 D_808006F8_chconga BT_DATA(4, overlays_ch_conga, 0x88) = {
    0xA1, 0x190, 0, 0, 1, 0x120E, 0, 82, 0, 0xC, 6, 0x3C, 2};
s16 D_80800714_chconga[8] BT_DATA(4, overlays_ch_conga, 0xA4) = {19,  1047, 13,    358,
                                                                 384, 22,   12000, 0};
f32 D_80800724_chconga[7] BT_DATA(4, overlays_ch_conga, 0xB4) = {0.42f, 0.48f, 0.54f, 0.68f,
                                                                 0.75f, 0.81f, -1.0f};
