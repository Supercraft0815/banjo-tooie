#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statictor/func_80800000_chstatictorch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statictor/func_80800090_chstatictorch.s")

void func_808000E4_chstatictorch(s32 arg0) 
{
}
/* extern */

void func_808000EC_chstatictorch(Actor *arg0) {
    void func_800C2FDC(u8 id);
    void* func_80100094(Actor*, u32);
    s32 _suflamefx_entrypoint_1(Actor *, s32);
    u8 temp_a0;

    if (func_80100094(arg0, 1U) != NULL) {
        _suflamefx_entrypoint_1(arg0, 1);
    }
    temp_a0 = arg0->unk5F;
    if (temp_a0 != 0) {
        func_800C2FDC(temp_a0);
        arg0->unk5F = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statictor/func_80800140_chstatictorch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statictor/func_80800180_chstatictorch.s")

OSThread *chstatictorch_entrypoint_0(void)
{
    extern u8 D_80800248_chstatictorch[];

    return (OSThread *) D_80800248_chstatictorch;
}
