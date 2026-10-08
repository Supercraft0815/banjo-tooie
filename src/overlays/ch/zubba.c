#include "common.h"

OSThread *chzubba_entrypoint_0(void)
{
    extern u8 D_80800178_chzubba[];

    return (OSThread *) D_80800178_chzubba;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/zubba/func_8080000C_chzubba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/zubba/func_80800040_chzubba.s")
