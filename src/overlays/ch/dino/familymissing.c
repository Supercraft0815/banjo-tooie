#include "common.h"
#include "core2/actor_animation_entry.h"
void func_80800000_chdinofamilymissing(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void *func_80105494(Actor *);

    switch (func_800EA05C()) {
        case 0x114:
            if (!_glcutDll_entrypoint_19(0x35)) {
                func_800FFAB0(arg0);
            }
            break;
        case 0x118:
            if (_glcutDll_entrypoint_20()) {
                if (func_80105494(arg0)) {
                    func_800FFAB0(arg0);
                } else {
                    func_80102424(arg0, 7);
                }
            } else if (!_glcutDll_entrypoint_19(0x35) || !func_80105494(arg0)) {
                if (func_800DA298(0x8A) && !func_80105494(arg0)) {
                    func_80102424(arg0, 5);
                } else {
                    func_800FFAB0(arg0);
                }
            }
            break;
        default:
            func_800FFAB0(arg0);
            break;
    }
}

void func_80800104_chdinofamilymissing(Actor *arg0) {
    struct DinoFamilyMissingFlags {
        u8 pad0[0x74];
        u32 pad74_4 : 28;
        u32 unk74_0 : 4;
    };
    void _chdinofamilyfx_entrypoint_0(Actor *arg0);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    void func_80105834(Actor *);
    s32 func_80105998(Actor *, f32);
    s32 func_80105A5C(Actor *);
    void func_80800418_chdinofamilymissing(Actor *);
    extern u32 D_808006A0_chdinofamilymissing[3];
    _sudeflect_entrypoint_1(arg0->position, func_80103EF4(arg0), 0.0f, func_80103EAC(arg0), 10);
    switch (arg0->unk70_10) {
        case 1:
            func_80800418_chdinofamilymissing(arg0);
            func_80105834(arg0);
            if (func_80105998(arg0, 0.15f)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17CD, 0xF, arg0->position, 0x39);
            }
            if (func_80105A5C(arg0)) {
                _glcutDll_entrypoint_24(0x118, -1, 0x35);
                func_800FFAB0(arg0);
            }
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808006A0_chdinofamilymissing, 0.47f);
            break;
        case 2:
            if (func_80105A5C(arg0)) {
                func_800DA524(0x588);
                func_80102424(arg0, 3);
                ((struct DinoFamilyMissingFlags *)arg0)->unk74_0 = 0;
            } else {
                func_80800418_chdinofamilymissing(arg0);
                func_80105834(arg0);
            }
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808006A0_chdinofamilymissing, 0.47f);
            break;
        case 3:
            if (func_80105A5C(arg0)) {
                func_800DA544(0x8A);
                func_80101180(0x290, 0x33, 2);
                func_80102424(arg0, 4);
            }
            break;
        case 4:
            break;
        case 5:
            _sudeflect_entrypoint_1(arg0->position, arg0->scale * 235.0f, 0.0f, arg0->scale * 179.0f, 30);
            if (_subaddiedialog_entrypoint_4(arg0->position, 0x258, 0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17CE, 0xF, arg0->position, 0x39);
            }
            break;
    }
    _chdinofamilyfx_entrypoint_0(arg0);
}

s32 func_80800324_chdinofamilymissing(Actor *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void *func_80105494(Actor *);

    switch (func_800EA05C()) {
        case 0x114:
            if (_glcutDll_entrypoint_19(0x35)) {
                func_80102424(arg0, 1);
                _capod_entrypoint_13(arg0->unk0, NULL, 5, 0x2831);
                return 1;
            }
            break;
        case 0x118:
            if (_glcutDll_entrypoint_19(0x35) && func_80105494(arg0)) {
                func_80102424(arg0, 2);
                _capod_entrypoint_13(arg0->unk0, NULL, 0xC, 0x2831);
                return 1;
            }
            if (_glcutDll_entrypoint_19(0x38) && func_80105494(arg0)) {
                func_800FFAB0(arg0);
                return 1;
            }
            break;
    }
    return 0;
}

void func_80800418_chdinofamilymissing(Actor *arg0) {
    f32 func_800F3780(f32, u8 *, s16);
    f32 func_80101F24(Actor *);
    void func_80105A9C(Actor *, f32);
    extern u8 D_808006AC_chdinofamilymissing[32];
    f32 temp_f2;
    f32 var_f0;
    f32 temp_f6;

    temp_f2 = func_800F3780(func_80101F24(arg0), D_808006AC_chdinofamilymissing, 4);
    if (arg0->unk70_10 == 1) {
        var_f0 = 0.75f;
    } else {
        var_f0 = 1.0f;
    }
    temp_f6 = temp_f2 * 1200.0f;
    func_80105A9C(arg0, var_f0 * temp_f6);
}

s32 func_808004A4_chdinofamilymissing(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _gcdialogcamera_entrypoint_4(BtIntPtr arg0);
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(s32);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    s32 func_800DA298(s32);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    extern ActorAnimationEntry D_80800660_chdinofamilymissing[];
    extern s32 D_808006CC_chdinofamilymissing[];

    switch (arg1) {
        case 0x49:
            return func_80800324_chdinofamilymissing(arg0, arg2);
        case 0x1F:
            func_801015D0(arg0);
            if (D_80800660_chdinofamilymissing[arg0->unk70_10].index == 0x14D) {
                func_800DF744(3, 1);
                return 1;
            }
            func_800DF744(1, 0);
            func_800DF744(2, 1);
            func_800DF744(3, 2);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_3(D_808006CC_chdinofamilymissing, arg0->scale);
            return 3;
        case 0xB:
            if (arg2 == 0xC && _glcutDll_entrypoint_19(0x35)) {
                if (func_800DA298(0x189) && func_800DA298(0x15E)) {
                    _glcutDll_entrypoint_24(0x114, -1, 0x38);
                    return 3;
                }
                if (!func_800DA298(0x15E) || func_800DA298(0x189) || !func_800DA298(0x15F)) {
                    _glcutDll_entrypoint_17();
                }
            }
            return 3;
        default:
            return 0;
    }
}

OSThread *chdinofamilymissing_entrypoint_0(void)
{
    extern ActorData D_808006DC_chdinofamilymissing;
    return (OSThread *) &D_808006DC_chdinofamilymissing;
}
#include "familymissing_data.inc"
