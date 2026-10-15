#include "common.h"

void func_80800000_chlavaarchgrill3switches()
{
    _chswitch_entrypoint_7();
}

void func_80800020_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    switch (arg1) {
    case 7:
        func_80101180(0x288, arg3, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    case 8:
        func_80101180(0x288, arg4, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    default:
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
}

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

void func_80800154_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800020_chlavaarchgrill3switches();
    func_80800020_chlavaarchgrill3switches(arg0, arg1, arg2, 0x61, 0x62);
}

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

void func_808001B8_chlavaarchgrill3switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800020_chlavaarchgrill3switches();
    func_80800020_chlavaarchgrill3switches(arg0, arg1, arg2, 0x5D, 0x5E);
}

OSThread *chlavaarchgrill3switches_entrypoint_2(void)
{
    extern u8 D_80800280_chlavaarchgrill3switches[];

    return (OSThread *) D_80800280_chlavaarchgrill3switches;
}
