#include "common.h"

OSThread *chtransparencypot_entrypoint_0(void)
{
    extern u8 D_808001B0_chtransparencypot[];

    return (OSThread *) D_808001B0_chtransparencypot;
}

void func_8080000C_chtransparencypot(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 0.5f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparencypot/func_8080001C_chtransparencypot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparencypot/func_808000B8_chtransparencypot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparencypot/func_80800104_chtransparencypot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/transparencypot/func_80800148_chtransparencypot.s")
