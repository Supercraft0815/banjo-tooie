#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_80800000_chfootwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_808000B8_chfootwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_80800364_chfootwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_80800424_chfootwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/footwear/func_8080050C_chfootwear.s")

void func_80800644_chfootwear(s32 arg0, s32 arg1) { func_8080050C_chfootwear(arg0, arg1, 0); }

void func_80800664_chfootwear(s32 arg0,s32 arg1)
{
    func_8080050C_chfootwear(arg0,arg1,0x1);
}

OSThread *chfootwear_entrypoint_0(void)
{
    extern u8 D_80800788_chfootwear[];

    return (OSThread *) D_80800788_chfootwear;
}

OSThread *chfootwear_entrypoint_1(void)
{
    extern u8 D_808007D0_chfootwear[];

    return (OSThread *) D_808007D0_chfootwear;
}

OSThread *chfootwear_entrypoint_2(void)
{
    extern u8 D_80800818_chfootwear[];

    return (OSThread *) D_80800818_chfootwear;
}

OSThread *chfootwear_entrypoint_3(void)
{
    extern u8 D_80800860_chfootwear[];

    return (OSThread *) D_80800860_chfootwear;
}

OSThread *chfootwear_entrypoint_4(void)
{
    extern u8 D_808008A8_chfootwear[];

    return (OSThread *) D_808008A8_chfootwear;
}
