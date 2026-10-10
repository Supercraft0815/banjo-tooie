#include "common.h"

OSThread *changlerbossflare_entrypoint_0(void)
{
    extern u8 D_80800480_changlerbossflare[];

    return (OSThread *) D_80800480_changlerbossflare;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_8080000C_changlerbossflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_80800068_changlerbossflare.s")

/* extern */

s32 func_80800154_changlerbossflare(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800190_changlerbossflare();
    switch (arg1) {
    case 0x40:
        func_80800190_changlerbossflare(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_80800190_changlerbossflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_8080021C_changlerbossflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_808003A4_changlerbossflare.s")
