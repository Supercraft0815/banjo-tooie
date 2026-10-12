#include "common.h"

OSThread *chalienbeam_entrypoint_0(void)
{
    extern u8 D_808001A0_chalienbeam[];

    return (OSThread *) D_808001A0_chalienbeam;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienbeam/func_8080000C_chalienbeam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienbeam/func_80800088_chalienbeam.s")

/* extern */

s32 func_80800110_chalienbeam(Actor *arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
    case 0x4F:
        _subaddiefade_entrypoint_3(arg0);
        func_80102424(arg0, 3);
        break;
    default:
        return 0;
    }
    return 1;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienbeam/func_8080015C_chalienbeam.s")
