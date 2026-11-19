/* data_to_c.py: from asm/data/overlays/ch/eato.data.s */
#include "core2/actor_animation_entry.h"

void func_80105834(Actor *);
void func_80107C2C();
f32 D_80800E50_chcheato[4] BT_DATA(4, overlays_ch_eato, 0x0) = {320.0f, 250.0f, 220.0f, 120.0f};
ActorAnimationEntry D_80800E60_chcheato[7] BT_DATA(4, overlays_ch_eato, 0x10) = {
    {0.0f, 0x0, 0x0},           {0.800000012f, 0x220, 0x0}, {0.800000012f, 0x220, 0x0},
    {0.800000012f, 0x220, 0x0}, {0.800000012f, 0x220, 0x0}, {0.800000012f, 0x220, 0x0},
    {0.800000012f, 0x220, 0x0}};
ActorData D_80800E98_chcheato[1] BT_DATA(4, overlays_ch_eato, 0x48) = {
    {390,
     309,
     1927,
     1,
     (void *)D_80800E60_chcheato,
     (void (*)(struct Actor *))func_80800068_chcheato,
     (void (*)(struct Actor *))func_80105834,
     (void (*)(long, long))func_8080035C_chcheato,
     0,
     1073741824,
     0,
     0,
     0,
     256,
     0,
     0,
     0,
     20,
     (void (*)(struct Actor *))func_8080000C_chcheato,
     (void (*)(void *, long, void *, long, void *))func_80107C2C,
     -32768,
     1154,
     (void (*)(struct Actor *, long, long))func_80800204_chcheato,
     0}};
subaddiedialog_UnkStruct0 D_80800EE0_chcheato BT_DATA(4, overlays_ch_eato, 0x90) = {
    0x68, 0x15E, 0x1142, 0, 0x201, 0x1208, 0, 55, 0, 0xE, 8, 0, 2};
struct CheatoTimes D_80800EFC_chcheato BT_DATA(4, overlays_ch_eato, 0xAC) = {{0.25f, 0.95f}};
struct CheatoSounds D_80800F04_chcheato BT_DATA(4, overlays_ch_eato, 0xB4) = {{1221, 1222}};
s16 D_80800F08_chcheato[12] BT_DATA(4, overlays_ch_eato, 0xB8) = {33, 13,  243,  268, 22, 14000,
                                                                  1,  200, 1500, 17,  0,  0};
OptionColors D_80800F20_chcheato BT_DATA(4, overlays_ch_eato, 0xD0) = {{255, 255, 255}};
OptionColors D_80800F28_chcheato BT_DATA(4, overlays_ch_eato, 0xD8) = {{255, 255, 0}};
