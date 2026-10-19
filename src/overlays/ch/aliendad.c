#include "common.h"

OSThread *chaliendad_entrypoint_0(void)
{
    extern u8 D_80802674_chaliendad[];

    return (OSThread *) D_80802674_chaliendad;
}

OSThread *chaliendad_entrypoint_1(void)
{
    extern u8 D_808026BC_chaliendad[];

    return (OSThread *) D_808026BC_chaliendad;
}

OSThread *chaliendad_entrypoint_2(void)
{
    extern u8 D_80802704_chaliendad[];

    return (OSThread *) D_80802704_chaliendad;
}

void func_80800024_chaliendad(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE940(s16 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80801324_chaliendad(Actor *, s32);
    s32 func_80801DD0_chaliendad(void);
    s16 *sp24;

    sp24 = func_80100094(arg0, 0U);
    func_800EE940(sp24, arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    sp24[3] = (s32)arg0->rotation[1];
    func_80801324_chaliendad(arg0, 0);
    if (func_80801DD0_chaliendad() == 3) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_808000AC_chaliendad.s")

void *func_80100094(Actor *, u32);

void func_808008C8_chaliendad(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_80801E80_chaliendad(Actor *);
    void *sp1C;

    sp1C = func_80100094(arg0, 0U);
    (*(u8 *)((s8 *)(sp1C) + (0x38))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(sp1C) + (0x38))));
    (*(u8 *)((s8 *)(sp1C) + (0x39))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(sp1C) + (0x39))));
    func_80801E80_chaliendad(arg0);
}

void func_80800918_chaliendad(Actor *arg0, void *arg1) {
    void _chlifeforcespell_entrypoint_2(Actor *, s32, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void func_800DF744(s32, s32);
    void func_800E39A8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_80101870(Actor *, void *);
    s32 *sp4C;
    f32 sp40[3];
    s32 sp34[3];
    s32 sp28[3];

    sp4C = func_80100094(arg0, 0U);
    if (arg0->unk70_10 == 2) {
        func_800E39A8(arg0->position, sp40);
        func_800EF214(arg0->position, sp40[0], sp40[1], -1000.0f);
        arg0->rotation[1] = sp40[1];
        arg0->rotation[0] = sp40[0] + 15.0f;
        func_800DF744(3, 1);
    } else {
        func_800DF744(3, 0);
    }
    func_800DF744(1, arg0->unk7A_11 + 1);
    func_800DF744(2, arg0->unk7A_11 + 1);
    if (sp4C[13] != 0) {
        _subaddiefade_entrypoint_9(arg0, sp28);
        _chlifeforcespell_entrypoint_2(arg0, sp4C[13], sp34);
        _subaddiefade_entrypoint_11(arg0, sp34);
        func_80101870(arg0, arg1);
        _subaddiefade_entrypoint_11(arg0, sp28);
        return;
    }
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80800A54_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80800F28_chaliendad.s")

void func_80801110_chaliendad(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);
    void func_80102424(Actor *, s32);
    void func_80801D40_chaliendad(Actor *, s32, s32, Unk80132ED0 *);
    extern s32 D_808025C0_chaliendad;
    extern f32 D_808025D8_chaliendad[3];
    extern u32 D_808025E4_chaliendad;
    f32 *sp2C;
    s32 i;

    sp2C = func_80100094(arg0, 0U);
    switch (arg1) {
    case 0x1287:
        func_80102424(arg0, 0xB);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B4, 0x144, arg0->position, 0x62);
        func_80801D40_chaliendad(arg0, 0x37, 0x30, NULL);
        arg0->unk58 = 1.5f;
        break;
    case 0x12AA:
        func_80801D40_chaliendad(arg0, 0x49, 0x30, NULL);
        func_80102424(arg0, 0xC);
        for (i = 0; i < 3; i++) {
            sp2C[i + 3] = D_808025D8_chaliendad[i];
        }
        break;
    default:
        if (_subaddiedialog_entrypoint_9(arg0, arg1, &D_808025C0_chaliendad, 3) != 0) {
            func_80102424(arg0, 9);
        }
        break;
    }
}

void func_80801220_chaliendad(void *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieaudioquick_entrypoint_2(void *, void *, s32 *);
    extern s32 D_8080281C_chaliendad;
    if (arg1 == 0x12A0) {
        _subaddieaudioquick_entrypoint_2(arg0, (u8 *)arg0 + 4, &D_8080281C_chaliendad);
    }
}

/* extern */

s32 func_80801254_chaliendad(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80801C9C_chaliendad(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x1C))) != 2) {
            func_80801C9C_chaliendad(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_808012AC_chaliendad.s")

void func_80801324_chaliendad(Actor *arg0, s32 arg1) {
    struct {
        u8 pad0[0x18];
        s16 state;
        s16 pad1A;
        f32 duration;
        f32 scale;
        f32 targetScale;
    } *data;
    struct {
        u8 pad0[0x78];
        u32 pad78 : 18;
        u32 blinkState : 2;
        u32 blinkFrame : 3;
        u32 pad7B : 9;
    } *actor = (void *)arg0;

    data = func_80100094(arg0, 0U);
    data->state = arg1;
    switch (arg1) {
        case 0:
            actor->blinkState = 0;
            actor->blinkFrame = 0;
            break;
        case 1:
            actor->blinkState = 0;
            actor->blinkFrame = 0;
            data->scale = 0.8f;
            data->targetScale = 0.8f;
            data->duration = 6.0f;
            break;
        case 2:
            actor->blinkFrame = 3;
            data->scale = 0.4f;
            data->targetScale = 0.4f;
            break;
        case 3:
            actor->blinkState = 2;
            actor->blinkFrame = 3;
            data->scale = 0.3f;
            data->targetScale = 0.3f;
            data->duration = 5.0f;
            break;
    }
}

void func_8080142C_chaliendad(void *arg0) {
    f32 func_800DC0C0(void);
    struct {
        u8 pad0[0x78];
        u32 pad78 : 18;
        u32 blinkState : 2;
        u32 blinkFrame : 3;
        u32 pad7B : 9;
    } *actor = arg0;

    switch (actor->blinkState) {
        case 0:
            if (func_800DC0C0() < 0.03f) {
                actor->blinkState = 1;
            }
            break;
        case 1:
            if (actor->blinkFrame == 3) {
                actor->blinkState = 3;
            } else {
                actor->blinkFrame++;
            }
            break;
        case 3:
            actor->blinkFrame--;
            if (actor->blinkFrame == 0) {
                actor->blinkState = 0;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_8080152C_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801868_chaliendad.s")

void func_80801B9C_chaliendad(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808025C0_chaliendad;
    extern s32 D_80802824_chaliendad;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_80802824_chaliendad, &D_808025C0_chaliendad, 3);
}

/* extern */

void func_80801BD4_chaliendad(Actor *arg0) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void func_80102424(Actor *, s32);
    void func_80801D40_chaliendad(Actor *, s32, s32, Unk80132ED0 *);
    Actor *temp_v0;

    arg0->unk64_16 = 1;
    _subaddieDll_entrypoint_4(arg0, 1);
    func_80102424(arg0, 2);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B3, 0x44, arg0->position, 0x62);
    func_80801D40_chaliendad(arg0, 0x22, 0x30, 0);
    temp_v0 = _subaddiefind_entrypoint_2(0x45B, 0);
    temp_v0->unk64_16 = 0;
}

/* extern */

void func_80801C60_chaliendad(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x1C))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x1C))) = 0;
    }
}

void func_80801C9C_chaliendad(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);
    extern u32 D_808025E4_chaliendad;

    switch (arg0->actorData[1]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xD, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->actorData[1] = 2;
            _gcdialogcamera_entrypoint_3(&D_808025E4_chaliendad, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80801D40_chaliendad(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    if (arg3 == NULL) {
        arg3 = arg0->unk0;
    }
    switch (arg0->actorData[1]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xD, arg2);
        case 2:
            arg0->actorData[1] = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}

s32 func_80801DD0_chaliendad(void) {
    s32 func_800DA298(s32);
    s32 i;
    s32 count = 0;
    for (i = 0; i < 3; i++) {
        if (func_800DA298(i + 0x372)) {
            count++;
        }
    }
    return count;
}

/* extern */

void func_80801E28_chaliendad(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        temp_v0 = _suexpression_entrypoint_7(arg0, 1, 0x62);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x3E8);
    }
}

void func_80801E80_chaliendad(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80801EB4_chaliendad(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void *func_80105494(Actor *);
    void func_80105A9C(Actor *, f32);
    f32 *data;

    data = func_80100094(arg0, 0U);
    data[2] = arg0->rotation[1];
    if (func_80105494(arg0) != NULL) {
        data[0] = 100.0f;
        data[1] = 100.0f;
        func_80105A9C(arg0, 1200.0f);
        if (func_80801DD0_chaliendad() == 3) {
            func_800FFAB0(arg0);
        }
    } else {
        data[1] = 100.0f;
        data[0] = 10.0f;
        func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        ((f32 *)arg0->actorData)[1] = 1000.0f;
        func_80101FDC(arg0, 5);
        arg0->unk58 = 6.0f;
    }
}

void func_80801F98_chaliendad(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_80105834(Actor *);
    s32 func_80105998(Actor *, f32);
    s32 func_80105A5C(Actor *);
    void func_80802218_chaliendad(Actor *);
    void func_80802284_chaliendad(Actor *);

    func_80802218_chaliendad(arg0);
    switch (arg0->unk70_10) {
        case 3:
            break;
        case 2:
            func_80105834(arg0);
            if (func_80105998(arg0, 0.8f)) {
                func_80102424(arg0, 3);
                func_80801BD4_chaliendad(_subaddiefind_entrypoint_2(0x45A, 0));
            }
            break;
        case 4:
            func_80105834(arg0);
            if (func_80105A5C(arg0)) {
                func_800FFAB0(arg0);
            }
            break;
    }
    func_80802284_chaliendad(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80802058_chaliendad.s")

void func_80802188_chaliendad(Actor *arg0, s32 arg1) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF47C(s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 *func_801018D8(Actor *);
    int func_80101970(Actor *);
    s32 func_8010347C(Unk80132ED0 *);
    s32 func_801015D0(Actor *);
    f32 sp34[3];
    f32 *sp30;

    sp30 = func_80100094(arg0, 0U);
    func_80101970(arg0);
    func_800EFA4C(sp34, arg0->rotation[0], sp30[2], arg0->rotation[2]);
    func_800DF47C(&func_801015D0, arg0);
    func_800DE448(arg0->position, sp34, arg0->scale, func_801018D8(arg0), func_8010347C(arg0->unk0));
}

/* extern */

void func_80802218_chaliendad(Actor *arg0) {
    f32 func_800D8FF8();
    f32 func_800F15F8(f32, f32, f32);
    void *sp1C;
    f32 sp18;
    f32 temp_f0;
    f32 temp_f0_2;

    sp1C = func_80100094(arg0, 0U);
    temp_f0 = func_800D8FF8();
    sp18 = temp_f0;
    temp_f0_2 = func_800F15F8((*(f32 *)((s8 *)(sp1C) + (4))), (*(f32 *)((s8 *)(sp1C) + (0))), temp_f0 * 15.0f);
    (*(f32 *)((s8 *)(sp1C) + (4))) = temp_f0_2;
    (*(f32 *)((s8 *)(sp1C) + (8))) = (f32) ((*(f32 *)((s8 *)(sp1C) + (8))) + (temp_f0_2 * sp18));
}

void func_80802284_chaliendad(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    void func_80103DFC(Actor*, f32*);
    extern u32 D_80802834_chaliendad;
    f32 sp1C[3];

    func_80103DFC(arg0, sp1C);
    _subaddieaudioloop_entrypoint_4(arg0, sp1C, (arg0->unk70_10 ^ 1) != 0, &D_80802834_chaliendad);
}

void func_808022CC_chaliendad(Actor *arg0) {
    void func_80102424(Actor *, s32);
    f32 *sp1C;
    sp1C = func_80100094(arg0, 0);
    func_80102424(arg0, 7);
    *(f32 *)&arg0->actorData[3] = 100.0f;
    arg0->unk58 = 5.0f;
    sp1C[0] = 100.0f;
    sp1C[1] = 10.0f;
}

void func_80802330_chaliendad(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.85f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80802340_chaliendad.s")
