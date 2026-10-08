#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/statemem/bastatemem_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/statemem/bastatemem_entrypoint_1.s")

void bastatemem_entrypoint_2(s32 arg0) 
{
}
void bastatemem_entrypoint_3(void* arg0)
{
    *(s32*)((u8*)arg0 + 0x188) = 0;
}
