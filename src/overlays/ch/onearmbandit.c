#include "common.h"

OSThread *chonearmbandit_entrypoint_0(void)
{
    extern u8 D_808012BC_chonearmbandit[];

    return (OSThread *) D_808012BC_chonearmbandit;
}

OSThread *chonearmbandit_entrypoint_1(void)
{
    extern u8 D_80801304_chonearmbandit[];

    return (OSThread *) D_80801304_chonearmbandit;
}

/* extern */

void func_80800018_chonearmbandit(void *arg0) {
    s32 func_80800040_chonearmbandit();
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 400.0f;
    func_80800040_chonearmbandit();
}

s32 func_80800040_chonearmbandit(Actor *arg0) {
    void _subaddierouteDll_entrypoint_1(Actor*);
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 1U), arg0->position);
    _subaddierouteDll_entrypoint_1(arg0);
}

void func_8080007C_chonearmbandit(u8 *arg0) {
    struct DisabledFlags {
        unsigned int : 29;
        unsigned int disabled : 1;
        unsigned int : 2;
    };
    struct InteractionFlags {
        unsigned int : 2;
        unsigned int interacting : 1;
        unsigned int : 29;
    };
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    f32 func_800D8FF8(void);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80102CF4(Actor *, f32);
    void func_80108B04(Actor *, u32);
    s32 func_8010C9B0(f32 *, s32);
    s32 func_8010D278(void);
    void func_80800680_chonearmbandit(u8 *, s32);
    void func_80800740_chonearmbandit(u8 *, f32);
    void func_808008E0_chonearmbandit(u8 *, f32);
    void func_80800A14_chonearmbandit(u8 *, f32);
    extern u32 D_808011F0_chonearmbandit[];
    extern u32 D_8080134C_chonearmbandit[];
    s32 pad;

    if (!((struct DisabledFlags *)(arg0 + 0x78))->disabled) {
        switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            if (((struct InteractionFlags *)(arg0 + 0x64))->interacting) {
                func_80800680_chonearmbandit(arg0, 2);
            } else if (func_8010C9B0((f32 *)(arg0 + 4), 1500)) {
                func_80800680_chonearmbandit(arg0, 4);
            }
            break;
        case 2:
            if (_subaddieaudioquick_entrypoint_3((Actor *)arg0, (f32 *)(arg0 + 4), D_808011F0_chonearmbandit, 0.75f)) {
                _subaddiejoy_entrypoint_10(arg0, 0.8f, 0.2f);
            }
            func_808008E0_chonearmbandit(arg0, 0.0f);
            if (_subaddiejoy_entrypoint_6(arg0, 1)) {
                func_80800680_chonearmbandit(arg0, 3);
            } else if (_subaddiejoy_entrypoint_6(arg0, 0)) {
                func_80800680_chonearmbandit(arg0, 5);
            }
            if (!((struct InteractionFlags *)(arg0 + 0x64))->interacting) {
                func_80800680_chonearmbandit(arg0, 3);
            }
            break;
        case 3:
            if (_subaddieaudioquick_entrypoint_3((Actor *)arg0, (f32 *)(arg0 + 4), D_808011F0_chonearmbandit, 0.75f)) {
                _subaddiejoy_entrypoint_10(arg0, 0.8f, 0.2f);
            }
            func_80800A14_chonearmbandit(arg0, 0.7f);
            func_808008E0_chonearmbandit(arg0, 0.0f);
            if (func_80101E14((Actor *)arg0, 0.999f)) {
                if (((struct InteractionFlags *)(arg0 + 0x64))->interacting) {
                    if (!_subaddiejoy_entrypoint_6(arg0, 1)) {
                        func_80800680_chonearmbandit(arg0, 2);
                    }
                } else if (!func_8010C9B0((f32 *)(arg0 + 4), 800)) {
                    func_80800680_chonearmbandit(arg0, 4);
                }
            }
            break;
        case 4:
            _subaddieaudioquick_entrypoint_3((Actor *)arg0, (f32 *)(arg0 + 4), D_808011F0_chonearmbandit, 0.75f);
            if (func_80101E14((Actor *)arg0, 0.999f)) {
                if (((struct InteractionFlags *)(arg0 + 0x64))->interacting) {
                    func_80800680_chonearmbandit(arg0, 2);
                } else if (!func_8010C9B0((f32 *)(arg0 + 4), 1500)) {
                    func_80800680_chonearmbandit(arg0, 1);
                } else if (func_8010C9B0((f32 *)(arg0 + 4), 800)) {
                    func_80800680_chonearmbandit(arg0, func_8010D278() == 0x10 ? 6 : 2);
                }
            } else {
                func_80800740_chonearmbandit(arg0, 0.0f);
                if (func_8010C9B0((f32 *)(arg0 + 4), 1500)) {
                    if (func_80102CF4((Actor *)arg0, 8.0f)) {
                        func_80800680_chonearmbandit(arg0, 5);
                    }
                } else {
                    func_80800680_chonearmbandit(arg0, 1);
                }
            }
            break;
        case 5:
            _subaddieaudioquick_entrypoint_3((Actor *)arg0, (f32 *)(arg0 + 4), D_8080134C_chonearmbandit, 0.1f);
            if (func_80101E14((Actor *)arg0, 0.25f)) {
                func_80108B04((Actor *)arg0, 0);
            }
            if (func_80101DDC((Actor *)arg0)) {
                *(f32 *)(arg0 + 0x58) -= func_800D8FF8();
                if (*(f32 *)(arg0 + 0x58) < 0.0f) {
                    if (((struct InteractionFlags *)(arg0 + 0x64))->interacting) {
                        func_80800680_chonearmbandit(arg0, 2);
                    } else {
                        func_80800680_chonearmbandit(arg0,
                            func_8010C9B0((f32 *)(arg0 + 4), 800) ?
                            (func_8010D278() == 0x10 ? 6 : 2) : 4);
                    }
                }
            }
            break;
        case 7:
            if (func_80101DDC((Actor *)arg0)) {
                func_80800680_chonearmbandit(arg0, 1);
            }
            break;
        case 6:
            _subaddieaudioquick_entrypoint_3((Actor *)arg0, (f32 *)(arg0 + 4), D_808011F0_chonearmbandit, 0.75f);
            if (func_80101E14((Actor *)arg0, 0.999f)) {
                if (((struct InteractionFlags *)(arg0 + 0x64))->interacting) {
                    func_80800680_chonearmbandit(arg0, 2);
                } else if (!func_8010C9B0((f32 *)(arg0 + 4), 800)) {
                    func_80800680_chonearmbandit(arg0, 4);
                }
            }
            func_808008E0_chonearmbandit(arg0, 180.0f);
            break;
        }
    }
}

s32 func_80800520_chonearmbandit(Actor *arg0, s32 arg1, volatile s32 arg2) {
    s32 _chexploder_entrypoint_4(void *, s32, s32);
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_80101074(void *);
    s32 func_80107070(Actor *, u32);
    s32 func_801072A8(void *);
    void func_808006F8_chonearmbandit(u8 *, s32);
    void func_80800AB8_chonearmbandit(Actor *);
    void func_80800D00_chonearmbandit(Actor *);
    extern s32 D_80801280_chonearmbandit;
    switch (arg1) {
        case 0x3F:
            func_808006F8_chonearmbandit((u8 *)arg0, arg2);
            break;
        case 0x40:
            _chexploder_entrypoint_4(arg0, *(s32 *)*(s32 *)&arg2 + 4, 4);
            break;
        case 0x3D:
            if (func_801072A8(arg0) == 0) {
                func_80800AB8_chonearmbandit(arg0);
            }
            break;
        case 0x90:
            func_80800D00_chonearmbandit(arg0);
            break;
        case 2:
            if ((s32)arg0->unk70_10 > 0 && _subaddieDll_entrypoint_3(arg0) == 0) {
                func_80107070(arg0, 1);
            }
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(arg0);
            break;
        case 0x38:
            func_80101074(&D_80801280_chonearmbandit);
            return 5;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_8080063C_chonearmbandit(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

void func_80800680_chonearmbandit(u8 *arg0, s32 arg1) {
    struct InteractionFlags {
        unsigned int : 2;
        unsigned int interacting : 1;
        unsigned int : 29;
    };
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80102424(Actor *, s32);
    extern s32 D_80801354_chonearmbandit;
    func_80102424((Actor *)arg0, arg1);
    if (arg1 == 5) {
        _subaddieaudioquick_entrypoint_2((Actor *)arg0, (f32 *)(arg0 + 4), &D_80801354_chonearmbandit);
        if (((struct InteractionFlags *)(arg0 + 0x64))->interacting) {
            ((Actor *)arg0)->unk58 = 0.36f;
            return;
        }
        ((Actor *)arg0)->unk58 = 1.2f;
    }
}

/* extern */

void func_808006F8_chonearmbandit(u8 *arg0, s32 arg1) {
    struct Flags {
        unsigned int : 29;
        unsigned int active : 1;
        unsigned int : 2;
    };
    void func_80800680_chonearmbandit(u8 *, s32);
    if (!((struct Flags *)(arg0 + 0x78))->active &&
        (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 7)) {
        func_80800680_chonearmbandit(arg0, 7);
    }
}

void func_80800740_chonearmbandit(u8 *arg0, f32 arg1) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_8010D09C(s32, f32 *, f32);
    extern u8 D_808011FC_chonearmbandit[];
    f32 position[3];
    f32 pad;
    f32 difference;
    f32 delta;

    if (((Actor *)arg0)->unk64_29) {
        _subaddiejoy_entrypoint_9(((Actor *)arg0), &((Actor *)arg0)->unk54, 3);
        func_80102BF8(((Actor *)arg0), 0.2f, 6.0f, 220.0f);
        return;
    }
    delta = func_800D8FF8();
    func_8010D09C(func_800F54E4(), position, 0.8f);
    if (((Actor *)arg0)->unk70_10 == 2 || ((Actor *)arg0)->unk70_10 == 3 || ((Actor *)arg0)->unk70_10 == 6) {
        if (_subaddierouteDll_entrypoint_4(((Actor *)arg0))) {
            ((Actor *)arg0)->unk54 = func_800136E4(func_80102D78(((Actor *)arg0), position) + arg1);
            _subaddierouteDll_entrypoint_7(((Actor *)arg0), func_80100094(((Actor *)arg0), 1),
                ((Actor *)arg0)->rotation[1], ((Actor *)arg0)->unk54, 200.0f, 0x4000);
        }
    } else {
        ((Actor *)arg0)->unk54 = func_800136E4(func_80102D78(((Actor *)arg0), position) + arg1);
    }
    difference = func_800F1DCC(func_800F1FF0(((Actor *)arg0)->rotation[1], ((Actor *)arg0)->unk54,
        0.15f, delta * 4.0f, delta * 120.0f), ((Actor *)arg0)->rotation[1]);
    difference *= func_800F3780(func_80101F24(((Actor *)arg0)), D_808011FC_chonearmbandit, 3);
    ((Actor *)arg0)->rotation[1] = func_800136E4(((Actor *)arg0)->rotation[1] + difference);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_808008E0_chonearmbandit.s")

void func_80800A14_chonearmbandit(u8 *arg0, f32 arg1) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern u32 D_808011F0_chonearmbandit[];
    extern s32 D_80801364_chonearmbandit;
    f32 position[3];
    f32 height;

    if (_subaddieaudioquick_entrypoint_3((Actor *)arg0, ((Actor *)arg0)->position, D_808011F0_chonearmbandit, arg1)) {
        if (_subaddieskeleton_entrypoint_2(((Actor *)arg0)->unk0, 5, position)) {
            height = ((Actor *)arg0)->position[1];
            if (height < position[1]) {
                position[1] = height;
            }
            func_800BBCB8(position, position, 0.7f, 6, &D_80801364_chonearmbandit);
        }
        _subaddiejoy_entrypoint_10(arg0, 1.4f, 0.3f);
    }
}

void func_80800AB8_chonearmbandit(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    f32 func_800136E4(f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    int func_800F20BC(f32, f32, f32);
    u32 func_800F54E4(void);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80108944(Actor *, Actor *);
    void func_8010D09C(s32, f32 *, f32);
    f32 target[3];
    f32 position[3];
    Actor *spawned;
    f32 yaw;
    f32 difference;

    if (!_subaddieskeleton_entrypoint_2(arg0->unk0, 4, position)) {
        func_800EE7F8(position, arg0->position);
        position[1] += arg0->scale * 60.0f;
    }
    spawned = func_80108528(0x35B, position, (s32)arg0->rotation[1], &arg0);
    func_80102FDC(spawned, arg0->scale);
    func_8010D09C(func_800F54E4(), target, 0.8f);
    target[1] += 60.0f;
    if (arg0->unk64_29) {
        yaw = func_800136E4(func_800F1DF4(spawned->position, target));
        if (func_800F20BC(yaw, arg0->rotation[1], 8.0f)) {
            spawned->rotation[1] = yaw;
        } else {
            spawned->rotation[1] = arg0->rotation[1];
        }
    } else {
        spawned->rotation[1] = func_800136E4(func_800F1DF4(spawned->position, target));
        difference = func_800F1DCC(spawned->rotation[1], arg0->rotation[1]);
        if (difference < -60.0f) {
            spawned->rotation[1] = arg0->rotation[1] - 60.0f;
        } else if (difference > 60.0f) {
            spawned->rotation[1] = arg0->rotation[1] + 60.0f;
        }
    }
    spawned->rotation[0] = func_800136E4(func_800F1828(spawned->position, target));
    if (spawned->rotation[0] > 180.0f) {
        if (spawned->rotation[0] < 350.0f) {
            spawned->rotation[0] = 350.0f;
        }
    } else if (spawned->rotation[0] > 10.0f) {
        spawned->rotation[0] = 10.0f;
    }
    func_80108944(spawned, arg0);
}

void func_800FFAB0(Actor *);
void func_80800D00_chonearmbandit(Actor *arg0) {
    extern void _chbaddiesetup_entrypoint_10(void);
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    s32 func_800D1000(s32, s32, f32 *, s32, s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void *func_80101080(void);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80107070(Actor *, u32);
    s32 func_8010A430(void *);
    u32 func_80800E78_chonearmbandit(Actor *);
    extern u8 D_8080139C_chonearmbandit[];
    s32 fade[3];
    Actor *spawned;
    u32 item;
    union { f32 f[3]; s32 i[3]; } position;
    union { f32 f; s32 i; } yaw;
    s32 kind;

    spawned = func_80106790(func_80101080());
    _chexploder_entrypoint_9(spawned, 3, 0);
    _chexploder_entrypoint_9(spawned, 4, 1);
    _chexploder_entrypoint_6(spawned, 1000.0f, 1200.0f);
    _subaddiefade_entrypoint_9(arg0, fade);
    _subaddiefade_entrypoint_11(spawned, fade);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080139C_chonearmbandit);
    _subaddiejoy_entrypoint_10(arg0, 1.4f, 0.3f);
    arg0->unk64_24 = 0;
    item = func_80800E78_chonearmbandit(arg0);
    if (item != 0) {
        func_800D1000(item, 8, arg0->position, 1, 0);
    } else if (func_8010A430(arg0)) {
        yaw.f = func_800DC178(0.0f, 359.0f);
        if (func_800DC298(0.5f)) {
            kind = 0x18;
        } else {
            kind = 0x19;
        }
        func_80103DFC(arg0, position.f);
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, kind,
            position.i[0], position.i[1], position.i[2], yaw.i);
    }
    if (func_80107070(arg0, 3) == 0) {
        func_800FFAB0(arg0);
    }
}

u32 func_80800E78_chonearmbandit(Actor *arg0) {
    u32 temp_a0;

    temp_a0 = arg0->unk74_7 - 0x31;
    if (func_800D0A9C(temp_a0, 8U) != 0) {
        return 0U;
    }
    return temp_a0;
}

void _subaddiefade_entrypoint_3(Actor *);
s32 func_8001210C(s32);
f32 func_800D8FF8(void);
s32 func_800D90A4(f32 *);
void func_8010A570(Actor *);
void func_80801114_chonearmbandit(Actor *);
s32 func_80801154_chonearmbandit(Actor *);

void func_80800EBC_chonearmbandit(Actor *arg0) {
    f32 sp24;

    sp24 = func_800D8FF8();
    if (func_800D90A4(&arg0->unk58) && !arg0->unk7C_12 && !arg0->unk64_20) {
        func_8010A570(arg0);
        _subaddiefade_entrypoint_3(arg0);
        arg0->unk64_20 = 1;
    }
    arg0->unk54 += sp24 * ((f32 *)arg0->actorData)[4];
    if (func_8001210C(1)) {
        func_80801114_chonearmbandit(arg0);
    }
    if (arg0->unk70_10 == 1) {
        func_80801154_chonearmbandit(arg0);
    }
}

/* extern */

void func_80800F80_chonearmbandit(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    f32 var_f2;

    if (func_800DC298(0.5f) != 0) {
        var_f2 = -1.0f;
    } else {
        var_f2 = 1.0f;
    }
    ((f32 *)arg0->actorData)[4] = func_800DC178(600.0f, 800.0f) * var_f2;
    arg0->unk58 = 4.0f;
    ((f32 *)arg0->actorData)[3] = 1000.0f;
}

void func_808010AC_chonearmbandit(Actor *, s32);
s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);

s32 func_80801008_chonearmbandit(Actor *arg0, s32 arg1, volatile s32 arg2) {
    if (arg1 == 0x40) {
        func_808010AC_chonearmbandit(arg0, *(s32 *)&arg2);
        return 1;
    }
    return 0;
}

/* extern */

void func_80801040_chonearmbandit(u8 *arg0, s32 arg1) {
    void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, s32 arg4);
    void func_800DF47C(s32 arg0, s32 arg1);
    void func_800EFA4C(f32[3], f32, f32, f32);
    s32 func_801015D0(Actor*);
    s32 func_8010347C(s32);
    f32 sp2C[3];

    func_800EFA4C(sp2C, (*(f32 *)((s8 *)(arg0) + (0x50))), (*(f32 *)((s8 *)(arg0) + (0x54))), 0.0f);
    func_800DF47C((s32) func_801015D0, (s32) arg0);
    func_800DE448(arg0 + 4, sp2C, (*(f32 *)((s8 *)(arg0) + (0x38))), NULL, func_8010347C((*(s32 *)((s8 *)(arg0) + (0)))));
}

void func_808010AC_chonearmbandit(Actor *arg0, s32 arg1) { void func_800C4AF0(f32 *, void *); extern s32 D_808013A4_chonearmbandit; extern s32 D_808013DC_chonearmbandit; (void)&arg0; func_800BBCB8(arg0->position, arg0->position, arg0->scale, 6, &D_808013A4_chonearmbandit);
    func_800C4AF0(arg0->position, &D_808013DC_chonearmbandit); func_8010A570(arg0); func_800FFAB0(arg0); }

void func_80801114_chonearmbandit(Actor *arg0) {
    extern s32 D_808013E8_chonearmbandit;
    func_800BBCB8(arg0->position, 0, arg0->scale, 1, &D_808013E8_chonearmbandit);
}

/* extern */

s32 func_80801154_chonearmbandit(Actor *arg0) {
    void func_801096C8(Actor *, s32);
    s32 func_8010B990(Actor *, s32);
    s32 var_a1;

    (void)&arg0;
    var_a1 = 6;
    if (!arg0->unk64_20) {
        var_a1 = 0x100006;
    }
    if (func_8010B990(arg0, var_a1) & 0x30) {
        func_801096C8(arg0, 0);
        func_808010AC_chonearmbandit(arg0, 0);
        return 1;
    }
    return 0;
}
