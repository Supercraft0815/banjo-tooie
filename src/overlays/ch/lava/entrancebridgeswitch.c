#include "ch/lavaentrancebridgeswitch.h"

/* extern */

s32 func_80800000_chlavaentrancebridgeswitch(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _chswitch_entrypoint_10(s32 *);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x38E, 0x60, 0);
        _capod_entrypoint_13(*arg0, 0, 5, 0x10);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0);
}

void func_8080005C_chlavaentrancebridgeswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_391_PROGRESS_IoH_HFP_BRIDGE_EXTENDED);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavaentrancebridgeswitch_entrypoint_0(void)
{
    extern u8 D_808000A0_chlavaentrancebridgeswitch[];

    return (OSThread *) D_808000A0_chlavaentrancebridgeswitch;
}
