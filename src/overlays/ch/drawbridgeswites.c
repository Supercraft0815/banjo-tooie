#include "common.h"

s32 func_80800000_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    _chswitch_entrypoint_7(arg0, arg1);
    _chswitch_entrypoint_8(arg0, arg2);
}

void func_80800030_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    switch (arg1) {
    case 7:
        func_80101180(0x49F, arg3, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    case 8:
        func_80101180(0x49F, arg4, 0);
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    default:
        _chswitch_entrypoint_10(arg0, arg1, arg2);
        return;
    }
}

void func_808000D0_chdrawbridgeswitches(s32 arg0) {
    s32 func_80800000_chdrawbridgeswitches(s32, s32, s32);
    func_80800000_chdrawbridgeswitches(arg0, 0xA20, 512);
}

void func_808000F4_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chdrawbridgeswitches();
    func_80800030_chdrawbridgeswitches(arg0, arg1, arg2, 0x69, 0x68);
}

OSThread *chdrawbridgeswitches_entrypoint_0(void)
{
    extern u8 D_80800210_chdrawbridgeswitches[];

    return (OSThread *) D_80800210_chdrawbridgeswitches;
}

void func_80800128_chdrawbridgeswitches(s32 arg0) {
    s32 func_80800000_chdrawbridgeswitches(s32, s32, s32);
    func_80800000_chdrawbridgeswitches(arg0, 0xA21, 1024);
}

void func_8080014C_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chdrawbridgeswitches();
    func_80800030_chdrawbridgeswitches(arg0, arg1, arg2, 0x6B, 0x6A);
}

OSThread *chdrawbridgeswitches_entrypoint_1(void)
{
    extern u8 D_80800258_chdrawbridgeswitches[];

    return (OSThread *) D_80800258_chdrawbridgeswitches;
}

/* extern */

void func_80800180_chdrawbridgeswitches(s32 arg0) {
    s32 _chswitch_entrypoint_9(s32);
    func_80800000_chdrawbridgeswitches(arg0, 0x58E, 1);
    _chswitch_entrypoint_9(arg0);
}

void func_808001B0_chdrawbridgeswitches(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x395, 7, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chdrawbridgeswitches_entrypoint_2(void)
{
    extern u8 D_808002A0_chdrawbridgeswitches[];

    return (OSThread *) D_808002A0_chdrawbridgeswitches;
}
