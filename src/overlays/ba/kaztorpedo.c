#include "common.h"

s32 bakaztorpedo_entrypoint_0() 
{
    return 0x20;
}

f32 bakaztorpedo_entrypoint_1(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 16);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/kaztorpedo/bakaztorpedo_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/kaztorpedo/bakaztorpedo_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/kaztorpedo/bakaztorpedo_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/kaztorpedo/bakaztorpedo_entrypoint_5.s")

void bakaztorpedo_entrypoint_6(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 12) = arg1;
}

void bakaztorpedo_entrypoint_7(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 176) + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/kaztorpedo/bakaztorpedo_entrypoint_8.s")
