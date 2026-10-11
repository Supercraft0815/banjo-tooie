#include "common.h"

s32 func_80800000_chminegrill2switches(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    _chswitch_entrypoint_7(arg0, arg1);
    _chswitch_entrypoint_8(arg0, arg2);
}

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

void func_808000B8_chminegrill2switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chminegrill2switches();
    func_80800030_chminegrill2switches(arg0, arg1, arg2, 0x7A, 0x79);
}

OSThread *chminegrill2switches_entrypoint_0(void)
{
    extern u8 D_80800150_chminegrill2switches[];

    return (OSThread *) D_80800150_chminegrill2switches;
}

void func_808000EC_chminegrill2switches(s32 arg0) {
    s32 func_80800000_chminegrill2switches(s32, s32, s32);
    func_80800000_chminegrill2switches(arg0, 0xA28, 1024);
}

void func_80800110_chminegrill2switches(s32 arg0, s32 arg1, s32 arg2) {
    void func_80800030_chminegrill2switches();
    func_80800030_chminegrill2switches(arg0, arg1, arg2, 0x7C, 0x7B);
}

OSThread *chminegrill2switches_entrypoint_1(void)
{
    extern u8 D_80800198_chminegrill2switches[];

    return (OSThread *) D_80800198_chminegrill2switches;
}
