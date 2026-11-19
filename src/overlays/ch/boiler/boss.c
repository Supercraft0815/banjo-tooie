#include "common.h"

extern u8 D_80802B7C_chboilerboss[];
void func_801018A4(Actor *, BtIntPtr);
void func_80102EC0();
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_80800030_chboilerboss();
void func_80800304_chboilerboss(Actor* arg0);
void func_80800324_chboilerboss(Actor *arg0);
s32 func_808008B0_chboilerboss(Actor *arg0, s32 arg1, BtIntPtr arg2);

u32 D_80802C00_chboilerboss[] = {
    0x00BE0002, 0x3F99999A,
    0x02C60001,
};

BtFnWord D_80802C0C_chboilerboss[] = {
    0x00070118, 0x06500001,
    (BtFnWord)D_80802B7C_chboilerboss, (BtFnWord)func_80102EC0,
    (BtFnWord)func_80800324_chboilerboss, (BtFnWord)func_801018A4,
    0x00000000, 0x00000000,
    0x00000000, 0x00011568,
    (BtFnWord)func_80800304_chboilerboss, (BtFnWord)func_80108ED0,
    0x00800000, (BtFnWord)func_80800030_chboilerboss,
    (BtFnWord)func_80107C2C, 0x80000422,
    (BtFnWord)func_808008B0_chboilerboss, 0x00000000,
};

BtFnWord D_80802C54_chboilerboss[] = {
    0x002B0223, 0x064D000E,
    (BtFnWord)D_80802B7C_chboilerboss,
};

OSThread *chboilerboss_entrypoint_0(void)
{

    return (OSThread *) D_80802C0C_chboilerboss;
}

OSThread *chboilerboss_entrypoint_1(void)
{

    return (OSThread *) D_80802C54_chboilerboss;
}

OSThread *chboilerboss_entrypoint_2(void)
{
    extern u8 D_80802C9C_chboilerboss[];

    return (OSThread *) D_80802C9C_chboilerboss;
}

OSThread *chboilerboss_entrypoint_3(void)
{
    extern u8 D_80802CE4_chboilerboss[];

    return (OSThread *) D_80802CE4_chboilerboss;
}

void func_80800030_chboilerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800EE88C(f32 *, s16 *);
    void func_800F497C(BtIntPtr);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    s32 func_800FFAB0(BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80105A9C(Actor *, f32);
    s32 _chintrotext_entrypoint_2(s32);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _glcutDll_entrypoint_20(void);
    void func_800F49A8(BtIntPtr, s32);
    void func_80105BAC(Actor *);
    void func_80109FE8(void **, s32);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_8080238C_chboilerboss(Unk80132ED0 **, s32, s32);
    void func_808024B8_chboilerboss(BtIntPtr);
    void func_80802730_chboilerboss(Actor *, s32, s32);
    void func_808027E4_chboilerboss(Actor *, s32, s32, Unk80132ED0 *);
    extern f32 D_80802B4C_chboilerboss[];
    extern s32 func_8010D5DC;
    struct BoilerData {
        u8 pad0[0x56];
        u8 unk56;
        u8 pad57[9];
        s32 unk60;
        s16 unk64;
        s16 unk66;
        f32 position[2][3];
    } *data;
    Prop *props[2];
    int i;
    int j;
    int count;
    BtIntPtr player;
    union BoilerFlags {
        u32 word;
        struct {
            BT_BITFIELD_ORDER(u32 pad:18, u32 rest : 11);
            BT_BITFIELD_ORDER(u32 bit13:1, u32 bit11 : 1);
            u32 bit12:1;
            BT_BITFIELD_ORDER(u32 bit11:1, u32 bit13 : 1);
            BT_BITFIELD_ORDER(u32 rest:11, u32 pad : 18);
        } bits;
    };

    data = func_80100094(arg0, 0);
    func_800DA524(0x670);
    if (func_800DA298(0x86) && !_glcutDll_entrypoint_20()) {
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(arg0);
        return;
    }
    ((f32 *)arg0->actorData)[4] = arg0->rotation[1];
    arg0->pad5E = ((s32 *)arg0->actorData)[5] = 50;
    ((union BoilerFlags *)&arg0->unk0->unk28)->bits.bit11 = 1;
    ((union BoilerFlags *)&arg0->unk0->unk28)->bits.bit13 =
        ((union BoilerFlags *)&arg0->unk0->unk28)->bits.bit12 =
        ((union BoilerFlags *)&arg0->unk0->unk28)->bits.bit11;
    func_80105A9C(arg0, D_80802B4C_chboilerboss[0]);
    func_80105BAC(arg0);
    func_80109FE8((void **)arg0, 0);
    _suexpression_entrypoint_7(arg0, 1, 0x42);
    count = _gccubesearch_entrypoint_9(0x3DA, props, 2);
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (i == props[j]->unk6_7 - 50) break;
        }
        func_800EE88C(data->position[i], props[j]->position);
    }
    player = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        func_80102424(arg0, 0x11);
        return;
    }
    if (func_800DA298(0x179)) {
        data->unk60 = 1;
        data->unk66 = 1;
        data->unk56 = 1;
        func_800F608C(player, 1);
        func_800F8294(player, data->position[1]);
        func_800F497C(player);
        func_8080238C_chboilerboss(&arg0->unk0, 0xF9E, 0x10F);
        func_80800F34_chboilerboss(arg0, 4);
        func_808024B8_chboilerboss((BtIntPtr)arg0);
        func_80802730_chboilerboss(arg0, 2, 1);
        return;
    }
    data->unk60 = 0;
    func_800F608C(player, 1);
    func_800F8294(player, data->position[0]);
    func_800F497C(player);
    func_800F49A8(player, 1);
    func_800F49D4(player, &func_8010D5DC, (BtIntPtr)arg0->unk0);
    func_800F4A58(player, data->position[1], 300.0f);
    _chintrotext_entrypoint_2(1);
    func_8080238C_chboilerboss(&arg0->unk0, 0xFA8, 0x40);
    func_808027E4_chboilerboss(arg0, 0x13, 0x20, NULL);
}

void func_80800304_chboilerboss(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_80800324_chboilerboss(Actor *arg0) {
    void _subaddieDll_entrypoint_7(Actor *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_9(u32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800CEAD0(s32);
    void func_800DA544(GameFlag);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F4EC8(BtUIntPtr, BtIntPtr, f32, f32, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80105834(Actor *);
    void func_80108B04(Actor *, u32);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_808012C8_chboilerboss(Actor *);
    void func_808013C4_chboilerboss(Actor *);
    void func_80801464_chboilerboss(Actor *, f32 *, f32);
    void func_808014F4_chboilerboss(Actor *, f32 *, f32);
    void func_80801628_chboilerboss(Actor *);
    void func_808017F0_chboilerboss(Actor *);
    void func_80801C24_chboilerboss(Actor *);
    void func_80801CE8_chboilerboss(Actor *);
    void func_80802114_chboilerboss(Actor *);
    void func_8080221C_chboilerboss(Actor *, s32, volatile s32);
    void func_8080238C_chboilerboss(Unk80132ED0 **, s32, s32);
    s32 func_808023C8_chboilerboss(BtIntPtr);
    void func_808025DC_chboilerboss(Actor *);
    extern s32 D_80802AB0_chboilerboss;
    extern u32 D_80802B08_chboilerboss;
    extern u32 D_80802B14_chboilerboss;
    extern f32 D_80802B34_chboilerboss;
    extern f32 D_80802B40_chboilerboss;
    extern f32 D_80802B5C_chboilerboss;
    extern u32 D_80802D2C_chboilerboss;
    extern s32 D_80802D38_chboilerboss;
    extern u32 D_80802D60_chboilerboss;
    f32 *sp5C;
    s32 sp58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    sp5C = func_80100094(arg0, 0);
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 4, sp5C);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 5, sp5C + 3);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 6, sp5C + 6);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 7, sp5C + 15);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 8, sp5C + 12);
    _subaddieskeleton_entrypoint_3(arg0->unk0, 9, sp5C + 9);
    func_808012C8_chboilerboss(arg0);
    func_80801628_chboilerboss(arg0);
    func_80802114_chboilerboss(arg0);
    func_808023C8_chboilerboss((BtIntPtr)arg0);
    switch (arg0->unk70_10) {
    case 1:
    case 4:
    case 12:
    case 13:
        break;
    case 2:
        func_808017F0_chboilerboss(arg0);
        if (func_80101DDC(arg0)) {
            func_80800F34_chboilerboss(arg0, 3);
        }
        func_80801C24_chboilerboss(arg0);
        break;
    case 3:
        if (func_80101DDC(arg0)) {
            func_800F82D4(func_800F54E4(), 0);
            func_8080238C_chboilerboss(&arg0->unk0, 0xF97, 0x10E);
            func_80800F34_chboilerboss(arg0, 4);
        }
        break;
    case 5:
        func_80105834(arg0);
        func_808013C4_chboilerboss(arg0);
        func_80801CE8_chboilerboss(arg0);
        break;
    case 6:
        func_80105834(arg0);
        func_80801CE8_chboilerboss(arg0);
        if (func_80101E14(arg0, 0.2f)) {
            _subaddieaudioquick_entrypoint_2(arg0, sp5C + 15,
                func_800DC298(0.5f) ? &D_80802B34_chboilerboss : &D_80802B40_chboilerboss);
        }
        if (func_80101DDC(arg0)) {
            func_80800F34_chboilerboss(arg0, 5);
        }
        break;
    case 10:
        if (func_80101DDC(arg0)) {
            func_80800F34_chboilerboss(arg0, 5);
        }
        if (func_80101E14(arg0, 0.8f)) {
            sp58 = -((arg0->unk0->unk28 << 20) >> 31) - ((arg0->unk0->unk28 << 19) >> 31) - ((arg0->unk0->unk28 << 18) >> 31) + 3;
            if (func_800CEAD0(0)) {
                func_800DA544(0x670);
                func_8080221C_chboilerboss(arg0, 1, 0x501502F9);
            } else {
                func_8080221C_chboilerboss(arg0, 1, 0x40A00000);
            }
            sp5C[18] = func_800DC178(((f32 (*)[2])&D_80802B5C_chboilerboss)[sp58][0], ((f32 (*)[2])&D_80802B5C_chboilerboss)[sp58][1]);
        }
        _subaddieaudioquick_entrypoint_3(arg0, sp5C + 15, &D_80802D2C_chboilerboss, 0.2f);
        break;
    case 7:
        _suexpression_entrypoint_9(func_80100094(arg0, 1));
        if (func_80101E14(arg0, 0.5f)) {
            func_80801464_chboilerboss(arg0, sp4C, 40.0f);
            func_800BBCB8(sp4C, sp5C + 6, arg0->scale, 8, &D_80802AB0_chboilerboss);
            _subaddieaudioquick_entrypoint_2(arg0, sp4C, &D_80802B14_chboilerboss);
            func_80108B04(arg0, 0x223);
        }
        if (func_80101DDC(arg0)) {
            func_80800F34_chboilerboss(arg0, 5);
        }
        _subaddieaudioquick_entrypoint_3(arg0, sp5C + 15, &D_80802B08_chboilerboss, 0.2f);
        break;
    case 8:
        _suexpression_entrypoint_9(func_80100094(arg0, 1));
        if (func_80101E14(arg0, 0.5f)) {
            func_808014F4_chboilerboss(arg0, sp40, 40.0f);
            func_800BBCB8(sp40, sp5C + 6, arg0->scale, 8, &D_80802AB0_chboilerboss);
            _subaddieaudioquick_entrypoint_2(arg0, sp40, &D_80802B14_chboilerboss);
            func_80108B04(arg0, 0x224);
        }
        if (func_80101DDC(arg0)) {
            func_80800F34_chboilerboss(arg0, 5);
        }
        _subaddieaudioquick_entrypoint_3(arg0, sp5C + 15, &D_80802B08_chboilerboss, 0.2f);
        break;
    case 9:
        _suexpression_entrypoint_9(func_80100094(arg0, 1));
        if (func_80101E14(arg0, 0.3f)) {
            func_800EE7F8(sp34, sp5C + 6);
            sp34[1] -= 120.0f;
            func_800BBCB8(sp5C + 6, sp34, arg0->scale, 16, &D_80802D38_chboilerboss);
            _subaddieaudioquick_entrypoint_2(arg0, sp5C + 6, &D_80802B14_chboilerboss);
            func_80108B04(arg0, 0x225);
        }
        if (func_80101DDC(arg0)) {
            func_80800F34_chboilerboss(arg0, 5);
        }
        _subaddieaudioquick_entrypoint_3(arg0, sp5C + 15, &D_80802B08_chboilerboss, 0.0f);
        break;
    case 11:
        func_800F4EC8(func_800F54E4(), (BtIntPtr)arg0->position, 340.0f, 0.0f, 300.0f);
        _subaddieDll_entrypoint_7(arg0, 8);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80802D60_chboilerboss);
        break;
    }
    func_808025DC_chboilerboss(arg0);
}

s32 func_808008B0_chboilerboss(Actor *arg0, s32 arg1, BtIntPtr arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcfrontend_entrypoint_10(void);
    s32 func_800D395C(void);
    BtUIntPtr func_800F54E4(void);
    void func_800F8300();
    u32 func_800FDC28(u32);
    s32 func_800FFAB0(BtIntPtr);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800B94_chboilerboss(Actor *, u8 *);
    void func_80800D50_chboilerboss(Actor *, s32 *);
    void func_80800E90_chboilerboss(Actor *, s32 *);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_80801584_chboilerboss(Actor *, BtIntPtr);
    void func_80801D80_chboilerboss(Actor *, s32, s32);
    void func_8080221C_chboilerboss(Actor *, s32, volatile s32);
    void func_808022BC_chboilerboss(Actor *);
    void func_8080238C_chboilerboss(Unk80132ED0 **, s32, s32);
    void func_808024DC_chboilerboss(Actor *);
    s32 func_80802690_chboilerboss(BtIntPtr, s32, s32);
    void func_808026F0_chboilerboss(BtIntPtr);
    void func_808027E4_chboilerboss(Actor *, s32, s32, Unk80132ED0 *);
    extern s32 D_80802AA0_chboilerboss;
    struct BoilerBossData {
        u8 pad0[0x55];
        u8 unk55;
        u8 unk56;
        u8 pad57[0xD];
        s16 unk64;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x3F:
        func_80800D50_chboilerboss(arg0, (s32 *)arg2);
        break;
    case 0x40:
        func_80800E90_chboilerboss(arg0, (s32 *)arg2);
        break;
    case 0x2E:
        func_80801D80_chboilerboss(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x3D:
        func_80801584_chboilerboss(arg0, arg2);
        break;
    case 0x90:
        func_808022BC_chboilerboss(arg0);
        break;
    case 0x32:
        data->unk64 = 1;
        func_800F8300(func_800F54E4(), 2, arg0->position);
        break;
    case 0x1F:
        func_80800B94_chboilerboss(arg0, *(u8 **)&arg2);
        break;
    case 0xB:
        switch (arg2) {
        case 8:
            if (func_800D395C()) {
                func_808026F0_chboilerboss((BtIntPtr)arg0);
                _gcfrontend_entrypoint_10();
            } else {
                func_808027E4_chboilerboss(arg0, 0x14, 0x30, NULL);
                func_80101180(0x46D, 7, 0);
            }
            return 4;
        case 20:
            func_808026F0_chboilerboss((BtIntPtr)arg0);
            func_800FFAB0(arg0);
            return 4;
        case 19:
            func_808026F0_chboilerboss((BtIntPtr)arg0);
            func_808024DC_chboilerboss(arg0);
            return 4;
        }
        return 3;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80802AA0_chboilerboss, arg0->scale);
        break;
    case 0x57:
        return func_80802690_chboilerboss((BtIntPtr)arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    case 0x95:
        if (data->unk56) {
            func_800FDC28(1U);
            data->unk56 = 0;
        }
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        func_8080238C_chboilerboss(&arg0->unk0, 0xCEB, 0x4A);
        break;
    case 0x9F:
        func_800FDC28(0U);
        func_80800F34_chboilerboss(arg0, 4);
        func_8080221C_chboilerboss(arg0, 0, 0x40A00000);
        data->unk55 = 0;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800B94_chboilerboss(Actor *arg0, u8 *arg1) {
    void _dbmorph_entrypoint_4(s16 *arg0, u8 *arg1, u8 *arg2, s32 arg3, BtIntPtr arg4);
    void *func_800AE080(s16);
    s32 func_800AE0E8(s16);
    u8 *func_800B2768(u8 *);
    BtIntPtr func_800B2840(BtIntPtr);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    BtIntPtr func_80103CDC(u8 *, u8 *);
    void func_808010F4_chboilerboss(Actor *);
    u32 sp3C;
    u32 sp38;
    u32 sp34;
    u8 *sp30;
    BtIntPtr sp2C;
    BtIntPtr sp28;
    sp3C = (arg0->unk0->unk28 << 18) >> 31;
    sp38 = (arg0->unk0->unk28 << 19) >> 31;
    sp34 = (arg0->unk0->unk28 << 20) >> 31;
    func_801015D0(arg0);
    func_808010F4_chboilerboss(arg0);
    func_800DF744(3, sp34 ? (sp3C ? 0 : 1) : 0);
    func_800DF744(4, sp3C);
    func_800DF744(5, sp3C);
    func_800DF744(6, sp34 ? (sp38 ? 0 : 1) : 0);
    func_800DF744(7, sp38);
    func_800DF744(8, sp38);
    func_800DF744(9, sp34 ? 0 : 1);
    func_800DF744(10, sp34);
    func_800DF744(11, sp34);
    if ((arg0->unk0->unk28 << 20) >> 31) {
        sp30 = func_800B2768(arg1);
        sp2C = func_80103CDC((u8 *)arg0, arg1);
        sp28 = func_800B2840((BtIntPtr)arg1);
        if (func_800AE0E8(*(s16 *)&arg0->unk0->unk10)) {
            _dbmorph_entrypoint_4(sp30, (u8 *)sp2C, sp28, 1,
                (BtIntPtr)func_800AE080(*(s16 *)&arg0->unk0->unk10));
        }
        func_800DF5D8(arg0->pad98, arg0->pad99, arg0->pad9A, 255);
    }
}

void func_80800D50_chboilerboss(Actor *arg0, s32 *arg1) {
    void func_800C4AF0(f32 *, void *);
    s16 func_800CB854(s32 *);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    void func_80109EEC(s16 *, s32);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_80801B88_chboilerboss(Actor *, s32 *);
    extern f32 D_80802B34_chboilerboss;
    extern f32 D_80802B40_chboilerboss;
    struct {
        u8 pad0[0x3C];
        f32 unk3C[3];
        u8 pad48[0x14];
        f32 unk5C;
    } *data;
    void *vector;
    data = func_80100094(arg0, 0);
    func_80801B88_chboilerboss(arg0, arg1);
    if ((s32)arg0->unk70_10 < 5 || (s32)arg0->unk70_10 >= 11) {
        return;
    }
    {
        if (func_800CB854(NULL) == 7) {
            data->unk5C = 1.5f;
            func_80109EEC((s16 *)arg0, 0x40);
        }
        switch (arg0->unk70_10) {
            default:
                if ((arg0->unk0->unk28 << 20) >> 31) {
                    func_80800F34_chboilerboss(arg0, 6);
                } else {
                    if (func_800DC298(0.5f)) {
                        vector = &D_80802B34_chboilerboss;
                    } else {
                        vector = &D_80802B40_chboilerboss;
                    }
                    func_800C4AF0(data->unk3C, vector);
                }
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                break;
        }
    }
}

/* extern */

void func_80800E64_chboilerboss(void *arg0) {
    BT_IDO_ONLY(s32 func_800D2498(s32, u8, s32, void *);) BT_NATIVE_ONLY(s32 func_800D2498(u32, s32, u32);)
    BT_IDO_ONLY(func_800D2498(0xC7, (((Actor *)arg0)->pad5E), 0, arg0);) BT_NATIVE_ONLY(func_800D2498(0xC7, (((Actor *)arg0)->pad5E), 0);)
}

void func_80800E90_chboilerboss(Actor *arg0, s32 *arg1) {
    void func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    void *func_80100094(Actor *, u32);
    void func_8010A570(Actor *);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_80801B88_chboilerboss(Actor *, s32 *);
    void func_8080221C_chboilerboss(Actor *, s32, volatile s32);
    void func_8080238C_chboilerboss(Unk80132ED0 **, s32, s32);
    void func_808027E4_chboilerboss(Actor *, s32, s32, Unk80132ED0 *);
    struct {
        u8 pad[0x55];
        u8 unk55;
    } *data;

    func_80801B88_chboilerboss(arg0, arg1);
    if (func_800CEAA8(0) != 0) {
        func_800CE88C(0, 0);
    }
    data = func_80100094(arg0, 0);
    data->unk55 = 0;
    func_8080238C_chboilerboss(&arg0->unk0, 0xF98, 2);
    func_808027E4_chboilerboss(arg0, 0x1F, 0x430, NULL);
    func_80800F34_chboilerboss(arg0, 0xB);
    func_8010A570(arg0);
    arg0->pad5E = 0;
    func_80800E64_chboilerboss(arg0);
    func_8080221C_chboilerboss(arg0, 0, 0x40A00000);
}

s32 func_80800F34_chboilerboss(Actor *arg0, s32 arg1) {
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void func_800187B4(s32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80109FE8(void **, s32);
    void func_80801EB4_chboilerboss(Actor *);
    void func_8080238C_chboilerboss(Unk80132ED0 **, s32, s32);
    void func_808024B8_chboilerboss(BtIntPtr);
    void func_808024DC_chboilerboss(Actor *);
    void func_80802594_chboilerboss(BtIntPtr);
    void func_808027E4_chboilerboss(Actor *, s32, s32, Unk80132ED0 *);
    struct {
        u8 pad[0x58];
        s8 unk58;
        u8 pad59[7];
        s32 unk60;
    } *data;
    s32 active;

    data = func_80100094(arg0, 0);
    active = 0;
    func_80102424(arg0, arg1);
    func_80802594_chboilerboss((BtIntPtr)arg0);
    switch (arg1) {
    case 7:
        func_808027E4_chboilerboss(arg0, 2, 0x30, NULL);
        func_8080238C_chboilerboss(&arg0->unk0, 0xF99, 0x40);
        func_80109FE8(&arg0->unk0, 0);
        break;
    case 8:
        func_808027E4_chboilerboss(arg0, 4, 0x30, NULL);
        func_8080238C_chboilerboss(&arg0->unk0, 0xF9A, 0x40);
        func_80109FE8(&arg0->unk0, 0);
        break;
    case 9:
        func_808027E4_chboilerboss(arg0, 6, 0x30, NULL);
        func_8080238C_chboilerboss(&arg0->unk0, 0xF9B, 0x40);
        func_80109FE8(&arg0->unk0, 0);
        break;
    case 5:
        func_80801EB4_chboilerboss(arg0);
        active = 1;
        break;
    case 10:
        active = 1;
        break;
    case 2:
        func_800187B4(0, 1.6f, 0.25f, 2.0f);
        func_808024B8_chboilerboss((BtIntPtr)arg0);
        func_808027E4_chboilerboss(arg0, 0, 0x20, NULL);
        _chintrotext_entrypoint_1(0x18B9, 0, 1, 0);
        data->unk60 = 1;
        break;
    case 6:
        active = 1;
        break;
    case 12:
        arg0->unk64_16 = 0;
        break;
    }
    data->unk58 = active;
    func_808024DC_chboilerboss(arg0); BT_NATIVE_ONLY(return 0;)
}

void func_808010F4_chboilerboss(Actor *arg0) {
    void _dbmorph_entrypoint_3(void *arg0, void *arg1, void *arg2, s32 arg3, f32 *weights);
    u8 *func_800B2768(u8 *);
    BtIntPtr func_800B2840(BtIntPtr);
    f32 func_800F0E00(f32, f32);
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    u8 *func_801039E4(Unk80132ED0 *);
    BtIntPtr func_80103CB8(Actor *, BtUIntPtr);
    union BoilerFlags {
        u32 word;
        struct {
            BT_BITFIELD_ORDER(u32 pad:20, u32 rest : 11);
            u32 bit11:1;
            BT_BITFIELD_ORDER(u32 rest:11, u32 pad : 20);
        } bits;
    } flags;
    u8 *mesh;
    f32 progress;
    struct {
        u8 pad[0x4C];
        f32 unk4C;
        f32 unk50;
    } *data;
    u8 *vertices;
    u8 *model;

    if (((union BoilerFlags *)&arg0->unk0->unk28)->bits.bit11 && arg0->unk64_16) {
        data = func_80100094(arg0, 0);
        mesh = func_801039E4(arg0->unk0);
        progress = func_80101F24(arg0);
        switch (arg0->unk70_10) {
        case 2:
            if (progress < 0.15f) {
                data->unk4C = 6.6666665f * progress;
            } else {
                data->unk4C = 1.0f;
            }
            data->unk50 = data->unk4C;
            break;
        case 6:
            if (progress < 0.5f) {
                data->unk4C = 2.0f * progress;
            } else {
                data->unk4C = 2.0f * (1.0f - progress);
            }
            data->unk50 = data->unk4C;
            break;
        case 7:
        case 8:
        case 9:
            if (progress < 0.15f) {
                data->unk4C = 6.6666665f * progress;
            } else {
                data->unk4C = 1.0f;
            }
            data->unk50 = data->unk4C;
            break;
        default:
            data->unk4C = func_800F0E00(data->unk4C - 0.2f, 0.0f);
            data->unk50 = data->unk4C;
            break;
        }
        model = func_800B2768(mesh);
        vertices = (u8 *)func_80103CB8(arg0, (BtUIntPtr)mesh);
        _dbmorph_entrypoint_3(model, vertices, func_800B2840((BtIntPtr)mesh), 1, (u8 *)&data->unk4C);
    }
}

void func_808012C8_chboilerboss(Actor *arg0) {
    s32 func_80800F34_chboilerboss(Actor *, s32);
    union {
        u32 word;
        struct {
            BT_BITFIELD_ORDER(u32 pad:18, u32 rest : 11);
            BT_BITFIELD_ORDER(u32 bit13:1, u32 bit11 : 1);
            u32 bit12:1;
            BT_BITFIELD_ORDER(u32 bit11:1, u32 bit13 : 1);
            BT_BITFIELD_ORDER(u32 rest:11, u32 pad : 18);
        } bits;
    } state;
    u8 health;

    state.word = arg0->unk70_10;
    if ((s32)state.word < 11) {
        if ((s32)state.word >= 5) {
            func_80800E64_chboilerboss(arg0);
            state.word = arg0->unk70_10;
        }
        if (state.word != 7 && state.word != 8 && state.word != 9 &&
            (health = arg0->pad5E) < (s32)arg0->actorData[5]) {
            arg0->actorData[5] = health;
            state.word = arg0->unk0->unk28;
            if (state.bits.bit13 && (s32)arg0->actorData[5] < 41) {
                func_80800F34_chboilerboss(arg0, 7);
                return;
            }
            if (state.bits.bit12 && (s32)arg0->actorData[5] < 31) {
                func_80800F34_chboilerboss(arg0, 8);
                return;
            }
            if (state.bits.bit11 && (s32)arg0->actorData[5] < 16) {
                func_80800F34_chboilerboss(arg0, 9);
            }
        }
    }
}

void func_808013C4_chboilerboss(Actor *arg0) {
    s32 func_800C0638(void);
    void *func_80100094(Actor *, u32);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_8080238C_chboilerboss(Unk80132ED0 **, s32, s32);
    struct {
        u8 pad0[0x48];
        f32 unk48;
        u8 pad4C[8];
        u8 unk54;
        u8 unk55;
    } *data;

    data = func_80100094(arg0, 0);
    if (data->unk55 != 3 && data->unk48 == 0.0f) {
        if (func_800C0638() == 0) {
            func_80800F34_chboilerboss(arg0, 10);
            if (data->unk54 == 0) {
                func_8080238C_chboilerboss(&arg0->unk0, 0xF9C, 0);
                data->unk54++;
            }
        }
    }
}

void func_80801464_chboilerboss(Actor *arg0, f32 *arg1, f32 arg2) {
    f32 func_800136E4(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);

    func_800EE7F8(arg1, func_80100094(arg0, 0));
    func_800EF1B8(arg1, func_800136E4(arg0->rotation[1] + 90.0f), 15.0f);
    func_800EF1B8(arg1, arg0->rotation[1], arg2);
    arg1[1] -= 10.0f;
}

void func_808014F4_chboilerboss(Actor *arg0, f32 *arg1, f32 arg2) {
    f32 func_800136E4(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *data;

    data = func_80100094(arg0, 0);
    func_800EE7F8(arg1, data + 3);
    func_800EF1B8(arg1, func_800136E4(arg0->rotation[1] - 90.0f), 15.0f);
    func_800EF1B8(arg1, arg0->rotation[1], arg2);
    arg1[1] -= 10.0f;
}

void func_80801584_chboilerboss(Actor *arg0, BtIntPtr arg1)
{
  void func_80102424(Actor *, s32);
  void func_80102FDC(void *, f32);
  void func_80105A9C(Actor *, f32);
  Actor *func_801084B0(BtIntPtr, Actor **);
  extern f32 D_80802B4C_chboilerboss[];
  Actor *sp1C;
  u32 flags;
  s32 index;
  Actor *temp_v0;
  temp_v0 = func_801084B0(arg1, &arg0);
  sp1C = temp_v0;
  temp_v0->unk3C = arg0->unk0;
  func_80102424(temp_v0, temp_v0->unk70_10);
  func_80102FDC(sp1C, arg0->scale);
  flags = arg0->unk0->unk28;
  index = ((3 - ((s32) ((flags << 20) >> 31))) - ((s32) ((flags << 19) >> 31))) - ((s32) ((flags << 18) >> 31));
  func_80105A9C(arg0, *((f32 *) (((u8 *) D_80802B4C_chboilerboss) + ((((index < 0) ? (index) : (index)) << 1) << 1))));
}

void func_80801628_chboilerboss(Actor *arg0) {
    int func_800DC298(f32 arg0);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void func_800EF1B8(f32 *arg0, f32 arg1, f32 arg2);
    void *func_80100094(Actor *arg0, u32 arg1);
    void func_808019C8_chboilerboss(BtIntPtr arg0, f32 *arg1);
    void func_80801A08_chboilerboss(BtIntPtr arg0, f32 *arg1);
    f32 *data;
    u32 bit13;
    u32 bit12;
    u32 bit11;
    f32 position[3];

    data = func_80100094(arg0, 0);
    bit13 = (arg0->unk0->unk28 << 18) >> 31;
    bit12 = (arg0->unk0->unk28 << 19) >> 31;
    bit11 = (arg0->unk0->unk28 << 20) >> 31;
    if ((s32)arg0->unk70_10 >= 11) {
        return;
    }
    if (bit11 && !bit13) {
        if (arg0->unk70_10 == 5) {
            if (func_800DC298(0.5f)) {
                func_80801464_chboilerboss(arg0, position, 75.0f);
                func_808019C8_chboilerboss((BtIntPtr)arg0, position);
            }
        } else if (func_800DC298(0.15f)) {
            func_80801464_chboilerboss(arg0, position, 75.0f);
            func_808019C8_chboilerboss((BtIntPtr)arg0, position);
        }
    }
    if (bit11 && !bit12) {
        if (arg0->unk70_10 == 5) {
            if (func_800DC298(0.5f)) {
                func_808014F4_chboilerboss(arg0, position, 75.0f);
                func_808019C8_chboilerboss((BtIntPtr)arg0, position);
            }
        } else if (func_800DC298(0.15f)) {
            func_808014F4_chboilerboss(arg0, position, 75.0f);
            func_808019C8_chboilerboss((BtIntPtr)arg0, position);
        }
    }
    if (!bit11 && arg0->unk70_10 != 9 && func_800DC298(0.4f)) {
        func_800EE7F8(position, data + 6);
        func_800EF1B8(position, arg0->rotation[1], 75.0f);
        func_80801A08_chboilerboss((BtIntPtr)arg0, position);
    }
}

void func_808017F0_chboilerboss(Actor *arg0) {
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80801A74_chboilerboss(Actor *, f32 *, f32 *, s32);
    void func_80801B00_chboilerboss(Actor *, f32 *);
    void func_80801B44_chboilerboss(Actor *, f32 *);
    f32 *data;
    f32 end[3];
    f32 start[3];

    data = func_80100094(arg0, 0);
    if (func_80101F24(arg0) < 0.7f && func_800DC298(0.4f)) {
        func_800EE7F8(end, arg0->position);
        end[1] += 30.0f;
        func_80801B00_chboilerboss(arg0, end);
    }
    if (func_80101E14(arg0, 0.0f)) {
        func_800EE7F8(end, arg0->position);
        end[1] -= 250.0f;
        func_80801A74_chboilerboss(arg0, arg0->position, end, 0);
    }
    if (func_80101E14(arg0, 0.45f)) {
        func_800EE7F8(start, data + 9);
        start[1] = arg0->position[1];
        func_800EE7F8(end, start);
        end[1] -= 100.0f;
        func_80801A74_chboilerboss(arg0, start, end, 1);
    }
    if (func_80101E14(arg0, 0.65f)) {
        func_800EE7F8(start, data + 12);
        start[1] = arg0->position[1];
        func_800EE7F8(end, start);
        end[1] -= 100.0f;
        func_80801A74_chboilerboss(arg0, start, end, 1);
    }
    if (func_80101E14(arg0, 0.85f)) {
        func_800EE7F8(start, data + 12);
        start[1] = arg0->position[1] + 25.0f;
        func_80801B44_chboilerboss(arg0, start);
    }
}

void func_808019C8_chboilerboss(BtIntPtr arg0, f32 *arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802ACC_chboilerboss;
    func_800BBCB8(arg1, 0, 1.0f, 1, &D_80802ACC_chboilerboss);
}

void func_80801A08_chboilerboss(BtIntPtr arg0, f32 *arg1) {
    BtIntPtr func_800B53A4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802ACC_chboilerboss;
    extern s32 D_80802D68_chboilerboss;
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BABB8(temp_v0, arg1, 0, 1.0f, &D_80802ACC_chboilerboss);
    func_800BABB8(sp24, arg1, 0, 1.0f, &D_80802D68_chboilerboss);
}

void func_80801A74_chboilerboss(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    void func_800BA22C(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802D88_chboilerboss;
    extern s32 D_80802DA4_chboilerboss;
    extern s32 D_80802DB0_chboilerboss;
    BtIntPtr emitter;
    s32 *settings;

    emitter = func_800BABB8(0, arg1, arg2, arg0->scale, &D_80802D88_chboilerboss);
    if (arg3 != 0) {
        settings = &D_80802DA4_chboilerboss;
    } else {
        settings = &D_80802DB0_chboilerboss;
    }
    func_800BABB8(emitter, arg1, arg2, arg0->scale, settings);
    func_800BA22C(emitter, 0x10);
}

void func_80801B00_chboilerboss(Actor *arg0, f32 *arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802DBC_chboilerboss;
    func_800BBCB8(arg1, 0, arg0->scale, 4, &D_80802DBC_chboilerboss);
}

void func_80801B44_chboilerboss(Actor *arg0, f32 *arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802E00_chboilerboss;
    func_800BBCB8(arg1, 0, arg0->scale, 8, &D_80802E00_chboilerboss);
}

void func_80801B88_chboilerboss(Actor *arg0, s32 *arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EC398(s32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern s32 D_80802E44_chboilerboss;
    extern s32 D_80802E6C_chboilerboss;
    f32 sp34[3];
    f32 sp28[3];
    f32 sp20[2];

    func_800EC398(arg1, sp34);
    func_800F18FC(sp34, arg0->position, sp20);
    func_800EEBF0(sp28, sp20, 40.0f);
    func_800EF04C(sp28, sp34);
    func_800BBCB8(sp34, sp28, 0.7f, 6, &D_80802E44_chboilerboss);
    func_800BBCB8(sp34, sp28, 1.0f, 3, &D_80802E6C_chboilerboss);
}

void func_80801C24_chboilerboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void *func_80100094(Actor *, u32);
    extern u32 D_80802B20_chboilerboss;
    extern u32 D_80802EA4_chboilerboss;
    f32 *sp24;

    sp24 = func_80100094(arg0, 0);
    if (!_subaddieaudioquick_entrypoint_3(arg0, sp24 + 15, &D_80802EA4_chboilerboss, 0.1f) &&
        (_subaddieaudioquick_entrypoint_3(arg0, sp24 + 9, &D_80802B20_chboilerboss, 0.65f) ||
         _subaddieaudioquick_entrypoint_3(arg0, sp24 + 12, &D_80802B20_chboilerboss, 0.88f))) {
        func_800E1610(0, 10.0f, 0.9f, arg0->position);
        func_80018820(0, 1.0f, 0.3f);
    }
}

void func_80801CE8_chboilerboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void *func_80100094(Actor *, u32);
    extern u32 D_80802B20_chboilerboss;
    f32 *sp1C;

    sp1C = func_80100094(arg0, 0);
    if (_subaddieaudioquick_entrypoint_3(arg0, sp1C + 9, &D_80802B20_chboilerboss, 0.0f) ||
        _subaddieaudioquick_entrypoint_3(arg0, sp1C + 12, &D_80802B20_chboilerboss, 0.5f)) {
        func_800E1610(0, 15.0f, 0.6f, arg0->position);
        func_80018820(0, 0.5f, 0.2f);
    }
}

void func_80801D80_chboilerboss(Actor *arg0, s32 arg1, s32 arg2) {
    extern void _chbaddiesetup_entrypoint_10(void);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    s32 _chexploder_entrypoint_5(u8 *, s32, u8 *, s32, f32, s32);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void func_80109FE8(void **, s32);
    u32 func_800FDC28(u32);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_80802414_chboilerboss(Actor *);
    void func_808024DC_chboilerboss(Actor *);
    void func_808026F0_chboilerboss(BtIntPtr);
    f32 sp2C;

    switch (arg1) {
        case 0xF97:
        case 0xF9E:
            func_80802414_chboilerboss(arg0);
            break;
        case 0xF99:
        case 0xF9A:
        case 0xF9B:
            func_80109FE8((void *)arg0, 1);
            func_808026F0_chboilerboss((BtIntPtr)arg0);
            func_808024DC_chboilerboss(arg0);
            break;
        case 0xF98:
            sp2C = arg0->position[1] + 200.0f;
            _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, 5,
                *(s32 *)&arg0->position[0], *(s32 *)&sp2C,
                *(s32 *)&arg0->position[2], *(s32 *)&arg0->rotation[1]);
            _chexploder_entrypoint_5((u8 *)arg0, 0x795, (u8 *)arg0->position,
                *(s32 *)&arg0->rotation[1], arg0->scale, 3);
            func_800FDC28(0U);
            func_80800F34_chboilerboss(arg0, 0xC);
            break;
        case 0xCEB:
            if (arg2 > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
    }
}

void func_80801EB4_chboilerboss(Actor *arg0) { void func_80101CDC(Actor *, f32); f32 func_8010203C(Actor *, u32); f32 func_80105AC4(Actor *); f32 sp1C; f32 sp18; extern f32 D_80802B58_chboilerboss; sp18 = func_8010203C(arg0, (u32)arg0->unk70_10); sp1C = D_80802B58_chboilerboss / func_80105AC4(arg0); func_80101CDC(arg0, sp18 * sp1C); }

/* extern */

void func_80801F10_chboilerboss(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(BtIntPtr);
    if (func_800DA298(0x86) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_80801F44_chboilerboss(Actor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80101DDC(Actor *);
    void _subaddiefade_entrypoint_3(Actor *);
    void func_80802098_chboilerboss(Actor *);
    struct BoilerMarker {
        u8 pad0[0x18];
        BT_BITFIELD_ORDER(u32 pad18_5 : 27, u32 pad18_0 : 1);
        u32 unk18_1 : 4;
        BT_BITFIELD_ORDER(u32 pad18_0 : 1, u32 pad18_5 : 27);
        u8 pad1C[0xC];
        BT_BITFIELD_ORDER(u32 pad28_14 : 18, u32 pad28_0 : 11);
        BT_BITFIELD_ORDER(u32 unk28_13 : 1, u32 unk28_11 : 1);
        u32 unk28_12 : 1;
        BT_BITFIELD_ORDER(u32 unk28_11 : 1, u32 unk28_13 : 1);
        BT_BITFIELD_ORDER(u32 pad28_0 : 11, u32 pad28_14 : 18);
    };
    Actor *actor;

    if (!arg0->unk64_20) {
        actor = func_80106790(arg0->unk3C);
        switch (arg0->unk6C_9) {
        case 0x223:
            ((struct BoilerMarker *)actor->unk0)->unk28_13 = 0;
            ((struct BoilerMarker *)actor->unk0)->unk18_1 = (u8)(((struct BoilerMarker *)actor->unk0)->unk18_1 | 1);
            break;
        case 0x224:
            ((struct BoilerMarker *)actor->unk0)->unk28_12 = 0;
            ((struct BoilerMarker *)actor->unk0)->unk18_1 = (u8)(((struct BoilerMarker *)actor->unk0)->unk18_1 | 2);
            break;
        case 0x225:
            ((struct BoilerMarker *)actor->unk0)->unk28_11 = 0;
            ((struct BoilerMarker *)actor->unk0)->unk18_1 = (u8)(((struct BoilerMarker *)actor->unk0)->unk18_1 | 4);
            break;
        }
        arg0->unk64_20 = 1;
    }
    if (func_80101DDC(arg0)) {
        _subaddiefade_entrypoint_3(arg0);
    }
    func_80802098_chboilerboss(arg0);
}

void func_80802098_chboilerboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    extern u32 D_80802EB0_chboilerboss;
    extern u32 D_80802EC4_chboilerboss;
    extern u32 D_80802ED0_chboilerboss;

    switch (arg0->unk6C_9) {
    case 0x223:
    case 0x224:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802EB0_chboilerboss, &D_80802EC4_chboilerboss);
        return;
    case 0x225:
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802EB0_chboilerboss, &D_80802ED0_chboilerboss);
        return;
    }
}

void func_80802114_chboilerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800D9078(f32 *);
    void func_80109EF4(void *, s32);
    s32 func_800CEAA8(s32);
    s32 func_800CEAD0(s32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800C4AF0(f32 *, void *);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_8080238C_chboilerboss(Unk80132ED0 **, s32, s32);
    extern u8 D_80802EE4_chboilerboss[];
    struct {
        u8 pad0[0x48];
        f32 unk48;
        u8 pad4C[9];
        u8 unk55;
        u8 pad56[6];
        f32 unk5C;
    } *data;

    data = func_80100094(arg0, 0);
    if (func_800D9078(&data->unk5C) != 0) {
        func_80109EF4(arg0, 0x40);
    }
    func_800D9078(&data->unk48);
    switch (data->unk55) {
    case 0:
        if (func_800CEAA8(0) != 0) {
            func_800CE88C(0, 0);
        }
        break;
    case 1:
        func_800CE8D8(0, 150.0f, 0x96);
        func_800CE88C(0, 1);
        data->unk55 = 2;
        break;
    case 2:
        if (func_800CEAD0(0) != 0) {
            data->unk55 = 3;
            func_800C4AF0(NULL, D_80802EE4_chboilerboss);
            func_80800F34_chboilerboss(arg0, 0xA);
            func_8080238C_chboilerboss(&arg0->unk0, 0xF9D, 0);
        }
        break;
    }
}

/* extern */

void func_8080221C_chboilerboss(Actor *arg0, s32 arg1, volatile s32 arg2) {
    s32 _chboilerid_entrypoint_5(Actor *);
    s32 _chboilerid_entrypoint_6(Actor *, s32);
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 pad[2];
    f32 *sp24;
    Actor *temp_v0;
    if (arg0->unk3C == NULL) {
        temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x321, -1, 0);
        if (temp_v0 == NULL) {
            return;
        }
        arg0->unk3C = temp_v0->unk0;
    }
    sp24 = arg0->position;
    arg0 = func_80106790(arg0->unk3C);
    if (arg1 != 0) {
        _chboilerid_entrypoint_6(arg0, arg2);
    } else {
        _chboilerid_entrypoint_5(arg0);
    }
    func_800EE7F8((f32 *)arg0->actorData, sp24);
}

void func_808022BC_chboilerboss(Actor *arg0) {
    s32 _chexploder_entrypoint_12(BtIntPtr, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    s32 func_800D395C(void);
#ifndef BT_NATIVE
    void func_800DA524(GameFlag);
#endif
    void func_800DA544(GameFlag);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808027E4_chboilerboss(Actor *, s32, s32, Unk80132ED0 *);
    extern s32 D_80802EF8_chboilerboss[];
    extern s32 D_80802F60_chboilerboss[];
    Actor *actor;
    f32 *position;

    actor = func_80106790(func_80101080());
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x4B);
    func_808027E4_chboilerboss(arg0, 8, 0x30, actor->unk0);
    position = arg0->position;
    _subaddieaudioquick_entrypoint_2(arg0, position, D_80802F60_chboilerboss);
    func_800BABB8(0, position, position, arg0->scale, D_80802EF8_chboilerboss);
    if (func_800D395C() == 0) {
        func_800D1000(0xB, 1, position, 1, NULL);
    }
    func_800DA544(0x86);
    func_800DA524(0x670);
}

void func_8080238C_chboilerboss(Unk80132ED0 **arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    arg2 |= 0x104;
    _subaddiedialog_entrypoint_11(*arg0, arg1, arg2, (f32 *)(arg0 + 1), 0x42);
}    typedef struct { u8 pad0[0x60]; s32 unk60; s16 unk64; } Objboss_func_808023C8_chboilerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 func_808023C8_chboilerboss(BtIntPtr arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if (((((Objboss_func_808023C8_chboilerboss_temp_v0 *)temp_v0)->unk60) == 0) && ((((Objboss_func_808023C8_chboilerboss_temp_v0 *)temp_v0)->unk64) != 0)) {
        func_80800F34_chboilerboss(arg0, 2);
    }
    return 0;
}

u32 func_800FDC28(u32);

void func_80802414_chboilerboss(Actor *arg0) {
    void _gcfrontend_entrypoint_9(s32 arg0);
    void func_800A51C0(void);
#ifndef BT_NATIVE
    void func_800DA544(s32);
#endif
    void *func_80100094(Actor *, u32);
    void func_80109FE8(void **, s32);
    void func_8010A590(Actor *);
    s32 func_80800F34_chboilerboss(Actor *, s32);
    void func_808026F0_chboilerboss(BtIntPtr);
    extern f32 D_80802B5C_chboilerboss;
    struct {
        u8 pad0[0x48];
        f32 unk48;
        u8 pad4C[9];
        u8 unk55;
        u8 pad56[0xA];
        s32 unk60;
    } *data;

    data = func_80100094(arg0, 0);
    func_808026F0_chboilerboss(arg0);
    func_800A51C0();
    func_80800F34_chboilerboss(arg0, 5);
    func_80109FE8(&arg0->unk0, 1);
    data->unk55 = 1;
    data->unk48 = D_80802B5C_chboilerboss * 0.5f;
    data->unk60 = 2;
    func_800DA544(0x179);
    _gcfrontend_entrypoint_9(0x24);
    func_8010A590(arg0);
    func_800FDC28(3);
}

void func_808024B8_chboilerboss(BtIntPtr arg0)
{
    func_800FDC28(0x1);
}

/* extern */

void func_808024DC_chboilerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80802538_chboilerboss(BtIntPtr);
    u8 *temp_v0;
    u8 *saved[1];

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0[0x57] == 0 && temp_v0[0x58] != 0 && temp_v0[0x59] == 0) {
        func_80802538_chboilerboss(arg0);
        if (0) {
            saved[0] = temp_v0;
        }
        temp_v0[0x58] = 0;
    }
}    typedef struct { u8 pad0[0x57]; u8 unk57; } Objboss_func_80802538_chboilerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x57]; s8 unk57; } Objboss_func_80802538_chboilerboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_80802538_chboilerboss(BtIntPtr arg0) {
    BtUIntPtr func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s32 func_800F4AF4(u32, s32);
    void func_808025DC_chboilerboss(Actor *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    if ((((Objboss_func_80802538_chboilerboss_temp_v0 *)temp_v0)->unk57) == 0) {
        func_800F4AF4(func_800F54E4(), 0x14);
        (((Objboss_func_80802538_chboilerboss_sp1C *)sp1C)->unk57) = 1;
    }
    func_808025DC_chboilerboss(arg0);
}    typedef struct { u8 pad0[0x57]; u8 unk57; } Objboss_func_80802594_chboilerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x57]; s8 unk57; } Objboss_func_80802594_chboilerboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_80802594_chboilerboss(BtIntPtr arg0) {
    BtUIntPtr func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s32 func_800F4B20(BtUIntPtr);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    if ((((Objboss_func_80802594_chboilerboss_temp_v0 *)temp_v0)->unk57) != 0) {
        func_800F4B20(func_800F54E4());
        (((Objboss_func_80802594_chboilerboss_sp1C *)sp1C)->unk57) = 0;
    }
}

void func_808025DC_chboilerboss(Actor *arg0) {
    s32 _plcamera_entrypoint_10(BtIntPtr);
    void _plcamera_entrypoint_9(BtIntPtr, f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F5EF8(BtIntPtr);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_80110014(s32 *);
    void func_80116088(u8 *, BtIntPtr);
    u8 *data;
    f32 position[3];

    data = func_80100094(arg0, 0);
    if (data[0x57] != 0) {
        if (_plcamera_entrypoint_10(func_800F54E4()) != 0x14) {
            data[0x57] = 0;
            return;
        }
        func_800EE7F8(position, arg0->position);
        position[1] += 400.0f;
        _plcamera_entrypoint_9(func_800F54E4(), position, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(func_800F54E4())), position);
    }
}

/* extern */

s32 func_80802690_chboilerboss(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80802730_chboilerboss(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(u8 *)((s8 *)(func_80100094(arg0, 0)) + (0x59))) != 2) {
            func_80802730_chboilerboss(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}    typedef struct { u8 pad0[0x59]; u8 unk59; } Objboss_func_808026F0_chboilerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_808026F0_chboilerboss(BtIntPtr arg0) {
    void _capod_entrypoint_3(u32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((((Objboss_func_808026F0_chboilerboss_temp_v0 *)temp_v0)->unk59) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_3(0);
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x59))) = 0;
    }
}

void func_80802730_chboilerboss(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);
    extern s32 D_80802AA0_chboilerboss;
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (data[0x59]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x14, 0);
        case 1:
            _capod_entrypoint_8(1);
            data[0x59] = 2;
            _gcdialogcamera_entrypoint_3(&D_80802AA0_chboilerboss, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_808027E4_chboilerboss(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    if (arg3 == NULL) {
        arg3 = arg0->unk0;
    }
    switch (data[0x59]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x14, arg2);
        case 2:
            data[0x59] = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}
