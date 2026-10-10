#include "ch/biggafoot.h"

OSThread *chbiggafoot_entrypoint_0(void)
{
    extern u8 D_80801094_chbiggafoot[];

    return (OSThread *) D_80801094_chbiggafoot;
}

OSThread *chbiggafoot_entrypoint_1(void)
{
    extern u8 D_808010DC_chbiggafoot[];

    return (OSThread *) D_808010DC_chbiggafoot;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800018_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800100_chbiggafoot.s")

void func_808004B0_chbiggafoot(s32 arg0)
{
    func_800DA524(FLAG2_6CD_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_808004D4_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800840_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_808008D4_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_808008FC_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800980_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_808009EC_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800A9C_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800BA4_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800C04_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800CDC_chbiggafoot.s")

void func_80800D38_chbiggafoot(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, 1.4f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800D5C_chbiggafoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/biggafoot/func_80800E2C_chbiggafoot.s")

void func_80800E98_chbiggafoot(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_80801244_chbiggafoot;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_80801244_chbiggafoot);
}
