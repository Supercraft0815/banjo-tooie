#include "common.h"

OSThread *chmineproplight_entrypoint_0(void)
{
    extern ActorData D_80800240_chmineproplight[];

    return (OSThread *) D_80800240_chmineproplight;
}

void func_8080000C_chmineproplight(Actor *arg0) {
    s32 _gccubesearch_entrypoint_16(s32 *, s32 *, s16 **, s32, s32);
    s16 _gsproplookup_entrypoint_0(void *prop);
    f32 func_800136E4(f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE904(s32 *, f32 *);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    void func_80103014(u8 *);
    s32 func_80103140(Actor *, u32, u16);
    void func_80108944(Actor *, Actor *);
    void func_8010A828(void **arg0, s32 arg1);
    struct LightProp {
        u16 id;
        u8 yaw;
        u8 pitch;
        s16 position[3];
        u8 scale;
        BT_BITFIELD_ORDER(u8 pad : 2, u8 rest : 4);
        BT_BITFIELD_ORDER(u8 enabled : 1, u8 hidden : 1);
        BT_BITFIELD_ORDER(u8 hidden : 1, u8 enabled : 1);
        BT_BITFIELD_ORDER(u8 rest : 4, u8 pad : 2);
    };
    s32 sp44;
    s16 *sp40;
    s32 sp34[3];
    struct LightProp *prop;

    func_800EE904(sp34, arg0->position);
    if (_gccubesearch_entrypoint_16(sp34, &sp44, &sp40, 2, 500)) {
        prop = (void *)sp40;
        prop->enabled = 1;
        prop->hidden = 0;
        func_800EE88C(arg0->position, prop->position);
        arg0->rotation[1] = func_800136E4(2.0f * (u32)prop->yaw);
        arg0->rotation[0] = func_800136E4(2.0f * (u32)prop->pitch);
        func_80103140(arg0, (u16)_gsproplookup_entrypoint_0(prop), 0);
        func_80102FDC(arg0, (u32)prop->scale * 0.01f);
        func_80103014((u8 *)arg0);
        func_80108944(arg0, arg0);
        func_8010A828(arg0, 5);
    } else {
        func_800FFAB0(arg0);
    }
}

void func_80800168_chmineproplight(Actor *arg0, void *arg1) {
    BtIntPtr func_800D674C(s32);
    u8 func_800D731C(u16);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF7E8(u8);
    void func_800DF830(s32);
    s32 func_800EB854(void);
    void func_80101870(Actor *, void *);
    switch (func_800EB854()) {
        case 2:
            func_800DF830(1);
            func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, func_800D674C(0x695));
            func_800DF7E8(func_800D731C(0x696));
            func_800DF830(1);
            func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, func_800D674C(0x696));
            break;
        case 0:
            func_80101870(arg0, arg1);
            break;
    }
}

void func_80800228_chmineproplight(s32 arg0) 
{
}
/* data_to_c.py: from asm/data/overlays/ch/mine/proplight.data.s */
void func_80105834(Actor*);
void func_80107C2C();
ActorData D_80800240_chmineproplight [1] BT_DATA(4, overlays_ch_mine_proplight, 0x0) = { { 344, 588, -1, 1, 0, (void (*)(struct Actor *))func_80800228_chmineproplight, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800168_chmineproplight, 0, 0, 0, 0, 10, 2052, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chmineproplight, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 10258, 0, 0 } };
