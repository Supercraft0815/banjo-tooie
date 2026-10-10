#include "common.h"

OSThread *chprisonbits_entrypoint_0(void)
{
    extern u8 D_80800F78_chprisonbits[];

    return (OSThread *) D_80800F78_chprisonbits;
}

OSThread *chprisonbits_entrypoint_1(void)
{
    extern u8 D_80800FC0_chprisonbits[];

    return (OSThread *) D_80800FC0_chprisonbits;
}

OSThread *chprisonbits_entrypoint_2(void)
{
    extern u8 D_80801008_chprisonbits[];

    return (OSThread *) D_80801008_chprisonbits;
}

OSThread *chprisonbits_entrypoint_3(void)
{
    extern u8 D_80801050_chprisonbits[];

    return (OSThread *) D_80801050_chprisonbits;
}

OSThread *chprisonbits_entrypoint_4(void)
{
    extern u8 D_808010A8_chprisonbits[];

    return (OSThread *) D_808010A8_chprisonbits;
}

void func_8080003C_chprisonbits()
{
    _chswitch_entrypoint_7();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_8080005C_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_808000C0_chprisonbits.s")

void func_808001E0_chprisonbits(s32 arg0)
{
    func_8080003C_chprisonbits(arg0,1);
}

void func_80800200_chprisonbits(s32 arg0) {
    s32 func_8080005C_chprisonbits(s32, s32, s32);
    func_8080005C_chprisonbits(arg0, 0x2, 175);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800224_chprisonbits.s")

void func_80800280_chprisonbits()
{
    func_800DA298();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_808002A0_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800344_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_8080044C_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800518_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_8080090C_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800970_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_808009C4_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800BB4_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800C18_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800C84_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800CC4_chprisonbits.s")

/* extern */

void func_80800DAC_chprisonbits(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_800CD08C(s32, u8 *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_800CD08C(((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) - 1, temp_v0);
    (*(f32 *)((s8 *)(sp1C) + (4))) = (f32) arg0->position[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/func_80800DFC_chprisonbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/prisonbits/chprisonbits_entrypoint_5.s")
