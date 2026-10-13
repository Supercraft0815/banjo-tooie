#include "common.h"

/* extern */

void subaddiemulti_entrypoint_0(s32 arg0) {
    s32 func_800F608C(s32, s32);
    s32 func_800F6438(s32);
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
    s32 func_800F6438(s32);
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
    s32 func_800F6438(s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/multi/subaddiemulti_entrypoint_3.s")

/* extern */

void subaddiemulti_entrypoint_4(s32 arg0) {
    s32 func_800F5EF8(s32);
    s32 func_800F6438(s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/multi/subaddiemulti_entrypoint_6.s")
