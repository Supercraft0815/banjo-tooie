#include "common.h"

/* extern */

void func_80800000_chmumbohealspell(s32 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_800FFA88(s32);
    void func_80103110(void *, s32);
    if ((func_800DA298(0x15E) != 0) && (func_800EA05C() == 0x155)) {
        func_800FFA88(*arg0);
    } else if (func_800DA298(0x189) == 0) {
        func_800FFA88(*arg0);
    }
    func_80103110(arg0, 0);
}

/* extern */

void func_80800074_chmumbohealspell(Actor *arg0) {
    void func_80800740_chmumbohealspell(Actor *arg0);
    s32 _subaddiefind_entrypoint_2(s32, s32);
    s32 _sumumbofx_entrypoint_14(s32);
    f32 _sumumbofx_entrypoint_21(s32);
    s32 _sumumbofx_entrypoint_5(s32, s32);
    s32 _sumumbofx_entrypoint_7(s32, f32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    void * func_80100094(Actor *, u32);
    f32 func_80103EAC(s32);
    void func_80800450_chmumbohealspell(void *, s32);
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 temp_v0;

    switch (((Actor *)arg0)->unk70_10) {
    case 2:
        if (func_800DA298(0x9DE) != 0) {
            func_80800450_chmumbohealspell(arg0, 3);
            return;
        }
    case 1:
    case 8:
    case 11:
    default:
        return;
    case 3:
        func_80800740_chmumbohealspell(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(arg0, 4);
            return;
        }
        break;
    case 4:
        func_80800740_chmumbohealspell(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 0));
        _sumumbofx_entrypoint_5(func_80100094(arg0, 0), 0x40800000);
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(arg0, 5);
            return;
        }
        break;
    case 5:
        func_80800740_chmumbohealspell(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(arg0, 6);
            return;
        }
        break;
    case 6:
        func_80800740_chmumbohealspell(arg0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(arg0, 8);
            return;
        }
        break;
    case 7:
        func_800FFA88(arg0->unk0);
        return;
    case 9:
        temp_v0 = _subaddiefind_entrypoint_2(0x52D, 0);
        sp3C = temp_v0;
        if (temp_v0 != 0) {
            sp34 = func_80100094(arg0, 0);
            _sumumbofx_entrypoint_7(sp34, func_80103EAC(sp3C), 0, 0x3C, sp3C + 4, 0, 0);
        }
        _sumumbofx_entrypoint_14(func_80100094(arg0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(arg0, 0xA);
            return;
        }
        break;
    case 10:
        sp38 = _subaddiefind_entrypoint_2(0x52D, 0);
        sp34 = func_80100094(arg0, 0);
        _sumumbofx_entrypoint_7(sp34, func_80103EAC(sp38), 0, 0x3C, sp38 + 4, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(arg0, 0xB);
        }
        break;
    }
}

s32 func_808003A8_chmumbohealspell(void *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_14(void);
    void func_80103110(void *, s32);
    void func_80800450_chmumbohealspell(void *, s32);

    switch (arg1) {
        case 0x4B:
            func_80800450_chmumbohealspell(arg0, 2);
            func_80103110(arg0, 1);
            return 1;
        case 0xB:
            if (arg2 == 0x10) {
                _capod_entrypoint_14();
                func_80800450_chmumbohealspell(arg0, 7);
                return 4;
            }
            return 3;
        case 0x49:
            if (arg2 == 0x71) {
                func_80800450_chmumbohealspell(arg0, 9);
                return 1;
            }
            return 0;
    }
    return 0;
}

void func_80800450_chmumbohealspell(void *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chglowbo_entrypoint_6(void);
    s16 _chmumbopad_entrypoint_0(s32);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void _sumumbofx_entrypoint_2(void *);
    void _sumumbofx_entrypoint_3(void *, f32);
    void _sumumbofx_entrypoint_4(void *);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_18(void *, f32);
    void _sumumbofx_entrypoint_24(void *, f32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    void func_80102424(Actor *, s32);
    void func_80103110(void *, s32);
    void func_8010A800(Actor *, s32);
    extern s32 D_808008D0_chmumbohealspell[3];
    s32 sp2C[3];
    Actor *actor = arg0;

    switch (arg1) {
    case 1:
        break;
    case 2:
        func_80103110(actor, 1);
        break;
    case 3:
        sp2C[0] = 0;
        sp2C[1] = 0;
        sp2C[2] = 0;
        _sumumbofx_entrypoint_0(actor, 0, 0x3C, _chmumbopad_entrypoint_0(0x10));
        _sumumbofx_entrypoint_2(func_80100094(actor, 0));
        _sumumbofx_entrypoint_25(func_80100094(actor, 0), 0x7D, sp2C);
        _sumumbofx_entrypoint_24(func_80100094(actor, 0), 0.65f);
        _sumumbofx_entrypoint_15(func_80100094(actor, 0), 3.0f);
        _capod_entrypoint_13(actor->unk0, actor->unk0, 0x10, 0x800);
        func_8010A800(actor, 2);
        break;
    case 4:
        _sumumbofx_entrypoint_18(func_80100094(actor, 0), 4.0f);
        _chglowbo_entrypoint_6();
        break;
    case 5:
        _sumumbofx_entrypoint_17(func_80100094(actor, 0), 3.0f);
        break;
    case 6:
        _sumumbofx_entrypoint_16(func_80100094(actor, 0), 3.0f);
        break;
    case 7:
        _glcutDll_entrypoint_6(0x121, 0x71);
        break;
    case 8:
        _sumumbofx_entrypoint_1(actor, 0);
        break;
    case 9:
        func_80103110(actor, 1);
        _sumumbofx_entrypoint_0(actor, 0, 0x3C, _chmumbopad_entrypoint_0(0x10));
        _sumumbofx_entrypoint_2(func_80100094(actor, 0));
        _sumumbofx_entrypoint_25(func_80100094(actor, 0), 0x7D, D_808008D0_chmumbohealspell);
        _sumumbofx_entrypoint_24(func_80100094(actor, 0), 0.65f);
        _sumumbofx_entrypoint_17(func_80100094(actor, 0), 3.0f);
        _sumumbofx_entrypoint_3(func_80100094(actor, 0), 375.0f);
        _sumumbofx_entrypoint_4(func_80100094(actor, 0));
        _capod_entrypoint_13(actor->unk0, actor->unk0, 0, 0x2900);
        break;
    case 10:
        _sumumbofx_entrypoint_16(func_80100094(actor, 0), 3.0f);
        func_80101180(0x52D, 0x33, 0);
        break;
    case 11:
        _sumumbofx_entrypoint_1(actor, 0);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0x15E);
        break;
    }
    func_80102424(actor, arg1);
}

void func_80800740_chmumbohealspell(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, void *, void *, void *);
    struct HealSpellVector { s32 values[3]; };
    extern struct HealSpellVector D_808008DC_chmumbohealspell;
    extern struct HealSpellVector D_808008E8_chmumbohealspell;
    extern struct HealSpellVector D_808008F4_chmumbohealspell;
    struct HealSpellVector sp44 = D_808008DC_chmumbohealspell;
    struct HealSpellVector sp38 = D_808008E8_chmumbohealspell;
    struct HealSpellVector sp2C = D_808008F4_chmumbohealspell;

    _sumumbofx_entrypoint_6(func_80100094(arg0, 0), 1400.0f, 500.0f,
                          0, 60, &sp38, &sp2C, &sp44);
}

/* extern */

void func_80800800_chmumbohealspell(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 _sumumbofx_entrypoint_9(u8 *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _sumumbofx_entrypoint_9(func_80100094(arg0, 0U), arg1);
        _sumumbofx_entrypoint_8(func_80100094(arg0, 0U), arg1);
    }
}

OSThread *chmumbohealspell_entrypoint_0(void)
{
    extern u8 D_80800900_chmumbohealspell[];

    return (OSThread *) D_80800900_chmumbohealspell;
}
