/* data_to_c.py: from asm/data/overlays/ch/attract.data.s */
#include "core2/actor_animation_entry.h"

void func_80102EC0();
void func_80107C2C();
ActorAnimationEntry D_80800440_chattract[5] BT_DATA(4, overlays_ch_attract,
                                                    0x0) = {{0.0f, 0x0, 0x0},
                                                            {0.0f, 0x0, 0x0},
                                                            {1.60000002f, 0x284, 0x4a},
                                                            {0.0f, 0x0, 0x0},
                                                            {1.10000002f, 0x286, 0x4a}};
struct AttractEntry D_80800468_chattract[5] BT_DATA(4, overlays_ch_attract, 0x28) = {
    {0, 0, 0, 0.0f, 0.0f, 0.0f, 0, 0, 0.0f, 0, {0, 0, 0}},
    {0x8A8, 1, 1, 2.5f, 0.0f, 0.14f, 152, 94, 0.0f, 1, {0, 0, 0}},
    {0x85A, 0, 1, 5.0f, 2.0f, 0.2f, 152, 171, 0.0f, 0, {0, 0, 0}},
    {0x859, 1, 0, 0.0f, 0.0f, 0.1f, 274, 198, 280.0f, 0, {0, 0, 0}},
    {0x85B, 0, 1, 5.0f, 2.0f, 0.2f, 152, 171, 0.0f, 0, {0, 0, 0}}};
ActorData D_808004F4_chattract[1] BT_DATA(4, overlays_ch_attract, 0xB4) = {
    {344,
     1205,
     0,
     2,
     D_80800440_chattract,
     (void (*)(struct Actor *))func_80800014_chattract,
     (void (*)(struct Actor *))func_80102EC0,
     (void (*)(long, long))func_80800204_chattract,
     0,
     0,
     0,
     0,
     2112,
     1028,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080000C_chattract,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     2,
     (void (*)(struct Actor *, long, long))func_808002AC_chattract,
     0}};
