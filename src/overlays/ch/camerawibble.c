#include "common.h"

OSThread *chcamerawibble_entrypoint_0(void)
{
    extern u8 D_808000E0_chcamerawibble[];

    return (OSThread *) D_808000E0_chcamerawibble;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/camerawibble/func_8080000C_chcamerawibble.s")

void func_8080004C_chcamerawibble()
{
    func_8080006C_chcamerawibble();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/camerawibble/func_8080006C_chcamerawibble.s")
