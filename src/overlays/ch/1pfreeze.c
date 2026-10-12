#include "common.h"

OSThread *ch1pfreeze_entrypoint_0(void)
{
    extern u8 D_80800420_ch1pfreeze[];

    return (OSThread *) D_80800420_ch1pfreeze;
}

void func_8080000C_ch1pfreeze(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_80800014_ch1pfreeze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_80800054_ch1pfreeze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_8080014C_ch1pfreeze.s")

s32 func_80800294_ch1pfreeze(Actor *arg0, s32 arg1, s32 arg2) {
    void func_808002D0_ch1pfreeze(s16*, s32);
    switch (arg1) {
        case 0x4:
            func_808002D0_ch1pfreeze((s16 *) arg0, 0x4);
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_808002D0_ch1pfreeze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/ch1pfreeze_entrypoint_1.s")
