#include "common.h"

OSThread *chklungoleave_entrypoint_0(void)
{
    extern u8 D_80800130_chklungoleave[];

    return (OSThread *) D_80800130_chklungoleave;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/leave/func_8080000C_chklungoleave.s")

void func_80800038_chklungoleave(s32 arg0)
{
    func_80105834();
    func_808000F0_chklungoleave(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/leave/func_80800060_chklungoleave.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/leave/func_808000F0_chklungoleave.s")
