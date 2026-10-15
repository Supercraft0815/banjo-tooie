#include "common.h"

s32 func_80800000_gcskyDll(s32 arg0) {
    extern s16 D_80800510_gcskyDll[];
    s16 *p = D_80800510_gcskyDll;
    while (*p != 0) {
        if (arg0 == *p) return (s32) p;
        p += 18;
    }
    return (s32) p;
}

void gcskyDll_entrypoint_0(u8 *arg0)
{
  s32 _dbtex_entrypoint_1(s32);
  s32 _glidmake_entrypoint_4(s32);
  s32 func_800B23E0(s32);
  s32 func_800D6CEC(s16);
  s32 func_800D70F8(s16, s32);
  s32 func_800D721C(s16, s32);
  s8 *new_var;
  s32 func_800DBFD8(s32);
  s32 func_800EA05C();
  s32 func_80800000_gcskyDll(s32);
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a0_3;
  s32 temp_a0_4;
  int temp_s4;
  s32 var_s3;
  u8 *temp_s0;
  u8 *var_s1;
  u8 *var_s2;
  temp_s4 = func_80800000_gcskyDll(func_800EA05C());
  var_s3 = 0;
  var_s1 = arg0;
  var_s2 = arg0;
  do
  {
    temp_a0 = *((s32 *) (((s8 *) var_s1) + 0));
    if (temp_a0 != 0)
    {
      func_800DBFD8(temp_a0);
      *((s32 *) (((s8 *) var_s1) + 0)) = 0;
    }
    temp_a0_2 = *((s32 *) (((s8 *) var_s1) + 8));
    if (temp_a0_2 != 0)
    {
      _glidmake_entrypoint_4(temp_a0_2);
      *((s32 *) (((s8 *) var_s1) + 8)) = 0;
    }
    temp_a0_3 = *((s32 *) (((s8 *) var_s1) + 0x18));
    if (temp_a0_3 != 0)
    {
      _dbtex_entrypoint_1(temp_a0_3);
      *((s32 *) (((s8 *) var_s1) + 0x18)) = 0;
    }
    temp_a0_4 = *((s32 *) (((s8 *) var_s2) + 0x24));
    if (temp_a0_4 != 0)
    {
      func_800B23E0(temp_a0_4);
      *((s32 *) (((s8 *) var_s2) + 0x24)) = 0;
    }
    *((s32 *) (((s8 *) var_s2) + 0x20)) = 0;
    temp_s0 = temp_s4 + (var_s3 * 0x10);
    if ((*((s32 *) (((s8 *) var_s1) + 0x10))) != 0)
    {
      func_800D70F8(*((s16 *) (((s8 *) temp_s0) + 4)), 0);
      func_800D721C(*((s16 *) (((s8 *) temp_s0) + 4)), 0);
      func_800D6CEC(*((s16 *) (((s8 *) temp_s0) + 4)));
      new_var = (s8 *) var_s1;
      *((s32 *) (new_var + 0x10)) = 0;
    }
    var_s3 += 1;
    var_s1 += 4;
    var_s2 += 8;
  }
  while (var_s3 != 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/skyDll/gcskyDll_entrypoint_2.s")

/* extern */

s32 gcskyDll_entrypoint_3(void) {
    s32 func_800EA05C();
    s32 func_80800000_gcskyDll(s32);
    return func_80800000_gcskyDll(func_800EA05C()) != 0;
}
