#include "common.h"

OSThread *chminelobbydoor_entrypoint_0(void)
{
    extern u8 D_808001F0_chminelobbydoor[];

    return (OSThread *) D_808001F0_chminelobbydoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/lobbydoor/func_8080000C_chminelobbydoor.s")

void func_808000A8_chminelobbydoor(s32 arg0)
{
    func_808000D0_chminelobbydoor();
    _chdoor_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/lobbydoor/func_808000D0_chminelobbydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/lobbydoor/func_8080018C_chminelobbydoor.s")
