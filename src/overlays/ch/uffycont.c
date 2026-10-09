#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800000_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_808001F8_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_808002C4_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800440_chchuffycont.s")

/* extern */

void func_8080046C_chchuffycont(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_32(s32, s32);
    _gcnewoption_entrypoint_32(arg1, 66);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800494_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800540_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800620_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_808006A4_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_8080070C_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800768_chchuffycont.s")

s32 chchuffycont_entrypoint_0(s32 *arg0, s32 *arg1)
{
  s32 _gcsectionDll_entrypoint_4(s32);
  void func_800A7A5C(void);
  void func_800A8230(void);
  s32 func_800DA298(s32);
  void func_800DA3B8(s32, s32);
  s32 func_800EA05C(void);
  extern u8 D_8012762C;
  extern s16 D_80800B20_chchuffycont;
  extern s16 D_80800B66_chchuffycont;
  register s16 *end;
  s16 *first_end;
  s16 *var_s0;
  s16 *var_v1;
  s32 temp_s0;
  s32 temp_v0;
  if (func_800EA05C() == 0xD0)
  {
    var_s0 = &D_80800B20_chchuffycont;
    first_end = &D_80800B66_chchuffycont;
    do
    {
      if (func_800DA298(var_s0[1]) != 0)
      {
        break;
      }
      var_s0 += 5;
    }
    while (var_s0 != first_end);
    *arg0 = *var_s0;
    *arg1 = 2;
    if (func_800DA298(0x66B) != 0)
    {
      func_800A7A5C();
    }
    else
    {
      temp_s0 = _gcsectionDll_entrypoint_4(*arg0);
      if (_gcsectionDll_entrypoint_4(0xD0) != temp_s0)
      {
        func_800A8230();
      }
    }
    func_800DA3B8(0x66B, 0);
 return 1; } temp_v0 = func_800EA05C(); var_v1 = &D_80800B20_chchuffycont; end = &D_80800B66_chchuffycont; do { if (temp_v0 == (*var_v1)) { break; }
    var_v1 += 5;
  }
  while (var_v1 != end);
  if (func_800DA298(var_v1[1]) != 0)
  {
    *arg0 = 0xD0;
    *arg1 = 1;
    if (_gcsectionDll_entrypoint_4(0xD0) != D_8012762C)
    {
      func_800A8230();
    }
    return 1;
  }
  return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/chchuffycont_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800A7C_chchuffycont.s")

OSThread *chchuffycont_entrypoint_2(void)
{
    extern u8 D_80800B84_chchuffycont[];

    return (OSThread *) D_80800B84_chchuffycont;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/chchuffycont_entrypoint_3.s")
