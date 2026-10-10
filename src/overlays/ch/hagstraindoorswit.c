#include "ch/hagstraindoorswit.h"

s32 func_80800000_chhagstraindoorswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x38C, 7, 0);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800040_chhagstraindoorswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_403_STATION_UNLOCKED_IoH);
    _chswitch_entrypoint_9(arg0);
}

OSThread *chhagstraindoorswitch_entrypoint_0(void)
{
    extern u8 D_80800080_chhagstraindoorswitch[];

    return (OSThread *) D_80800080_chhagstraindoorswitch;
}
