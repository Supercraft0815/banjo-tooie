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

s32 func_808000B4_sccustom_big(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _scinfobar_entrypoint_11(s32);
    s32 _scinfobar_entrypoint_15(s32);
    f32 _scinfobar_entrypoint_18(s32);
    void func_800B7F14(Gfx **);
    void func_800B811C(Gfx **);
    void func_800B8C50(void);
    void func_800B8C8C(s32);
    void func_800B8C98(s32);
    void func_800B8CE0(s32);
    void func_800B8DEC(Gfx **, s32, s32, u8);
    s32 func_800E7188(u8 *);
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f26;
    f32 var_f2;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s4;
    s32 var_s0;
    s32 var_s0_2;
    u8 var_a3;

    temp_s1 = _scinfobar_entrypoint_11(arg1);
    temp_f22 = _scinfobar_entrypoint_18(arg1);
    temp_s4 = _scinfobar_entrypoint_15(arg1);
    func_800B8C50();
    func_800B8C98(1);
    func_800B8CE0(0xC26);
    temp_f20 = (f32) temp_s1;
    temp_f26 = (24.0f * temp_f22) + 8.0f;
    if (temp_f20 < temp_f26) {
        var_s0 = (s32) ((1.0f - ((temp_f26 - temp_f20) / temp_f26)) * 255.0f);
    } else {
        var_s0 = 0xFF;
    }
    temp_s3 = func_800E7188((u8 *) arg4) - 1;
    func_800B8C8C(var_s0);
    func_800B7F14((Gfx **) arg0);
    var_s0_2 = temp_s3;
    if (temp_s3 >= 0) {
        do {
            var_f2 = (f32) var_s0_2;
            var_f2 = 16.0f * var_f2;
            var_f2 = temp_f26 + var_f2;
            if (temp_f20 < var_f2) {
                var_f2 = temp_f20;
            }
            if (temp_s4 == 2) {
                var_f2 = -var_f2;
                var_a3 = *((temp_s3 - var_s0_2) + (u8 *) arg4);
            } else {
                var_a3 = *((u8 *) arg4 + var_s0_2);
            }
            func_800B8DEC((Gfx **) arg0, (s32) ((f32) arg2 + var_f2), arg3, var_a3);
            var_s0_2 -= 1;
        } while (var_s0_2 >= 0);
    }
    func_800B811C((Gfx **) arg0);
}

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
#ifdef BT_NATIVE
    func_80800314_sccustom_big(arg0, ((s32 (*)())func_80800000_sccustom_big)());
#else
    func_80800314_sccustom_big(arg0, func_80800000_sccustom_big());
#endif
}

void sccustom_big_entrypoint_3(s32 arg0) {
    s32 func_80800044_sccustom_big(s32, u8);
    s32 func_80800314_sccustom_big(s32, s32);
    func_80800314_sccustom_big(arg0, func_80800044_sccustom_big(arg0, 0x2F));
}
