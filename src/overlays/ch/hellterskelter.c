#include "ch/hellterskelter.h"

OSThread *chhellterskelter_entrypoint_0(void)
{
    extern u8 D_808007C8_chhellterskelter[];

    return (OSThread *) D_808007C8_chhellterskelter;
}

OSThread *chhellterskelter_entrypoint_1(void)
{
    extern u8 D_80800810_chhellterskelter[];

    return (OSThread *) D_80800810_chhellterskelter;
}

OSThread *chhellterskelter_entrypoint_2(void)
{
    extern u8 D_80800858_chhellterskelter[];

    return (OSThread *) D_80800858_chhellterskelter;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800024_chhellterskelter.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_808000A8_chhellterskelter.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800158_chhellterskelter.s")

void func_80800274_chhellterskelter(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A4B_UNK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800294_chhellterskelter.s")

void func_808002E8_chhellterskelter(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_808002F0_chhellterskelter.s")

void func_808004D0_chhellterskelter(s32 arg0) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    s32 func_800DC298(f32);
    void *func_80105494();
    extern s32 D_808008C0_chhellterskelter;
    if (!((*(f32 *)((s8 *)(func_80105494()) + (0xC))) > 0.9f) && (func_800DC298(0.1f) != 0)) {
        func_800BBCB8(arg0 + 4, 0, 0x3F800000, 1, &D_808008C0_chhellterskelter);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800540_chhellterskelter.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_808005E0_chhellterskelter.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800680_chhellterskelter.s")
