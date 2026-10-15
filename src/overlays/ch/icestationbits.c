#include "common.h"

OSThread *chicestationbits_entrypoint_0(void)
{
    extern u8 D_80800280_chicestationbits[];

    return (OSThread *) D_80800280_chicestationbits;
}

OSThread *chicestationbits_entrypoint_1(void)
{
    extern u8 D_808002C8_chicestationbits[];

    return (OSThread *) D_808002C8_chicestationbits;
}

/* extern */

void func_80800018_chicestationbits(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    _chswitch_entrypoint_7(arg0, 0x1CF);
    _chswitch_entrypoint_9(arg0);
    _chswitch_entrypoint_8(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_80800050_chicestationbits.s")

/* extern */

void func_808000D4_chicestationbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_12(Actor *, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, f32);
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
    if (_chdoormake_entrypoint_3(arg0, var_f0, 0.0f, 600.0f, 0x20, 0x1CF) != 0) {
        _chdoormake_entrypoint_5(arg0, 3.5f);
        _chdoormake_entrypoint_6(arg0, 0.5f);
        _chdoormake_entrypoint_12(arg0, 0, 0x48);
        if (arg0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(arg0, 9);
            _chdoormake_entrypoint_9(arg0, 0, 0, 0x900);
        }
    }
    if ((func_800DA298(0x1CF) != 0) && (_glcutDll_entrypoint_19(0x48) == 0)) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_808001E0_chicestationbits.s")
