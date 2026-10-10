#include "su/baddiefade.h"

u32 subaddiefade_entrypoint_0(u8 *arg0) {
    return arg0[155];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_1.s")

void subaddiefade_entrypoint_2(void *arg0) {
    (*(s8 *)((s8 *)(arg0) + (0x9B))) = 0;
    (*(u8 *)((s8 *)(arg0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x79))) & 0xFFFC) | 1);
}

void subaddiefade_entrypoint_3(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x79))) & 0xFFFC) | 2);
}

void subaddiefade_entrypoint_4(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x79))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x79))) & 0xFFFC) | 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_7.s")

/* extern */

void subaddiefade_entrypoint_8(void *arg0, s32 arg1) {
    s8 func_800F0D90(s32, s32, s32);
    (*(s8 *)((s8 *)(arg0) + (0x9B))) = func_800F0D90(arg1, 0, 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_9.s")

void subaddiefade_entrypoint_10(void *arg0, f32 *arg1) {
    s32 func_800F2EFC();
    func_800F2EFC(arg1, (u8 *)arg0 + 0x98);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/func_80800450_subaddiefade.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/fade/subaddiefade_entrypoint_14.s")
