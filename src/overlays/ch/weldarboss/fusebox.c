#include "common.h"

OSThread *chweldarbossfusebox_entrypoint_0(void)
{
    extern ActorData D_80800670_chweldarbossfusebox[];

    return (OSThread *) D_80800670_chweldarbossfusebox;
}

OSThread *chweldarbossfusebox_entrypoint_1(void)
{
    extern ActorData D_808006B8_chweldarbossfusebox[];

    return (OSThread *) D_808006B8_chweldarbossfusebox;
}

OSThread *chweldarbossfusebox_entrypoint_2(void)
{
    extern ActorData D_80800700_chweldarbossfusebox[];

    return (OSThread *) D_80800700_chweldarbossfusebox;
}

/* extern */

void func_80800024_chweldarbossfusebox(BtIntPtr arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3)) {
    s32 _subaddiefade_entrypoint_14(BtIntPtr);
    BT_IDO_ONLY(s32 func_800BF744(s32, s32);) BT_NATIVE_ONLY(void func_800BF744(s32, s32);)
    s32 func_800DA298(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    s32 func_80103014(BtIntPtr);
    func_800BF744(2, func_800DA298(0x18C));
    func_800EFA4C((f32 *)(arg0 + 4), -1800.0f, 1200.0f, -2200.0f);
    func_80103014(arg0);
    _subaddiefade_entrypoint_14(arg0);
    if (func_800DA298(0x18C) != 0) {
        func_800FFAB0(arg0);
    }
}

s32 func_80800098_chweldarbossfusebox(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800140_chweldarbossfusebox(BtIntPtr);
    f32 sp1C[3];

    switch (arg1) {
    case 5:
        func_800EE7F8(sp1C, arg0->position);
        func_800EF1B8(sp1C, arg0->rotation[1], -400.0f);
        _chexploder_entrypoint_3(arg0, sp1C, 0xB);
        func_80101180(0x33D, 0xA, 0);
        break;
    case 0x90:
        func_80800140_chweldarbossfusebox((BtIntPtr)arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800140_chweldarbossfusebox(BtIntPtr arg0) {
    s32 _chexploder_entrypoint_15(BtIntPtr, s32, s32);
    s32 _chexploder_entrypoint_6(BtIntPtr, s32, s32);
    s32 _chexploder_entrypoint_7(BtIntPtr, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(BtIntPtr, s32, s32 *);
    BT_IDO_ONLY(s32 func_800BF744(s32, s32);) BT_NATIVE_ONLY(void func_800BF744(s32, s32);)
    BtIntPtr func_80101080();
    BtIntPtr func_80106790(BtIntPtr);
    extern s32 D_80800660_chweldarbossfusebox[4];
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    temp_v0 = func_80106790(func_80101080());
    sp1C = temp_v0;
    _chexploder_entrypoint_6(temp_v0, 0x44E10000, 0x44FA0000);
    _chexploder_entrypoint_7(sp1C, 0xC4AF0000, 0xC4960000);
    _chexploder_entrypoint_15(sp1C, 2, 0x3FC00000);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800660_chweldarbossfusebox);
    func_800BF744(2, 1);
}

/* extern */

void func_808001BC_chweldarbossfusebox(f32 *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3)) {
    void func_800EFA4C(f32 position[3], f32 x, f32 y, f32 z);
    s32 _subaddiefade_entrypoint_14(BtIntPtr);
    s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    BT_IDO_ONLY(s32 func_800BF744(s32, s32);) BT_NATIVE_ONLY(void func_800BF744(s32, s32);)
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_80103014(BtIntPtr);
    f32 sp30[6];

    func_800BF744(4, func_800DA298(0x18C));
    func_800EFA4C(arg0 + 1, 0.0f, 4900.0f, -2300.0f);
    func_80103014(arg0);
    _subaddiefade_entrypoint_14(arg0);
    if (func_800DA298(0x18C) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (_subaddiemarker_entrypoint_1(arg0, 0x320, 0x35, sp30, 1) != 0) {
        func_800EE7F8(arg0 + 6, sp30);
    }
}

s32 func_80800268_chweldarbossfusebox(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_8080032C_chweldarbossfusebox(BtIntPtr);
    void func_80800384_chweldarbossfusebox(f32 *);

    switch (arg1) {
        case 5:
            if (++arg0->unk6C_0 == 2) {
                _chexploder_entrypoint_3(arg0, (u8 *)arg0 + 4, 0xB);
                func_80101180(0x465, 7, 0);
                func_80101180(0x3B3, 0x4F, 0);
                func_80800384_chweldarbossfusebox((f32 *)arg0);
            }
            break;
        case 0x90:
            func_8080032C_chweldarbossfusebox((BtIntPtr)arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080032C_chweldarbossfusebox(BtIntPtr arg0) {
    s32 _chexploder_entrypoint_15(BtIntPtr, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(BtIntPtr, s32, s32 *);
    BT_IDO_ONLY(s32 func_800BF744(s32, s32);) BT_NATIVE_ONLY(void func_800BF744(s32, s32);)
    BtIntPtr func_80101080();
    BtIntPtr func_80106790(BtIntPtr);
    extern s32 D_80800660_chweldarbossfusebox[4];
    _chexploder_entrypoint_15(func_80106790(func_80101080()), 2, 0x3FC00000);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800660_chweldarbossfusebox);
    func_800BF744(4, 1);
}

void func_80800384_chweldarbossfusebox(f32 *arg0) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800748_chweldarbossfusebox[18];
    f32 sp24[3];

    func_800EE7F8(sp24, arg0 + 6);
    sp24[1] += 400.0f;
    sp24[2] -= 100.0f;
    func_800BABB8(0, arg0 + 6, sp24, 1.0f, D_80800748_chweldarbossfusebox);
}

void func_808003F8_chweldarbossfusebox(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80105A9C(Actor *arg0, f32 arg1);
    f32 height;

    if (func_800DA298(0x18C) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (arg0->unk74_7 == 0x32) {
        arg0->unk58 = 0.0f;
    } else {
        arg0->unk58 = 0.5f;
    }
    if (arg0->unk74_7 == 0x32) {
        height = 750.0f;
    } else {
        height = 700.0f;
    }
    func_80105A9C(arg0, height);
}
struct FuseboxSettings { f32 value[2]; };
void func_8080049C_chweldarbossfusebox(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_8001210C(s32);
    s32 func_800C8A98(void);
    void func_800C8B84(volatile s32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_800D90A4(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    void func_808005F8_chweldarbossfusebox(BtIntPtr);

    extern struct FuseboxSettings D_80800790_chweldarbossfusebox;
    extern u32 D_80800798_chweldarbossfusebox[][3];
    extern u32 D_808007B0_chweldarbossfusebox[];
    f32 position[3];
    struct FuseboxSettings settings;

    if (func_800D90A4(&arg0->unk58) != 0) {
        if (arg0->actorData[4] == 0) {
            settings = D_80800790_chweldarbossfusebox;
            arg0->actorData[4] = func_800C8A98();
            func_800C8D4C(arg0->actorData[4], settings.value);
        }
        func_800EE7F8(position, arg0->position);
        position[2] += 200.0f;
        func_800C8CB8(arg0->actorData[4], position);
        func_800C8E84(arg0->actorData[4], D_80800798_chweldarbossfusebox[func_8001210C(1)]);
        func_80105834(arg0);
        func_808005F8_chweldarbossfusebox((BtIntPtr)arg0);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808007B0_chweldarbossfusebox);
        if (func_80105A5C(arg0) != 0) {
            func_800C8B84(arg0->actorData[4]);
            arg0->actorData[4] = 0;
            func_80101180(0x3AE, 5, 0);
            func_800FFAB0(arg0);
        }
    }
}

s32 func_808005C0_chweldarbossfusebox(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80103110(Actor*, u32);
    if (arg1 == 0xA) {
        func_80103110(arg0, 1U);
        return 1;
    }
    return 0;
}

void func_808005F8_chweldarbossfusebox(BtIntPtr arg0) {
    s32 func_8001210C(s32);
    BtIntPtr func_800BBCB8(BtIntPtr, BtIntPtr, s32, s32, s32 *);
    extern s32 D_808007BC_chweldarbossfusebox[13];
    if (func_8001210C(3) != 0) {
        func_800BBCB8(arg0 + 4, 0, 0x3F800000, 2, D_808007BC_chweldarbossfusebox);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/weldarboss/fusebox.data.s */
void func_80102EC0();
void func_80105834 ( Actor * );
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void func_8010A730();
s32 D_80800660_chweldarbossfusebox[4] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0x0) = { 1246227, 655590, 1469792, 131072 };
ActorData D_80800670_chweldarbossfusebox [1] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0x10) = { { 344, 837, 2156, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 1028, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chweldarbossfusebox, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800098_chweldarbossfusebox, 0 } };
ActorData D_808006B8_chweldarbossfusebox [1] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0x58) = { { 344, 942, 2161, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 1028, 0, 0, 0, 0, (void (*)(struct Actor *))func_808001BC_chweldarbossfusebox, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800268_chweldarbossfusebox, 0 } };
ActorData D_80800700_chweldarbossfusebox [1] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0xA0) = { { 344, 1130, 0, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_8080049C_chweldarbossfusebox, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_808003F8_chweldarbossfusebox, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 3586, (void (*)(struct Actor *, long, long))func_808005C0_chweldarbossfusebox, 0 } };
s32 D_80800748_chweldarbossfusebox[18] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0xE8) = { 135266326, 33554461, 165478445, 16384300, 1769532, 5242890, -16384000, 250, 655370, 1610743842, 25166336, 67110272, 1376256, 10027050, 1638438, 26804736, 2622976, 0 };
struct FuseboxSettings D_80800790_chweldarbossfusebox BT_DATA(4, overlays_ch_weldarboss_fusebox, 0x130) = { { 300.0f, 600.0f } };
u32 D_80800798_chweldarbossfusebox [2] [ 3 ] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0x138) = { { 0xC0, 0xC0, 0xFF }, { 0x80, 0x80, 0xA0 } };
u32 D_808007B0_chweldarbossfusebox [3] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0x150) = { 0x13052E, 0x166D60, 0x20000 };
s32 D_808007BC_chweldarbossfusebox[13] BT_DATA(4, overlays_ch_weldarboss_fusebox, 0x15C) = { 1903053, 1834858, -6553586, 5242980, 2293862, 2818176, 10027029, 128, 1446400, 0, 0, 0, 0 };
