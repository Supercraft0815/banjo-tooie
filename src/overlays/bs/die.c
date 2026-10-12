#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/func_80800000_bsdie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_1.s")

/* extern */

void bsdie_entrypoint_2(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(s32, f32);
    s32 func_800A0CF4(s32, s32);
    _basudie_entrypoint_6();
    func_800A0CF4(arg0, 0);
    func_8009BF5C(arg0, 0);
    baroll_setIdeal(arg0, 0);
}

s32 bsdie_entrypoint_3(s32 arg0) {
    extern s32 D_80800960_bsdie[];
    return ((s32 *)&D_80800960_bsdie)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_6.s")

s32 bsdie_entrypoint_7(s32 arg0) {
    extern s32 D_80800970_bsdie[];
    return ((s32 *)&D_80800970_bsdie)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/die/bsdie_entrypoint_9.s")

/* extern */

void bsdie_entrypoint_10(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    s32 _basudie_entrypoint_6();
    void func_8009BF5C(s32, f32);
    _basudie_entrypoint_6();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
}

s32 bsdie_entrypoint_11(s32 arg0) {
    extern s32 D_80800980_bsdie[];
    return ((s32 *)&D_80800980_bsdie)[arg0];
}
