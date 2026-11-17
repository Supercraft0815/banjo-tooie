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
  s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
  void _gcfrontend_entrypoint_9(s32 arg0);
  s32 func_800D0A9C(u32, u32);
  BtIntPtr func_800D10D4(u32, u32, f32 *, s32, BtIntPtr);
  s32 func_800DA298(s32);
  void func_800DA544(s32 index);
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
    void func_800DA544(s32 index);
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
    extern ActorData D_80800374_chdodgemdoors[];

    return (OSThread *) D_80800374_chdodgemdoors;
}
/* data_to_c.py: from asm/data/overlays/ch/dodgemdoors.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
u8 D_80800360_chdodgemdoors [20] BT_DATA(4, overlays_ch_dodgemdoors, 0x0) = { 0, 0x13, 5, 0x1C, 0, 0xA, 1, 0, 0, 0x16, 0x6D, 0x60, 0, 1, 1, 0xF4, 0x13, 0x88, 0, 0 };
ActorData D_80800374_chdodgemdoors [1] BT_DATA(4, overlays_ch_dodgemdoors, 0x14) = { { 172, 775, 1895, 1, 0, (void (*)(struct Actor *))func_8080026C_chdodgemdoors, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 8, 4100, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chdodgemdoors, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 18, (void (*)(struct Actor *, long, long))func_808000A0_chdodgemdoors, 0 } };
