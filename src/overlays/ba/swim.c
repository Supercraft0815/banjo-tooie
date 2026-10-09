#include "common.h"

s32 baswim_entrypoint_0() 
{
    return 0x8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_3.s")

void baswim_entrypoint_4()
{
    bastick_resetZones();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_7.s")

void baswim_entrypoint_8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 4) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/func_808003B8_baswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_13.s")

f32 baswim_entrypoint_14(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 0);
}
