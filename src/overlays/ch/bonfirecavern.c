#include "common.h"

OSThread *chbonfirecavern_entrypoint_0(void)
{
    extern u8 D_80800200_chbonfirecavern[];

    return (OSThread *) D_80800200_chbonfirecavern;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bonfirecavern/func_8080000C_chbonfirecavern.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bonfirecavern/func_80800080_chbonfirecavern.s")

void func_80800190_chbonfirecavern(u8 *arg0)
{
  s32 _chfirefx_entrypoint_3(u8 *);
  s32 func_800D9078(s32);
  s32 func_80101FDC(u8 *, s32);
  s32 func_8010A590(u8 *);
  s32 sp24;
  sp24 = func_800D9078(arg0 + 0x24);
  _chfirefx_entrypoint_3(arg0);
  if ((sp24 != 0) && (((((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) >> 0xA) == 1))
  {
    func_80101FDC(arg0, 2);
    func_8010A590(arg0);
  }
}
