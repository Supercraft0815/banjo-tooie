#include "common.h"

OSThread *chmumboskulls_entrypoint_0(void)
{
    extern u8 D_808000C0_chmumboskulls[];

    return (OSThread *) D_808000C0_chmumboskulls;
}

void func_8080000C_chmumboskulls(s32 arg0)
{
    func_8010A800(arg0,1);
}

void func_8080002C_chmumboskulls(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/skulls/func_80800034_chmumboskulls.s")

void func_8080007C_chmumboskulls(Actor *arg0) {
    s32 index = arg0->unk74_7;
    extern u16 D_80800108_chmumboskulls[];
    index -= 0x32;
    func_80103140(arg0, D_80800108_chmumboskulls[index], 0U);
}
