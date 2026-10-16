#include "common.h"

extern s32 D_80128770;

void func_800BFCD0(s32 arg0, s32 arg1) {
    (*(s32 *)((s8 *)(&(&D_80128770)[arg0]) + (0x30))) = arg1;
    if ((*(s32 *)((s8 *)(&D_80128770) + (0x30))) < arg0) {
        (*(s32 *)((s8 *)(&D_80128770) + (0x30))) = arg0;
    }
}

void func_800BFD00(void)
{
  s32 func_800DF744(s32, s32);
  extern s32 D_80128774;
  s8 *new_var;
  s32 var_s0;
  var_s0 = 1;
  if ((*((s32 *) (((s8 *) (&D_80128770)) + 0x30))) > 0)
  {
    new_var = &D_80128774;
    do
    {
      new_var = (s8 *) new_var;
      func_800DF744(var_s0, *((s32 *) (new_var + 0x30)));
      var_s0 += 1;
      new_var += 4;
    }
    while ((*((s32 *) (((s8 *) (&D_80128770)) + 0x30))) >= var_s0);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E995C0/func_800BFD6C.s")

void func_800BFF28()
{
    _gcskyDll_entrypoint_0(&D_80128770);
}

void func_800BFF4C()
{
    _gcskyDll_entrypoint_1(&D_80128770);
}

/* extern */

void func_800BFF70(void) {
    f32 func_800D8FF8();
    (*(f32 *)((s8 *)(&D_80128770) + 0x134)) += func_800D8FF8();
}

s32 func_800BFFA0(s32 arg0) {
    extern s32 D_80128778[];
    return ((s32 *)&D_80128778)[arg0];
}

/* extern */

s32 func_800BFFB4(s32 arg0, s32 arg1, f32 *arg2) {
    void func_800DBEFC(s32 *, s32, f32 *);
    s32 temp_a3;
    s32 var_v0;

    temp_a3 = (&D_80128770)[arg0];
    var_v0 = 0;
    if (temp_a3 != 0) {
        func_800DBEFC((s32 *)temp_a3, arg1, arg2);
        return 1;
    }
    return var_v0;
}

void func_800BFFF4(void) {
    s32 func_800DC060(s32);
    s32 func_800EE5D8(s32);
    extern s32 D_80128778[];
    s32 *var_s0;
    s32 temp_a0;

    var_s0 = &D_80128770; do {
        temp_a0 = var_s0[2];
        if (temp_a0 != 0) {
            var_s0[2] = func_800EE5D8(temp_a0);
        }
        temp_a0 = var_s0[0];
        if (temp_a0 != 0) {
            var_s0[0] = func_800DC060(temp_a0);
        }
        var_s0++;
    } while (var_s0 != D_80128778);
}

/* extern */

void func_800C0064(s32 arg0) {
    s32 _gcskyDll_entrypoint_2(s32 *, s32);
    _gcskyDll_entrypoint_2(&D_80128770, arg0);
}
