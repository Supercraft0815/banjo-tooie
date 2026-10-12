#include "common.h"

void func_80800000_chfactoryempspell(Actor *arg0) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void _chglowbo_entrypoint_6(void);
    s32 _chmrtannoy_entrypoint_0(void);
    void _subaddieDll_entrypoint_4(Actor *, u32);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_18(void *, f32);
    void _sumumbofx_entrypoint_20(void *, f32);
    f32 _sumumbofx_entrypoint_26(void *);
    s32 _sumumbofx_entrypoint_27(void *);
    void _sumumbofx_entrypoint_5(void *, f32);
    s16 func_800CEA84(s32);
    s32 func_800CEAA8();
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    void func_80800A08_chfactoryempspell(void);
    void func_80801130_chfactoryempspell(Actor *, void *, f32);
    void func_808012C0_chfactoryempspell(f32, f32);
    void func_808016AC_chfactoryempspell(Actor *);
    void func_80801844_chfactoryempspell(Actor *);
    s32 func_80801AB4_chfactoryempspell(void *);
    void func_80801C00_chfactoryempspell(Actor *, f32);
    void func_80801E48_chfactoryempspell(Actor *);
    void func_80801E9C_chfactoryempspell(Actor *, f32);
    void func_80801F30_chfactoryempspell(Actor *);

    func_80800A08_chfactoryempspell();
    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2: {
        void *fx;
        if (func_800DA298(0x9DE)) {
            func_80801F30_chfactoryempspell(arg0);
            fx = func_80100094(arg0, 0);
            _sumumbofx_entrypoint_15(fx, 3.0f);
            _capod_entrypoint_13(*(s32 *)arg0, 0, 10, 0x810);
            arg0->unk64_20 = 0;
            func_800DA544(0xA05);
            func_80101180(0x2B0, 0xBB, 0xB);
            func_80101FDC(arg0, 3);
            func_800DA544(0x57F);
        }
        break;
    }
    case 3: {
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, 1.0f);
        func_80801C00_chfactoryempspell(arg0, 1.0f);
        if (_sumumbofx_entrypoint_27(fx)) {
            _sumumbofx_entrypoint_18(fx, 3.0f);
            func_80101FDC(arg0, 4);
        }
        break;
    }
    case 4: {
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, 0.75f);
        _sumumbofx_entrypoint_5(fx, 1.5f);
        func_80801C00_chfactoryempspell(arg0, _sumumbofx_entrypoint_26(fx));
        if (_sumumbofx_entrypoint_27(fx)) {
            _sumumbofx_entrypoint_17(fx, 5.0f);
            func_80101FDC(arg0, 5);
        }
        break;
    }
    case 5: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        Actor *second = _subaddiefind_entrypoint_3(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_80801C00_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        if (first->unk70_10 == 3) {
            func_80101FDC(first, 5);
            *(f32 *)((u8 *)first + 0x34) = 1.0f;
            func_80101FDC(second, 5);
            *(f32 *)((u8 *)second + 0x34) = 1.0f;
            func_80101FDC(arg0, 6);
            _sumumbofx_entrypoint_20(fx, 5.0f);
        }
        break;
    }
    case 6: {
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, 1.0f);
        func_808012C0_chfactoryempspell(0.1f, 0.1f);
        func_80801E9C_chfactoryempspell(arg0, 1.0f);
        func_80801C00_chfactoryempspell(arg0, 1.0f);
        if (_sumumbofx_entrypoint_27(fx)) {
            arg0->unk64_19 = 1;
            func_80101FDC(arg0, 7);
            _sumumbofx_entrypoint_20(fx, 5.0f);
        }
        break;
    }
    case 7: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        Actor *second = _subaddiefind_entrypoint_3(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        f32 amount = 1.0f - _sumumbofx_entrypoint_26(fx);
        *(f32 *)((u8 *)first + 0x34) = amount;
        *(f32 *)((u8 *)second + 0x34) = amount;
        func_80801130_chfactoryempspell(arg0, fx, amount);
        func_808012C0_chfactoryempspell(0.2f, 0.2f);
        func_80801E9C_chfactoryempspell(arg0, amount);
        func_80801C00_chfactoryempspell(arg0, 1.0f);
        if (_sumumbofx_entrypoint_27(fx)) {
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x1339, 4, (f32 *)((u8 *)arg0 + 4), 0);
            func_800DA544(0x9DF);
            _chglowbo_entrypoint_6();
            func_808016AC_chfactoryempspell(arg0);
            func_80101FDC(arg0, 8);
        }
        break;
    }
    case 8: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_808012C0_chfactoryempspell(0.07f, 0.05f);
        func_80801844_chfactoryempspell(arg0);
        func_80801E9C_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        if (func_800CEAA8(0)) {
            func_80101FDC(arg0, 9);
        }
        break;
    }
    case 9: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_808012C0_chfactoryempspell(0.07f, 0.05f);
        func_80801844_chfactoryempspell(arg0);
        func_80801E9C_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        if (!func_800DA298(0xA05) || func_800CEA84(0) < 2.0f) {
            *((u8 *)arg0 + 0x28) = _subaddieaudioloop_entrypoint_3(*((u8 *)arg0 + 0x28));
            _sumumbofx_entrypoint_16(fx, 2.0f);
            func_80101FDC(arg0, 10);
        }
        break;
    }
    case 10: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_80801C00_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        func_80801844_chfactoryempspell(arg0);
        if (_sumumbofx_entrypoint_27(fx)) {
            if (!func_800DA298(0x329)) {
                func_808012C0_chfactoryempspell(1.0f, 1.0f);
            }
            func_80801AB4_chfactoryempspell(arg0);
            func_80801E48_chfactoryempspell(arg0);
            arg0->unk64_19 = 0;
            func_80101FDC(arg0, 11);
        }
        break;
    }
    case 11: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        Actor *second = _subaddiefind_entrypoint_3(0x3BA, &search);
        _sumumbofx_entrypoint_1(arg0, 0);
        func_80101FDC(first, 1);
        func_80101FDC(second, 1);
        *(f32 *)((u8 *)first + 0x58) = 1.2f;
        *(f32 *)((u8 *)second + 0x58) = 1.2f;
        _subaddieDll_entrypoint_4(arg0, 0);
        func_800DA524(0x9DE);
        func_80101FDC(arg0, 1);
        break;
    }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800630_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800A08_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80800C7C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801038_chfactoryempspell.s")

/* extern */

void chfactoryempspell_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _chmrtannoy_entrypoint_0();
    s32 func_800C0534(s32, s32, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    if (func_800DA298(0x329) == 0) {
        _chmrtannoy_entrypoint_0();
        func_800C0534(0x133A, 4, 0, 0, 0, 0, 0, 0xA3);
    }
    if (func_800EA05C() != 0x10B) {
        func_800DA524(0x9DE);
    }
    func_800DA524(0xA05);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801130_chfactoryempspell.s")

void func_808012C0_chfactoryempspell(f32 arg0, f32 arg1) {
    void func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC0C0(void);
    void func_800E3980(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_80802240_chfactoryempspell;
    extern s32 D_8080227C_chfactoryempspell;
    extern f32 D_808022C8_chfactoryempspell[][3];
    extern f32 D_808022E0_chfactoryempspell[][3];
    extern f32 D_808022F8_chfactoryempspell[][3];
    extern f32 D_80802310_chfactoryempspell[][3];
    f32 position[3];
    f32 random;
    s32 side;

    func_800E3980(position);
    if (position[0] < 0.0f) {
        side = 0;
    } else {
        side = 1;
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_808022C8_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_808022C8_chfactoryempspell[side][0] + 100.0f, D_808022C8_chfactoryempspell[side][1] - 30.0f, D_808022C8_chfactoryempspell[side][2] - 50.0f);
        func_800BBCB8(D_808022C8_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_808022E0_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_808022E0_chfactoryempspell[side][0] + 100.0f, D_808022E0_chfactoryempspell[side][1] - 30.0f, D_808022E0_chfactoryempspell[side][2] - 50.0f);
        func_800BBCB8(D_808022E0_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_808022F8_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_808022F8_chfactoryempspell[side][0] + 100.0f, D_808022F8_chfactoryempspell[side][1] - 30.0f, D_808022F8_chfactoryempspell[side][2] + 50.0f);
        func_800BBCB8(D_808022F8_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(D_80802310_chfactoryempspell[side], NULL, 1.0f, 1, &D_80802240_chfactoryempspell);
    }
    if (random < arg1) {
        func_800EFA4C(position, D_80802310_chfactoryempspell[side][0] + 100.0f, D_80802310_chfactoryempspell[side][1] - 30.0f, D_80802310_chfactoryempspell[side][2] + 50.0f);
        func_800BBCB8(D_80802310_chfactoryempspell[side], position, 1.0f, 2, &D_8080227C_chfactoryempspell);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_808016AC_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801844_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801AB4_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801B2C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801C00_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801E48_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801E9C_chfactoryempspell.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801F30_chfactoryempspell.s")

/* extern */

void func_80801FE0_chfactoryempspell(void *arg0) {
    s32 _subaddieaudioloop_entrypoint_2();
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    s32 func_80801AB4_chfactoryempspell(void *);
    _subaddieaudioloop_entrypoint_2();
    (*(u8 *)((s8 *)(arg0) + (0x28))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x28))));
    func_80801AB4_chfactoryempspell(arg0);
    if ((*(s16 *)((s8 *)(arg0) + (0x82))) != 0) {
        _sumumbofx_entrypoint_1(arg0, 0);
    }
}

OSThread *chfactoryempspell_entrypoint_1(void)
{
    extern u8 D_80802414_chfactoryempspell[];

    return (OSThread *) D_80802414_chfactoryempspell;
}
