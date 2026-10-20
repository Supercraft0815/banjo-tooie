#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_0.s")

void idtwinklecolour_entrypoint_1(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    if ((*(s16 *)((s8 *)(arg3) + (0x1E))) == (*(s16 *)((s8 *)(arg3) + (0x1C)))) {
        (*(s16 *)((s8 *)(arg3) + (0xE))) = (s16) (*(s16 *)((s8 *)(arg1) + (0)));
        (*(s16 *)((s8 *)(arg3) + (0x10))) = (s16) (*(s16 *)((s8 *)(arg1) + (2)));
        (*(s16 *)((s8 *)(arg3) + (0x12))) = (s16) (*(s16 *)((s8 *)(arg1) + (4)));
    }
    (*(s16 *)((s8 *)(arg3) + (0x1C))) = (s16) ((*(s16 *)((s8 *)(arg3) + (0x1C))) + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_2.s")

void func_80800574_idtwinklecolour(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _glid_entrypoint_2(s32, s32, s32 *, void *);
    s16 func_800DC214(s16, s16);
    extern s32 _idtwinklecolour_entrypoint_0;
    extern s32 _idtwinklecolour_entrypoint_1;
    s16 temp_v0;

    (*(s16 *)((s8 *)(arg0) + (0x1E))) = func_800DC214(0, (*(s16 *)((s8 *)(arg0) + (0xC))));
    (*(s16 *)((s8 *)(arg0) + (0x1C))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x20))) = (s16) arg3;
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_1, arg0);
    temp_v0 = func_800DC214((*(s16 *)((s8 *)(arg0) + (0x18))), (*(s16 *)((s8 *)(arg0) + (0x1A))));
    (*(s32 *)((s8 *)(arg0) + (0x14))) = (s32) (temp_v0 * temp_v0);
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_0, arg0);
}

/* extern */

void idtwinklecolour_entrypoint_3(void *arg0) {
    s32 heap_free(s32);
    heap_free((*(s32 *)((s8 *)(arg0) + (0x24))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklecolour/idtwinklecolour_entrypoint_4.s")

void idtwinklecolour_entrypoint_5(s16 *arg0, s32 arg1, s32 arg2)
{
  s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
  f32 func_800D8FF8(void);
  s32 func_800E3DC0(s16 *, s16 *);
  extern s32 _idtwinklecolour_entrypoint_2;
  f32 sp34;
  f32 temp_f0;
  s32 var_s0;
  s32 var_s1;
  u8 *temp_v0;
  sp34 = func_800D8FF8();
  if (func_800E3DC0(arg0, arg0 + 3) != 0)
  {
    var_s1 = 0;
 do { if ((*((s16 *) (((s8 *) arg0) + 0x22))) > 0) { var_s0 = 0; do { temp_v0 = (*((s32 *) (((s8 *) arg0) + 0x24))) + var_s0; *((f32 *) (((s8 *) temp_v0) + 0)) += ((f32) (*((s8 *) (((s8 *) temp_v0) + 0xB)))) * sp34; temp_v0 = (*((s32 *) (((s8 *) arg0) + 0x24))) + var_s0; temp_f0 = *((f32 *) temp_v0); if (temp_f0 >= 1.0f) { *((f32 *) temp_v0) = 1.0f; temp_v0 = (*((s32 *) (((s8 *) arg0) + 0x24))) + var_s0; *((s8 *) (((s8 *) temp_v0) + 0xB)) = (s8) (-(*((s8 *) (((s8 *) temp_v0) + 0xB)))); } else if (temp_f0 < 0.0f) { *((f32 *) temp_v0) = 0.0f; *((s8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x24))) + var_s0)) + 0xD)) = 1; } var_s1 += 1; var_s0 += 0x14; } while (var_s1 < (*((s16 *) (((s8 *) arg0) + 0x22)))); var_s1 = 0; } _glid_entrypoint_0(arg1, arg2, &_idtwinklecolour_entrypoint_2, (s32) arg0); } while (0);
    var_s0 = 0;
    if ((*((s16 *) (((s8 *) arg0) + 0x22))) > 0)
    {
      do
      {
        if ((*((u8 *) (((s8 *) ((*((s32 *) (((s8 *) arg0) + 0x24))) + var_s0)) + 0xD))) != 0)
        {
          func_80800574_idtwinklecolour(arg0, arg1, arg2, var_s1);
        }
        var_s1 += 1;
        var_s0 += 0x14;
      }
      while (var_s1 < (*((s16 *) (((s8 *) arg0) + 0x22))));
    }
  }
}
