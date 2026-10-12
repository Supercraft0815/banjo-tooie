#include "core2/1ED3900.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA2C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA508.s")

void func_800FA608(void)
{
  s32 defrag(s32);
  extern s32 D_80123880[][7];
  extern s32 D_80123DC0;
  s32 new_var;
  s32 (*var_s0)[7];
  s32 temp_a0;
 var_s0 = D_80123880; do { temp_a0 = var_s0[0][6];
    if (temp_a0 != 0)
    {
      new_var = defrag(temp_a0);
      var_s0[0][6] = new_var;
    }
    var_s0++;
  }
  while (var_s0 != ((s32 (*)[7]) (&D_80123DC0)));
}

void func_800FA660(void)
{
  s32 _scinfobar_entrypoint_1(s32);
  extern s32 D_80123DC0;
  extern s32 D_80123880[][7];
  s32 (*var_s0)[7];
  s32 temp_a0;
 var_s0 = D_80123880; do {
    temp_a0 = var_s0[0][6];
    if (temp_a0 != 0)
    {
      _scinfobar_entrypoint_1(temp_a0);
      var_s0[0][6] = 0;
    }
    var_s0++;
  }
  while (var_s0 != ((s32 (*)[7]) (&D_80123DC0)));
}

void func_800FA6B8(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_80123880[][7];
    if (arg1) {
        arg0 = arg0;
    }
    _scinfobar_entrypoint_3(D_80123880[arg0][6]);
    _scinfobar_entrypoint_8(D_80123880[arg0][6], arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA818.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA874.s")

s32 func_800FA8E8(s32 arg0, s32 arg1) {
    extern s32 D_80123880[][7];
    s32 *temp_v1;

    temp_v1 = D_80123880[arg0];
    if ((temp_v1[6] == 0) || (arg1 != *((s8 *)temp_v1 + 0xE))) {
        return -1;
    }
    return (*((u8 *)temp_v1 + 0xC)) != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FA934.s")

void func_800FA9A8(s32 arg0) {
    extern u8 D_801357B0;
    D_801357B0 = arg0;
}

void func_800FA9B4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_9(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_9(temp_a2, arg1);
    }
}

void func_800FA9F4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_4(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_4(temp_a2, arg1);
    }
}

void func_800FAA34(s32 arg0) {
    s32 _scinfobar_entrypoint_5(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 1);
    }
}

void func_800FAA74(s32 arg0) {
    s32 _scinfobar_entrypoint_5(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED3900/func_800FAAB4.s")
