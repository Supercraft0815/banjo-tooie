#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grill2switches/func_80800000_chminegrill2switches.s")

/* extern */

void func_80800030_chminegrill2switches(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x4C2, arg3, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800094_chminegrill2switches(s32 arg0) {
    s32 func_80800000_chminegrill2switches(s32, s32, s32);
    func_80800000_chminegrill2switches(arg0, 0xA26, 512);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grill2switches/func_808000B8_chminegrill2switches.s")

OSThread *chminegrill2switches_entrypoint_0(void)
{
    extern u8 D_80800150_chminegrill2switches[];

    return (OSThread *) D_80800150_chminegrill2switches;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grill2switches/func_808000EC_chminegrill2switches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grill2switches/func_80800110_chminegrill2switches.s")

OSThread *chminegrill2switches_entrypoint_1(void)
{
    extern u8 D_80800198_chminegrill2switches[];

    return (OSThread *) D_80800198_chminegrill2switches;
}
