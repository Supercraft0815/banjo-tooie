#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/func_80800000_gctransitionDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/func_8080004C_gctransitionDll.s")

/* extern */

void func_80800098_gctransitionDll(s32 *arg0, f32 *arg1) {
    f32 func_800A8AF0(s32);
    *arg1 *= func_800A8AF0(*arg0) * 0.75f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/func_808000D8_gctransitionDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_0.s")

/* extern */

void gctransitionDll_entrypoint_1(s32 arg0) {
    s32 func_800EA05C();
    void *func_80800000_gctransitionDll(u8);
    void *func_8080004C_gctransitionDll(s32);
    s32 func_808000D8_gctransitionDll(s32, u8, void *);
    void *temp_v0;

    temp_v0 = func_80800000_gctransitionDll((*(u8 *)((s8 *)(func_8080004C_gctransitionDll(func_800EA05C())) + (2))));
    func_808000D8_gctransitionDll(arg0, (*(u8 *)((s8 *)(temp_v0) + (1))), temp_v0);
}

s32 gctransitionDll_entrypoint_2(void *arg0) {
    return (*(u8 *)((s8 *)(arg0) + (0x1C))) == 1;
}

s32 gctransitionDll_entrypoint_3(void *arg0) {
    return (*(u8 *)((s8 *)(arg0) + (0x1C))) != 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_9.s")
