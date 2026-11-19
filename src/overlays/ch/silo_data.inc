/* data_to_c.py: from asm/data/overlays/ch/silo.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80108ED0();
void func_80107C2C();
s16 D_808012C0_chsilo[8] BT_DATA(4, overlays_ch_silo, 0x0) = {19, 1308, 10, 204, 22, 28000, 0, 0};
s16 D_808012D0_chsilo[8] BT_DATA(4, overlays_ch_silo, 0x10) = {19, 1465, 14, 243, 268, 25, 0, 0};
SiloTable D_808012E0_chsilo BT_DATA(4, overlays_ch_silo, 0x20) = {{19, 1223, 22, 20000, 0, 0},
                                                                  {{{1562, 3264, 4}, 174},
                                                                   {{1344, 2932, 6}, 151},
                                                                   {{1344, 656, 5}, 155},
                                                                   {{1764, 2664, 5}, 64},
                                                                   {{1344, 3176, 7}, 16},
                                                                   {{1344, 3272, 4}, 101},
                                                                   {{1344, 4, 4}, 34}}};
ActorAnimationEntry D_80801324_chsilo[12] BT_DATA(4, overlays_ch_silo, 0x64) = {
    {0.0f, 0x0, 0x0},           {0.0f, 0x4aa, 0x44},        {1.70000005f, 0x4aa, 0xa},
    {1.70000005f, 0x4aa, 0x84}, {1.70000005f, 0x4aa, 0x84}, {1.70000005f, 0x4aa, 0x84},
    {1.60000002f, 0x4aa, 0x12}, {1.70000005f, 0x4aa, 0x84}, {1.70000005f, 0x4aa, 0xa},
    {1.70000005f, 0x4aa, 0xa},  {1.60000002f, 0x4aa, 0x12}, {1.70000005f, 0x4aa, 0x84}};
ActorData D_80801384_chsilo[1] BT_DATA(4, overlays_ch_silo, 0xC4) = {
    {185,
     413,
     2327,
     1,
     D_80801324_chsilo,
     (void (*)(struct Actor *))func_80800B80_chsilo,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_808011C8_chsilo,
     98304000,
     0,
     0,
     0,
     10,
     2148,
     (void (*)(struct Actor *))func_808009E8_chsilo,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     8194,
     (void (*)(struct Actor *, long, long))func_80801080_chsilo,
     0}};
