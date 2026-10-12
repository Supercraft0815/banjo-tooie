#include "common.h"

OSThread *chweldarbossdoors_entrypoint_0(void)
{
    extern u8 D_80800270_chweldarbossdoors[];

    return (OSThread *) D_80800270_chweldarbossdoors;
}

OSThread *chweldarbossdoors_entrypoint_1(void)
{
    extern u8 D_808002B8_chweldarbossdoors[];

    return (OSThread *) D_808002B8_chweldarbossdoors;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/doors/func_80800018_chweldarbossdoors.s")

void func_808000E0_chweldarbossdoors(Actor *arg0, s32 arg1, s32 arg2)
{
  s32 _chdoor_entrypoint_1(s32, s32, s32);
  void func_80103140(Actor *, u32, u16);
  if (arg1 == 0x95)
  {
    func_80103140(arg0, (((((u16) (*((u16 *) (((s8 *) arg0) + 0x76)))) & 0xFFFFFFFFu) >> 7) + 0x837) & 0xFFFF, 0U);
  }
  _chdoor_entrypoint_1((s32) arg0, arg1, arg2);
}

void func_80800140_chweldarbossdoors(void *arg0, s32 arg1)
{
  s32 func_800DF744(s32, s32, void *);
  s32 func_80101870(void *, s32);
  s32 var_a1;
  if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 1)
  {
    var_a1 = 0;
  }
  else
  {
    var_a1 = 1;
  }
  func_800DF744(1, var_a1, arg0);
  func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/doors/func_80800194_chweldarbossdoors.s")
