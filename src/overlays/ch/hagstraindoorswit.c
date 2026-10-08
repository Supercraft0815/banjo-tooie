#include "ch/hagstraindoorswit.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hagstraindoorswit/func_80800000_chhagstraindoorswitch.s")

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
