#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_80800000_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808000B0_chintroticker.s")

void func_80800188_chintroticker(u8 *arg0, s32 arg1) {
    s32 func_800167F4(void);
    void _chattract_entrypoint_1(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);

    if (arg1 == 0xA1 || arg1 == 0x18B || arg1 == 0x18E || arg1 == 0x194 || arg1 == 0x196) {
        switch (arg0[0x79] >> 4) {
        case 0:
            break;
        case 1:
            if (func_800167F4() != 0) {
                _chattract_entrypoint_1(3);
            }
            break;
        case 2:
            func_800DA544(0x578);
            break;
        case 3:
            func_800DA524(0x360);
            func_800DA524(0x3B);
            break;
        case 4:
            func_800DA544(0x360);
            func_800DA524(0x3B);
            func_800DA524(0x578);
            break;
        case 5:
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_80800254_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808002DC_chintroticker.s")

void func_808003BC_chintroticker(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808003C4_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808004A8_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_80800530_chintroticker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/ticker/func_808005AC_chintroticker.s")

OSThread *chintroticker_entrypoint_0(void)
{
    extern u8 D_80800934_chintroticker[];

    return (OSThread *) D_80800934_chintroticker;
}
