/* data_to_c.py: from asm/data/overlays/ch/anemone.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80101870();
void func_80108ED0();
void func_80107C2C();
ActorAnimationEntry D_808008B0_chanemone[5] BT_DATA(4, overlays_ch_anemone,
                                                    0x0) = {{0.0f, 0x0, 0x0},
                                                            {0.800000012f, 0x14e, 0x1},
                                                            {1.5f, 0x14f, 0x2},
                                                            {1.5f, 0x14f, 0x84},
                                                            {2.5999999f, 0x150, 0x2}};
ActorData D_808008D8_chanemone[1] BT_DATA(4, overlays_ch_anemone, 0x28) = {
    {754,
     863,
     1746,
     1,
     (void *)D_808008B0_chanemone,
     (void (*)(struct Actor *))func_8080000C_chanemone,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     294912000,
     0,
     0,
     0,
     0,
     40,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80800260_chanemone,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32720,
     25680,
     (void (*)(struct Actor *, long, long))func_808002E8_chanemone,
     0}};
s16 D_80800920_chanemone[10] BT_DATA(4, overlays_ch_anemone, 0x70) = {19,  1590, 10, 230,   1,
                                                                      800, 2000, 22, 18000, 0};
s16 D_80800934_chanemone[8] BT_DATA(4, overlays_ch_anemone, 0x84) = {19,  1472, 13, 128,
                                                                     153, 24,   0,  0};
s16 D_80800944_chanemone[8] BT_DATA(4, overlays_ch_anemone, 0x94) = {19,  1591, 13, 128,
                                                                     153, 24,   0,  0};
s16 D_80800954_chanemone[8] BT_DATA(4, overlays_ch_anemone, 0xA4) = {19,  1207, 13,    179,
                                                                     204, 22,   28000, 0};
BtFnWord D_80800964_chanemone[4] BT_DATA(4, overlays_ch_anemone,
                                         0xB4) = {0, 0, 0, (BtFnWord)func_80800648_chanemone};
