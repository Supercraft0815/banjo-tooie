#include "common.h"

/* extern */

void func_80800000_chgoldstatue(s32 arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(s32, s32, s32, s16);
    s32 _sumumbofx_entrypoint_15(s32, s32);
    s32 _sumumbofx_entrypoint_2(s32);
    s32 _sumumbofx_entrypoint_24(s32, s32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    s32 sp1C;
    s32 temp_v0;

    _sumumbofx_entrypoint_0(arg0, 1, 0x2D, _chmumbopad_entrypoint_0(2));
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

void func_80800094_chgoldstatue(s32 arg0)
{
    _sumumbofx_entrypoint_1(arg0,1);
}

/* extern */

void func_808000B4_chgoldstatue(Actor *arg0, s32 arg1) {
    s32 _sumumbofx_entrypoint_10(u8 *);
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    void func_800DF5D8(u32, u32, u32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101870(s32, s32);
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

s32 func_80800150_chgoldstatue(s32 arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _capod_entrypoint_14(void);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void func_80090734(s32, f32 *);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    s32 func_800DA524(s32);
    u32 func_800F54E4(void);
    s32 func_800F7D38(s32, s32, void *, f32);
    s32 func_80101180(s32, s32, s32);
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
    }
}

/* extern */

void func_808002C8_chgoldstatue(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddieDll_entrypoint_1();
    s32 func_800DA524(s32);
    s32 func_8010D278();
    s32 func_80800150_chgoldstatue(s32, s32);
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

void func_8080032C_chgoldstatue(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 _sumumbofx_entrypoint_14(s32);
    void _sumumbofx_entrypoint_17(void *, f32);
    f32 _sumumbofx_entrypoint_21(s32);
    s32 _sumumbofx_entrypoint_5(s32, s32);
    s32 _sumumbofx_entrypoint_6(s32, f32, f32, s32, s32, f32 *, f32 *, f32 *);
    s32 _sumumbofx_entrypoint_7(s32, f32, s32, s32, f32 *, f32 *, f32 *);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    typedef struct { f32 v[3]; } Vector;
    extern Vector D_80800910_chgoldstatue;
    extern Vector D_8080091C_chgoldstatue;
    extern Vector D_80800928_chgoldstatue;
    extern Vector D_80800934_chgoldstatue;
    Vector sp64 = D_80800910_chgoldstatue;
    f32 sp58[3];
    Vector sp4C = D_8080091C_chgoldstatue;
    Vector sp40 = D_80800928_chgoldstatue;
    Vector sp34 = D_80800934_chgoldstatue;
    s32 temp_s0;

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/statue/func_80800528_chgoldstatue.s")

OSThread *chgoldstatue_entrypoint_0(void)
{
    extern u8 D_80800990_chgoldstatue[];

    return (OSThread *) D_80800990_chgoldstatue;
}
