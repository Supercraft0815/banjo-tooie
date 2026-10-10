#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/traindoorswitch/func_80800000_chdinotraindoorswitch.s")

/* extern */

void func_8080003C_chdinotraindoorswitch(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 func_80104E78(s32);
    _chswitch_entrypoint_7(arg0, 0x164);
    _chswitch_entrypoint_9(arg0);
    func_80104E78(arg0);
}

OSThread *chdinotraindoorswitch_entrypoint_0(void)
{
    extern u8 D_80800080_chdinotraindoorswitch[];

    return (OSThread *) D_80800080_chdinotraindoorswitch;
}
