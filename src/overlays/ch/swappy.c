#include "common.h"

/* extern */

void func_80800000_chswappy(Actor *arg0) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    s32 func_800F8B88();
    void func_80102FDC(Actor *, f32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    s32 func_808000B0_chswappy(void *, s32);
    func_80102FDC(arg0, arg0->scale * 0.6f);
    if (func_800F8B88() == 2) {
        _subaddiefade_entrypoint_1(arg0, 0xFF);
        func_80103110(arg0, 1);
        func_8010A590(arg0);
        func_808000B0_chswappy(arg0, 1);
        return;
    }
    _subaddiefade_entrypoint_1(arg0, 0);
    func_80103110(arg0, 0);
    func_8010A570(arg0);
    func_808000B0_chswappy(arg0, 1);
}

s32 func_808000B0_chswappy(void *arg0, s32 arg1) {
    void func_80101FDC(Actor *, u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);

    func_80101FDC(arg0, arg1);
    switch (arg1) {
    case 1:
        _subaddieDll_entrypoint_4(arg0, 0);
    case 2:
    case 3:
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/func_80800108_chswappy.s")

/* extern */

void func_80800234_chswappy(Actor *arg0, void *arg1) {
    struct SwappyContact {
        u8 pad0[0x1A];
        u16 characterIndex : 11;
        u16 pad1A : 5;
        u8 pad1C[8];
        u32 flags : 10;
        u32 pad24 : 22;
    };
    Unk80132ED0 *func_800F55D0(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_800F7CF4(s32, s32, void *);
    s32 func_808000B0_chswappy(void *, s32);
    struct SwappyContact *contact = arg1;
    s32 temp_a0;

    if (contact->flags == 0) {
        temp_a0 = contact->characterIndex;
        if ((func_800F64A4(temp_a0, 0x600) != 0) && ((arg0->unk74_7 != 0x32) || (func_800F55D0(temp_a0) != 0)) && ((arg0->unk70_10 == 3) || (func_800F7CF4(temp_a0, 0x40, arg0->position) == 2))) {
            arg0->unk79_4 = temp_a0;
            func_808000B0_chswappy(arg0, 2);
        }
    }
}

s32 func_80800300_chswappy(Actor *arg0, s32 arg1, void * volatile arg2) {
    s32 _subaddiefade_entrypoint_2();
    s32 _subaddiefade_entrypoint_5();
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    switch (arg1) {
        case 0x95:
            func_808000B0_chswappy(arg0, 1);
            break;
        case 0x16:
            func_808000B0_chswappy(arg0, 1);
            func_80103110(arg0, 1);
            func_8010A590(arg0);
            _subaddiefade_entrypoint_2(arg0);
            break;
        case 0x17:
            func_808000B0_chswappy(arg0, 1);
            func_80103110(arg0, 0);
            func_8010A570(arg0);
            _subaddiefade_entrypoint_5(arg0);
            break;
        case 0x3E:
            func_80800234_chswappy(arg0, arg2);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_808003DC_chswappy(Actor *arg0, s32 arg1) {
    union SwappyActorView {
        Actor actor;
        struct {
            u8 padding[0x7C];
            u32 pad7C_15 : 17;
            u32 unk7C_14 : 1;
            u32 pad7C_13 : 1;
            u32 unk7C_12 : 1;
            u32 unk7C_0 : 12;
        } flags;
    };
    void func_800E3980(f32 *);
    s32 func_800E3E8C(f32 *, f32);
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_800F8B88();
    void func_8010A73C(Actor *, s32);
    s32 sp34;
    f32 sp28[3];
    f32 *sp20[2];

    sp20[1] = arg0->position;
    sp34 = func_800E3E8C(sp20[1], 300.0f);
    func_8010A73C(arg0, arg1);
    if ((sp34 != 0) && (func_800F8B88() == 2)) {
        func_800E3980(sp28);
        if (func_800EEB40(sp20[1], sp28) < 6250000.0f) {
            arg0->unk7C_12 = 1;
        }
        ((union SwappyActorView *)(void *)arg0)->flags.unk7C_14 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swappy/chswappy_entrypoint_0.s")

OSThread *chswappy_entrypoint_1(void)
{
    extern u8 D_808006D4_chswappy[];

    return (OSThread *) D_808006D4_chswappy;
}
