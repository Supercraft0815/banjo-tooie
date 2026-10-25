#include "common.h"
void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
s32 func_800C05B8(s32, s32, f32 *, Unk80132ED0 *, s32, s32, s16);

/* extern */

void func_80800000_chjinjo(Actor *arg0) {
    s16 chjinjo_entrypoint_2(s32);
    u8 func_800D0CC8(s32);
    u32 func_800D1338(u32);
    s32 func_800DA298(s32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    s32 var_v0;

    arg0->unk79_4 = 1;
    if (func_800DA298(0x653) != 0) {
        func_800FFAB0(arg0);
    }
    if (arg0->unk6C_9 == 0x48F) {
        var_v0 = chjinjo_entrypoint_2(-1);
    } else {
        var_v0 = func_800D0CC8(arg0->unk6C_0);
    }
    if ((arg0->unk6C_9 == 0x48F) && ((f32) (s32) func_800D1338(var_v0) <= arg0->rotation[1])) {
        func_800FFAB0(arg0);
    }
    if (arg0->unk64_20) {
        func_800FC660(0x10);
    }
}

u8 func_800D0CC8(s32);
s32 chjinjo_entrypoint_0(s32);

s32 func_808000DC_chjinjo(Actor *arg0) {
    return chjinjo_entrypoint_0(func_800D0CC8(arg0->unk6C_0));
}

s32 chjinjo_entrypoint_0(s32 arg0) {
    extern s16 D_80801368_chjinjo[];
    return ((s16 *)&D_80801368_chjinjo)[arg0];
}

/* extern */

void func_80800120_chjinjo(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor*, u32);
    void func_800FC74C(u32);
    s32 func_8080102C_chjinjo(Actor *, s32);
    if (arg0->actorData[5] != 0U) {
        func_800FC74C(0x1CU);
        arg0->actorData[5] = 0;
    }
    func_8080102C_chjinjo(arg0, 1);
    _suexpression_entrypoint_8(arg0, 1U);
}

/* extern */

void chjinjo_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800D0C78(s32, s32, s32);
    func_800D0C78(arg0 + 0x51, 1, arg1);
}

s16 chjinjo_entrypoint_2(s32 arg0) {
    s32 func_800EA05C();
    extern s16 D_80801300_chjinjo;
    extern s16 D_80801302_chjinjo;
    extern s32 D_80801304_chjinjo;
    extern s32 D_80801324_chjinjo;
    s32 *var_v1;
    if (arg0 == -1) {
        arg0 = func_800EA05C();
    }
    var_v1 = &D_80801304_chjinjo;
    if (arg0 == D_80801300_chjinjo) {
        return D_80801302_chjinjo;
    }
loop_5:
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0)))) {
        return (*(s16 *)((s8 *)(var_v1) + (2)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (4)))) {
        return (*(s16 *)((s8 *)(var_v1) + (6)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (8)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0xA)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0xC)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0xE)));
    }
    var_v1 += 4;
    if (var_v1 == &D_80801324_chjinjo) {
        return -1;
    }
    goto loop_5;
}

s16 chjinjo_entrypoint_3(s32 arg0) {
    extern s16 D_80801300_chjinjo;
    extern s16 D_80801302_chjinjo;
    extern s32 D_80801304_chjinjo;
    extern s32 D_80801324_chjinjo;
    s32 *var_v1;

    var_v1 = &D_80801304_chjinjo;
    if (arg0 == D_80801302_chjinjo) {
        return D_80801300_chjinjo;
    }
loop_3:
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (2)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (6)))) {
        return (*(s16 *)((s8 *)(var_v1) + (4)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0xA)))) {
        return (*(s16 *)((s8 *)(var_v1) + (8)));
    }
    if (arg0 == (*(s16 *)((s8 *)(var_v1) + (0xE)))) {
        return (*(s16 *)((s8 *)(var_v1) + (0xC)));
    }
    var_v1 += 4;
    if (var_v1 == &D_80801324_chjinjo) {
        return -1;
    }
    goto loop_3;
}

void func_808002E0_chjinjo(Actor *arg0) {
    typedef struct {
        u8 pad0[0x70];
        u32 pad70_4 : 28;
        u32 unk70_3 : 1;
        u32 pad70_0 : 3;
        u32 pad74_21 : 11;
        u32 unk74_20 : 1;
        u32 pad74_0 : 20;
    } JinjoFlags;
    void _fxtwinkle_entrypoint_0(f32 *);
    s32 _glcutDll_entrypoint_6(s32, s32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 _subaddiefade_entrypoint_1(Actor *, s32);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void func_8008FFBC(f32 *);
    s32 func_800901CC(f32 *, f32);
    void func_800C3EB8(s32);
    void func_800C4244(s32, f32, u32, f32 *, f32, f32);
    f32 func_800D8FF8(void);
    s32 func_800DA7A8(s32, s32, s32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    void func_800EF3DC(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_800F82D4(s32, s32);
    void func_800FC63C(u32, u32);
    void func_800FC74C(u32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    s32 func_800FCCD4(s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102FE8(Actor *, s32);
    void func_8010C908(Actor *, f32 *);
    void func_8010D254(f32 *);
    void func_80800EE4_chjinjo(Actor *);
    void func_80800F14_chjinjo(Actor *);
    void func_80800F80_chjinjo(Actor *);
    s32 func_8080102C_chjinjo(Actor *, s32);
    extern u32 D_8080137C_chjinjo;
    f32 sp74[3];
    f32 sp68[3];
    f32 sp64;
    s32 sp60;
    f32 sp5C;
    s32 sp58;
    f32 sp54;
    f32 sp48[3];
    s32 sp44;
    s32 sp40;

    sp64 = func_800D8FF8();
    if (((JinjoFlags *)arg0)->unk70_3) {
        _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
        if (arg0->unk74_29) {
            func_800E3980(sp74);
        } else {
            func_8010D254(sp74);
        }
        if (arg0->unk6C_9 == 0x48F) {
            func_8010C908(arg0, arg0->position);
        }
        func_800F1E6C(arg0->position, sp74, &sp5C);
        sp54 = func_800F1DCC(arg0->rotation[1], sp5C);
        switch (arg0->unk70_10) {
        case 1:
            if (func_800DC0C0() < 0.015f) {
                if (func_800901CC(arg0->position, 55.0f)) {
                    func_80102424(arg0, 3);
                } else {
                    func_80102424(arg0, 2);
                }
            }
            break;
        case 2:
            func_80800F14_chjinjo(arg0);
            if (func_80101E14(arg0, 0.999f)) {
                func_80102424(arg0, 1);
            }
            break;
        case 3:
            func_80800F80_chjinjo(arg0);
            if (func_80101E14(arg0, 0.999f)) {
                func_80102424(arg0, 1);
            }
            break;
        case 4:
            func_80800EE4_chjinjo(arg0);
            if (func_80101E14(arg0, 0.999f)) {
                func_80102424(arg0, 1);
            } else if (sp54 >= 0.0f) {
                arg0->rotation[1] -= 80.0f * sp64;
            } else {
                arg0->rotation[1] += 80.0f * sp64;
            }
            break;
        case 6:
            func_80800EE4_chjinjo(arg0);
            if (sp54 >= 0.0f) {
                arg0->rotation[1] -= 120.0f * sp64;
            } else {
                arg0->rotation[1] += 120.0f * sp64;
            }
            if (func_80101E14(arg0, 0.0f)) {
                arg0->unk79_4--;
                if (arg0->unk79_4 == 0) {
                    func_80102424(arg0, 7);
                    func_80102FE8(arg0, 0);
                    func_800FC63C(2, 0x6D60);
                }
            }
            break;
        case 7:
        case 8:
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 0.0f, 0.0f);
            sp58 = arg0->unk70_10 == 7;
            if (!sp58 || func_80101F24(arg0) > 0.1f) {
                func_8008FFBC(sp68);
                func_800EF334(sp68, sp64 * 6.0f);
                func_800EF04C(sp68, sp74);
                func_800EF3DC(sp68, arg0->position);
                func_800EF334(sp68, sp64 * 3.0f);
                func_800EF04C(arg0->position, sp68);
                if (sp58 || func_80101F24(arg0) < 0.8f) {
                    for (sp60 = 0; sp60 != 4; sp60++) {
                        if (func_800DC0C0() < 0.3f) {
                            _subaddieskeleton_entrypoint_0(arg0, 3, sp48);
                            func_800EF214(sp48, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f), 15.0f);
                            _fxtwinkle_entrypoint_0(sp48);
                        }
                    }
                }
            }
            if (sp58) {
                if (func_80101F24(arg0) < 0.2f) {
                    if (sp54 >= 0.0f) {
                        arg0->rotation[1] -= 120.0f * sp64;
                    } else {
                        arg0->rotation[1] += 120.0f * sp64;
                    }
                }
                if (func_80101E14(arg0, 0.1f)) {
                    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_8080137C_chjinjo);
                    arg0->actorData[5] = 1;
                    func_800FC63C(0x1C, 0x7FFF);
                    func_800FCA90(0x1C);
                    func_800C4244(0x4A2, 0.8f, 0x7FFF, arg0->position, 300.0f, 2000.0f);
                } else if (func_80101E14(arg0, 0.434f) || func_80101E14(arg0, 0.811f)) {
                    func_800C4244(0x4A2, 0.9f, 0x7FFF, arg0->position, 300.0f, 2000.0f);
                }
            } else {
                if (func_80101E14(arg0, 0.214f)) {
                    func_800C4244(0x4A2, 1.1f, 0x7FFF, arg0->position, 300.0f, 2000.0f);
                } else if (func_80101E14(arg0, 0.55f)) {
                    func_800C4244(0x43A, 1.5f, 0x7FFF, arg0->position, 300.0f, 2000.0f);
                } else if (func_80101E14(arg0, 0.75f)) {
                    if (func_800FCCD4(2)) {
                        func_800FCAE0(2, 0, 4000);
                        func_800FCA90(2);
                    }
                } else if (func_80101E14(arg0, 0.85f)) {
                    _subaddieaudioloop_entrypoint_2(arg0);
                    func_800C3EB8(0x411);
                    func_800FC74C(0x1C);
                    arg0->actorData[5] = 0;
                }
                if (func_80101F24(arg0) > 0.75f) {
                    sp44 = _subaddiefade_entrypoint_0(arg0);
                    if (sp44 >= 7) {
                        sp44 -= 7;
                    }
                    if (func_80101F24(arg0) > 0.9f) {
                        sp44 = sp44 >= 21 ? sp44 - 21 : 0;
                    }
                    _subaddiefade_entrypoint_1(arg0, sp44);
                }
                if (func_80101E14(arg0, 0.999f)) {
                    func_80102424(arg0, 9);
                    ((JinjoFlags *)arg0)->unk74_20 = 0;
                    arg0->unk64_16 = ((JinjoFlags *)arg0)->unk74_20;
                }
            }
            if (sp58 && (func_80101E14(arg0, 0.96f) || func_80101E14(arg0, 0.999f))) {
                func_80102424(arg0, 8);
            }
            break;
        case 9:
            if (arg0->unk74_30) {
                sp40 = func_800D0CC8(arg0->unk6C_0);
                if (arg0->unk64_19) {
                    func_800F82D4(arg0->actorData[4], 0);
                    func_800DA7A8(0x6D0, sp40, 4);
                    _glcutDll_entrypoint_6(0x142, 0x84);
                } else {
                    func_8080102C_chjinjo(arg0, 0);
                }
                arg0->unk74_30 = 0;
                arg0->unk64_19 = 0;
            }
            func_800FFAB0(arg0);
            break;
        }
        if ((s32)arg0->unk70_10 < 4 && (sp54 > 45.0f || sp54 < -45.0f)) {
            func_80102424(arg0, 4);
        }
    }
}

/* extern */

void chjinjo_entrypoint_4(s32 arg0, s32 arg1, s32 arg2) {
    s32 _glcutDll_entrypoint_6(s32, s32);
    _glcutDll_entrypoint_6(0x142, 0x84);
}

s32 func_80800C10_chjinjo(Actor *arg0, s32 arg1, void *volatile arg2) {
    typedef struct {
        u8 pad0[0x18];
        u32 pad18_16 : 16;
        u32 unk18_5 : 11;
        u32 pad18_0 : 5;
    } JinjoEvent;
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void *_suexpression_entrypoint_20(Actor *);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    void _suexpression_entrypoint_8(Actor *, u32);
    void func_800D0BD4(s32, u32);
    u8 func_800D0CC8(s32);
    s32 func_800D129C(u32);
    u32 func_800D1338(u32);
    s32 func_800D24E8(s32, s32, u32);
    s32 func_800DA9E4(s32, s32);
    void func_80102424(Actor *, s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_80108A30(s32, void *, f32, s32);
    void func_8010A570(Actor *);
    s32 func_8010A6B0(Actor *, s32);
    u32 func_80801098_chjinjo(Actor *, s32);
    extern s32 D_80801324_chjinjo;
    extern void _chjinjo_entrypoint_4(s32, s32, s32);
    JinjoEvent *sp44;
    s32 sp40;
    s32 color;

    switch (arg1) {
    case 0x29:
        _suexpression_entrypoint_7(arg0, 1, (s16)func_808000DC_chjinjo(arg0));
        _suexpression_entrypoint_12(_suexpression_entrypoint_20(arg0), 65.0f, 30.0f);
        break;
    case 0x2A:
        _suexpression_entrypoint_8(arg0, 1);
        break;
    case 0x3E:
        sp44 = arg2;
        if ((s32)arg0->unk70_10 < 5) {
            if (func_8010A6B0(arg0, sp44->unk18_5)) {
                sp40 = func_800D0CC8(arg0->unk6C_0);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801324_chjinjo);
                func_80102424(arg0, 6);
                _subaddieDll_entrypoint_4(arg0, 1);
                func_8010A570(arg0);
                if (!func_800DA9E4(0x35, 1)) {
                    func_800C05B8(0xCDA, 0xC, NULL, NULL, (s32)_chjinjo_entrypoint_4, 0, func_808000DC_chjinjo(arg0));
                }
                func_800D0BD4(arg0->unk6C_0, 0);
                func_800D24E8(sp40 + 0xE1, func_800D1338(sp40), func_800D129C(sp40));
                func_80801098_chjinjo(arg0, sp44->unk18_5);
            }
        }
        break;
    case 0x13:
        arg0->unk6C_0 = (s32)arg2;
        if (arg0->unk6C_0 == 0x1E) {
            arg0->unk74_29 = 1;
        }
        break;
    case 0x7E:
        if (arg0->rotation[1] == 0.0f) {
            func_80108A30(0x4D6, arg0->position, 0, 0x32);
        }
        break;
    case 0x14:
        arg0->unk64_20 = 1;
        break;
    case 0x95:
        if (arg0->unk6C_9 == 0x48F) {
            color = chjinjo_entrypoint_2(-1);
        } else {
            color = func_800D0CC8(arg0->unk6C_0);
        }
        func_80103140(arg0, 0x643, color + 0xC31);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800EE4_chjinjo(Actor *arg0) {
    extern u32 D_80801358_chjinjo;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801358_chjinjo, 0.6f);
}

void func_80800F14_chjinjo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_80101E14(Actor *, f32);
    extern s32 D_8080133C_chjinjo;
    extern s32 D_80801348_chjinjo;
    if (func_80101E14(arg0, 0.2f) != 0) {
        if (arg0->unk6C_9 == 0x48F) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801348_chjinjo);
            return;
        }
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080133C_chjinjo);
    }
}

void func_80800F80_chjinjo(Actor *arg0) {
    extern u32 D_80801330_chjinjo;
    if (arg0->unk6C_9 != 0x48F) {
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801330_chjinjo, 0.2f);
    }
}

void func_80800FC4_chjinjo(Actor *arg0) { extern u16 D_80801390_chjinjo[]; s32 sp2C; sp2C = func_800D0CC8(arg0->unk6C_0); func_800C05B8(D_80801390_chjinjo[sp2C], 0x44, NULL, NULL, 0, 0, func_808000DC_chjinjo((u8 *)arg0)); }

s32 func_8080102C_chjinjo(Actor *arg0, s32 arg1) {
    if (arg0->unk74_30) {
        chjinjo_entrypoint_1(func_800D0CC8(arg0->unk6C_0), arg1);
        *(u8 *)((s8 *)arg0 + 0x74) = (*(u8 *)((s8 *)arg0 + 0x74)) & 0xFFBF;
        return 1;
    }
    return 0;
}

/* extern */

u32 func_80801098_chjinjo(Actor *arg0, s32 arg1) {
    s32 func_800D035C(s32);
    u8 func_800D0CC8(s32);
    s32 func_800D129C(u32);
    u32 func_800D1338(u32);
    s32 func_800DA298(s32);
    s32 func_800DA7A8(s32, s32, s32);
    void func_800F82D4(s32, s32);
    s32 sp2C;
    s32 temp_v0;
    s32 sp24;
    u32 sp20;

    temp_v0 = func_800D0CC8(arg0->unk6C_0);
    sp24 = temp_v0;
    arg0->unk64_19 = 0;
    arg0->unk74_30 = 0;
    arg0->actorData[4] = arg1;
    sp20 = func_800D1338(temp_v0);
    sp2C = func_800D129C(sp24) == sp20;
    if (func_800D035C(0) == 1) {
        func_800DA7A8(0x6D0, func_800D0CC8(arg0->unk6C_0), 4);
    } else if (sp2C != 0) {
        arg0->unk74_30 = 1;
        if (func_800DA298(0x43D) == 0) {
            arg0->unk64_19 = 1;
            func_800F82D4(arg0->actorData[4], 2);
        } else {
            func_80800FC4_chjinjo(arg0);
        }
    }
    return arg0->unk74_30;
}

OSThread *chjinjo_entrypoint_5(void)
{
    extern u8 D_808013A4_chjinjo[];

    return (OSThread *) D_808013A4_chjinjo;
}

OSThread *chjinjo_entrypoint_6(void)
{
    extern u8 D_808013EC_chjinjo[];

    return (OSThread *) D_808013EC_chjinjo;
}
