/* data_to_c.py: from asm/data/overlays/ch/factory/battery.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_801018A4();
void func_80108ED0();
void func_80107C2C();
extern u8 D_80801AB0_chfactorybattery[];
void func_80101870();
u8 D_80801AB0_chfactorybattery[20] BT_DATA(4, overlays_ch_factory_battery, 0x0) = {
    0x00, 0x06, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00};
ActorAnimationEntry D_80801AC4_chfactorybattery[14] BT_DATA(4, overlays_ch_factory_battery,
                                                            0x14) = {
    {0.0f, 0x0, 0x0},           {0.467000008f, 0x2cc, 0x1}, {0.467000008f, 0x2cc, 0x1},
    {0.467000008f, 0x2cc, 0x1}, {0.467000008f, 0x2cc, 0x1}, {0.467000008f, 0x2cc, 0x1},
    {0.467000008f, 0x2cb, 0x1}, {0.467000008f, 0x2cc, 0x1}, {0.467000008f, 0x2cb, 0x1},
    {0.467000008f, 0x2cc, 0x1}, {0.467000008f, 0x2cb, 0x1}, {0.467000008f, 0x2cb, 0x1},
    {0.467000008f, 0x2cb, 0x1}, {0.467000008f, 0x2cc, 0x1}};
BtFnWord D_80801B34_chfactorybattery[2] BT_DATA(4, overlays_ch_factory_battery, 0x84) = {
    (BtFnWord)func_808003C0_chfactorybattery, (BtFnWord)func_8080019C_chfactorybattery};
Color D_80801B3C_chfactorybattery BT_DATA(4, overlays_ch_factory_battery,
                                          0x8C) = {{0xC8, 0xC8, 0xC8}};
Color D_80801B48_chfactorybattery BT_DATA(4, overlays_ch_factory_battery, 0x98) = {{0, 0, 0}};
Color D_80801B54_chfactorybattery BT_DATA(4, overlays_ch_factory_battery,
                                          0xA4) = {{0x28, 0xC8, 0xFF}};
s16 D_80801B60_chfactorybattery[12] BT_DATA(4, overlays_ch_factory_battery, 0xB0) = {
    19, 1237, 22, 10000, 13, 204, 230, 1, 200, 6000, 0, 0};
s16 D_80801B78_chfactorybattery[8] BT_DATA(4, overlays_ch_factory_battery,
                                           0xC8) = {19, 1326, 13, 307, 358, 22, 14000, 0};
f32 D_80801B88_chfactorybattery[4][2] BT_DATA(4, overlays_ch_factory_battery, 0xD8) = {
    {0.0f, 0.0f}, {0.400000006f, 0.0f}, {0.800000012f, 1.0f}, {1.0f, 0.0f}};
ActorData D_80801BA8_chfactorybattery[1] BT_DATA(4, overlays_ch_factory_battery, 0xF8) = {
    {292,
     652,
     2020,
     6,
     (void *)D_80801AC4_chfactorybattery,
     (void (*)(struct Actor *))func_80800AB8_chfactorybattery,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_801018A4,
     131072000,
     1069547520,
     0,
     0,
     132,
     357,
     (void (*)(struct Actor *))func_808014C0_chfactorybattery,
     (BtIntPtr)func_80108ED0,
     0,
     0,
     0,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     21509,
     (void (*)(struct Actor *, long, long))func_80801040_chfactorybattery,
     (BtIntPtr)D_80801AB0_chfactorybattery}};
ActorData D_80801BF0_chfactorybattery[1] BT_DATA(4, overlays_ch_factory_battery, 0x140) = {
    {282,
     1019,
     2171,
     1,
     0,
     (void (*)(struct Actor *))func_80801728_chfactorybattery,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_80101870,
     131072000,
     0,
     0,
     0,
     16384,
     3072,
     0,
     0,
     0,
     0,
     (void (*)(struct Actor *))func_8080150C_chfactorybattery,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32760,
     25618,
     (void (*)(struct Actor *, long, long))func_80801804_chfactorybattery,
     0}};
