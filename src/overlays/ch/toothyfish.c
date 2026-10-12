#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800000_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_808000E8_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800188_chtoothyfish.s")

void func_808002DC_chtoothyfish(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    void _subaddieskeleton_entrypoint_2(Unk80132ED0*, s32, f32*);
    extern u32 D_8080178C_chtoothyfish;
    extern u32 D_8080179C_chtoothyfish;
    extern u32 D_80801858_chtoothyfish;
    extern u32 D_80801864_chtoothyfish;
    f32 sp1C[3];

    if (arg0->unk7C_12) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 0xA, sp1C);
        _subaddieaudioquick_entrypoint_4(arg0, sp1C, &D_8080178C_chtoothyfish, &D_80801858_chtoothyfish);
        _subaddieaudioquick_entrypoint_4(arg0, sp1C, &D_8080179C_chtoothyfish, &D_80801864_chtoothyfish);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800350_chtoothyfish.s")

void func_808003D4_chtoothyfish(s32 arg0, u8 *arg1)
{
  s32 func_808000E8_chtoothyfish(s32, s32, s32, u8 *);
  s32 sp18;
  s32 var_a2;
  s32 var_v0;
  u8 *var_v1;
  var_a2 = 0;
 do { var_v0 = 0; var_v1 = arg1; do { var_v0 += 1; if ((*((u8 *) (((s8 *) var_v1) + 0x34))) == 0) { var_a2 += 1; } var_v1 += 1; } while (var_v0 != 5); } while (0);
  if (var_a2 != (*((u8 *) (((s8 *) arg1) + 0x3E))))
  {
    if (var_a2 != 0)
    {
      sp18 = var_a2;
      func_808000E8_chtoothyfish(arg0, 2, var_a2, arg1);
    }
    else
    {
      sp18 = var_a2;
      func_808000E8_chtoothyfish(arg0, 3, var_a2, arg1);
    }
    *((u8 *) (((s8 *) arg1) + 0x3E)) = ((u8) var_a2) & 0xFFFF;
  }
}

/* extern */

void func_80800470_chtoothyfish(Actor *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s32 func_808000E8_chtoothyfish(s32, s32, s32, u8 *);
    if (arg0->unk70_10 == 6) {
        if (arg1) {
            arg1 = 5;
        } else {
            arg1 = 5;
        }
        func_808000E8_chtoothyfish((s32) arg0, arg1, arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_808004A4_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800908_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_8080096C_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800B68_chtoothyfish.s")

OSThread *chtoothyfish_entrypoint_0(void)
{
    extern u8 D_80801870_chtoothyfish[];

    return (OSThread *) D_80801870_chtoothyfish;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800E04_chtoothyfish.s")

void func_80800EDC_chtoothyfish(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800EE4_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800F6C_chtoothyfish.s")

void func_8080106C_chtoothyfish(Actor *self)
{
  f32 func_800D8FF8(void);
  void func_800EFA20(void *, void *, f32);
  void func_800EF04C(f32 *, f32 *);
  s32 func_800DC298(f32);
  f32 func_800DC178(f32, f32);
  s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
  s32 func_80102D4C(Actor *, f32);
  s32 func_80102CF4(Actor *, f32);
  void func_80102B6C(u8 *, f32);
  void func_80102B2C(Actor *, f32);
  void func_80800EE4_chtoothyfish(Actor *, s32);
  void func_80800F6C_chtoothyfish(f32 *, f32, f32);
  f32 delta[3];
  f32 dt;
  dt = func_800D8FF8();
  func_800EFA20(delta, &self->actorData[4], dt);
  switch (self->unk70_10)
  {
    case 1:
      func_800EF04C(self->position, delta);
      ((f32 *) self->actorData)[4] *= 0.7f;
      ((f32 *) self->actorData)[6] *= 0.7f;
      ((f32 *) self->actorData)[5] += ((f32 *) self->actorData)[7] * dt;
      if (((f32 *) self->actorData)[5] < (-50.0f))
    {
      func_80800EE4_chtoothyfish(self, 2);
    }
      self->rotation[0] += 400.0f * dt;
      self->rotation[1] += 200.0f * dt;
      if (func_800DC298(0.2f))
    {
      func_80800F6C_chtoothyfish(self->position, 200.0f, self->scale);
    }
      break;

    case 2:
      func_800EF04C(self->position, delta);
      ((f32 *) self->actorData)[4] *= 0.7f;
      ((f32 *) self->actorData)[6] *= 0.7f;
      ((f32 *) self->actorData)[5] += ((f32 *) self->actorData)[7] * dt;
      if (_subaddie3d_entrypoint_0(self->position, 0.0f, self->scale * (-200.0f), &((f32 *) self->actorData)[1]))
    {
      if ((((f32 *) self->actorData)[1] + (20.0f * self->scale)) < (delta[1] + self->position[1]))
      {
        self->position[1] += delta[1];
      }
      else
      {
        func_80800EE4_chtoothyfish(self, 4);
      }
    }
    else
      if (func_80102D4C(self, 4.0f))
    {
      func_80800EE4_chtoothyfish(self, 3);
    }
    else
    {
      func_80102B6C((u8 *) self, 4.0f);
    }
      if (func_800DC298(0.2f))
    {
      func_80800F6C_chtoothyfish(self->position, 200.0f, self->scale);
    }
      break;

    case 3:
      ((f32 *) self->actorData)[4] *= 0.7f;
      ((f32 *) self->actorData)[6] *= 0.7f;
      ((f32 *) self->actorData)[5] += ((f32 *) self->actorData)[7] * dt;
      self->position[0] += ((f32 *) self->actorData)[4];
      self->position[2] += ((f32 *) self->actorData)[6];
      if (_subaddie3d_entrypoint_0(self->position, 0.0f, self->scale * (-200.0f), &((f32 *) self->actorData)[1]))
    {
      if ((((f32 *) self->actorData)[1] + (50.0f * self->scale)) < (delta[1] + self->position[1]))
      {
        self->position[1] += delta[1];
      }
      else
      {
        func_80800EE4_chtoothyfish(self, 4);
      }
    }
    else
    {
      self->position[1] += delta[1];
    }
      if (!func_80102D4C(self, 3.0f))
    {
      func_80102B6C((u8 *) self, 3.0f);
    }
      if (!func_80102CF4(self, 3.0f))
    {
      func_80102B2C(self, 3.0f);
    }
      if (func_800DC298(0.1f))
    {
      self->unk50 = func_800DC178(140.0f, 220.0f);
    }
      if (func_800DC298(0.1f))
    {
      self->unk54 = self->rotation[1] + func_800DC178(-90.0f, 90.0f);
    }
      if (func_800DC298(0.2f))
    {
      func_80800F6C_chtoothyfish(self->position, 200.0f, self->scale);
    }
      break;

    case 4:
      if ((((f32 *) self->actorData)[1] + (10.0f * self->scale)) < self->position[1])
    {
      self->position[1] += ((f32 *) self->actorData)[5] * dt;
    }
    else
      if (self->position[1] < ((f32 *) self->actorData)[1])
    {
      self->position[1] += 4.0f;
    }
      if (!func_80102D4C(self, 8.0f))
    {
      func_80102B6C((u8 *) self, 8.0f);
    }
    else
    {
      func_80800EE4_chtoothyfish(self, 5);
    }
      break;

    case 5:
      if ((((f32 *) self->actorData)[1] + (10.0f * self->scale)) < self->position[1])
    {
      self->position[1] += ((f32 *) self->actorData)[5] * dt;
    }
    else
      if (self->position[1] < (((f32 *) self->actorData)[1] + (5.0f * self->scale)))
    {
      self->position[1] += 4.0f;
    }
    else
    {
      ((u8 *) self)[0x7E] &= ~0x40;
    }
      break;

  }

}

/* extern */

void func_80801588_chtoothyfish(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    Actor* func_801084B0(s32, Actor**);
    s32 func_800DA544(s32);
    Actor *sp1C;
    u8 *sp18;

    sp18 = func_80100094(arg0, 0U);
    sp1C = func_801084B0(0x310, &arg0);
    func_800DA544(arg1 + 0x4F6);
    (*(s8 *)((s8 *)((sp18 + arg1)) + (0x34))) = 1;
    sp1C->unk3C = arg0->unk0;
    sp1C->unk6C_0 = arg1;
}

OSThread *chtoothyfish_entrypoint_1(void)
{
    extern u8 D_80801914_chtoothyfish[];

    return (OSThread *) D_80801914_chtoothyfish;
}
