#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/perspexboxswit/func_80800000_chperspexboxswitch.s")

/* extern */

void func_80800080_chperspexboxswitch(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 func_80104E78(s32);
    _chswitch_entrypoint_7(arg0, 0x43A);
    _chswitch_entrypoint_8(arg0, 0x201);
    _chswitch_entrypoint_9(arg0);
    func_80104E78(arg0);
}

OSThread *chperspexboxswitch_entrypoint_0(void)
{
    extern u8 D_808000D0_chperspexboxswitch[];

    return (OSThread *) D_808000D0_chperspexboxswitch;
}
