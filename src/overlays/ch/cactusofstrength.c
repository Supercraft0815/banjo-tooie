#include "common.h"

OSThread *chcactusofstrength_entrypoint_0(void)
{
    extern u8 D_80800D00_chcactusofstrength[];

    return (OSThread *) D_80800D00_chcactusofstrength;
}

OSThread *chcactusofstrength_entrypoint_1(void)
{
    extern u8 D_80800D48_chcactusofstrength[];

    return (OSThread *) D_80800D48_chcactusofstrength;
}

OSThread *chcactusofstrength_entrypoint_2(void)
{
    extern u8 D_80800D90_chcactusofstrength[];

    return (OSThread *) D_80800D90_chcactusofstrength;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800024_chcactusofstrength.s")

void func_80800108_chcactusofstrength(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800110_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_808001C4_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800200_chcactusofstrength.s")

/* extern */

void func_808003EC_chcactusofstrength(void *arg0) {
    s32 func_800D0A9C(s32, s32, void *);
    s32 func_800FFAB0(void *);
    (*(s32 *)((s8 *)(arg0) + (0x50))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 1200.0f;
    if (func_800D0A9C(0x1E, 1, arg0) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800440_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_808004F8_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_808006BC_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800718_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800780_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800824_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_8080094C_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800A44_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800B24_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800B90_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800C18_chcactusofstrength.s")
