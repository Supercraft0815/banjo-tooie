#include "ch/alienkids.h"

void *func_80100094(Actor *, u32);
Actor *func_80106790(Unk80132ED0 *);

OSThread *chalienkids_entrypoint_0(void)
{
    extern u8 D_808020DC_chalienkids[];

    return (OSThread *) D_808020DC_chalienkids;
}

OSThread *chalienkids_entrypoint_1(void)
{
    extern u8 D_80802124_chalienkids[];

    return (OSThread *) D_80802124_chalienkids;
}

OSThread *chalienkids_entrypoint_2(void)
{
    extern u8 D_8080216C_chalienkids[];

    return (OSThread *) D_8080216C_chalienkids;
}

OSThread *chalienkids_entrypoint_3(void)
{
    extern u8 D_808021B4_chalienkids[];

    return (OSThread *) D_808021B4_chalienkids;
}

/* extern */

void func_80800030_chalienkids(s32 arg0) {
    void func_80800FA4_chalienkids(s32, s32, s32, s32);
    func_80800FA4_chalienkids(arg0, 0x32, 0x372, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800058_chalienkids.s")

/* extern */

void func_8080017C_chalienkids(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_8010A85C(u8 *, s32);
    void func_80800FA4_chalienkids(s32, s32, s32, s32);
    func_80800FA4_chalienkids(arg0, 0x33, 0x373, 6);
    if ((func_800DA298(0x373) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_8010A85C((u8 *) arg0, 2);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_808001D0_chalienkids.s")

void func_80800370_chalienkids(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void _chlifeforcespell_entrypoint_2(Actor *, s32, s32 *);
    void func_80800D58_chalienkids(Actor *, s32);
    s32 *sp3C;
    s32 sp30[3];
    s32 sp24[3];

    sp3C = func_80100094(arg0, 0U);
    if (sp3C[11] != 0) {
        _subaddiefade_entrypoint_9(arg0, sp24);
        _chlifeforcespell_entrypoint_2(arg0, sp3C[11], sp30);
        _subaddiefade_entrypoint_11(arg0, sp30);
        func_80800D58_chalienkids(arg0, arg1);
        _subaddiefade_entrypoint_11(arg0, sp24);
    } else {
        func_80800D58_chalienkids(arg0, arg1);
    }
}

/* extern */

void func_80800408_chalienkids(u8 *arg0) {
    void func_8010A63C(void ***);
    void func_80800FA4_chalienkids(s32, s32, s32, s32);
    func_80800FA4_chalienkids(arg0, 0x34, 0x374, 9);
    if (((Actor *) arg0)->unk70_10 == 9) {
        func_8010A63C((void ***) arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800454_chalienkids.s")

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x74];
        u32 pad74_6 : 26;
        u32 unk74_5 : 1;
        u32 pad74_0 : 5;
    } flags;
    struct {
        u8 pad0[0x50];
        s32 dialogFlag;
    } dialog;
} AlienKidsActor;

s32 func_80800648_chalienkids(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _capod_entrypoint_14(void);
    s32 _chlifeforcespell_entrypoint_1(Actor **, void *, s32, f32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _glcutDll_entrypoint_20(void);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F77E8(s32, f32 *);
    void func_800F8300(s32, s32, f32 *);
    s32 func_80101180(s32, s32, s32);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);
    Actor *func_801084B0(s32, Actor **);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A63C();
    void func_80800DB8_chalienkids(Actor *, s32, s32);
    void func_808014B0_chalienkids(AlienKidsActor *, s32);
    void func_8080193C_chalienkids(Actor *);
    typedef struct {
        f32 v[3];
    } KidPosition;
    typedef struct {
        u8 pad0[0x2C];
        s32 spell;
        Unk80132ED0 *child;
    } KidData;
    extern KidPosition D_8080220C_chalienkids;
    extern KidPosition D_80802218_chalienkids;
    extern s32 D_80802224_chalienkids[];
    KidData *data;
    Actor *child;
    f32 position[3];
    s16 *params;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x3D:
        switch (arg2) {
        case 0:
        case 1:
            child = func_801084B0(0x459, &arg0);
            data->child = child->unk0;
            child->unk3C = arg0->unk0;
            child->rotation[1] = 0.0f;
            if (arg2 == 1) {
                ((AlienKidsActor *)child)->dialog.dialogFlag = 0x6B4;
            } else {
                ((AlienKidsActor *)child)->dialog.dialogFlag = 0;
            }
            if (!func_800DA298(0x376)) {
                func_8010A570(child);
            } else {
                child->unk64_16 = 0;
            }
            break;
        case 2:
            func_800EE7F8(position, arg0->position);
            position[1] -= 120.0f;
            data->spell = _chlifeforcespell_entrypoint_1(&arg0, position, 100, 4.0f, 0x12);
            break;
        case 3:
            arg0->unk3C = func_80108528(0x466, arg0->position, 0, &arg0)->unk0;
            break;
        }
        break;
    case 0xA:
        if (arg0->unk6C_9 == 0x456) {
            KidPosition position1 = D_8080220C_chalienkids;
            func_800F77E8(func_800F54E4(), position1.v);
            func_80102424(arg0, 5);
            ((AlienKidsActor *)arg0)->flags.unk74_5 = 0;
            _capod_entrypoint_13(arg0->unk0, NULL, 0x60, 0x30);
        } else if (arg0->unk6C_9 == 0x457) {
            KidPosition position2 = D_80802218_chalienkids;
            func_800F77E8(func_800F54E4(), position2.v);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12CE, 6, arg0->position, 0xB7);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x5D, 0x30);
        }
        data->child = NULL;
        break;
    case 0x18:
        {
            f32 position3[3];
            s32 pad[2];
            func_800EE7F8(position3, arg0->position);
            func_800EF1B8(position3, arg0->rotation[1] + 40.0f, 150.0f);
            func_800F77E8(func_800F54E4(), position3);
            func_800F8300(func_800F54E4(), 2, arg0->position);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x65, 0x30);
            func_80102424(arg0, 0xB);
            arg0->unk58 = 2.0f;
        }
        break;
    case 0x2E:
        params = (s16 *)&arg2;
        func_80800DB8_chalienkids(arg0, params[0], params[1]);
        break;
    case 0xB:
        switch (arg2) {
        case 0xC:
            func_80101180(0x457, 0x4A, 0);
            return 4;
        case 0xF:
            func_80101180(0x458, 0x4A, 0);
            return 4;
        case 0x13:
            func_808014B0_chalienkids((AlienKidsActor *)arg0, 0x372);
            _subaddieDll_entrypoint_4(arg0, 0);
            func_80102424(arg0, 0x10);
            _capod_entrypoint_14();
            func_80101180(0x45A, 0x31, arg0->unk6C_9);
            return 4;
        case 0x16:
            func_808014B0_chalienkids((AlienKidsActor *)arg0, 0x373);
            _subaddieDll_entrypoint_4(arg0, 0);
            func_80102424(arg0, 0x10);
            _capod_entrypoint_14();
            func_80101180(0x45A, 0x31, arg0->unk6C_9);
            return 4;
        }
        return 2;
    case 0x4A:
        func_80102424(arg0, 2);
        func_80103110(arg0, 1);
        _subaddieDll_entrypoint_4(arg0, 1);
        switch (arg0->unk6C_9) {
        case 0x456:
            arg0->unk58 = 4.0f;
            _capod_entrypoint_13(arg0->unk0, NULL, 0xC, 0x2030);
            break;
        case 0x457:
            arg0->unk58 = 2.5f;
            _capod_entrypoint_14();
            _capod_entrypoint_13(arg0->unk0, NULL, 0xF, 0x2030);
            break;
        case 0x458:
            arg0->unk58 = 2.0f;
            func_8010A63C(arg0);
            _capod_entrypoint_14();
            _capod_entrypoint_13(arg0->unk0, NULL, 0x12, 0x2010);
            break;
        }
        break;
    case 0x4B:
        func_80108B04(arg0, 2);
        _capod_entrypoint_13(arg0->unk0, NULL, 0x31, 0x30);
        _subaddieDll_entrypoint_4(arg0, 1);
        arg0->unk58 = 6.0f;
        func_80102424(arg0, 7);
        break;
    case 0x4C:
        ((KidData *)func_80100094(arg0, 0))->spell = 0;
        break;
    case 0x4E:
        if (arg0->unk70_10 == 0x10) {
            _subaddieDll_entrypoint_4(arg0, 1);
            func_80102424(arg0, 0x12);
            func_80108B04(arg0, 3);
            arg0->unk58 = 1.2f;
        }
        break;
    case 0x29:
        func_8080193C_chalienkids(arg0);
        break;
    case 0x2A:
        func_80801994_chalienkids(arg0);
        break;
    case 0x95:
        ((KidData *)func_80100094(arg0, 0))->child = NULL;
        switch (arg0->unk6C_9) {
        case 0x456:
            if (!func_800DA298(0x372) && !_glcutDll_entrypoint_20()) {
                func_80108B04(arg0, 0);
            }
            break;
        case 0x457:
            if (!func_800DA298(0x373) && !func_800DA298(0x6B4) && !_glcutDll_entrypoint_20()) {
                func_80108B04(arg0, 1);
            }
            break;
        }
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80802224_chalienkids, arg0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}


void func_80800D58_chalienkids(Actor *arg0, s32 arg1) {
    s32 func_80101870(s32, s32);
    void func_8010A764(s32, s32);
    struct {
        u8 pad0[0x30];
        Unk80132ED0 *unk30;
    } *data;

    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        data = func_80100094(arg0, 0);
        if (data->unk30 != NULL) {
            func_8010A764(func_80106790(data->unk30), arg1);
        }
    }
}

void func_80800DB8_chalienkids(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _capod_entrypoint_14(void);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    s32 _subaddiefade_entrypoint_5();
    void func_80102424(Actor *, s32);
    extern s32 D_80801E60_chalienkids[];
    extern s32 D_80801E80_chalienkids[];
    extern s32 D_80801E98_chalienkids[];
    extern s32 D_80801EA8_chalienkids[];
    extern u8 D_80802234_chalienkids[];
    s32 first;
    s32 second;

    switch (arg1) {
    case 0x1284:
        ((f32 *)arg0->actorData)[3] = 200.0f;
        func_80102424(arg0, 0xF);
        _subaddieDll_entrypoint_4(arg0, 1);
        _capod_entrypoint_14();
        _capod_entrypoint_13(arg0->unk0, 0, 0x13, 0x2010);
        return;
    case 0x1285:
        arg0->unk6C_0 = 5;
        ((f32 *)arg0->actorData)[3] = 200.0f;
        func_80102424(arg0, 0xF);
        _subaddieDll_entrypoint_4(arg0, 1);
        _capod_entrypoint_14();
        _capod_entrypoint_13(arg0->unk0, 0, 0x16, 0x2010);
        return;
    case 0x1286:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802234_chalienkids);
        func_80102424(arg0, 0xC);
        _subaddiefade_entrypoint_5(arg0);
        arg0->unk58 = 2.0f;
        return;
    case 0x12CE:
        _capod_entrypoint_14();
        return;
    default:
        first = _subaddiedialog_entrypoint_9((s32)arg0, arg1, D_80801E60_chalienkids, 4) != 0;
        second = _subaddiedialog_entrypoint_9((s32)arg0, arg1, D_80801E80_chalienkids, 3) != 0;
        if (first || second) {
            func_80102424(arg0, 0x10);
            return;
        }
        if (_subaddiedialog_entrypoint_9((s32)arg0, arg1, D_80801EA8_chalienkids, 3)) {
            func_80102424(arg0, 0x10);
            return;
        }
        if (_subaddiedialog_entrypoint_9((s32)arg0, arg1, D_80801E98_chalienkids, 2)) {
            func_80102424(arg0, 9);
        }
        return;
    }
}

void func_80800FA4_chalienkids(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _glcutDll_entrypoint_20();
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800FFAB0(u8 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80103014(u8 *);
    void func_80103110(void *, s32);
    void func_8010A85C(u8 *, s32);
    typedef union {
        Actor actor;
        struct {
            u8 pad[0x94];
            u32 pad94_17 : 15;
            u32 unk94_16 : 1;
            u32 pad94_0 : 16;
        } flags;
    } InitActor;
    f32 *data;
    s32 ready;

    data = func_80100094((Actor *)arg0, 0);
    ready = func_800DA298(0x372) != 0;
    if (ready) {
        ready = func_800DA298(0x373) != 0;
        if (ready) {
            ready = func_800DA298(0x374) != 0;
        }
    }
    if (ready && !_glcutDll_entrypoint_20()) {
        func_800FFAB0((u8 *)arg0);
        return;
    }
    ((InitActor *)arg0)->flags.unk94_16 = 1;
    _subaddiemarker_entrypoint_1((Actor *)arg0, 0x154, arg1, data, 1);
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C((u8 *)arg0, 1);
        func_800EE7F8(((Actor *)arg0)->position, data);
        ((Actor *)arg0)->rotation[1] = data[4];
        func_80102424((Actor *)arg0, 0x10);
        func_80103014((u8 *)arg0);
        return;
    }
    if (!func_800DA298(0x376)) {
        ((Actor *)arg0)->unk64_16 = 0;
        func_80103110((Actor *)arg0, 0);
        return;
    }
    if (func_800DA298(arg2)) {
        func_8010A85C((u8 *)arg0, 1);
        func_800EE7F8(((Actor *)arg0)->position, data);
        ((Actor *)arg0)->rotation[1] = data[4];
        func_80102424((Actor *)arg0, 0x10);
        func_80103014((u8 *)arg0);
        return;
    }
    func_80102424((Actor *)arg0, arg3);
}

void func_80801138_chalienkids(Actor* arg0)
{
    func_80801994_chalienkids(arg0);
}

s32 func_80801158_chalienkids(Actor *arg0, s32 arg1) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    f32 func_800136E4(f32);
    f32 func_80013970(f32);
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800FCAE0(u32, u32, u32);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    extern s32 D_8080223C_chalienkids[];
    f32 firstHeight;
    s32 spD0;
    f32 spC4[3];
    f32 spB8[3];
    f32 spAC[3];
    f32 height;
    f32 radius;
    f32 spA0;
    f32 sp9C;
    f32 sp90[3];
    s32 emitter;
    s32 i;
    f32 *data;

    data = func_80100094(arg0, 0);
    spD0 = func_800D9078(&arg0->unk58);
    if (!_subaddieskeleton_entrypoint_0(arg0, 3, spC4)) {
        func_800EE7F8(spC4, arg0->position);
    }
    sp9C = func_800D8FF8();
    emitter = func_800B53A4(8);
    height = func_80103EF4(arg0);
    radius = func_80103EAC(arg0) * 1.25f;
    func_800EE7F8(sp90, spC4);
    sp90[1] += (0.5f * height);
    firstHeight = func_800F12D4(arg0->unk58, 0.0f, 2.0f, height, (0.5f * height));
    spA0 = func_800F12D4(arg0->unk58, 0.0f, 2.0f, (0.5f * height), height);
    radius = func_800F12D4(arg0->unk58, 0.0f, 2.0f, 0.25f * radius, radius);
    func_800BA3FC(emitter, arg1);
    for (i = 0, height = 0.0f; i != 4; i++, height += 90.0f) {
        func_800EEB9C(spAC, data[7] + height, radius);
        func_800EE780(spB8, spC4, spAC);
        spB8[1] += firstHeight + 10.0f * func_80013970(data[9] + height);
        func_800BABB8(emitter, spB8, sp90, 1.0f, D_8080223C_chalienkids);
        func_800EEB9C(spAC, data[8] + height, radius);
        func_800EE780(spB8, spC4, spAC);
        spB8[1] += spA0 + 10.0f * func_80013970(data[10] + height);
        func_800BABB8(emitter, spB8, sp90, 1.0f, D_8080223C_chalienkids);
    }
    height = sp9C * 380.0f;
    data[7] = func_800136E4(data[7] - height);
    data[8] = func_800136E4(data[8] + height);
    data[9] += sp9C * 100.0f;
    data[10] += sp9C * 150.0f;
    if (spD0) {
        func_800FCAE0(0x1C, 0, 500);
    } else {
        func_800FCAE0(0x1C, -1, 500);
    }
    return spD0;
}

void *func_80100094(Actor *, u32);

void func_808014B0_chalienkids(AlienKidsActor *arg0, s32 arg1) {
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80103014(u8 *);
    s32 func_80104E78(Actor *);
    f32 *data;

    data = func_80100094(&arg0->actor, 0);
    func_800EE7F8(arg0->actor.position, data);
    arg0->actor.rotation[1] = data[4];
    arg0->flags.unk74_5 = 1;
    func_80103014((u8 *)arg0);
    func_80104E78(&arg0->actor);
    func_800DA544(arg1);
}

/* extern */

void func_80801520_chalienkids(void *arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiefade_entrypoint_2();
    void func_80102424(Actor *, s32);
    s32 func_8010A3E8(void *, s32);
    void func_808014B0_chalienkids(AlienKidsActor *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 2.0f;
    _subaddiefade_entrypoint_2();
    _subaddieDll_entrypoint_4(arg0, 1);
    func_8010A3E8(arg0, 0x3F19999A);
    func_80102424(arg0, 0xD);
    func_808014B0_chalienkids(arg0, arg1);
}

/* extern */

void func_8080158C_chalienkids(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void func_8008FB58(f32 *, f32, f32);
    f32 func_80103EAC(Actor *);
    f32 func_8010A40C(void *);
    u32 func_8010A698(void ***);
    f32 sp2C[3];
    f32 sp28;
    f32 sp24;

    sp24 = func_80103EAC(arg0);
    sp28 = func_8010A40C(arg0) * sp24;
    if (arg0->unk64_16) {
        if (func_8010A698(arg0) == 0) {
            if (_subaddieskeleton_entrypoint_0(arg0, 3, sp2C) != 0) {
                func_8008FB58(sp2C, 0.5f * sp28, sp28);
            }
        }
    }
}

/* extern */

void func_80801628_chalienkids(Actor *arg0) {
    s32 _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    u32 func_8010A654(void ***, s32);
    Unk80132ED0 **temp_v0;
    u32 sp20;
    void *var_s0;

    if (arg0->unk7C_12) {
        temp_v0 = func_80100094(arg0, 0U);
        sp20 = 0;
        var_s0 = temp_v0[12] != NULL ? func_80106790(temp_v0[12]) : NULL;
        if (var_s0 != 0) {
            sp20 = func_8010A654(var_s0, 0);
        }
        _chbadshad_entrypoint_2(arg0, 3, arg0->scale * 1.4f, 0);
        if (var_s0 != 0) {
            func_8010A654(var_s0, sp20);
        }
    }
}

void func_808016D4_chalienkids(Actor *arg0) {
    s32 func_800FFAB0();
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_8010114C(s32, s32, s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern s32 D_80802260_chalienkids;
    f32 delta;
    s32 sp20;

    switch (arg0->unk70_10) {
        case 18:
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 19);
            }
            break;
        case 19:
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 20);
                arg0->unk58 = ((f32 *)((u8 *)func_80800D58_chalienkids + 0x10))[arg0->unk6C_9];
            }
            break;
        case 20:
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 21);
                ((f32 *)arg0->actorData)[7] = 50.0f;
                arg0->unk58 = 4.0f;
                ((f32 *)arg0->actorData)[4] = 0.5f;
            }
            break;
        case 21:
            sp20 = func_800D9078(&arg0->unk58);
            ((f32 *)arg0->actorData)[7] += func_800D8FF8() * 100.0f;
            delta = ((f32 *)arg0->actorData)[7] * func_800D8FF8();
            arg0->position[1] += delta;
            if (func_800D9078(&((f32 *)arg0->actorData)[4])) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80802260_chalienkids);
            }
            if (sp20) {
                func_8010114C((s32)arg0->unk3C, 0x4F, 0);
                func_800FFAB0(arg0);
            }
            break;
    }
}

void func_8080184C_chalienkids(s32 arg0, s32 *arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_8080226C_chalienkids;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_8080226C_chalienkids, arg1, arg2);
}
void func_80801884_chalienkids(Actor *arg0) {
    s32 func_800D9078(f32 *);
    void func_80102424(Actor *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiefade_entrypoint_2();
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A590(Actor *);
    void func_8010A800(Actor *, s32);
    extern s32 D_8080227C_chalienkids;
    Unk80132ED0 **sp24;
    Unk80132ED0 *temp_a0;
    Actor *temp_v0;

    if (func_800D9078(&arg0->unk58) != 0) {
        sp24 = func_80100094(arg0, 0U);
        func_80102424(arg0, 3);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080227C_chalienkids);
        arg0->unk64_16 = 1;
        arg0->unk58 = 2.0f;
        _subaddiefade_entrypoint_2(arg0);
        func_8010A800(arg0, 0);
        temp_a0 = sp24[12];
        if (temp_a0 != NULL) {
            temp_v0 = func_80106790(temp_a0);
            temp_v0->unk64_16 = 0;
            func_8010A590(temp_v0);
        }
    }
}

/* extern */

void func_8080193C_chalienkids(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        temp_v0 = _suexpression_entrypoint_7(arg0, 1, 0xB7);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x3E8);
    }
}

void func_80801994_chalienkids(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
/* extern */

void func_808019C8_chalienkids(Actor *arg0) {
    s32 _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
    s32 _suexpression_entrypoint_18(void *, s32);
    s32 func_801022E4(Actor *);
    void *sp1C;
    s32 temp_v0_2;
    void *temp_v0;

    if ((*(u16 *)((s8 *)(arg0) + (0x64))) & 1) {
        temp_v0 = func_80100094(arg0, 1U);
        sp1C = temp_v0;
        if (temp_v0 != NULL) {
            temp_v0_2 = func_801022E4(arg0);
            switch (temp_v0_2) {
            case 0x325:
            case 0x326:
            case 0x329:
            case 0x32C:
            case 0x32E:
                break;
            default:
            case 0x327:
            case 0x328:
            case 0x32A:
            case 0x32B:
            case 0x32D:
                _suexpression_entrypoint_18(sp1C, 1);
                break;
            }
            _suexpression_entrypoint_10(sp1C, arg0->unk0, 0);
        }
    }
}

void func_80801A50_chalienkids(u8 *arg0) {
    void func_80109F08(void *arg0, s32 arg1);
    func_80109F08(arg0, 0x44);
    (*(u8 *)((s8 *)(arg0) + (0x7A))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x7A))) & 0xFF3F) | 0x80);
}

/* extern */

void func_80801A88_chalienkids(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _subaddieDll_entrypoint_6(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_8010A570(Actor *);
    f32 sp24[3];

    if ((arg0->unk70_10 == 2) && (_subaddieDll_entrypoint_6(arg0, 0xA) != 0)) {
        func_8010A570(arg0);
        func_800EE7F8(sp24, arg0->position);
        sp24[1] -= 100.0f;
        _chexploder_entrypoint_3(arg0, sp24, 0);
    }
}

/* extern */

void func_80801B08_chalienkids(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_80101870(arg0, arg1);
}

s32 func_80801B40_chalienkids(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_5(Actor *, s32);
    void func_80103110(void *, s32);
    void func_80101FDC(Actor *, u32);
    void func_80801BC4_chalienkids(u8 *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x40:
            if (_subaddieDll_entrypoint_5(arg0, arg2) != 0) {
                func_80103110(arg0, 1);
                func_80101FDC(arg0, 2);
                return 0;
            }
            break;
        case 0x90:
            func_80801BC4_chalienkids((u8 *)arg0);
            return 0;
        default:
            return 0;
    }
    return 0;
}

void func_80801BC4_chalienkids(u8 *arg0) {
    s32 _chexploder_entrypoint_9(s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800DA544(s32);
    s32 func_800FFAB0(u8 *);
    s32 func_80101080();
    s32 func_8010114C(s32, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80802284_chalienkids;
    s32 temp_a0;

    _chexploder_entrypoint_9(func_80106790(func_80101080()), 3, 2);
    func_8010114C((*(s32 *)((s8 *)(arg0) + (0x3C))), 0xA, 0);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80802284_chalienkids);
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x50)));
    if (temp_a0 != 0) {
        func_800DA544(temp_a0);
    }
    func_800FFAB0(arg0);
}
