#include "common.h"

OSThread *chproplighter_entrypoint_0(void)
{
    extern ActorData D_808001A0_chproplighter[];

    return (OSThread *) D_808001A0_chproplighter;
}

void func_8080000C_chproplighter(Actor *arg0) {
    s32 _gccubesearch_entrypoint_16(s32 *, s32 *, s16 **, s32, s32);
    s16 _gsproplookup_entrypoint_0(void *prop);
    f32 func_800136E4(f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE904(s32 *, f32 *);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    void func_80103014(u8 *);
    s32 func_80103140(Actor *, u32, u16);
    s32 func_80104E78(Actor *);
    s32 func_80105010(Actor *);
    void func_80108944(Actor *, Actor *);
    void func_8010A63C(Actor *);
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
    if (_gccubesearch_entrypoint_16(sp34, &sp44, &sp40, 2, 0x1F4) != 0) {
        prop = (struct LightProp *)sp40;
        prop->enabled = 1;
        prop->hidden = 0;
        func_800EE88C(arg0->position, prop->position);
        arg0->rotation[1] = func_800136E4(2.0f * (u32)prop->yaw);
        arg0->rotation[0] = func_800136E4(2.0f * (u32)prop->pitch);
        func_80103140(arg0, _gsproplookup_entrypoint_0(prop) & 0xFFFF, 0);
        func_80102FDC(arg0, (u32)prop->scale * 0.01f);
        func_80103014((u8 *)arg0);
        func_80108944(arg0, arg0);
        if (func_80105010(arg0) == 0) {
            func_80104E78(arg0);
        }
        func_8010A63C(arg0);
    } else {
        func_800FFAB0(arg0);
    }
}

void func_8080017C_chproplighter(void *arg0)
{
}
/* data_to_c.py: from asm/data/overlays/ch/proplighter.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808001A0_chproplighter [1] BT_DATA(4, overlays_ch_proplighter, 0x0) = { { 344, 1099, -1, 1, 0, (void (*)(struct Actor *))func_8080017C_chproplighter, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chproplighter, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, 0, 0 } };
