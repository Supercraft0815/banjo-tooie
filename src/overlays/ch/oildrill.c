#include "common.h"

void func_80800000_choildrill(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80103110(void *, s32);
    void func_808009F8_choildrill(Actor *, s32);
    f32 sp34[3];
    f32 sp28[3];
    f32 *sp24[1];

    if (func_800EA05C() == 0x111) {
        if (func_800D0B68(0x42, 1) != 0) {
            func_800FFAB0(arg0);
            return;
        }
        if (func_800D0A9C(0x42, 1) != 0) {
            func_808009F8_choildrill(arg0, 8);
            return;
        }
        func_808009F8_choildrill(arg0, 1);
        return;
    }
    func_808009F8_choildrill(arg0, 2);
    if (func_800DA298(0x351) != 0) {
        func_80103110(arg0, 0);
        return;
    }
    _subaddieskeleton_entrypoint_0(arg0, 0x2B, sp34);
    sp24[0] = (f32 *)arg0->actorData;
    func_800EFA4C(sp24[0], sp34[0], sp34[1] - 5000.0f, sp34[2]);
    func_800BEF00(sp34, sp24[0], sp28, 0);
}
typedef struct { f32 time; f32 value; u8 flags; u8 pad[3]; f32 rate; } DrillStep; typedef struct { f32 v[3]; } DrillVec;
void func_80800104_choildrill(Actor *arg0)
{












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
  void func_80103DFC(Actor *actor,f32 *center);
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

 } if ((arg0->unk0->unk14) == 0x91F) { arg0->unk50 += ((f32 *) arg0->actorData)[7] * func_800D8FF8(); if (arg0->unk50 >= 360.0f) { arg0->unk50 -= 360.0f; } step = (((arg0->unk50 > 272.0f) && (arg0->unk54 < 272.0f)) ? 9 : 0) | (done = ((arg0->unk50 > 92.0f) && (arg0->unk54 < 92.0f)) ? 5 : 0, flags3 = ((arg0->unk50 > 180.0f) && (arg0->unk50 < 270.0f)) ? 2 : 0, flags3 | done); func_80800CF0_choildrill(arg0, step, func_800F10B4(((f32 *) arg0->actorData)[7], 0.0f, 180.0f, 0.8f, 1.1f)); arg0->unk54 = arg0->unk50; part = func_8010262C(arg0->unk0, 2); if (part) {
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

void func_808007DC_choildrill(Actor *arg0, f32 arg1, s32 arg2) {
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC0C0(void);
    extern u32 D_8080138C_choildrill[3];
    extern s32 D_80801398_choildrill[14];
    extern f32 D_808013D0_choildrill[3];
    if (arg2 != 0) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_8080138C_choildrill);
        _subaddieaudioloop_entrypoint_0(arg0, arg1);
        if (func_800DC0C0() < 0.4f) {
            func_800BBCB8(D_808013D0_choildrill, NULL, 1.0f, 1, D_80801398_choildrill);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

void choildrill_entrypoint_0(s32 arg0, f32 *arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808013DC_choildrill[10];
    func_800BBCB8(arg1, NULL, 1.0f, 1, D_808013DC_choildrill);
}

void func_808008AC_choildrill(f32 *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA4D0(void *emitter, s16 min_y);
    void func_800BA544(s32 *, BtIntPtr);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800C6920(f32[3], f32, f32, s32);
    extern s32 D_80801404_choildrill[19];
#ifndef BT_NATIVE
    extern s32 _choildrill_entrypoint_0;
#endif
    BtIntPtr temp_s1;
    f32 sp28;

    temp_s1 = func_800B53A4(8);
    sp28 = arg0[1];
    arg0[1] = func_800C6920(arg0, 200.0f, -200.0f, 0) + 5.0f;
    func_800BABB8(temp_s1, arg0, arg0, 1.0f, D_80801404_choildrill);
    func_800BA4D0(temp_s1, (s16) (s32) arg0[1]);
    func_800BA544((s32 *) temp_s1, (BtIntPtr) &_choildrill_entrypoint_0);
    func_800BA22C(temp_s1, 8);
    choildrill_entrypoint_0(0, arg0);
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
        choildrill_entrypoint_0(0, sp1C);
        arg0->unk58 = 2.0f * func_800DC0C0();
    }
}

void func_808009F8_choildrill(Actor *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void func_800C3F48(u32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FC6B0(u32);
    void func_80102424(Actor *, s32);
    void func_80800B90_choildrill(void **);
    f32 temp;

    switch (arg1) {
    case 1:
        func_80800B90_choildrill((void *)arg0);
        arg0->unk64_16 = 0;
        break;
    case 2:
        arg0->unk50 = 0.0f;
        arg0->unk54 = 0.0f;
        ((f32 *)arg0->actorData)[7] = 0.0f;
        break;
    case 4:
        arg0->unk58 = 0.0f;
        _capod_entrypoint_13(arg0->unk0, NULL, 0x54, 0x810);
        func_800C3F48(0x7FFFFD1C);
        arg0->unk74_7 = 1;
        break;
    case 5:
        func_800FC6B0(0x18);
        ((f32 *)arg0->actorData)[7] = 180.0f;
        temp = func_800DC178(0.4f, 0.5f);
        ((f32 *)arg0->actorData)[5] = temp;
        ((f32 *)arg0->actorData)[3] = temp;
        arg0->unk58 = 5.0f;
        break;
    case 6:
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        func_80800B90_choildrill((void *)arg0);
        arg0->unk79_4 = 4;
        arg0->unk58 = 0.75f;
        break;
    case 7:
        arg0->unk58 = 2.0f * func_800DC0C0();
        break;
    case 8:
        func_80800B90_choildrill((void *)arg0);
        arg0->unk58 = 2.0f * func_800DC0C0();
        break;
    case 9:
        ((f32 *)arg0->actorData)[7] = 180.0f;
        arg0->unk58 = 4.0f;
        func_808007DC_choildrill(arg0, 0.0f, 0);
        break;
    }
    func_80102424(arg0, arg1);
}

/* extern */

void func_80800B90_choildrill(void **arg0) {
    s32 func_80103140(void **, s32, u16);
    void func_8010A590(Actor *arg0);
    s32 func_8010A624();
    func_8010A624();
    func_8010A590(arg0);
    func_80103140(arg0, 0x610, (*(u16 *)((s8 *)(*arg0) + (0x16))));
}

s32 func_80800BCC_choildrill(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _chjigsawcollect_entrypoint_1(Actor **, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    void func_800D0BD4(s32, u32);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    void func_800FFAB0(Actor *);
    void func_80108B04(Actor *, u32);

    switch (arg1) {
    case 0xB:
        if (arg2 == 0x54) {
            func_808009F8_choildrill(arg0, 9);
            func_800D1000(0x42, 1, arg0->position, 3, 0);
            _glcutDll_entrypoint_6(0x111, 0x85);
        }
        return 3;
    case 0x49:
        if (arg2 == 0x85) {
            func_808009F8_choildrill(arg0, 6);
            _capod_entrypoint_13(arg0->unk0, 0, 8, 0x900);
            return 1;
        }
        return 0;
    case 0x3D:
        _chjigsawcollect_entrypoint_1(&arg0, 0x42, 0);
        func_800FFAB0(arg0);
        return 1;
    case 0x3E:
        func_80108B04(arg0, 0);
        func_800D0BD4(0x42, 1);
        return 1;
    case 0xA:
        func_808009F8_choildrill(arg0, 4);
        return 1;
    default:
        return 0;
    }
}

void func_80800CF0_choildrill(Actor *arg0, u8 arg1, f32 arg2) {
    void func_800C4140(u32, f32 *, u32);
    s32 func_8001210C(s32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80801450_choildrill[];
    if (arg1 & 4) {
        func_800C4140(((u16)(arg2 * 1023.0f) << 21) + 0x9C608, arg0->position, 0x12C000FA);
    }
    if (arg1 & 8) {
        func_800C4140(((u16)(arg2 * 1023.0f) << 21) + 0x9C609, arg0->position, 0x12C000FA);
    }
    if ((arg1 & 2) && *(f32 *)((u8 *)arg0 + 0x34) > 135.0f && func_8001210C(1)) {
        func_800BBCB8((f32 *)((u8 *)arg0 + 0x18), (f32 *)((u8 *)arg0 + 0x18), 1.0f, 1, D_80801450_choildrill);
    }
}

void func_80800F08_choildrill(Actor *arg0, void *arg1) {
    void _fxtwinkle_entrypoint_0(f32 *);
    f32 func_80013970(f32);
    void *func_800D674C(s32);
    f32 func_800DC178(f32, f32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF830(s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101870(Actor *, void *);
    extern f32 D_80801490_choildrill[3];
    extern f32 D_8080149C_choildrill[3];
    void *sp64;
    f32 sp60;
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];

    func_80101870(arg0, arg1);
    if (arg0->unk70_10 == 5) {
        sp64 = func_800D674C(0x610);
        sp60 = func_800F10B4(arg0->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
        func_800EFE50(sp54, D_80801490_choildrill, D_8080149C_choildrill, sp60);
        sp48[2] = 0.0f;
        sp48[0] = sp48[2];
        sp48[1] = sp60 * 360.0f;
        sp60 = func_800F10B4(((f32 *)arg0->actorData)[3], ((f32 *)arg0->actorData)[5], 0.0f, 0.0f, 1.0f);
        sp54[1] += func_80013970(180.0f * sp60) * func_800F10B4(((f32 *)arg0->actorData)[5], 0.5f, 0.4f, 300.0f, 200.0f);
        func_800EEC30(sp3C, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f), 40.0f);
        func_800EF04C(sp3C, sp54);
        _fxtwinkle_entrypoint_0(sp3C);
        func_800DF830(1);
        func_800DE498(arg1, sp54, sp48, 1.0f, NULL, (BtIntPtr)sp64);
    }
}

OSThread *choildrill_entrypoint_1(void)
{
    extern ActorData D_808014A8_choildrill[];

    return (OSThread *) D_808014A8_choildrill;
}

/* extern */

void func_808010C0_choildrill(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_9(void *arg0);
    s32 func_800DA298(s32);
    _chswitch_entrypoint_7(arg0, 0x351);
    _chswitch_entrypoint_9(arg0);
    ((Actor *)arg0)->unk64_20 = func_800DA298(0x351);
}

/* extern */

s32 func_80801110_choildrill(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    BtUIntPtr func_800F54E4(void);
    int func_800F6B94(BtIntPtr);
    s32 func_80101180(s32, s32, BtIntPtr);
    Actor *actor = (Actor *)arg0;
    if (arg1 != 7) {
        if (arg1 == 0x91) {
            if (func_800F6B94(func_800F54E4()) != 0) {
                if (!actor->unk74_29 && (func_800DA298(0x351) == 0)) {
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x12BE, 0xC, actor->position, 0x6F);
                    actor->unk74_29 = 1;
                    return _chswitch_entrypoint_10(arg0, arg1, arg2);
                }
                goto block_9;
            }
            if (!actor->unk74_30 && (func_800DA298(0x351) == 0)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x12BD, 4, actor->position, 0x6F);
                actor->unk74_30 = 1;
            }
block_9:
            return 0;
        }
        goto block_11;
    }
    func_80101180(0x484, 0xA, 0);
block_11:
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *choildrill_entrypoint_2(void)
{
    extern ActorData D_808014F0_choildrill[];

    return (OSThread *) D_808014F0_choildrill;
}
/* data_to_c.py: from asm/data/overlays/ch/oildrill.data.s */
extern u8 D_808012B0_choildrill[];
void func_80105834(Actor*);
void func_80108ED0();
void func_80107C2C();
extern u8 D_8011A1BC[];
void _chswitch_entrypoint_6();
void func_80101870 ( Actor * , void * );
u8 D_808012B0_choildrill[80] BT_DATA(4, overlays_ch_oildrill, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x4A, 0x00, 0x00 };
DrillVec D_80801300_choildrill BT_DATA(4, overlays_ch_oildrill, 0x50) = { { -6460.0f, 0.0f, 1777.0f } };
DrillStep D_8080130C_choildrill [8] BT_DATA(4, overlays_ch_oildrill, 0x5C) = { { 0.0f, 0.0f, 0, { 0, 0, 0 }, 0.0f }, { 2.0f, 0.0f, 1, { 0, 0, 0 }, 0.0f }, { 6.0f, 0.0f, 5, { 0, 0, 0 }, 1.1f }, { 6.5f, 0.3f, 5, { 0, 0, 0 }, 1.1f }, { 7.0f, 0.1f, 5, { 0, 0, 0 }, 1.1f }, { 9.0f, 0.4f, 1, { 0, 0, 0 }, 0.0f }, { 18.0f, 1.0f, 1, { 0, 0, 0 }, 0.0f }, { -1.0f, 0.0f, 0, { 0, 0, 0 }, 0.0f } };
u32 D_8080138C_choildrill[3] BT_DATA(4, overlays_ch_oildrill, 0xDC) = { 0x1304B4, 0x103E8, 0x27100000 };
s32 D_80801398_choildrill[14] BT_DATA(4, overlays_ch_oildrill, 0xE8) = { 1903068, 1572864, 1250304, 503316507, 19661325, 851998, 2054746, 1509949462, 301989925, 83887872, 1376335, 10027051, 42074880, 0 };
f32 D_808013D0_choildrill [ 3 ] BT_DATA(4, overlays_ch_oildrill, 0x120) = { -5260.0f, 3600.0f, 4510.0f };
s32 D_808013DC_choildrill[10] BT_DATA(4, overlays_ch_oildrill, 0x12C) = { 1903067, 1445889, 2818560, 50331669, 4194496, 2228480, 16777984, 83886111, -1263891456, -2013134848 };
s32 D_80801404_choildrill[19] BT_DATA(4, overlays_ch_oildrill, 0x154) = { 1903065, 1834008, -58982355, 19661200, 1445888, 2293790, 1376268, 15073323, 67109888, 3080320, 8388608, 3342425, 153, 3276750, -655353, 65547, 1310770, 327680, 0 };
s32 D_80801450_choildrill [16] BT_DATA(4, overlays_ch_oildrill, 0x1A0) = { 1903092, 1834558, -36044755, 9830650, 851998, 1446912, 2490618, 16384000, 26214800, 34, 11731200, 4980864, 262297, 458754, 3276790, -1966080 };
f32 D_80801490_choildrill [ 3 ] BT_DATA(4, overlays_ch_oildrill, 0x1E0) = { -5530.0f, 3015.0f, 4600.0f };
f32 D_8080149C_choildrill [ 3 ] BT_DATA(4, overlays_ch_oildrill, 0x1EC) = { -6230.0f, 2980.0f, 6520.0f };
ActorData D_808014A8_choildrill [1] BT_DATA(4, overlays_ch_oildrill, 0x1F8) = { { 344, 1156, 2335, 2, (void *)D_808012B0_choildrill, (void (*)(struct Actor *))func_80800104_choildrill, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800F08_choildrill, 262164000, 0, 0, 0, 128, 3104, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_choildrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800BCC_choildrill, 0 } };
ActorData D_808014F0_choildrill [1] BT_DATA(4, overlays_ch_oildrill, 0x240) = { { 344, 1157, 2354, 1, (void *)((u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808010C0_choildrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80801110_choildrill, 0 } };
