#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800000_choildrill.s")

void func_80800104_choildrill(Actor *arg0)
{
  typedef struct 
  {
    f32 time;
    f32 value;
    u8 flags;
    u8 pad[3];
    f32 rate;
  } DrillStep;
  typedef struct 
  {
    f32 v[3];
  } DrillVec;
  extern DrillStep D_8080130C_choildrill[];
  extern DrillVec D_80801300_choildrill;
  void _fxtwinkle_entrypoint_2(f32 *, s32);
  f32 func_800136E4(f32);
  f32 func_80013970(f32);
  void func_800C3F48(u32);
  f32 func_800D8FF8(void);
  s32 func_800D90A4(f32 *);
  s32 func_800D91EC(u8 *, f32);
  f32 func_800DC0C0(void);
  f32 func_800DC178(f32, f32);
  void func_800E0AFC(void *, u8, f32, f32, f32, f32);
  void func_800EE7F8(f32 *, f32 *);
  void func_800EF214(f32 *, f32, f32, f32);
  void func_800EFE50(f32 *, f32 *, f32 *, f32);
  f32 func_800F10B4(f32, f32, f32, f32, f32);
  void func_800FFAB0(Actor *);
  void *func_8010262C(Unk80132ED0 *, s32);
  void func_80103110(void *, s32);
  s32 func_80103DFC(Actor *, f32 *);
  void func_808007DC_choildrill(Actor *, f32, s32);
  void func_808008AC_choildrill(f32 *);
  void func_8080097C_choildrill(Actor *);
  void func_808009F8_choildrill(Actor *, s32);
  void func_80800CF0_choildrill(Actor *, u8, f32);
  u32 step;
  s32 done;
  DrillVec end;
  s32 flags3;
  f32 angle1;
  f32 angle2;
  f32 sparkle[3];
  void *part;
  f32 t;
  switch (arg0->unk70_10)
  {
    case 1:
      func_800FFAB0(arg0);
      break;

    case 4:
      done = func_800D91EC((u8 *) (&arg0->unk58), D_8080130C_choildrill[arg0->unk74_7].time);
      ((f32 *) arg0->actorData)[7] = func_800F10B4(arg0->unk58, D_8080130C_choildrill[((s32) arg0->unk74_7) - 1].time, D_8080130C_choildrill[arg0->unk74_7].time, D_8080130C_choildrill[((s32) arg0->unk74_7) - 1].value, D_8080130C_choildrill[arg0->unk74_7].value) * 180.0f;
      if (arg0->unk58 > 3.0f)
    {
      func_808007DC_choildrill(arg0, func_800F10B4(((f32 *) arg0->actorData)[7], 0.0f, 180.0f, 0.2f, 0.5f), 1);
    }
      if (done)
    {
      if (D_8080130C_choildrill[arg0->unk74_7].flags)
      {
        func_80800CF0_choildrill(arg0, D_8080130C_choildrill[arg0->unk74_7].flags, D_8080130C_choildrill[arg0->unk74_7].rate);
      }
      arg0->unk74_7++;
      if (D_8080130C_choildrill[arg0->unk74_7].time == (-1.0f))
      {
        func_808009F8_choildrill(arg0, 5);
      }
    }
      break;

    case 5:
      if (func_800D90A4((f32 *) (&arg0->actorData[3])))
    {
      func_800C3F48(0x8CBB5BE9);
      ((f32 *) arg0->actorData)[3] = (((f32 *) arg0->actorData)[5] = func_800DC178(0.4f, 0.5f));
    }
      func_800D90A4(&arg0->unk58);
      func_808007DC_choildrill(arg0, 0.5f, 1);
      break;

    case 6:
      end = D_80801300_choildrill;
      if (func_800D90A4(&arg0->unk58))
    {
      arg0->unk79_4--;
      if (arg0->unk79_4 == 0)
      {
        func_800C3F48(0x7FFFFC09);
        func_808009F8_choildrill(arg0, 7);
        func_800EE7F8(arg0->position, (f32 *) arg0->actorData);
      }
      else
      {
        func_800C3F48(0x7FFFFC0A);
        arg0->unk58 = 0.75f;
      }
      func_808008AC_choildrill(arg0->position);
    }
      if (arg0->unk79_4)
    {
      t = func_800F10B4(arg0->unk58, 0.75f, 0.0f, 0.25f, 0.0f);
      func_800EFE50(arg0->position, (f32 *) arg0->actorData, end.v, func_800F10B4(((f32) arg0->unk79_4) - 1, 3.0f, 0.0f, 1.0f, 0.0f) + t);
      arg0->position[1] += (func_80013970(func_800F10B4(arg0->unk58, 0.75f, 0.0f, 0.0f, 180.0f)) * arg0->unk79_4) * 50.0f;
    }
      break;

    case 7:
      func_8080097C_choildrill(arg0);
      break;

    case 8:
      func_8080097C_choildrill(arg0);
      break;

    case 9:
      ((f32 *) arg0->actorData)[7] = func_800F10B4(arg0->unk58, 4.0f, 0.0f, 180.0f, 0.0f);
      if (func_800D90A4(&arg0->unk58))
    {
      func_808009F8_choildrill(arg0, 2);
      func_80103110(arg0, 0);
    }
      break;

 } if ((*((u16 *) (((u8 *) arg0->unk0) + 0x14))) == 0x91F) { arg0->unk50 += ((f32 *) arg0->actorData)[7] * func_800D8FF8(); if (arg0->unk50 >= 360.0f) { arg0->unk50 -= 360.0f; } step = (((arg0->unk50 > 272.0f) && (arg0->unk54 < 272.0f)) ? 9 : 0) | (done = ((arg0->unk50 > 92.0f) && (arg0->unk54 < 92.0f)) ? 5 : 0, flags3 = ((arg0->unk50 > 180.0f) && (arg0->unk50 < 270.0f)) ? 2 : 0, flags3 | done); func_80800CF0_choildrill(arg0, step, func_800F10B4(((f32 *) arg0->actorData)[7], 0.0f, 180.0f, 0.8f, 1.1f)); arg0->unk54 = arg0->unk50; part = func_8010262C(arg0->unk0, 2); if (part) {
      angle1 = func_800136E4(func_80013970(arg0->unk50) * 20.0f);
      angle2 = func_800136E4(-angle1);
      func_800E0AFC(part, 0x2A, -1.0f, angle1, 0.0f, 0.0f);
      func_800E0AFC(part, 0x2B, -1.0f, angle2, 0.0f, 0.0f);
    }
  }
  else
  {
    f32 yaw;
    if (arg0->unk7C_12)
    {
      for (done = 0; done < 4; done++)
      {
        if (func_800DC0C0() < 0.015f)
        {
          func_80103DFC(arg0, sparkle);
          yaw = func_800DC178(0.0f, 360.0f);
          func_800EF214(sparkle, yaw, func_800DC178(0.0f, 360.0f), 40.0f);
          _fxtwinkle_entrypoint_2(sparkle, 0x9E2);
        }
      }

    }
    arg0->rotation[1] += func_800D8FF8() * 230.0f;
    arg0->rotation[1] = func_800136E4(arg0->rotation[1]);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_808007DC_choildrill.s")

void choildrill_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808013DC_choildrill;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_808013DC_choildrill);
}

void func_808008AC_choildrill(f32 *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    s32 func_800BA4D0(s32, s16);
    void func_800BA544(s32 *, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800C6920(f32[3], f32, f32, s32);
    extern s32 D_80801404_choildrill;
    extern s32 _choildrill_entrypoint_0;
    s32 temp_s1;
    f32 sp28;

    temp_s1 = func_800B53A4(8);
    sp28 = arg0[1];
    arg0[1] = func_800C6920(arg0, 200.0f, -200.0f, 0) + 5.0f;
    func_800BABB8(temp_s1, arg0, arg0, 1.0f, &D_80801404_choildrill);
    func_800BA4D0(temp_s1, (s16) (s32) arg0[1]);
    func_800BA544((s32 *) temp_s1, (s32) &_choildrill_entrypoint_0);
    func_800BA22C(temp_s1, 8);
    choildrill_entrypoint_0(0, (s32) arg0);
    arg0[1] = sp28;
}

/* extern */

void func_8080097C_choildrill(Actor *arg0) {
    f32 func_800C6920(f32[3], f32, f32, s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC0C0(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp1C[3];

    if (func_800D90A4(&arg0->unk58) != 0) {
        func_800EE7F8(sp1C, arg0->position);
        sp1C[1] = func_800C6920(sp1C, 200.0f, -200.0f, 0) + 5.0f;
        choildrill_entrypoint_0(0, (s32) sp1C);
        arg0->unk58 = 2.0f * func_800DC0C0();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_808009F8_choildrill.s")

/* extern */

void func_80800B90_choildrill(void **arg0) {
    s32 func_80103140(void **, s32, u16);
    s32 func_8010A590(void **);
    s32 func_8010A624();
    func_8010A624();
    func_8010A590(arg0);
    func_80103140(arg0, 0x610, (*(u16 *)((s8 *)(*arg0) + (0x16))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800BCC_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800CF0_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800F08_choildrill.s")

OSThread *choildrill_entrypoint_1(void)
{
    extern u8 D_808014A8_choildrill[];

    return (OSThread *) D_808014A8_choildrill;
}

/* extern */

void func_808010C0_choildrill(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 func_800DA298(s32);
    _chswitch_entrypoint_7(arg0, 0x351);
    _chswitch_entrypoint_9(arg0);
    ((Actor *)arg0)->unk64_20 = func_800DA298(0x351);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80801110_choildrill.s")

OSThread *choildrill_entrypoint_2(void)
{
    extern u8 D_808014F0_choildrill[];

    return (OSThread *) D_808014F0_choildrill;
}
