/* data_to_c.py: from asm/data/overlays/ch/friendlystonehead.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80107C2C();
subaddiedialog_UnkStruct1
    D_808008C0_chfriendlystonehead[4] BT_DATA(4, overlays_ch_friendlystonehead, 0x0) = {
        {0x80, 3865, 1, 0}, {0x80, 3866, 2, 0}, {1, 3867, 3, 0}, {0x1000, 3930, 3, 0}};
subaddiedialog_UnkStruct1 D_808008E0_chfriendlystonehead[5] BT_DATA(4,
                                                                    overlays_ch_friendlystonehead,
                                                                    0x20) = {{0x201, 4729, 2, 0},
                                                                             {0x400, 4831, 2, 0},
                                                                             {0x1000, 4832, 2, 0},
                                                                             {0x80, 4727, 1, 0},
                                                                             {0x80, 4728, 2, 0}};
u16 D_80800908_chfriendlystonehead[4][2] BT_DATA(4, overlays_ch_friendlystonehead, 0x48) = {
    {0xF0F, 0xF30}, {0xF11, 0xF10}, {0xF13, 0xF12}, {0xF15, 0xF14}};
ActorAnimationEntry D_80800918_chfriendlystonehead[7] BT_DATA(4, overlays_ch_friendlystonehead,
                                                              0x58) = {
    {0.0f, 0x0, 0x0},  {1.5f, 0x7a, 0x44},       {1.5f, 0x7a, 0x2}, {4.0f, 0x7b, 0x1},
    {4.0f, 0x7b, 0x1}, {1.29999995f, 0x7c, 0x2}, {4.0f, 0x7b, 0x1}};
s16 D_80800950_chfriendlystonehead[6] BT_DATA(4, overlays_ch_friendlystonehead,
                                              0x90) = {19, 1602, 13, 192, 217, 0};
s16 D_8080095C_chfriendlystonehead[6] BT_DATA(4, overlays_ch_friendlystonehead,
                                              0x9C) = {19, 1602, 13, 166, 192, 0};
f32 D_80800968_chfriendlystonehead[4] BT_DATA(4, overlays_ch_friendlystonehead,
                                              0xA8) = {160.0f, 100.0f, 100.0f, 40.0f};
subaddiedialog_UnkStruct2 D_80800978_chfriendlystonehead BT_DATA(4, overlays_ch_friendlystonehead,
                                                                 0xB8) = {0x64, 0, 0x12C, 53, 0,
                                                                          0xE,  0, 0,     4};
subaddiedialog_UnkStruct2 D_80800988_chfriendlystonehead BT_DATA(4, overlays_ch_friendlystonehead,
                                                                 0xC8) = {0x36E, 0, 0x12C, 53, 0,
                                                                          0xE,   0, 0,     4};
subaddiedialog_UnkStruct0 D_80800998_chfriendlystonehead BT_DATA(4, overlays_ch_friendlystonehead,
                                                                 0xD8) = {
    0, 0x12C, 0, 0, 0x80, 0, 0, 53, 0, 0xE, 0x40, 0, 4};
ActorData D_808009B4_chfriendlystonehead[1] BT_DATA(4, overlays_ch_friendlystonehead, 0xF4) = {
    {348,
     276,
     1654,
     1,
     D_80800918_chfriendlystonehead,
     (void (*)(struct Actor *))func_80800020_chfriendlystonehead,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80800160_chfriendlystonehead,
     65536000,
     1067030938,
     0,
     0,
     16384,
     0,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_80800000_chfriendlystonehead,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32256,
     9302,
     (void (*)(struct Actor *, long, long))func_808001A8_chfriendlystonehead,
     0}};
