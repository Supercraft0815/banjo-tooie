#include "ch/biggafoot.h"

void func_800FFAB0(Actor *);

OSThread *chbiggafoot_entrypoint_0(void)
{
    extern u8 D_80801094_chbiggafoot[];

    return (OSThread *) D_80801094_chbiggafoot;
}

OSThread *chbiggafoot_entrypoint_1(void)
{
    extern u8 D_808010DC_chbiggafoot[];

    return (OSThread *) D_808010DC_chbiggafoot;
}

void func_80800018_chbiggafoot(Actor *arg0) {
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 func_800A9C98(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    f32 sp28[6];

    func_80102FDC(arg0, arg0->scale * 1.6f);
    ((f32 *)arg0->actorData)[5] = 0.0f;
    ((f32 *)arg0->actorData)[4] = 0.0f;
    ((f32 *)arg0->actorData)[6] = 0.0f;
    arg0->unk50 = arg0->rotation[1];
    if (func_800A9C98() != 0) {
        func_800DA544(FLAG_1C7_UNK);
        func_800DA524(FLAG_1CC_UNK);
    }
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 0xA);
    } else {
        if (func_800DA298(FLAG_1CC_UNK) != 0) {
            func_800FFAB0(arg0);
            return;
        }
        _subaddiemarker_entrypoint_1(arg0, 0x320, 0x32, sp28, 1);
        func_800EE7F8((f32 *)arg0->actorData, sp28);
    }
    ((f32 *)arg0->actorData)[7] = 3.0f;
}

void func_80800100_chbiggafoot(Actor *arg0) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 _sudeflect_entrypoint_3(BtIntPtr arg0, BtIntPtr arg1, BtIntPtr arg2, BtIntPtr arg3, s32 arg4);
    void _sudeflect_entrypoint_4(s32, f32 *);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    s32 func_8010B990(Actor *, s32);
    void func_808008D4_chbiggafoot(BtIntPtr);
    s32 func_808008FC_chbiggafoot(Actor *);
    void func_80800980_chbiggafoot(void *);
    s32 func_808009EC_chbiggafoot(Actor *);
    void func_80800A9C_chbiggafoot(Actor *);
    void func_80800BA4_chbiggafoot(Actor *);
    void func_80800C04_chbiggafoot(Actor *);
    extern u8 D_80801124_chbiggafoot[];
    extern f32 D_8080113C_chbiggafoot[3];
    extern f32 D_80801148_chbiggafoot[3];
    f32 sp44[3];
    f32 sp38[3];
    s32 state;

    func_800D9078(&arg0->unk58);
    switch (arg0->unk70_10) {
    case 1:
        func_80800980_chbiggafoot(arg0);
        if (func_808009EC_chbiggafoot(arg0)) {
            func_800F7F98(func_800F54E4(), 1);
            func_80102424(arg0, 4);
            func_80108B04(arg0, 0);
            _subaddieDll_entrypoint_4(arg0, 1);
        } else if (func_808008FC_chbiggafoot(arg0)) {
            arg0->unk64_20 = 0;
            func_80102424(arg0, 3);
        } else {
            func_808008D4_chbiggafoot((BtIntPtr)arg0);
        }
        break;
    case 2:
        func_80800980_chbiggafoot(arg0);
        break;
    case 3:
        if (!arg0->unk64_20 && func_80101F24(arg0) > 0.35f) {
            func_8010A590(arg0);
        }
        func_80800980_chbiggafoot(arg0);
        if (func_80101DDC(arg0)) {
            func_8010A570(arg0);
            func_80101FDC(arg0, 1);
        }
        break;
    case 4:
        arg0->unk54 = arg0->unk50;
        func_80102BF8(arg0, 0x3E19999A, 0x40A00000, 0x42F00000);
        break;
    case 5:
        if (func_80101E14(arg0, 0.9f)) {
            func_80800BA4_chbiggafoot(arg0);
        }
        break;
    case 6:
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 7);
        }
        func_80800C04_chbiggafoot(arg0);
        break;
    case 7:
        func_80800C04_chbiggafoot(arg0);
        break;
    case 9:
        arg0->unk54 = func_80102D78(arg0, (s32 *)arg0->actorData);
        ((f32 *)arg0->actorData)[3] = func_800F3780(func_80101F24(arg0), D_80801124_chbiggafoot, 3) * 400.0f;
        func_80102B2C(arg0, func_800D8FF8() * 100.0f);
        func_8010B990(arg0, 0x1005);
        break;
    }
    state = arg0->unk70_10;
    if (state >= 5 && state < 10) {
        ((f32 *)arg0->actorData)[6] += func_800D8FF8() * 400.0f;
        ((f32 *)arg0->actorData)[5] = func_800F10B4(func_80013970(((f32 *)arg0->actorData)[6]), -1.0f, 1.0f, -0.2f, 0.0f);
        ((f32 *)arg0->actorData)[4] = func_800F15F8(((f32 *)arg0->actorData)[4], 1.0f, func_800D8FF8());
    }
    func_800EE7F8(sp44, arg0->position);
    if (_sudeflect_entrypoint_0(arg0->position, 140.0f, 160.0f, 10) & 2) {
        _sudeflect_entrypoint_4(9, arg0->position);
    }
    func_800EF1B8(sp44, arg0->unk50, -250.0f);
    func_800EFA4C(sp38, 0.0f, arg0->unk50, 0.0f);
    _sudeflect_entrypoint_3(sp44, sp38, D_8080113C_chbiggafoot, D_80801148_chbiggafoot, 2);
    func_80800A9C_chbiggafoot(arg0);
}

void func_808004B0_chbiggafoot(s32 arg0)
{
    func_800DA524(FLAG2_6CD_UNK);
}

s32 func_808004D4_chbiggafoot(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_17(f32);
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    s32 _capod_entrypoint_3(s32 arg0);
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);
    void _dbmorph_entrypoint_3(void *arg0, void *arg1, void *arg2, s32 arg3, f32 *weights);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    u8 *func_800B2768(u8 *);
    BtIntPtr func_800B2840(BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void func_800FFAB0(Actor *);
    s32 func_801015D0(Actor *);
    void func_80102424(Actor *, s32);
    BtIntPtr func_80103CB8(Actor *, BtUIntPtr);
    BtIntPtr func_80106790(BtIntPtr);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_8010A570(Actor *);
    void func_8010D930(s32, s32, f32 *, s32 *);
    void func_80800840_chbiggafoot(Actor *, s32, s32);
    extern f32 D_80801154_chbiggafoot[2];
    extern s32 D_8080115C_chbiggafoot[];
    extern s32 D_80801170_chbiggafoot[];
    extern s32 D_80801188_chbiggafoot[];
    f32 *threshold;
    Actor *sp58;
    f32 sp50[2];
    u8 *model;
    f32 sp40[3];
    Actor *spawned;

    switch (arg1) {
    case 0x2E:
        func_80800840_chbiggafoot(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0xB:
        if (arg2 == 0x50) {
            func_800DA544(FLAG_1CC_UNK);
            func_800FFAB0(arg0);
            _capod_entrypoint_3(0);
            return 4;
        }
        return 3;
    case 0xE:
        if (arg2 == 0x5A) {
            sp58 = func_80106790(arg0->unk3C);
            threshold = D_80801154_chbiggafoot;
            do {
                if (_capod_entrypoint_17(*threshold)) {
                    func_8010D930(4, sp58->unk70_0, sp58->position, D_8080115C_chbiggafoot);
                    return 3;
                }
                threshold++;
            } while (threshold != (f32 *)D_8080115C_chbiggafoot);
        }
        return 3;
    case 0x3F:
        func_8010A570(arg0);
        arg0->unk64_20 = 1;
        func_8010D930(1, arg0->unk70_0, arg0->position, D_80801170_chbiggafoot);
        if (!arg0->unk64_19) {
            arg0->unk64_19 = 1;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B1, 0xE, arg0->position, 0xA8);
        }
        break;
    case 0x1F:
        model = *(u8 **)&arg2;
        sp50[0] = sp50[1] = func_800F0D50(((f32 *)arg0->actorData)[4] + ((f32 *)arg0->actorData)[5], 0.0f, 1.0f);
        _dbmorph_entrypoint_3(func_800B2768(model), (u8 *)func_80103CB8(arg0, (BtUIntPtr)model), func_800B2840((BtIntPtr)model), 1, (u8 *)sp50);
        func_801015D0(arg0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80801188_chbiggafoot, arg0->scale);
        break;
    case 0x3D:
        func_800F7F98(func_800F54E4(), 0);
        func_800EE7F8(sp40, arg0->position);
        func_800EF1B8(sp40, arg0->unk50 - 40.0f, 100.0f);
        sp40[1] += 60.0f;
        spawned = func_80108528(0x44E, (f32 *)arg0->actorData, (s32)func_800F1DF4((f32 *)arg0->actorData, sp40), &arg0);
        spawned->unk3C = arg0->unk0;
        arg0->unk3C = spawned->unk0;
        func_800EE7F8((f32 *)spawned->actorData, sp40);
        func_800EE7F8((f32 *)spawned->actorData + 4, (f32 *)arg0->actorData);
        spawned->unk58 = ((f32 *)spawned->actorData)[3] = func_800EEAD4((f32 *)arg0->actorData, sp40) / 1600.0f;
        _capod_entrypoint_2(arg0->unk0, 0x23, 0);
        _capod_entrypoint_6(spawned->unk0, 0x5A, 0x30);
        break;
    case 0xA:
        func_80102424(arg0, 5);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_80800840_chbiggafoot(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80102424(Actor *, s32);
    f32 *temp_a0;

    arg0->unk58 = 1.5f;
    if (arg1 != 0x12B1) {
        temp_a0 = (f32 *)arg0->actorData;
        if (arg1 == 0x12B2) {
            func_800EE7F8(temp_a0, arg0->position);
            func_800EF1B8(temp_a0, arg0->unk50, 1000.0f);
            func_80102424(arg0, 9);
            _capod_entrypoint_6(arg0->unk0, 0x50, 0x2010);
            return;
        }
        func_80102424(arg0, 1);
    }
}

void func_808008D4_chbiggafoot(BtIntPtr arg0) {
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *);
    extern s32 D_80801198_chbiggafoot;
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80801198_chbiggafoot);
}

/* extern */

s32 func_808008FC_chbiggafoot(Actor *arg0) {
    s32 func_800F0008(f32 [3], f32, f32 [3], f32);
    BtUIntPtr func_800F54E4(void);
    f32 func_800F5BF0(BtIntPtr, f32 *);
    s32 func_800F6478(BtIntPtr);
    f32 sp24[3];
    s32 pad20;
    BtIntPtr sp1C;

    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    sp1C = func_800F54E4();
    if (func_800F6478(sp1C) == 0) {
        return 0;
    }
    return func_800F0008(sp24, func_800F5BF0(sp1C, sp24), arg0->position, 180.0f);
}

/* extern */

void func_80800980_chbiggafoot(void *arg0) {
    BtUIntPtr func_800F54E4(void);
    s32 func_800F5A00(BtIntPtr, s32 *);
    s32 func_800F6438(BtIntPtr);
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 sp1C[3];

    if (func_800F6438(func_800F54E4()) != 0) {
        func_800F5A00(func_800F54E4(), sp1C);
        (((Actor *)arg0)->unk54) = func_80102D78(arg0, sp1C);
        func_80102BF8(arg0, 0x3E19999A, 0x40A00000, 0x42F00000);
    }
}

s32 func_808009EC_chbiggafoot(Actor *arg0) {
    s32 func_800D9078(f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6478(BtIntPtr);
    s32 func_8010C9B0(f32 *, u32);
    s32 sp1C;

    sp1C = func_8010C9B0(arg0->position, 0x320);
    func_800DA3B8(FLAG2_6CD_UNK, sp1C);
    if (sp1C == 0) {
        ((f32 *)arg0->actorData)[7] = 3.0f;
        return 0;
    }
    if (func_800F6478(func_800F54E4()) == 0) {
        return 0;
    }
    if (func_800DA298(FLAG3_9FB_UNK) && func_800DA298(FLAG_1C7_UNK)) {
        return func_800D9078(&((f32 *)arg0->actorData)[7]);
    }
    return 0;
}

void func_80800A9C_chbiggafoot(Actor *arg0) {
    s32 func_801022E4(Actor *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    extern u32 D_808011B4_chbiggafoot;
    extern u32 D_808011C4_chbiggafoot;
    extern u32 D_808011D4_chbiggafoot;
    extern u32 D_808011E4_chbiggafoot;
    extern u32 D_808011F4_chbiggafoot;
    extern u32 D_80801200_chbiggafoot;
    extern u32 D_80801208_chbiggafoot;
    extern u32 D_80801218_chbiggafoot;
    f32 *position;

    switch (func_801022E4(arg0)) {
        case 0x389:
            position = arg0->position;
            _subaddieaudioquick_entrypoint_3(arg0, position, &D_808011B4_chbiggafoot, 0.75f);
            _subaddieaudioquick_entrypoint_4(arg0, position, &D_808011D4_chbiggafoot, &D_808011F4_chbiggafoot);
            _subaddieaudioquick_entrypoint_4(arg0, position, &D_808011C4_chbiggafoot, &D_808011E4_chbiggafoot);
            break;
        case 0x38B:
            position = arg0->position;
            _subaddieaudioquick_entrypoint_3(arg0, position, &D_80801200_chbiggafoot, 0.12f);
            _subaddieaudioquick_entrypoint_3(arg0, position, &D_80801208_chbiggafoot, 0.62f);
            break;
        case 0x38A:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801218_chbiggafoot, 0.35f);
            break;
    }
}

void func_80800BA4_chbiggafoot(Actor *arg0) { void func_80102424(Actor *, s32); void func_80800CDC_chbiggafoot(Actor *); extern s16 D_80801030_chbiggafoot; func_80102424(arg0, 6); arg0->unk3C = NULL; arg0->unk6C_0 = 0; ((f32 *)arg0->actorData)[3] = 1.0f; _capod_entrypoint_20(arg0->unk0, D_80801030_chbiggafoot, 0x10); func_80800CDC_chbiggafoot(arg0); }

void func_80800C04_chbiggafoot(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800D9078(f32 *);
    void func_80102424(Actor *, s32);
    void func_80800CDC_chbiggafoot(Actor *);
    extern s16 D_80801030_chbiggafoot;
    s32 temp_t3;

    if (func_800D9078(&((f32 *)arg0->actorData)[3]) != 0) {
        arg0->unk6C_0++;
        temp_t3 = arg0->unk6C_0;
        if (temp_t3 == 4) {
            _capod_entrypoint_20(arg0->unk0, 0x7F, 0x10);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B2, 6, arg0->position, 0xA8);
            func_80102424(arg0, 8);
            return;
        }
        _capod_entrypoint_20(arg0->unk0, (&D_80801030_chbiggafoot)[temp_t3], 0x10);
        func_80800CDC_chbiggafoot(arg0);
        ((f32 *)arg0->actorData)[3] = 1.0f;
    }
}

void func_80800CDC_chbiggafoot(Actor *arg0) {
    void func_800C3BDC(u8 id);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    void func_800C32C4(u8, s32);
    extern u8 D_80801038_chbiggafoot[];
    extern s32 D_80801224_chbiggafoot;
    u8 sp1F;

    sp1F = func_800C4350(0, NULL, &D_80801224_chbiggafoot);
    func_800C32C4(sp1F, D_80801038_chbiggafoot[arg0->unk6C_0]);
    func_800C3BDC(sp1F);
}

void func_80800D38_chbiggafoot(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, 1.4f);
}

void func_80800D5C_chbiggafoot(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFE50(f32[3], f32[3], f32[3], f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_80800E98_chbiggafoot(u8 *);
    extern u8 D_80801238_chbiggafoot[];
    s32 sp3C;
    f32 t;
    f32 sp2C[3];

    sp3C = func_800D9078(&arg0->unk58);
    t = func_800F10B4(arg0->unk58, 0.0f, ((f32 *)arg0->actorData)[3], 1.0f, 0.0f);
    func_800EFE50(arg0->position, &((f32 *)arg0->actorData)[4], (f32 *)arg0->actorData, t);
    func_80800E98_chbiggafoot((u8 *)arg0);
    if (arg0->unk70_10 == 1 && sp3C != 0) {
        func_800EE7F8(sp2C, arg0->position);
        _chexploder_entrypoint_3(arg0, sp2C, 0xB);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801238_chbiggafoot);
        func_80101FDC(arg0, 2);
        func_8010114C(arg0->unk3C, 0xA, 0);
    }
}

/* extern */

s32 func_80800E2C_chbiggafoot(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chexploder_entrypoint_6(BtIntPtr, s32, s32);
    s32 _chexploder_entrypoint_9(BtIntPtr, s32, s32);
    BtIntPtr func_80101080();
    BtIntPtr func_80106790(BtIntPtr);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    if (arg1 == 0x90) {
        temp_v0 = func_80106790(func_80101080());
        sp1C = temp_v0;
        _chexploder_entrypoint_9(temp_v0, 1, 2);
        _chexploder_entrypoint_6(sp1C, 0x43C80000, 0x43FA0000);
    } else {
        return 0;
    }
    return 1;
}

void func_80800E98_chbiggafoot(u8 *arg0) {
    BtIntPtr func_800BBCB8(u8 *, BtIntPtr, s32, s32, s32 *);
    extern s32 D_80801244_chbiggafoot;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_80801244_chbiggafoot);
}
