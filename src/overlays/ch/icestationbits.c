#include "common.h"

OSThread *chicestationbits_entrypoint_0(void)
{
    extern u8 D_80800280_chicestationbits[];

    return (OSThread *) D_80800280_chicestationbits;
}

OSThread *chicestationbits_entrypoint_1(void)
{
    extern u8 D_808002C8_chicestationbits[];

    return (OSThread *) D_808002C8_chicestationbits;
}

/* extern */

void func_80800018_chicestationbits(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    _chswitch_entrypoint_7(arg0, 0x1CF);
    _chswitch_entrypoint_9(arg0);
    _chswitch_entrypoint_8(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_80800050_chicestationbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_808000D4_chicestationbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icestationbits/func_808001E0_chicestationbits.s")
