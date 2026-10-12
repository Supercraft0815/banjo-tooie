#include "common.h"

void func_80800000_chlavaarchgrill3switches()
{
    _chswitch_entrypoint_7();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill3switches/func_80800020_chlavaarchgrill3switches.s")

/* extern */

void func_808000C0_chlavaarchgrill3switches(s32 arg0) {
    s32 _chswitch_entrypoint_8(s32, s32);
    func_80800000_chlavaarchgrill3switches(arg0, 0xA1D);
    _chswitch_entrypoint_8(arg0, 0x200);
}

void func_808000F0_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800020_chlavaarchgrill3switches();
    func_80800020_chlavaarchgrill3switches(arg0, arg1, arg2, 0x63, 0x64);
}

OSThread *chlavaarchgrill3switches_entrypoint_0(void)
{
    extern u8 D_808001F0_chlavaarchgrill3switches[];

    return (OSThread *) D_808001F0_chlavaarchgrill3switches;
}

/* extern */

void func_80800124_chlavaarchgrill3switches(s32 arg0) {
    s32 _chswitch_entrypoint_8(s32, s32);
    func_80800000_chlavaarchgrill3switches(arg0, 0xA1E);
    _chswitch_entrypoint_8(arg0, 0x400);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill3switches/func_80800154_chlavaarchgrill3switches.s")

OSThread *chlavaarchgrill3switches_entrypoint_1(void)
{
    extern u8 D_80800238_chlavaarchgrill3switches[];

    return (OSThread *) D_80800238_chlavaarchgrill3switches;
}

/* extern */

void func_80800188_chlavaarchgrill3switches(s32 arg0) {
    s32 _chswitch_entrypoint_8(s32, s32);
    func_80800000_chlavaarchgrill3switches(arg0, 0xA1F);
    _chswitch_entrypoint_8(arg0, 0x200);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/archgrill3switches/func_808001B8_chlavaarchgrill3switches.s")

OSThread *chlavaarchgrill3switches_entrypoint_2(void)
{
    extern u8 D_80800280_chlavaarchgrill3switches[];

    return (OSThread *) D_80800280_chlavaarchgrill3switches;
}
