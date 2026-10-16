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
    void func_80801AB4_chfactoryempspell(Actor *);
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

void func_80801038_chfactoryempspell(Actor *arg0) {
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, s32, s32);
    extern s32 _chfactoryempspell_entrypoint_0;
    if (arg0->unk64_20) {
        func_800CE8D8(0, 45.0f, 0x2D);
        func_800CE928(0, (s32)&_chfactoryempspell_entrypoint_0, (s32)arg0->unk0);
        func_800CE88C(0, 1);
        return;
    }
    arg0->unk64_20 = 1;
}

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

void func_80801130_chfactoryempspell(Actor *arg0, void *arg1, f32 arg2) {
    s32 _sumumbofx_entrypoint_14(void *);
    s32 _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, u8 *, f32 *, f32 *);
    void func_800E3980(f32 *);
    extern f32 D_808021BC_chfactoryempspell[][3];
    extern f32 D_808021D4_chfactoryempspell[][3];
    extern f32 D_808021EC_chfactoryempspell[][3];
    extern f32 D_80802204_chfactoryempspell[][3];
    extern u8 D_8080221C_chfactoryempspell[];
    extern f32 D_80802228_chfactoryempspell[];
    extern f32 D_80802234_chfactoryempspell[];
    f32 position[3];
    s32 side;

    func_800E3980(position);
    if (position[0] < 0.0f) {
        side = 0;
    } else {
        side = 1;
    }
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0, 0xA, D_8080221C_chfactoryempspell, D_808021BC_chfactoryempspell[side], D_80802228_chfactoryempspell);
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0xA, 0x14, D_8080221C_chfactoryempspell, D_808021D4_chfactoryempspell[side], D_80802228_chfactoryempspell);
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0x14, 0x1E, D_8080221C_chfactoryempspell, D_808021EC_chfactoryempspell[side], D_80802234_chfactoryempspell);
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0x1E, 0x28, D_8080221C_chfactoryempspell, D_80802204_chfactoryempspell[side], D_80802234_chfactoryempspell);
    _sumumbofx_entrypoint_14(arg1);
}

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

void func_80801AB4_chfactoryempspell(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800C8B84(volatile s32);
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad0[8];
        u8 audio;
        u8 pad9[3];
        s32 handle;
        u8 active : 7;
        u8 flag : 1;
        u8 pad11[3];
    } *entry;
    s32 i;
    u8 audio;
    void *data;

    data = func_80100094(arg0, 1);
    i = 0;
    entry = data;
    do {
        if (entry->handle != 0) {
            func_800C8B84(entry->handle);
        }
        audio = _subaddieaudioloop_entrypoint_3(entry->audio);
        i++;
        entry++;
        entry[-1].audio = audio;
        entry[-1].active = 0;
    } while (i != 3);
}

/* extern */

void func_80801B2C_chfactoryempspell(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 var_s1;
    struct {
        u8 pad[0x3C];
        s32 handles[4];
    } *var_s0;
    f32 sp44[3];

    var_s0 = func_80100094(arg0, 1);
    var_s1 = 0;
    do {
        func_800F5A00(func_800F54E4(), sp44);
        var_s0->handles[var_s1] = func_800C8A98();
        func_800C8E54(var_s0->handles[var_s1], 300.0f, 400.0f);
        func_800C8FB0(var_s0->handles[var_s1], 0x50, 0xFF, 0xFF);
        func_800C8F64(var_s0->handles[var_s1], 1);
        func_800C8CB8(var_s0->handles[var_s1], sp44);
        var_s1++;
    } while (var_s1 != 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801C00_chfactoryempspell.s")

void func_80801E48_chfactoryempspell(Actor *arg0) {
    void func_800C8B84(volatile s32);
    void* func_80100094(Actor*, u32);
    s32 var_s0;
    u8 *var_s1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    var_s0 = 0;
    var_s1 = temp_v0;
    do {
        func_800C8B84((*(s32 *)((s8 *)(var_s1) + (0x3C))));
        var_s0 += 4;
        var_s1 += 4;
    } while (var_s0 != 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/empspell/func_80801E9C_chfactoryempspell.s")

/* extern */

void func_80801F30_chfactoryempspell(Actor *arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(s32, s32, s32, s16);
    s32 _sumumbofx_entrypoint_2(s32);
    s32 _sumumbofx_entrypoint_24(s32, s32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 _sumumbofx_entrypoint_28(void *, f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_808016AC_chfactoryempspell(Actor *);
    void func_80801B2C_chfactoryempspell(Actor *);
    s32 sp2C[3];
    s32 pad;
    void *sp24;

    sp2C[0] = 0;
    sp2C[1] = 0;
    sp2C[2] = 0;
    _sumumbofx_entrypoint_0(arg0, 0, 0x28, _chmumbopad_entrypoint_0(0xB));
    sp24 = func_80100094(arg0, 0);
    _sumumbofx_entrypoint_2(sp24);
    _sumumbofx_entrypoint_24(sp24, 0x3F000000);
    _sumumbofx_entrypoint_25(sp24, 0x8C, sp2C);
    func_80801B2C_chfactoryempspell(arg0);
    func_808016AC_chfactoryempspell(arg0);
    _sumumbofx_entrypoint_28(sp24, arg0->position, 4000.0f, 5000.0f);
}

/* extern */

void func_80801FE0_chfactoryempspell(void *arg0) {
    s32 _subaddieaudioloop_entrypoint_2();
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void func_80801AB4_chfactoryempspell(Actor *);
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
