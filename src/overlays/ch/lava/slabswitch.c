#include "ch/lavaslabswitch.h"

/* extern */

s32 func_80800000_chlavaslabswitch(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _chswitch_entrypoint_10(s32 *);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x250, 0x7, 0);
        _capod_entrypoint_13(*arg0, 0, 22, 0x10);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0);
}

void func_8080005C_chlavaslabswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_38F_UNK);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chlavaslabswitch_entrypoint_0(void)
{
    extern u8 D_808000A0_chlavaslabswitch[];

    return (OSThread *) D_808000A0_chlavaslabswitch;
}
