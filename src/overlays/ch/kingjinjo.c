#include "common.h"

OSThread *chkingjinjo_entrypoint_0(void)
{
    extern ActorData D_808011A8_chkingjinjo[];

    return (OSThread *) D_808011A8_chkingjinjo;
}

OSThread *chkingjinjo_entrypoint_1(void)
{
    extern ActorData D_808011F0_chkingjinjo[];

    return (OSThread *) D_808011F0_chkingjinjo;
}

void func_80800018_chkingjinjo(Actor *arg0) {
    s32 _glcutDll_entrypoint_20(void);
    void _subaddieDll_entrypoint_1(Actor *arg0);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_80104E78(Actor *);
    void func_8010A590(Actor *);
    typedef union {
        Actor actor;
        struct {
            u32 padding[29];
            u32 pad74_31 : 11;
            u32 visible : 1;
            u32 pad74_18 : 20;
            u32 pad78_31 : 30;
            u32 enabled : 1;
            u32 pad78_0 : 1;
        } flags;
    } KingJinjoActor;
    f32 *sp44;
    f32 sp2C[6];

    sp44 = func_80100094(arg0, 0);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 0xB);
        ((KingJinjoActor *)arg0)->flags.visible = 0;
        return;
    }
    if (func_800DA298(0x360) != 0) {
        _subaddiemarker_entrypoint_1(arg0, 0x154, 0x32, sp2C, 1);
        func_800EE7F8(arg0->position, sp2C);
        arg0->rotation[1] = func_800DC178(0.0f, 360.0f);
        _subaddieDll_entrypoint_1(arg0);
        _subaddierouteDll_entrypoint_3(arg0, sp44, arg0->position);
        func_80102424(arg0, 6);
        func_8010A590(arg0);
        func_80104E78(arg0);
        ((KingJinjoActor *)arg0)->flags.visible = 1;
        arg0->unk58 = func_800DC178(8.0f, 12.0f);
        sp44[3] = func_800DC178(4.0f, 6.0f);
        ((KingJinjoActor *)arg0)->flags.enabled = 1;
        return;
    }
    if (func_800DA298(0x3B) != 0) {
        if (func_800DA298(0x43) == 0) {
            func_800FFAB0(arg0);
            return;
        }
        func_80102424(arg0, 9);
        ((KingJinjoActor *)arg0)->flags.visible = 0;
        return;
    }
    ((KingJinjoActor *)arg0)->flags.visible = 0;
}

void func_80800194_chkingjinjo(Actor *arg0) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    u32 *_suexpression_entrypoint_20(Actor *);
    s32 func_800C0638(void);
    void func_800C3CE8(u8);
    int func_800C3D78(u8);
    u8 func_800C4350(u8, f32 *, s32 *);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    s32 func_800F4EC8(BtUIntPtr, BtIntPtr, f32, f32, f32);
    BtIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    void func_80102424(Actor *, s32);
    void func_80102BF8(Actor *, f32, f32, f32);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010C500(Actor *);
    s32 func_8010C9B0(f32 *, s32);
    s32 func_8010CAC0(f32 *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_8010CD88(Actor *, f32, f32);
    s32 func_8010D248(void);
    void func_80800AE4_chkingjinjo(BtIntPtr, s32 *);
    extern s32 D_80801238_chkingjinjo[];
    extern s32 D_80801254_chkingjinjo[];
    extern s32 D_80801264_chkingjinjo[];
    extern s32 D_80801274_chkingjinjo[];
    extern s32 D_80801284_chkingjinjo[];
    typedef struct {
        u16 unk0[3];
        u16 sound;
        f32 unk8;
        f32 timer;
    } KingJinjoRoute;
    typedef struct {
        f32 unk0[3];
        f32 speed;
    } KingJinjoData;
    KingJinjoRoute *route;
    f32 position[3];
    s32 pad;

    route = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
    case 3:
        func_80800AE4_chkingjinjo((BtIntPtr)arg0, D_80801238_chkingjinjo);
        break;
    case 5:
        if (func_800D9078(&arg0->unk58)) {
            func_800F5A00(func_800F54E4(), position);
            position[1] += 200.0f;
            func_800D1000(0x5A, 1, position, 1, NULL);
            func_80102424(arg0, 4);
        }
        break;
    case 6:
        if (func_800D9078(&route->timer)) {
            if (arg0->unk5F == 0) {
                arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
            }
            arg0->unk5F = func_800C4350(arg0->unk5F, arg0->position, D_80801254_chkingjinjo);
            route->timer = func_800DC178(4.0f, 6.0f);
        }
        if (!func_800C0638() && func_8010CAC0(arg0->position, 1000) && func_800D90A4(&arg0->unk58)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, func_800DC128(0, 6) + 0x152F, 0x44, arg0->position, 0xA5);
            arg0->unk58 = func_800DC178(8.0f, 12.0f);
        }
        if (func_8010D248() && func_8010C500(arg0)) {
            arg0->unk54 = func_8010CD28(arg0);
        }
        ((KingJinjoData *)arg0->actorData)->speed = arg0->scale * 60.0f;
        _subaddierouteDll_entrypoint_7(arg0, route, arg0->rotation[1], arg0->unk54, 400.0f, 0x4000);
        _subaddierouteDll_entrypoint_6(arg0, route, route->sound, 0x7F, 0.2f, 20, 40);
        _subaddierouteDll_entrypoint_5(arg0, route, route->sound, 0.1f, 4.0f, 80.0f);
        func_8010B990(arg0, 0x1405);
        if (func_8010C9B0(arg0->position, 200) && func_8010CD88(arg0, 180.0f, 60.0f)) {
            func_80102424(arg0, 8);
        }
        break;
    case 7:
        if (func_80101E14(arg0, 0.3f)) {
            if (arg0->unk5F && func_800C3D78(arg0->unk5F)) {
                func_800C3CE8(arg0->unk5F);
            }
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801264_chkingjinjo);
        }
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 6);
        }
        break;
    case 8:
        if (func_8010D248() && func_8010C500(arg0)) {
            arg0->unk54 = func_8010CD28(arg0);
        }
        func_80102BF8(arg0, 0.1f, 4.0f, 80.0f);
        if (func_80101E14(arg0, 0.3f)) {
            if (arg0->unk5F && func_800C3D78(arg0->unk5F)) {
                func_800C3CE8(arg0->unk5F);
            }
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801274_chkingjinjo);
        }
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 6);
        }
        break;
    case 9:
        func_80800AE4_chkingjinjo((BtIntPtr)arg0, D_80801284_chkingjinjo);
        break;
    }
    if (func_800DA298(0x360)) {
        func_800F4EC8(func_800F54E4(), (BtIntPtr)arg0->position, arg0->scale * 300.0f, 0.0f, arg0->scale * 90.0f);
    } else if (func_801022E4(arg0) == 0x3A9 && func_80102320(arg0, 0.55f, 0.95f)) {
        _suexpression_entrypoint_18(_suexpression_entrypoint_20(arg0), 1);
    }
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
}

s32 func_80800634_chkingjinjo(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 _glcutDll_entrypoint_20(void);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s16);
    s32 func_800DA298(s32);
    s32 func_800DF744(s32, u32);
    void func_800F497C(BtIntPtr);
    void func_800F49A8(BtIntPtr, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    BtIntPtr func_800F54E4(void);
    s32 func_801015D0(Actor *);
    void func_80102424(Actor *, s32);
    void func_801032B0(void *, u16, u16);
    void func_808009FC_chkingjinjo(Actor *, s32, s16);
    void func_80800B28_chkingjinjo(Actor *);
    s32 func_80800BBC_chkingjinjo(void *, s32, s32);
    void func_80800C60_chkingjinjo(Actor *, s32, s32);
    void func_80800CFC_chkingjinjo(Actor *, s32, s32);
    void func_8010D5DC(void);
    BtIntPtr expression_id;
    Actor *found;
    s32 expression;
    s32 pad0[2];
    f32 sp50[3];
    BtIntPtr sp4C;
    s32 pad1[3];
    f32 sp34[3];
    BtIntPtr sp30;

    switch (arg1) {
    case 0x2E:
        func_808009FC_chkingjinjo(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x3F:
        if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) != 7) {
            func_80102424(arg0, 7);
        }
        break;
    case 0x52:
        func_80800B28_chkingjinjo(arg0);
        break;
    case 0x95:
        found = _subaddiefind_entrypoint_2(0x147, 0);
        if (found != NULL) {
            *(s32 *)((u8 *)arg0 + 0x3C) = *(s32 *)found;
        } else {
            *(s32 *)((u8 *)arg0 + 0x3C) = 0;
        }
        if (func_800DA298(0x360) != 0) {
            func_801032B0(arg0, 0x897, *(u16 *)(*(u8 **)arg0 + 0x16));
            _subaddierouteDll_entrypoint_1(arg0);
        } else {
            if (func_800DA298(0x1A5) == 0 && func_800DA298(0x3B) == 0 && _glcutDll_entrypoint_20() == 0) {
                sp4C = func_800F54E4();
                _subaddiemarker_entrypoint_1(arg0, 0x154, 0x33, sp50, 1);
                func_800F497C(sp4C);
                func_800F49A8(sp4C, 1);
                func_800F49D4(sp4C, &func_8010D5DC, *(s32 *)arg0);
                func_800F4A58(sp4C, sp50, 300.0f);
                func_80800CFC_chkingjinjo(arg0, 5, 0x20);
                func_80102424(arg0, 1);
            }
            func_801032B0(arg0, 0x896, *(u16 *)(*(u8 **)arg0 + 0x16));
        }
        if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) == 2) {
            sp30 = func_800F54E4();
            _subaddiemarker_entrypoint_1(arg0, 0x154, 0x34, sp34, 1);
            func_800F497C(sp30);
            func_800F49A8(sp30, 1);
            func_800F49D4(sp30, &func_8010D5DC, *(s32 *)arg0);
            func_800F4A58(sp30, sp34, 300.0f);
            func_80800CFC_chkingjinjo(arg0, 0x17, 0x2020);
        }
        expression = func_800DA298(0x360) != 0 ? 0xA5 : 0xAE;
        expression_id = _suexpression_entrypoint_7(arg0, 1, (s16)expression);
        _suexpression_entrypoint_12((void *)expression_id, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17((void *)expression_id, 0x5DC);
        break;
    case 0x57:
        return func_80800BBC_chkingjinjo(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    case 0xB:
        if (arg2 == 1) {
            func_80800C60_chkingjinjo(arg0, 3, 1);
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x1535, 6, &arg0->position[0], 0xAE);
            return 4;
        }
        return 3;
    case 0x32:
        switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
        case 1:
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x14FD, 0xE, &arg0->position[0], 0xAE);
            break;
        case 2:
            _gcgoto_entrypoint_1(0x142, 1);
            break;
        }
        break;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_808009D0_chkingjinjo(BtIntPtr arg0) {
    void _suexpression_entrypoint_8(void *arg0, s32 arg1);
    s32 func_80800C18_chkingjinjo();
    func_80800C18_chkingjinjo();
    _suexpression_entrypoint_8(arg0, 0x1);
}

void func_808009FC_chkingjinjo(Actor *arg0, s32 arg1, s16 arg2) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_80102424(Actor *, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 func_80800C18_chkingjinjo(void *);
    void func_80800CFC_chkingjinjo(Actor *, s32, s32);

    switch (arg1) {
    case 0x14FD:
        func_800DA544(0x1A5);
        func_80800CFC_chkingjinjo(arg0, 1, 0x30);
        func_80102424(arg0, 5);
        arg0->unk58 = 0.4f;
        break;
    case 0x1535:
        func_80800C18_chkingjinjo(arg0);
        func_80102424(arg0, 2);
        _glcutDll_entrypoint_6(0x143, 0x65);
        break;
    default:
        if (func_800DA298(0x360) == 0) {
            if (arg0->unk6C_0) {
                func_80800C18_chkingjinjo(arg0);
            }
            func_80102424(arg0, func_800DA298(0x3B) ? 9 : 3);
        }
        break;
    }
}

void func_80800AE4_chkingjinjo(BtIntPtr arg0, s32 *arg1) {
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *);
    void func_80800C60_chkingjinjo(Actor *, s32, s32);
    s32 temp_v0;

    temp_v0 = _subaddiedialog_entrypoint_7(arg0, arg0 + 4, arg1);
    if ((temp_v0 != 0) && (temp_v0 != 0x1208)) {
        func_80800C60_chkingjinjo((Actor *) arg0, 3, 0);
    }
}

void func_80800B28_chkingjinjo(Actor *arg0) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_801022E4(Actor *);
    extern u32 D_808012A0_chkingjinjo[4];
    extern u32 D_808012B0_chkingjinjo[4];
    f32 sp24[3];

    if (func_801022E4(arg0) == 0x3A9) {
        func_800EE7F8(sp24, arg0->position);
        func_800EF1B8(sp24, arg0->rotation[1], -50.0f);
        _gcdialogcamera_entrypoint_3(D_808012A0_chkingjinjo, arg0->scale);
        _gcdialogcamera_entrypoint_4(sp24);
        _gcdialogcamera_entrypoint_5(arg0->rotation);
        return;
    }
    _gcdialogcamera_entrypoint_3(D_808012B0_chkingjinjo, arg0->scale);
    _gcdialogcamera_entrypoint_4(arg0->position);
    _gcdialogcamera_entrypoint_5(arg0->rotation);
}

/* extern */

s32 func_80800BBC_chkingjinjo(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80800C60_chkingjinjo(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_80800C60_chkingjinjo(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

s32 func_80800C18_chkingjinjo(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    } BT_NATIVE_ONLY(return 0;)
}

void func_80800C60_chkingjinjo(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x17, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->unk6C_0 = 2;
            func_80800B28_chkingjinjo(arg0);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800CFC_chkingjinjo(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x17, arg2);
        case 2:
            arg0->unk6C_0 = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

/* extern */

void func_80800D80_chkingjinjo(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    if (_glcutDll_entrypoint_20() != 0) {
        arg0->unk64_19 = 1;
        arg0->unk6C_0 = 1;
        return;
    }
    if ((func_800DA298(0x3B) != 0) && (func_800DA298(0x43) == 0)) {
        arg0->unk6C_0 = 1;
        return;
    }
    if (func_800DA298(0x360) != 0) {
        func_80102424(arg0, 2);
        arg0->unk64_19 = 0;
        arg0->unk6C_0 = 2;
        return;
    }
    arg0->unk64_19 = 1;
    arg0->unk6C_0 = 1;
}

void func_80800E58_chkingjinjo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    void _sudeflect_entrypoint_2(f32 *, f32 *, s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern u32 D_808012C0_chkingjinjo[];
    extern u32 D_808012D0_chkingjinjo[];
    extern u32 D_808012DC_chkingjinjo[];
    extern u32 D_808012E8_chkingjinjo[];
    extern u32 D_808012F8_chkingjinjo[];
    extern u32 D_80801304_chkingjinjo[];
    f32 sp34[3];
    f32 sp28[3];
    f32 *position;

    if (arg0->unk70_10 == 1) {
        position = arg0->position;
        if (arg0->unk64_19) {
            _subaddieaudioquick_entrypoint_4(arg0, position, D_808012C0_chkingjinjo, D_808012E8_chkingjinjo);
            _subaddieaudioquick_entrypoint_4(arg0, position, D_808012D0_chkingjinjo, D_808012F8_chkingjinjo);
            _subaddieaudioquick_entrypoint_4(arg0, position, D_808012DC_chkingjinjo, D_80801304_chkingjinjo);
        }
    }
    position = arg0->position;
    func_800EFA4C(sp34, -280.0f, 0.0f, -250.0f);
    func_800EFA4C(sp28, 170.0f, 400.0f, 80.0f);
    func_800EF334(sp34, arg0->scale);
    func_800EF334(sp28, arg0->scale);
    func_800EF04C(sp34, position);
    func_800EF04C(sp28, position);
    _sudeflect_entrypoint_2(sp34, sp28, 10);
}

s32 func_80800F60_chkingjinjo(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}                 typedef struct { u8 pad0[0x64]; s32 unk64; u8 pad68[0x4]; s32 unk6C; } Objkingjinjo_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
/* extern */

void func_80800F74_chkingjinjo(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, u32);
    s32 func_80101870(void *, BtIntPtr);
    func_800DF744(3, (((Objkingjinjo_arg0 *)arg0)->unk6C) & 0x1FF);
    func_800DF744(4, (u32) ((((Objkingjinjo_arg0 *)arg0)->unk64) << 0xC) >> 0x1F);
    func_80101870(arg0, arg1);
}
/* data_to_c.py: from asm/data/overlays/ch/kingjinjo.data.s */
extern u8 D_80801130_chkingjinjo[];
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
extern u8 D_80801190_chkingjinjo[];
u8 D_80801130_chkingjinjo[96] BT_DATA(4, overlays_ch_kingjinjo, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01, 0x3F, 0xEA, 0x3D, 0x71, 0x03, 0xA6, 0x00, 0x01, 0x3F, 0x86, 0x66, 0x66, 0x03, 0xA8, 0x00, 0x02, 0x3F, 0xEA, 0x3D, 0x71, 0x03, 0xA7, 0x00, 0x02, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xA9, 0x00, 0x01 };
u8 D_80801190_chkingjinjo[24] BT_DATA(4, overlays_ch_kingjinjo, 0x60) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x44, 0xA3, 0xD7, 0x03, 0xAA, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
ActorData D_808011A8_chkingjinjo [1] BT_DATA(4, overlays_ch_kingjinjo, 0x78) = { { 59, 1080, 2198, 3, (void *)D_80801130_chkingjinjo, (void (*)(struct Actor *))func_80800194_chkingjinjo, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 1073741824, 0, 0, 901, 1312, (void (*)(struct Actor *))func_808009D0_chkingjinjo, (BtIntPtr)func_80108ED0, 16, 0, (void (*)(struct Actor *))func_80800018_chkingjinjo, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800634_chkingjinjo, 0 } };
ActorData D_808011F0_chkingjinjo [1] BT_DATA(4, overlays_ch_kingjinjo, 0xC0) = { { 344, 327, 2200, 1, (void *)D_80801190_chkingjinjo, (void (*)(struct Actor *))func_80800E58_chkingjinjo, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800F74_chkingjinjo, 0, 0, 0, 0, 128, 1284, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800D80_chkingjinjo, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_80800F60_chkingjinjo, 0 } };
s32 D_80801238_chkingjinjo [7] BT_DATA(4, overlays_ch_kingjinjo, 0x108) = { 350, 5374, 513, 302514176, 11403264, 919100, 67108864 };
s32 D_80801254_chkingjinjo [4] BT_DATA(4, overlays_ch_kingjinjo, 0x124) = { 50724883, 110559245, 15925516, 1114112 };
s32 D_80801264_chkingjinjo [4] BT_DATA(4, overlays_ch_kingjinjo, 0x134) = { 1246513, 852108, 10879000, 0 };
s32 D_80801274_chkingjinjo [4] BT_DATA(4, overlays_ch_kingjinjo, 0x144) = { 1246743, 852108, 10879000, 0 };
s32 D_80801284_chkingjinjo [7] BT_DATA(4, overlays_ch_kingjinjo, 0x154) = { 27591006, 357963095, 513, 302514176, 11403264, 919100, 167772160 };
u32 D_808012A0_chkingjinjo[4] BT_DATA(4, overlays_ch_kingjinjo, 0x170) = { 0x43C80000, 0x43960000, 0x43020000, 0x43340000 };
u32 D_808012B0_chkingjinjo[4] BT_DATA(4, overlays_ch_kingjinjo, 0x180) = { 0x43E10000, 0x43160000, 0x437A0000, 0x437A0000 };
u32 D_808012C0_chkingjinjo [4] BT_DATA(4, overlays_ch_kingjinjo, 0x190) = { 0x1305CA, 0xD00F3, 0x10C0016, 0x65900000 };
u32 D_808012D0_chkingjinjo [3] BT_DATA(4, overlays_ch_kingjinjo, 0x1A0) = { 0x130562, 0xD0140, 0x1590000 };
u32 D_808012DC_chkingjinjo [3] BT_DATA(4, overlays_ch_kingjinjo, 0x1AC) = { 0x130562, 0xD0119, 0x1330000 };
u32 D_808012E8_chkingjinjo [4] BT_DATA(4, overlays_ch_kingjinjo, 0x1B8) = { 0x3F35C28F, 0x3F47AE14, 0x3F5C28F6, 0xBF800000 };
u32 D_808012F8_chkingjinjo [3] BT_DATA(4, overlays_ch_kingjinjo, 0x1C8) = { 0x3F0CCCCD, 0x3F147AE1, 0xBF800000 };
u32 D_80801304_chkingjinjo [3] BT_DATA(4, overlays_ch_kingjinjo, 0x1D4) = { 0x3F428F5C, 0x3F570A3D, 0xBF800000 };
