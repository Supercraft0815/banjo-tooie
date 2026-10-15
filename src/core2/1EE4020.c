#include "common.h"

void func_8010A730(s32 arg0, s32 arg1) {
}
/* extern */

void func_8010A73C(Actor *arg0, s32 arg1) {
    s32 func_801039E4(Unk80132ED0 *);
    func_801039E4(arg0->unk0);
}

/* extern */

void func_8010A764(s32 arg0, s32 arg1) {
    void *func_80100368();
    (*(s32 (**)(s32, s32))((s8 *)(func_80100368()) + (0x14)))(arg0, arg1);
}

/* extern */

void func_8010A79C(Actor *arg0, s32 arg1) {
    void *func_80100368(void *arg0);
    struct {
        u8 padding[0x14];
        s32 (*unk14)(Actor *, s32);
    } *methods;
    struct Flags {
        u8 padding[0x7C];
        u32 high : 16;
        u32 unk7C_15 : 1;
        u32 low : 15;
    } *flags = (void *)arg0;
    if (flags->unk7C_15 && !arg0->unk64_17 && arg0->unk64_16) {
        methods = func_80100368(arg0);
        methods->unk14(arg0, arg1);
    }
}

void func_8010A800(void **arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x2A];
        u16 high : 7;
        u16 value : 8;
        u16 low : 1;
    };
    struct Fields *fields = *arg0;

    fields->value = 1 << arg1;
}

void func_8010A828(void **arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x2A];
        u16 high : 7;
        u16 value : 8;
        u16 low : 1;
    };
    struct Fields *fields = *arg0;

    fields->value = arg1;
}

u32 func_8010A848(void **arg0) {
    return (u32) ((*(s32 *)((s8 *)(*arg0) + (0x28))) << 0x17) >> 0x18;
}

void func_8010A85C(u8 *arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x77];
        u8 high : 4;
        u8 low : 4;
    };
    ((struct Fields *)arg0)->low = arg1;
}

void func_8010A874(s32 arg0)
{
  s32 _subaddiezone_entrypoint_1(void *);
  void func_800E3A30(s16 *);
  void func_800EB3D0(void *, s32, s16 *);
  void func_800EB800(void);
  void *func_801067C4(s32 *);
  void *func_8010682C(s32 *);
  s32 var_s0;
  s32 sp50;
  s32 var_s1;
  unsigned int temp_s2;
  s16 sp40[3];
  void *temp_s3;
  void *var_v0;
  func_800EB800();
  func_800E3A30(sp40);
  var_v0 = func_801067C4(&sp50);
  if (var_v0 != NULL)
  {
    do
    {
      temp_s3 = *((void **) (((s8 *) var_v0) + 0));
      if ((((*((u16 *) (((s8 *) temp_s3) + 0x14))) != 0) && ((*((u16 *) (((s8 *) var_v0) + 0x64))) & 1)) && (((*((u8 *) (((s8 *) var_v0) + 0x78))) == 0) || (_subaddiezone_entrypoint_1(var_v0) != 0)))
      {
        var_s1 = 1;
        var_s0 = 0;
        temp_s2 = ((u32) ((*((s32 *) (((s8 *) temp_s3) + 0x28))) << 0x17)) >> 0x18;
        do
        {
          if (temp_s2 & var_s1)
          {
            func_800EB3D0(*((void **) (((s8 *) temp_s3) + 0)), var_s0, sp40);
          }
          var_s0 += 1;
          var_s1 *= 2;
        }
        while (var_s0 != 7);
      }
      var_v0 = func_8010682C(&sp50);
        }
    while (var_v0 != NULL);
  }
}
