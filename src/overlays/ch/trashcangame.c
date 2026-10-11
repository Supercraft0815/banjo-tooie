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

void func_80800BA8_chtrashcangame(Actor *arg0) {
    typedef struct { f32 values[4]; } Timing4;
    typedef struct { f32 values[7]; } Timing7;
    extern u16 D_80802FF4_chtrashcangame[][4];
    extern Timing4 D_808030BC_chtrashcangame;
    extern Timing4 D_808030CC_chtrashcangame;
    extern Timing4 D_808030DC_chtrashcangame;
    extern Timing4 D_808030EC_chtrashcangame;
    extern Timing4 D_808030FC_chtrashcangame;
    extern Timing4 D_8080310C_chtrashcangame;
    extern Timing4 D_8080311C_chtrashcangame;
    extern Timing7 D_8080312C_chtrashcangame;
    extern Timing7 D_80803148_chtrashcangame;
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    void func_800C4140(u32, f32 *, u32);

    switch (D_80802FF4_chtrashcangame[(u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10][0]) {
        case 0x369: {
            Timing4 first = D_808030BC_chtrashcangame;
            Timing4 second = D_808030CC_chtrashcangame;
            Timing4 third = D_808030DC_chtrashcangame;
            s32 volume = 0;

            if (func_80101E14(arg0, 0.157f)) {
                volume = 22000;
            } else if (func_80101E4C(arg0, first.values)) {
                volume = 10000;
            } else if (func_80101E4C(arg0, second.values)) {
                volume = 5000;
            }
            if (func_80101E4C(arg0, third.values)) {
                func_800C4140((((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21) + 0x157C04,
                             (f32 *)((u8 *)arg0 + 4), 0x04B000FA);
            }
            if (volume) {
                func_800C4140((((u32)(func_800DC178(1.05f, 1.15f) * 1023.0f) & 0x7FF) << 21) +
                             (((volume >> 5) & 0x3FF) << 11) + 0x4C1,
                             (f32 *)((u8 *)arg0 + 4), 0x04B000FA);
            }
            break;
        }
        case 0x36A: {
            Timing4 first = D_808030EC_chtrashcangame;
            Timing4 second = D_808030FC_chtrashcangame;
            Timing4 third = D_8080310C_chtrashcangame;
            s32 volume = 0;

            if (func_80101E14(arg0, 0.126f)) {
                volume = 22000;
            } else if (func_80101E14(arg0, 0.156f) || func_80101E14(arg0, 0.888f)) {
                volume = 10000;
            } else if (func_80101E14(arg0, 0.918f)) {
                volume = 5000;
            }
            if (volume) {
                func_800C4140((((u32)(func_800DC178(1.05f, 1.15f) * 1023.0f) & 0x7FF) << 21) +
                             (((volume >> 5) & 0x3FF) << 11) + 0x4C1,
                             (f32 *)((u8 *)arg0 + 4), 0x04B000FA);
            }
            break;
        }
        case 0x36B: {
            Timing4 first = D_8080311C_chtrashcangame;
            Timing7 second = D_8080312C_chtrashcangame;
            Timing7 third = D_80803148_chtrashcangame;
            s32 volume = 0;

            if (func_80101E4C(arg0, first.values)) {
                volume = 22000;
            } else if (func_80101E4C(arg0, second.values)) {
                volume = 10000;
            } else if (func_80101E14(arg0, 0.44f) || func_80101E14(arg0, 0.994f)) {
                volume = 5000;
            }
            if (func_80101E4C(arg0, third.values)) {
                func_800C4140((((u32)(func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21) + 0x157C04,
                             (f32 *)((u8 *)arg0 + 4), 0x04B000FA);
            }
            if (volume) {
                func_800C4140((((u32)(func_800DC178(1.05f, 1.15f) * 1023.0f) & 0x7FF) << 21) +
                             (((volume >> 5) & 0x3FF) << 11) + 0x4C1,
                             (f32 *)((u8 *)arg0 + 4), 0x04B000FA);
            }
            break;
        }
    }
}

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
