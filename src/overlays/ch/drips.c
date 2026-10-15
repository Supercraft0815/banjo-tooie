#include "common.h"

OSThread *chdrips_entrypoint_0(void)
{
    extern u8 D_80800610_chdrips[];

    return (OSThread *) D_80800610_chdrips;
}

void chdrips_entrypoint_1(s32 arg0, s32 arg1)
{
  s32 _fxripple_entrypoint_0(s32, s32);
  s32 func_800C4140(s32, s32, s32);
  f32 func_800DC178(f32, f32);
  func_800C4140(((((u32) (func_800DC178(1.0f, 1.4f) * 1023.0f)) << 13) << 8) + 0xBBD53, arg1, 0x05DC012C);
  _fxripple_entrypoint_0(0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/chdrips_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_80800260_chdrips.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/drips/func_80800394_chdrips.s")

void func_808005CC_chdrips(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, 0U, 0U);
}
