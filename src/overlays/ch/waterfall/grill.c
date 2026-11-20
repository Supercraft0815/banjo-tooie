#include "common.h"

/* extern */

void func_80800000_chwaterfallgrill(Actor *arg0) {
    void _chdoor_entrypoint_0(BT_NATIVE_ONLY(Actor *));
    void func_800CE88C(s32, s32);
    void func_800CE928(s32, BtIntPtr, BtIntPtr);
    void func_800DA544(GameFlag);
    void func_800FC660(u32);
    void func_80103110(Actor *, u32);
    s32 func_8010CB0C(f32 *, s32, s32, s32);
    _chdoor_entrypoint_0(BT_NATIVE_ONLY((Actor *)arg0));
    if ((arg0->unk70_10 == 4) && (func_8010CB0C((f32 *)arg0->actorData, 0xB4, 0xC8, -0x15E) != 0)) {
        func_800DA544(0x503);
        func_800CE928(0, 0, 0);
        func_800CE88C(0, 0);
        func_800FC660(0x10);
        func_80103110(arg0, 0);
    }
}

void func_8080008C_chwaterfallgrill(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void _chdoormake_entrypoint_9(Actor *arg0, s32 arg1, u16 arg2, s32 arg3);
    void _chdoormake_entrypoint_10(Actor *arg0, s32 arg1, s32 arg2);
    void _chdoormake_entrypoint_11(Actor *, s32, f32);
    void _chwaterfallgrill_entrypoint_0(s32, s32);
    s32 func_800CE95C();
    s32 func_800CEAA8(s32);
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
#ifndef BT_NATIVE
    void func_800DA544(s32);
#endif
    void func_800EE7F8(f32 *, f32 *);
    void func_80103110(Actor *, u32);

    if (func_800DA298(0x503) != 0) {
        func_800DA544(0x9F2);
    } else if (func_800CEAA8(0) == 0 || func_800CE95C(0) != (BtIntPtr)_chwaterfallgrill_entrypoint_0) {
        func_800DA524(0x9F2);
    }
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 440.0f, 0x408A, 0x9F2)) {
        _chdoormake_entrypoint_8(arg0, 2);
        _chdoormake_entrypoint_5(arg0, 2.5f);
        _chdoormake_entrypoint_9(arg0, 0, 0, 0x10);
        _chdoormake_entrypoint_10(arg0, 0, 0x501);
        _chdoormake_entrypoint_11(arg0, 0, 0.9499969482421875f);
        _chdoormake_entrypoint_9(arg0, 1, 2, 0x10);
        _chdoormake_entrypoint_10(arg0, 1, 0x502);
        _chdoormake_entrypoint_11(arg0, 1, 0.25f);
    }
    if (func_800DA298(0x503) != 0 || func_800DA298(0x9F2) == 0) {
        func_80103110(arg0, 0);
    }
}

s32 func_808001E0_chwaterfallgrill(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    void _chwaterfallgrill_entrypoint_0(s32, s32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, BtIntPtr, BtIntPtr);
    s32 func_800CEAA8(s32);
#ifndef BT_NATIVE
    s32 func_800DA298(GameFlag);
#endif
    void func_80103110(Actor *, u32);

    switch (arg1) {
        case 7:
            if (func_800DA298(0x503)) {
                return 0;
            }
            if (func_800CEAA8(0)) {
                func_800CE8D8(0, 35.0f, 0x23);
                func_800CE928(0, (BtIntPtr)_chwaterfallgrill_entrypoint_0, 0);
            }
            func_80103110((Actor *)arg0, 1);
            break;
        case 0x9D:
            func_800CE8D8(0, 35.0f, 0x23);
            func_800CE928(0, (BtIntPtr)_chwaterfallgrill_entrypoint_0, 0);
            func_800CE88C(0, 1);
            break;
        case 0x9E:
            func_80103110((Actor *)arg0, 0);
            break;
    }
    return _chdoor_entrypoint_1(arg0, arg1, arg2);
}

/* extern */

void chwaterfallgrill_entrypoint_0(s32 arg0, s32 arg1) {
    void func_800DA524(s32 index);
    s32 func_800EA05C();
    s32 func_80101180(s32, s32, BtIntPtr);
    if (func_800EA05C() == 0xC7) {
        func_80101180(0x11B, 8, 0);
        return;
    }
    func_800DA524(0x9F2);
}

OSThread *chwaterfallgrill_entrypoint_1(void)
{
    extern ActorData D_80800330_chwaterfallgrill[];

    return (OSThread *) D_80800330_chwaterfallgrill;
}
/* data_to_c.py: from asm/data/overlays/ch/waterfall/grill.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800330_chwaterfallgrill [1] BT_DATA(4, overlays_ch_waterfall_grill, 0x0) = { { 172, 283, 1665, 1, 0, (void (*)(struct Actor *))func_80800000_chwaterfallgrill, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080008C_chwaterfallgrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9218, (void (*)(struct Actor *, long, long))func_808001E0_chwaterfallgrill, 0 } };
