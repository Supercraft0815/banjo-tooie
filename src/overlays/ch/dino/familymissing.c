#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymissing/func_80800000_chdinofamilymissing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymissing/func_80800104_chdinofamilymissing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymissing/func_80800324_chdinofamilymissing.s")

void func_80800418_chdinofamilymissing(Actor *arg0) {
    f32 func_800F3780(f32, u8 *, s16);
    f32 func_80101F24(Actor *);
    void func_80105A9C(Actor *, f32);
    extern u8 D_808006AC_chdinofamilymissing;
    f32 temp_f2;
    f32 var_f0;
    f32 temp_f6;

    temp_f2 = func_800F3780(func_80101F24(arg0), &D_808006AC_chdinofamilymissing, 4);
    if (arg0->unk70_10 == 1) {
        var_f0 = 0.75f;
    } else {
        var_f0 = 1.0f;
    }
    temp_f6 = temp_f2 * 1200.0f;
    func_80105A9C(arg0, var_f0 * temp_f6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymissing/func_808004A4_chdinofamilymissing.s")

OSThread *chdinofamilymissing_entrypoint_0(void)
{
    extern u8 D_808006DC_chdinofamilymissing[];

    return (OSThread *) D_808006DC_chdinofamilymissing;
}
