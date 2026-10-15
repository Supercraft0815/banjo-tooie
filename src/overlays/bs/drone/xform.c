#include "common.h"

void func_80800000_bsdronexform(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808011F0_bsdronexform;
    func_800BABB8(arg1, 0, 0, 0x3F800000, &D_808011F0_bsdronexform);
    func_800BA3FC(arg1, arg2);
}

/* extern */

void func_80800050_bsdronexform(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    void func_800BA7C4(void *, f32, f32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    f32 temp_f0;
    s32 temp_f10;
    s32 temp_f6;

    temp_f6 = (s32) (arg2 * 30.0f);
    temp_f10 = (s32) (arg3 * 30.0f);
    func_800BA930(arg1, (s16) temp_f6, 0xA, (s16) temp_f10, (s16) temp_f6, 0xA, (s16) temp_f10);
    temp_f0 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x18C)))) + (0x14)));
    func_800BA7C4(arg1, temp_f0, temp_f0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_808000E4_bsdronexform.s")

/* extern */

void func_808002CC_bsdronexform(void *arg0) {
    s32 func_800B5450(s32);
    func_800B5450((*(s32 *)((s8 *)((*(s32 **)((s8 *)(arg0) + (0x18C)))) + (4))));
    func_800B5450(*(*(s32 **)((s8 *)(arg0) + (0x18C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_80800304_bsdronexform.s")

void func_808003BC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 12) = arg1;
}

void func_808003CC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 24) = arg1;
}

void func_808003DC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 20) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_808003EC_bsdronexform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_8080051C_bsdronexform.s")

/* extern */

void bsdronexform_entrypoint_0(s32 *arg0, s32 arg1) {
    void func_800DFF64(s32 *, s32, f32 *);
    f32 func_800F1074(f32, f32);
    struct player_state_s *func_800F53D0(s32);
    f32 values[3];
    struct player_state_s *self;

    self = func_800F53D0(arg1);
    arg1 = 0;
    do {
        values[arg1] = (*(f32 **)((s8 *)self + 0x18C))[9] + ((*(f32 **)((s8 *)self + 0x18C))[9] * (*(f32 **)((s8 *)self + 0x18C))[10]) * func_800F1074((*(f32 **)((s8 *)self + 0x18C))[8] + ((f32)arg1 / 3.0f) * 0.5f, 0.5f);
        arg1++;
    } while (arg1 != 3);
    func_800DFF64(arg0, 3, values);
}

void func_8080069C_bsdronexform(s32 arg0)
{
    func_8008C9D8(arg0,0);
}

extern void _bsdronexform_entrypoint_0(s32, s32);
void func_808006BC_bsdronexform(void *arg0) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 32) = 0.0f;
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 36) = 1.0f;
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 40) = 0.0f;
    func_8008C9D8(arg0, _bsdronexform_entrypoint_0);
}

void func_80800704_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 40) = arg1;
}

void func_80800714_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 36) = arg1;
}

void func_80800724_bsdronexform(void *arg0) {
    f32 func_800D8FF8();
    void *arg0_copy;
    f32 temp_f0;

    arg0_copy = arg0;
    temp_f0 = func_800D8FF8();
    (*(f32 *)((s8 *)(*(void **)((s8 *)arg0_copy + 0x18C)) + 0x20)) = temp_f0 + (*(f32 *)((s8 *)(*(void **)((s8 *)arg0_copy + 0x18C)) + 0x20));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_80800758_bsdronexform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/bsdronexform_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/bsdronexform_entrypoint_2.s")

f32 func_80800B5C_bsdronexform(void *self, s32 id, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    f32 _batimer_get(void *, s32);
    return func_800F10B4(_batimer_get(self, id), arg2, 0.0f, arg3, arg4);
}

void bsdronexform_entrypoint_3(void *arg0)
{
  s32 _badata_entrypoint_34(void *);
  s32 _batimer_decrement(void *, s32);
  s32 bs_setState(void *, s32);
  void func_8009C118(void *, f32);
  void func_800C59F0(s32, s32, s32);
  s32 func_8080051C_bsdronexform();
  s32 func_80800758_bsdronexform(void *, s32);
  f32 func_80800B5C_bsdronexform(void *, s32, f32, f32, f32);
  s32 sp34;
  f32 sp30;
  f32 sp2C;
  f32 sp28;
  if ((*((u8 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x18C)))) + 0x1C))) != 0)
  {
    func_8080051C_bsdronexform();
  }
  func_80800724_bsdronexform(arg0);
  switch (*((u8 *) (((s8 *) (*((void **) (((s8 *) arg0) + 0x18C)))) + 0x32)))
  {
    case 1:
      sp34 = _batimer_decrement(arg0, 0);
      func_8009C118(arg0, (*((f32 *) (((u8 *) (*((void **) (((u8 *) arg0) + 0x18C)))) + 0x2C))) + func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.0f, 90.0f));
      func_808003BC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.28f, 1.0f));
 func_808003CC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 180.0f, 55.0f)); func_808003DC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.04f, 0.35f)); func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 1.0f, 0.8f)); func_80800704_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.05f, 0.4f)); sp28 = func_80800B5C_bsdronexform(arg0, 0, 2.8f, 255.0f, 200.0f); sp2C = func_80800B5C_bsdronexform(arg0, 0, 2.8f, 255.0f, 80.0f); sp30 = func_80800B5C_bsdronexform(arg0, 0, 2.8f, 255.0f, 80.0f); func_800C59F0((s32) sp28, (s32) sp2C, (s32) sp30); if (sp34 != 0) {
      func_80800758_bsdronexform(arg0, 2);
      return;
    }

    default:
      return;

    case 2:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800704_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.5f, 0.4f, 0.6f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 3);
      return;
    }
      break;

    case 3:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.05f, 0.8f, 1.2f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 4);
      return;
    }
      break;

    case 4:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.8f, 1.2f, 0.09f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 5);
      return;
    }
      break;

    case 5:
      if (_batimer_decrement(arg0, 0) != 0)
    {
      func_80800758_bsdronexform(arg0, 6);
      return;
    }
      break;

    case 6:
      if (_batimer_decrement(arg0, 0) != 0)
    {
      func_80800758_bsdronexform(arg0, 7);
      return;
    }
      break;

    case 7:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.8f, 0.09f, 1.0f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 8);
      return;
    }
      break;

    case 8:
      func_808003DC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 1.0f, 0.35f, 0.03f));
      func_80800704_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 1.0f, 0.6f, 0.05f));
      sp28 = func_80800B5C_bsdronexform(arg0, 0, 1.0f, 200.0f, 255.0f);
      sp2C = func_80800B5C_bsdronexform(arg0, 0, 1.0f, 80.0f, 255.0f);
      sp30 = func_80800B5C_bsdronexform(arg0, 0, 1.0f, 80.0f, 255.0f);
      func_800C59F0((s32) sp28, (s32) sp2C, (s32) sp30);
      if (_batimer_decrement(arg0, 0) != 0)
    {
      func_80800758_bsdronexform(arg0, 9);
      return;
    }
      break;

    case 9:
      sp34 = _batimer_decrement(arg0, 0);
      func_8009C118(arg0, (*((f32 *) (((u8 *) (*((void **) (((u8 *) arg0) + 0x18C)))) + 0x2C))) + func_80800B5C_bsdronexform(arg0, 0, 0.7f, 90.0f, 0.0f));
      if (sp34 != 0)
    {
      bs_setState(arg0, _badata_entrypoint_34(arg0));
    }
      break;

  }

}
