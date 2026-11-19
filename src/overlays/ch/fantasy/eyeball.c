#include "common.h"

/* extern */

void func_80800000_chfantasyeyeball(Actor *arg0) {
    void _subaddielink_entrypoint_0(void *arg0);
    s32 func_800D0B68(u32, u32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_808010B0_chfantasyeyeball(Actor *, f32 *, f32 *);
    if (func_800D0B68(0x4C, 1) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (!(arg0->unk74_7 - 0x32) && (func_800D0B68(0x4C, 1) == 0)) {
        arg0->unk64_20 = 1;
    } else {
        arg0->unk64_20 = 0;
    }
    func_808010B0_chfantasyeyeball(arg0, &arg0->actorData[2], &arg0->actorData[4]);
    func_808010B0_chfantasyeyeball(arg0, &arg0->actorData[0], &arg0->actorData[1]);
    arg0->unk64_19 = 0;
    _subaddielink_entrypoint_0(func_80100094(arg0, 0));
    ((f32 *)arg0->actorData)[6] = 0.0f;
}

void func_808000D8_chfantasyeyeball(Actor *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3)) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    BtIntPtr func_800B53A4(s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4140(s32, f32 *, s32);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    int func_800F6720(BtIntPtr);
    void func_800FC6B0(u32);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80108B04(Actor *, u32);
    void func_8010A590(Actor *);
    void func_8010C93C(BtIntPtr, BtIntPtr, f32);
    s32 func_8010C9B0(f32 *, s32);
    s32 func_80800950_chfantasyeyeball();
    void func_808011D0_chfantasyeyeball(Actor *, f32, f32, f32);
    void func_80801314_chfantasyeyeball(void *);
    void func_80801378_chfantasyeyeball(Actor *);
    void func_808013F8_chfantasyeyeball(Actor *);
    void func_80801740_chfantasyeyeball(Actor *, f32 *);
    s32 func_808017B4_chfantasyeyeball();
    extern s32 D_80801EEC_chfantasyeyeball[];
    f32 sp54[3];
    s32 sp50;
    BtIntPtr sp4C;
    Actor *sp48;
    Actor *sp44;
    f32 sp40;
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused : 29, u32 remaining : 2);
        u32 disabled : 1;
        BT_BITFIELD_ORDER(u32 remaining : 2, u32 unused : 29);
    } EyeballUpdateFlags;

    _sudeflect_entrypoint_0(arg0->position, arg0->scale * 456.0f, arg0->scale * 224.0f, 0xE);
    if (!((EyeballUpdateFlags *)&arg0->unk78)->disabled) {
        switch (arg0->unk70_10) {
        case 1:
            if (func_8010C9B0(arg0->position, 5000) && func_800F6720(func_800F54E4())) {
                func_80800950_chfantasyeyeball(arg0, 2);
            }
            break;
        case 2:
            if (func_80101DDC(arg0)) {
                func_80800950_chfantasyeyeball(arg0, 3);
            }
            if (!func_800DA298(0x6EC)) {
                func_800D90A4(&arg0->unk58);
                func_808011D0_chfantasyeyeball(arg0, ((f32 *)arg0->actorData)[2], ((f32 *)arg0->actorData)[4], func_800F10B4(arg0->unk58, 2.708f, 0.0f, 1.0f, 0.0f));
            }
            if (func_80101E14(arg0, 0.4f)) {
                func_800C4140(0x8CBB5C1E, arg0->position, 0x1B5801F4);
            } else if (func_80101E14(arg0, 0.0f)) {
                func_800C4140(0x7FFB5C1D, arg0->position, 0x1B5801F4);
            }
            break;
        case 3:
            if (!func_800DA298(0x6EC)) {
                if (!func_800D90A4(&arg0->unk58) || arg0->unk64_19) {
                    func_808011D0_chfantasyeyeball(arg0, ((f32 *)arg0->actorData)[2], ((f32 *)arg0->actorData)[4], func_800F10B4(arg0->unk58, 2.708f, 0.0f, 1.0f, 0.0f));
                } else {
                    func_80801314_chfantasyeyeball(arg0);
                    func_800DA544(0x6EC);
                }
            } else if (func_8010C9B0(arg0->position, 5000)) {
                if (!func_800F6720(func_800F54E4())) {
                    func_80800950_chfantasyeyeball(arg0, 4);
                } else if (func_800D90A4(&((f32 *)arg0->actorData)[3]) && func_808017B4_chfantasyeyeball(arg0)) {
                    func_80800950_chfantasyeyeball(arg0, 5);
                }
            }
            break;
        case 4:
            if (func_80101DDC(arg0)) {
                func_80800950_chfantasyeyeball(arg0, 1);
            }
            break;
        case 5:
            if (func_80101E14(arg0, 0.55f)) {
                func_800C4140(((u16)(func_800DC178(1.15f, 1.25f) * 1023.0f) << 21) + 0x1B5E3D, arg0->position, 0x1B5801F4);
                func_80108B04(arg0, 1);
            } else if (func_80101DDC(arg0)) {
                func_80800950_chfantasyeyeball(arg0, 3);
            }
            break;
        case 7:
        case 10:
            if (func_80101DDC(arg0)) {
                if (arg0->unk64_20) {
                    if (arg0->actorData[7]) {
                        func_80800950_chfantasyeyeball(arg0, arg0->unk70_10 == 7 ? 8 : 11);
                    } else {
                        func_8010A590(_subaddielink_entrypoint_4(func_80100094(arg0, 0)));
                        func_80800950_chfantasyeyeball(arg0, arg0->unk70_10 == 7 ? 9 : 12);
                    }
                } else {
                    func_80800950_chfantasyeyeball(arg0, arg0->unk70_10 == 7 ? 9 : 12);
                }
            }
            if (arg0->unk64_20) {
                func_800D90A4(&arg0->unk58);
                func_808011D0_chfantasyeyeball(arg0, ((f32 *)arg0->actorData)[2], ((f32 *)arg0->actorData)[4], func_800F10B4(arg0->unk58, 2.708f, 0.0f, 1.0f, 0.0f));
            }
            if (func_80101E14(arg0, 0.35f)) {
                func_80801740_chfantasyeyeball(arg0, sp54);
                for (sp50 = 0; sp50 != 8; sp50++) {
                    sp4C = func_800B53A4(3);
                    func_800BA3FC(sp4C, sp50 + 0x9DF);
                    func_800BABB8(sp4C, sp54, sp54, 3.0f, D_80801EEC_chfantasyeyeball);
                }
                func_800C4140(0xBFDB5C13, arg0->position, 0x1B5801F4);
                func_80108B04(arg0, 2);
            }
            break;
        case 8:
        case 11:
            sp48 = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
            if (func_800D90A4(&arg0->unk58)) {
                func_80800950_chfantasyeyeball(arg0, arg0->unk70_10 == 8 ? 9 : 12);
            } else {
                func_808011D0_chfantasyeyeball(arg0, ((f32 *)arg0->actorData)[2], ((f32 *)arg0->actorData)[4], func_800F10B4(arg0->unk58, 2.708f, 0.0f, 1.0f, 0.0f));
            }
            _subaddiefade_entrypoint_1(sp48, (s32)func_800F10B4(arg0->unk58, 1.5f, 0.0f, 255.0f, 0.0f));
            break;
        case 6:
            sp44 = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
            if (func_800D90A4(&arg0->unk58)) {
                func_80801314_chfantasyeyeball(arg0);
                func_80800950_chfantasyeyeball(arg0, 1);
            }
            sp40 = func_800F10B4(arg0->unk58, 1.5f, 0.0f, 0.0f, 1.0f);
            _subaddiefade_entrypoint_1(sp44, (s32)(sp40 * 255.0f));
            func_808011D0_chfantasyeyeball(arg0, ((f32 *)arg0->actorData)[0], ((f32 *)arg0->actorData)[1], sp40);
            break;
        case 9:
        case 12:
            if (arg0->unk64_20) {
                func_800D90A4(&arg0->unk58);
                func_800D90A4(&((f32 *)arg0->actorData)[5]);
                if (!arg0->unk64_19) {
                    func_80801314_chfantasyeyeball(arg0);
                    func_800FC6B0(0x18);
                    func_800FFA88(arg0->unk0);
                    return;
                }
                func_808011D0_chfantasyeyeball(arg0, ((f32 *)arg0->actorData)[2], ((f32 *)arg0->actorData)[4], func_800F10B4(arg0->unk58, 2.708f, 0.0f, 1.0f, 0.0f));
            } else if (func_800D90A4(&((f32 *)arg0->actorData)[5])) {
                func_800FFA88(arg0->unk0);
            }
            arg0->alpha = func_800F10B4(((f32 *)arg0->actorData)[5], 1.5f, 0.0f, 255.0f, 0.0f);
            break;
        default:
            break;
        }
        func_808013F8_chfantasyeyeball(arg0);
        func_8010C93C(arg0, arg0->position, 0.75f);
        if (arg0->unk70_10 != 9 && arg0->unk70_10 != 12 && arg0->unk64_20) {
            func_80801378_chfantasyeyeball(arg0);
        }
    }
}

s32 func_80800950_chfantasyeyeball(Actor *arg0, s32 arg1, Actor *arg2, Actor *arg3) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800C3F48(u32);
    void func_800C4140(s32, f32 *, s32);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800F78_chfantasyeyeball(Actor *, Actor *);
    s32 func_80800FEC_chfantasyeyeball(Actor *);
    void func_80801290_chfantasyeyeball(Actor *, s32, s32);
    f32 func_808016B4_chfantasyeyeball(BtIntPtr);
    Unk80132ED0 *marker;

    if (arg2) {}
    if (arg3) {}
    switch (arg1) {
    case 2:
        if (func_800DA298(0x6EC) == 0) {
            func_80801290_chfantasyeyeball(arg0, 0x40800000, 0);
        }
        if (func_800DA298(0x6D4) == 0) {
            func_800DA544(0x6D4);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x141A, 0xF, arg0->position, 0x22);
        }
        break;
    case 3:
        ((f32 *)arg0->actorData)[3] = func_808016B4_chfantasyeyeball((BtIntPtr)arg0);
        break;
    case 7:
    case 10:
        if (arg0->unk64_20 && func_800DA298(0x6D5) == 0) {
            func_800DA544(0x6D5);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x141B, 0xF, arg0->position, 0x22);
        }
        func_800C4140(0xB31B5DB8, arg0->position, 0x1B5801F4);
        if (arg0->unk64_20) {
            func_80800FEC_chfantasyeyeball(arg0);
            func_80801290_chfantasyeyeball(arg0, 0x402D4FDF, 0);
        }
        break;
    case 8:
    case 11:
        func_800C3F48(0x4CBB5CEE);
        break;
    case 6:
        func_800C3F48(0x4CBB5CED);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_80801290_chfantasyeyeball(arg0, 0x3FC00000, 1);
        break;
    case 9:
    case 12:
        if (arg0->unk64_20) {
            marker = ((Unk80132ED0 **)arg0->actorData)[7];
            if (marker != NULL) {
                func_80800F78_chfantasyeyeball(arg0, func_80106790(marker));
            } else if (func_800DA298(0x6BD) == 0) {
                func_800DA544(0x6BD);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x141C, 0xF, arg0->position, 0x22);
            }
        }
        arg0->unk64_19 = 0;
        ((f32 *)arg0->actorData)[5] = 1.5f;
        break;
    }
    func_80102424(arg0, arg1); BT_NATIVE_ONLY(return 0;)
}

s32 func_80800B68_chfantasyeyeball(Actor *arg0, s32 arg1, s32 arg2 BT_PASS2(, s32 bt_a3)) {
    typedef struct {
        u8 actorFields[0x74];
        BT_BITFIELD_ORDER(u32 pad74_6 : 26, u32 pad74_0 : 5);
        u32 unk74_5 : 1;
        BT_BITFIELD_ORDER(u32 pad74_0 : 5, u32 pad74_6 : 26);
        BT_BITFIELD_ORDER(u32 pad78_3 : 29, char : 0);
        BT_BITFIELD_ORDER(u32 unk78_2 : 1, u32 pad78_0 : 2);
        BT_BITFIELD_ORDER(u32 pad78_0 : 2, u32 unk78_2 : 1; u32 pad78_3 : 29);
    } FantasyEyeballFlags;
    void _chskeletonexplode_entrypoint_3(Actor *, s32, s32);
    void _chskeletonexplode_entrypoint_4(Actor *, s32);
    void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
    void _subaddielink_entrypoint_1(u8 *arg0, u8 *arg1);
    s32 _subaddielink_entrypoint_3(u8 *);
    void func_800C4140(s32, f32 *, s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D0B68(u32, u32);
    BtIntPtr func_800D10D4(u32, u32, f32 *, s32, BtIntPtr);
    void func_800DF744(s32, s32);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800FC6B0(u32);
    void *func_80100094(Actor *, u32);
    void func_80101074(void *);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010D12C(BtIntPtr, f32 *, f32, s32);
    s32 func_80800950_chfantasyeyeball();
    void func_80801740_chfantasyeyeball(Actor *, f32 *);
    extern u8 D_80801E98_chfantasyeyeball[];
    Actor *sp54;
    Actor *sp50;
    f32 sp48[2];
    f32 sp3C[3];
    f32 distance;
    f32 sp2C[3];
    Actor *sp28;

    switch (arg1) {
        case 0x3F:
            switch (arg0->unk70_10) {
                case 1:
                case 2:
                case 4:
                case 6:
#ifdef BT_NATIVE
                    ((s32 (*)())func_80800950_chfantasyeyeball)(arg0, 7);
#else
                    func_80800950_chfantasyeyeball(arg0, 7);
#endif
                    break;
                case 3:
                case 5:
#ifdef BT_NATIVE
                    ((s32 (*)())func_80800950_chfantasyeyeball)(arg0, 10);
#else
                    func_80800950_chfantasyeyeball(arg0, 10);
#endif
                    break;
            }
            if (func_800D0B68(0x4C, 1) == 0) {
                func_800FC6B0(0xE);
            }
            return 1;
        case 0x40:
            if (((f32 *)arg0->actorData)[6] <= 0.0f && !((FantasyEyeballFlags *)arg0)->unk78_2) {
                func_800C4140(0x3FEFA49D, arg0->position, 0x04B000FA);
            }
            ((f32 *)arg0->actorData)[6] = 2.0f;
            return 1;
        case 0x38:
            func_80101074(D_80801E98_chfantasyeyeball);
            return 7;
        case 0x3D:
            switch (arg2) {
                case 0:
                    if (func_800D0B68(0x4C, 1) == 0 && func_800D0A9C(0x4C, 1) == 0) {
                        sp54 = func_80106790(func_800D10D4(0x4C, 1, arg0->position, 3, 0));
                        _subaddielink_entrypoint_1(func_80100094(arg0, 0), sp54->unk0);
                        ((FantasyEyeballFlags *)sp54)->unk74_5 = 0;
                        func_8010A570(sp54);
                    }
                    return 1;
                case 1:
                    func_80801740_chfantasyeyeball(arg0, sp3C);
                    sp50 = func_80108528(0x483, sp3C, 0, &arg0);
                    func_800F5A00(func_800F54E4(), sp3C);
                    sp3C[1] += 40.0f;
                    sp50->unk58 = func_800EEAD4(sp50->position, sp3C) / 1200.0f;
                    func_8010D12C(func_800F54E4(), sp3C, sp50->unk58, 0);
                    distance = func_800EEAD4(sp50->position, sp3C);
                    sp50->unk58 = distance / 1200.0f;
                    ((f32 *)sp50->actorData)[7] = func_800F10B4(distance, 500.0f, 5000.0f, 100.0f, 600.0f);
                    func_800F18FC(sp50->position, sp3C, sp48);
                    func_800EEBF0((f32 *)&sp50->actorData[4], sp48, 1200.0f);
                    return 1;
                case 2:
                    func_80801740_chfantasyeyeball(arg0, sp2C);
                    sp28 = func_80108528(0x483, sp2C, 0, &arg0);
                    sp28->scale = 3.0f;
                    _chskeletonexplode_entrypoint_7(sp28, sp28->position);
                    return 1;
            }
            return 0;
        case 0xF:
            sp28 = func_80106790(func_80101080());
            _chskeletonexplode_entrypoint_3(sp28, 3, 2);
            _chskeletonexplode_entrypoint_4(sp28, 6);
            return 1;
        case 0x1F:
            func_801015D0(arg0);
            func_800DF744(3, 1);
            return 1;
        case 0x2E:
            if (*(s16 *)&arg2 == 0x141A || *(s16 *)&arg2 == 0x141B || *(s16 *)&arg2 == 0x141C) {
                arg0->unk64_19 = 0;
            }
            return 1;
        case 0x95:
            if (_subaddielink_entrypoint_3(func_80100094(arg0, 0)) == 0 && func_800D0B68(0x4C, 1) == 0 && arg0->unk64_20) {
                func_80108B04(arg0, 0);
            }
            return 1;
    }
    return 0;
}

/* extern */

void func_80800F78_chfantasyeyeball(Actor *arg0, Actor *arg1) {
    void* func_80100094(Actor*, u32);
    void _subaddielink_entrypoint_5(void *arg0, void *arg1);
    s32 func_80800950_chfantasyeyeball(Actor *, s32, Actor *, Actor *);
    void *sp18[2];

    arg0->unk64_20 = 0;
    arg1->unk64_20 = 1;
    func_80800950_chfantasyeyeball(arg1, 6, arg1, arg0);
    sp18[0] = func_80100094(arg0, 0U);
    _subaddielink_entrypoint_5(sp18[0], func_80100094(arg1, 0U));
}

s32 func_80800FEC_chfantasyeyeball(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    u8 *actors[15];
    s32 count;
    s32 index;
    s32 minimum;
    s32 best;
    s32 value;
    Actor *actor;

    count = _subaddiefind_entrypoint_4(0x482, actors, 15);
    best = -1;
    minimum = 255;
    index = 0;
    if (count > 0) {
        do {
            actor = (Actor *)actors[index];
            if ((s32)actor->unk70_10 < 7 && arg0 != actor) {
                value = actor->unk74_7;
                if (value < minimum) {
                    best = index;
                    minimum = value;
                }
            }
            index++;
        } while (index < count);
    }
    if (best == -1) {
        arg0->actorData[7] = 0;
        return 0;
    }
    arg0->actorData[7] = (BtUIntPtr)((Actor *)actors[best])->unk0;
    return 1;
}

/* extern */

void func_808010B0_chfantasyeyeball(Actor *arg0, f32 *arg1, f32 *arg2) {
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    f32 func_800DC0C0(void);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp64[3];
    f32 temp_f20;
    f32 sp54[3];

    temp_f20 = func_800DC0C0() * 360.0f;
    *arg1 = (func_800DC0C0() * 20.0f) + 20;
    *arg2 = temp_f20;
    for (; *arg2 < temp_f20 + 360.0f; *arg2 += 30.0f) {
        func_800EEC30(sp54, *arg1, *arg2, 2500.0f);
        func_800EF04C(sp54, arg0->position);
        if (func_800BEF00(arg0->position, sp54, sp64, 0) == 0) {
            break;
        }
    }
}

/* extern */

void func_808011D0_chfantasyeyeball(Actor *arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800A516C(f32 *, f32 *, f32 *);
    void func_800E39D8(BtIntPtr, BtIntPtr);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_800EEC30(sp30, arg1, arg2, (500.0f * arg3) + 2000.0f);
    func_800EF04C(sp30, arg0->position);
    func_800EFA4C(sp24, arg0->position[0], arg0->position[1] + arg0->scale * 224.0f, arg0->position[2]);
    func_800A516C(sp3C, sp24, sp30);
    func_800E39D8(sp30, sp3C);
}

void func_80801290_chfantasyeyeball(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void func_800A50B0(s32 arg0);
    u32 func_800F54E4(void);
    void func_800F7B9C(BtIntPtr arg0,u32 a1);
    void func_800F82D4(BtIntPtr arg0,s32 arg1);

    _subaddieDll_entrypoint_4(arg0, 1);
    arg0->unk58 = 2.708f;
    arg0->unk64_19 = 1;
    if (arg2 == 0) {
        func_800F7B9C(func_800F54E4(), 0x6B);
        func_800A50B0(1);
        func_800F82D4(func_800F54E4(), 2);
    }
}

/* extern */

void func_80801314_chfantasyeyeball(void *arg0) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void func_800A50B0(s32 arg0);
    u32 func_800F54E4(void);
    void func_800F7B9C(BtIntPtr arg0,u32 a1);
    void func_800F82D4(BtIntPtr arg0,s32 arg1);
    func_800F82D4(func_800F54E4(), 0);
    _subaddieDll_entrypoint_4(arg0, 0);
    func_800F7B9C(func_800F54E4(), 0x6C);
    func_800A50B0(2);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFF7);
}

/* extern */

void func_80801378_chfantasyeyeball(Actor *arg0) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_800D0B68(u32, u32);
    void *func_80100094(Actor *, u32);
    void func_8010C964(u8 *);
    void func_80801740_chfantasyeyeball(Actor *, f32 *);
    void *sp1C;
    Actor *temp_v0;

    if ((func_800D0B68(0x4C, 1) == 0) && arg0->unk7C_12) {
        temp_v0 = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
        if (temp_v0 != NULL) {
            sp1C = temp_v0;
            func_80801740_chfantasyeyeball(arg0, temp_v0->position);
            temp_v0 = sp1C;
            temp_v0->position[1] -= 48.0f;
            func_8010C964(sp1C);
        }
    }
}

void func_808013F8_chfantasyeyeball(Actor *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    void func_800E0ACC(void *);
    void func_800E0AF0(void *, f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void func_800E0B8C(void *, u8, f32, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    BtIntPtr func_8010262C(Unk80132ED0 *, u32);
    void func_80801740_chfantasyeyeball(Actor *, f32 *);
    BtIntPtr sp6C;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp4C[2];
    f32 sp48;
    f32 sp44;

    sp6C = func_8010262C(arg0->unk0, 3);
    if (sp6C != 0) {
        sp48 = func_800D8FF8();
        if ((s32)arg0->unk70_10 < 7) {
            func_800F5A00(func_800F54E4(), sp54);
            func_80801740_chfantasyeyeball(arg0, sp60);
            func_800F18FC(sp60, sp54, sp4C);
            if (sp4C[0] < 310.0f && sp4C[0] > 180.0f) {
                sp4C[0] = 320.0f;
            }
            if (arg0->unk70_10 == 1 || arg0->unk70_10 == 4) {
                sp4C[0] = func_800136E4(80.0f - sp4C[0]);
            } else {
                sp4C[0] = func_800136E4(45.0f - sp4C[0]);
            }
            sp4C[1] = func_800136E4(sp4C[1] - arg0->rotation[1]);
            arg0->unk54 = func_800F1FF0(arg0->unk54, sp4C[1], 0.75f, 2.0f * sp48, 90.0f * sp48);
            arg0->unk50 = func_800F1FF0(arg0->unk50, sp4C[0], 0.75f, 2.0f * sp48, 90.0f * sp48);
            func_800E0ACC((void *)sp6C);
            func_800E0AF0((void *)sp6C, 1.0f);
            func_800E0AFC((void *)sp6C, 0x2C, -1.0f, arg0->unk50, 0.0f, 0.0f);
            func_800E0AFC((void *)sp6C, 1, -1.0f, 0.0f, arg0->unk54, 0.0f);
            if (func_800D90A4(&((f32 *)arg0->actorData)[6]) == 0) {
                sp44 = func_800F10B4(((f32 *)arg0->actorData)[6], 2.0f, 0.0f, 1.0f, 0.0f);
                func_800E0B8C((void *)sp6C, 1, -1.0f,
                    func_80013970(1800.0f * sp44) * 0.25f * sp44 + 1.0f,
                    func_80013970(2520.0f * sp44) * 0.25f * sp44 + 1.0f,
                    func_80013970(1080.0f * sp44) * 0.25f * sp44 + 1.0f);
            }
        }
    }
}

f32 func_808016B4_chfantasyeyeball(BtIntPtr arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    u8 *found[10];
    s32 count;
    s32 i;

    count = 0;
    for (i = _subaddiefind_entrypoint_4(0x482, found, 10) - 1; i >= 0; i--) {
        if ((s32)((Actor *)found[i])->unk70_10 < 7) {
            count++;
        }
    }
    return (f32)count * 0.5f;
}

/* extern */

void func_80801740_chfantasyeyeball(Actor *arg0, f32 *arg1) {
    void _subaddieskeleton_entrypoint_1(Actor *, s32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    if (arg0->unk7C_12) {
        _subaddieskeleton_entrypoint_1(arg0, 4, arg1);
    } else {
        func_800EE7F8(arg1, arg0->position);
        arg1[1] += arg0->scale * 224.0f;
    }
}

/* extern */

#ifdef BT_NATIVE
s32 func_808017B4_chfantasyeyeball(s32 bt_a0) {
#else
s32 func_808017B4_chfantasyeyeball(void) {
#endif
    s32 func_8010C754();
    s32 func_8010D248();
    f32 temp_f0;

    temp_f0 = (f32) func_8010C754();
    if ((temp_f0 > 5000.0f) || (temp_f0 < 500.0f)) {
        return 0;
    }
    return func_8010D248();
}

OSThread *chfantasyeyeball_entrypoint_0(void)
{
    extern ActorData D_80801F28_chfantasyeyeball[];

    return (OSThread *) D_80801F28_chfantasyeyeball;
}

void func_8080182C_chfantasyeyeball(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_80013970(f32);
    BtIntPtr func_800B53A4(s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 *func_800BF340(f32[3], f32[3], f32[3], s32, f32);
    f32 func_800D8FF8(void);
    int func_800D91EC(f32 *, f32);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF174(f32[3], f32[3], f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFDE8(f32 *, u8 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80801BC4_chfantasyeyeball(Actor *, f32 *);
    extern s32 D_80801F70_chfantasyeyeball[];
    extern u32 D_80801FB0_chfantasyeyeball[];
    typedef struct {
    f32 position[3];
    f32 timer;
    f32 velocity[3];
    f32 amplitude;

    }
    EyeballData;
    f32 sp4C[3];
    f32 sp40[3];
    BtIntPtr sp3C;
    if (func_800D91EC(&((EyeballData *)arg0->actorData)->timer, 5.0f)) {
    func_80801BC4_chfantasyeyeball(arg0, NULL);
    return;

    }
    func_800EE7F8(sp4C, arg0->position);
    if (((EyeballData *)arg0->actorData)->timer <= arg0->unk58) {
    func_800EF174(((EyeballData *)arg0->actorData)->position, ((EyeballData *)arg0->actorData)->velocity, func_800D8FF8());
    func_800EFA4C(arg0->position, ((EyeballData *)arg0->actorData)->position[0], ((EyeballData *)arg0->actorData)->position[1] + (func_80013970(func_800F10B4(((EyeballData *)arg0->actorData)->timer, 0.0f, arg0->unk58, 0.0f, 180.0f)) * ((EyeballData *)arg0->actorData)->amplitude), ((EyeballData *)arg0->actorData)->position[2]);

    }
    else {
    ((EyeballData *)arg0->actorData)->velocity[1] += -2000.0f * func_800D8FF8();
    func_800EF174(arg0->position, ((EyeballData *)arg0->actorData)->velocity, func_800D8FF8());

    }
    if (func_800BF340(sp4C, arg0->position, sp40, 0x20020, arg0->scale * 33.0f)) {
    func_800EFB24(((EyeballData *)arg0->actorData)->position, arg0->position, sp4C);
    func_800EFDE8(((EyeballData *)arg0->actorData)->position, (u8 *)((EyeballData *)arg0->actorData)->position, sp40);
    func_800EFB24(((EyeballData *)arg0->actorData)->position, arg0->position, ((EyeballData *)arg0->actorData)->position);
    func_80801BC4_chfantasyeyeball(arg0, ((EyeballData *)arg0->actorData)->position);
    return;

    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80801FB0_chfantasyeyeball);
    sp3C = func_800B53A4(1);
    func_800BA3FC(sp3C, func_800DC128(0, 9) + 0x9DF);
    func_800BABB8(sp3C, arg0->position, NULL, 1.0f, D_80801F70_chfantasyeyeball);
    arg0->rotation[0] += arg0->unk50 * func_800D8FF8();
    arg0->rotation[1] += arg0->unk54 * func_800D8FF8();
    }

s32 func_80801A50_chfantasyeyeball(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2) {
    void _chskeletonexplode_entrypoint_3(Actor *, s32, s32);
    void _chskeletonexplode_entrypoint_4(Actor *, s32);
    f32 func_800DC178(f32, f32);
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80801BC4_chfantasyeyeball(Actor *, f32 *);
    f32 sp2C[3];
    Actor *sp28;

    switch (arg1) {
    case 0x3E:
        func_800F5A00(func_800F54E4(), sp2C);
        func_80801BC4_chfantasyeyeball(arg0, sp2C);
        return 1;
    case 0x3F:
        if (((u16 *)&(*(Unk80132ED0 **)&arg2)->unk18)[0] & 1) {
            func_80801BC4_chfantasyeyeball(arg0, func_80106790(*(Unk80132ED0 **)&arg2)->position);
            return 1;
        }
        func_80801BC4_chfantasyeyeball(arg0, NULL);
        return 1;
    case 0xF:
        sp28 = func_80106790(func_80101080());
        _chskeletonexplode_entrypoint_3(sp28, 3, 2);
        _chskeletonexplode_entrypoint_4(sp28, 6);
        func_800FFA88(arg0->unk0);
        return 1;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 1);
        return 1;
    case 0x95:
        arg0->unk54 = func_800DC178(180.0f, 360.0f);
        arg0->unk50 = func_800DC178(180.0f, 360.0f);
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        ((f32 *)arg0->actorData)[3] = 0.0f;
        return 1;
    default:
        return 0;
    }
}

void func_80801BC4_chfantasyeyeball(Actor *arg0, f32 *arg1) {
    void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4140(s32, f32 *, s32);
    extern s32 D_80801FC0_chfantasyeyeball[18];
    BtIntPtr temp_v0;
    f32 *var_a2;
    s32 var_s0;

    for (var_s0 = 0; var_s0 < 8; var_s0++) {
        var_a2 = arg1 != NULL ? arg1 : arg0->position;
        temp_v0 = func_800BABB8(0, arg0->position, var_a2, 1.0f, D_80801FC0_chfantasyeyeball);
        func_800BA3FC(temp_v0, var_s0 + 0x9DF);
        func_800BA22C(temp_v0, 3);
    }
    if (arg1 != NULL) {
        var_a2 = arg1;
    } else {
        var_a2 = arg0->position;
    }
    _chskeletonexplode_entrypoint_7(arg0, var_a2);
    func_800C4140(0x7FFF441F, arg0->position, 0x04B000FA);
}

OSThread *chfantasyeyeball_entrypoint_1(void)
{
    extern ActorData D_80802008_chfantasyeyeball[];

    return (OSThread *) D_80802008_chfantasyeyeball;
}
/* data_to_c.py: from asm/data/overlays/ch/fantasy/eyeball.data.s */
extern u8 D_80801E30_chfantasyeyeball[];
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
u8 D_80801E30_chfantasyeyeball[104] BT_DATA(4, overlays_ch_fantasy_eyeball, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x5C, 0x28, 0xF6, 0x03, 0x93, 0x00, 0x49, 0x3F, 0x88, 0x93, 0x75, 0x03, 0x96, 0x00, 0x4A, 0x3F, 0x5C, 0x28, 0xF6, 0x03, 0x97, 0x00, 0x49, 0x3F, 0x66, 0x66, 0x66, 0x03, 0x9A, 0x00, 0x4A, 0x3F, 0x66, 0x66, 0x66, 0x03, 0x98, 0x00, 0x4A, 0x3F, 0x5C, 0x28, 0xF6, 0x03, 0x93, 0x00, 0x4A, 0x3F, 0x9A, 0x9F, 0xBE, 0x03, 0x95, 0x00, 0x4A, 0x3F, 0x9A, 0x9F, 0xBE, 0x03, 0x95, 0x00, 0x86, 0x3F, 0x9A, 0x9F, 0xBE, 0x03, 0x95, 0x00, 0x86, 0x3F, 0x9A, 0x9F, 0xBE, 0x03, 0x99, 0x00, 0x4A, 0x3F, 0x9A, 0x9F, 0xBE, 0x03, 0x99, 0x00, 0x86, 0x3F, 0x9A, 0x9F, 0xBE, 0x03, 0x99, 0x00, 0x86 };
u8 D_80801E98_chfantasyeyeball [84] BT_DATA(4, overlays_ch_fantasy_eyeball, 0x68) = { 0, 0, 0, 0x2B, 0x40, 0, 0, 0, 1, 0x12, 0, 0, 0, 0, 0, 0x12, 0x40, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0x2C, 0x40, 0x73, 0x33, 0x33, 0, 0x2A, 0, 0, 0, 0, 0, 0x50, 0x40, 0, 0, 0, 2, 0x52, 0, 0, 0, 0, 0, 0x55, 0x40, 0, 0, 0, 2, 0x57, 0, 0, 0, 0, 0, 0x4B, 0x40, 0, 0, 0, 2, 0x4D, 0, 0, 0, 0, 0, 0x46, 0x40, 0, 0, 0, 2, 0x48, 0, 0 };
s32 D_80801EEC_chfantasyeyeball [15] BT_DATA(4, overlays_ch_fantasy_eyeball, 0xBC) = { 1447302, 917554, 6553645, 26215000, 1834208, -39321564, 4194380, 1376256, 12582955, 16777728, 2555904, -26214400, 26214449, -3211364, 52035584 };
ActorData D_80801F28_chfantasyeyeball [1] BT_DATA(4, overlays_ch_fantasy_eyeball, 0xF8) = { { 271, 1154, 2195, 1, (void *)D_80801E30_chfantasyeyeball, (void (*)(struct Actor *))func_808000D8_chfantasyeyeball, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 458752000, 0, 0, 0, 130, 608, 0, (BtIntPtr)func_80108ED0, 8, 0, (void (*)(struct Actor *))func_80800000_chfantasyeyeball, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31742, 28676, (void (*)(struct Actor *, long, long))func_80800B68_chfantasyeyeball, 0 } };
s32 D_80801F70_chfantasyeyeball [16] BT_DATA(4, overlays_ch_fantasy_eyeball, 0x140) = { 1834408, -32767978, 268435470, 1966110, 2359360, 4980757, 192, 2818124, 4980775, 65136, 400, 3080268, 2490368, 38, 40, 18481152 };
u32 D_80801FB0_chfantasyeyeball [4] BT_DATA(4, overlays_ch_fantasy_eyeball, 0x180) = { 0x13065C, 0x1661A8, 0xA0100, 0 };
s32 D_80801FC0_chfantasyeyeball[18] BT_DATA(4, overlays_ch_fantasy_eyeball, 0x190) = { 51380246, 361103374, 1966110, 2949520, 39321627, -52363864, 2359360, 4980757, 192, 2818176, 16777255, 65136, 400, 3080268, 2490368, 38, 40, 0 };
ActorData D_80802008_chfantasyeyeball [1] BT_DATA(4, overlays_ch_fantasy_eyeball, 0x1D8) = { { 272, 1155, 2196, 1, 0, (void (*)(struct Actor *))func_8080182C_chfantasyeyeball, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 128, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32736, 0, (void (*)(struct Actor *, long, long))func_80801A50_chfantasyeyeball, 0 } };
