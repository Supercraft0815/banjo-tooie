#include "common.h"

s32 func_80800000_sccustom_big(s32 arg0) {
    s32 _scinfobar_entrypoint_19(s32);
    void func_800E6DB4(char *, s32);
    void func_800E73D4(s8 *);
    extern char B_808003F0_sccustom_big[];
    func_800E73D4(B_808003F0_sccustom_big);
    func_800E6DB4(B_808003F0_sccustom_big, _scinfobar_entrypoint_19(arg0));
    return (s32) &B_808003F0_sccustom_big;
}

s32 func_80800044_sccustom_big(s32 arg0, u8 arg1) {
    s32 _scinfobar_entrypoint_19(s32);
    s32 _scinfobar_entrypoint_20(s32);
    void func_800E6A58(char *, char);
    void func_800E6DB4(char *, s32);
    void func_800E73D4(s8 *);
    extern char B_80800400_sccustom_big[];
    func_800E73D4(B_80800400_sccustom_big);
    func_800E6DB4(B_80800400_sccustom_big, _scinfobar_entrypoint_19(arg0));
    func_800E6A58(B_80800400_sccustom_big, arg1);
    func_800E6DB4(B_80800400_sccustom_big, _scinfobar_entrypoint_20(arg0));
    return (s32) B_80800400_sccustom_big;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_big/func_808000B4_sccustom_big.s")

/* extern */

void sccustom_big_entrypoint_0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800000_sccustom_big(s32);
    s32 func_808000B4_sccustom_big(s32, s32, s32, s32, s32);
    func_808000B4_sccustom_big(arg0, arg1, arg2, arg3, func_80800000_sccustom_big(arg1));
}

/* extern */

void sccustom_big_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800044_sccustom_big(s32, u8);
    s32 func_808000B4_sccustom_big(s32, s32, s32, s32, s32);
    func_808000B4_sccustom_big(arg0, arg1, arg2, arg3, func_80800044_sccustom_big(arg1, 0x2F));
}

/* extern */

s32 func_80800314_sccustom_big(s32 arg0, s32 arg1) {
    f32 _scinfobar_entrypoint_18(s32);
    s32 func_800E7188(u8 *);
    int sp1C;
    f32 temp_f0;
    int var_v1;

    sp1C = func_800E7188(arg1);
    temp_f0 = _scinfobar_entrypoint_18(arg0);
    var_v1 = sp1C;
    if (var_v1 < 2) {
        var_v1 = 2;
    }
    var_v1--;
    return (s32) ((24.0f * temp_f0) + 8.0f + (16.0f * (f32) var_v1));
}

/* extern */

void sccustom_big_entrypoint_2(s32 arg0) {
    s32 func_80800000_sccustom_big();
    s32 func_80800314_sccustom_big(s32, s32);
    func_80800314_sccustom_big(arg0, func_80800000_sccustom_big());
}

void sccustom_big_entrypoint_3(s32 arg0) {
    s32 func_80800044_sccustom_big(s32, u8);
    s32 func_80800314_sccustom_big(s32, s32);
    func_80800314_sccustom_big(arg0, func_80800044_sccustom_big(arg0, 0x2F));
}
