#include "common.h"

OSThread *chdippy_entrypoint_0(void)
{
    extern u8 D_80801580_chdippy[];

    return (OSThread *) D_80801580_chdippy;
}

OSThread *chdippy_entrypoint_1(void)
{
    extern u8 D_808015C8_chdippy[];

    return (OSThread *) D_808015C8_chdippy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800018_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_808000D8_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800374_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_8080047C_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800530_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800654_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800800_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800948_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800990_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_808009D8_chdippy.s")

void chdippy_entrypoint_2(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808014B0_chdippy;
    func_800BBCB8(arg1, 0, 0x3F99999A, 1, &D_808014B0_chdippy);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800CBC_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800D44_chdippy.s")

void func_80800D84_chdippy(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800D9C_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80801110_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80801200_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/chdippy_entrypoint_3.s")
