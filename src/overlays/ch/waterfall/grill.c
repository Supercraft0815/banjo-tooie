#include "common.h"

/* extern */

void func_80800000_chwaterfallgrill(Actor *arg0) {
    void _chdoor_entrypoint_0();
    void func_800CE88C(s32, s32);
    void func_800CE928(s32, s32, s32);
    void func_800DA544(GameFlag);
    void func_800FC660(u32);
    void func_80103110(Actor *, u32);
    s32 func_8010CB0C(f32 *, s32, s32, s32);
    _chdoor_entrypoint_0();
    if ((arg0->unk70_10 == 4) && (func_8010CB0C((f32 *)arg0->actorData, 0xB4, 0xC8, -0x15E) != 0)) {
        func_800DA544(0x503);
        func_800CE928(0, 0, 0);
        func_800CE88C(0, 0);
        func_800FC660(0x10);
        func_80103110(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_8080008C_chwaterfallgrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/grill/func_808001E0_chwaterfallgrill.s")

/* extern */

void chwaterfallgrill_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    s32 func_80101180(s32, s32, s32);
    if (func_800EA05C() == 0xC7) {
        func_80101180(0x11B, 8, 0);
        return;
    }
    func_800DA524(0x9F2);
}

OSThread *chwaterfallgrill_entrypoint_1(void)
{
    extern u8 D_80800330_chwaterfallgrill[];

    return (OSThread *) D_80800330_chwaterfallgrill;
}
