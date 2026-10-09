#include "common.h"

s32 ncba1p_entrypoint_0() 
{
    return 0x54;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_80800008_ncba1p.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_8080004C_ncba1p.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_808000A0_ncba1p.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_80800230_ncba1p.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/func_808003DC_ncba1p.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_3.s")

void ncba1p_entrypoint_4(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 80) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_8.s")

f32 ncba1p_entrypoint_9(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 16);
}

s32 ncba1p_entrypoint_10(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 76);
}

f32 ncba1p_entrypoint_11(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 72);
}

void ncba1p_entrypoint_12(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0) + 72) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/1p/ncba1p_entrypoint_13.s")
