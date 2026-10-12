#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800000_chflysaucer.s")

/* extern */

void func_8080003C_chflysaucer(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 func_800DA7A8(s32, s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    func_800DA7A8(0xA34, arg1, 3);
    (*(s8 *)((s8 *)(sp1C) + (0x26))) = (s8) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800080_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_8080013C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808001B4_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800388_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800424_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808004B0_chflysaucer.s")

void func_808004F0_chflysaucer(void) {
    s32 func_808017D0_chflysaucer();
    extern s32 D_80127194;
    (*(s16 *)((s8 *)(&D_80127194) + (0x434))) = 0;
    func_808017D0_chflysaucer();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800514_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808005FC_chflysaucer.s")

s16 func_80800728_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    extern s16 D_808045DA_chflysaucer[];
    return D_808045DA_chflysaucer[*((u8 *)func_80100094(arg0, 0U) + 0x26)];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800758_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808007C4_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808009DC_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800C3C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800DAC_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800E48_chflysaucer.s")

/* extern */

void func_80800F98_chflysaucer(void) {
    s32 func_800FC6B0(s32);
    u32 func_80800E48_chflysaucer();
    u32 temp_v0;

    temp_v0 = func_80800E48_chflysaucer();
    switch (temp_v0) {
    case 0:
    case 5:
        func_800FC6B0(0x17);
        return;
    case 1:
    case 2:
    case 3:
    case 4:
        func_800FC6B0(0x16);
        /* fallthrough */
    default:
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80800FF0_chflysaucer.s")

void func_80801034_chflysaucer(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (4))) = -7800.0f;
    (*(f32 *)((s8 *)(arg0) + (8))) = 1700.0f;
    (*(f32 *)((s8 *)(arg0) + (0xC))) = -2900.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_8080105C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80801130_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808012A4_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808013B4_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80801428_chflysaucer.s")

void func_8080149C_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_801042D8(s32);
    s16 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*temp_v0 != 0) {
        func_801042D8((s32) temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/chflysaucer_entrypoint_0.s")

void func_80801534_chflysaucer(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_801042D8(s32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(s16 *)((s8 *)(temp_v0) + (2))) != 0) {
        func_801042D8((s32) (temp_v0 + 2));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80801568_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808017D0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_8080185C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80801E98_chflysaucer.s")

/* extern */

void func_80802014_chflysaucer(s32 arg0) {
    void func_8008FB10(s32, f32, f32, f32);
    func_8008FB10(arg0 + 4, 65.0f, 0.0f, 90.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802044_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802114_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808021C0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802290_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808024E0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802CF0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80802ED8_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803150_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808031C8_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803224_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_8080329C_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808035C4_chflysaucer.s")

OSThread *chflysaucer_entrypoint_1(void)
{
    extern u8 D_80804668_chflysaucer[];

    return (OSThread *) D_80804668_chflysaucer;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803844_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808038C4_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_808039B8_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803AF0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803B60_chflysaucer.s")

void func_80803BE8_chflysaucer(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803BF0_chflysaucer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803C3C_chflysaucer.s")

void func_80803CC4_chflysaucer(s32 arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808046DC_chflysaucer;
    s32 sp24;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(6);
    temp_a1 = arg0 + 4;
    sp24 = temp_v0;
    func_800BABB8(temp_v0, temp_a1, temp_a1, 0x3FB33333, &D_808046DC_chflysaucer);
    func_800BA3FC(sp24, arg1);
    func_800BA22C(sp24, 6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucer/func_80803D30_chflysaucer.s")

OSThread *chflysaucer_entrypoint_2(void)
{
    extern u8 D_8080470C_chflysaucer[];

    return (OSThread *) D_8080470C_chflysaucer;
}
