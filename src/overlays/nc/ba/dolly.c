#include "common.h"

s32 ncbadolly_entrypoint_0() 
{
    return 0x2C;
}

void ncbadolly_entrypoint_1(u8 *arg0) {
    s32 func_801124D0(s32, s32);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x21))) = 1;
    func_801124D0((s32) arg0, 1);
}

void ncbadolly_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/dolly/ncbadolly_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/dolly/ncbadolly_entrypoint_4.s")
