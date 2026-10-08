#include "common.h"

OSThread *chnutsnbolts_entrypoint_0(void)
{
    extern u8 D_80800E28_chnutsnbolts[];

    return (OSThread *) D_80800E28_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_1(void)
{
    extern u8 D_80800E70_chnutsnbolts[];

    return (OSThread *) D_80800E70_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_2(void)
{
    extern u8 D_80800EB8_chnutsnbolts[];

    return (OSThread *) D_80800EB8_chnutsnbolts;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800024_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800080_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_808005D0_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_808008FC_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_8080092C_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800A88_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800B80_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800BD4_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800C04_chnutsnbolts.s")
