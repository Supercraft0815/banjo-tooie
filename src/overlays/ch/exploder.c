#include "common.h"

OSThread *chexploder_entrypoint_0(void)
{
    extern u8 D_80801AE0_chexploder[];

    return (OSThread *) D_80801AE0_chexploder;
}

void func_8080000C_chexploder(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_80800014_chexploder.s")

/* extern */

void func_80800078_chexploder(void **arg0) {
    s32 func_800ADFE0(s16);
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(*arg0) + (0x10)));
    if (temp_a1 != 0) {
        func_800ADFE0(temp_a1);
        (*(s16 *)((s8 *)(*arg0) + (0x10))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_808000C0_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_80800154_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_808002FC_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_8080067C_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_80800834_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_80800A18_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_80800AC8_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_80800D7C_chexploder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/func_80800F74_chexploder.s")

/* extern */

void func_808010E0_chexploder(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80018820(s32, s32, s32);
    s32 func_800E1610(s32, s32, s32, s32);
    s32 func_800FFAB0(s32);
    if (arg2 & 2) {
        func_800E1610(0, 0x41F00000, 0x3F666666, arg0 + 4);
    }
    if (arg2 & 1) {
        func_80018820(0, 0x40400000, 0x3E800000);
    }
    if ((arg1 != 0) && (arg2 & 8)) {
        func_800FFAB0(arg1);
    }
    if (arg2 & 0x40) {
        (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    }
}

void func_80801188_chexploder(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 * func_800B26F0(u8 *arg0);
    if (func_800B26F0(arg1) != NULL) {
        arg0[0x70] = (u8)((arg0[0x70] & ~1) | 1);
        (*(u8 *)((s8 *)(arg0) + (0x71))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x71))) & 0xFFDF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/chexploder_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/chexploder_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/chexploder_entrypoint_3.s")

/* extern */

void chexploder_entrypoint_4(s32 arg0, s16 *arg1, s32 arg2) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    s32 chexploder_entrypoint_3(s32, f32 *, s32);
    f32 sp1C[3];

    func_800EE88C(sp1C, arg1);
    chexploder_entrypoint_3(arg0, sp1C, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/chexploder_entrypoint_5.s")

void chexploder_entrypoint_6(Actor *arg0, f32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(temp_v0) + (0))) = (s16) (s32) arg1;
    (*(s16 *)((s8 *)(temp_v0) + (2))) = (s16) (s32) arg2;
}

void chexploder_entrypoint_7(Actor *arg0, f32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(temp_v0) + (8))) = (s16) (s32) arg1;
    (*(s16 *)((s8 *)(temp_v0) + (0xA))) = (s16) (s32) arg2;
}

void chexploder_entrypoint_8(Actor *arg0, f32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(temp_v0) + (4))) = (s16) (s32) arg1;
    (*(s16 *)((s8 *)(temp_v0) + (6))) = (s16) (s32) arg2;
}

void chexploder_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)((temp_v0 + arg1)) + (0x18))) = (s8) arg2;
    if ((s32) (*(u8 *)((s8 *)(temp_v0) + (0x18))) < arg1) {
        (*(u8 *)((s8 *)(temp_v0) + (0x18))) = (u8) arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/chexploder_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/chexploder_entrypoint_11.s")

void chexploder_entrypoint_12(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0xC))) = (s16) (s32) (arg0->scale * (f32) arg1);
}

void chexploder_entrypoint_13(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x12))) = (s8) arg1;
}

void chexploder_entrypoint_14(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0x10))) = (s16) arg1;
}

void chexploder_entrypoint_15(Actor *arg0, s32 arg1, f32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)(temp_v0) + (0x13))) = (s8) arg1;
    (*(f32 *)((s8 *)(temp_v0) + (0x58))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/exploder/chexploder_entrypoint_16.s")
