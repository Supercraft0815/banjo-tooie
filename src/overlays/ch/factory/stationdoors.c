#include "common.h"

/* extern */

void func_80800000_chfactorystationdoors(s32 arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_80101FDC(s32, s32);
    if (_glcutDll_entrypoint_19(0x44) == 0) {
        if (func_800DA298(0x163) != 0) {
            func_800FFAB0(arg0);
            return;
        }
        func_80101FDC(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/stationdoors/func_80800054_chfactorystationdoors.s")

/* extern */

void func_80800158_chfactorystationdoors(s32 arg0, s32 arg1) {
    s32 func_800DF500(f32, f32, s32);
    s32 func_80101870(s32, s32);
    func_800DF500(1.07f, 1.65f, 0x3F800000);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/stationdoors/func_8080019C_chfactorystationdoors.s")

OSThread *chfactorystationdoors_entrypoint_0(void)
{
    extern u8 D_80800268_chfactorystationdoors[];

    return (OSThread *) D_80800268_chfactorystationdoors;
}
