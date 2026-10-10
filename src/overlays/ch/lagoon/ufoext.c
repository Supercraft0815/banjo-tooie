#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoext/func_80800000_chlagoonufoext.s")

/* extern */

void func_80800168_chlagoonufoext(void *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    s32 func_80100094(void *, s32);
    (*(u8 *)((s8 *)(arg0) + (0x34))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x34))));
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 0)) != 0) {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 0));
    }
}

OSThread *chlagoonufoext_entrypoint_0(void)
{
    extern u8 D_80800558_chlagoonufoext[];

    return (OSThread *) D_80800558_chlagoonufoext;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoext/func_808001D8_chlagoonufoext.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoext/func_808002A4_chlagoonufoext.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/ufoext/func_8080032C_chlagoonufoext.s")

void func_8080047C_chlagoonufoext(u8 *arg0, s32 arg1)
{
  s32 _subaddieskeleton_entrypoint_3(s32, s32, u8 *);
  s32 func_800DF428(f32);
  s32 func_800DF440(s32);
  s32 func_80101808(u8 *, s32 *);
  extern s32 func_801015D0;
  if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) != 3)
  {
    func_800DF428(9000.0);
  }
  else
  {
    func_800DF440(0);
  }
  func_80101808(arg0, &func_801015D0);
  _subaddieskeleton_entrypoint_3(*((s32 *) (((s8 *) arg0) + 0)), 4, arg0 + 0x18);
}
