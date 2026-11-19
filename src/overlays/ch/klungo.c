#include "klungo_potions.h"

extern KlungoAnimations D_80803A4C_chklungo;
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_8080000C_chklungo();
void func_808002D0_chklungo();
void func_8080101C_chklungo(Actor *arg0);
void func_808011B4_chklungo(void *arg0, s32 arg1);
s32 func_80801220_chklungo(Actor *arg0, s32 arg1, s32 arg2);
void func_8080162C_chklungo(Actor *arg0);

u32 D_80803B60_chklungo[] = {
    0x025C0001, 0x3F333333,
    0x02640001,
};

BtFnWord D_80803B6C_chklungo[] = {
    0x00B3041E, 0xFFFF0001,
    (BtFnWord)&D_80803A4C_chklungo, (BtFnWord)func_808002D0_chklungo,
    (BtFnWord)func_8080101C_chklungo, (BtFnWord)func_808011B4_chklungo,
    0x00000000, 0x40000000,
    0x00000000, 0x00040561,
    (BtFnWord)func_8080162C_chklungo, (BtFnWord)func_80108ED0,
    0x00A00000, (BtFnWord)func_8080000C_chklungo,
    (BtFnWord)func_80107C2C, 0x80201404,
    (BtFnWord)func_80801220_chklungo, 0x00000000,
};

u32 D_80803BB4_chklungo[] = {
    0x00130567, 0x000A00B3,
    0x00020000,
};

OSThread *chklungo_entrypoint_0(void)
{

    return (OSThread *) D_80803B6C_chklungo;
}

void func_8080000C_chklungo(Actor *arg0) {
    s32 _chintrotext_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_20(void);
    s32 _glsplinefind_entrypoint_0(s32 arg0, f32 arg1[3]);
    void _plcamera_entrypoint_8(BT_IDO_ONLY(s32 *) BT_NATIVE_ONLY(u32) arg0);
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    void _susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2);
    void _susubgame_entrypoint_1(BtIntPtr arg0, u8 *arg1, s32 arg2);
    void _susubgame_entrypoint_12(void *arg0, void *arg1);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800F497C(BtIntPtr);
    u32 func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_801032B0(Actor *actor,u16 id,u16 palette);
    void func_80109FE8(void **, s32);
    void func_80801964_chklungo(Actor *, s32);
    void func_808020F0_chklungo(Actor *, s32);
    s32 func_8080242C_chklungo(void);
    void func_80802588_chklungo(Actor *, s32, s32);
    u8 func_80802DF4_chklungo(Actor *);
    s32 func_80803158_chklungo(Actor *, s32, s32);



    extern f32 D_80803A3C_chklungo[4];
    struct KlungoInit {
        s16 unk0, unk2, unk4, unk6, unk8;
        u8 padA[6];
        s16 unk10;
        u8 pad12[0x10];
        s16 unk22;
        u8 pad24[6];
        s16 unk2A, unk2C;
        u8 pad2E[2];
        f32 spline[3];
        u8 pad3C[6];
        s16 unk42;
        u8 pad44[8];
        f32 marker[3];
        u8 pad58[12];
        f32 camera[3];
        u8 pad70[12];
        u32 route[3];
        u32 subgame[1];
    } *data;
    struct KlungoActorFlags {
        u8 pad[0x70];
        BT_BITFIELD_ORDER(u8 pad70:7, u8 flag70 : 1);
        BT_BITFIELD_ORDER(u8 flag70:1, u8 pad70 : 7);
    };
    BtIntPtr camera;

    data = func_80100094(arg0, 0);
    data->unk8 = func_8080242C_chklungo();
    if (func_800DA298(data->unk8 + 0x318)) {
        func_800FFAB0(arg0);
        return;
    }
    if (_glcutDll_entrypoint_20()) {
        func_801032B0(arg0, 0x90C, 0);
        func_80801964_chklungo(arg0, 0xA);
        return;
    }
    func_80109FE8((void **)arg0, 0);
    _subaddierouteDll_entrypoint_3(arg0, data->route, arg0->position);
    _susubgame_entrypoint_0(arg0, data->subgame, 0);
    _susubgame_entrypoint_12(data->subgame, D_80803A3C_chklungo);
    _susubgame_entrypoint_1(arg0, data->subgame, 0xC);
    func_808020F0_chklungo(arg0, 0);
    ((f32 *)arg0->actorData)[3] = D_808038A0_chklungo[data->unk8].speed;
    data->unk2 = 1;
    data->unk4 = 0;
    data->unk0 = data->unk2;
    data->unk10 = func_80802DF4_chklungo(arg0);
    if (data->unk8 == 0) {
        data->unk22 = 0;
    } else {
        data->unk22 = 1;
    }
    if (arg0->unk7A_5) {
        ((struct KlungoActorFlags *)arg0)->flag70 = 1;
        data->unk2C = _glsplinefind_entrypoint_0(0x3A1, data->spline);
        _subaddiemarker_entrypoint_0(arg0, 0x3A1, data->marker, 1);
        _subaddiemarker_entrypoint_0(arg0, 0x154, data->camera, 1);
        if (func_800DA298(D_808038A0_chklungo[data->unk8].defeatedFlag)) {
            camera = func_800F54E4();
            data->unk2A = 1;
            func_800F608C(camera, 1);
            func_800F8294(camera, data->camera);
            func_800F497C(camera);
            _plcamera_entrypoint_8(BT_NATIVE_ONLY((u32)) camera);
            func_80802588_chklungo(arg0, 2, 1);
            func_80803158_chklungo(arg0, D_808038A0_chklungo[data->unk8].dialog[1], 0xE);
            func_80801964_chklungo(arg0, 8);
            data->unk42 = 1;
            return;
        }
        if (func_800D395C()) {
            if (data->unk8 == 2) {
                func_80803158_chklungo(arg0, 0x1633, 0x44);
                func_80801964_chklungo(arg0, 2);
            }
            func_80801964_chklungo(arg0, 5);
            return;
        }
        _chintrotext_entrypoint_2(1);
        if (data->unk8 == 2) {
            func_80801964_chklungo(arg0, 2);
        }
    }
}

void func_808002D0_chklungo(Actor *arg0) {
    void _gcfrontend_entrypoint_9(s32 arg0);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 _subaddiefind_entrypoint_9(s32);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    void func_8008FB58(f32 *, f32, f32);
    s32 func_800CBD84(f32 *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFD24(f32 vec[3]);
    void func_800EFE50(f32 *, void *, void *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    f32 func_80102D78(void *, s32 *);
    void func_801058C4(Actor *, s32, f32, s32);
    void func_80105BAC(Actor *);
    void func_80108B04(Actor *, u32);
    void func_80109FE8(void **, s32);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010CA74(f32 *, s32);
    void func_80801888_chklungo(void *);
    void func_808018D4_chklungo(void *);
    void func_80801910_chklungo(u8 *);
    void func_80801964_chklungo(Actor *, s32);
    void func_808020F0_chklungo(Actor *, s32);
    void func_8080220C_chklungo(Actor *);
    s32 func_80802558_chklungo(Actor *);
    void func_80802588_chklungo(Actor *, s32, s32);
    void func_808025CC_chklungo(Actor *, s32);
    void func_80802634_chklungo(Actor *);
    void func_808026CC_chklungo(Actor *);
    void func_80802798_chklungo(Actor *);
    void func_80802864_chklungo(Actor *);
    void func_808028E8_chklungo(Actor *);
    void func_80802914_chklungo(Actor *);
    void func_80802940_chklungo(Actor *);
    void func_80802B10_chklungo(Actor *);
    void func_808030A4_chklungo(Actor *);
    s32 func_80803158_chklungo(Actor *, s32, s32);
    void func_8080318C_chklungo(Actor *);
    f32 func_808031E4_chklungo(void *);
    void func_80803208_chklungo(s32 *);
    s32 func_808034CC_chklungo(void *);





    extern u32 D_80803BB4_chklungo[];
    struct KlungoState {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        s16 unk8;
        u8 padA[2];
        f32 unkC;
        s16 unk10;
        u8 unk12;
        u8 pad13[7];
        s16 unk1A;
        u8 pad1C[4];
        s16 unk20;
        s16 unk22;
        u8 pad24[8];
        s16 unk2C;
        u8 pad2E[2];
        f32 unk30[3];
        f32 unk3C;
        s16 unk40;
        s16 unk42;
        s16 unk44;
        u8 pad46[3];
        u8 unk49;
        u8 pad4A[0x12];
        f32 unk5C;
        u8 pad60[0x1C];
        struct {
            u8 pad0[6];
            u16 unk6;
        } route;
    };







    struct KlungoActorData {
        f32 start[3];
        f32 unkC;
        f32 end[3];
        f32 velocity;
    };
    struct KlungoState *data;
    u32 *expression;
    f32 dt;
    f32 scale;
    f32 angle;
    s32 result;
    f32 blend;
    s32 origin[3];
    KlungoEncounter *table;

    data = func_80100094(arg0, 0);
    expression = func_80100094(arg0, 1);
    func_800D9078(&data->unkC);
    func_8080220C_chklungo(arg0);
    switch (arg0->unk70_10) {
    case 1:
        func_80801888_chklungo(arg0);
        func_80801910_chklungo((u8 *)arg0);
        func_808026CC_chklungo(arg0);
        if (func_8010CA74(arg0->position, D_808038A0_chklungo[data->unk8].range) && func_800F64A4(func_800F54E4(), 1)) {
            func_80801964_chklungo(arg0, 5);
        }
        break;
    case 2:
        func_80801888_chklungo(arg0);
        if (func_8010CA74(arg0->position, D_808038A0_chklungo[data->unk8].range) && func_800F64A4(func_800F54E4(), 1)) {
            func_80803158_chklungo(arg0, 0x1633, 0x44);
            func_80801964_chklungo(arg0, 5);
        }
        break;
    case 3:
        dt = func_800D8FF8();
        ((struct KlungoActorData *)arg0->actorData)->velocity -= dt * 1000.0f;
        arg0->position[1] += dt * ((struct KlungoActorData *)arg0->actorData)->velocity;
        if (arg0->position[1] < data->unk3C) {
            arg0->position[1] = data->unk3C;
            func_80801964_chklungo(arg0, 4);
            func_80802940_chklungo(arg0);
        }
        break;
    case 4:
        if (func_80101DDC(arg0)) {
            func_80801964_chklungo(arg0, 8);
        }
        break;
    case 5:
        if (data->unk40 != 0) {
            break;
        }
    case 6:
    case 8:
        func_80801888_chklungo(arg0);
        func_808026CC_chklungo(arg0);
        break;
    case 27:
        func_808026CC_chklungo(arg0);
        break;
    case 7:
        func_80801888_chklungo(arg0);
        func_808026CC_chklungo(arg0);
        if (!func_800DA298(0x6AD)) {
            func_80802588_chklungo(arg0, 3, 1);
            func_80803158_chklungo(arg0, D_808038A0_chklungo[data->unk8].dialog[0], 0xE);
            func_80801964_chklungo(arg0, 8);
        }
        break;
    case 9:
        func_80802634_chklungo(arg0);
        if (func_80101DDC(arg0)) {
            func_800FDC28(0xB);
            func_800DA544(D_808038A0_chklungo[data->unk8].defeatedFlag);
            _gcfrontend_entrypoint_9(D_808038A0_chklungo[data->unk8].reward);
            func_800DA544(data->unk10 + 0xC07);
            switch (data->unk10) {
            case 1:
                func_80801964_chklungo(arg0, 0xB);
                func_80803158_chklungo(arg0, 0x1624, 4);
                break;
            case 2:
                func_80801964_chklungo(arg0, 0x10);
                func_80803158_chklungo(arg0, 0x1625, 4);
                break;
            case 3:
                func_80801964_chklungo(arg0, 0x14);
                func_80803158_chklungo(arg0, 0x1626, 4);
                break;
            }
        }
        break;
    case 10:
        func_808026CC_chklungo(arg0);
        break;
    case 11:
        scale = func_800F12D4(func_80101F24(arg0), 0.0f, 1.0f, 1.0f, 2.5f) * arg0->scale;
        func_8008FB58(arg0->position, scale * 80.0f, scale * 100.0f);
        func_80802864_chklungo(arg0);
        result = func_80101DDC(arg0);
        if (result) {
            table = &D_808038A0_chklungo[data->unk8];
            /* Keep the result live through the table address calculation for IDO. */
            if (result) { }
            data->unkC = func_800DC178(table->unk60, table->unk64);
            func_80802558_chklungo(arg0);
            func_80801964_chklungo(arg0, 12);
        }
        break;
    case 12:
        func_80801888_chklungo(arg0);
        func_808026CC_chklungo(arg0);
        if (data->unkC == 0.0f) {
            func_808018D4_chklungo(arg0);
            func_80801964_chklungo(arg0, 15);
            if (!data->unk49) {
                data->unk49 = 1;
                func_808025CC_chklungo(arg0, 4);
            }
        } else if (func_800D9078(&arg0->unk58)) {
            func_80801964_chklungo(arg0, 13);
        }
        break;
    case 13:
        blend = func_800F12D4(func_80101F24(arg0), 0.0f, 0.5f, 0.0f, 1.0f);
        func_800EFE50(arg0->position, ((struct KlungoActorData *)arg0->actorData)->end, ((struct KlungoActorData *)arg0->actorData)->start, blend);
        func_80802B10_chklungo(arg0);
        if (func_80101DDC(arg0)) {
            if (data->unkC == 0.0f) {
                func_808018D4_chklungo(arg0);
                func_80801964_chklungo(arg0, 15);
                if (!data->unk49) {
                    data->unk49 = 1;
                    func_808025CC_chklungo(arg0, 4);
                }
            } else {
                func_80801964_chklungo(arg0, 12);
            }
        }
        break;
    case 14:
        if (func_80101DDC(arg0)) {
            func_80801964_chklungo(arg0, 15);
        }
        break;
    case 15:
        func_808028E8_chklungo(arg0);
        if (data->unk12) {
            func_80801910_chklungo((u8 *)arg0);
        }
        if (func_80101DDC(arg0)) {
            if (data->unk12) {
                func_80801964_chklungo(arg0, 29);
            } else {
                if (data->unk22) {
                    func_80802558_chklungo(arg0);
                }
                func_80801964_chklungo(arg0, 28);
            }
        }
        break;
    case 16:
        func_808026CC_chklungo(arg0);
        result = _subaddiefade_entrypoint_0(arg0);
        if (!result) {
            result = func_80802558_chklungo(arg0);
            table = &D_808038A0_chklungo[data->unk8];
            /* Keep the result live through the table address calculation for IDO. */
            if (!result) { }
            data->unkC = func_800DC178(table->unk60, table->unk64);
            func_80801964_chklungo(arg0, 17);
        }
        break;
    case 17:
        func_8080318C_chklungo(arg0);
        func_80803208_chklungo((s32 *)arg0);
        if (data->unkC == 0.0f) {
            func_808020F0_chklungo(arg0, 5);
            func_80801964_chklungo(arg0, 28);
        }
        scale = func_808031E4_chklungo(arg0);
        _subaddierouteDll_entrypoint_7(arg0, &data->route, arg0->rotation[1], arg0->unk54, scale, 0x4802);
        _subaddierouteDll_entrypoint_6(arg0, &data->route, data->route.unk6, 0x3F, 0.7f, 40, 100);
        _subaddierouteDll_entrypoint_5(arg0, &data->route, data->route.unk6, 0.15f, 4.0f, 120.0f);
        func_8010B990(arg0, 0x1305);
        break;
    case 18:
        if (func_80101DDC(arg0)) {
            if (data->unk12) {
                func_80801964_chklungo(arg0, 29);
            } else {
                func_80802558_chklungo(arg0);
                func_80801964_chklungo(arg0, 28);
            }
        }
        break;
    case 19:
        func_800EFD24(origin);
        arg0->unk54 = func_80102D78(arg0, origin);
        _subaddierouteDll_entrypoint_5(arg0, &data->route, 0, 0.15f, 4.0f, 120.0f);
        func_8010B990(arg0, 0x1305);
        func_80803208_chklungo((s32 *)arg0);
        if (func_808034CC_chklungo(arg0)) {
            func_80109FE8((void **)arg0, 1);
            func_80801964_chklungo(arg0, 20);
        }
        break;
    case 20:
        func_808026CC_chklungo(arg0);
        break;
    case 21:
    case 22:
        func_80802914_chklungo(arg0);
        if (func_80101DDC(arg0)) {
            if (!_subaddieskeleton_entrypoint_0(arg0, 3, arg0->position) || func_800CBD84(arg0->position) == -1) {
                angle = arg0->unk70_10 == 21 ? 90.0f : -90.0f;
                func_800EF1B8(arg0->position, arg0->rotation[1] + angle, 150.0f);
            }
            func_80101180(0x41E, 10, 0);
            func_80801964_chklungo(arg0, 23);
        }
        break;
    case 23:
        func_8080318C_chklungo(arg0);
        func_80803208_chklungo((s32 *)arg0);
        if (data->unkC == 0.0f && data->unk1A == 0) {
            func_80101180(0x41E, 44, 0);
        }
        scale = func_808031E4_chklungo(arg0);
        _subaddierouteDll_entrypoint_7(arg0, &data->route, arg0->rotation[1], arg0->unk54, scale, 0x4802);
        _subaddierouteDll_entrypoint_6(arg0, &data->route, data->route.unk6, 0x3F, 0.6f, 40, 60);
        _subaddierouteDll_entrypoint_5(arg0, &data->route, data->route.unk6, 0.15f, 4.0f, 120.0f);
        func_8010B990(arg0, 0x1325);
        break;
    case 24:
        if (func_80101DDC(arg0)) {
            func_80801964_chklungo(arg0, data->unk12 ? 29 : 26);
        }
        break;
    case 26:
        func_80801888_chklungo(arg0);
        func_808026CC_chklungo(arg0);
        if (_subaddiefind_entrypoint_9(0x41E) == 1) {
            func_80109FE8((void **)arg0, 1);
            func_80801964_chklungo(arg0, 28);
        }
        break;
    case 28:
        func_80801888_chklungo(arg0);
        if (func_80101E14(arg0, 0.75f)) {
            func_80108B04(arg0, 0);
        }
        if (data->unk6 == 1) {
            data->unk6++;
        }
        if (func_80101E14(arg0, 0.999f)) {
            data->unk2--;
            if (data->unk2 == 0) {
                switch (data->unk10) {
                case 1:
                    func_80801964_chklungo(arg0, 11);
                    break;
                case 2:
                    func_80801964_chklungo(arg0, 16);
                    break;
                case 3:
                    func_80801964_chklungo(arg0, func_808034CC_chklungo(arg0) ? 20 : 19);
                    break;
                }
                func_80101180(0x421, 44, 0);
                data->unk44 = 0;
            }
            data->unk6 = 0;
        }
        break;
    case 29:
        func_80801910_chklungo((u8 *)arg0);
        func_80802798_chklungo(arg0);
        if (func_80101DDC(arg0)) {
            func_80801964_chklungo(arg0, 30);
        }
        break;
    case 31:
        func_80801910_chklungo((u8 *)arg0);
        if (func_800D9078(&arg0->unk58)) {
            func_80801964_chklungo(arg0, 32);
        }
        break;
    case 32:
        func_80801910_chklungo((u8 *)arg0);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80803BB4_chklungo, 0.2f);
        if (func_80101DDC(arg0)) {
            func_80801964_chklungo(arg0, 33);
        }
        break;
    case 33:
        func_80801910_chklungo((u8 *)arg0);
        func_808026CC_chklungo(arg0);
        if (func_800D9078(&arg0->unk58)) {
            func_80801964_chklungo(arg0, 34);
        }
        break;
    case 34:
        func_808026CC_chklungo(arg0);
        func_80801910_chklungo((u8 *)arg0);
        break;
    case 35:
        func_80801910_chklungo((u8 *)arg0);
        data->unk20++;
        if (data->unk20 == 1) {
            arg0->rotation[1] = arg0->unk54 = data->unk5C;
            func_800EE7F8(arg0->position, data->unk30);
            func_801058C4(arg0, data->unk2C, 300.0f, 1);
            func_80105BAC(arg0);
        }
        break;
    }
    func_808030A4_chklungo(arg0);
    if (expression != NULL) {
        if (func_801022E4(arg0) != 0x264) {
            _suexpression_entrypoint_18(expression, 1);
        }
        _suexpression_entrypoint_10(expression, arg0->unk0, 0);
    }
}

void func_8080101C_chklungo(Actor *arg0) {
    void _gcfrontend_entrypoint_10(void);
    void _glcutDll_entrypoint_6(u32, u32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    s32 func_800D395C(void);
    void *func_80100094(Actor *, u32);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    void func_800FFAB0(Actor *);
    void func_80803208_chklungo(s32 *);
    void func_80801910_chklungo(u8 *);
    s32 func_80802558_chklungo(Actor *);
    u32 *sp24;
    struct {
        u8 pad0[8];
        s16 unk8;
    } *data;

    sp24 = func_80100094(arg0, 1);
    func_80105834(arg0);
    func_80803208_chklungo((s32 *)arg0);
    func_80801910_chklungo((u8 *)arg0);
    if (func_80105A5C(arg0) != 0) {
        func_80802558_chklungo(arg0);
        if (func_800D395C() != 0) {
            _gcfrontend_entrypoint_10();
        } else {
            data = func_80100094(arg0, 0);
            if (data->unk8 == 2) {
                _glcutDll_entrypoint_6(0x15D, 0x5B);
            }
        }
        func_800FFAB0(arg0);
    }
    if (sp24 != NULL) {
        _suexpression_entrypoint_10(sp24, arg0->unk0, 0);
    }
}

void func_808010E0_chklungo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    void func_800DF744(s32, s32);
    void func_800DF5D8(u32, u32, u32, s32);
    s32 _subaddiefade_entrypoint_0(Actor *);
    struct {
        u8 pad0[6];
        s16 unk6;
        u8 pad8[8];
        s16 unk10;
        u8 pad12[8];
        s16 unk1A;
    } *data;
    u32 state;

    data = func_80100094(arg0, 0);
    func_801015D0(arg0);
    state = arg0->unk70_10;
    switch (state) {
        case 9:
            func_800DF744(3, data->unk10);
            break;
        case 28:
            state = data->unk6 == 2 ? 0 : 4;
            func_800DF744(3, state);
            break;
        default:
            func_800DF744(3, 0);
            break;
    }
    if (data->unk1A != 0) {
        func_800DF5D8(0xE0, 0xE0, 0xFF, _subaddiefade_entrypoint_0(arg0));
    }
}    typedef struct { u8 pad0[0x72]; u16 unk72; } Objklungo_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_808011B4_chklungo(void *arg0, s32 arg1)
{
  void func_800DF440(s32 enabled);
  s32 func_80101808(void *, s32 *);
  extern s32 func_801017D0;
  u32 temp_t7;
  temp_t7 = (u16) (((Objklungo_arg0 *)arg0)->unk72);
  temp_t7 = temp_t7 >> 0xA;
  if (((temp_t7 == 0xD) || (temp_t7 == 0x15)) || (temp_t7 == 0x16))
  {
    func_800DF440(0);
  }
  else
  {
    func_800DF440(1);
  }
  func_80101808(arg0, &func_801017D0);
}

s32 func_80801220_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    void _suexpression_entrypoint_8(void *arg0, s32 arg1);
    void _suexpression_entrypoint_12(void *arg0, f32 arg1, f32 arg2);
    void _suexpression_entrypoint_17(s16 *arg0, s32 arg1);
    s32 func_800D395C(void);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 func_801032B0(Actor *actor,u16 id,u16 palette);
    void func_80108B04(Actor *, u32);
    void func_8010A800(Actor *, s32);
    void func_80801680_chklungo(Actor *, s32);
    void func_80801744_chklungo(Actor *, s32, s32);
    s32 func_80801848_chklungo(Actor *, s32, s32);
    void func_80801964_chklungo(Actor *, s32);
    s32 func_80802480_chklungo(Actor *, s32);
    s32 func_80802558_chklungo(Actor *);
    s32 func_80802B84_chklungo(Actor *, s32);
    s32 func_80803158_chklungo(Actor *, s32, s32);

    extern f32 D_80803A3C_chklungo[4];
    struct KlungoData {
        s16 pad0[4];
        s16 index;
        s16 padA[8];
        s16 state;
        s16 count;
        s16 pad1E[5];
        s16 flag28;
        s16 flag2A;
        s16 pad2C[10];
        s16 flag40;
    } *data;
    void *expression;

    data = func_80100094(arg0, 0);
    switch ((int)arg1) {
    case 0x2E:
        func_80801744_chklungo(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0xB:
        switch (func_80802480_chklungo(arg0, arg2)) {
        case 2:
            func_80801964_chklungo(arg0, 9);
            return 4;
        case 6:
            func_80801964_chklungo(arg0, 0x1F);
            return 4;
        default:
            return 3;
        }
        break;
    case 0x40:
        func_80801680_chklungo(arg0, *(s32 *)&arg2);
        break;
    case 0x3D:
        func_80802B84_chklungo(arg0, arg2);
        break;
    case 0x2C:
        if (data->state != 0) {
            func_80801964_chklungo(arg0, 0x19);
        } else {
            func_8010A800(arg0, 0);
            if (arg2 == 0) {
                if (data->flag28 == 0) {
                    data->flag28 = 1;
                    func_80803158_chklungo(arg0, 0x1631, 0x44);
                }
                func_80801964_chklungo(arg0, 0x1A);
            }
        }
        break;
    case 0xA:
        if (data->state != 0) {
            return 0;
        }
        if (data->count == 0) {
            func_80802558_chklungo(arg0);
            func_80801964_chklungo(arg0, 0x17);
            func_8010A800(arg0, 0);
            return 0;
        }
        data->count--;
        func_80108B04(arg0, 2);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80803A3C_chklungo, arg0->scale);
        break;
    case 0x32:
        if (data->flag40 == 0) {
            func_80801964_chklungo(arg0, 7);
        }
        break;
    case 0x57:
        return func_80801848_chklungo(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    case 0x95:
        func_801032B0(arg0, D_808038A0_chklungo[data->index].model, 0);
        if (data->flag2A != 0) {
            func_800FDC28(1);
            data->flag2A = 0;
        }
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    case 0x29:
        if (data->state == 0) {
            expression = _suexpression_entrypoint_7(arg0, 1, 0xAB);
            _suexpression_entrypoint_12(expression, 70.0f, 30.0f);
            _suexpression_entrypoint_17(expression, 1000);
        }
        break;
    case 0x2A:
        if (data->state == 0) {
            _suexpression_entrypoint_8(arg0, 1);
        }
        break;
    case 0x1F:
        func_808010E0_chklungo(arg0, *(s32 *)&arg2);
        break;
    case 0x96:
        if (data->state != 0 || func_800D395C() == 0) {
            return 0;
        }
        func_80803158_chklungo(arg0, 0xCEB, 0x4E);
        break;
    case 0x9F:
        if (data->state != 0) {
            func_80801964_chklungo(arg0, 0x19);
            return 0;
        }
        func_800FDC28(0);
        func_80801964_chklungo(arg0, 8);
        break;
    default:
        return 0;
    }
    return 1;
}    typedef struct { u8 pad0[0x1A]; s16 unk1A; } Objklungo_func_8080162C_chklungo_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_8080162C_chklungo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_80802558_chklungo(Actor *);
    void func_80802FCC_chklungo(Actor *);
    void _suexpression_entrypoint_8(void *arg0, s32 arg1);
    void *sp1C;

    sp1C = func_80100094(arg0, 0);
    func_80802FCC_chklungo(arg0);
    func_80802558_chklungo(arg0);
    if (((Objklungo_func_8080162C_chklungo_sp1C *)sp1C)->unk1A == 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}    typedef struct { u8 pad0[0x1A]; s16 unk1A; } Objklungo_func_80801680_chklungo_data; /* offsets.py genstruct: fields from raw offsets on data; rename once understood */

void func_80801680_chklungo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80801964_chklungo(Actor *, s32);
    void func_800FC6B0(u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 12:
        case 13:
            func_80801964_chklungo(arg0, 14);
            return;
        case 16:
        case 17:
            func_80801964_chklungo(arg0, 18);
            return;
        case 23:
            if (((Objklungo_func_80801680_chklungo_data *)data)->unk1A == 0) {
                func_80801964_chklungo(arg0, 24);
                func_800FC6B0(14);
                func_80101180(0x41E, 0x2C, 1);
                return;
            }
            func_800FC6B0(15);
            func_80101180(0x41E, 0x2C, 0);
        default:
            return;
    }
}

void func_80801744_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void func_80801964_chklungo(Actor *, s32);
    s32 func_80802558_chklungo(Actor *);
    void func_808025CC_chklungo(Actor *, s32);
    s32 func_80803158_chklungo(Actor *, s32, s32);

    switch (arg1) {
        case 0x1622:
        case 0x1623:
        case 0x1628:
        case 0x1629:
        case 0x162B:
        case 0x162C:
            func_80801964_chklungo(arg0, 6);
            break;
        case 0x1627:
        case 0x162A:
        case 0x162D:
            func_80801964_chklungo(arg0, 0x23);
            break;
        case 0x162F:
            func_80802558_chklungo(arg0);
            func_80801964_chklungo(arg0, 0x1C);
            break;
        case 0x1633:
            func_80803158_chklungo(arg0, 0x1634, 0x4E);
            func_808025CC_chklungo(arg0, 1);
            func_80801964_chklungo(arg0, 3);
            break;
        case 0x1634:
            func_80801964_chklungo(arg0, 7);
            break;
        case 0xCEB:
        {
            if (arg2 > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
        }
        case 0x1624:
        case 0x1625:
        case 0x1626:
        case 0x1630:
        case 0x1631:
        case 0x1632:
        case 0x1635:
        case 0x1636:
        case 0x1637:
            break;
        default:
            func_80801964_chklungo(arg0, 1);
            break;
    }
}

s32 func_80801848_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    return _susubgame_entrypoint_3(arg0, (BtIntPtr)func_80100094(arg0, 0U) + 0x88, arg1, arg2);
}

void func_80801888_chklungo(void *arg0) {
    void func_8010D600(s32 *);
    f32 func_80102D78(void *, s32 *);
    void func_80102BF8(void *, f32, f32, f32);
    s32 sp1C[3];

    func_8010D600(sp1C);
    (((Actor *)arg0)->unk54) = func_80102D78(arg0, sp1C);
    func_80102BF8(arg0, 0.15f, 4.0f, 200.0f);
}

/* extern */

void func_808018D4_chklungo(void *arg0) {
    void func_800EFD24(f32 vec[3]);
    f32 func_80102D78(void *, s32 *);
    s32 sp1C[3];
    f32 temp_f0;

    func_800EFD24(sp1C);
    temp_f0 = func_80102D78(arg0, sp1C);
    (((Actor *)arg0)->unk54) = temp_f0;
    (((Actor *)arg0)->rotation[1]) = temp_f0;
}

void func_80801910_chklungo(u8 *arg0) {
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    Actor *actor = (Actor *)arg0;
    _sudeflect_entrypoint_0(actor->position, actor->scale * 100.0f, actor->scale * 130.0f, 2);
}

void func_80801964_chklungo(Actor *arg0, s32 arg1) {
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F497C(BtIntPtr);
    void func_800F49A8(BtIntPtr, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    u32 func_800F54E4(void);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);
    void func_80109FE8(void **, s32);
    void func_8010A570(Actor *);
    void func_8010A800(Actor *, s32);
    void func_808020F0_chklungo(Actor *, s32);
    void func_80802588_chklungo(Actor *, s32, s32);
    void func_808025CC_chklungo(Actor *, s32);
    void func_80802F30_chklungo(Actor *);
    void func_80802FCC_chklungo(Actor *);
    void func_80803000_chklungo(Actor *);
    void func_8080305C_chklungo(Actor *);
    s32 func_80803158_chklungo(Actor *, s32, s32);
    void func_8080322C_chklungo(Actor *, f32);
    extern s32 func_8010D5DC;




    extern u16 D_80803A2C_chklungo[8];
    extern s16 D_80803BC0_chklungo[8];
    extern s16 D_80803BD0_chklungo[7];
    struct KlungoState {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        s16 unk8;
        u8 padA[2];
        f32 unkC;
        u8 pad10[2];
        u8 unk12;
        u8 pad13[9];
        s16 unk1C;
        u8 pad1E[4];
        s16 unk22;
        u8 pad24[2];
        s16 unk26;
        u8 pad28[0x14];
        f32 unk3C;
        s16 unk40;
        s16 unk42;
        s16 unk44;
        u8 pad46[3];
        u8 unk49;
        u8 pad4A[0x1A];
        f32 unk64[3];
    };








    u32 sp3C;
    s32 sp38;
    s32 sp34;
    struct KlungoState *data;
    BtIntPtr sp2C;
    f32 sp28;

    sp3C = arg0->unk70_10;
    sp38 = 0;
    sp34 = 0;
    data = func_80100094(arg0, 0);
    func_80102424(arg0, arg1);
    func_8080305C_chklungo(arg0);
    switch (arg1) {
        case 2:
            data->unk3C = arg0->position[1];
            data->unk40 = 1;
            arg0->position[1] += 2500.0f;
            break;
        case 5:
            sp2C = func_800F54E4();
            func_808025CC_chklungo(arg0, 0);
            func_800F497C(sp2C);
            func_800F49A8(sp2C, 1);
            func_800F49D4(sp2C, &func_8010D5DC, (BtIntPtr)arg0->unk0);
            func_800F4A58(sp2C, data->unk64, data->unk40 ? 220 : 300);
            func_800FDC28(1);
            break;
        case 6:
            if (data->unk42) {
                func_80801964_chklungo(arg0, 9);
            } else {
                func_808025CC_chklungo(arg0, 2);
            }
            func_80101180(0x41F, 8, 0);
            break;
        case 7:
            _chintrotext_entrypoint_1(0x18B9, data->unk8 + 0xB, 1, 0);
            break;
        case 9:
            func_808025CC_chklungo(arg0, 3);
            break;
        case 12:
            arg0->unk58 = func_800DC178(D_808038A0_chklungo[data->unk8].unk68, D_808038A0_chklungo[data->unk8].unk6C);
            if (sp3C == 11) {
                arg0->unk58 = 1.0f;
            }
            sp38 = 1;
            break;
        case 13:
            sp28 = 0.0f;
            switch (data->unk8) {
                case 0:
                    sp28 = -1.0f;
                    break;
                case 1:
                    break;
                case 2:
                    sp28 = 1.0f;
                    break;
            }
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803BC0_chklungo);
            func_8080322C_chklungo(arg0, sp28);
            func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
            sp38 = 1;
            break;
        case 14:
            data->unk4++;
            if (data->unk4 == 3) {
                data->unk12 = 1;
            }
            if (!data->unk49 || data->unk12) {
                data->unk49 = 1;
                func_808018D4_chklungo(arg0);
                func_808025CC_chklungo(arg0, 4);
            }
            func_80802FCC_chklungo(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803A2C_chklungo);
            break;
        case 15:
            if (sp3C != 14 && !data->unk26) {
                func_80803158_chklungo(arg0, 0x1632, 0x44);
                data->unk26 = 1;
            }
            break;
        case 16:
            func_80802F30_chklungo(arg0);
            func_808020F0_chklungo(arg0, 1);
            break;
        case 17:
            ((f32 *)arg0->actorData)[3] = D_808038A0_chklungo[data->unk8].speed;
            arg0->unk54 = arg0->rotation[1];
            sp38 = 1;
            break;
        case 18:
            data->unk4++;
            if (data->unk4 == 3) {
                data->unk12 = 1;
            }
            func_80802FCC_chklungo(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803A2C_chklungo);
            func_808020F0_chklungo(arg0, 5);
            break;
        case 19:
        case 26:
            func_80109FE8((void **)arg0, 0);
            break;
        case 20:
            switch (data->unk4) {
                case 0: data->unk1C = 1; break;
                case 1: data->unk1C = 2; break;
                case 2: data->unk1C = 3; break;
            }
            data->unk1C--;
            func_80108B04(arg0, 2);
            func_8010A800(arg0, 2);
            break;
        case 23:
            data->unkC = func_800DC178(D_808038A0_chklungo[data->unk8].unk60, D_808038A0_chklungo[data->unk8].unk64);
            sp38 = 1;
            break;
        case 24:
            data->unk4++;
            if (data->unk4 == 3) {
                data->unk12 = 1;
            }
            func_80802FCC_chklungo(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803A2C_chklungo);
            break;
        case 25:
            func_8010A570(arg0);
            _subaddiefade_entrypoint_3(arg0);
            func_8010A800(arg0, 2);
            break;
        case 28:
            if (!data->unk22) {
                func_80801964_chklungo(arg0, 27);
                func_808025CC_chklungo(arg0, 9);
                func_80803158_chklungo(arg0, 0x162F, 0xE);
                func_80108B04(arg0, 1);
                data->unk22 = 1;
            } else {
                sp34 = 1;
                if (!func_800DA298(0x685)) {
                    switch (data->unk4) {
                        case 0: data->unk2 = 3; data->unk0 = data->unk2; break;
                        case 1: data->unk2 = 5; data->unk0 = data->unk2; break;
                        case 2: data->unk2 = 7; data->unk0 = data->unk2; break;
                    }
                } else {
                    data->unk2 = 10000; data->unk0 = data->unk2;
                }
                data->unk6 = 0;
                if (!data->unk44) {
                    func_80108B04(arg0, 1);
                }
            }
            break;
        case 29:
            func_800FDC28(0);
            func_80802FCC_chklungo(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803BD0_chklungo);
            func_808018D4_chklungo(arg0);
            func_808025CC_chklungo(arg0, 5);
            func_8010A570(arg0);
            func_80101180(0x423, 0x4F, 0);
            func_800DA544(data->unk8 + 0x318);
            break;
        case 30:
            func_808025CC_chklungo(arg0, 6);
            func_80101180(0x41F, 7, 0);
            func_80101180(0x420, 7, 0);
            break;
        case 31:
            func_808025CC_chklungo(arg0, 7);
            arg0->unk58 = 1.4f;
            break;
        case 33:
            arg0->unk58 = 3.0f;
            break;
        case 34:
            func_80802588_chklungo(arg0, 3, 1);
            func_80803158_chklungo(arg0, D_808038A0_chklungo[data->unk8].dialog[2], 0xE);
            break;
        case 35:
            func_808025CC_chklungo(arg0, 8);
            func_80803158_chklungo(arg0, D_808038A0_chklungo[data->unk8].dialog[3], 0x44);
            break;
    }
    func_80109FE8((void **)arg0, sp38);
    if (sp34) {
        func_80803000_chklungo(arg0);
    }
}

void func_808020F0_chklungo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    f32 func_800DC178(f32, f32);
    struct {
        u8 pad0[8];
        s16 unk8;
        u8 padA[10];
        f32 unk14;
        s16 unk18;
    } *data;

    data = func_80100094(arg0, 0);
    data->unk18 = arg1;
    switch (arg1) {
        case 0:
            _subaddiefade_entrypoint_1(arg0, 255);
            break;
        case 2:
            switch (data->unk8) {
                case 0:
                    data->unk14 = func_800DC178(1.0f, 2.0f);
                    break;
                case 1:
                    data->unk14 = func_800DC178(2.0f, 3.0f);
                    break;
                case 2:
                    data->unk14 = func_800DC178(3.0f, 4.0f);
                    break;
            }
            break;
        case 4:
            data->unk14 = func_800DC178(1.5f, 2.0f);
            break;
    }
}

void func_8080220C_chklungo(Actor *arg0) {
    s32 func_800D9078(f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_8080231C_chklungo(Actor *, f32, f32);
    s32 func_808023A4_chklungo(Actor *, f32, f32);
    void func_80802F58_chklungo(Actor *);
    struct {
        u8 unk0[0x14];
        f32 unk14;
        u16 unk18;
    } *data;

    data = func_80100094(arg0, 0);
    switch (data->unk18) {
        case 0:
            break;
        case 1:
            if (func_8080231C_chklungo(arg0, 0.0f, 150.0f)) {
                func_808020F0_chklungo(arg0, 2);
            }
            break;
        case 2:
            if (func_800D9078(&data->unk14)) {
                func_80802F58_chklungo(arg0);
                func_808020F0_chklungo(arg0, 3);
            }
            break;
        case 3:
            if (func_808023A4_chklungo(arg0, 48.0f, 150.0f)) {
                func_808020F0_chklungo(arg0, 4);
            }
            break;
        case 4:
            if (func_800D9078(&data->unk14)) {
                func_808020F0_chklungo(arg0, 1);
            }
            break;
        case 5:
            if (func_808023A4_chklungo(arg0, 255.0f, 150.0f)) {
                func_808020F0_chklungo(arg0, 0);
            }
            break;
    }
}

s32 func_8080231C_chklungo(Actor *arg0, f32 arg1, f32 arg2) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    f32 func_800D8FF8(void);
    s32 sp1C;
    f32 var_f2;

    sp1C = 0;
    var_f2 = (f32) _subaddiefade_entrypoint_0(arg0);
    var_f2 -= func_800D8FF8() * arg2;
    if (var_f2 < arg1) {
        var_f2 = arg1;
        sp1C = 1;
    }
    _subaddiefade_entrypoint_1(arg0, (s32) var_f2);
    return sp1C;
}

/* extern */

s32 func_808023A4_chklungo(Actor *arg0, f32 arg1, f32 arg2) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    f32 func_800D8FF8(void);
    s32 sp1C;
    f32 var_f2;

    sp1C = 0;
    var_f2 = (f32) _subaddiefade_entrypoint_0(arg0);
    var_f2 += func_800D8FF8() * arg2;
    if (arg1 < var_f2) {
        var_f2 = arg1;
        sp1C = 1;
    }
    _subaddiefade_entrypoint_1(arg0, (s32) var_f2);
    return sp1C;
}

s32 func_8080242C_chklungo(void) {
    s32 func_800EA05C();

    s8 *var_a0;
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800EA05C();
    var_a0 = &D_808038A0_chklungo;
    var_v1 = 0;
loop_1:
    if (temp_v0 == *(s16 *) var_a0) {
        return var_v1;
    }
    var_v1 += 1;
    var_a0 += 0x84;
    if (var_v1 == 3) {
        return -1;
    }
    goto loop_1;
}

s32 func_80802480_chklungo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);

    struct KlungoLookupData {
        u8 pad0[8];
        s16 unk8;
    };
    s32 i;
    s32 value;
    s32 *table;

    table = (s32 *)((u8 *)&D_808038A0_chklungo +
        ((struct KlungoLookupData *)func_80100094(arg0, 0))->unk8 * 0x84);
    for (i = 0; i != 10; i++) {
        value = arg1 == table[i * 2 + 2];
        if (value) {
            return i;
        }
    }
    return -1;
}

s32 func_80802558_chklungo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    return _susubgame_entrypoint_4(arg0, (BtIntPtr)func_80100094(arg0, 0U) + 0x88);
}

void func_80802588_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    _susubgame_entrypoint_5(arg0, (u8 *)func_80100094(arg0, 0U) + 0x88, arg1, arg2, 0);
}    typedef struct { u8 pad0[0x8]; s16 unk8; } Objklungo_func_808025CC_chklungo_data; /* offsets.py genstruct: fields from raw offsets on data; rename once understood */

void func_808025CC_chklungo(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);

    void *data;
    BT_NATIVE_ONLY(KlungoRound) BT_IDO_ONLY(s32) *entry;
    s32 a3;
    s32 a2;

    data = func_80100094(arg0, 0U);
    entry = BT_DATA_FIELD(&D_808038A0_chklungo[((Objklungo_func_808025CC_chklungo_data *)data)->unk8].rounds[arg1], (s32 *)((u8 *)&D_808038A0_chklungo + (((Objklungo_func_808025CC_chklungo_data *)data)->unk8 * 0x84) + (arg1 * 8)));
    a3 = BT_DATA_FIELD(entry->options, entry[3]);
    a2 = BT_DATA_FIELD(entry->action, entry[2]);
    _susubgame_entrypoint_6(arg0, (u8 *)data + 0x88, a2, a3, 0);
}

void func_80802634_chklungo(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    extern s16 D_80803BE0_chklungo[5];
    extern s16 D_80803BEC_chklungo[7];
    extern s16 D_80803BFC_chklungo[7];
    extern s16 D_80803C0C_chklungo[8];
    extern f32 D_80803C1C_chklungo[4];
    extern f32 D_80803C2C_chklungo[4];
    f32 *temp_s1;

    temp_s1 = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80803BE0_chklungo, 0.2f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80803BEC_chklungo, 0.78f);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80803C0C_chklungo, D_80803C2C_chklungo);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80803BFC_chklungo, D_80803C1C_chklungo);
}

void func_808026CC_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    extern s16 D_80803C3C_chklungo[11];
    extern f32 D_80803C54_chklungo[6];
    if (func_80101E4C(arg0, D_80803C54_chklungo) != 0) {
        func_80018820(0, 0.8f, 0.3f);
        func_800E15CC(0, 5.0f, 0.7f);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803C3C_chklungo);
        return;
    }
    if (func_80101E14(arg0, 0.7f) != 0) {
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 10.0f, 0.8f);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803C3C_chklungo);
    }
}

void func_80802798_chklungo(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    extern Actor *_chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw);
    void func_800EE7F8(f32 *, f32 *);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern s16 D_80803C6C_chklungo[4];
    extern s16 D_80803C74_chklungo[7];
    f32 position[3];

    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80803C74_chklungo, 0.7f);
    if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80803C6C_chklungo, 0.8f)) {
        func_800EE7F8(position, arg0->position);
        position[1] += 80.0f;
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 5, *(s32 *)&position[0], *(s32 *)&position[1], *(s32 *)&position[2], *(s32 *)&arg0->rotation[1]);
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 10.0f, 0.8f);
    }
}

void func_80802864_chklungo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8, f32[3], s32 *);
    extern s16 D_80803C84_chklungo[10];
    u8 *data;

    if (func_80101E14(arg0, 0.0f) != 0) {
        data = func_80100094(arg0, 0);
        if (data[0x48] == 0) {
            data[0x48] = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
        }
        func_800C4350(data[0x48], arg0->position, (s32 *)D_80803C84_chklungo);
        func_800C3BDC(data[0x48]);
    }
}

void func_808028E8_chklungo(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    extern s16 D_80803C98_chklungo[8];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80803C98_chklungo, 0.0f);
}

void func_80802914_chklungo(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    extern s16 D_80803CA8_chklungo[7];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80803CA8_chklungo, 0.0f);
}

void func_80802940_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_8080299C_chklungo();
    extern s16 D_80803CB8_chklungo[4];
    func_8080299C_chklungo();
    func_80018820(0, 1.0f, 0.4f);
    func_800E15CC(0, 10.0f, 0.8f);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803CB8_chklungo);
}

s32 func_8080299C_chklungo(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    BtIntPtr func_800B53A4(s32);
    void func_800BAB80(BtIntPtr, void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s16[]);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);

    extern s16 D_80803CC0_chklungo[26];
    BtIntPtr particles;
    s32 i;
    f32 sp74[3];
    s16 *data;

    data = func_80100094(arg0, 0);
    particles = func_800B53A4(8);
    func_800BAB80(particles, D_808038A0_chklungo[data[4]].color);
    for (i = 0; i != 8; i++) {
        func_800EEB9C(sp74, (f32)i * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(sp74, arg0->position);
        sp74[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(particles, sp74, arg0->position, 1.0f, D_80803CC0_chklungo);
    }
    BT_NATIVE_ONLY(return 0;) }

void func_80802B10_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_8080299C_chklungo();
    /* This cue ends in bytes also used by the potion order table. */
    if (func_80101E14(arg0, 0.8f) != 0) {
        func_8080299C_chklungo(arg0);
        func_800E15CC(0, 30.0f, 0.9f);
        func_80018820(0, 1.5f, 0.6f);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, KLUNGO_POTION_CUE);
    }
}

s32 func_80802B84_chklungo(Actor *arg0, s32 arg1) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80100120(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102FDC(Actor *, f32);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_801084B0(BtIntPtr, Actor **);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_8010A800(Actor *, s32);


    s16 *data;
    Actor *spawned;
    f32 pos0[3];
    s32 pad;
    f32 pos1[3];
    Actor *clone;
    s16 *cloneData;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0:
            if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, pos0) == 0) {
                func_80103DFC(arg0, pos0);
            }
            spawned = func_80108528(0x422, pos0, (s32)arg0->rotation[1], &arg0);
            spawned->rotation[0] = 180.0f;
            if (func_800DA298(0x683)) {
                ((f32 *)spawned->actorData)[3] = D_808038A0_chklungo[data[4]].spawnSpeed;
            } else {
                ((f32 *)spawned->actorData)[3] = 0.3f;
            }
            if (!func_800DA298(0x684)) {
                spawned->unk58 = D_808038A0_chklungo[data[4]].spawnScale;
            } else {
                spawned->unk58 = 0.2f;
            }
            func_80102FDC(spawned, arg0->scale);
            data[3] = 1;
            break;
        case 1:
            func_80103DFC(arg0, pos1);
            func_80102FDC(func_80108528(0x421, pos1, 0, &arg0), arg0->scale * 1.4f);
            data[34] = 1;
            break;
        case 2:
            if (arg0->unk70_10 != 0x14) {
                func_8010A800(arg0, 0);
                return BT_NATIVE_ONLY(0);
            }
            clone = func_801084B0(0x41E, &arg0);
            if (clone->unk70_25 == 0) {
                func_800FFAB0(clone);
                func_80101180(0x41E, 10, 0);
                return BT_NATIVE_ONLY(0);
            }
            cloneData = func_80100094(clone, 0);
            data[15] ^= 1;
            cloneData[13] = 1;
            func_80100120(clone);
            func_80102FDC(clone, arg0->scale);
            func_80801964_chklungo(clone, data[15] == 0 ? 0x16 : 0x15);
            break;
    }
    BT_NATIVE_ONLY(return 0;) }

u8 func_80802DF4_chklungo(Actor *arg0) {
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    s32 func_800DA980(s32, s32);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    BT_IDO_ONLY(extern u8 D_80803D01_chklungo[][3];)
    BT_IDO_ONLY(extern u8 D_80803D04_chklungo[];)
    s32 sp2C;
    s32 sp28;
    s32 selected;
    s32 value;
    s32 i;
    s32 count;
    u8 *entry;
    u8 result;
    struct {
        u8 pad0[8];
        s16 unk8;
    } *data;

    data = func_80100094(arg0, 0);
    sp2C = data->unk8;
    sp28 = func_800DA564(0x315, 3);
    if (sp28 == 0) {
        if (func_800D395C() != 0) {
            selected = func_800DC128(0, func_800DA980(0xC08, 3));
            i = 0;
            count = 0;
            do {
                if (func_800DA298(i + 0xC08) != 0) {
                    if (count == selected) {
                        break;
                    }
                    count++;
                }
                i++;
            } while (i < 3);
            value = i + 1;
            i = 0;
            entry = BT_DATA_FIELD(KLUNGO_ORDER_BYTES + 3, D_80803D04_chklungo) + sp2C;
            do {
                if (value == *entry) {
                    sp28 = i + 1;
                    break;
                }
                i++;
                entry += 3;
            } while (i != 6);
            func_800DA7A8(0x315, sp28, 3);
        } else {
            sp28 = func_800DC128(0, 6) + 1;
            func_800DA7A8(0x315, sp28, 3);
        }
    }
    result = BT_DATA_FIELD(KLUNGO_ORDER_BYTES[3 * sp28 + sp2C], D_80803D01_chklungo[sp28][sp2C]);
    return result;
}

void func_80802F30_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern s16 D_80803D18_chklungo[8];
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803D18_chklungo);
}

void func_80802F58_chklungo(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800C0638(void);
    void *func_80100094(Actor *, u32);
    s32 func_80803158_chklungo(Actor *, s32, s32);
    extern s16 D_80803D28_chklungo[7];
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80803D28_chklungo);
    if ((*(s16 *)(sp1C + 0x24) == 0) && (func_800C0638() == 0)) {
        func_80803158_chklungo(arg0, 0x1630, 0x44);
        *(s16 *)(sp1C + 0x24) = 1;
    }
}    typedef struct { u8 pad0[0x48]; u8 unk48; } Objklungo_func_80802FCC_chklungo_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { u8 pad0[0x48]; u8 unk48; } Objklungo_func_80802FCC_chklungo_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80802FCC_chklungo(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (((Objklungo_func_80802FCC_chklungo_sp1C *)sp1C)->unk48) = _subaddieaudioloop_entrypoint_3((((Objklungo_func_80802FCC_chklungo_temp_v0 *)temp_v0)->unk48));
}    typedef struct { u8 pad0[0x46]; s16 unk46; } Objklungo_func_80803000_chklungo_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { u8 pad0[0x46]; s16 unk46; } Objklungo_func_80803000_chklungo_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80803000_chklungo(Actor *arg0) {
    u32 func_800F54E4(void);
    void* func_80100094(Actor*, u32);
    BT_IDO_ONLY(s32 func_800F4AF4(u32, s32);) BT_NATIVE_ONLY(s32 func_800F4AF4(s32, s32);)
    void func_808030A4_chklungo(Actor *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((((Objklungo_func_80803000_chklungo_temp_v0 *)temp_v0)->unk46) == 0) {
        func_800F4AF4(func_800F54E4(), 0x14);
        (((Objklungo_func_80803000_chklungo_sp1C *)sp1C)->unk46) = 1;
    }
    func_808030A4_chklungo(arg0);
}    typedef struct { u8 pad0[0x46]; s16 unk46; } Objklungo_func_8080305C_chklungo_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { u8 pad0[0x46]; s16 unk46; } Objklungo_func_8080305C_chklungo_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_8080305C_chklungo(Actor *arg0) {
    u32 func_800F54E4(void);
    void* func_80100094(Actor*, u32);
    void func_800F4B20(BtIntPtr arg0);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((((Objklungo_func_8080305C_chklungo_temp_v0 *)temp_v0)->unk46) != 0) {
        func_800F4B20(func_800F54E4());
        (((Objklungo_func_8080305C_chklungo_sp1C *)sp1C)->unk46) = 0;
    }
}

void func_808030A4_chklungo(Actor *arg0) {
    s32 _plcamera_entrypoint_10(BtIntPtr);
    void _plcamera_entrypoint_9(BtIntPtr, f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800F5EF8(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(u32));
    void *func_80100094(Actor *, u32);
    BtIntPtr func_80110014(s32 *);
    void func_80116088(u8 *, BtIntPtr);
    struct {
        u8 padding[0x46];
        s16 cameraActive;
    } *data;
    f32 position[3];

    data = func_80100094(arg0, 0);
    if (data->cameraActive != 0) {
        if (_plcamera_entrypoint_10(func_800F54E4()) != 0x14) {
            data->cameraActive = 0;
            return;
        }
        func_800EE7F8(position, arg0->position);
        position[1] += 400.0f;
        _plcamera_entrypoint_9(func_800F54E4(), position, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(func_800F54E4())), position);
    }
}

s32 func_80803158_chklungo(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    return _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0xAB);
}

/* extern */

void func_8080318C_chklungo(Actor *arg0) {
    void func_80101CDC(Actor*, f32);
    f32 func_8010203C(Actor *, u32);
    f32 sp1C;

    sp1C = 300.0f / *(f32 *)((s8 *)arg0 + 0x24);
    func_80101CDC(arg0, func_8010203C(arg0, arg0->unk70_10) * sp1C);
}

f32 func_808031E4_chklungo(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = *(f32 *)((s8 *)(arg0) + 0x24) / 300.0f;
    temp_f2 = 400.0f;
    return temp_f2 * temp_f0;
}

void func_80803208_chklungo(s32 *arg0) {
    s32 func_80105230();
    extern f32 D_80803D38_chklungo[3];
    func_80105230(arg0, D_80803D38_chklungo);
}

void func_8080322C_chklungo(Actor *arg0, f32 arg1) {
    s32 func_800CC338(s32 *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_8010D09C(BtIntPtr, f32 *, f32);
    s32 func_80803304_chklungo(Actor *, f32 *);
    BtIntPtr func_80803390_chklungo(void *, f32 *);
    void func_80803464_chklungo(BtIntPtr, void *, f32 *, f32 *);
    struct KlungoNavigation {
        u32 reserved[28];
        BT_BITFIELD_ORDER(u32 region : 7, u32 reserved73 : 4);
        BT_BITFIELD_ORDER(u32 reserved70 : 15, u32 area : 6);
        BT_BITFIELD_ORDER(u32 area : 6, u32 reserved70 : 15);
        BT_BITFIELD_ORDER(u32 reserved73 : 4, u32 region : 7);
    };
    f32 sp2C[3];
    register f32 *sp20;

    func_8010D09C(func_800F54E4(), sp2C, arg1);
    if (func_80803304_chklungo(arg0, sp2C)) {
        if (func_800CC338(sp2C, ((struct KlungoNavigation *)arg0)->region - 1,
                         ((struct KlungoNavigation *)arg0)->area - 1) != -1) {
            func_800EE7F8((f32 *)arg0->actorData, sp2C);
            return;
        }
    }
    func_80803464_chklungo((BtIntPtr)arg0,
        (void *)func_80803390_chklungo(arg0, sp2C), sp2C,
        sp20 = (f32 *)arg0->actorData);
    if (!func_80803304_chklungo(arg0, sp20)) {
        func_800EE7F8(sp20, arg0->position);
    }
}

s32 func_80803304_chklungo(Actor *arg0, f32 arg1[3]) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg1);
    func_800EE7F8(sp28, arg1);
    sp34[1] = arg0->position[1] + 500.0f;
    sp28[1] = arg0->position[1] - 500.0f;
    if (func_800C6A7C(sp34, sp28, sp1C, 0x20020) == 0) {
        return 0;
    }
    arg1[1] = sp28[1];
    return 1;
}

/* extern */

BtIntPtr func_80803390_chklungo(void *arg0, f32 *arg1) {
    s32 func_800CC5F4(s32);
    BtIntPtr func_800CC63C(s32, s32);
    f32 func_800EEB40(s32, f32 *);
    f32 temp_f20;
    s32 temp_v0;
    BtIntPtr temp_v0_2;
    s32 var_s0;
    BtIntPtr var_s2;

    temp_v0 = func_800CC5F4(((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) - 1);
    var_s2 = 0;
    var_s0 = 0;
    if (temp_v0 > 0) {
        do {
            temp_v0_2 = func_800CC63C(((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) - 1, var_s0);
            if ((var_s2 == 0) || (temp_f20 = func_800EEB40(temp_v0_2, arg1), (temp_f20 < func_800EEB40(var_s2, arg1)))) {
                var_s2 = temp_v0_2;
            }
            var_s0 += 1;
        } while (var_s0 < temp_v0);
    }
    return var_s2;
}    typedef struct { u8 pad0[0xC]; s16 unkC; } Objklungo_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

void func_80803464_chklungo(BtIntPtr arg0, void *arg1, f32 *arg2, f32 *arg3) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(void *, f32 *);
    f32 sp1C;

    sp1C = func_800F1DF4(arg1, arg2);
    func_800EE7F8(arg3, arg1);
    func_800EF1B8(arg3, sp1C, (f32) (((Objklungo_arg1 *)arg1)->unkC));
}
#include "klungo_tail_data.inc"
s32 func_808034CC_chklungo(void *arg0) {
    s32 func_800CBD84(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];
    f32 *sp18;

    sp18 = &((Actor *)arg0)->position[0];
    func_800EE7F8(sp2C, sp18);
    func_800EF1B8(sp2C, ((Actor *)arg0)->rotation[1] + 90.0f, 150.0f);
    if (func_800CBD84(sp2C) == -1) {
        return 0;
    }
    func_800EE7F8(sp20, sp18);
    func_800EF1B8(sp20, ((Actor *)arg0)->rotation[1] - 90.0f, 150.0f);
    if (func_800CBD84(sp20) == -1) {
        return 0;
    }
    return 1;
}
