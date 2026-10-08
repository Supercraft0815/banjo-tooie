#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sounder/func_80800000_chsounder.s")

void func_80800078_chsounder(s32 arg0) 
{
}
void func_80800080_chsounder(s32 arg0) 
{
}
OSThread *chsounder_entrypoint_0(void)
{
    extern u8 D_808000BC_chsounder[];

    return (OSThread *) D_808000BC_chsounder;
}
