#include "common.h"

void func_80800000_chwumbawigwam(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    BtIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    f32 func_80103EAC(u8 *);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    void func_80800B9C_chwumbawigwam(u8 *, s32);
    f32 pad[2];
    f32 var_f2;
    f32 sp2C;
    f32 sp24;
    f32 var_f0;

    if (func_800EA05C() == 0x112) {
        if (func_800DA298(0x18A) != 0 && func_800EA05C() == 0x112) {
            arg0->scale = 2.8f;
        } else {
            arg0->scale = 1.0f;
        }
        sp24 = func_80103EAC((u8 *)arg0);
        if (func_800F64A4(func_800F54E4(), 0x40000) != 0) {
            var_f2 = 1.0f;
        } else {
            var_f2 = 0.6f;
        }
        sp2C = var_f2;
        if (func_800F64A4(func_800F54E4(), 0x40000) != 0) {
            var_f0 = 40.0f;
        } else {
            var_f0 = arg0->scale * 280.0f;
        }
        if (func_8010C9FC(arg0->position, (s32)(var_f2 * sp24), (s32)var_f0, 0) != 0) {
            func_80800B9C_chwumbawigwam((u8 *)arg0, 2);
        } else {
            func_80800B9C_chwumbawigwam((u8 *)arg0, 3);
        }
        func_800EFA4C((f32 *)&arg0->actorData[4], 1.0f, 1.0f, 1.0f);
    }
}
typedef struct { f32 v[3]; } WigwamVec;
void func_80800158_chwumbawigwam(u8 *arg0) {

    typedef struct {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u32 : 11, u32  : 19);
        BT_BITFIELD_ORDER(u32 sound1 : 1, u32 sound2 : 1);
        BT_BITFIELD_ORDER(u32 sound2 : 1, u32 sound1 : 1);
        BT_BITFIELD_ORDER(u32 : 19, u32  : 11);
        u8 pad68[0xC];
        BT_BITFIELD_ORDER(u32 : 2, u32  : 29);
        u32 effect : 1;
        BT_BITFIELD_ORDER(u32 : 29, u32  : 2);
    } WigwamFlags;
    s32 _gcgoto_entrypoint_5(s32, s32, f32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 _sumumbofx_entrypoint_14(BtIntPtr);
    f32 _sumumbofx_entrypoint_21(BtIntPtr);
    s32 _sumumbofx_entrypoint_27(BtIntPtr);
    s32 _sumumbofx_entrypoint_5(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_6(BtIntPtr, f32, f32, s32, s32, u8 *, BtIntPtr, BtIntPtr);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    BtIntPtr func_800BBCB8(WigwamVec *, WigwamVec *, f32, s32, s32 *);
    s32 func_800C4140(s32, WigwamVec *, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C(void);
    s32 func_800F00A4(f32 *, f32, f32, f32, f32 *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    BtIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F64A4(BtIntPtr, s32);
    BtIntPtr func_80100094(u8 *, s32);
    void func_80103110(u8 *, s32);
    f32 func_80103EAC(u8 *);
    f32 func_80103EF4(u8 *);
    void func_8010A624(u8 *);
    f32 func_8010CD28(u8 *);
    void func_80800B9C_chwumbawigwam(u8 *, s32);
    extern WigwamVec D_808010E0_chwumbawigwam;
    extern s32 D_808010EC_chwumbawigwam[5];
    extern s32 D_80801100_chwumbawigwam[5];
    extern s32 D_80801114_chwumbawigwam[17];
    extern s32 D_80801158_chwumbawigwam[5];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp5C;
    WigwamVec sp50;
    f32 sp4C;

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        func_80103110(arg0, 0);
        break;
    case 2:
        func_800F5A00(func_800F54E4(), sp6C);
        if (!func_800F00A4((f32 *)(arg0 + 4),
            func_80103EAC(arg0) * (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
            func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : *(f32 *)(arg0 + 0x38) * 280.0f, 0.0f, sp6C)) {
            func_80800B9C_chwumbawigwam(arg0, 3);
        }
        break;
    case 3:
        func_800F5A00(func_800F54E4(), sp60);
        if (func_800F00A4((f32 *)(arg0 + 4),
            func_80103EAC(arg0) * (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
            func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : *(f32 *)(arg0 + 0x38) * 280.0f, 0.0f, sp60)) {
            func_8010A624(arg0);
            if (func_800DA298(0x18A) && func_800EA05C() == 0x112) {
                _gcgoto_entrypoint_5(0x122, 1, func_8010CD28(arg0) + 180.0f);
            } else {
                _gcgoto_entrypoint_5(0x11E, 1, func_8010CD28(arg0) + 180.0f);
            }
        }
        break;
    case 4:
        if (func_800DA298(0x9DE)) {
            func_80800B9C_chwumbawigwam(arg0, 5);
        }
        break;
    case 5:
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0),
            *(f32 *)(arg0 + 0x38) * (f32)(u32)*(u16 *)(arg0 + 0x62), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 6);
        }
        break;
    case 6:
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0),
            *(f32 *)(arg0 + 0x38) * (f32)(u32)*(u16 *)(arg0 + 0x62), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_5(func_80100094(arg0, 1), 0x40400000);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            if (func_800DA298(0x18A)) {
                func_80800B9C_chwumbawigwam(arg0, 8);
            } else {
                func_80800B9C_chwumbawigwam(arg0, 7);
            }
        }
        break;
    case 7:
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) > 2.5f) {
            if (!((WigwamFlags *)arg0)->sound2) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_808010EC_chwumbawigwam);
                ((WigwamFlags *)arg0)->sound2 = 1;
            }
            *(f32 *)(arg0 + 0x28) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.5f, 1.0f, 2.0f);
            *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x28);
            *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x28);
        } else {
            sp5C = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.5f, 0.0f, 1.0f, 0.0f);
            if (!((WigwamFlags *)arg0)->sound1) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80801100_chwumbawigwam);
                ((WigwamFlags *)arg0)->sound1 = 1;
            }
            *(f32 *)(arg0 + 0x28) = func_800138D0(sp5C * 3.0f * 360.0f) * sp5C + 1.0f;
            *(f32 *)(arg0 + 0x2C) = func_800138D0(sp5C * 5.0f * 360.0f) * sp5C + 1.0f;
            *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x28);
            *(f32 *)(arg0 + 0x38) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.5f, 0.0f, 1.0f, 2.8f);
        }
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0) * *(f32 *)(arg0 + 0x2C),
            ((f32)(u32)*(u16 *)(arg0 + 0x62) * *(f32 *)(arg0 + 0x38)) * func_800F0E00(*(f32 *)(arg0 + 0x28), *(f32 *)(arg0 + 0x30)), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 9);
        }
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) <= 2.0f) {
            if (!((WigwamFlags *)arg0)->effect) {
                sp50 = D_808010E0_chwumbawigwam;
                func_800BBCB8(&sp50, &sp50, 1.0f, 0xF, D_80801114_chwumbawigwam);
                func_800C4140(0x7FFB5BF2, &sp50, 0x1F4003E8);
                ((WigwamFlags *)arg0)->effect = 1;
            }
        }
        break;
    case 8:
        sp4C = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 0.0f, 1.0f, 0.0f);
        if (!((WigwamFlags *)arg0)->sound1) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80801158_chwumbawigwam);
            ((WigwamFlags *)arg0)->sound1 = 1;
        }
        *(f32 *)(arg0 + 0x28) = func_80013970(sp4C * 6.0f * 360.0f) * (sp4C * 0.5f) + 1.0f;
        *(f32 *)(arg0 + 0x2C) = func_80013970(sp4C * 7.0f * 360.0f) * (sp4C * 0.5f) + 1.0f;
        *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x28);
        *(f32 *)(arg0 + 0x38) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.5f, 2.8f, 1.0f);
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0) * *(f32 *)(arg0 + 0x2C),
            ((f32)(u32)*(u16 *)(arg0 + 0x62) * *(f32 *)(arg0 + 0x38)) * func_800F0E00(*(f32 *)(arg0 + 0x28), *(f32 *)(arg0 + 0x30)), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 9);
        }
        break;
    case 9:
        _sumumbofx_entrypoint_6(func_80100094(arg0, 1), func_80103EF4(arg0),
            *(f32 *)(arg0 + 0x38) * (f32)(u32)*(u16 *)(arg0 + 0x62), 0, 0x28, arg0 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800B9C_chwumbawigwam(arg0, 10);
        }
        break;
    case 10:
        func_80800B9C_chwumbawigwam(arg0, 3);
        break;
    }
}

/* extern */

void func_80800B9C_chwumbawigwam(u8 *arg0, s32 arg1) {
    typedef struct { s32 pad[4]; f32 scale[3]; } WigwamData;
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chglowbo_entrypoint_6(void);
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _subaddieDll_entrypoint_4(u8 *, s32);
    s32 _sumumbofx_entrypoint_0(u8 *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_1(u8 *, s32);
    s32 _sumumbofx_entrypoint_15(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_16(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_17(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_18(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_2(BtIntPtr);
    s32 _sumumbofx_entrypoint_24(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_25(BtIntPtr, s32, s32 *);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    BtIntPtr func_80100094(u8 *, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80101FDC(u8 *, s32);
    s32 func_8010A800(u8 *, s32);
    s32 sp34[3];
    s32 pad[2];
    BtIntPtr sp28;

    switch (arg1) {
    case 4:
        _subaddieDll_entrypoint_4(arg0, 1);
        ((Actor *)arg0)->unk64_20 = 0;
        ((Actor *)arg0)->unk64_19 = 0;
        ((Actor *)arg0)->unk74_29 = 0;
        func_8010A800(arg0, 2);
        break;
    case 5:
        sp34[0] = 0;
        sp34[1] = 0;
        sp34[2] = 0;
        _sumumbofx_entrypoint_0(arg0, 1, 0x28, _chmumbopad_entrypoint_0(9));
        _sumumbofx_entrypoint_2(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_25(func_80100094(arg0, 1), 0x7D, sp34);
        sp28 = func_80100094(arg0, 1);
        func_800DA298(0x18A);
        _sumumbofx_entrypoint_24(sp28, 0x3FC00000);
        _sumumbofx_entrypoint_15(func_80100094(arg0, 1), 0x40400000);
        func_80101180(0x2B0, 0xBB, 9);
        _capod_entrypoint_13(((Actor *)arg0)->unk0, 0, 0xE, 0x210);
        func_800DA544(0x57D);
        break;
    case 6:
        _sumumbofx_entrypoint_18(func_80100094(arg0, 1), 0x40400000);
        break;
    case 7:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 1), 0x40800000);
        func_800DA544(0x18A);
        break;
    case 8:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 1), 0x40800000);
        func_800DA524(0x18A);
        break;
    case 9:
        _sumumbofx_entrypoint_16(func_80100094(arg0, 1), 0x40400000);
        if (func_800DA298(0x18A) != 0) {
            ((Actor *)arg0)->scale = 2.8f;
        } else {
            ((Actor *)arg0)->scale = 1.0f;
        }
        ((WigwamData *)((Actor *)arg0)->actorData)->scale[0] = 1.0f;
        ((WigwamData *)((Actor *)arg0)->actorData)->scale[1] = 1.0f;
        ((WigwamData *)((Actor *)arg0)->actorData)->scale[2] = 1.0f;
        _chglowbo_entrypoint_6();
        break;
    case 10:
        _sumumbofx_entrypoint_1(arg0, 1);
        func_8010A800(arg0, 0);
        func_800DA544(0x9DF);
        _subaddieDll_entrypoint_4(arg0, 0);
        break;
    }
    func_80101FDC(arg0, arg1);
}

void func_80800E04_chwumbawigwam(Actor *arg0, void *arg1) {
    typedef struct {
        u8 pad[0x7A];
        BT_BITFIELD_ORDER(u8 mode : 2, u8  : 6);
        BT_BITFIELD_ORDER(u8 : 6, u8 mode : 2);
    } WigwamRenderFlags;
    BtIntPtr func_80100094();
    s32 _subaddiefade_entrypoint_1(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_8(u8 *, BtIntPtr);
    s32 _sumumbofx_entrypoint_9(u8 *, BtIntPtr);
    void func_800DF500(f32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80101870(Actor *, void *);
    extern f32 B_808011C0_chwumbawigwam[3];
    extern f32 B_808011E4_chwumbawigwam[3];
    extern f32 B_808011F0_chwumbawigwam[3];
    f32 *dst;
    f32 *src;
    s32 i;

    if (func_80100094(arg0, 1)) {
        _sumumbofx_entrypoint_9(func_80100094(arg0, 1), (BtIntPtr)arg1);
    }
    i = 4;
    if (arg0->unk70_10 == 7 || arg0->unk70_10 == 8) {
        dst = B_808011F0_chwumbawigwam; src = B_808011E4_chwumbawigwam;
        do {
            func_800EE7F8(dst, src);
            if (dst[0] != 0.0f && dst[1] != 0.0f && dst[2] != 0.0f) {
                func_800DF500(dst[0], dst[1], dst[2]);
                _subaddiefade_entrypoint_1((BtIntPtr)arg0, 160 - i * 30);
                ((WigwamRenderFlags *)arg0)->mode = 2;
                func_80101870(arg0, arg1);
            }
            i--;
            dst -= 3;
            src -= 3;
        } while (i != 0);
        func_800EE7F8(B_808011C0_chwumbawigwam, (f32 *)&arg0->actorData[4]);
        if (((f32 *)arg0->actorData)[4] != 0.0f &&
            ((f32 *)arg0->actorData)[5] != 0.0f &&
            ((f32 *)arg0->actorData)[6] != 0.0f) {
            func_800DF500(((f32 *)arg0->actorData)[4],
                         ((f32 *)arg0->actorData)[5],
                         ((f32 *)arg0->actorData)[6]);
        }
        ((WigwamRenderFlags *)arg0)->mode = 1;
    }
    _subaddiefade_entrypoint_1((BtIntPtr)arg0, 255);
    func_80101870(arg0, arg1);
    if (func_80100094(arg0, 1)) {
        _sumumbofx_entrypoint_8(func_80100094(arg0, 1), (BtIntPtr)arg1);
    }
}

/* extern */

s32 func_80800FEC_chwumbawigwam(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA524(s32);
    void func_80800B9C_chwumbawigwam(u8 *, s32);
    switch (arg1) {
    case 0x4B:
        if ((arg2 == 9) && ((s32)((Actor *)arg0)->unk70_10 < 5)) {
            func_80800B9C_chwumbawigwam(arg0, 4);
            return 1;
        }
        return 0;
    case 0x2E:
        return 1;
    case 0xB:
        func_800DA524(0x9DE);
        return 3;
    }
    return 0;
}

OSThread *chwumbawigwam_entrypoint_0(void)
{
    extern ActorData D_8080116C_chwumbawigwam[];

    return (OSThread *) D_8080116C_chwumbawigwam;
}
/* data_to_c.py: from asm/data/overlays/ch/wumbawigwam.data.s */
void func_80105834(Actor*);
void func_80107C2C();
WigwamVec D_808010E0_chwumbawigwam BT_DATA(4, overlays_ch_wumbawigwam, 0x0) = { { 0.0f, 4000.0f, 1850.0f } };
s32 D_808010EC_chwumbawigwam[5] BT_DATA(4, overlays_ch_wumbawigwam, 0xC) = { 1246237, 655449, 1469792, 68536, 393216000 };
s32 D_80801100_chwumbawigwam[5] BT_DATA(4, overlays_ch_wumbawigwam, 0x20) = { 1246238, 655616, 1469792, 68536, 393216000 };
s32 D_80801114_chwumbawigwam[17] BT_DATA(4, overlays_ch_wumbawigwam, 0x34) = { 1902240, 1834308, -39321556, -45875200, -45874500, 700, 917564, 3932182, 67239975, 45875900, 65537000, 2359488, 16777259, 83887616, 262246, 458755, 0 };
s32 D_80801158_chwumbawigwam[5] BT_DATA(4, overlays_ch_wumbawigwam, 0x78) = { 1246238, 655616, 68536, 393216022, 1835008000 };
ActorData D_8080116C_chwumbawigwam [1] BT_DATA(4, overlays_ch_wumbawigwam, 0x8C) = { { 344, 653, 1778, 1, 0, (void (*)(struct Actor *))func_80800158_chwumbawigwam, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800E04_chwumbawigwam, 131072000, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chwumbawigwam, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800FEC_chwumbawigwam, 0 } };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 B_808011C0_chwumbawigwam [ 3 ] BT_DATA(16, bss_ch_wumbawigwam, 0x0);
f32 B_808011E4_chwumbawigwam [ 3 ] BT_DATA(4, bss_ch_wumbawigwam, 0x24);
f32 B_808011F0_chwumbawigwam [ 3 ] BT_DATA(4, bss_ch_wumbawigwam, 0x30);
#endif
