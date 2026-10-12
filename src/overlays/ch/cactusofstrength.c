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

/* extern */

s32 func_808001C4_chcactusofstrength(s32 arg0, s32 arg1, volatile s32 arg2) {
    s32 func_80800110_chcactusofstrength(s32, s32);
    s32 result;
    if (arg1 == 0x40) {
        func_80800110_chcactusofstrength(arg0, *(s32 *)&arg2);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

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

/* extern */

void func_808006BC_chcactusofstrength(void *arg0) {
    s32 func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    s32 func_800CEAD0(s32);
    s32 func_80101FDC(void *, s32);
    if (((*(s32 *)((s8 *)(arg0) + (0x50))) != 0) && (func_800CEAD0(0) != 0)) {
        if (func_800CEAA8(0) != 0) {
            func_800CE88C(0, 0);
        }
        func_80101FDC(arg0, 3);
    }
}

/* extern */

void func_80800718_chcactusofstrength(void *arg0) {
    s32 _mlwave_entrypoint_0(s32, s32, s32);
    s32 func_80100074(void *, s32, s32);
    s32 func_80101FDC(void *, s32);
    s32 func_80103110(void *, s32);
    void *func_80106790(s32);
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_80106790((*(s32 *)((s8 *)(arg0) + (0x3C))));
    sp1C = temp_v0;
    func_80101FDC(temp_v0, 2);
    func_80103110(sp1C, 1);
    (*(f32 *)((s8 *)(sp1C) + (0x58))) = 2.5f;
    _mlwave_entrypoint_0(func_80100074(sp1C, 1, 0x1C), 0x42C80000, 0x42A00000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800780_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800824_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_8080094C_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800A44_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800B24_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800B90_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800C18_chcactusofstrength.s")
