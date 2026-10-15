#include "common.h"

/* extern */

void subaddiemulti_entrypoint_0(s32 arg0) {
    s32 func_800F608C(s32, s32);
    s32 func_800F6438(u32);
    s32 func_800F82D4(s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_800F82D4(var_s0, 2);
            if (arg0 != 0) {
                func_800F608C(var_s0, arg0);
            }
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

/* extern */

void subaddiemulti_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800F608C(s32, s32);
    s32 func_800F6438(u32);
    s32 func_800F8300(s32, s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_800F8300(var_s0, 2, arg1);
            if (arg0 != 0) {
                func_800F608C(var_s0, arg0);
            }
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

/* extern */

void subaddiemulti_entrypoint_2(void) {
    s32 func_800F6438(u32);
    s32 func_800F82D4(s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_800F82D4(var_s0, 0);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

/* extern */

void subaddiemulti_entrypoint_3(s32 arg0) {
    Prop *_gccubesearch_entrypoint_14(s32, s32);
    void _plcamera_entrypoint_8(s32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EFD24(f32 *);
    s32 func_800F6438(u32);
    void func_800F8294(s32, f32 *);
    s32 func_800F832C(s32, f32 *);
    s32 var_s0;
    Prop *temp_v0;
    f32 sp3C[3];
    f32 sp30[3];

    func_800EFD24(sp30);
    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            temp_v0 = _gccubesearch_entrypoint_14(arg0, 0);
            func_800EE88C(sp3C, temp_v0->position);
            sp30[1] = temp_v0->FlagOrRotation;
            func_800F8294(var_s0, sp3C);
            func_800F832C(var_s0, sp30);
            _plcamera_entrypoint_8(var_s0);
        }
        var_s0 += 1;
        arg0 += 1;
    } while (var_s0 != 8);
}

/* extern */

void subaddiemulti_entrypoint_4(s32 arg0) {
    s32 func_800F5EF8(s32);
    s32 func_800F6438(u32);
    s32 _ncfixposrot_entrypoint_8(s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            _ncfixposrot_entrypoint_8(func_800F5EF8(var_s0), arg0);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

u32 subaddiemulti_entrypoint_5(void *arg0)
{
  u32 _suegg_entrypoint_7(void *);
  s32 _sueggmisc_entrypoint_0();
  u32 func_800F54E4(void *);
  if (_sueggmisc_entrypoint_0() != 0)
  {
    return _suegg_entrypoint_7(arg0);
  }
  if ((((u32) (*((u32 *) (((s8 *) arg0) + 0x24)))) >> 0x16) == 0)
  {
    return (((u16) (*((u16 *) (((s8 *) arg0) + 0x1A)))) & 0xFFFFFFFFu) >> 5;
  }
  return func_800F54E4(arg0);
}

void subaddiemulti_entrypoint_6(f32 *arg0, f32 arg1) {
    void func_800EEB9C(f32 dst[3], f32 angle, f32 distance);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800EFC7C(void *, void *);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    s32 func_800F8418(s32, f32 *);
    f32 sqrtf(f32);
    f32 sp50[4];
    f32 height;
    f32 angle;
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_800F5A00(var_s0, sp50);
            if (arg1 < func_800EFC7C(arg0, sp50)) {
                height = sp50[1];
                angle = func_800F1DF4(arg0, sp50);
                func_800EEB9C(sp50, angle, sqrtf(arg1));
                func_800EF04C(sp50, arg0);
                sp50[1] = height;
                func_800F8418(var_s0, sp50);
            }
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}
