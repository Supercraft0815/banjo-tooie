#include "common.h"

OSThread *chbadbeehive_entrypoint_0(void)
{
    extern u8 D_80800B1C_chbadbeehive[];

    return (OSThread *) D_80800B1C_chbadbeehive;
}

f32 func_8080000C_chbadbeehive(void) {
    extern u8 D_8012762C;
    switch (D_8012762C) {
    case 19:
        return 420.0f;
    case 16:
        return 440.0f;
    case 15:
        return 460.0f;
    case 18:
        return 480.0f;
    case 20:
        return 500.0f;
    case 21:
        return 550.0f;
    case 22:
        return 600.0f;
    case 23:
        return 650.0f;
    case 24:
        return 700.0f;
    case 25:
        return 630.0f;
    case 26:
        return 700.0f;
    default:
        return 0.0f;
    }
}

/* extern */

void func_808000EC_chbadbeehive(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 func_8080000C_chbadbeehive(void);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0U);
    _subaddierouteDll_entrypoint_3(arg0, sp24, arg0->position);
    ((f32 *)arg0->actorData)[3] = 0.0f;
    ((f32 *)arg0->actorData)[5] = 0.0f;
    func_800EE7F8((f32 *)(sp24 + 0x10), arg0->position);
    ((f32 *)arg0->actorData)[6] = func_8080000C_chbadbeehive();
}

void func_80800158_chbadbeehive(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3584(u8, f32, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    void func_800C3CE8(u8);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    extern s32 D_80800AEC_chbadbeehive;
    extern f32 D_80800B64_chbadbeehive;
    extern f32 D_80800B74_chbadbeehive;
    s32 sp2C;
    s32 temp_v0;

    sp2C = 0;
    temp_v0 = func_801022E4(arg0);
    if (temp_v0 != 0x54) {
        if (temp_v0 == 0x1C7) {
            if ((func_80101E14(arg0, 0.48f) != 0) || (func_80101E14(arg0, 0.98f) != 0)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800AEC_chbadbeehive);
            }
            if (func_80101E4C(arg0, &D_80800B74_chbadbeehive) != 0) {
                sp2C = 1;
            }
        }
    } else if (func_80101E4C(arg0, &D_80800B64_chbadbeehive) != 0) {
        sp2C = 1;
    }
    if (sp2C != 0) {
        func_800C3CE8(arg0->unk5F);
        func_800C301C(arg0->unk5F, 0x447);
        func_800C3058(arg0->unk5F, 0x2EE0);
        func_800C31DC(arg0->unk5F, func_80101F24(arg0) + 0.5f);
        func_800C35E8(arg0->unk5F, arg0->position);
        func_800C3584(arg0->unk5F, 300.0f, 1500.0f);
        func_800C330C(arg0->unk5F, 3);
        func_800C3BDC(arg0->unk5F);
    }
}

void func_80800298_chbadbeehive(Actor *arg0) {
    typedef struct Vec3s32 { f32 x, y, z; } Vec3s32;
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    int func_800DC298(f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    void func_801026CC(Actor *, Vec3s32, f32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010C3A8(Actor *, u32, f32);
    s32 func_8010C500(void *);
    void func_8010C908(s32, s32);
    s32 func_8010C9B0(f32 *, s32);
    void func_8010D254(f32 *);
    void func_808008F8_chbadbeehive(Actor *, s32);
    s32 func_80800990_chbadbeehive(Actor *);
    extern u8 D_80800B90_chbadbeehive[];
    extern Vec3s32 D_80800BD8_chbadbeehive;
    struct BeehiveRoute {
        u16 unk0[3];
        u16 next;
        s32 unk8;
        s32 current;
        f32 position[3];
    } *sp3C;
    struct BeehiveFlags {
        u32 pad : 29;
        u32 inactive : 1;
        u32 rest : 2;
    };
    f32 sp38;
    f32 sp34;

    sp3C = func_80100094(arg0, 0);
    sp38 = func_800F3780(func_80101F24(arg0), D_80800B90_chbadbeehive, 9);
    if (!((struct BeehiveFlags *)&arg0->unk78)->inactive) {
        func_800D9078(&arg0->unk58);
        switch (arg0->unk70_10) {
        case 1:
            if (arg0->unk64_29) {
                if (_subaddiejoy_entrypoint_9(arg0, NULL, 0) > 0.1f) {
                    func_808008F8_chbadbeehive(arg0, 2);
                }
            } else if (func_80800990_chbadbeehive(arg0)) {
                func_808008F8_chbadbeehive(arg0, 2);
            }
            break;
        case 2:
            func_801026CC(arg0, D_80800BD8_chbadbeehive, ((f32 *)arg0->actorData)[3]);
            func_8010D254((f32 *)arg0->actorData);
            if (arg0->unk64_29) {
                sp34 = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
                ((f32 *)arg0->actorData)[3] = ((f32 *)arg0->actorData)[5];
                func_80102BF8(arg0, 0.2f, 8.0f, 500.0f);
                func_8010C3A8(arg0, 0x205015, sp34 * sp38);
                if (_subaddiejoy_entrypoint_9(arg0, NULL, 0) == 0.0f) {
                    func_808008F8_chbadbeehive(arg0, 1);
                }
            } else {
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
                    _subaddierouteDll_entrypoint_7(arg0, sp3C, arg0->rotation[1], arg0->unk54, 200.0f, 0x5800);
                    sp3C->current = sp3C->next;
                }
                _subaddierouteDll_entrypoint_5(arg0, sp3C, sp3C->current, 0.15f, 8.0f, 200.0f);
                ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], ((f32 *)arg0->actorData)[5], func_800D8FF8() * 400.0f);
                func_8010C3A8(arg0, 0x305115, sp38);
                if (_subaddierouteDll_entrypoint_4(arg0) && func_800DC298(0.2f) && (!func_8010C9B0(arg0->position, 1000) || !func_8010C500(arg0))) {
                    func_808008F8_chbadbeehive(arg0, 3);
                }
            }
            break;
        case 3:
            func_801026CC(arg0, D_80800BD8_chbadbeehive, ((f32 *)arg0->actorData)[3]);
            if (func_80800990_chbadbeehive(arg0)) {
                func_808008F8_chbadbeehive(arg0, 2);
            }
            if (_subaddierouteDll_entrypoint_4(arg0)) {
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
                _subaddierouteDll_entrypoint_7(arg0, sp3C, arg0->rotation[1], arg0->unk54, 200.0f, 0x5800);
                sp3C->current = sp3C->next;
            }
            _subaddierouteDll_entrypoint_5(arg0, sp3C, sp3C->current, 0.15f, 8.0f, 200.0f);
            ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], ((f32 *)arg0->actorData)[5], func_800D8FF8() * 400.0f);
            func_8010C3A8(arg0, 0x305115, sp38);
            if (_subaddierouteDll_entrypoint_4(arg0) && func_800DC298(0.2f) && func_800EFFB4(arg0->position, 100.0f, sp3C->position)) {
                func_808008F8_chbadbeehive(arg0, 1);
            }
            break;
        }
        if ((s32)arg0->unk70_10 < 4) {
            func_8010C908((s32)arg0, (s32)arg0->position);
        }
        func_80800158_chbadbeehive(arg0);
    }
}

s32 func_8080070C_chbadbeehive(Actor *arg0, s32 arg1, s16 **arg2) {
    void _chexploder_entrypoint_15(s32, u32, f32);
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    u8 func_800C2E04(void);
    void func_800DF744(s32, s32);
    void func_800EE88C(f32 *, s16 *);
    void func_800FFAB0(Actor *);
    void func_80101074(void *);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80107070(Actor *, u32);
    void func_808008F8_chbadbeehive(Actor *, s32);
    extern u8 D_80800ABC_chbadbeehive[];
    extern u8 D_80800AFC_chbadbeehive[];
    extern u8 D_80800B0C_chbadbeehive[];
    extern s32 D_80800BE4_chbadbeehive[];
    f32 sp34[3];
    Actor *sp30;

    switch (arg1) {
    case 0x95:
        arg0->unk5F = func_800C2E04();
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    case 0x40:
        func_800EE88C(sp34, *arg2 + 2);
        sp34[1] = arg0->position[1];
        _chexploder_entrypoint_3(arg0, sp34, 0x20);
        break;
    case 0x90:
        sp30 = func_80106790(func_80101080());
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800AFC_chbadbeehive);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800B0C_chbadbeehive);
        func_800BBCB8(arg0->position, NULL, arg0->scale, 1, D_80800BE4_chbadbeehive);
        if (!func_80107070(arg0, 3)) {
            func_800FFAB0(arg0);
        }
        _chexploder_entrypoint_15((s32)sp30, 2, 1.0f);
        _chexploder_entrypoint_9(sp30, 3, 2);
        break;
    case 1:
        func_808008F8_chbadbeehive(arg0, 2);
        break;
    case 2:
        if (!_subaddieDll_entrypoint_3(arg0)) {
            if (!func_80107070(arg0, 1)) {
                _subaddiefade_entrypoint_3(arg0);
            }
        } else {
            func_808008F8_chbadbeehive(arg0, 3);
        }
        break;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 2);
        break;
    case 0x38:
        func_80101074(D_80800ABC_chbadbeehive);
        return 4;
    default:
        return 0;
    }
    return 1;
}

void func_808008F0_chbadbeehive(s32 arg0) 
{
}
void func_808008F8_chbadbeehive(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0U);
    func_80102424(arg0, arg1);
    switch (arg1) {
        case 1:
            break;
        case 2:
            ((f32 *)arg0->actorData)[5] = ((f32 *)arg0->actorData)[6];
            break;
        case 3:
            func_800EE7F8((f32 *)arg0->actorData, (f32 *)(sp24 + 0x10));
            ((f32 *)arg0->actorData)[5] *= 0.5f;
            break;
    }
}

/* extern */

s32 func_80800990_chbadbeehive(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_8010C9B0(arg0->position, 0x3E8) != 0) && (_suchase_entrypoint_1(arg0) != 0) && (func_8010C500(arg0) != 0)) {
        return 1;
    }
    return 0;
}
