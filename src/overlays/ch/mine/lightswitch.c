#include "ch/minelightswitch.h"

s32 func_80800000_chminelightswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);

    switch (arg1) {
        case 7:
            if (func_800DA298(0x673) == 0) {
                _glcutDll_entrypoint_6(0xCF, 0x15);
            }
            break;
        case 8:
            if (func_800DA298(0x673) == 0) {
                func_800DA544(0x673);
                _glcutDll_entrypoint_6(0xCF, 0x15);
            }
            break;
        default:
            return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return 1;
}

void func_80800094_chminelightswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_9E0_UNK);
}

OSThread *chminelightswitch_entrypoint_0(void)
{
    extern u8 D_808000C0_chminelightswitch[];

    return (OSThread *) D_808000C0_chminelightswitch;
}
