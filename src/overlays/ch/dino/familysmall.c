#include "common.h"
#include "core2/actor_animation_entry.h"
/* extern */

typedef struct { s32 unk0; u8 pad4[0x4]; f32 unk8; u8 padC[0x1C]; f32 unk28; f32 unk2C; f32 unk30; f32 unk34; f32 unk38; } Objfamilysmall_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chdinofamilysmall(u8 *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800EFA4C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    s32 func_808008B4_chdinofamilysmall(u8 *, s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_808008B4_chdinofamilysmall(arg0, 0xA);
    } else if (func_800DA298(0x15F) == 0) {
        func_808008B4_chdinofamilysmall(arg0, 1);
    } else {
        func_808008B4_chdinofamilysmall(arg0, 9);
    }
    (((Objfamilysmall_arg0 *)arg0)->unk34) = (f32) (((Objfamilysmall_arg0 *)arg0)->unk8);
    func_800EFA4C(arg0 + 0x28, 1.0f, 1.0f, 1.0f);
}

void func_80800090_chdinofamilysmall(u8 *arg0) {
    s32 _chdinofamilyfx_entrypoint_0(u8 *);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, u8 *, s32);
    s32 _subaddiedialog_entrypoint_4(u8 *, s32, s32);
    s32 _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
    s32 _sumumbofx_entrypoint_14(BtIntPtr);
    f32 _sumumbofx_entrypoint_21(BtIntPtr);
    f32 _sumumbofx_entrypoint_26(BtIntPtr);
    s32 _sumumbofx_entrypoint_27(BtIntPtr);
    s32 _sumumbofx_entrypoint_5(BtIntPtr, s32);
    s32 _sumumbofx_entrypoint_7(BtIntPtr, f32, s32, s32, f32 *, s32, s32);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    s32 func_800C4244(s32, s32, s32, u8 *, f32, f32);
    s32 func_800DA298(s32);
    s32 func_800E1610(s32, s32, s32, u8 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    BtIntPtr func_80100094(u8 *, s32);
    s32 func_80103DFC(u8 *, f32 *);
    f32 func_80103EAC(u8 *);
    s32 func_808008B4_chdinofamilysmall(u8 *, s32);
    extern s32 D_80800EE8_chdinofamilysmall[5];
    extern s32 D_80800EFC_chdinofamilysmall[5];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp5C;
    f32 sp50[3];
    f32 sp4C;
    struct StateBits { u32 unused:16; u32 state:6; u32 rest:10; };
    struct SoundBits { u32 unused:11; u32 first:1; u32 second:1; u32 rest:19; };
    struct LandingBits { u32 unused:1; u32 landed:1; u32 rest:30; };

    switch (((struct StateBits *)(arg0 + 0x70))->state) {
    case 1:
        if (_subaddiedialog_entrypoint_4(arg0 + 4, 0x258, 0) != 0) {
            _subaddiedialog_entrypoint_11((((Objfamilysmall_arg0 *)arg0)->unk0), 0x17CB, 0xF, arg0 + 4, 0x39);
        }
        _sudeflect_entrypoint_1(arg0 + 4, (*(f32 *)(arg0 + 0x38)) * 235.0f, 0, (*(f32 *)(arg0 + 0x38)) * 179.0f, 0x1E);
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 2:
        if (func_800DA298(0x9DE) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 3);
        }
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 3:
        func_80103DFC(arg0, sp84);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp84, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 4);
        }
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 4:
        func_80103DFC(arg0, sp78);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp78, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_5(func_80100094(arg0, 1), 0x40000000);
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 5);
            return;
        }
    default:
        return;
    case 5:
        func_80103DFC(arg0, sp6C);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp6C, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        (((Objfamilysmall_arg0 *)arg0)->unk8) = (f32) ((((Objfamilysmall_arg0 *)arg0)->unk34) + func_800F12D4(_sumumbofx_entrypoint_26(func_80100094(arg0, 1)), 0.0f, 1.0f, 0.0f, 800.0f));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 6);
            return;
        }
        break;
    case 6:
        func_80103DFC(arg0, sp60);
        if (_sumumbofx_entrypoint_21(func_80100094(arg0, 1)) > 2.0f) {
            if (!((struct SoundBits *)(arg0 + 0x64))->first) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800EE8_chdinofamilysmall);
                ((struct SoundBits *)(arg0 + 0x64))->first = 1;
            }
            (((Objfamilysmall_arg0 *)arg0)->unk38) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.0f, 0.5f, 0.5);
            (*(f32 *)(arg0 + 0x30)) = (*(f32 *)(arg0 + 0x2C)) = (*(f32 *)(arg0 + 0x28)) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 4.0f, 2.0f, 1.0f, 2.0);
        } else {
            sp5C = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.0f, 0.0f, 1.0f, 0.0f);
            if (!((struct SoundBits *)(arg0 + 0x64))->second) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800EFC_chdinofamilysmall);
                ((struct SoundBits *)(arg0 + 0x64))->second = 1;
            }
            (((Objfamilysmall_arg0 *)arg0)->unk38) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(arg0, 1)), 2.0f, 0.0f, 0.5f, 1.0f);
            (((Objfamilysmall_arg0 *)arg0)->unk28) = (f32) ((func_800138D0(sp5C * 3.0f * 360.0f) * sp5C) + 1.0f);
            (((Objfamilysmall_arg0 *)arg0)->unk2C) = (f32) ((func_800138D0(sp5C * 5.0f * 360.0f) * sp5C) + 1.0f);
            (((Objfamilysmall_arg0 *)arg0)->unk30) = (f32) ((func_800138D0(sp5C * 4.0f * 360.0f) * sp5C) + 1.0f);
        }
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0) * ((2.0f * func_80013970(_sumumbofx_entrypoint_26(func_80100094(arg0, 1)) * 180.0f)) + 1.0f), 0, 0x28, sp60, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(arg0, 1)) != 0) {
            func_808008B4_chdinofamilysmall(arg0, 7);
            return;
        }
        break;
    case 7:
        func_80103DFC(arg0, sp50);
        _sumumbofx_entrypoint_7(func_80100094(arg0, 1), func_80103EAC(arg0), 0, 0x28, sp50, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(arg0, 1));
        sp4C = _sumumbofx_entrypoint_21(func_80100094(arg0, 1));
        if ((sp4C <= 1.6500001f) && (sp4C >= 1.05f)) {
            (((Objfamilysmall_arg0 *)arg0)->unk8) = (f32) ((((Objfamilysmall_arg0 *)arg0)->unk34) + (func_800138D0(func_800F10B4(sp4C, 1.6500001f, 1.05f, 0, 90.0f)) * 800.0f));
        } else if ((sp4C < 1.05f) && !((struct LandingBits *)(arg0 + 0x74))->landed) {
                    func_800C4244(0x416, 0x3F666666, 0x55F0, arg0 + 4, 100.0f, 2500.0f);
            ((struct LandingBits *)(arg0 + 0x74))->landed = 1;
            func_800E1610(3, 0x42C80000, 0x3F19999A, arg0 + 4);
            (((Objfamilysmall_arg0 *)arg0)->unk8) = (f32) (((Objfamilysmall_arg0 *)arg0)->unk34);
        }
        if (sp4C <= 0.0f) {
            func_808008B4_chdinofamilysmall(arg0, 8);
            return;
        }
        break;
    case 8:
        func_808008B4_chdinofamilysmall(arg0, 9);
        return;
    case 9:
        if (_subaddiedialog_entrypoint_4(arg0 + 4, 0x258, 0) != 0) {
            _subaddiedialog_entrypoint_11((((Objfamilysmall_arg0 *)arg0)->unk0), 0x17CC, 0xF, arg0 + 4, 0x39);
        }
        _sudeflect_entrypoint_1(arg0 + 4, (*(f32 *)(arg0 + 0x38)) * 235.0f, 0, (*(f32 *)(arg0 + 0x38)) * 179.0f, 0x1E);
        _chdinofamilyfx_entrypoint_0(arg0);
        return;
    case 10:
        _chdinofamilyfx_entrypoint_0(arg0);
        break;
    }
}

s32 func_808008B4_chdinofamilysmall(u8 *arg0, s32 arg1) {
    struct FamilySmallFlags {
        u8 actorFields[0x74];
        u32 otherFlags : 28;
        u32 state : 4;
    };
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _chglowbo_entrypoint_6(void);
    s32 _chmumbopad_entrypoint_0(s32 arg0);
    void _sumumbofx_entrypoint_0(Actor *arg0, u32 arg1, s32 arg2, s16 arg3);
    void _sumumbofx_entrypoint_1(Actor *arg0, u32 arg1);
    void _sumumbofx_entrypoint_2(BtIntPtr);
    void _sumumbofx_entrypoint_15(BtIntPtr, f32);
    void _sumumbofx_entrypoint_16(BtIntPtr, f32);
    void _sumumbofx_entrypoint_17(BtIntPtr, f32);
    void _sumumbofx_entrypoint_18(BtIntPtr, f32);
    void _sumumbofx_entrypoint_20(BtIntPtr, f32);
    void _sumumbofx_entrypoint_24(BtIntPtr, f32);
    void _sumumbofx_entrypoint_25(u8 *arg0, s32 arg1, BtIntPtr arg2);
    void func_800DA524(s32);
    void func_800DA544(s32);
    BtIntPtr func_80100094(u8 *, s32);
    void func_80102424(Actor *, s32);
    void func_8010A800(Actor *, s32);
    s32 color[3];
    Actor *actor = (Actor *)arg0;

    switch (arg1) {
    case 1:
        actor->scale = 0.5f;
        break;
    case 3:
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        _sumumbofx_entrypoint_0(actor, 1, 0x28, _chmumbopad_entrypoint_0(7));
        _sumumbofx_entrypoint_2(func_80100094(arg0, 1));
        _sumumbofx_entrypoint_25(func_80100094(arg0, 1), 0x7D, color);
        _sumumbofx_entrypoint_24(func_80100094(arg0, 1), 0.2f);
        _sumumbofx_entrypoint_15(func_80100094(arg0, 1), 3.0f);
        _capod_entrypoint_13(actor->unk0, NULL, 0x15, 0x210);
        func_8010A800(actor, 2);
        break;
    case 4:
        _sumumbofx_entrypoint_18(func_80100094(arg0, 1), 2.0f);
        _chglowbo_entrypoint_6();
        break;
    case 5:
        _sumumbofx_entrypoint_17(func_80100094(arg0, 1), 3.0f);
        break;
    case 6:
        actor->unk64_19 = 0;
        actor->unk64_20 = 0;
        _sumumbofx_entrypoint_20(func_80100094(arg0, 1), 4.0f);
        actor->position[1] = ((f32 *)actor->actorData)[7] + 800.0f;
        break;
    case 7:
        actor->unk74_30 = 0;
        _sumumbofx_entrypoint_16(func_80100094(arg0, 1), 3.0f);
        ((struct FamilySmallFlags *)arg0)->state = 0;
        actor->scale = 1.0f;
        break;
    case 8:
        _sumumbofx_entrypoint_1(actor, 1);
        func_8010A800(actor, 0);
        actor->position[1] = ((f32 *)actor->actorData)[7];
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0x15F);
        break;
    case 9:
    case 10:
        actor->scale = 1.0f;
        break;
    }
    func_80102424(actor, arg1); BT_NATIVE_ONLY(return 0;)
}

s32 func_80800AF4_chdinofamilysmall(Actor *arg0, s32 arg1, s32 arg2) {
    extern ActorAnimationEntry D_80800E90_chdinofamilysmall[];
    extern s32 D_80800F10_chdinofamilysmall[];
    s32 _capod_entrypoint_14(void);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _gcdialogcamera_entrypoint_4(BtIntPtr arg0);
    void func_800DF744(s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_801015D0(Actor *);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
    case 0xB:
        _capod_entrypoint_14();
        func_80101180(0x290, 0x33, 1);
        return 4;
    case 0x4B:
        func_80101FDC(arg0, 2);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(arg0->position);
        _gcdialogcamera_entrypoint_3(D_80800F10_chdinofamilysmall, arg0->scale);
        return 3;
    case 0x1F:
        func_801015D0(arg0);
        if (D_80800E90_chdinofamilysmall[arg0->unk70_10].index == 0x14D) {
            func_800DF744(3, 1);
            return 1;
        }
        func_800DF744(1, 0);
        func_800DF744(2, 1);
        func_800DF744(3, 2);
        return 1;
    default:
        return 0;
    }
}

void func_80800C10_chdinofamilysmall(Actor *arg0, BtIntPtr arg1) {
    typedef struct {
        f32 pad[4];
        f32 scale[3];
        f32 height;
    } DinoData;
    BtIntPtr func_80100094();
    void _sumumbofx_entrypoint_8(u8 *arg0, BtIntPtr arg1);
    void _sumumbofx_entrypoint_9(u8 *arg0, Gfx **arg1);
    struct ImageStruct *func_800D674C(s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF410(s32);
    void func_800DF500(f32, f32, f32);
    void func_800DF744(s32, s32);
    void func_800DF830(s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_801015D0(Actor *);
    void func_801018A4(Actor *, BtIntPtr);
    extern f32 B_80800F70_chdinofamilysmall[3];
    extern f32 B_80800F94_chdinofamilysmall[3];
    extern f32 B_80800FA0_chdinofamilysmall[3];
    f32 *dst;
    f32 *src;
    s32 i;

    if (func_80100094(arg0, 1)) {
        _sumumbofx_entrypoint_9(func_80100094(arg0, 1), arg1);
    }
    if (arg0->unk70_10 == 6) {
        func_801015D0(arg0);
        dst = B_80800FA0_chdinofamilysmall; src = B_80800F94_chdinofamilysmall;
        for (i = 4; i != 0; i--, dst -= 3, src -= 3) {
            func_800EE7F8(dst, src);
            if (dst[0] != 0.0f && dst[1] != 0.0f && dst[2] != 0.0f) {
                func_800DF744(3, 1);
                func_800DF500(dst[0], dst[1], dst[2]);
                func_800DF410(160 - i * 30);
                func_800DF830(2);
                func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL,
                    func_800D674C(arg0->unk0->unk14));
            }
        }
        func_800EE7F8(B_80800F70_chdinofamilysmall, ((DinoData *)arg0->actorData)->scale);
        if (((DinoData *)arg0->actorData)->scale[0] != 0.0f &&
            ((DinoData *)arg0->actorData)->scale[1] != 0.0f &&
            ((DinoData *)arg0->actorData)->scale[2] != 0.0f) {
            func_800DF500(((DinoData *)arg0->actorData)->scale[0],
                ((DinoData *)arg0->actorData)->scale[1],
                ((DinoData *)arg0->actorData)->scale[2]);
        }
    }
    func_801018A4(arg0, arg1);
    if (func_80100094(arg0, 1)) {
        _sumumbofx_entrypoint_8(func_80100094(arg0, 1), arg1);
    }
}

OSThread *chdinofamilysmall_entrypoint_0(void)
{
    extern ActorData D_80800F20_chdinofamilysmall[];
    return (OSThread *) D_80800F20_chdinofamilysmall;
}
#include "familysmall_data.inc"
