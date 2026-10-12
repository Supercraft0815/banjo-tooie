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

void func_808003D0_chtrashcangame(void *arg0, s32 arg1) {
    typedef struct { u8 padding[0x79]; u8 variant : 4; u8 other : 4; } TrashFlags;
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, f32 *, s32);
    s32 func_800946C4(s32, s32);
    s32 func_800CE88C(s32, s32);
    s32 func_800CE8D8(s32, f32, s32);
    s32 func_800D0A9C(s32, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D395C(void);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    s32 func_800F53D0(s32);
    s32 func_800F54E4();
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    s32 func_80101180(s32, s32, s32);
    void func_80102424(void *, s32);
    s32 func_80800014_chtrashcangame();
    s32 func_80800098_chtrashcangame(s32, s32, s32);
    void func_808016B4_chtrashcangame(void *, s32, s32, s32);
    void func_808017F0_chtrashcangame(void *, s32, s32);
    void func_8080189C_chtrashcangame(void *);
    s32 dialog;

    switch (arg1) {
        case 1:
            *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(15.0f, 25.0f);
            break;
        case 2:
            _subaddiedialog_entrypoint_11(*(s32 *)arg0,
                func_800DC128(0x13FE, 0x1401), 4, (f32 *)((u8 *)arg0 + 4), 0x6A);
            break;
        case 3:
            *(s32 *)((u8 *)arg0 + 0x50) = 0;
            *(s32 *)((u8 *)arg0 + 0x34) = 10;
            func_8080189C_chtrashcangame(arg0);
            break;
        case 4:
            ((TrashFlags *)arg0)->variant = func_800DC128(1, 4);
            func_808017F0_chtrashcangame(arg0, 0x13F1, 0x4E);
            break;
        case 5:
            func_808017F0_chtrashcangame(arg0, 0x13F2, 0x4E);
            break;
        case 6:
            func_808017F0_chtrashcangame(arg0,
                func_800D0A9C(0x4E, 1) ? 0x13FD : 0x13F3, 0xF);
            break;
        case 7:
            *(s32 *)((u8 *)arg0 + 0x50) = 0;
            if (func_800D395C()) {
                dialog = 0x1444;
                func_800946C4(func_800F53D0(func_800F54E4()), 1);
            } else if (func_800D0A9C(0x4E, 1)) {
                dialog = 0x13F5;
            } else {
                dialog = 0x13F4;
            }
            func_808017F0_chtrashcangame(arg0, dialog, 0xF);
            func_80800000_chtrashcangame(arg0);
            _gcfrontend_entrypoint_9(0x72);
            func_80101180(0x533, 8, 0);
            break;
        case 8:
            func_8080189C_chtrashcangame(arg0);
            func_800CE8D8(0, 60.0f, 0x3C);
            func_800CE88C(0, 1);
            *(f32 *)((u8 *)arg0 + 0x58) = 0.2999878f;
            func_80800098_chtrashcangame((s32)arg0, 0, 0);
            *(s32 *)((u8 *)arg0 + 0x50) = 0;
            func_800FDC28(0xC);
            break;
        case 9:
            func_800FC6B0(0x17);
            break;
        case 10:
            func_808017F0_chtrashcangame(arg0,
                func_800D0A9C(0x4E, 1) ? 0x13FC : 0x13FB, 0x4E);
            func_800D2054(0, 0x86, func_80800014_chtrashcangame(arg0, 0));
            break;
        case 11:
            func_800FC6B0(0x16);
            break;
        case 12:
            func_800D1000(0x4E, 1, (s32 *)((u8 *)arg0 + 4), 6, 0);
            func_808016B4_chtrashcangame(arg0, *(s32 *)arg0, 6, 0x10);
            break;
        case 13:
            func_8080189C_chtrashcangame(arg0);
            break;
        case 14:
            *(f32 *)((u8 *)arg0 + 0x58) = 0.5f;
            break;
        case 15:
            func_808017F0_chtrashcangame(arg0, 0x13FC, 0x4E);
            func_800D2054(0, 0x86, func_80800014_chtrashcangame(arg0, 0));
            break;
        case 16:
            *(s32 *)((u8 *)arg0 + 0x50) = 0;
            *(s32 *)((u8 *)arg0 + 0x34) = 10;
            func_8080189C_chtrashcangame(arg0);
            func_808017F0_chtrashcangame(arg0, 0x1443, 0x4E);
            break;
        case 17:
            func_808017F0_chtrashcangame(arg0, 0x1451, 0xF);
            break;
    }
    func_80102424(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_80800728_chtrashcangame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcangame/func_8080093C_chtrashcangame.s")

/* extern */

void func_80800B64_chtrashcangame(s32 arg0) {
    f32 func_800EFC7C(f32 *, f32 *);
    s32 _subaddiefind_entrypoint_5(s32, s32 *, s32, s32, f32, f32 (*)(f32 *, f32 *));
    struct { s32 before[2]; s32 output; s32 rest[49]; } sp;

    _subaddiefind_entrypoint_5(0x476, &sp.output, 0x32, arg0, 300.0f, func_800EFC7C);
}

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

void func_8080223C_chtrashcangame(Actor *arg0) {
    f32 func_80013970(f32);
    void func_800BA22C(s32, s32);
    s32 func_800BA994(s32, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32 *, f32 *, s32, s32 *);
    s32 func_800BBCB8(f32 *, f32 *, s32, s32, s32 *);
    void func_800C4140(u32, f32 *, u32);
    s32 func_800D3948(void);
    s32 func_800D90A4(f32 *);
    s32 func_800DB9B0(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    s32 func_800F54E4(void);
    s32 func_800FFA88(Unk80132ED0 *);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    void func_80102424(void *, s32);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010C754(Actor *);
    extern s32 D_8080326C_chtrashcangame[];
    extern s32 D_808032C0_chtrashcangame[];
    extern f32 D_80803300_chtrashcangame[];
    s32 emitter;

    switch (arg0->unk70_10) {
        case 1:
            if (func_80101E14(arg0, 0.01f) &&
                (func_8010C754(arg0) < 1500 || func_800DB9B0())) {
                if (!func_800D3948()) {
                    func_800BBCB8(arg0->position, arg0->position, 0x3F800000, 5, D_8080326C_chtrashcangame);
                }
                func_800C4140(((u16)(func_800DC178(0.45f, 0.65f) * 1023.0f) << 21) + 0x1FFCB7,
                             arg0->position, 0x05DC0190);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[1] + (func_80013970(func_80101F24(arg0) * 135.0f) - 0.707f) * (func_80103EF4(arg0) * 1.25f);
            arg0->scale = func_80101F24(arg0) * 0.8f + 0.2f;
            if (func_80101DDC(arg0)) {
                if (arg0->unk64_20) {
                    func_80102424(arg0, 3);
                } else {
                    arg0->unk58 = func_800DC178(2.0f, 3.0f);
                    func_80102424(arg0, 2);
                }
            }
            break;
        case 3:
            if (func_80101E14(arg0, 0.1f) && func_8010C754(arg0) < 1500) {
                func_800C4140(((u16)(func_800DC178(0.75f, 0.85f) * 1023.0f) << 21) + 0x157C9D,
                             arg0->position, 0x05DC0190);
            }
            if (!func_800D3948() && func_80101E4C(arg0, D_80803300_chtrashcangame)) {
                emitter = func_800BABB8(0, arg0->position, arg0->position, 0x3F800000, D_808032C0_chtrashcangame);
                if (func_800DC0C0() < 0.5f) {
                    func_800BA994(emitter, -20, (s16)arg0->rotation[1] - 75, 300,
                                 -45, (s16)arg0->rotation[1] - 75, 500);
                } else {
                    func_800BA994(emitter, -20, (s16)arg0->rotation[1] + 75, 300,
                                 -45, (s16)arg0->rotation[1] + 75, 500);
                }
                func_800BA22C(emitter, 1);
            }
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 4);
            }
            break;
        case 2:
            if (func_800D90A4(&arg0->unk58)) {
                func_80102424(arg0, 4);
            }
            break;
        case 4:
            if (func_80101E14(arg0, 0.05f) && func_8010C754(arg0) < 1500) {
                if (!func_800D3948()) {
                    func_800BBCB8(arg0->position, arg0->position, 0x3F800000, 5, D_8080326C_chtrashcangame);
                }
                func_800C4140(((u16)(func_800DC178(0.45f, 0.65f) * 1023.0f) << 21) + 0x1FFC01,
                             arg0->position, 0x05DC0190);
            }
            if (func_80101DDC(arg0)) {
                ((s32 *)func_80106790(arg0->unk3C))[0x14] -= 1;
                func_800FFA88(arg0->unk0);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[1] + (func_80013970(func_80101F24(arg0) * 135.0f) - 0.707f) * (func_80103EF4(arg0) * 1.25f);
            arg0->scale = func_80101F24(arg0) * 0.8f + 0.2f;
            break;
    }
    if (arg0->scale > 0.5f) {
        arg0->scale = 0.5f;
    }
    func_800F4F34(func_800F54E4(), arg0->position, 2.0f * func_80103EAC(arg0), func_80103EAC(arg0) * 0.4f);
}

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
