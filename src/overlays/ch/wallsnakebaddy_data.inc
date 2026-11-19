/* data_to_c.py: from asm/data/overlays/ch/wallsnakebaddy.data.s */
#include "core2/actor_animation_entry.h"
void func_80105834(Actor *);
void func_80108ED0();
void func_80107C2C();
extern u8 D_808006E0_chwallsnakebaddy[];
ActorAnimationEntry D_808006A0_chwallsnakebaddy[8] BT_DATA(4, overlays_ch_wallsnakebaddy, 0x0) = {
    {0.0f, 0x0, 0x0},          {2.20000005f, 0x1a5, 0x44},
    {2.20000005f, 0x1a5, 0x2}, {2.20000005f, 0x1a6, 0x2},
    {2.70000005f, 0x1a4, 0x2}, {2.70000005f, 0x1ab, 0x2},
    {0.0f, 0x0, 0x0},          {0.0f, 0x0, 0x0}};
u8 D_808006E0_chwallsnakebaddy[20] BT_DATA(4, overlays_ch_wallsnakebaddy, 0x40) = {
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x06, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00};
s32 D_808006F4_chwallsnakebaddy[3] BT_DATA(4, overlays_ch_wallsnakebaddy, 0x54) = {1246391, 1473792,
                                                                                   0};
s32 D_80800700_chwallsnakebaddy[4] BT_DATA(4, overlays_ch_wallsnakebaddy,
                                           0x60) = {1246390, 1473792, 852211, 17563648};
s32 D_80800710_chwallsnakebaddy[4] BT_DATA(4, overlays_ch_wallsnakebaddy, 0x70) = {1246391, 1474552,
                                                                                   655564, 0};
s32 D_80800720_chwallsnakebaddy[12] BT_DATA(4, overlays_ch_wallsnakebaddy, 0x80) = {
    1903069, 2818457, 30146594, 25166336, 33555072, 1376256,
    2490393, 7,       2949070,  720846,   3276850,  3276800};
s16 D_80800750_chwallsnakebaddy[6] BT_DATA(4, overlays_ch_wallsnakebaddy, 0xB0) = {1760, 1761, 1762,
                                                                                   1764, 1763, 0};
u8 D_8080075C_chwallsnakebaddy[8] BT_DATA(4, overlays_ch_wallsnakebaddy, 0xBC) = {8, 2, 2, 2,
                                                                                  1, 0, 0, 0};
s32 D_80800764_chwallsnakebaddy[10] BT_DATA(4, overlays_ch_wallsnakebaddy, 0xC4) = {
    2818560, 41943085, 22938050, 2556104, 13107600, 26214427, -65471264, 2293964, 786452, 0};
s32 D_8080078C_chwallsnakebaddy[3] BT_DATA(4, overlays_ch_wallsnakebaddy, 0xEC) = {786532, 2115214,
                                                                                   12451840};
u8 D_80800798_chwallsnakebaddy[4] BT_DATA(4, overlays_ch_wallsnakebaddy, 0xF8) = {0x5F, 0x96, 0x0A, 0xE6};
s32 D_8080079C_chwallsnakebaddy[3] BT_DATA(4, overlays_ch_wallsnakebaddy, 0xFC) = {1246239, 1458792,
                                                                                   0};
s32 D_808007A8_chwallsnakebaddy[3] BT_DATA(4, overlays_ch_wallsnakebaddy, 0x108) = {1246229,
                                                                                    1458792, 0};
ActorData D_808007B4_chwallsnakebaddy[1] BT_DATA(4, overlays_ch_wallsnakebaddy, 0x114) = {
    {345,
     273,
     1638,
     1,
     (void *)D_808006A0_chwallsnakebaddy,
     (void (*)(struct Actor *))func_80800000_chwallsnakebaddy,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8080027C_chwallsnakebaddy,
     131072000,
     0,
     0,
     0,
     0,
     34,
     0,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     (void (*)(struct Actor *))func_80800650_chwallsnakebaddy,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32720,
     9233,
     (void (*)(struct Actor *, long, long))func_808005D8_chwallsnakebaddy,
     (BtIntPtr)D_808006E0_chwallsnakebaddy}};
