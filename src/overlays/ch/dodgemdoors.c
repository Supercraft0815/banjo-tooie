#include "common.h"

void func_80800000_chdodgemdoors(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A63C(void ***);

    arg0->unk74_7 = arg0->unk74_7 - 0x32;
    arg0->position[2] = -645.0f;
    func_80103140(arg0, (u16)(arg0->unk74_7 + 0x767), arg0->unk0->unk16);
    func_8010A63C(arg0);
    if (func_800DA298(arg0->unk74_7 + 0xAB) != 0) {
        func_80101FDC(arg0, 3);
        arg0->position[1] = 275.0f;
    }
}

s32 func_808000A0_chdodgemdoors(Actor *arg0, s32 arg1, s32 arg2)
{
  void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
  s32 _gcfrontend_entrypoint_9(s32);
  s32 func_800D0A9C(u32, u32);
  s32 func_800D10D4(u32, u32, f32 *, s32, s32);
  s32 func_800DA298(s32);
  s32 func_800DA544(s32);
  void func_80101FDC(Actor *, u32);
  switch (arg1)
  {
    case 0x49:
      if ((func_800DA298(0xA5) && func_800DA298(arg0->unk74_7 + 0xA8)) && (!func_800DA298(arg0->unk74_7 + 0xAB)))
    {
 do { func_80101FDC(arg0, 2); _capod_entrypoint_13(arg0->unk0, NULL, (arg0->unk74_7 * 2) + 3, 0x2010); func_800DA544(arg0->unk74_7 + 0xAB); } while (0);
      switch (arg0->unk74_7)
      {
        case 0:
          _gcfrontend_entrypoint_9(0x64);
          break;

        case 1:
          _gcfrontend_entrypoint_9(0x65);
          break;

        case 2:
          _gcfrontend_entrypoint_9(0x66);
          break;

      }

    }
      if (((arg0->unk74_7 == 2) && func_800DA298(0xB0)) && (!func_800D0A9C(0x16, 1)))
    {
      func_800D10D4(0x16, 1, NULL, 1, 0);
      _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x10);
    }
      break;

    case 0xA:
      if (arg0->unk74_7 == 0)
    {
      func_800DA544(arg0->unk74_7 + 0xAB);
      func_80101FDC(arg0, 2);
      _capod_entrypoint_13(arg0->unk0, NULL, (arg0->unk74_7 * 2) + 3, 0x2010);
      _gcfrontend_entrypoint_9(0x64);
    }
      break;

    default:
      return 0;

  }

  return 1;
}

void func_8080026C_chdodgemdoors(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800D8FF8(void);
    s32 func_800DA544(s32);
    void func_80101FDC(Actor *, u32);
    extern u8 D_80800360_chdodgemdoors[];

    switch (arg0->unk70_10) {
        case 2:
            if (!arg0->unk74_30) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800360_chdodgemdoors);
                arg0->unk74_30 = 1;
            }
            if (arg0->position[1] < 275.0f) {
                arg0->position[1] += 175.0f * func_800D8FF8();
            } else {
                func_80101FDC(arg0, 3);
                func_800DA544(arg0->unk74_7 + 0xAB);
            }
            break;
        case 1:
        case 3:
            break;
    }
}

OSThread *chdodgemdoors_entrypoint_0(void)
{
    extern u8 D_80800374_chdodgemdoors[];

    return (OSThread *) D_80800374_chdodgemdoors;
}
