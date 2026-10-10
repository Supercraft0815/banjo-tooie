#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/suautobaddies_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/suautobaddies_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/func_80800104_suautobaddies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/func_80800194_suautobaddies.s")

/* extern */

void func_80800258_suautobaddies(void) {
    s32 _suquiz_entrypoint_27();
    s32 func_800DA298(s32);
    s32 func_800DB9B0();
    if ((func_800DA298(0x6B6) != 0) && (func_800DB9B0() != 0)) {
        _suquiz_entrypoint_27();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/func_80800298_suautobaddies.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/suautobaddies_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/autobaddies/func_8080036C_suautobaddies.s")

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
