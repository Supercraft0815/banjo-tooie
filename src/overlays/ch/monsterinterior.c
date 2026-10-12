#include "common.h"

OSThread *chmonsterinterior_entrypoint_0(void)
{
    extern u8 D_80801E80_chmonsterinterior[];

    return (OSThread *) D_80801E80_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_1(void)
{
    extern u8 D_80801EC8_chmonsterinterior[];

    return (OSThread *) D_80801EC8_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_2(void)
{
    extern u8 D_80801F10_chmonsterinterior[];

    return (OSThread *) D_80801F10_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_3(void)
{
    extern u8 D_80801F58_chmonsterinterior[];

    return (OSThread *) D_80801F58_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_4(void)
{
    extern u8 D_80801FA0_chmonsterinterior[];

    return (OSThread *) D_80801FA0_chmonsterinterior;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_8080003C_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808000BC_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808002D4_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_8080060C_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_8080068C_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_8080078C_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808009C0_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80800A44_chmonsterinterior.s")

void func_80800BC8_chmonsterinterior(u8 **arg0, s32 arg1) {
    s32 func_800D3948(void);
    void func_801032B0(void *, u16, u16);
    extern u16 D_80801FE8_chmonsterinterior[];
    extern u16 D_80801FF0_chmonsterinterior[];
    if (func_800D3948() != 0) {
        func_801032B0(arg0, D_80801FF0_chmonsterinterior[arg1], *(u16 *)(*arg0 + 0x16));
        return;
    }
    func_801032B0(arg0, D_80801FE8_chmonsterinterior[arg1], *(u16 *)(*arg0 + 0x16));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80800C38_chmonsterinterior.s")

/* extern */

void func_80800DA4_chmonsterinterior(Actor *arg0) {
    void _subaddiemulti_entrypoint_3(s32);
    void* func_80100094(Actor*, u32);
    s32 _sumultiscore_entrypoint_3(u8 *);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _subaddiemulti_entrypoint_3(0xA);
    arg0->unk6C_0 = 5;
    _sumultiscore_entrypoint_3(sp1C + 0x28);
    _sumultiscore_entrypoint_4(sp1C + 0x28, 8, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80800E0C_chmonsterinterior.s")

void func_8080101C_chmonsterinterior(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumultiscore_entrypoint_12(s32, s32, s32);
    _sumultiscore_entrypoint_12((s32)func_80100094(arg0, 0U) + 0x28, arg1, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80801050_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80801114_chmonsterinterior.s")

s32 func_80801180_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    if (arg1 == 0x17F8) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))) + 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808011BC_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808013D0_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808014E8_chmonsterinterior.s")

void func_808017E8_chmonsterinterior(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_808017F0_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80801930_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80801ADC_chmonsterinterior.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/monsterinterior/func_80801B7C_chmonsterinterior.s")

/* extern */
s32 func_80801C1C_chmonsterinterior(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800D9078((f32 *) (arg0 + 0x28));
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, 0.0f, -250.0f);
    return sp24;
}

/* extern */

s32 func_80801C78_chmonsterinterior(u8 *arg0) {
    u8 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp28;

    sp28 = func_800D9078((f32 *) (arg0 + 0x28));
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, -250.0f, 0.0f);
    return sp28;
}
