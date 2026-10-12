#include "common.h"

OSThread *chdumbwaiterlift_entrypoint_0(void)
{
    extern u8 D_80800BE8_chdumbwaiterlift[];

    return (OSThread *) D_80800BE8_chdumbwaiterlift;
}

/* extern */

void func_8080000C_chdumbwaiterlift(s32 arg0) {
    s32 func_800EE7F8(s32, s32, s32);
    s32 func_8010A828(s32, s32);
    func_800EE7F8(arg0 + 0x28, arg0 + 4, arg0);
    func_8010A828(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800044_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800268_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_808002C0_chdumbwaiterlift.s")

void func_8080035C_chdumbwaiterlift(void *arg0, s32 arg1)
{
  s32 _gcnewoption_entrypoint_1(s32, s32);
  s32 func_800EB854();
  s32 func_80100094(void *, s32);
  s32 func_80101870(void *, s32);
  if (func_800EB854() == 3)
  {
    if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFFu) >> 0xA) == 4)
    {
      _gcnewoption_entrypoint_1(func_80100094(arg0, 0), arg1);
    }
  }
  else
  {
    func_80101870(arg0, arg1);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_808003C4_chdumbwaiterlift.s")

/* extern */

void func_808004E8_chdumbwaiterlift(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    s32 _gcnewoption_entrypoint_32(s32, s32);
    s32 _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
    _gcnewoption_entrypoint_14(arg1, 0, 1, 4, 4.0f);
    _gcnewoption_entrypoint_40(arg1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(arg1, 0xA3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800560_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800608_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800770_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800804_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_808008B4_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_8080094C_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_808009B8_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800A8C_chdumbwaiterlift.s")

void func_80800B40_chdumbwaiterlift(Actor *arg0) {
    void _capod_entrypoint_3(u32);
    void _subaddieDll_entrypoint_4(Actor*, u32);
    if (arg0->unk64_20) {
        _capod_entrypoint_3(0U);
        _subaddieDll_entrypoint_4(arg0, 0U);
        *(volatile u8 *)((s8 *)arg0 + 0x65) = *(volatile u8 *)((s8 *)arg0 + 0x65) & 0xFFEF;
    }
}
