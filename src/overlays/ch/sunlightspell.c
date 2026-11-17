#include "common.h"

/* extern */

void func_80800000_chsunlightspell(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0*);
    void func_80800404_chsunlightspell(Actor *, s32);
    if (func_800DA298(0xE9) != 0) {
        func_800FFA88(arg0->unk0);
        return;
    }
    func_80800404_chsunlightspell(arg0, 1);
}

void func_80800048_chsunlightspell(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_1(Actor *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 _sumumbofx_entrypoint_26(void *);
    s32 _sumumbofx_entrypoint_27(void *);
    s32 _sumumbofx_entrypoint_5(u8 *, s32);
    s32 func_800DA298(s32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80800404_chsunlightspell(Actor *, s32);
    void func_80800668_chsunlightspell(Actor *);
    void func_80800704_chsunlightspell(Actor *, f32);
    extern u32 D_80800890_chsunlightspell[5];
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2:
        if (func_800DA298(0x9DE)) {
            func_80800404_chsunlightspell(arg0, 3);
        }
        break;
    case 3:
        func_80800668_chsunlightspell(arg0);
        func_80800704_chsunlightspell(arg0, 100.0f);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800404_chsunlightspell(arg0, 4);
        }
        break;
    case 4:
        func_80800668_chsunlightspell(arg0);
        func_80800704_chsunlightspell(arg0, 100.0f);
        _sumumbofx_entrypoint_5(func_80100094(arg0, 1), 0x40900000);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800404_chsunlightspell(arg0, 5);
        }
        break;
    case 5:
        sp34 = _sumumbofx_entrypoint_26(func_80100094(arg0, 1));
        func_80800668_chsunlightspell(arg0);
        func_80800704_chsunlightspell(arg0, func_800F12D4(sp34, 0.0f, 1.0f, 100.0f, 10.0f));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800404_chsunlightspell(arg0, 6);
        }
        break;
    case 6:
        sp30 = _sumumbofx_entrypoint_26(func_80100094(arg0, 1));
        func_80800668_chsunlightspell(arg0);
        func_80800704_chsunlightspell(arg0, func_800F12D4(sp30, 0.0f, 1.0f, 10.0f, 100.0f));
        arg0->scale = func_800F12D4(sp30, 0.0f, 1.0f, 0.01f, 1.0f);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800890_chsunlightspell);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800404_chsunlightspell(arg0, 7);
        }
        break;
    case 7:
        func_80800668_chsunlightspell(arg0);
        func_80800704_chsunlightspell(arg0, 100.0f);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800890_chsunlightspell);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800404_chsunlightspell(arg0, 8);
        }
        break;
    case 8:
        func_80800668_chsunlightspell(arg0);
        func_80800704_chsunlightspell(arg0, 100.0f);
        sp2C = 1.0f - _sumumbofx_entrypoint_26(func_80100094(arg0, 1));
        arg0->alpha = (u8)(u32)(sp2C * 255.0f);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800890_chsunlightspell);
        _subaddieaudioloop_entrypoint_1(arg0, (s32)(sp2C * 20000.0f));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1))) {
            func_80800404_chsunlightspell(arg0, 9);
        }
        break;
    case 9:
        break;
    }
}
struct SunlightColor { s32 rgb[3]; };
void func_80800404_chsunlightspell(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s16 _chmumbopad_entrypoint_0(s32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void _sumumbofx_entrypoint_2(void *);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_18(void *, f32);
    void _sumumbofx_entrypoint_24(void *, f32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);
    struct SunlightColor sp34;
    extern struct SunlightColor D_808008A4_chsunlightspell;
    struct SunlightActorFlags {
        u8 unk78;
        u8 unk79;
        u8 mode : 2;
        u8 remaining : 6;
    };

    switch (arg1) {
    case 1:
        arg0->unk64_19 = 0;
        break;
    case 2:
        func_80103110(arg0, 1);
        ((struct SunlightActorFlags *)&arg0->unk78)->mode = 2;
        break;
    case 3:
        sp34 = D_808008A4_chsunlightspell;
        _sumumbofx_entrypoint_0(arg0, 1, 0x2E, _chmumbopad_entrypoint_0(6));
        _sumumbofx_entrypoint_2(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_15(func_80100094(arg0, 1), 3.0f);
        _sumumbofx_entrypoint_24(func_80100094(arg0, 1), 0.5f);
        _sumumbofx_entrypoint_25(func_80100094(arg0, 1), 0, sp34.rgb);
        _capod_entrypoint_13(arg0->unk0, NULL, 0x12, 0x10);
        break;
    case 4:
        _sumumbofx_entrypoint_18(func_80100094(arg0, 1), 6.0f);
        break;
    case 5:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 1), 2.0f);
        break;
    case 6:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 1), 6.0f);
        arg0->unk64_19 = 1;
        arg0->scale = 0.01f;
        break;
    case 7:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 1), 1.5f);
        arg0->scale = 1.0f;
        break;
    case 8:
        _sumumbofx_entrypoint_16(func_80100094(arg0, 1), 3.0f);
        break;
    case 9:
        _sumumbofx_entrypoint_1(arg0, 1);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0xE9);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1035, 7, arg0->position, 0x10);
        arg0->unk64_16 = 0;
        _subaddieaudioloop_entrypoint_2(arg0);
        func_800FFAB0(arg0);
        break;
    }
    func_80102424(arg0, arg1);
}

void func_80800668_chsunlightspell(Actor *arg0) {
    s32 func_800BFFB4(s32, s32, f32 *);
    void func_800E3980(f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern f32 D_808008B0_chsunlightspell[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp20[2];

    if (func_800BFFB4(0, 4, sp34) != 0) {
        func_800E3980(sp28);
        func_800F18FC(sp28, sp34, sp20);
        func_800EEBF0(sp34, sp20, 1000.0f);
        func_800EE780(arg0->position, sp28, sp34);
        func_800F18FC(arg0->position, D_808008B0_chsunlightspell, sp20);
        arg0->rotation[1] = sp20[1];
        arg0->rotation[0] = sp20[0];
    }
}

/* extern */

void func_80800704_chsunlightspell(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    void _sumumbofx_entrypoint_14(u8 *arg0);
    void _sumumbofx_entrypoint_7(u8 *arg0, f32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5, f32 *arg6);
    _sumumbofx_entrypoint_7(func_80100094(arg0, 1U), arg1, 0, 0x2E, arg0->position, 0, 0);
    _sumumbofx_entrypoint_14(func_80100094(arg0, 1U));
}

/* extern */

void func_80800768_chsunlightspell(Actor *arg0, u8 *arg1) {
    void* func_80100094(Actor*, u32);
    void func_80101870(Actor* arg0, void* arg1);
    s32 _sumumbofx_entrypoint_8(u8 *, u8 *);
    if (func_80100094(arg0, 1U) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(arg0, 1U), arg1);
    }
    if (arg0->unk64_19) {
        func_80101870(arg0, arg1);
    }
}

/* extern */

s32 func_808007CC_chsunlightspell(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_0(Actor *);
    void func_800FFA88(Unk80132ED0 *);
    void func_80800404_chsunlightspell(Actor *, s32);

    switch (arg1) {
    case 0x4B:
        _subaddieDll_entrypoint_0(arg0);
        func_80800404_chsunlightspell(arg0, 2);
        return 1;
    case 0x2E:
        func_800FFA88(arg0->unk0);
        return 1;
    default:
        return 0;
    }
}

OSThread *chsunlightspell_entrypoint_0(void)
{
    extern ActorData D_808008BC_chsunlightspell[];

    return (OSThread *) D_808008BC_chsunlightspell;
}
/* data_to_c.py: from asm/data/overlays/ch/sunlightspell.data.s */
void func_80105834(Actor*);
void func_80107C2C();
u32 D_80800890_chsunlightspell[5] BT_DATA(4, overlays_ch_sunlightspell, 0x0) = { 0x130673, 0x200002, 0xA0119, 0x164E20, 0 };
struct SunlightColor D_808008A4_chsunlightspell BT_DATA(4, overlays_ch_sunlightspell, 0x14) = { { 255, 255, 255 } };
f32 D_808008B0_chsunlightspell [ 3 ] BT_DATA(4, overlays_ch_sunlightspell, 0x20) = { -9000.0f, 8000.0f, -3100.0f };
ActorData D_808008BC_chsunlightspell [1] BT_DATA(4, overlays_ch_sunlightspell, 0x2C) = { { 305, 663, 2344, 1, 0, (void (*)(struct Actor *))func_80800048_chsunlightspell, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800768_chsunlightspell, 0, 0, 0, 0, 2, 4096, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chsunlightspell, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_808007CC_chsunlightspell, 0 } };
