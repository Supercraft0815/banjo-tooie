#include "common.h"

void func_80800000_chtrashcangame(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x30))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x2C))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80800014_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80800098_chtrashcangame.s")

/* extern */

void func_80800144_chtrashcangame(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800014_chtrashcangame();
    s32 func_80800098_chtrashcangame(s32, s32, s32);
    func_80800098_chtrashcangame(arg0, arg1, func_80800014_chtrashcangame() + arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80800180_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_808003D0_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80800728_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_8080093C_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80800B64_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80800BA8_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_8080134C_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80801558_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_808016B4_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80801740_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_808017F0_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_8080189C_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_808018E4_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_808019EC_chtrashcangame.s")

OSThread *chtrashcangame_entrypoint_0(void)
{
    extern u8 D_808031B4_chtrashcangame[];

    return (OSThread *) D_808031B4_chtrashcangame;
}

/* extern */

void func_80801CF0_chtrashcangame(s32 arg0) {
    s32 _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_3(s32);
    s32 func_800946C4(s32, s32);
    s32 func_800F53D0(s32);
    s32 var_s0;

    _subaddiemulti_entrypoint_3(1);
    var_s0 = 0;
    if (_gcstatusDll_entrypoint_11() > 0) {
        do {
            func_800946C4(func_800F53D0(var_s0), 1);
            var_s0 += 1;
        } while (var_s0 < _gcstatusDll_entrypoint_11());
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80801D54_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80801EE8_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_808020D8_chtrashcangame.s")

OSThread *chtrashcangame_entrypoint_1(void)
{
    extern u8 D_808031FC_chtrashcangame[];

    return (OSThread *) D_808031FC_chtrashcangame;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_808021BC_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_8080223C_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_8080292C_chtrashcangame.s")

OSThread *chtrashcangame_entrypoint_2(void)
{
    extern u8 D_808033A0_chtrashcangame[];

    return (OSThread *) D_808033A0_chtrashcangame;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80802C40_chtrashcangame.s")

OSThread *chtrashcangame_entrypoint_3(void)
{
    extern u8 D_808033E8_chtrashcangame[];

    return (OSThread *) D_808033E8_chtrashcangame;
}

void func_80802CC0_chtrashcangame(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_8(void*, u32);
    f32 func_80103EF4(Actor*);
    _chdoormake_entrypoint_3(arg0, arg0->rotation[1], 90.0f, func_80103EF4(arg0), 0x802, 0);
    _chdoormake_entrypoint_8(arg0, 2U);
    _chdoormake_entrypoint_5(arg0, 2.0f);
}

OSThread *chtrashcangame_entrypoint_4(void)
{
    extern u8 D_80803430_chtrashcangame[];

    return (OSThread *) D_80803430_chtrashcangame;
}
