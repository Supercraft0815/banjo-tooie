#include "common.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif
#include "core2/particle_colors.h"
#include "core2/actor_animation_entry.h"
void func_80800000_chquicksandbaddy(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _subaddieDll_entrypoint_1(Actor *);
    f32 func_800DC178(f32, f32);
    void func_800EFD24(f32 *);
    void func_800FFA88(Unk80132ED0 *);
    u32 *func_80100074(Actor *, u32, u32);
    f32 func_80800CC0_chquicksandbaddy(u8 *);
    Prop *props[3];
    s32 count;
    s32 i;
    f32 (*positions)[3];

    count = _gccubesearch_entrypoint_9(0x510, props, 3);
    if (count != 0) {
        positions = (f32 (*)[3])func_80100074(arg0, 1, 0x24);
        for (i = 0; i < count; i++) {
            _gspropctrl_entrypoint_11(props[i], positions[i]);
        }
        for (; i < 3; i++) {
            func_800EFD24(positions[i]);
        }
    }
    if (_subaddieDll_entrypoint_1(arg0) == 0) {
        func_800FFA88(arg0->unk0);
    } else {
    ((f32 *)arg0->actorData)[7] = arg0->position[1];
    arg0->unk58 = 0.2f;
    ((f32 *)arg0->actorData)[3] = 0.0f;
    arg0->unk54 = 0.0f;
    arg0->unk54 = arg0->position[1] - func_80800CC0_chquicksandbaddy((u8 *)arg0);
    ((f32 *)arg0->actorData)[4] = func_800DC178(20.0f, 30.0f);
    arg0->unk64_16 = 0;
    }
}

void func_80800140_chquicksandbaddy(Actor *arg0) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    s32 func_8008FC00(void);
    void func_800C4140(u32, f32 *, u32);
    f32 func_800C6920(f32 arg0[3], f32 arg1, f32 arg2, s32 arg3);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    s32 func_800CC338(f32 *, s32, s32);
    void *func_800CC63C(s32, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800D91B8(f32 *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(f32 *, f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_800F4F34(BtUIntPtr arg0, f32 *arg1, f32 arg2, f32 arg3);
    u32 func_800F54E4(void);
    BT_IDO_ONLY(f32 func_800F5628(BtIntPtr);) BT_NATIVE_ONLY(s32 func_800F5628(BtIntPtr);)
    s32 func_800F56AC(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6AA4(BtIntPtr);
    s32 func_800F6C5C(BtIntPtr);
    s32 func_800F7B9C(BtIntPtr, s32);
    int func_800F7C58(BtIntPtr arg0, s32 arg1, s32 arg2);
    void func_800F7D90(BtIntPtr, s32, f32 *, s32);
    void func_800FC660(s32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80101EE4(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103014(Actor *);
    f32 func_80103EAC(Actor *);
    void func_8010D254(f32 *);
    f32 func_80800CC0_chquicksandbaddy(u8 *);
    s32 func_80800CFC_chquicksandbaddy(Actor *, f32 *, f32 *);
    s32 func_80800DBC_chquicksandbaddy(Actor *);
    s32 func_80801154_chquicksandbaddy(Actor *, f32 *);
    void func_80800FC8_chquicksandbaddy(f32 *, f32, s32);
    void chquicksandbaddy_entrypoint_0(s32, BtIntPtr);
    extern ActorAnimationEntry D_808012A0_chquicksandbaddy[];
    extern u32 D_808012E0_chquicksandbaddy[];
    extern u32 D_808012F0_chquicksandbaddy[];
    extern u32 D_80801300_chquicksandbaddy[];
    extern u32 D_80801310_chquicksandbaddy[];
    extern f32 D_80801320_chquicksandbaddy[10][2];
    extern s32 D_80801370_chquicksandbaddy[8];
    f32 spB4[3];
    f32 spA8[3];
    f32 sp9C[3];
    f32 sp90[3];
    union {
        Actor actor;
        struct {
            u8 pad0[0x70];
            BT_BITFIELD_ORDER(u32 map : 7, u32 pad70_0 : 4);
            BT_BITFIELD_ORDER(u32 pad70_10 : 15, u32 region : 6);
            BT_BITFIELD_ORDER(u32 region : 6, u32 pad70_10 : 15);
            BT_BITFIELD_ORDER(u32 pad70_0 : 4, u32 map : 7);
        } bits;
    } *baddy;
    volatile s32 i;
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 angle;
    f32 (*p)[2];
    int next;
    f32 height;
    f32 sp3C[3];

    baddy = (void *)arg0;
    switch (arg0->unk70_10) {
    case 1:
        func_8010D254(spB4);
        if (func_800D90A4(&((f32 *)arg0->actorData)[4])) {
            func_800E3980(spA8);
            arg0->rotation[1] = func_800F1DF4(arg0->position, spA8);
            func_80102424(arg0, 6);
        }
        if (func_80800DBC_chquicksandbaddy(arg0)) {
            if (func_800F6AA4(func_800F54E4())) {
                arg0->actorData[5] = 1;
            } else {
                arg0->actorData[5] = 0;
            }
            if (func_800F7B9C(func_800F54E4(), 0x34)) {
                func_800EE7F8(arg0->position, spB4);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808012E0_chquicksandbaddy);
                _subaddieDll_entrypoint_4(arg0, 1);
                func_800F5A00(func_800F54E4(), arg0->position);
                arg0->position[1] = BT_IDO_ONLY(func_800F5628(func_800F54E4())) BT_NATIVE_ONLY(((union { s32 bits; f32 value; }){ .bits = func_800F5628(func_800F54E4()) }).value) + arg0->unk54;
                if (func_8008FC00() == 1) {
                    func_80102424(arg0, 5);
                    arg0->unk58 = 0.0f;
                    ((f32 *)arg0->actorData)[4] = 0.0f;
                } else {
                    func_80102424(arg0, 2);
                    arg0->unk58 = 0.5f;
                }
            }
        } else if (((f32 *)arg0->actorData)[7] < spB4[1]) {
            arg0->unk58 = 0.2f;
            if (func_800D90A4(&((f32 *)arg0->actorData)[3])) {
                ((f32 *)arg0->actorData)[3] = 0.5f;
                if (func_800F56AC(func_800F54E4()) != 0x14 && func_800F6C5C(func_800F54E4())) {
                    spB4[1] = BT_IDO_ONLY(func_800F5628(func_800F54E4())) BT_NATIVE_ONLY(((union { s32 bits; f32 value; }){ .bits = func_800F5628(func_800F54E4()) }).value);
                    func_800EE7F8((f32 *)arg0->actorData, spB4);
                    arg0->unk64_20 = 1;
                }
            }
        } else {
            arg0->unk58 = 0.2f;
        }
        break;
    case 2:
        if (func_800D90A4(&arg0->unk58)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808012F0_chquicksandbaddy);
            if ((func_800EA05C() == 0xB9 || func_800EA05C() == 0xC4) &&
                func_80800CFC_chquicksandbaddy(arg0, arg0->position, (f32 *)arg0->actorData)) {
                func_800F7D90(func_800F54E4(), 0x52, (f32 *)arg0->actorData, arg0->actorData[5] ? 0 : 1);
                arg0->unk64_19 = 1;
            } else if (func_80801154_chquicksandbaddy(arg0, sp9C) != -1) {
                func_800F7D90(func_800F54E4(), 0x52, sp9C, arg0->actorData[5] ? 0 : 1);
                arg0->unk64_19 = 1;
            } else {
                func_800F7C58(func_800F54E4(), 0x6A, arg0->actorData[5] ? 0 : 1);
                arg0->unk64_19 = 0;
            }
            arg0->unk74_30 = 0;
            arg0->unk79_4 = 0;
            arg0->unk50 = 0.0f;
            arg0->unk58 = 1.0f;
            func_80102424(arg0, 3);
        }
        break;
    case 3:
        if (func_800D90A4(&arg0->unk58)) {
            if (arg0->unk64_19) {
                func_800F5A00(func_800F54E4(), sp90);
            } else {
                func_800E3980(sp90);
            }
            arg0->rotation[1] = func_800F1DF4(arg0->position, sp90);
            func_80102424(arg0, 4);
            if (!arg0->unk74_30 || arg0->unk79_4 < 6) {
                func_800EE7F8(arg0->position, func_800CC63C(baddy->bits.map - 1, baddy->bits.region - 1));
                arg0->position[1] = func_80800CC0_chquicksandbaddy((u8 *)arg0);
            }
        } else if (!arg0->unk74_30 || arg0->unk79_4 < 6) {
            arg0->unk74_30 = 1;
            i = 0; do {
                angle = arg0->unk79_4 * 60.0f;
                func_800EE7F8(sp7C, arg0->position);
                sp7C[1] += 60.0f;
                func_800EEB9C(sp70, angle, func_80103EAC(arg0));
                func_800EF04C(sp70, sp7C);
                func_800EE7F8(sp58, sp70);
                if (func_800C6A7C(sp7C, sp70, sp64, 0)) {
                    func_800EF334(sp64, 300.0f);
                    func_800EF04C(sp64, sp70);
                    func_800EFB24(sp58, sp70, sp58);
                    func_800EF04C(arg0->position, sp58);
                    arg0->position[1] = func_80800CC0_chquicksandbaddy((u8 *)arg0);
                    arg0->unk74_30 = 0;
                    arg0->unk79_4 = 0;
                    break;
                }
                if (func_800CC338(sp70, baddy->bits.map - 1, baddy->bits.region - 1) == -1) {
                    func_800EEB9C(sp64, func_800F1DF4(arg0->position, func_800CC63C(baddy->bits.map - 1, baddy->bits.region - 1)), func_80103EAC(arg0));
                    func_800EF04C(arg0->position, sp64);
                    arg0->position[1] = func_80800CC0_chquicksandbaddy((u8 *)arg0);
                    arg0->unk74_30 = 0;
                    arg0->unk79_4 = 0;
                    break;
                } else {
                    arg0->unk79_4++;
                    arg0->unk74_30 = (u8)(arg0->unk74_30 & 1);
                }
                next = i + 1;
                i = next;
            } while (next != 3);
        }
        func_80103014(arg0);
        break;
    case 4:
        func_800F4F34(func_800F54E4(), arg0->position, arg0->scale * 50.0f, arg0->scale * 150.0f);
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801300_chquicksandbaddy, D_80801310_chquicksandbaddy);
        if (func_80101E14(arg0, 0.6f)) {
            func_800C4140(0x7FFB5DB2, arg0->position, 0x0BB80190);
        } else if (func_80101E14(arg0, 0.69f)) {
            func_800C4140(0x797B5DB2, arg0->position, 0x0BB80190);
        } else if (func_80101E14(arg0, 0.78f)) {
            func_800C4140(0x731B5DB2, arg0->position, 0x0BB80190);
        } else if (func_80101E14(arg0, 0.87f)) {
            func_800C4140(0x6CBB5DB2, arg0->position, 0x0BB80190);
        }
        if (func_80101DDC(arg0)) {
            ((f32 *)arg0->actorData)[4] = func_800DC178(20.0f, 30.0f);
            func_80102424(arg0, 1);
            _subaddieDll_entrypoint_4(arg0, 0);
            arg0->unk58 = 0.2f;
        }
        break;
    case 5:
        ((f32 *)arg0->actorData)[4] = arg0->unk58;
        func_800D91B8(&arg0->unk58);
        p = D_80801320_chquicksandbaddy; do {
            if ((*p)[0] < arg0->unk58 && ((f32 *)arg0->actorData)[4] <= (*p)[0]) {
                if ((*p)[1] == -1.0f) {
                    func_800F7B9C(func_800F54E4(), 0x26);
                } else if ((*p)[1] == -2.0f) {
                    func_800FC660(0xB);
                } else {
                    func_800C4140(((u16)((*p)[1] * 1023.0f) << 21) + 0x1B5DB2, arg0->position, 0x0BB80190);
                }
                break;
            }
        } while (++p != (void *)D_80801370_chquicksandbaddy);
        break;
    case 6:
        if (func_80101E14(arg0, 0.09f)) {
            func_80101EE4(arg0, 0.91f);
            func_80102424(arg0, 7);
        }
        break;
    case 7:
        if (func_80101DDC(arg0)) {
            ((f32 *)arg0->actorData)[4] = func_800DC178(20.0f, 30.0f);
            func_80102424(arg0, 1);
        }
        break;
    }
    if (D_808012A0_chquicksandbaddy[arg0->unk70_10].index == 0x1E4) {
        arg0->unk64_16 = 1;
        if (func_80101E14(arg0, 0.07f) || func_80101E14(arg0, 0.92f)) {
            height = func_800C6920((BtIntPtr)arg0->position, 500.0f, -500.0f, 0) + arg0->unk54;
            func_80800FC8_chquicksandbaddy(arg0->position, height, 5);
            arg0->position[1] = height;
            chquicksandbaddy_entrypoint_0(0, (BtIntPtr)arg0->position);
        } else if (func_80101F24(arg0) > 0.2f && func_80101F24(arg0) < 0.55f && func_800DC0C0() < 0.5f) {
            _subaddieskeleton_entrypoint_0(arg0, 0x4D, sp3C);
            func_80800FC8_chquicksandbaddy(sp3C, func_800C6920((BtIntPtr)sp3C, 500.0f, -500.0f, 0) + arg0->unk54, 1);
        }
    } else {
        arg0->unk64_16 = 0;
    }
}

/* extern */

f32 func_80800CC0_chquicksandbaddy(u8 *arg0) {
    f32 func_800C6920(f32 arg0[3], f32 arg1, f32 arg2, s32 arg3);
    f32 result;

    result = func_800C6920((BtIntPtr) (arg0 + 4), 500.0f, -500.0f, 0);
    result += *(f32 *) (arg0 + 0x54);
    return result;
}

/* extern */

s32 func_80800CFC_chquicksandbaddy(Actor *arg0, f32 arg1[3], f32 arg2[3]) {
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    f32 func_800EEB40(f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 sp1C[3];

    if (!arg0->unk64_20) {
        return 0;
    }
    if (func_800EEB40(arg1, arg2) > 4000000.0f) {
        return 0;
    }
    if (mlAbsF(arg2[1] - arg1[1]) > 500.0f) {
        return 0;
    }
    if (func_800C6A7C(arg1, arg2, sp1C, 0) != 0) {
        return 0;
    }
    return 1;
}

s32 func_80800DBC_chquicksandbaddy(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    u32 func_800F54E4(void);
    Unk80132ED0 *func_800F55D0(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6C5C(BtIntPtr);
    s32 func_800F6E00(BtIntPtr);
    s32 func_8010C500(void *);
    f32 position[3];
    u8 *actors[20];
    f32 distance;
    s32 count;
    s32 i;
    u8 **actor;
    Actor *other;

    if (!func_8010C500(arg0)) {
        return 0;
    }
    if (func_800F55D0(func_800F54E4())) {
        return 0;
    }
    if (!func_800F6E00(func_800F54E4())) {
        return 0;
    }
    if (!func_800F6C5C(func_800F54E4())) {
        return 0;
    }
    count = _subaddiefind_entrypoint_4(0x1EF, actors, 20);
    func_800F5A00(func_800F54E4(), position);
    i = 0;
    if (count > 0) {
        actor = actors;
        do {
            other = (Actor *)*actor;
            if (arg0 != other && other->unk70_25 == arg0->unk70_25) {
                distance = func_800EEB40(position, arg0->position);
                if (func_800EEB40(position, ((Actor *)*actor)->position) < distance) {
                    return 0;
                }
            }
            i++;
            actor++;
        } while (i != count);
    }
    return func_800D90A4(&arg0->unk58) == 0;
}

void chquicksandbaddy_entrypoint_0(s32 arg0, BtIntPtr arg1) {
    s32 func_8001210C(s32);
    BtIntPtr func_800B53A4(s32);
    s32 func_800BA22C(BtIntPtr, s32);

    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);)
    f32 func_800DC0C0();
    s32 func_808010A0_chquicksandbaddy(void *);
    extern s32 D_80801370_chquicksandbaddy[8];
    extern u8 D_80801390_chquicksandbaddy[4];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    if ((func_800DC0C0() < 0.75f) && (func_808010A0_chquicksandbaddy(D_80801390_chquicksandbaddy) != 0) && (func_8001210C(3) != 0)) {
        temp_v0 = func_800B53A4(1);
        sp24 = temp_v0;
        func_800BABB8(temp_v0, BT_NATIVE_ONLY((f32 *))(arg1), 0, BT_DATA_FIELD(2.0f, 0x40000000), BT_NATIVE_ONLY((s16 *))D_80801370_chquicksandbaddy);
        func_800BAB80(sp24, D_80801390_chquicksandbaddy);
        func_800BA22C(sp24, 1);
    }
}

void func_80800FC8_chquicksandbaddy(f32 *arg0, f32 arg1, s32 arg2) {
    BtIntPtr func_800B53A4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    void func_800BA4D0(void *emitter, s16 min_y);
    void func_800BA544(void *emitter, BtIntPtr arg1);
    void func_800BA714(void *emitter, s16 min, s16 max);

    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);)
    s32 func_808010A0_chquicksandbaddy(void *);
    extern s32 D_80801394_chquicksandbaddy[16];
    extern u8 D_808013D4_chquicksandbaddy[4];
#ifndef BT_NATIVE
    extern s32 _chquicksandbaddy_entrypoint_0;
#endif
    BtIntPtr temp_v0;

    if (func_808010A0_chquicksandbaddy(D_808013D4_chquicksandbaddy) != 0) {
        temp_v0 = func_800B53A4(arg2);
        func_800BABB8(temp_v0, BT_NATIVE_ONLY((f32 *))(arg0), BT_NATIVE_ONLY((f32 *))(arg0), BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80801394_chquicksandbaddy);
        if (arg2 >= 2) {
            func_800BA714(temp_v0, 0x32, 0x64);
        }
        func_800BAB80(temp_v0, D_808013D4_chquicksandbaddy);
        func_800BA4D0(temp_v0, (s16) (s32) arg1);
        func_800BA544(temp_v0, &_chquicksandbaddy_entrypoint_0);
        func_800BA22C(temp_v0, arg2);
    }
}

s32 func_808010A0_chquicksandbaddy(void *arg0) {
    s32 func_800EA05C();
    u8 *color = arg0;

    switch (func_800EA05C()) {
        case 0xB9:
        case 0xC4:
            color[0] = 0xC8;
            color[1] = 0xA0;
            color[2] = 0x32;
            return 1;
        case 0x100:
        case 0x10F:
        case 0x15C:
            color[0] = 0xB4;
            color[1] = 0xB4;
            color[2] = 0xB4;
            return 1;
        case 0x106:
            color[0] = 0x32;
            color[1] = 0xA0;
            color[2] = 0x32;
            return 1;
        default:
            return 0;
    }
}

/* extern */

s32 func_80801154_chquicksandbaddy(Actor *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    int func_800EEF24(f32 *);
    void *func_80100094(Actor *, u32);
    f32 (*volatile points)[3];
    f32 (*temp)[3];
    f32 *position;
    f32 (*p)[3];
    s32 i;
    s32 best;
    f32 distance;
    f32 d;

    temp = func_80100094(arg0, 1);
    best = -1;
    if (temp != NULL) {
        distance = 0.0f;
        i = 0;
        p = temp;
        points = temp;
do {
            if (func_800EEF24(*p)) {
            position = arg0->position;
            if (best != -1) {
                d = func_800EEB40(position, *p);
                if (d < distance) {
                    distance = d;
                    best = i;
                }
            } else {
                distance = func_800EEB40(position, *p);
                best = i;
            }
            i++;
            p++;
            } else {
                break;
            }
        } while (i != 3);
        if (best != -1) {
            func_800EE7F8(arg1, points[best]);
        }
        return best;
    }
    return -1;
}

OSThread *chquicksandbaddy_entrypoint_1(void)
{
    extern ActorData D_808013D8_chquicksandbaddy[];
    return (OSThread *) D_808013D8_chquicksandbaddy;
}
#include "quicksandbaddy_data.inc"
