#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/func_80800220_subaddietaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_2.s")

void subaddietaxi_entrypoint_3(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_5.s")

/* extern */

void subaddietaxi_entrypoint_6(s32 *arg0, volatile f32 arg1) {
    void func_800DFF64(s32 *, s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];
    f32 scale = arg1;

    func_800EFA4C(sp1C, scale, scale, scale);
    func_800DFF64(arg0, 0x12, (s32)sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_11.s")

s32 subaddietaxi_entrypoint_12(u8 *arg0, s32 arg1) {
    return (*(f32 *)(arg0 + 0x34)) == 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_13.s")

/* extern */

void subaddietaxi_entrypoint_14(s32 arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(s32, s32);
    void *func_8010410C();
    (*(s16 *)((s8 *)(func_8010410C()) + (0x20))) = 0;
    _subaddieDll_entrypoint_4(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/func_80800C00_subaddietaxi.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/taxi/subaddietaxi_entrypoint_16.s")

s32 func_80800CF0_subaddietaxi(s32 arg0) {
    extern s16 D_80800DB4_subaddietaxi[];
    return ((s16 *)&D_80800DB4_subaddietaxi)[arg0];
}
