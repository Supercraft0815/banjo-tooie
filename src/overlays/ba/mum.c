#include "common.h"

s32 bamum_entrypoint_0() 
{
    return 0x8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/mum/func_80800008_bamum.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/mum/func_80800018_bamum.s")

void bamum_entrypoint_1(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/mum/bamum_entrypoint_2.s")

void bamum_entrypoint_3()
{
    func_80800018_bamum();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/mum/bamum_entrypoint_4.s")

void bamum_entrypoint_5(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 208) + 4) = arg1;
}
