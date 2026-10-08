#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/func_80800000_idwibble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_0.s")

void idwibble_entrypoint_1(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/func_80800324_idwibble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wibble/idwibble_entrypoint_4.s")

void idwibble_entrypoint_5(void *arg0, s16 arg1) {
    (*(s16 *)((s8 *)(arg0) + (0x34))) = arg1;
}
