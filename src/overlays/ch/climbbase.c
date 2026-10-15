#include "common.h"

/* extern */

s32 func_80800000_chclimbbase(Actor *arg0, f32 *arg1) {
    s32 _gccubesearch_entrypoint_13(f32 *, u32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 *temp_s0;
    s32 var_v1;
    s32 temp_v0;

    temp_s0 = arg0->position;
    var_v1 = _gccubesearch_entrypoint_13(sp44, 0x1FA, temp_s0);
    temp_v0 = _gccubesearch_entrypoint_13(sp38, 0x1FB, temp_s0);
    if ((var_v1 == 0) && (temp_v0 == 0)) {
        return 0;
    }
    if ((var_v1 != 0) && (temp_v0 != 0)) {
        sp34 = func_800EFB8C(temp_s0, sp44);
        if (func_800EFB8C(temp_s0, sp38) < sp34) {
            var_v1 = 0;
        }
    }
    if (var_v1 != 0) {
        func_800EE7F8(arg1, sp44);
        arg0->unk6C_0 = 1;
    } else {
        func_800EE7F8(arg1, sp38);
        arg0->unk6C_0 = 2;
    }
    return 1;
}

/* extern */

s32 func_808000FC_chclimbbase(void) {
    s32 _gclevel_entrypoint_4(s32);
    if (_gclevel_entrypoint_4(0x80) != 0) {
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800128_chclimbbase.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/climbbase/func_80800200_chclimbbase.s")

OSThread *chclimbbase_entrypoint_0(void)
{
    extern u8 D_808003D0_chclimbbase[];

    return (OSThread *) D_808003D0_chclimbbase;
}

OSThread *chclimbbase_entrypoint_1(void)
{
    extern u8 D_80800418_chclimbbase[];

    return (OSThread *) D_80800418_chclimbbase;
}
