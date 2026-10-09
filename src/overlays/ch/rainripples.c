#include "common.h"

OSThread *chrainripples_entrypoint_0(void)
{
    extern u8 D_80800290_chrainripples[];

    return (OSThread *) D_80800290_chrainripples;
}

/* extern */

void func_8080000C_chrainripples(void *arg0) {
    f32 func_808001FC_chrainripples();
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (func_808001FC_chrainripples() + 4.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainripples/func_80800040_chrainripples.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/rainripples/func_808001FC_chrainripples.s")
