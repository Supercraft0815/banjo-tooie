#include "common.h"

OSThread *chlightdemon_entrypoint_0(void)
{
    extern ActorData D_80800140_chlightdemon[];

    return (OSThread *) D_80800140_chlightdemon;
}

/* extern */

void func_8080000C_chlightdemon(Actor *arg0) {
    void func_800C8CB8(s32, f32 *);
    void func_80105834(Actor *);
    func_80105834(arg0);
    func_800C8CB8(arg0->actorData[4], arg0->position);
}

void func_8080003C_chlightdemon(Actor *arg0) {
    void func_80105A9C(Actor*, f32);
    func_80105A9C(arg0, 650.0f);
}

s32 func_80800060_chlightdemon(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    extern f32 D_80800194_chlightdemon[];
    extern u32 D_80800188_chlightdemon[];
    s32 temp_v0;

    if (arg1 == 0x95) {
        temp_v0 = func_800C8A98();
        arg0->actorData[4] = temp_v0;
        func_800C8D4C(temp_v0, D_80800194_chlightdemon);
        func_800C8CB8(arg0->actorData[4], arg0->position);
        func_800C8E84(arg0->actorData[4], D_80800188_chlightdemon);
        return 1;
    }
    return 0;
}

/* extern */

void func_808000D8_chlightdemon(s32 arg0) {
    u32 func_800F54E4(void);
    s32 func_800F581C(BtIntPtr);
    void func_800F796C(BtIntPtr arg0,s32 arg1);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F581C(temp_v0) & 0x08000000) {
        func_800F796C(sp1C, 3);
    }
}

OSThread *chlightdemon_entrypoint_1(void)
{
    extern ActorData D_8080019C_chlightdemon[];

    return (OSThread *) D_8080019C_chlightdemon;
}
/* data_to_c.py: from asm/data/overlays/ch/light/demon.data.s */
extern u8 D_80800130_chlightdemon[];
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void func_8010A730();
u8 D_80800130_chlightdemon[16] BT_DATA(4, overlays_ch_light_demon, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0x13, 0x00, 0x00 };
ActorData D_80800140_chlightdemon [1] BT_DATA(4, overlays_ch_light_demon, 0x10) = { { 414, 301, 1726, 1, (void *)D_80800130_chlightdemon, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_8080000C_chlightdemon, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 2, 5376, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080003C_chlightdemon, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800060_chlightdemon, 0 } };
u32 D_80800188_chlightdemon [3] BT_DATA(4, overlays_ch_light_demon, 0x58) = { 0xFF, 0xFF, 0x40 };
f32 D_80800194_chlightdemon [2] BT_DATA(4, overlays_ch_light_demon, 0x64) = { 500.0f, 1750.0f };
ActorData D_8080019C_chlightdemon [1] BT_DATA(4, overlays_ch_light_demon, 0x6C) = { { 344, 480, 0, 1, 0, (void (*)(struct Actor *))func_808000D8_chlightdemon, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9730, 0, 0 } };
