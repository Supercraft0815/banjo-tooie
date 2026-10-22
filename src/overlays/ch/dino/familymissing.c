#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymissing/func_80800000_chdinofamilymissing.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymissing/func_80800104_chdinofamilymissing.s")

s32 func_80800324_chdinofamilymissing(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
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
    extern u8 D_808006AC_chdinofamilymissing;
    f32 temp_f2;
    f32 var_f0;
    f32 temp_f6;

    temp_f2 = func_800F3780(func_80101F24(arg0), &D_808006AC_chdinofamilymissing, 4);
    if (arg0->unk70_10 == 1) {
        var_f0 = 0.75f;
    } else {
        var_f0 = 1.0f;
    }
    temp_f6 = temp_f2 * 1200.0f;
    func_80105A9C(arg0, var_f0 * temp_f6);
}

s32 func_808004A4_chdinofamilymissing(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(s32);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    s32 func_800DA298(s32);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    extern u16 D_80800664_chdinofamilymissing[][4];
    extern s32 D_808006CC_chdinofamilymissing[];

    switch (arg1) {
        case 0x49:
            return func_80800324_chdinofamilymissing(arg0, arg2);
        case 0x1F:
            func_801015D0(arg0);
            if (D_80800664_chdinofamilymissing[arg0->unk70_10][0] == 0x14D) {
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
    extern u8 D_808006DC_chdinofamilymissing[];

    return (OSThread *) D_808006DC_chdinofamilymissing;
}
