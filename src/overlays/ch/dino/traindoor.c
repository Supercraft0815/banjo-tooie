#include "common.h"

/* extern */

void func_80800000_chdinotraindoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_12(Actor *, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80103014(u8 *);
    f32 var_f0;

    var_f0 = arg0->rotation[1];
    if (arg0->unk74_7 == 0x32) {
        var_f0 += 180.0f;
    }
    func_800EFD24(arg0->position);
    func_80103014((u8 *)arg0);
    if (_chdoormake_entrypoint_3(arg0, var_f0, 0.0f, arg0->scale * 600.0f, 0x20, 0x164) != 0) {
        _chdoormake_entrypoint_5(arg0, 3.5f);
        _chdoormake_entrypoint_6(arg0, 0x40800000);
        _chdoormake_entrypoint_12(arg0, 0, 0x3C);
        if (arg0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(arg0, 5);
            _chdoormake_entrypoint_9(arg0, 0, 0xA, 0x910);
        }
    }
    if ((func_800DA298(0x164) != 0) && (_glcutDll_entrypoint_19(0x3C) == 0)) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/traindoor/func_80800120_chdinotraindoor.s")

OSThread *chdinotraindoor_entrypoint_0(void)
{
    extern u8 D_808001D0_chdinotraindoor[];

    return (OSThread *) D_808001D0_chdinotraindoor;
}
