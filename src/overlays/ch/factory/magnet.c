#include "common.h"

void func_80800000_chfactorymagnet(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    f32 func_800EFC7C(void *, void *);
    void func_800FFA88(Unk80132ED0 *);
    void func_80801508_chfactorymagnet(Actor *, s32);
    Prop *props[3];
    Prop *center[2];
    f32 position[3];
    f32 first[3];
    f32 second[3];
    f32 third[3];
    f32 distances[3];
    s32 i;
    s32 j;
    f32 temp;

    if (_gccubesearch_entrypoint_9(0x299, props, 3) != 3) {
        func_800FFA88(arg0->unk0);
        return;
    }
    if (_gccubesearch_entrypoint_9(0x3FC, center, 1) == 0) {
        func_800FFA88(arg0->unk0);
        return;
    }
    _gspropctrl_entrypoint_11(props[0], first);
    _gspropctrl_entrypoint_11(props[1], second);
    _gspropctrl_entrypoint_11(props[2], third);
    _gspropctrl_entrypoint_11(center[0], position);
    distances[0] = func_800EFC7C(position, first);
    distances[1] = func_800EFC7C(position, second);
    distances[2] = func_800EFC7C(position, third);
    for (i = 0; i < 2; i++) {
        for (j = i; j < 3; j++) {
            if (distances[j] < distances[i]) {
                temp = distances[j];
                distances[j] = distances[i];
                distances[i] = temp;
            }
        }
    }
    ((f32 *)arg0->actorData)[4] = distances[0];
    ((f32 *)arg0->actorData)[5] = distances[1];
    ((f32 *)arg0->actorData)[6] = distances[2];
    for (i = 0; i != 30; i++) {
        func_80801508_chfactorymagnet(arg0, i);
    }
}

void func_80800224_chfactorymagnet(Actor *arg0) {
    s32 _chmrtannoy_entrypoint_0(void);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sumumbofx_entrypoint_14(BtIntPtr);
    s32 _sumumbofx_entrypoint_27(BtIntPtr);
    s32 _sumumbofx_entrypoint_5(BtIntPtr, s32);
    void func_800CE88C(s32, s32);
    s16 func_800CEA84(s32);
    s32 func_800CEAA8(s32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    s32 func_800D91EC(u8 *, f32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F8418(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_80108B04(Actor *, s32);
    void func_8080083C_chfactorymagnet(BtIntPtr);
    void func_80800898_chfactorymagnet(Actor *, s32);
    void func_80800FE8_chfactorymagnet(Actor *);
    s32 func_808012E4_chfactorymagnet(BtIntPtr, f32);
    void func_80801368_chfactorymagnet(u8 *);
    void func_80801460_chfactorymagnet(Actor *, BtIntPtr);
    void func_80801B74_chfactorymagnet(Actor *);
    f32 sp54[3];
    f32 sp48[3];
    BtIntPtr sp44;
    BtIntPtr sp40;
    BtIntPtr sp3C;
    BtIntPtr sp38;
    BtIntPtr sp34;

    switch (arg0->unk70_10) {
    case 1:
        if (func_808012E4_chfactorymagnet((BtIntPtr)arg0, ((f32 *)arg0->actorData)[5])) {
            func_80800898_chfactorymagnet(arg0, 2);
        }
        break;
    case 2:
        if (func_800D91EC(&arg0->unk58, 1.0f)) {
            func_80800898_chfactorymagnet(arg0, func_800DA298(0x19E) ? 3 : 4);
        }
        break;
    case 3:
        func_8080083C_chfactorymagnet((BtIntPtr)arg0);
        if (func_808012E4_chfactorymagnet((BtIntPtr)arg0, ((f32 *)arg0->actorData)[4])) {
            func_80800898_chfactorymagnet(arg0, 4);
        } else if (!func_808012E4_chfactorymagnet((BtIntPtr)arg0, ((f32 *)arg0->actorData)[5])) {
            func_80800898_chfactorymagnet(arg0, 5);
        }
        break;
    case 4:
        if (func_808012E4_chfactorymagnet((BtIntPtr)arg0, ((f32 *)arg0->actorData)[6])) {
            func_800F5A00(func_800F54E4(), sp54);
            func_800EFB24(sp48, sp54, arg0->position);
            func_800D90A4((f32 *)arg0->actorData);
            func_800EF334(sp48, func_800F10B4(((f32 *)arg0->actorData)[0], 20.0f, 0.0f, 1.0f, 0.5f));
            func_800EF04C(sp48, arg0->position);
            func_800F8418(func_800F54E4(), sp48);
        } else {
            func_80800898_chfactorymagnet(arg0, 5);
        }
        func_8080083C_chfactorymagnet((BtIntPtr)arg0);
        break;
    case 5:
        if (func_808012E4_chfactorymagnet((BtIntPtr)arg0, ((f32 *)arg0->actorData)[5])) {
            func_80800898_chfactorymagnet(arg0, 2);
        } else if (--arg0->unk6C_0 == 0) {
            func_80800898_chfactorymagnet(arg0, 6);
        }
        break;
    case 6:
        if (func_808012E4_chfactorymagnet((BtIntPtr)arg0, ((f32 *)arg0->actorData)[5])) {
            func_80800898_chfactorymagnet(arg0, 2);
        } else if (func_800D90A4(&arg0->unk58)) {
            func_80800898_chfactorymagnet(arg0, 1);
        }
        break;
    case 7:
        if (func_800DA298(0x9DE)) {
            func_80800898_chfactorymagnet(arg0, 8);
        }
        break;
    case 8:
        sp44 = (BtIntPtr)func_80100094(arg0, 0);
        func_80801460_chfactorymagnet(arg0, sp44);
        _sumumbofx_entrypoint_14(sp44);
        if (_sumumbofx_entrypoint_27(sp44)) {
            func_80800898_chfactorymagnet(arg0, 9);
        }
        break;
    case 9:
        sp40 = (BtIntPtr)func_80100094(arg0, 0);
        func_80801460_chfactorymagnet(arg0, sp40);
        _sumumbofx_entrypoint_14(sp40);
        _sumumbofx_entrypoint_5(sp40, 0x40400000);
        if (_sumumbofx_entrypoint_27(sp40)) {
            func_80800898_chfactorymagnet(arg0, 11);
        }
        break;
    case 11:
        sp3C = (BtIntPtr)func_80100094(arg0, 0);
        func_80801460_chfactorymagnet(arg0, sp3C);
        _sumumbofx_entrypoint_14(sp3C);
        func_800D91EC(&arg0->unk58, 1.0f);
        if (_sumumbofx_entrypoint_27(sp3C)) {
            func_800DA544(0x9DF);
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1337, 4, arg0->position, 0xA3);
            func_80800898_chfactorymagnet(arg0, 12);
        }
        break;
    case 12:
        sp38 = (BtIntPtr)func_80100094(arg0, 0);
        func_80801460_chfactorymagnet(arg0, sp38);
        _sumumbofx_entrypoint_14(sp38);
        func_80801368_chfactorymagnet(arg0);
        if (func_800DA298(0x1B8) || !func_800DA298(0xA06) ||
            (func_800CEAA8(0) && func_800CEA84(0) < 5.0f)) {
            func_80800898_chfactorymagnet(arg0, 13);
        }
        break;
    case 13:
        sp34 = (BtIntPtr)func_80100094(arg0, 0);
        func_80801460_chfactorymagnet(arg0, sp34);
        _sumumbofx_entrypoint_14(sp34);
        func_80801368_chfactorymagnet(arg0);
        if (_sumumbofx_entrypoint_27(sp34)) {
            func_80800898_chfactorymagnet(arg0, 14);
        }
        break;
    case 14:
        if (func_808012E4_chfactorymagnet((BtIntPtr)arg0, ((f32 *)arg0->actorData)[5]) && !func_800DA298(0x1B8)) {
            func_800DA524(0xA06);
            func_800DA524(0x9DE);
            func_80800898_chfactorymagnet(arg0, 2);
        } else {
            arg0->unk58 -= func_800D8FF8() * 0.5f;
            if (arg0->unk58 <= 0.0f) {
                func_80800898_chfactorymagnet(arg0, 15);
            }
        }
        break;
    case 15:
        if (func_800D90A4(&((f32 *)arg0->actorData)[1])) {
            func_80800898_chfactorymagnet(arg0, 16);
        }
        break;
    case 16:
        if (func_800CEAA8(0)) {
            func_800CE88C(0, 0);
        }
        if (func_800DA298(0x1B8)) {
            if (func_800D91EC(&arg0->unk58, 1.0f)) {
                func_80800898_chfactorymagnet(arg0, 17);
            }
        } else if (func_800D91EC(&arg0->unk58, 0.4f)) {
            func_80800898_chfactorymagnet(arg0, 6);
        }
        func_800DA524(0xA06);
        func_800DA524(0x9DE);
        break;
    case 17:
        func_80103110(arg0, 0);
        if (func_800D90A4((f32 *)arg0->actorData)) {
            ((f32 *)arg0->actorData)[0] = func_800DC178(2.0f, 20.0f);
            func_80108B04(arg0, 1);
        }
        break;
    }
    if (*(volatile f32 *)&arg0->actorData[7] != *(volatile f32 *)&arg0->unk58 && arg0->unk3C) {
        func_80800FE8_chfactorymagnet(arg0);
    }
    func_80801B74_chfactorymagnet(arg0);
    ((f32 *)arg0->actorData)[7] = arg0->unk58;
}

/* extern */

void func_8080083C_chfactorymagnet(BtIntPtr arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800F4EC8(BtIntPtr, s32 *, f32, f32, f32);
    BtUIntPtr func_800F54E4(void);
    s32 sp24[3];

    func_800EE7F8(sp24, _subaddiefind_entrypoint_2(0x3FC, 0)->position);
    func_800F4EC8(func_800F54E4(), sp24, 500.0f, 0.0f, 200.0f);
}

void func_80800898_chfactorymagnet(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chglowbo_entrypoint_6(void);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_18(void *, f32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_8010A624(Actor *);
    void func_8010A63C(Actor *);
    void func_8010A800(Actor *, s32);
    void *func_80800E40_chfactorymagnet(Actor *);
    void func_80801CD8_chfactorymagnet(Actor *);
    void *sp24;

    switch (arg1) {
    case 1:
        arg0->unk58 = 0.0f;
        func_8010A624(arg0);
        break;
    case 2:
        func_8010A63C(arg0);
        break;
    case 4:
        func_80101180(0x50F, 0xA, 0);
        arg0->unk58 = 1.0f;
        ((f32 *)arg0->actorData)[0] = 20.0f;
        if (func_800DA298(0x19E) == 0) {
            _capod_entrypoint_13(arg0->unk0, 0, 0, 0x850);
        }
        break;
    case 5:
        func_80101180(0x50F, 0x4F, 0);
        arg0->unk6C_0 = 0x3C;
        if (arg0->unk70_10 == 4) {
            func_80801CD8_chfactorymagnet(arg0);
        }
        break;
    case 6:
        if (func_800DA298(0x19E) == 0) {
            func_800DA544(0x19E);
        }
        break;
    case 8:
        sp24 = func_80800E40_chfactorymagnet(arg0);
        _capod_entrypoint_13(arg0->unk0, 0, 2, 0x10);
        func_800DA544(0xA06);
        func_80101180(0x2B0, 0xBB, 0xA);
        _sumumbofx_entrypoint_15(sp24, 3.0f);
        func_800DA544(0x57E);
        func_8010A63C(arg0);
        break;
    case 9:
        _sumumbofx_entrypoint_18(func_80100094(arg0, 0), 3.0f);
        _chglowbo_entrypoint_6();
        break;
    case 11:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 0), 2.0f);
        func_8010A63C(arg0);
        break;
    case 12:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 0), 2.0f);
        break;
    case 13:
        _sumumbofx_entrypoint_16(func_80100094(arg0, 0), 4.0f);
        break;
    case 14:
        func_80100094(arg0, 0);
        _sumumbofx_entrypoint_1(arg0, 0);
        func_8010A800(arg0, 0);
        break;
    case 15:
        ((f32 *)arg0->actorData)[1] = 1.5f;
        break;
    case 17:
        func_8010A63C(arg0);
        arg0->unk58 = 1.0f;
        ((f32 *)arg0->actorData)[7] = 1.0f;
        ((f32 *)arg0->actorData)[0] = func_800DC178(2.0f, 20.0f);
        break;
    }
    func_80101FDC(arg0, arg1);
}

s32 func_80800B20_chfactorymagnet(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void _sumumbofx_entrypoint_3(void *, f32);
    void _sumumbofx_entrypoint_4(void *);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, BtIntPtr, BtIntPtr);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    f32 func_800DC178(f32, f32);
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_80103EAC(Actor *);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80108B04(Actor *, s32);
    void *func_80800E40_chfactorymagnet(Actor *);
    void func_80801A9C_chfactorymagnet(BtIntPtr, f32 *, f32 *);
    void func_80801AE8_chfactorymagnet(Actor *);
    extern f32 D_80802910_chfactorymagnet[3];
#ifdef BT_NATIVE
    void chfactorymagnet_entrypoint_0(s32 arg0, s32 arg1);
#else
    extern void _chfactorymagnet_entrypoint_0(void);
#endif
    Actor *sp4C;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    Actor *sp2C;
    void *sp28;

    switch (arg1) {
    case 0x4B:
        func_80800898_chfactorymagnet(arg0, 7);
        return 1;
    case 0x30:
        if (*(s16 *)&arg2 == 0x1337) {
            return 0x5A;
        }
        return 0;
    case 0xB:
        if (arg2 == 2) {
            func_800CE8D8(0, 90.0f, 0x5A);
            func_800CE928(0, (BtIntPtr)_chfactorymagnet_entrypoint_0, (BtIntPtr)arg0->unk0);
            func_800CE88C(0, 1);
        }
        return 3;
    case 0x3D:
        switch (arg2) {
        case 0:
            sp4C = func_80108528(0x3F6, D_80802910_chfactorymagnet, 0, &arg0);
            sp4C->unk3C = arg0->unk0;
            arg0->unk3C = sp4C->unk0;
            func_80801A9C_chfactorymagnet((BtIntPtr)arg0, NULL, sp40);
            func_80108528(0x50F, sp40, 0, &arg0)->scale = arg0->scale;
            break;
        case 1:
            sp30 = func_800DC178(0.0f, 360.0f);
            func_80801A9C_chfactorymagnet((BtIntPtr)arg0, NULL, sp34);
            func_800EF214(sp34, func_800DC178(0.0f, 360.0f), sp30, func_80103EAC(arg0));
            sp4C = func_80108528(0x52F, sp34, 0, &arg0);
            sp4C->scale = arg0->scale;
            sp4C->rotation[1] = func_800DC178(160.0f, 200.0f) + sp30;
            sp4C->rotation[0] = func_800DC178(-20.0f, 20.0f);
            sp4C->unk58 = ((f32 *)sp4C->actorData)[7] = func_800DC178(0.5f, 1.25f);
            break;
        }
        return 1;
    case 0x95:
        sp2C = _subaddiefind_entrypoint_2(0x3F6, 0);
        *(s8 *)&arg0->actorData[3] = 0;
        *(s8 *)&arg0->unk54 = 0;
        func_80801AE8_chfactorymagnet(arg0);
        if (sp2C == NULL) {
            func_80108B04(arg0, 0);
            arg0->unk3C = NULL;
        } else {
            arg0->unk3C = sp2C->unk0;
        }
        if (func_800DA298(0xA06)) {
            sp28 = func_80800E40_chfactorymagnet(arg0);
            _sumumbofx_entrypoint_4(sp28);
            _sumumbofx_entrypoint_3(sp28, 10.0f);
            func_80800898_chfactorymagnet(arg0, 12);
            if (func_800DA298(0x1B8)) {
                func_800DA524(0xA06);
            }
        } else if (func_800DA298(0x1B8)) {
            func_80800898_chfactorymagnet(arg0, 17);
        } else {
            func_80800898_chfactorymagnet(arg0, 1);
        }
        return 1;
    }
    return 0;
}

/* extern */

void *func_80800E40_chfactorymagnet(Actor *arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_2(void *);
    s32 _sumumbofx_entrypoint_24(void *, s32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 _sumumbofx_entrypoint_28(void *, f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_8010A800(Actor *, s32);
    void *temp_v0;
    s32 sp28[3];

    sp28[0] = 0;
    sp28[1] = 0;
    sp28[2] = 0;
    _sumumbofx_entrypoint_0(arg0, 0, 0x28, _chmumbopad_entrypoint_0(0xA));
    temp_v0 = func_80100094(arg0, 0);
    _sumumbofx_entrypoint_2(temp_v0);
    _sumumbofx_entrypoint_25(temp_v0, 0x8C, sp28);
    _sumumbofx_entrypoint_24(temp_v0, 0x3F266666);
    func_8010A800(arg0, 2);
    _sumumbofx_entrypoint_28(temp_v0, arg0->position, 2000.0f, 4000.0f);
    return temp_v0;
}

void func_80800EF0_chfactorymagnet(Actor *arg0, s32 arg1) {
    s32 _sumumbofx_entrypoint_8(u8 *, BtIntPtr);
    s32 _sumumbofx_entrypoint_9(u8 *, BtIntPtr);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101870(Actor *, void *);
    void func_808016A4_chfactorymagnet(Actor *, BtIntPtr);
    void func_80801A9C_chfactorymagnet(BtIntPtr, f32 *, f32 *);
    struct MagnetVector { f32 v[3]; };
    extern struct MagnetVector D_8080291C_chfactorymagnet;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    struct MagnetVector sp30;
    u8 *temp_s1;

    sp3C = func_800F12D4(arg0->unk58, 0.25f, 1.0f, 0.0f, 1.0f);
    sp30 = D_8080291C_chfactorymagnet;
    temp_s1 = func_80100094(arg0, 0);
    func_80801A9C_chfactorymagnet((BtIntPtr)arg0, sp4C, sp40);
    func_800EFE50(arg0->position, sp4C, sp40, sp3C);
    if (temp_s1 != NULL) {
        _sumumbofx_entrypoint_9(temp_s1, arg1);
    }
    if (arg0->unk70_10 == 4) {
        func_808016A4_chfactorymagnet(arg0, arg1);
    }
    func_80101870(arg0, (void *)arg1);
    if (temp_s1 != NULL) {
        _sumumbofx_entrypoint_8(temp_s1, arg1);
    }
}

void func_80800FE8_chfactorymagnet(Actor *arg0) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    BtIntPtr func_800B53A4(s32);
    void func_800BA1D0(BtIntPtr, f32[3], f32[3], s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_80103EF4(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80802934_chfactorymagnet;
    extern s32 D_80802940_chfactorymagnet;
    extern s32 D_8080294C_chfactorymagnet;
    extern s32 D_80802954_chfactorymagnet;
    BtIntPtr sp74;
    Actor *sp70;
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;

    *(u8 *)&arg0->actorData[3] = _subaddieaudioloop_entrypoint_7(
        *(u8 *)&arg0->actorData[3], arg0->position,
        arg0->unk58 > 0.25f && arg0->unk58 < 1.0f,
        &D_80802940_chfactorymagnet, arg0->unk70_0);
    *(u8 *)&arg0->unk54 = _subaddieaudioloop_entrypoint_7(
        *(u8 *)&arg0->unk54, arg0->position,
        arg0->unk58 > 0.0f && arg0->unk58 < 0.75f,
        &D_80802940_chfactorymagnet, arg0->unk70_0);
    if ((arg0->unk58 <= 0.0f && ((f32 *)arg0->actorData)[7] > 0.0f) ||
        (arg0->unk58 >= 0.75f && ((f32 *)arg0->actorData)[7] < 0.75f)) {
        sp74 = func_800B53A4(4);
        sp70 = func_80106790(arg0->unk3C);
        sp3C = func_80103EF4(sp70);
        func_800EE7F8(sp4C, sp70->position);
        func_800EE7F8(sp40, sp4C);
        sp4C[0] -= sp3C;
        sp40[0] += sp3C;
        func_800EE7F8(sp64, sp4C);
        func_800EE7F8(sp58, sp40);
        sp64[1] += sp3C * func_800138D0(sp70->rotation[0]);
        sp58[1] += sp3C * func_800138D0(sp70->rotation[0]);
        sp64[2] += sp3C * func_80013970(sp70->rotation[0]);
        sp58[2] += sp3C * func_80013970(sp70->rotation[0]);
        func_800BABB8(sp74, sp70->position, NULL, sp70->scale, &D_80802954_chfactorymagnet);
        func_800BA1D0(sp74, sp4C, sp64, 1);
        func_800BA1D0(sp74, sp64, sp58, 2);
        func_800BA1D0(sp74, sp58, sp40, 1);
        _subaddieaudioquick_entrypoint_2(arg0, sp70->position, &D_80802934_chfactorymagnet);
    }
    if (arg0->unk58 >= 1.0f && ((f32 *)arg0->actorData)[7] < 1.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080294C_chfactorymagnet);
    }
}

/* extern */

s32 func_808012E4_chfactorymagnet(BtIntPtr arg0, f32 arg1) {
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_80090178(s32);
    f32 func_800EFC7C(void *, void *);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    f32 sp24[3];
    Actor *sp20;

    if (func_80090178(0x40) != 0) {
        sp20 = _subaddiefind_entrypoint_2(0x3FC, 0);
        func_800F5A00(func_800F54E4(), sp24);
        return func_800EFC7C(sp24, sp20->position) < arg1;
    }
    return 0;
}

/* extern */ void func_80801368_chfactorymagnet(u8 *arg0) { s32 func_800D90F8(u8 *, f32); s32 func_800D91EC(u8 *, f32); f32 func_800DC178(f32, f32); f32 temp_f0; s32 var_v0; temp_f0 = (*(f32 *)((s8 *)(arg0) + (0x1C))); if (temp_f0 < (((Actor *)arg0)->unk58)) { var_v0 = func_800D90F8(arg0 + 0x58, temp_f0); } else { var_v0 = func_800D91EC(arg0 + 0x58, temp_f0); } if (var_v0 != 0) { (*(f32 *)((s8 *)(arg0) + (0x1C))) = func_800DC178(0.0f, 1.0f); } }

/* extern */

void chfactorymagnet_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _chmrtannoy_entrypoint_0();
    s32 func_800C05B8(s32, s32, s32, s32, BtIntPtr, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    func_800DA524(0xA06);
    if (func_800EA05C() != 0x107) {
        func_800DA524(0x9DE);
    }
    if (func_800DA298(0x1B8) == 0) {
        _chmrtannoy_entrypoint_0();
        func_800C05B8(0x1338, 4, 0, 0, 0, 0, 0xA3);
    }
}

void func_80801460_chfactorymagnet(Actor *arg0, BtIntPtr arg1) {
    void _sumumbofx_entrypoint_7(u8 *arg0, f32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5, f32 *arg6);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_80103EAC(Actor *);
    void func_80801A9C_chfactorymagnet(BtIntPtr, f32 *, f32 *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;

    sp30 = func_800F12D4(arg0->unk58, 0.25f, 1.0f, 0.0f, 1.0f);
    func_80801A9C_chfactorymagnet((BtIntPtr)arg0, sp40, sp34);
    func_800EFE50(sp4C, sp40, sp34, sp30);
    _sumumbofx_entrypoint_7(arg1, func_80103EAC(arg0) * 0.6f, 0, 0x28, sp4C, 0, 0);
}

void func_80801508_chfactorymagnet(Actor *arg0, s32 arg1) {
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    struct MagnetParticle {
        f32 position[3];
        f32 unkC;
        f32 unk10;
        f32 unk14;
        s8 unk18;
        s8 unk19;
    } *sp24, *particle;
    f32 value;

    sp24 = func_80100094(arg0, 1);
    if (func_800DC0C0() < 0.2f) {
        particle = sp24;
        particle += arg1;
        particle->unk19 = func_800DC128(0, 3);
        particle->unk14 = func_800DC0C0() * 0.15f + 0.35f;
        value = func_800DC178(1.0f, 3.0f);
        particle->unk10 = value;
        particle->unkC = value;
        if (func_800DC0C0() < 0.5f) { particle->unk18 = 1; } else { particle->unk18 = 2; }
        if (func_800DC0C0() < 0.2f) {
            func_800F5A00(func_800F54E4(), particle->position);
            particle->position[0] += func_800DC178(-100.0f, 100.0f);
            particle->position[1] += func_800DC178(0.0f, 200.0f);
        } else {
            particle->position[0] = func_800DC178(-2000.0f, 1500.0f);
            particle->position[1] = func_800DC178(0.0f, 1600.0f);
            particle->position[2] = func_800DC178(1200.0f, 1800.0f);
        }
    }
}

void func_808016A4_chfactorymagnet(Actor *arg0, BtIntPtr arg1) {
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    BtIntPtr func_800D674C(s32);
    s32 func_800D90A4(f32 *);
    void func_800E2588(u32);
    void func_800E2594(BtUIntPtr, void *);
    s32 func_800E2720(u8 *, s32, s32, f32 *, f32 *, s32);
    void func_800E2A14(BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_808019F4_chfactorymagnet(Actor *, f32 *, f32 *);
    f32 spC4[3];
    f32 spB8[3];
    struct MagnetParticle {
        f32 position[3];
        f32 unkC;
        f32 unk10;
        f32 unk14;
        u8 unk18;
        u8 unk19;
    } *particles;
    s32 i;
    f32 t;
    f32 position[3];
    f32 scale[3];
    s32 alpha;
    f32 t2;
    f32 position2[3];
    f32 scale2[3];
    struct MagnetParticle *particle;

    particles = func_80100094(arg0, 1);
    func_808019F4_chfactorymagnet(arg0, spC4, spB8);
    func_800E2594(arg1, func_800D674C(0x9D8));
    for (i = 0, particle = particles; i < 20; i++, particle++) {
        if (particle->unk18 != 0) {
            if (func_800D90A4(&particle->unkC)) {
                particle->unk18 = 0;
            } else {
                t = func_800F12D4(particle->unkC, particle->unk10, 0.0f, 0.0f, 1.0f);
                if (t > 0.5f) {
                    alpha = 255;
                    t -= 0.5f;
                    t *= 2.0f;
                    func_800EFE50(position, particle->position, particle->unk18 == 1U ? spC4 : spB8, t);
                    scale[2] = func_800F10B4(particle->unkC, particle->unk10, 0.0f, 0.0f, 1.0f);
                    t = func_800138D0(scale[2] * 720.0f);
                    scale[0] = particle->unk14 * t;
                    t = func_80013970(scale[2] * 360.0f);
                    scale[1] = particle->unk14 * t;
                } else {
                    func_800EE7F8(position, particle->unk18 == 1U ? spC4 : spB8);
                    scale[0] = scale[1] = scale[2] = particle->unk14;
                    alpha = (s32)(511.0f * t);
                }
                func_800E2588(1);
                func_800E2720(arg1, particle->unk19, 0, position, scale, alpha);
            }
        } else {
            func_80801508_chfactorymagnet(arg0, i);
        }
    }
    func_800E2A14(arg1);
    func_800E2594(arg1, func_800D674C(0x9DF));
    for (; i < 30; i++, particle++) {
        if (particle->unk18 != 0) {
            if (func_800D90A4(&particle->unkC)) {
                particle->unk18 = 0;
            } else {
                t2 = func_800F12D4(particle->unkC, particle->unk10, 0.0f, 0.0f, 1.0f);
                func_800EFE50(position2, particle->position, particle->unk18 == 1U ? spC4 : spB8, t2);
                scale2[2] = particle->unk14;
                scale2[0] = particle->unk14;
                scale2[1] = particle->unk14;
                func_800E2588(1);
                func_800E2720(arg1, 0, 0, position2, scale2, 255);
            }
        } else {
            func_80801508_chfactorymagnet(arg0, i);
        }
    }
    func_800E2A14(arg1);
}

/* extern */

void func_808019F4_chfactorymagnet(Actor *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];

    func_800EFA4C(sp1C, (*&arg0)->scale * -195.0f, arg0->scale * 60.0f, arg0->scale * 390.0f);
    func_800EE780(arg1, arg0->position, sp1C);
    sp1C[0] = arg0->scale * 205.0f;
    func_800EE780(arg2, arg0->position, sp1C);
}

void func_80801A9C_chfactorymagnet(BtIntPtr arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    extern f32 D_8080298C_chfactorymagnet;
    extern f32 D_80802998_chfactorymagnet;
    if (arg1 != NULL) {
        func_800EE7F8(arg1, &D_8080298C_chfactorymagnet);
    }
    if (arg2 != NULL) {
        func_800EE7F8(arg2, &D_80802998_chfactorymagnet);
    }
}    typedef struct { u8 pad0[0x348]; s32 unk348; s32 unk34C; } Objmagnet_func_80801AE8_chfactorymagnet_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */

/* extern */

void func_80801AE8_chfactorymagnet(Actor *arg0) {
    s32 func_800C8A98();
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    void *func_80100094(Actor *, u32);
    void *temp_s0;

    temp_s0 = func_80100094(arg0, 1);
    (((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk348) = func_800C8A98();
    (((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk34C) = func_800C8A98();
    func_800C8E54((((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk348), 300.0f, 450.0f);
    func_800C8E54((((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk34C), 300.0f, 450.0f);
    func_800C8FE0((((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk348), 0);
    func_800C8FE0((((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk34C), 0);
    func_800C8F64((((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk348), 3);
    func_800C8F64((((Objmagnet_func_80801AE8_chfactorymagnet_temp_s0 *)temp_s0)->unk34C), 3);
}

void func_80801B74_chfactorymagnet(Actor *arg0) {
    void func_800C8CB8(s32, f32[3]);
    void func_800C8FB0(s32, u32, u32, u32);
    void func_800C8FE0(s32, s32);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    typedef struct { f32 v[3]; } MagnetVector;
    typedef struct { u8 pad[0x348]; s32 first; s32 second; } MagnetData;
    extern MagnetVector D_808029A4_chfactorymagnet;
    extern MagnetVector D_808029B0_chfactorymagnet;
    MagnetVector sp3C = D_808029A4_chfactorymagnet;
    MagnetVector sp30 = D_808029B0_chfactorymagnet;
    MagnetData *data;

    data = func_80100094(arg0, 1);
    if (arg0->unk70_10 == 4) {
        func_800C8FE0(data->first, 1);
        func_800C8FE0(data->second, 1);
        func_800C8CB8(data->first, sp3C.v);
        func_800C8CB8(data->second, sp30.v);
        func_800C8FB0(data->first, func_800DC128(0xE6, 0x100), func_800DC128(0, 0x29), func_800DC128(0xE6, 0x100));
        func_800C8FB0(data->second, func_800DC128(0xE6, 0x100), func_800DC128(0, 0x29), func_800DC128(0xE6, 0x100));
    } else {
        func_800C8FE0(data->first, 0);
        func_800C8FE0(data->second, 0);
    }
}

void func_80801CD8_chfactorymagnet(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA5B0(s16 *, s32, s32);
    void func_800BAA9C(void *, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    typedef struct {
        f32 position[3];
        f32 start;
        f32 end;
        f32 scale;
        u8 active;
        u8 alpha;
        u8 pad[2];
    } MagnetParticle;
    extern s32 D_808029BC_chfactorymagnet[];
    f32 sp9C[3];
    f32 sp90[3];
    f32 t;
    BtIntPtr particle;
    s32 offset;
    f32 sp78[3];
    MagnetParticle *data;

    data = func_80100094(arg0, 1);
    func_808019F4_chfactorymagnet(arg0, sp9C, sp90);
    for (offset = 0; offset < 20; offset++) {
        if (data[offset].active != 0) {
            t = func_800F12D4(data[offset].start, data[offset].end, 0.0f, 0.0f, 1.0f);
            particle = func_800B53A4(1);
            if (t > 0.5f) {
                t -= 0.5f;
                t *= 2.0f;
                func_800EFE50(sp78, data[offset].position, data[offset].active == 1 ? sp9C : sp90, t);
            } else {
                func_800EE7F8(sp78, data[offset].active == 1 ? sp9C : sp90);
            }
            func_800BAA9C((void *)particle, data[offset].scale);
            func_800BA5B0((s16 *)particle, data[offset].alpha, data[offset].alpha);
            func_800BABB8(particle, sp78, NULL, 1.0f, D_808029BC_chfactorymagnet);
        }
    }
}                  typedef struct { u8 pad0[0x24]; s32 unk24; u8 pad28[0x5A]; s16 unk82; } Objmagnet_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80801E84_chfactorymagnet(u8 *arg0) {
    s32 _sumumbofx_entrypoint_1(void *, s32);
    if ((((Objmagnet_arg0 *)arg0)->unk82) != 0) {
        _sumumbofx_entrypoint_1(arg0, 0);
    }
}

OSThread *chfactorymagnet_entrypoint_1(void)
{
    extern u8 D_80802A04_chfactorymagnet[];

    return (OSThread *) D_80802A04_chfactorymagnet;
}

void func_80801EBC_chfactorymagnet(Actor *arg0) {
    f32 func_80013970(f32);
    s32 func_800DA298(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800F4D74(BtIntPtr, f32 *, f32, f32, f32);
    BtUIntPtr func_800F54E4(void);
    f32 func_80103EF4(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 sp3C[3];
    f32 sp38;
    f32 sine;
    BtUIntPtr sp30;

    if (func_800DA298(0xA06) != 0) {
        sp38 = func_80103EF4(arg0) * 1.2f;
        func_800EFA4C(sp3C, arg0->position[0], arg0->position[1] + sp38 * 0.5f, arg0->position[2] - sp38);
        sp30 = func_800F54E4();
        sine = func_80013970(arg0->rotation[0]); func_800F4D74(sp30, sp3C, sp38, sp38 * 0.5f, sine * sp38 + sp38);
    }
    arg0->rotation[0] = func_800F12D4(func_80106790(arg0->unk3C)->unk58, 0.0f, 0.75f, 0.0f, 90.0f);
}

OSThread *chfactorymagnet_entrypoint_2(void)
{
    extern u8 D_80802A4C_chfactorymagnet[];

    return (OSThread *) D_80802A4C_chfactorymagnet;
}

void func_80801FB8_chfactorymagnet(Actor *arg0) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void func_80018820(s32, f32, f32);
    void func_800C31DC(u8, f32);
    s32 func_800D90A4(f32 *);
    s32 func_800D91EC(u8 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    extern s32 D_80802A94_chfactorymagnet[];
    extern s32 D_80802AA4_chfactorymagnet[];

    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_800D91EC(&arg0->unk58, 0.5f)) {
                arg0->alpha = 255;
                func_80101FDC(arg0, 3);
            }
            break;
        case 3:
            func_80018820(0, 2.0f, 0.5f);
            break;
        case 4:
            arg0->alpha = (u32)func_800F10B4(arg0->unk58, 0.5f, 0.0f, 0.0f, 255.0f);
            if (func_800D90A4(&arg0->unk58)) {
                arg0->unk64_16 = 0;
                func_80101FDC(arg0, 1);
            }
            break;
    }
    *(u8 *)&arg0->actorData[4] = _subaddieaudioloop_entrypoint_7(
        *(u8 *)&arg0->actorData[4], arg0->position, arg0->unk58 != 0.0f,
        D_80802A94_chfactorymagnet, arg0->unk70_0);
    *(u8 *)&arg0->actorData[5] = _subaddieaudioloop_entrypoint_7(
        *(u8 *)&arg0->actorData[5], arg0->position, arg0->unk58 != 0.0f,
        D_80802AA4_chfactorymagnet, arg0->unk70_0);
    if (arg0->unk58 == 0.0f) {
        arg0->unk64_16 = 0;
    } else {
        arg0->unk64_16 = 1;
        arg0->alpha = (u32)func_800F10B4(arg0->unk58, 0.5f, 0.0f, 255.0f, 0.0f);
        func_800C31DC(*(u8 *)&arg0->actorData[4], func_800F10B4(arg0->unk58, 0.5f, 0.0f, 1.1f, 0.9f));
        func_800C31DC(*(u8 *)&arg0->actorData[5], func_800F10B4(arg0->unk58, 0.5f, 0.0f, 1.1f, 0.9f));
    }
}

s32 func_808022D8_chfactorymagnet(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800187B4(s32, f32, f32, f32);
    void func_800DF830(s32);
    s32 func_801015D0(Actor *);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 0x1F:
            func_801015D0(arg0);
            func_800DF830(2);
            return 1;
        case 0xA:
            arg0->unk64_16 = 1;
            func_80101FDC(arg0, 2);
            func_800187B4(0, 1.0f, 2.0f, 0.5f);
            return 1;
        case 0x4F:
            func_80101FDC(arg0, 4);
            func_800187B4(0, 2.0f, 1.0f, 0.5f);
            return 1;
        default:
            return 0;
    }
}

OSThread *chfactorymagnet_entrypoint_3(void)
{
    extern u8 D_80802AB4_chfactorymagnet[];

    return (OSThread *) D_80802AB4_chfactorymagnet;
}

void func_80802390_chfactorymagnet(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_8001210C(s32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800C8A98(void);
    void func_800C8B84(s32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    void func_800C8FE0(s32, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    extern s32 D_80802AFC_chfactorymagnet[];
    extern f32 D_80802B50_chfactorymagnet[];
    extern u32 D_80802B58_chfactorymagnet[];
    s32 active;
    f32 *first;

    switch (arg0->unk70_10) {
        case 1:
            if (func_800D90A4(&arg0->unk58)) {
                if (_subaddiefind_entrypoint_2(0x3F5, 0)->unk70_10 == 0x11) {
                    first = (f32 *)&arg0->actorData[4];
                    func_800BBCB8(first, (f32 *)&arg0->actorData[0], 1.0f, 10, D_80802AFC_chfactorymagnet);
                    func_800BBCB8((f32 *)&arg0->actorData[0], first, 1.0f, 10, D_80802AFC_chfactorymagnet);
                    arg0->actorData[3] = func_800C8A98();
                    func_800C8D4C(arg0->actorData[3], D_80802B50_chfactorymagnet);
                    func_800C8FE0(arg0->actorData[3], 1);
                    func_800C8F64(arg0->actorData[3], 15);
                    func_800C8CB8(arg0->actorData[3], arg0->position);
                    func_800C8FB0(arg0->actorData[3], 200, 200, 255);
                    arg0->unk58 = ((f32 *)arg0->actorData)[7] = func_800DC178(0.5f, 1.25f);
                    func_80101FDC(arg0, 2);
                    arg0->unk64_16 = 1;
                } else {
                    arg0->unk58 = ((f32 *)arg0->actorData)[7] = func_800DC178(2.0f, 20.0f);
                }
            }
            break;
        case 2:
            if (func_800D90A4(&arg0->unk58)) {
                _subaddieaudioloop_entrypoint_2(arg0);
                func_800C8B84(arg0->actorData[3]);
                arg0->actorData[3] = 0;
                func_80101FDC(arg0, 1);
                arg0->unk58 = ((f32 *)arg0->actorData)[7] = func_800DC178(2.0f, 20.0f);
                arg0->unk64_16 = 0;
            } else {
                active = func_8001210C(1);
                func_800C8FB0(arg0->actorData[3], active ? 200 : 160, active ? 200 : 160, active ? 255 : 200);
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80802B58_chfactorymagnet);
            }
            break;
    }
}

s32 func_808025B4_chfactorymagnet(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32 *);
    s32 _gspropctrl_entrypoint_8(Prop *);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_801015D0(Actor *);
    f32 func_80103EAC(Actor *);
    Prop *props[20];
    s32 count;
    s32 i;
    f32 angles[4];
    f32 speed;

    switch (arg1) {
        case 0x1F:
            arg0->alpha = (u32)func_800F10B4(arg0->unk58, ((f32 *)arg0->actorData)[7], 0.0f, 255.0f, 50.0f);
            func_801015D0(arg0);
            func_800DF744(1, 1);
            func_800DF744(2, func_800DC128(1, 5));
            return 1;
        case 0x95:
            count = _gccubesearch_entrypoint_9(0x511, props, 20);
            for (i = 0; i < count; i++) {
                if (_gspropctrl_entrypoint_8(props[i]) == arg0->unk74_7) {
                    speed = func_80103EAC(arg0);
                    angles[2] = func_800DC0C0() * 200.0f;
                    angles[3] = angles[2] + func_800DC0C0() * 200.0f;
                    _gspropctrl_entrypoint_11(props[i], (f32 *)arg0->actorData);
                    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
                    func_800F18FC(arg0->position, (f32 *)arg0->actorData, angles);
                    arg0->rotation[0] = angles[0];
                    arg0->rotation[1] = angles[1];
                    speed = func_800EEAD4((f32 *)&arg0->actorData[4], (f32 *)arg0->actorData) / speed;
                    arg0->scale = speed;
                    func_800EF214(arg0->position, angles[0], angles[1], -speed);
                    arg0->unk64_16 = 0;
                    arg0->unk58 = ((f32 *)arg0->actorData)[7] = func_800DC178(2.0f, 20.0f);
                    return 1;
                }
            }
            func_800FFAB0(arg0);
            return 0;
        default:
            return 0;
    }
}

void func_8080281C_chfactorymagnet(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (((Objmagnet_arg0 *)arg0)->unk24);
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
    }
}

OSThread *chfactorymagnet_entrypoint_4(void)
{
    extern u8 D_80802B68_chfactorymagnet[];

    return (OSThread *) D_80802B68_chfactorymagnet;
}
