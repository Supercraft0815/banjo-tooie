#include "common.h"

OSThread *chcamerawibble_entrypoint_0(void)
{
    extern u8 D_808000E0_chcamerawibble[];

    return (OSThread *) D_808000E0_chcamerawibble;
}

void func_8080000C_chcamerawibble(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x24) = (f32)((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) * 10.0f;
    *(f32 *)((u8 *)arg0 + 0x54) = *(f32 *)((u8 *)arg0 + 0x38);
}

void func_8080004C_chcamerawibble()
{
    func_8080006C_chcamerawibble();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/camerawibble/func_8080006C_chcamerawibble.s")
