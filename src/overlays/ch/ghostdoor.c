#include "ch/ghostdoor.h"

OSThread *chghostdoor_entrypoint_0(void)
{
    extern u8 D_80800220_chghostdoor[];

    return (OSThread *) D_80800220_chghostdoor;
}

OSThread *chghostdoor_entrypoint_1(void)
{
    extern u8 D_80800268_chghostdoor[];

    return (OSThread *) D_80800268_chghostdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ghostdoor/func_80800018_chghostdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ghostdoor/func_808000F4_chghostdoor.s")

void func_80800190_chghostdoor(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_096_STATION_UNLOCKED_WW);
    _chswitch_entrypoint_9(arg0);
}

/* extern */

s32 func_808001BC_chghostdoor(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _chswitch_entrypoint_10(Actor *);
    s32 func_80101180(s32, s32, s32);
    int result;
    if (arg1 == 7) {
        _capod_entrypoint_13(arg0->unk0, 0, 5, 0x10);
        func_80101180(0x344, 7, 0);
        result = 1;
    } else {
        return _chswitch_entrypoint_10(arg0);
    }
    return result;
}
