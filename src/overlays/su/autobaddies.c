#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/suautobaddies_entrypoint_0.s")

/* extern */

void suautobaddies_entrypoint_1(void) {
    s32 _glcutDll_entrypoint_18();
    s32 func_8010108C(s32, s32, s32);
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 sp28;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 var_a0;

    temp_s0 = _glcutDll_entrypoint_18();
    var_a0 = func_801067C4((&sp28) - 1);
    if (var_a0 != 0) {
        do {
            func_8010108C(var_a0, 0x49, temp_s0);
            temp_v0_2 = func_8010682C((&sp28) - 1);
            var_a0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
}

/* extern */

void func_80800104_suautobaddies(void) {
    s32 _chintrotext_entrypoint_2(s32);
    s32 _gcintrotext_entrypoint_1();
    s32 _gclevel_entrypoint_4(s32);
    s32 _glcutDll_entrypoint_1();
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800A9C98();
    s32 func_800DA298(s32);
    if ((_glcutDll_entrypoint_1() == 0) && (func_800DA298(0x647) == 0) && (func_800A9C98() == 0) && (_gcintrotext_entrypoint_1() == 0) && (_glcutDll_entrypoint_19(0x6F) == 0) && (_glcutDll_entrypoint_20() == 0) && (_gclevel_entrypoint_4(0x40) == 0)) {
        _chintrotext_entrypoint_2(0);
    }
}

void func_80800194_suautobaddies(void) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    s32 _gcsectionDll_entrypoint_4(s32);
    s32 _glcutDll_entrypoint_1();
    s32 func_800A9C98();
    s32 func_800D3934();
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    s32 func_800DB9B0();
    s32 func_800EA05C();
    extern s32 _chbaddiesetup_entrypoint_8;
    s32 sp24;

    sp24 = func_800EA05C();
    if ((func_800DB9B0() == 0) && (_glcutDll_entrypoint_1() == 0) && (func_800DA298(0x647) == 0) && (func_800A9C98() == 0) && (_gcsectionDll_entrypoint_4(sp24) != 0xD)) {
        if ((func_800D3934() != 0) || (sp24 == 0xAF)) {
            func_800DA544(0x6A7);
            _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_8, 0x153, 0, 0, 0);
            return;
        }
        func_800DA524(0x6A7);
    }
}

/* extern */

void func_80800258_suautobaddies(void) {
    s32 _suquiz_entrypoint_27();
    s32 func_800DA298(s32);
    s32 func_800DB9B0();
    if ((func_800DA298(0x6B6) != 0) && (func_800DB9B0() != 0)) {
        _suquiz_entrypoint_27();
    }
}

/* extern */

void func_80800298_suautobaddies(void) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_800EFD24(s32 *);
    s32 func_80108474(s32, s32 *, s32);
    s32 sp1C[3];
    s32 temp_v0;

    if (func_800DA298(0x650) != 0) {
        temp_v0 = func_800EA05C();
        if ((temp_v0 != 0x19C) && (temp_v0 != 0x19D)) {
            func_800EFD24(sp1C);
            func_80108474(0x174, sp1C, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/suautobaddies_entrypoint_2.s")

void func_8080036C_suautobaddies(void) {
    s32 func_800C9DAC(f32, s32 *);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DB9B0();
    s32 func_800EA05C();
    extern s32 _suautobaddies_entrypoint_2;
    s32 sp1C;

    sp1C = func_800EA05C();
    if ((func_800DB9B0() == 0) && ((sp1C == 0x154) || (sp1C == 0xCA) || (func_800DA298(0x6E7) != 0))) {
        func_800DA524(0x6E7);
        func_800C9DAC(1.5f, &_suautobaddies_entrypoint_2);
    }
}

void func_808003DC_suautobaddies(void) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    s32 _chlensflare_entrypoint_0();
    extern s32 _chbaddiesetup_entrypoint_8;
    if (_chlensflare_entrypoint_0() != 0) {
        _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_8, 0x3FE, 0, 0, 0);
    }
}

void suautobaddies_entrypoint_3(void) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    s32 _gcfrontend_entrypoint_3(s32);
    s32 func_800D035C(s32);
    s32 func_800D395C();
    s32 func_800DB9B0();
    extern s32 _chbaddiesetup_entrypoint_8;
    if ((func_800D395C() == 0) && (func_800DB9B0() == 0) && (_gcfrontend_entrypoint_3(0x85) == 0) && (func_800D035C(1) == 0x5A)) {
        _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_8, 0x524, 0, 0, 0);
    }
}
