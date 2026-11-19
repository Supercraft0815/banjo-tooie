#include "common.h"

/* extern */

void func_80800000_chgoldstatue(BtIntPtr arg0) {
    BT_IDO_ONLY(s16 _chmumbopad_entrypoint_0(s32);) BT_NATIVE_ONLY(s32 _chmumbopad_entrypoint_0(s32);)
    s32 _sumumbofx_entrypoint_0(BtIntPtr, s32, s32, s16);
    s32 _sumumbofx_entrypoint_15(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_2(BtIntPtr);
    s32 _sumumbofx_entrypoint_24(BtIntPtr, s32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    _sumumbofx_entrypoint_0(arg0, 1, 0x2D, BT_NATIVE_ONLY((s16)) _chmumbopad_entrypoint_0(2));
    temp_v0 = func_80100094(arg0, 1);
    sp1C = temp_v0;
    _sumumbofx_entrypoint_2(temp_v0);
    _sumumbofx_entrypoint_24(sp1C, 0x3F266666);
    if (func_800DA298(0x57C) == 0) {
        _sumumbofx_entrypoint_15(sp1C, 0x40400000);
        return;
    }
    _sumumbofx_entrypoint_15(sp1C, 0x3E800000);
}

void func_80800094_chgoldstatue(BtIntPtr arg0)
{
    _sumumbofx_entrypoint_1(arg0,1);
}

/* extern */

void func_808000B4_chgoldstatue(Actor *arg0, s32 arg1) {
    s32 _sumumbofx_entrypoint_10(u8 *);
    s32 _sumumbofx_entrypoint_8(u8 *, BtIntPtr);
    void func_800DF5D8(u32, u32, u32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101870(BtIntPtr, BtIntPtr);
    u8 *sp1C;
    s32 sp18;

    sp1C = func_80100094(arg0, 1);
    func_80101870(arg0, arg1);
    if (sp1C != 0) {
        sp18 = _sumumbofx_entrypoint_10(sp1C);
        _sumumbofx_entrypoint_8(sp1C, arg1);
        func_800DF5D8(0xFF, (s32) (((f32) sp18 * 0.5f) + 128.0f), 0xFF, 0xFF);
    }
}

s32 func_80800150_chgoldstatue(BtIntPtr arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _capod_entrypoint_14(void);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_80090734(s32, f32 *);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    s32 func_800DA524(s32);
    u32 func_800F54E4(void);
    s32 func_800F7D38(BtIntPtr, s32, void *, f32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    s32 func_801032B0(Actor *, u16, u16);
    void func_8010381C(Actor *);
    Actor *actor = (Actor *)arg0;

    func_80102424(actor, arg1);
    switch (actor->unk70_10) {
        case 2:
            _subaddieDll_entrypoint_4(actor, 1);
            func_801032B0(actor, 0x673, actor->unk0->unk16);
            if (func_800DA298(0x57C) == 0) {
                _capod_entrypoint_13(actor->unk0, 0, 2, 0x20);
            } else {
                _capod_entrypoint_13(actor->unk0, 0, 8, 0x20);
            }
            func_80101180(0x2B0, 0xBB, 2);
            func_80800000_chgoldstatue(arg0);
            func_80090734(2, actor->position);
            break;
        case 3:
            func_800DA3B8(0x57C, 1);
            break;
        case 5:
            _capod_entrypoint_14();
            func_80800094_chgoldstatue(arg0);
            func_800F7D38(func_800F54E4(), 0x3F, actor->position, actor->rotation[1]);
            func_800DA524(0x9DE);
            func_8010381C(actor);
            actor->unk64_16 = 0;
            break;
        case 6:
            if (actor->unk64_16) {
                func_8010381C(actor);
                actor->unk64_16 = 0;
            }
            break;
        case 7:
            func_801032B0(actor, 0x673, actor->unk0->unk16);
            break;
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_808002C8_chgoldstatue(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddieDll_entrypoint_1();
    s32 func_800DA524(s32);
    s32 func_8010D278();
    s32 func_80800150_chgoldstatue(BtIntPtr, s32);
    _subaddieDll_entrypoint_1();
    if (func_8010D278() == 0xE) {
        func_80800150_chgoldstatue(arg0, 6);
        return;
    }
    func_800DA524(0x9DE);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800150_chgoldstatue(arg0, 7);
    }
}
typedef struct { f32 v[3]; } Vector;
void func_8080032C_chgoldstatue(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 _sumumbofx_entrypoint_14(BtIntPtr);
    void _sumumbofx_entrypoint_17(void *, f32);
    f32 _sumumbofx_entrypoint_21(BtIntPtr);
    s32 _sumumbofx_entrypoint_5(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_6(BtIntPtr, f32, f32, s32, s32, f32 *, f32 *, f32 *);
    s32 _sumumbofx_entrypoint_7(BtIntPtr, f32, s32, s32, f32 *, f32 *, f32 *);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);

    extern Vector D_80800910_chgoldstatue;
    extern Vector D_8080091C_chgoldstatue;
    extern Vector D_80800928_chgoldstatue;
    extern Vector D_80800934_chgoldstatue;
    Vector sp64 = D_80800910_chgoldstatue;
    f32 sp58[3];
    Vector sp4C = D_8080091C_chgoldstatue;
    Vector sp40 = D_80800928_chgoldstatue;
    Vector sp34 = D_80800934_chgoldstatue;
    BtIntPtr temp_s0;

    temp_s0 = func_80100094(arg0, 1);
    if (arg0->unk7C_12) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 2, sp58);
        _sumumbofx_entrypoint_7(temp_s0, 175.0f, 0, 20, sp40.v, sp58, sp64.v);
        _sumumbofx_entrypoint_6(temp_s0, 150.0f, 150.0f, 21, 35, sp34.v, sp58, sp64.v);
        _sumumbofx_entrypoint_6(temp_s0, 150.0f, 100.0f, 36, 45, sp4C.v, sp58, sp64.v);
        _sumumbofx_entrypoint_14(temp_s0);
        if (arg0->unk70_10 == 2 && _sumumbofx_entrypoint_21(temp_s0) == 0.0f &&
            _sumumbofx_entrypoint_5(temp_s0, 0x40000000)) {
            _sumumbofx_entrypoint_17(temp_s0, 1.0f);
            if (func_800DA298(0x57C) == 0) {
                func_80800150_chgoldstatue(arg0, 3);
                return;
            }
            func_80800150_chgoldstatue(arg0, 4);
        }
    }
}

void func_80800528_chgoldstatue(Actor *arg0) {
    void _chglowbo_entrypoint_6(void);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    u8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u32, u32 *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void _sumumbofx_entrypoint_16(void *, f32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    u32 func_800F54E4(void);
    s32 func_800F7B9C(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    s32 func_8010C500(Actor *);
    extern u32 D_80800890_chgoldstatue[];
    extern u32 D_808008A0_chgoldstatue[];
    extern u32 D_808008B8_chgoldstatue[];
    extern f32 D_80800940_chgoldstatue[];
    extern f32 D_80800954_chgoldstatue[];
    extern u32 D_80800968_chgoldstatue[];
    extern u32 D_8080097C_chgoldstatue[];
    s32 sp34;
    void *sp30;

    sp34 = 0;
    if (!arg0->unk64_17) {
        sp30 = func_80100094(arg0, 1);
        switch (arg0->unk70_10) {
        case 1:
            _sudeflect_entrypoint_1(arg0->position, 240.0f, 0.0f, 100.0f, 14);
            if (func_800DA298(0x9DE)) {
                func_80800150_chgoldstatue((BtIntPtr)arg0, 2);
            }
            break;
        case 2:
            func_8080032C_chgoldstatue(arg0);
            break;
        case 3:
            if (func_80101E14(arg0, 0.35f)) {
                _chglowbo_entrypoint_6();
            }
            if (func_80101F24(arg0) < 0.38f) {
                sp34 = 1;
            }
            if (func_80101E14(arg0, 0.38f)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800890_chgoldstatue);
            } else if (func_80101E4C(arg0, D_80800940_chgoldstatue)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808008A0_chgoldstatue);
            } else if (func_80101E4C(arg0, D_80800954_chgoldstatue)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808008B8_chgoldstatue);
            }
            if (func_80101E14(arg0, 0.39f)) {
                func_800DA544(0x9DF);
                _sumumbofx_entrypoint_16(sp30, 3.0f);
            }
            func_8080032C_chgoldstatue(arg0);
            if (func_80101DDC(arg0)) {
                func_80800150_chgoldstatue((BtIntPtr)arg0, 5);
            }
            break;
        case 4:
            func_8080032C_chgoldstatue(arg0);
            if (func_80101F24(arg0) < 0.38f) {
                sp34 = 1;
            }
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800890_chgoldstatue, 0.38f);
            if (func_80101E14(arg0, 0.34f)) {
                _sumumbofx_entrypoint_16(sp30, 0.25f);
                func_800DA544(0x9DF);
            } else if (func_80101E14(arg0, 0.39f)) {
                func_80800150_chgoldstatue((BtIntPtr)arg0, 5);
            }
            break;
        case 5:
            if (!func_8010C500(arg0)) {
                func_80800150_chgoldstatue((BtIntPtr)arg0, 6);
            }
            break;
        case 6:
            if (func_8010C500(arg0)) {
                func_800F7B9C(func_800F54E4(), 0x82);
            }
            break;
        }
        if (sp34) {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800968_chgoldstatue);
            arg0->unk6C_0 = _subaddieaudioloop_entrypoint_7(arg0->unk6C_0, arg0->position, 1, D_8080097C_chgoldstatue, arg0->unk70_0);
        }
    }
}

OSThread *chgoldstatue_entrypoint_0(void)
{
    extern ActorData D_80800990_chgoldstatue[];

    return (OSThread *) D_80800990_chgoldstatue;
}
/* data_to_c.py: from asm/data/overlays/ch/gold/statue.data.s */
extern u8 D_808008D0_chgoldstatue[];
void func_80105834(Actor*);
void func_80107C2C();
u32 D_80800890_chgoldstatue [4] BT_DATA(4, overlays_ch_gold_statue, 0x0) = { 0x1304CC, 0x167D00, 0x109C4, 0x13880000 };
u32 D_808008A0_chgoldstatue [6] BT_DATA(4, overlays_ch_gold_statue, 0x10) = { 0x1304A1, 0xD00E1, 0xF30016, 0x2AF80001, 0x9C41388, 0 };
u32 D_808008B8_chgoldstatue [6] BT_DATA(4, overlays_ch_gold_statue, 0x28) = { 0x130632, 0xD008C, 0xA60016, 0x1F400001, 0x9C41388, 0 };
u8 D_808008D0_chgoldstatue[64] BT_DATA(4, overlays_ch_gold_statue, 0x40) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x59, 0x99, 0x9A, 0x01, 0xED, 0x00, 0x44, 0x41, 0x59, 0x99, 0x9A, 0x01, 0xED, 0x00, 0x44, 0x41, 0x59, 0x99, 0x9A, 0x01, 0xED, 0x00, 0x02, 0x41, 0x59, 0x99, 0x9A, 0x01, 0xED, 0x00, 0x02, 0x40, 0xE0, 0x00, 0x00, 0x01, 0xEE, 0x00, 0x02, 0x40, 0xE0, 0x00, 0x00, 0x01, 0xEE, 0x00, 0x02, 0x40, 0xE0, 0x00, 0x00, 0x01, 0xEE, 0x00, 0x01 };
Vector D_80800910_chgoldstatue BT_DATA(4, overlays_ch_gold_statue, 0x80) = { { 0.0f, 0.0f, 0.0f } };
Vector D_8080091C_chgoldstatue BT_DATA(4, overlays_ch_gold_statue, 0x8C) = { { 0.0f, 250.0f, 0.0f } };
Vector D_80800928_chgoldstatue BT_DATA(4, overlays_ch_gold_statue, 0x98) = { { 0.0f, 75.0f, 0.0f } };
Vector D_80800934_chgoldstatue BT_DATA(4, overlays_ch_gold_statue, 0xA4) = { { 0.0f, -250.0f, 0.0f } };
f32 D_80800940_chgoldstatue [5] BT_DATA(4, overlays_ch_gold_statue, 0xB0) = { 0.43f, 0.56f, 0.77f, 0.9f, -1.0f };
f32 D_80800954_chgoldstatue [5] BT_DATA(4, overlays_ch_gold_statue, 0xC4) = { 0.5f, 0.66f, 0.84f, 0.97f, -1.0f };
u32 D_80800968_chgoldstatue [5] BT_DATA(4, overlays_ch_gold_statue, 0xD8) = { 0x1304AD, 0x1661A8, 0xA0099, 0x109C4, 0x13880000 };
u32 D_8080097C_chgoldstatue [5] BT_DATA(4, overlays_ch_gold_statue, 0xEC) = { 0x1304A9, 0x1661A8, 0xA0100, 0x109C4, 0x13880000 };
ActorData D_80800990_chgoldstatue [1] BT_DATA(4, overlays_ch_gold_statue, 0x100) = { { 629, 355, 2110, 1, (void *)D_808008D0_chgoldstatue, (void (*)(struct Actor *))func_80800528_chgoldstatue, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808000B4_chgoldstatue, 65536000, 0, 0, 0, 8, 321, 0, 0, 0, 0, (void (*)(struct Actor *))func_808002C8_chgoldstatue, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, 0, 0 } };
