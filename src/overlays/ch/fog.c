#include "common.h"

/* extern */

void func_80800000_chfog(s32 arg0) {
    s32 func_800CF494();
    func_800CF494();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fog/func_80800020_chfog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fog/func_80800174_chfog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fog/func_8080032C_chfog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fog/func_808009F0_chfog.s")

OSThread *chfog_entrypoint_0(void)
{
    extern u8 D_80800A90_chfog[];

    return (OSThread *) D_80800A90_chfog;
}
