#include "common.h"

OSThread *chamazongoldhordeofficial_entrypoint_0(void)
{
    extern u8 D_80801240_chamazongoldhordeofficial[];

    return (OSThread *) D_80801240_chamazongoldhordeofficial;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_8080000C_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800150_chamazongoldhordeofficial.s")

void *_func_unused(void);
void *func_80100094(Actor *, u32);
void func_80800630_chamazongoldhordeofficial(Actor *arg0) { _suexpression_entrypoint_8(arg0, 1); if (_susubgame_entrypoint_2(arg0, (s32)func_80100094(arg0, 0) + 0x6C) != 0) { _susubgame_entrypoint_4(arg0, (s32)func_80100094(arg0, 0) + 0x6C); } }

/* extern */

void func_80800690_chamazongoldhordeofficial(Actor *arg0) {
    void _gspropctrl_entrypoint_11(Prop*, f32[3]);
    s32 _gspropctrl_entrypoint_12(s32);
    Prop *_gccubesearch_entrypoint_15(u32, u32, f32 *, Actor *);
    Prop *sp1C;
    sp1C = _gccubesearch_entrypoint_15(arg0->unk6C_9, arg0->pad6C_21, arg0->position, arg0);
    _gspropctrl_entrypoint_11(sp1C, arg0->position);
    arg0->rotation[1] = (f32) _gspropctrl_entrypoint_12((s32) sp1C);
}

s32 func_808006F8_chamazongoldhordeofficial(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_14(void);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_5(f32 *);
    s32 _glcutDll_entrypoint_20(void);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, f32, f32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    void func_8008F8B0(void);
    void func_8008F8D8(s32);
    void func_8008F904(s32 *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    s32 func_8008FD48(void);
    void func_800904C8(s32);
    s32 func_800DA298(s32);
    s32 func_800EA090(void);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);
    f32 func_8010CD28(Actor *);
    void func_80800690_chamazongoldhordeofficial(Actor *);
    s32 func_80800C18_chamazongoldhordeofficial(void);
    void func_80800CD8_chamazongoldhordeofficial(Actor *, s32, s32);
    void func_80800E18_chamazongoldhordeofficial(Actor *);
    void func_80801060_chamazongoldhordeofficial(Actor *);
    extern s32 D_808011C0_chamazongoldhordeofficial[];
    extern s32 func_8010D5DC;
    f32 sp3C[3];
    f32 sp30[3];

    switch (arg1) {
        default:
            return 0;
        case 0x3D:
            func_80801060_chamazongoldhordeofficial(arg0);
            return 1;
        case 0x2E:
            func_80800CD8_chamazongoldhordeofficial(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            return 1;
        case 0xB:
            if (arg2 == 4) {
                _capod_entrypoint_14();
                _glcutDll_entrypoint_6(0x119, 0x34);
                return 4;
            }
            return 3;
        case 0x52:
            func_800EFA4C(sp3C, 0.0f, func_8010CD28(arg0), 0.0f);
            _gcdialogcamera_entrypoint_3(D_808011C0_chamazongoldhordeofficial, *(f32 *)((u8 *)arg0 + 0x38));
            _gcdialogcamera_entrypoint_5(sp3C);
            return 1;
        case 0x57:
            return _susubgame_entrypoint_3(arg0, (u8 *)func_80100094(arg0, 0) + 0x6C, arg2 & 0xFFFF, (arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            _suexpression_entrypoint_7(arg0, 1, 0x31);
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 80.0f, 10.0f);
            if (func_800DA298(0x5A) || _glcutDll_entrypoint_20()) {
                func_80102424(arg0, 6);
                if (!_glcutDll_entrypoint_20()) {
                    func_80108B04(arg0, 0);
                }
                if (!func_800DA298(0x59C) && !_glcutDll_entrypoint_20()) {
                    _susubgame_entrypoint_5(arg0, (u8 *)func_80100094(arg0, 0) + 0x6C, 3, 1, 0x2000);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xF59, 0xE, (f32 *)((u8 *)arg0 + 4), 0x31);
                }
            } else if (func_80800C18_chamazongoldhordeofficial() && func_8008FD48() == 1) {
                func_80800690_chamazongoldhordeofficial(arg0);
                func_80102424(arg0, 0xA);
            } else if (func_800EA090() == 1 && !func_800DA298(0x59C) && func_8008FD48() == 1) {
                func_80800690_chamazongoldhordeofficial(arg0);
                func_800EEB9C(sp30, *(f32 *)((u8 *)arg0 + 0x48), 300.0f);
                func_800EF04C(sp30, (f32 *)((u8 *)arg0 + 4));
                func_8008F8B0();
                func_8008F904(&func_8010D5DC, *(Unk80132ED0 **)arg0);
                func_8008F8D8(1);
                func_8008F990(sp30, 300.0f);
                _susubgame_entrypoint_6(arg0, (u8 *)func_80100094(arg0, 0) + 0x6C, 0xF, 0x60, 0);
                func_80102424(arg0, 9);
            } else {
                func_80800E18_chamazongoldhordeofficial(arg0);
            }
            break;
        case 0x32:
            func_800904C8(0x8D);
            if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) == 9) {
                _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xF0D, 0xE, (f32 *)((u8 *)arg0 + 4), 0x31);
            } else {
                func_80102424(arg0, 0xB);
            }
            break;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800A84_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800C18_chamazongoldhordeofficial.s")

s32 func_80800C60_chamazongoldhordeofficial(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_800DA298(s32);
    s32 func_800F54E4();
    s32 func_800F56AC(s32);
    extern s32 D_80801324_chamazongoldhordeofficial;
    extern s32 D_80801340_chamazongoldhordeofficial;
    if (func_800F56AC(func_800F54E4()) == 0x12) {
        return 0;
    }
    if (func_800DA298(0x5A) != 0) {
        return _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80801340_chamazongoldhordeofficial);
    }
    return _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80801324_chamazongoldhordeofficial);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800CD8_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800DB4_chamazongoldhordeofficial.s")

/* extern */

void func_80800E18_chamazongoldhordeofficial(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_80102424(Actor*, s32);
    s32 func_80800DB4_chamazongoldhordeofficial(Actor *, u8);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_80800DB4_chamazongoldhordeofficial(arg0, (*(u8 *)((s8 *)(temp_v0) + (0x67))));
    func_80102424(arg0, 2);
    (*(s16 *)((s8 *)(sp1C) + (8))) = -0x3E7;
}

void func_80800E64_chamazongoldhordeofficial(Actor *arg0) {
    extern u32 D_808011D0_chamazongoldhordeofficial;
    extern u32 D_8080135C_chamazongoldhordeofficial;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808011D0_chamazongoldhordeofficial, &D_8080135C_chamazongoldhordeofficial);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800E94_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800F40_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80801060_chamazongoldhordeofficial.s")
