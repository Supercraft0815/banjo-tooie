#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_banjo/sccustom_banjo_entrypoint_0.s")

/* extern */

void sccustom_banjo_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _scinfobar_entrypoint_11(s32);
    f32 _scinfobar_entrypoint_18(s32);
    s32 func_800CF6B0();
    s32 func_800CF6D0();
    s32 func_800D674C(s32);
    void func_800E24F8(s32, s32, s32);
    void func_800E253C(f32);
    void func_800E257C(s32);
    s32 func_800E30E0(s32, s32, s32, s32 *);
    s32 sp84;
    f32 temp_f20;
    s32 temp_f10;
    s32 temp_s3;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_fp;
    s32 var_s0;
    s32 sp5C[2];
    s32 var_s1;
    s32 var_s2;

    var_s1 = 0x28;
    sp84 = func_800D674C(0x9DA);
    temp_s3 = _scinfobar_entrypoint_11(arg1);
    temp_f20 = _scinfobar_entrypoint_18(arg1);
    temp_s7 = func_800CF6B0();
    temp_v0 = func_800CF6D0();
    temp_f10 = (s32) ((f32) var_s1 * temp_f20);
    if (temp_s3 < temp_f10) {
        var_fp = (s32) ((1.0f - ((f32) (temp_f10 - temp_s3) / (f32) temp_f10)) * 256.0f);
    } else {
        var_fp = 0x100;
    }
    for (temp_v1 = temp_v0 - 1; temp_v1 >= 0; temp_v1--) {
            var_s1 = (temp_v1 * 0x14) + 0x28;
            var_s2 = (s32) ((f32) var_s1 * temp_f20);
            if (temp_s3 < var_s2) {
                var_s2 = temp_s3;
            }
            if (temp_v1 < temp_s7) {
                var_s0 = 0xFF;
                func_800E24F8(0x80, 0x80, 0xFF);
            } else {
                var_s0 = 0x78;
            }
            func_800E257C((s32) (var_s0 * var_fp) >> 8);
            func_800E253C(temp_f20);
            sp5C[0] = arg2 * 4;
            sp5C[1] = (arg3 + var_s2) * 4;
            func_800E30E0(arg0, sp84, 0, sp5C);
    }
}

s32 sccustom_banjo_entrypoint_2(s32 arg0)
{
  f32 _scinfobar_entrypoint_18(s32);
  s32 _scinfobar_entrypoint_20();
  s32 sp1C;
  f32 new_var;
  sp1C = _scinfobar_entrypoint_20() - 1;
  new_var = _scinfobar_entrypoint_18(arg0);
  return (s32) (((f32) ((sp1C * 0x14) + 0x28)) * new_var);
  if (sp1C)
  {
  }
}

s32 sccustom_banjo_entrypoint_3(s32 arg0)
{
  f32 _scinfobar_entrypoint_18(s32);
  s32 func_800CF6D0();
  s32 sp1C;
  f32 new_var;
  sp1C = func_800CF6D0() - 1;
  new_var = _scinfobar_entrypoint_18(arg0);
  return (s32) (((f32) ((sp1C * 0x14) + 0x28)) * new_var);
  if (sp1C)
  {
  }
}
