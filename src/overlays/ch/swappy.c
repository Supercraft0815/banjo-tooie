#include "common.h"

/* extern */

void func_80800000_chswappy(Actor *arg0) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    u8 func_800F8B88(void);
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
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);

    func_80101FDC(arg0, arg1);
    switch (arg1) {
    case 1:
        _subaddieDll_entrypoint_4(arg0, 0);
    case 2:
    case 3:
        return;
    } BT_NATIVE_ONLY(return 0;)
}

void func_80800108_chswappy(Actor *arg0) {
    struct SwappyFlags {
        u8 pad0[0x7E];
        BT_BITFIELD_ORDER(u8 pad7E_7 : 1, u8 pad7E_0 : 6);
        u8 active : 1;
        BT_BITFIELD_ORDER(u8 pad7E_0 : 6, u8 pad7E_7 : 1);
    };
    s32 _plsu_entrypoint_1(s32);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6BE4(BtIntPtr);
    s32 func_800F7B9C(BtIntPtr, s32);
    u8 func_800F8B88(void);
    void chswappy_entrypoint_0(Actor *, s32);
    s32 sp44;
    f32 sp38[3];
    s32 player;

    sp44 = (s32)arg0->unk70_10 == 2;
    switch (arg0->unk70_10) {
    case 1:
        player = _plsu_entrypoint_1(10);
        if (player != -1) {
            func_800F5A00(player, sp38);
            if (func_800EFFB4(arg0->position, 100.0f, sp38)) {
                _sudeflect_entrypoint_1(sp38, 125.0f, 0.0f, 40.0f, 28);
            }
        }
        break;
    case 2:
        func_808000B0_chswappy(arg0, 3);
        break;
    case 3:
        if (!func_800F6BE4(arg0->unk79_4) || func_800F7B9C(arg0->unk79_4, 0x41) == 2) {
            func_808000B0_chswappy(arg0, 1);
        }
        break;
    }
    if (func_800F8B88() == 2) {
        chswappy_entrypoint_0(arg0, sp44);
    }
    ((struct SwappyFlags *)arg0)->active = 0;
}

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
    Unk80132ED0 *func_800F55D0(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F7CF4(BtIntPtr, s32, void *);
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
    void _subaddiefade_entrypoint_2(void *arg0);
    void _subaddiefade_entrypoint_5(void *arg0);
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
            BT_BITFIELD_ORDER(u32 pad7C_15 : 17, u32 unk7C_0 : 12);
            BT_BITFIELD_ORDER(u32 unk7C_14 : 1, u32 unk7C_12 : 1);
            u32 pad7C_13 : 1;
            BT_BITFIELD_ORDER(u32 unk7C_12 : 1, u32 unk7C_14 : 1);
            BT_BITFIELD_ORDER(u32 unk7C_0 : 12, u32 pad7C_15 : 17);
        } flags;
    };
    void func_800E3980(f32 *);
    s32 func_800E3E8C(f32 *, f32);
    f32 func_800EEB40(f32 *, f32 *);
    u8 func_800F8B88(void);
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

void chswappy_entrypoint_0(Actor *arg0, s32 arg1) {
    BtIntPtr func_800B5BE4(s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern s32 D_80800690_chswappy[];
    extern u16 D_808006CC_chswappy[];
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    BtIntPtr particles;
    f32 sp7C[3];
    s32 i;

    if (arg0->unk7C_12) {
        if (arg1 != 0) {
            particles = func_800B5BE4(0x1D);
            func_800BA3FC(particles, 0x9DE);
        } else {
            i = func_800DC128(0, 3);
            particles = func_800B5BE4(i + 0x1E);
            func_800BA3FC(particles, D_808006CC_chswappy[i]);
        }
        func_800E3980(spA4);
        func_800F18FC(arg0->position, spA4, sp7C);
        func_800EE7F8(sp98, arg0->position);
        sp98[1] -= 200.0f;
        for (i = 0; i != 2; i++) {
            func_800EEB9C(sp8C, sp7C[1] + func_800DC178(-90.0f, 90.0f), 50.0f);
            func_800EF04C(sp8C, arg0->position);
            sp8C[1] += -30.0f + func_800DC178(0.0f, 100.0f);
            func_800BABB8(particles, sp8C, sp98, 1.0f, D_80800690_chswappy);
        }
    }
}

OSThread *chswappy_entrypoint_1(void)
{
    extern ActorData D_808006D4_chswappy[];

    return (OSThread *) D_808006D4_chswappy;
}
/* data_to_c.py: from asm/data/overlays/ch/swappy.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800690_chswappy [15] BT_DATA(4, overlays_ch_swappy, 0x0) = { 2818150, 8388652, 50, 0, 6553600, 2621240, -13107000, 13107234, 4980838, 2490419, 1376307, 11730966, 262195, 131354, 0 };
u16 D_808006CC_chswappy [4] BT_DATA(4, overlays_ch_swappy, 0x3C) = { 0x9E4, 0x9E0, 0x9E2, 0 };
ActorData D_808006D4_chswappy [1] BT_DATA(4, overlays_ch_swappy, 0x44) = { { 618, 344, 1787, 1, 0, (void (*)(struct Actor *))func_80800108_chswappy, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808003DC_chswappy, 0, 0, 0, 0, 0, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chswappy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 17408, (void (*)(struct Actor *, long, long))func_80800300_chswappy, 0 } };
