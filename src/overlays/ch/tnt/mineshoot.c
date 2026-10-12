#include "common.h"

void func_80800000_chtntmineshoot(Actor *arg0) { extern s32 D_80802590_chtntmineshoot; extern s32 D_8080259C_chtntmineshoot; f32 *sp1C[2]; sp1C[1] = arg0->position; func_800C4AF0(sp1C[1], &D_80802590_chtntmineshoot);
    func_800C4AF0(sp1C[1], &D_8080259C_chtntmineshoot);
}

void func_8080003C_chtntmineshoot(s32 arg0) {
    s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
    extern s32 D_808025A8_chtntmineshoot;
    func_800BBCB8((f32 *)(arg0 + 4), 0, 1.0f, 4, &D_808025A8_chtntmineshoot);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800078_chtntmineshoot.s")

void func_80800150_chtntmineshoot(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808025DC_chtntmineshoot;
    _subaddieaudioloop_entrypoint_4(arg0, (f32 *) ((u8 *) arg0 + 4), 1U, &D_808025DC_chtntmineshoot);
    arg0->unk5F = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800188_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800228_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800280_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800440_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808004BC_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808005AC_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808006D0_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800830_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800A1C_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800AD0_chtntmineshoot.s")

void func_80800BCC_chtntmineshoot(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)(temp_v0) + (1))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (4))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800BF4_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800C90_chtntmineshoot.s")

OSThread *chtntmineshoot_entrypoint_0(void)
{
    extern u8 D_80802690_chtntmineshoot[];

    return (OSThread *) D_80802690_chtntmineshoot;
}

/* extern */

void func_80800E10_chtntmineshoot(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 func_800C2E04(void);
    void func_800C330C(u8 id, s32);
    void* func_80100094(Actor*, u32);
    void func_800C431C(u8, s32);
    struct { u8 pad[12]; u8 id; } *sp1C;

    sp1C = func_80100094(arg0, 0U);
    sp1C->id = func_800C2E04();
    func_800C330C(sp1C->id, 3);
    func_800C431C(sp1C->id, 0);
    _susubgame_entrypoint_11(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800E64_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801128_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808011D4_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801318_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_8080146C_chtntmineshoot.s")

void func_80801604_chtntmineshoot(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    void func_800C2FDC(u8 id);
    void func_800D284C(u32 a0);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 temp_a0;

    sp1C = func_80100094(arg0, 0U);
    _susubgame_entrypoint_11(0);
    func_800D284C(0x102U);
    temp_a0 = (*(u8 *)((s8 *)(sp1C) + (0xC)));
    if (temp_a0 != 0) {
        func_800C2FDC(temp_a0);
        (*(u8 *)((s8 *)(sp1C) + (0xC))) = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801658_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801714_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801974_chtntmineshoot.s")

/* extern */

s32 func_80801A18_chtntmineshoot(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800D211C(s32);
    if (arg1 == 0xFB3) {
        return func_800D211C(0x95);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801A54_chtntmineshoot.s")

OSThread *chtntmineshoot_entrypoint_1(void)
{
    extern u8 D_808026D8_chtntmineshoot[];

    return (OSThread *) D_808026D8_chtntmineshoot;
}

void func_80801BA0_chtntmineshoot(void) {
    s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    struct Vec { f32 v[3]; };
    extern struct Vec D_80802720_chtntmineshoot;
    extern s32 D_8080272C_chtntmineshoot;
    struct Vec sp24;

    sp24 = D_80802720_chtntmineshoot;
    func_800BBCB8(sp24.v, 0, 1.0f, 2, &D_8080272C_chtntmineshoot);
    func_800E1610(0, 20.0f, 0.9f, sp24.v);
}

void func_80801C10_chtntmineshoot(s32 arg0) 
{
}
void func_80801C18_chtntmineshoot(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801C20_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801D6C_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801DEC_chtntmineshoot.s")

OSThread *chtntmineshoot_entrypoint_2(void)
{
    extern u8 D_80802774_chtntmineshoot[];

    return (OSThread *) D_80802774_chtntmineshoot;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801F90_chtntmineshoot.s")

void func_80802140_chtntmineshoot(s32 arg0) 
{
}
/* extern */

void func_80802148_chtntmineshoot(void *arg0, s32 arg1) {
    s32 func_800DF5D8(u8, u8, u8, u8);
    s32 func_80101870(void *, s32);
    s32 func_80802320_chtntmineshoot(void *);
    func_800DF5D8((*(u8 *)((s8 *)(arg0) + (0x98))), (*(u8 *)((s8 *)(arg0) + (0x99))), (*(u8 *)((s8 *)(arg0) + (0x9A))), (*(u8 *)((s8 *)(arg0) + (0x9B))));
    func_80101870(arg0, arg1);
    func_80802320_chtntmineshoot(arg0);
}

/* extern */

void func_80802198_chtntmineshoot(s32 arg0) {
    s32 func_808021C4_chtntmineshoot();
    s32 func_808022A8_chtntmineshoot(s32, s32);
    func_808022A8_chtntmineshoot(arg0, func_808021C4_chtntmineshoot());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808021C4_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808022A8_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80802320_chtntmineshoot.s")

OSThread *chtntmineshoot_entrypoint_3(void)
{
    extern u8 D_808028E4_chtntmineshoot[];

    return (OSThread *) D_808028E4_chtntmineshoot;
}
