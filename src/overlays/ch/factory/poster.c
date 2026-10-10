#include "common.h"

OSThread *chfactoryposter_entrypoint_0(void)
{
    extern u8 D_80800110_chfactoryposter[];

    return (OSThread *) D_80800110_chfactoryposter;
}

/* extern */

void func_8080000C_chfactoryposter(s32 arg0) {
    s32 func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    if (func_800DA298(0x3D) != 0) {
        func_800BF744(2, 2);
        func_800FFAB0(arg0);
        return;
    }
    func_800BF744(2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/poster/func_8080005C_chfactoryposter.s")
