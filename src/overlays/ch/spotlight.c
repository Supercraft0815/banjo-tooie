#include "common.h"

OSThread *chspotlight_entrypoint_0(void)
{
    extern u8 D_808009B0_chspotlight[];

    return (OSThread *) D_808009B0_chspotlight;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_8080000C_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800210_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_8080047C_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800518_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800580_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800600_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_808006B8_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800730_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_808007F4_chspotlight.s")

/* extern */

s32 func_808008A4_chspotlight(void *arg0) {
    s32 func_800DA298(s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x3C))) == 0) {
        return 0;
    }
    if (func_800DA298(3) != 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_808008EC_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800934_chspotlight.s")
