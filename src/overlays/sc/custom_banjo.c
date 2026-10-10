#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_banjo/sccustom_banjo_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom_banjo/sccustom_banjo_entrypoint_1.s")

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
