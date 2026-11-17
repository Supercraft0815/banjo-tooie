#include "common.h"

OSThread *chstarspinnerplanet_entrypoint_0(void)
{
    extern ActorData D_80800260_chstarspinnerplanet[];

    return (OSThread *) D_80800260_chstarspinnerplanet;
}

OSThread *chstarspinnerplanet_entrypoint_1(void)
{
    extern ActorData D_808002A8_chstarspinnerplanet[];

    return (OSThread *) D_808002A8_chstarspinnerplanet;
}

void func_80800018_chstarspinnerplanet(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    f32 func_800F15F8(f32, f32, f32);
    extern u32 D_808002F0_chstarspinnerplanet[8];
    f32 sp24;

    if (func_800DA298(0) != 0) {
        sp24 = func_800D8FF8();
        ((f32 *)arg0->actorData)[5] = func_800F15F8(((f32 *)arg0->actorData)[5], 20.0f, 0.5f);
        ((f32 *)arg0->actorData)[4] = func_800F15F8(((f32 *)arg0->actorData)[4], 40.0f, 0.8f);
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] + ((f32 *)arg0->actorData)[5] * sp24);
        arg0->rotation[0] = func_800136E4(arg0->rotation[0] + ((f32 *)arg0->actorData)[4] * sp24);
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, func_800DA298(0), D_808002F0_chstarspinnerplanet);
}

/* extern */

void func_808000E4_chstarspinnerplanet(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddiefade_entrypoint_12(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800EA05C();
    void func_80108A30(s32, void *, f32, s32);
    void func_8010A624(Actor *arg0);
    if ((func_800DA298(0xEA) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_800DA544(0);
    }
    func_80108A30(0x335, (void *)(arg0 + 4), 0.0f, 0x32);
    if (func_800EA05C() != 0xE6) {
        func_8010A624(arg0);
    }
    _subaddiefade_entrypoint_12(arg0, 0xA0, 0xA0, 0xA0);
}                typedef struct { u8 pad0[0x2C]; f32 unk2C; u8 pad30[0x18]; f32 unk48; } Objplanet_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800170_chstarspinnerplanet(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8();
    s32 func_800DA298(s32);
    f32 func_800F15F8(f32, f32, f32);
    f32 sp1C;
    f32 temp_f0;

    if (func_800DA298(0) != 0) {
        sp1C = func_800D8FF8();
        temp_f0 = func_800F15F8((((Objplanet_arg0 *)arg0)->unk2C), 25.0f, 0.6f);
        (((Objplanet_arg0 *)arg0)->unk2C) = temp_f0;
        (((Objplanet_arg0 *)arg0)->unk48) = func_800136E4((((Objplanet_arg0 *)arg0)->unk48) - (temp_f0 * sp1C));
    }
}

/* extern */

void func_808001E8_chstarspinnerplanet(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddiefade_entrypoint_12(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800EA05C();
    void func_8010A624(Actor *arg0);
    if ((func_800DA298(0xEA) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_800DA544(0);
    }
    if (func_800EA05C() != 0xE6) {
        func_8010A624(arg0);
    }
    _subaddiefade_entrypoint_12(arg0, 0xA0, 0xA0, 0xA0);
}
/* data_to_c.py: from asm/data/overlays/ch/starspinner/planet.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800260_chstarspinnerplanet [1] BT_DATA(4, overlays_ch_starspinner_planet, 0x0) = { { 431, 820, 1911, 1, 0, (void (*)(struct Actor *))func_80800018_chstarspinnerplanet, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 12416, 19456, 0, 0, 0, 0, (void (*)(struct Actor *))func_808000E4_chstarspinnerplanet, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 1026, 0, 0 } };
ActorData D_808002A8_chstarspinnerplanet [1] BT_DATA(4, overlays_ch_starspinner_planet, 0x48) = { { 438, 821, 1912, 1, 0, (void (*)(struct Actor *))func_80800170_chstarspinnerplanet, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 12416, 19456, 0, 0, 0, 0, (void (*)(struct Actor *))func_808001E8_chstarspinnerplanet, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 1026, 0, 0 } };
u32 D_808002F0_chstarspinnerplanet[8] BT_DATA(4, overlays_ch_starspinner_planet, 0x90) = { 0x1304CB, 0x167530, 0x105DC, 0xFA0000A, 0x660000, 0, 0, 0 };
