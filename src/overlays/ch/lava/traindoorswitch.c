#include "ch/lavatraindoorswitch.h"

s32 func_80800000_chlavatraindoorswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x129U, 0x4DU);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_8080003C_chlavatraindoorswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D0_STATION_UNLOCKED_HFPL);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavatraindoorswitch_entrypoint_0(void)
{
    extern u8 D_80800080_chlavatraindoorswitch[];

    return (OSThread *) D_80800080_chlavatraindoorswitch;
}
