#include "common.h"

/* extern */

void func_80800000_chmumbohealspell(s32 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_800FFA88(BtIntPtr);
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
    s32 _subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 _sumumbofx_entrypoint_14(BtIntPtr);
    f32 _sumumbofx_entrypoint_21(BtIntPtr);
    s32 _sumumbofx_entrypoint_5(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_7(BtIntPtr, f32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800FFA88(BtIntPtr);
    void * func_80100094(Actor *, u32);
    f32 func_80103EAC(s32);
    void func_80800450_chmumbohealspell(void *, s32);
    s32 sp3C;
    s32 sp38;
    BtIntPtr sp34;
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
    s32 _capod_entrypoint_14(void);
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
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _chglowbo_entrypoint_6(void);
    s32 _chmumbopad_entrypoint_0(s32 arg0);
    void _glcutDll_entrypoint_6(u32, u32);
    void _sumumbofx_entrypoint_0(Actor *arg0, u32 arg1, s32 arg2, s16 arg3);
    void _sumumbofx_entrypoint_1(Actor *arg0, u32 arg1);
    void _sumumbofx_entrypoint_2(void *);
    void _sumumbofx_entrypoint_3(void *, f32);
    void _sumumbofx_entrypoint_4(void *);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_18(void *, f32);
    void _sumumbofx_entrypoint_24(void *, f32);
    void _sumumbofx_entrypoint_25(u8 *arg0, s32 arg1, BtIntPtr arg2);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
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
struct HealSpellVector { s32 values[3]; };
void func_80800740_chmumbohealspell(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _sumumbofx_entrypoint_6(u8 *arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, f32 *arg5, f32 *arg6, f32 *arg7);

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

void func_80800800_chmumbohealspell(Actor *arg0, BtIntPtr arg1) {
    void* func_80100094(Actor*, u32);
    void _sumumbofx_entrypoint_8(u8 *arg0, BtIntPtr arg1);
    void _sumumbofx_entrypoint_9(u8 *arg0, Gfx **arg1);
    if (func_80100094(arg0, 0U) != NULL) {
        _sumumbofx_entrypoint_9(func_80100094(arg0, 0U), arg1);
        _sumumbofx_entrypoint_8(func_80100094(arg0, 0U), arg1);
    }
}

OSThread *chmumbohealspell_entrypoint_0(void)
{
    extern ActorData D_80800900_chmumbohealspell[];

    return (OSThread *) D_80800900_chmumbohealspell;
}
/* data_to_c.py: from asm/data/overlays/ch/mumbo/healspell.data.s */
void func_80105834(Actor*);
void func_80108ED0();
void func_80107C2C();
s32 D_808008D0_chmumbohealspell [ 3 ] BT_DATA(4, overlays_ch_mumbo_healspell, 0x0) = { 0, 0, 0 };
struct HealSpellVector D_808008DC_chmumbohealspell BT_DATA(4, overlays_ch_mumbo_healspell, 0xC) = { { 1119092736, 1132920832, 0 } };
struct HealSpellVector D_808008E8_chmumbohealspell BT_DATA(4, overlays_ch_mumbo_healspell, 0x18) = { { 0, 0, 0 } };
struct HealSpellVector D_808008F4_chmumbohealspell BT_DATA(4, overlays_ch_mumbo_healspell, 0x24) = { { 1148846080, 1140457472, -997785600 } };
ActorData D_80800900_chmumbohealspell [1] BT_DATA(4, overlays_ch_mumbo_healspell, 0x30) = { { 344, 1240, -1, 1, 0, (void (*)(struct Actor *))func_80800074_chmumbohealspell, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800800_chmumbohealspell, 0, 1073741824, 0, 0, 0, 1024, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chmumbohealspell, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1024, (void (*)(struct Actor *, long, long))func_808003A8_chmumbohealspell, 0 } };
