#include "common.h"

/* extern */

void func_80800000_chfoodwarn(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gccubesearch_entrypoint_1(s32, s32);
    s32 _gspropctrl_entrypoint_11(s32, s32);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(arg1 + 0x521, arg0 + 4), arg2);
}

void func_8080003C_chfoodwarn(s32 arg0) {
    func_80800000_chfoodwarn(arg0, 0, arg0 + 0x28);
    func_80800000_chfoodwarn(arg0, 1, arg0 + 0x18);
}

/* extern */

s32 func_80800074_chfoodwarn(s32 arg0, s32 arg1) {
    f32 func_800EFC7C(f32 *, f32 *);
    if (func_800EFC7C((f32 *)arg1, (f32 *)(arg0 + 0x28)) < func_800EFC7C((f32 *)arg1, (f32 *)(arg0 + 0x18))) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_808000D4_chfoodwarn.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/foodwarn/func_808001F4_chfoodwarn.s")

OSThread *chfoodwarn_entrypoint_0(void)
{
    extern u8 D_808002A8_chfoodwarn[];

    return (OSThread *) D_808002A8_chfoodwarn;
}
