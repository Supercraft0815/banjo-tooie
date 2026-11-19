#include "su/coasterfly.h"

OSThread *sucoasterfly_entrypoint_0(void)
{
    extern BtFnWord D_80802280_sucoasterfly[5];

    return (OSThread *) D_80802280_sucoasterfly;
}

s32 sucoasterfly_entrypoint_1(Actor *arg0, s32 arg1) {
    u32 *func_80100074(Actor *, u32, u32);
    s32 _sucoasterflydata_entrypoint_0(Actor *);
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    s32 func_80801FE4_sucoasterfly(Actor *, f32 *, f32, f32);
    struct CoasterFlyData {
        f32 position[3];
        f32 unkC;
        u8 unk10;
        BT_BITFIELD_ORDER(u8 variant : 4, u8 flags : 4);
        BT_BITFIELD_ORDER(u8 flags : 4, u8 variant : 4);
        s16 unk12;
        s32 unk14;
        s16 height;
        s16 unk1A;
    } *data;
    f32 groundY;

    data = (struct CoasterFlyData *)func_80100074(arg0, 0, arg1 + 0x1C);
    data->variant = _sucoasterflydata_entrypoint_0(arg0);
    _subaddierouteDll_entrypoint_3(arg0, data, arg0->position);
    data->unkC = 0.0f;
    groundY = arg0->position[1] - 400.0f;
    func_80801FE4_sucoasterfly(arg0, &groundY, 50.0f, -1500.0f);
    data->height = (s32)(arg0->position[1] - groundY);
    return 1;
}

void sucoasterfly_entrypoint_2(Actor* arg0)
{
    func_80802128_sucoasterfly(arg0);
}

void sucoasterfly_entrypoint_3(Actor *arg0) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddiefade_entrypoint_3(Actor *);
    f32 _subaddiejoy_entrypoint_3();
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    int func_800DC298(f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800EEFFC(void *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFCD8(f32 *, f32, f32);
    s32 func_800F0008(f32 *, f32, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    int func_800F20BC(f32, f32, f32);
    u32 func_800F54E4(void);
    f32 func_800F5BF0(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101D7C(Actor *);
    s32 func_80101DDC(Actor *);
    int func_801021BC(Actor *, s32);
    void func_80102BF8(Actor *, f32, f32, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_80102D98(Actor *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5);
    s32 func_80107070(Actor *, s32);
    s32 func_801072A8(Actor *);
    s32 func_801072E4(Actor *);
    f32 func_80107C00(void);
    s32 func_8010B990(Actor *, s32);
    f32 func_8010CD28(Actor *);
    void func_8010D690(Actor *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    void func_8080181C_sucoasterfly(Actor *);
    void func_808019A0_sucoasterfly(Actor *);
    void func_80801A80_sucoasterfly(BtIntPtr);
    s32 func_80801AB0_sucoasterfly(Actor *);
    s32 func_80801B90_sucoasterfly(Actor *);
    void func_80801C44_sucoasterfly(Actor *, s32);
    s32 func_80801DD0_sucoasterfly(Actor *);
    void func_8080215C_sucoasterfly(Actor *);
    struct CoasterFlyData {
        union {
            f32 position[3];
            u16 route[6];
        } path;
        f32 unkC;
        u8 unk10;
        BT_BITFIELD_ORDER(u8 variant : 4, u8 flags : 3);
        u8 returning : 1;
        BT_BITFIELD_ORDER(u8 flags : 3, u8 variant : 4);
        s16 origin[3];
        s16 height;
        s16 unk1A;
    } *data;
    f32 oldYaw;
    f32 delta;
    f32 unused[3];
    f32 joy;
    f32 routeHeading;
    f32 routeDistance;
    f32 player[3];
    f32 radius;
    f32 difference;
    f32 direction[3];
    u32 flags;
    s32 collision;
    s32 collisionResult2;
    s32 collision2;
    f32 home[3];
    f32 step;
    f32 homeDistance;
    f32 route[3];
    f32 destination[3];
    f32 step2;
    f32 fallDelta;
    f32 bank;

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    flags = arg0->pad7A_0;
    if (((s32)(flags << 29) >> 31) == 0) {
        func_800D9078(&arg0->unk58);
        oldYaw = arg0->rotation[1];
        if (func_80100094(arg0, 1) != NULL) {
            _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
        }
        switch (arg0->unk70_10) {
        case 1:
            func_80801C44_sucoasterfly(arg0, 0);
            if (arg0->unk64_29) {
                if (_subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3) > 0.2f) {
                    func_808014AC_sucoasterfly(arg0, 3);
                }
                func_80801DD0_sucoasterfly(arg0);
            } else {
                if (!func_80801AB0_sucoasterfly(arg0) && arg0->unk58 <= 0.0f && func_800DC298(0.02f)) {
                    func_808014AC_sucoasterfly(arg0, 3);
                }
                func_80102D98(arg0, 0x3F, 0, 0.3f, 20.0f, 40.0f);
            }
            func_80102BF8(arg0, 0.1f, 4.0f, 150.0f);
            func_808019A0_sucoasterfly(arg0);
            break;
        case 2:
            func_80801C44_sucoasterfly(arg0, 0);
            func_80102BF8(arg0, 0.1f, 4.0f, 150.0f);
            if (func_80102CF4(arg0, 0x40C00000)) {
                func_808014AC_sucoasterfly(arg0, 3);
            }
            break;
        case 3:
            func_80801C44_sucoasterfly(arg0, 0);
            if (arg0->unk64_29) {
                joy = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
                func_80102BF8(arg0, 0.1f, 4.0f, 150.0f);
                if (joy == 0.0f) {
                    func_808014AC_sucoasterfly(arg0, 1);
                }
                func_80801DD0_sucoasterfly(arg0);
            } else {
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    _subaddierouteDll_entrypoint_7(arg0, data, arg0->rotation[1], arg0->unk54, func_80107C00() * 300.0f, 0x4802);
                    data->unk10 = data->path.route[3];
                }
                if (!func_80801AB0_sucoasterfly(arg0) && arg0->unk58 <= 0.0f && func_800DC298(0.02f)) {
                    func_808014AC_sucoasterfly(arg0, 1);
                }
                _subaddierouteDll_entrypoint_5(arg0, data, data->unk10, 0.1f, 4.0f, 150.0f);
            }
            func_808019A0_sucoasterfly(arg0);
            break;
        case 4:
            func_80801C44_sucoasterfly(arg0, 0);
            if (_subaddierouteDll_entrypoint_4(arg0)) {
                arg0->unk54 = func_8010CD28(arg0);
                _subaddierouteDll_entrypoint_7(arg0, data, arg0->rotation[1], arg0->unk54, func_80107C00() * 300.0f, 0x4802);
                data->unk10 = data->path.route[3];
            }
            _subaddierouteDll_entrypoint_5(arg0, data, data->unk10, 0.1f, 4.0f, 180.0f);
            func_808019A0_sucoasterfly(arg0);
            if (arg0->unk64_29) {
                func_808014AC_sucoasterfly(arg0, 1);
            } else if (!func_80801B90_sucoasterfly(arg0) && func_80102CF4(arg0, 0x41A00000)) {
                if (func_801021BC(arg0, 5)) {
                    func_808014AC_sucoasterfly(arg0, 5);
                } else {
                    func_808014AC_sucoasterfly(arg0, 6);
                }
            }
            break;
        case 5:
            func_80801C44_sucoasterfly(arg0, 1);
            if (_subaddierouteDll_entrypoint_4(arg0)) {
                arg0->unk54 = func_8010CD28(arg0);
                _subaddierouteDll_entrypoint_7(arg0, data, arg0->rotation[1], arg0->unk54, func_80107C00() * 300.0f, 0x4802);
                data->unk10 = data->path.route[3];
            }
            _subaddierouteDll_entrypoint_5(arg0, data, data->unk10, 0.1f, 4.0f, 180.0f);
            func_808019A0_sucoasterfly(arg0);
            if (!func_80801B90_sucoasterfly(arg0) && func_80101DDC(arg0)) {
                func_808014AC_sucoasterfly(arg0, 6);
            }
            break;
        case 6:
            radius = func_800F5BF0(func_800F54E4(), player);
            func_80801C44_sucoasterfly(arg0, 0);
            if (!func_800F0008(arg0->position, 300.0f, player, radius)) {
                func_80801A80_sucoasterfly((BtIntPtr)arg0);
            }
            if (arg0->unk64_29) {
                if (_subaddiejoy_entrypoint_3(arg0) > 0.0f) {
                    difference = func_800F1DCC(arg0->unk54, arg0->rotation[1]);
                    if (difference < -30.0f) {
                        arg0->unk54 = arg0->rotation[1] - 30.0f;
                    } else if (difference > 30.0f) {
                        arg0->unk54 = arg0->rotation[1] + 30.0f;
                    }
                }
            } else {
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
            }
            func_80102BF8(arg0, 0.1f, 4.0f, 180.0f);
            if (!func_80801B90_sucoasterfly(arg0)) {
                collision = arg0->unk64_29 ? 0x604027 : 0x600307;
                func_8080181C_sucoasterfly(arg0);
                func_800EFB24(direction, arg0->actorData, arg0->position);
                func_800EF368(direction, ((f32 *)arg0->actorData)[3]);
                func_800EFCD8((f32 *)&arg0->actorData[4], arg0->rotation[1], func_800EEFFC(direction));
                ((f32 *)arg0->actorData)[5] = direction[1];
                if (func_8010B990(arg0, collision) & 0x24) {
                    func_808014AC_sucoasterfly(arg0, 8);
                } else if (!func_800F20BC(arg0->rotation[1], func_80102D78(arg0, (f32 *)arg0->actorData), 100.0f)) {
                    func_808014AC_sucoasterfly(arg0, 7);
                }
            }
            break;
        case 7:
            collision2 = arg0->unk64_29 ? 0x604027 : 0x600307;
            func_80801C44_sucoasterfly(arg0, 0);
            func_80102BF8(arg0, 0.1f, 4.0f, 150.0f);
            func_8080181C_sucoasterfly(arg0);
            if (((f32 *)arg0->actorData)[3] > 30.0f) {
                func_800EF368((f32 *)&arg0->actorData[4], ((f32 *)arg0->actorData)[3]);
                if ((func_8010B990(arg0, collision2) & 0x24) || ((f32 *)arg0->actorData)[3] == 0.0f) {
                    func_808014AC_sucoasterfly(arg0, 8);
                }
            } else if (arg0->unk64_24) {
                func_808014AC_sucoasterfly(arg0, 3);
            } else {
                func_808014AC_sucoasterfly(arg0, 8);
            }
            break;
        case 8:
            step = func_800D8FF8() * (10.0f * data->unkC);
            func_80801C44_sucoasterfly(arg0, 0);
            if (_subaddierouteDll_entrypoint_4(arg0)) {
                func_800EE88C(route, data->origin);
                arg0->unk54 = func_80102D78(arg0, route);
                _subaddierouteDll_entrypoint_7(arg0, data, arg0->rotation[1], arg0->unk54, func_80107C00() * 300.0f, 0x4802);
                data->unk10 = data->path.route[3];
            }
            _subaddierouteDll_entrypoint_5(arg0, data, data->unk10, 0.1f, 4.0f, 150.0f);
            func_808019A0_sucoasterfly(arg0);
            func_800EE88C(home, data->origin);
            if (func_80102CF4(arg0, 0x40C00000) || func_800EEB40(arg0->position, home) < step * step) {
                func_808014AC_sucoasterfly(arg0, 9);
            }
            break;
        case 9:
            step2 = func_800D8FF8() * (10.0f * data->unkC);
            func_80801C44_sucoasterfly(arg0, 0);
            func_80102BF8(arg0, 0.1f, 4.0f, 150.0f);
            func_800EE88C(destination, data->origin);
            if (func_800EEB40(arg0->position, destination) < step2 * step2) {
                arg0->unk64_24 = 1;
                func_808014AC_sucoasterfly(arg0, 3);
            } else {
                func_8080181C_sucoasterfly(arg0);
                func_800EFB24(&arg0->actorData[4], destination, arg0->position);
                func_800EF368((f32 *)&arg0->actorData[4], ((f32 *)arg0->actorData)[3]);
                func_8010B990(arg0, 0x4027);
            }
            break;
        case 10:
            func_8080215C_sucoasterfly(arg0);
            func_80801C44_sucoasterfly(arg0, 2);
            if (func_80101DDC(arg0)) {
                if (data->returning) {
                    func_808014AC_sucoasterfly(arg0, 8);
                } else {
                    func_808014AC_sucoasterfly(arg0, 3);
                }
                func_80101D7C(arg0);
            }
            break;
        case 11:
            fallDelta = func_800D8FF8();
            func_8080215C_sucoasterfly(arg0);
            ((f32 *)arg0->actorData)[7] += fallDelta * -9800.0f;
            ((f32 *)arg0->actorData)[5] += fallDelta * ((f32 *)arg0->actorData)[7];
            if (((f32 *)arg0->actorData)[5] < -1500.0f) {
                ((f32 *)arg0->actorData)[5] = -1500.0f;
            }
            if (func_8010B990(arg0, 0x204007) & 0x28) {
                func_808014AC_sucoasterfly(arg0, 12);
            }
            break;
        case 12:
            func_8080215C_sucoasterfly(arg0);
            func_80801C44_sucoasterfly(arg0, 3);
            if (func_80101DDC(arg0)) {
                _subaddieDll_entrypoint_4(arg0, 0);
                if (!func_80107070(arg0, 2)) {
                    func_808014AC_sucoasterfly(arg0, 13);
                    _subaddiefade_entrypoint_3(arg0);
                }
            }
            break;
        case 13:
        case 14:
        case 15:
        case 16:
            func_8080215C_sucoasterfly(arg0);
            break;
        }
        bank = func_800F10B4(func_800F1DCC(oldYaw, arg0->rotation[1]) * (1.0f / delta), -60.0f, 60.0f, -12.0f, 12.0f);
        arg0->rotation[2] = func_800F1FF0(arg0->rotation[2], bank, 0.1f, 4.0f * delta, 120.0f * delta);
        if (!func_801072A8(arg0) || func_801072E4(arg0)) {
            func_8010D690(arg0);
        }
    }
}

s32 sucoasterfly_entrypoint_4(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddiefade_entrypoint_3(Actor *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void *_sucoasterflydata_entrypoint_2(u32, s32 *);
    void _suexpression_entrypoint_13(void *, f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101010(f32 *);
    void func_80101074(void *);
    s32 func_80107070(Actor *, s32);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    void func_80802080_sucoasterfly(Actor *);
    struct CoasterFlyActorFlags {
        u8 unused[0x74];
        BT_BITFIELD_ORDER(u32 other : 28, u32 mode : 4);
        BT_BITFIELD_ORDER(u32 mode : 4, u32 other : 28);
    };
    struct CoasterFlyData {
        f32 position[3];
        f32 unkC;
        u8 unk10;
        BT_BITFIELD_ORDER(u8 variant : 4, u8 flags : 4);
        BT_BITFIELD_ORDER(u8 flags : 4, u8 variant : 4);
        s16 unk12;
        s32 unk14;
        s16 height;
        s16 unk1A;
    };
    f32 position[3];
    s32 result;

    switch (arg1) {
    case 1:
        func_808014AC_sucoasterfly(arg0, 1);
        break;
    case 2:
        if (arg0->unk70_10 != 11 && !_subaddieDll_entrypoint_3(arg0) && !func_80107070(arg0, 1)) {
            _subaddiefade_entrypoint_3(arg0);
            func_808014AC_sucoasterfly(arg0, 15);
            arg0->unk64_24 = 0;
        }
        break;
    case 0x8F:
        if (arg2 == 0) {
            arg0->unk64_25 = 1;
            ((struct CoasterFlyActorFlags *)arg0)->mode = 1;
            func_808014AC_sucoasterfly(arg0, 3);
        }
        break;
    case 0x29:
        func_80802080_sucoasterfly(arg0);
        break;
    case 0x2A:
        func_80802128_sucoasterfly(arg0);
        break;
    case 0x4D:
        _subaddieDll_entrypoint_4(arg0, 0);
        if (!func_80107070(arg0, 3)) {
            return 0;
        }
        break;
    case 0x94:
        if (func_80100094(arg0, 1) == NULL) {
            return 0;
        }
        position[2] = 0.0f;
        _suexpression_entrypoint_13(func_80100094(arg0, 1), &position[1], &position[0]);
        func_80101010(position);
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    case 0x38:
        func_80101074(_sucoasterflydata_entrypoint_2(((struct CoasterFlyData *)func_80100094(arg0, 0))->variant, &result));
        return result;
    default:
        return 0;
    }
    return 1;
}

void func_80800EF0_sucoasterfly(Unk80132ED0 *arg0, u8 *arg1)
{
  Actor *func_80106790(Unk80132ED0 *);
  s32 func_808014AC_sucoasterfly(Actor *, s32);
  Actor *temp_a0;
  Actor *temp_v0;
  temp_v0 = func_80106790(arg0);
  temp_a0 = temp_v0;
  if (((((u32) ((((Unk80132ED0 *)arg1)->unk24) ^ 0)) >> 0x16) == 0) && (((((u16) (*((u16 *) (((s8 *) temp_v0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 6))
  {
    func_808014AC_sucoasterfly(temp_a0, 7);
  }
}

/* extern */

void func_80800F44_sucoasterfly(Unk80132ED0 *arg0, BtIntPtr arg1) {
    int func_801021BC(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    Actor *temp_v0;
    Actor *sp1C;
    u32 flags;

    temp_v0 = func_80106790(arg0);
    if (temp_v0->unk70_10 != 0xA) {
        flags = temp_v0->pad7A_0;
        if (((s32)(flags << 29) >> 31) == 0) {
        sp1C = temp_v0;
        if (func_801021BC(temp_v0, 0xA) != 0) {
            func_808014AC_sucoasterfly(sp1C, 0xA);
        }
        }
    }
}

void func_80800FA8_sucoasterfly(Unk80132ED0 *arg0, Unk80132ED0 *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    s32 _sueggmisc_entrypoint_0();
    void _suegg_entrypoint_19(Actor *, f32 *);
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F5D70(BtIntPtr, f32 *);
    Actor *actor;
    f32 velocity[3];
    f32 position[4];

    actor = func_80106790(arg0);
    if (_sueggmisc_entrypoint_0(arg1) != 0) {
        _suegg_entrypoint_19(func_80106790(arg1), velocity);
        func_800EF334(velocity, 1.0f / func_800D8FF8());
        if (func_800EEF94(velocity) > 400.0f) {
            func_800EF368(velocity, 400.0f);
        }
    } else if ((arg1->unk24 >> 22) == 0) {
        func_800F5D70((u32)((u16 *)&arg1->unk18)[1] >> 5, velocity);
        if (func_800EEFD4(velocity) < 100.0f) {
            func_800F5A00((u32)((u16 *)&arg1->unk18)[1] >> 5, position);
            func_800EFB24(velocity, actor->position, position);
            func_800EF368(velocity, 200.0f);
            velocity[1] += 150.0f;
        }
    } else {
        func_800EFD24(velocity);
    }
    func_808014AC_sucoasterfly(actor, 0xB);
    func_800EF04C(&((f32 *)actor->actorData)[4], velocity);
}

void func_80801108_sucoasterfly(Unk80132ED0 *arg0, Unk80132ED0 *arg1, s32 arg2) {
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    void _chflamer_entrypoint_1(void *, void *);
    void _chfreezy_entrypoint_1(void *, s16 *);
    s32 _glhittableDll_entrypoint_10(s32);
    s32 _glhittableDll_entrypoint_6(s32);
    s32 _glhittableDll_entrypoint_8(s32);
    s32 _glhittableDll_entrypoint_9(s32);
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    void func_800EB860(s32 (*filter)(s16 *, uintptr_t), uintptr_t data);
    void func_800EB874(void);
    void func_800EC370(void **, void *);
    f32 func_800EC708(Unk80132ED0 *);
    s32 func_800F0E28(s32, s32);
    u32 func_800F54E4(void);
    f32 func_800F5F24(BtUIntPtr);
    s32 func_800F6C1C(s32);
    s32 func_800F70EC(s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80109600(void *, void *);
    s32 func_8010A430(void *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    void func_80800EF0_sucoasterfly(Unk80132ED0 *arg0, u8 *arg1);
    void func_80800F44_sucoasterfly(Unk80132ED0 *arg0, BtIntPtr arg1);
    void func_80800FA8_sucoasterfly(Unk80132ED0 *arg0, Unk80132ED0 *arg1);
    extern s16 D_80802294_sucoasterfly[11];
    extern Actor *_chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw);
    s32 func_80108EF4(void *, s32);
    Actor *sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 var_v1;
    f32 height;
    u32 temp_t8;
    s16 sp38[3];
    f32 sp34;
    f32 sp30;

    sp5C = func_80106790(arg0);
    sp58 = _glhittableDll_entrypoint_10(arg2);
    sp54 = _glhittableDll_entrypoint_9(arg2);
    sp50 = _glhittableDll_entrypoint_6(arg2);
    var_v1 = (arg1->unk24 >> 22) == 0;
    if (!var_v1 || ((temp_t8 = (u32)((u16 *)&arg1->unk18)[1] >> 5, func_800F70EC(temp_t8)) && func_800F6C1C(temp_t8)) || !_glhittableDll_entrypoint_8(arg2)) {
        if (sp50 == 0) {
            if (!sp54 && (arg1->unk24 >> 22)) {
                return;
            }
            if (sp54 <= 0) {
                sp54 = 1;
            }
        }
        (&sp5C->pad5C)[sp50] = func_800F0E28(0, (&sp5C->pad5C)[sp50] - 100 / sp54);
        sp4C = sp50 == 2 && (&sp5C->pad5C)[sp50] == 0;
        if (sp54) {
            switch (sp50) {
                case 2:
                    func_80109600(sp5C, arg1);
                    switch (arg1->unk24 >> 22) {
                        case 0x26D:
                            _chflamer_entrypoint_1(sp5C, arg1);
                            break;
                    }
                    break;
                case 1:
                    func_80109600(sp5C, arg1);
                    switch (arg1->unk24 >> 22) {
                        case 0x26E:
                            func_800EC370(arg1, sp38);
                            _chfreezy_entrypoint_1(sp5C, sp38);
                            break;
                    }
                    break;
            }
        }
        if ((&sp5C->pad5C)[sp50] == 0 || sp50 != 0) {
            if ((&sp5C->pad5C)[sp50] != 0) {
                sp50--;
            }
            if (sp50 != 2) {
                (&sp5C->pad5C)[sp50] = 99;
            }
            if (sp50 == 2 && sp58 && func_8010A430(sp5C)) {
                sp34 = func_800F5F24(func_800F54E4());
                func_800EB860(&func_80108EF4, sp5C);
                sp30 = sp5C->position[1] + (height = func_800EC708(arg0));
                _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, sp58 + 2, *(s32 *)&sp5C->position[0], *(s32 *)&sp30, *(s32 *)&sp5C->position[2], *(s32 *)&sp34);
                func_800EB874();
            }
            switch (sp50) {
                case 0:
                    func_80800EF0_sucoasterfly(sp5C->unk0, arg1);
                    break;
                case 1:
                    func_80800F44_sucoasterfly(sp5C->unk0, arg1);
                    break;
                case 2:
                    func_80800FA8_sucoasterfly(sp5C->unk0, arg1);
                    break;
            }
        }
        if (sp4C) {
            func_8010D930(1, sp5C->unk70_0, sp5C->position, (s32 *)D_80802294_sucoasterfly);
            _subaddiejoy_entrypoint_10(sp5C, 1.0f, 0.25f);
        }
    }
}

s32 func_808014AC_sucoasterfly(Actor *arg0, s32 arg1) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void *_sucoasterflydata_entrypoint_1(u32);
    s32 _sucoasterflydata_entrypoint_3(u32);
    s32 _sucoasterflydata_entrypoint_4(u32);
    s32 _sucoasterflydata_entrypoint_5(u32);
    s32 func_800DC128(s32, s32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE940(s16 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    f32 func_80102D78(Actor *, f32 *);
    f32 func_80107C00(void);
    void func_8010A570(Actor *);
    f32 func_8010CD28(Actor *);
    void func_80801A80_sucoasterfly(BtIntPtr);
    void func_80801CD0_sucoasterfly(Actor *, s32);
    extern s16 D_808022AC_sucoasterfly[8];
    struct CoasterFlyData {
        f32 position[3];
        f32 speed;
        u8 unk10;
        BT_BITFIELD_ORDER(u8 type : 4, u8 rest : 3);
        u8 active : 1;
        BT_BITFIELD_ORDER(u8 rest : 3, u8 type : 4);
        s16 destination[3];
    };
    struct CoasterFlyParameters {
        u8 pad0[0x24];
        s16 speed1;
        s16 speed3;
    };
    struct CoasterFlyFlags {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u32 b7 : 1, u32 pad64 : 30);
        u32 b6 : 1;
        BT_BITFIELD_ORDER(u32 pad64 : 30, u32 b7 : 1);
        u32 pad68[2];
        BT_BITFIELD_ORDER(u32 top : 1, u32 low : 4);
        BT_BITFIELD_ORDER(u32 flags : 6, u32 mode : 6);
        BT_BITFIELD_ORDER(u32 pad70 : 9, u32 state : 6);
        BT_BITFIELD_ORDER(u32 state : 6, u32 pad70 : 9);
        BT_BITFIELD_ORDER(u32 mode : 6, u32 flags : 6);
        BT_BITFIELD_ORDER(u32 low : 4, u32 top : 1);
        BT_BITFIELD_ORDER(u32 pad74 : 28, char : 0);
        BT_BITFIELD_ORDER(u32 type : 4, u32 type : 4; u32 pad74 : 28);
    };
    struct CoasterFlyData *temp_v0;
    struct CoasterFlyParameters *sp48;
    u32 sp44;
    f32 sp38[3];
    s32 temp_s0;
    f32 temp_f0;
    f32 sp2C;
    f32 sp28;


    temp_v0 = func_80100094(arg0, 0);
    sp48 = _sucoasterflydata_entrypoint_1(temp_v0->type);
    sp44 = arg0->unk70_10;
    func_80102424(arg0, arg1);
    switch (arg1) {
    case 1:
        arg0->unk58 = sp48->speed1;
        temp_v0->speed = 0.0f;
        break;
    case 2:
        temp_v0->speed = 0.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        break;
    case 3:
        arg0->unk58 = sp48->speed3;
        sp2C = func_80107C00();
        temp_s0 = _sucoasterflydata_entrypoint_3(temp_v0->type);
        temp_v0->speed = func_800DC128(temp_s0, _sucoasterflydata_entrypoint_4(temp_v0->type)) * sp2C;
        break;
    case 4:
        arg0->unk54 = func_8010CD28(arg0);
        sp2C = func_80107C00();
        temp_v0->speed = _sucoasterflydata_entrypoint_3(temp_v0->type) * sp2C;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        break;
    case 5:
        func_800EE940(temp_v0->destination, arg0->position);
        break;
    case 6:
        if (sp44 != 5) {
            func_800EE940(temp_v0->destination, arg0->position);
        }
        func_80801A80_sucoasterfly((BtIntPtr)arg0);
        arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
        temp_v0->active = 1;
        sp28 = func_80107C00();
        temp_f0 = _sucoasterflydata_entrypoint_5(temp_v0->type) * sp28;
        temp_v0->speed = temp_f0;
        ((f32 *)arg0->actorData)[3] = temp_f0;
        break;
    case 7:
        temp_v0->speed = 0.0f;
        break;
    case 8:
        func_800EE88C(sp38, temp_v0->destination);
        arg0->unk54 = func_80102D78(arg0, sp38);
        temp_v0->active = 0;
        sp2C = func_80107C00();
        temp_v0->speed = _sucoasterflydata_entrypoint_3(temp_v0->type) * sp2C;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        break;
    case 9:
        sp2C = func_80107C00();
        temp_v0->speed = _sucoasterflydata_entrypoint_4(temp_v0->type) * (sp2C * 1.2f);
        break;
    case 11:
        ((f32 *)arg0->actorData)[7] = 0.0f;
        _subaddieDll_entrypoint_4(arg0, 1);
        arg0->unk64_25 = 0;
        arg0->unk64_24 = 0;
        ((struct CoasterFlyFlags *)arg0)->mode = 0;
        arg0->unk70_25 = ((struct CoasterFlyFlags *)arg0)->mode;
        ((struct CoasterFlyFlags *)arg0)->b6 = 0;
        ((struct CoasterFlyFlags *)arg0)->b7 = ((struct CoasterFlyFlags *)arg0)->b6;
        arg0->unk14 &= ~0x80000;
        ((struct CoasterFlyFlags *)arg0)->type = 2;
        func_8010A570(arg0);
        func_80801CD0_sucoasterfly(arg0, 2);
        break;
    case 12:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808022AC_sucoasterfly);
        break;
    }
    BT_NATIVE_ONLY(return 0;) }

void *func_80100094(Actor *, u32);

void func_8080181C_sucoasterfly(Actor *arg0) {
    f32 func_800F0E00(f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_80107C00(void);
    f32 *sp1C;
    volatile f32 sp18;
    f32 speed;
    f32 current;
    f32 initial;

    sp1C = func_80100094(arg0, 0);
    initial = sp1C[3];
    current = ((f32 *)arg0->actorData)[3];
    if (initial < current) {
        speed = func_800F0E00(current, 10.0f);
    } else {
        speed = initial;
    }
    sp18 = speed * 0.1f;
    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], sp1C[3], func_80107C00() * sp18);
}

void func_808018BC_sucoasterfly(Actor *arg0) {
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    f32 func_800F0E00(f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_80107C00(void);
    struct CoasterFlyActorFlags {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u32 pad64 : 2, u32 remaining64 : 29);
        u32 disabled : 1;
        BT_BITFIELD_ORDER(u32 remaining64 : 29, u32 pad64 : 2);
    };
    f32 *sp2C;
    volatile f32 sp28;
    f32 scale;
    f32 speed;
    f32 current;
    f32 initial;

    sp2C = func_80100094(arg0, 0);
    if (((struct CoasterFlyActorFlags *)arg0)->disabled) {
        scale = _subaddiejoy_entrypoint_9(arg0, NULL, 0);
    } else {
        scale = 1.0f;
    }
    initial = sp2C[3];
    current = ((f32 *)arg0->actorData)[3];
    if (initial < current) {
        speed = func_800F0E00(current, 10.0f);
    } else {
        speed = initial;
    }
    sp28 = speed * 0.1f;
    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], sp2C[3] * scale, func_80107C00() * sp28);
}

/* extern */

void func_808019A0_sucoasterfly(Actor *arg0) {
    void func_800EEB9C(f32[3], f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    void func_80102924(void *, f32);
    s32 func_8010B990(Actor *, s32);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    void func_808018BC_sucoasterfly(Actor *);
    f32 func_80801E5C_sucoasterfly();
    f32 sp24;
    s32 sp20;

    sp24 = func_80801E5C_sucoasterfly();
    sp20 = (arg0->unk64_29) ? 0x404027 : 0x504327;
    func_808018BC_sucoasterfly(arg0);
    func_800EEB9C(&((f32 *)arg0->actorData)[4], arg0->rotation[1], ((f32 *)arg0->actorData)[3]);
    ((f32 *)arg0->actorData)[5] = func_800F0D50(sp24 - arg0->position[1], -300.0f, 300.0f);
    if ((func_8010B990(arg0, sp20) & 0x24) && !(arg0->unk64_29)) {
        func_80102924(arg0, arg0->rotation[1] + 180.0f);
        func_808014AC_sucoasterfly(arg0, 2);
    }
}

/* extern */

void func_80801A80_sucoasterfly(BtIntPtr arg0) {
    u32 func_800F54E4(void);
    f32 func_800F5BF0(BtIntPtr, f32 *);
    func_800F5BF0(func_800F54E4(), (f32 *)(arg0 + 0x18));
}

/* extern */

s32 func_80801AB0_sucoasterfly(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_801072A8(Actor *);
    s32 func_8010C500(Actor *);
    s32 func_8010C9B0(f32 *, s32);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    union {
        u32 word;
        struct {
            BT_BITFIELD_ORDER(u32 pad : 28, u32 rest : 3);
            u32 blocked : 1;
            BT_BITFIELD_ORDER(u32 rest : 3, u32 pad : 28);
        } bits;
    } state;
    union {
        u32 word;
        struct {
            BT_BITFIELD_ORDER(u32 unused : 1, u32 rest : 29);
            BT_BITFIELD_ORDER(u32 enabled : 1, u32 active : 1);
            BT_BITFIELD_ORDER(u32 active : 1, u32 enabled : 1);
            BT_BITFIELD_ORDER(u32 rest : 29, u32 unused : 1);
        } bits;
    } flags;

    flags.word = *(u32 *)((u8 *)arg0 + 0x64);

    if (!flags.bits.enabled) {
        return 0;
    }
    if (flags.bits.active) {
        return 1;
    }
    if ((func_801072A8(arg0) != 0) ||
        (state.word = arg0->pad7A_0, state.bits.blocked)) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9B0(arg0->position, 0x578) == 0) {
        return 0;
    }
    if (func_8010C500(arg0) == 0) {
        return 0;
    }
    if (_suchase_entrypoint_1(arg0) == 0) {
        return 0;
    }
    func_808014AC_sucoasterfly(arg0, 4);
    return 1;
}

/* extern */

s32 func_80801B90_sucoasterfly(Actor *arg0) {
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_8010C500(Actor *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    struct CoasterFlyActorFlags {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u32 pad64 : 2, u32 remaining64 : 29);
        u32 disabled : 1;
        BT_BITFIELD_ORDER(u32 remaining64 : 29, u32 pad64 : 2);
    };
    s32 var_v1 = 0;
    struct {
        u32 unk0[4];
        BT_BITFIELD_ORDER(u32 pad10 : 12, u32 unk10_0 : 19);
        u32 unk10_19 : 1;
        BT_BITFIELD_ORDER(u32 unk10_0 : 19, u32 pad10 : 12);
    } *data;

    if (((struct CoasterFlyActorFlags *)arg0)->disabled) {
        return 0;
    }
    if (func_8010C500(arg0) == 0) {
        var_v1 = 1;
    }
    if (var_v1 == 0) {
        if (_suchase_entrypoint_1(arg0) == 0) {
            var_v1 += 1;
        }
    }
    if (var_v1 != 0) {
        data = func_80100094(arg0, 0U);
        func_808014AC_sucoasterfly(arg0, data->unk10_19 ? 7 : 1);
    }
    return var_v1;
}

void func_80801C44_sucoasterfly(Actor *arg0, s32 arg1) {
    void *_sucoasterflydata_entrypoint_1(u32);
    s32 func_80101E14(Actor *, f32);
    void func_80801CD0_sucoasterfly(Actor *, s32);
    struct CoasterFlyData {
        u8 pad0[0x11];
        u8 track;
    } *data;
    struct CoasterFlyParameters {
        s16 pad0[2];
        struct {
            s16 enabled;
            s16 pad2[2];
            s16 fraction;
        } entries[1];
    } *parameters;

    data = func_80100094(arg0, 0U);
    parameters = _sucoasterflydata_entrypoint_1((u32)data->track >> 4);
    if (parameters->entries[arg1].enabled != 0 &&
        func_80101E14(arg0, (f32)parameters->entries[arg1].fraction * 0.00390625f) != 0) {
        func_80801CD0_sucoasterfly(arg0, arg1);
    }
}

void func_80801CD0_sucoasterfly(Actor *arg0, s32 arg1) {
    void *_sucoasterflydata_entrypoint_1(u32);
    void func_8010D640(f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern s16 D_808022BC_sucoasterfly[7];
    struct CoasterFlyData {
        u8 pad0[0x11];
        u8 track;
    };
    struct SoundParameters {
        s16 id;
        s16 volume;
        s16 pitch;
        s16 pad;
    };
    f32 pitch;
    u8 *sp38;
    struct CoasterFlyData *data;
    f32 sp28[3];

    data = func_80100094(arg0, 0U);
    sp38 = _sucoasterflydata_entrypoint_1((u32)data->track >> 4);
    if (((struct SoundParameters *)(sp38 + 4))[arg1].id != 0) {
        func_8010D640(sp28);
        if (!(func_800EEB40(sp28, arg0->position) >= 9000000.0f)) {
            pitch = func_800DC178(-0.05f, 0.05f);
            pitch += (f32)((struct SoundParameters *)(sp38 + 4))[arg1].pitch * 0.00390625f;
            func_800C4B64(pitch);
            func_800C4B7C(((struct SoundParameters *)(sp38 + 4))[arg1].id);
            func_800C4B70(((struct SoundParameters *)(sp38 + 4))[arg1].volume);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808022BC_sucoasterfly);
        }
    }
}

s32 func_80801DD0_sucoasterfly(Actor *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    int func_800F20BC(f32, f32, f32);
    int func_801021BC(Actor *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);

    if (func_800F20BC(arg0->rotation[1], func_8010CD28(arg0), 20.0f) != 0 &&
        _subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1) {
        if (func_801021BC(arg0, 5) != 0) {
            func_808014AC_sucoasterfly(arg0, 5);
            return 1;
        }
        func_808014AC_sucoasterfly(arg0, 6);
        return 1;
    }
    return 0;
}

f32 func_80801E5C_sucoasterfly(Actor *arg0) {
    void func_8008FE94(s32, f32 *);
    s32 func_800CC338(f32 *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    int func_80104544();
    f32 func_8010473C(Actor *, f32 *);
    s32 func_80801FE4_sucoasterfly(Actor *, f32 *, f32, f32);
    struct CoasterFlyActorFlags {
        u8 pad0[0x70];
        BT_BITFIELD_ORDER(u32 section : 7, u32 pad74 : 4);
        BT_BITFIELD_ORDER(u32 pad70 : 15, u32 track : 6);
        BT_BITFIELD_ORDER(u32 track : 6, u32 pad70 : 15);
        BT_BITFIELD_ORDER(u32 pad74 : 4, u32 section : 7);
    };
    struct CoasterFlyData {
        f32 position[3];
        f32 unkC;
        u8 unk10;
        BT_BITFIELD_ORDER(u8 variant : 4, u8 flags : 4);
        BT_BITFIELD_ORDER(u8 flags : 4, u8 variant : 4);
        s16 unk12;
        s32 unk14;
        s16 height;
        s16 unk1A;
    } *data;
    f32 position[3];
    f32 height;
    f32 ground;

    data = func_80100094(arg0, 0);
    if (arg0->unk64_29) {
        func_8008FE94(5, position);
        return position[1] + 100.0f;
    }
    if (func_80104544(arg0)) {
        height = func_8010473C(arg0, NULL) + (f32)data->height;
        func_800EE7F8(position, arg0->position);
        position[1] = height;
        if (func_800CC338(position, arg0->unk70_25 - 1, ((struct CoasterFlyActorFlags *)arg0)->track - 1) != -1) {
            return height;
        }
    } else if (func_80801FE4_sucoasterfly(arg0, &ground, 50.0f, -((f32)data->height + 400.0f))) {
        func_800EE7F8(position, arg0->position);
        position[1] = (f32)data->height + ground;
        if (func_800CC338(position, arg0->unk70_25 - 1, ((struct CoasterFlyActorFlags *)arg0)->track - 1) != -1) {
            return (f32)data->height + ground;
        }
    }
    return arg0->position[1];
}

s32 func_80801FE4_sucoasterfly(Actor *arg0, f32 *arg1, f32 arg2, f32 arg3) {
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg0->position);
    func_800EE7F8(sp28, arg0->position);
    sp34[1] += arg2;
    sp28[1] += arg3;
    if (func_800BEF00(sp34, sp28, sp1C, arg0->unk14) != 0) {
        *arg1 = sp28[1];
        return 1;
    }
    return 0;
}

/* extern */

void func_80802080_sucoasterfly(Actor *arg0) {
    typedef struct {
        u8 pad0[0x11];
        u8 track;
    } CoasterFlyData;
    typedef struct {
        u8 pad0[2];
        union {
            s16 id;
            u8 bytes[2];
        } expression;
    } TrackData;
    void *_sucoasterflydata_entrypoint_1(u32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _suexpression_entrypoint_1(u8);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BT_IDO_ONLY(BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);) BT_NATIVE_ONLY(void *_suexpression_entrypoint_7(Actor *, s32, s16);)
    s32 pad;
    TrackData *sp20;

    sp20 = _sucoasterflydata_entrypoint_1((u32)((CoasterFlyData *)func_80100094(arg0, 0U))->track >> 4);
    if ((func_80100094(arg0, 1U) == NULL) && (_suexpression_entrypoint_1(sp20->expression.bytes[1]) != 0)) {
        _suexpression_entrypoint_7(arg0, 1, sp20->expression.id);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42480000, 0x42200000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x7D0);
    }
}

void func_80802128_sucoasterfly(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_8080215C_sucoasterfly(Actor *arg0) {
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
    }
}

u8 *sucoasterfly_entrypoint_5(Actor *arg0) {
    return (u8 *)func_80100094(arg0, 0U) + 0x1C;
}
void sucoasterfly_entrypoint_6(BT_NATIVE_ONLY(s32 bt_a0) BT_PASS2(, s32 bt_a1))
{
    func_80101870(BT_PASS2(bt_a0, bt_a1));
}
#include "fly_data.inc"
