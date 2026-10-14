#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/worldmake/func_80800000_idworldmake.s")

/* extern */

void idworldmake_entrypoint_0(s32 arg0, s32 arg1) {
    s16 *_glidmake_entrypoint_1();
    s32 func_80800000_idworldmake(s32, s16, s32, s32, s32);
    s16 *sp34;
    s16 *temp_v0;
    s16 *var_s2;
    s16 temp_a1;
    s32 var_s3;

    temp_v0 = _glidmake_entrypoint_1();
    sp34 = temp_v0;
    var_s2 = temp_v0 + 1;
    var_s3 = 0;
    if (*temp_v0 > 0) {
        do {
            temp_a1 = (*(s16 *)((s8 *)(var_s2) + (0)));
            if ((temp_a1 >= 0x65) && (temp_a1 < 0xC8)) {
                func_80800000_idworldmake(arg0, temp_a1, 1, temp_a1 - 0x64, arg1);
            } else if ((temp_a1 >= 0xC8) && (temp_a1 < 0x12C)) {
                func_80800000_idworldmake(arg0, temp_a1, 0, temp_a1 - 0xC8, arg1);
            } else if ((temp_a1 >= 0x12C) && (temp_a1 < 0x190)) {
                func_80800000_idworldmake(arg0, temp_a1, 3, temp_a1 - 0x12C, arg1);
            } else if ((temp_a1 >= 0x190) && (temp_a1 < 0x1F4)) {
                func_80800000_idworldmake(arg0, temp_a1, 2, temp_a1 - 0x190, arg1);
            } else if ((temp_a1 >= 0x1F4) && (temp_a1 < 0x258)) {
                func_80800000_idworldmake(arg0, temp_a1, 4, temp_a1 - 0x1F4, arg1);
            } else if ((temp_a1 >= 0x258) && (temp_a1 < 0x2BC)) {
                func_80800000_idworldmake(arg0, temp_a1, 2, temp_a1 - 0x258, arg1);
            } else if ((temp_a1 >= 0x2BC) && (temp_a1 < 0x320)) {
                func_80800000_idworldmake(arg0, temp_a1, 5, temp_a1 - 0x2BC, arg1);
            } else if ((temp_a1 >= 0x320) && (temp_a1 < 0x384)) {
                func_80800000_idworldmake(arg0, temp_a1, 6, temp_a1 - 0x320, arg1);
            } else if ((temp_a1 >= 0x384) && (temp_a1 < 0x3E8)) {
                func_80800000_idworldmake(arg0, temp_a1, 8, temp_a1 - 0x384, arg1);
            } else if ((temp_a1 >= 0x3E8) && (temp_a1 < 0x44C)) {
                func_80800000_idworldmake(arg0, temp_a1, 7, temp_a1 - 0x3E8, arg1);
            } else if ((temp_a1 >= 0x44C) && (temp_a1 < 0x4B0)) {
                func_80800000_idworldmake(arg0, temp_a1, 9, temp_a1 - 0x44C, arg1);
            } else if ((temp_a1 >= 0x4B0) && (temp_a1 < 0x6A4)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xA, temp_a1 - 0x4B0, arg1);
            } else if ((temp_a1 >= 0x6A4) && (temp_a1 < 0x708)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xB, temp_a1 - 0x6A4, arg1);
            } else if ((temp_a1 >= 0x708) && (temp_a1 < 0x76C)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xC, temp_a1 - 0x708, arg1);
            } else if ((temp_a1 >= 0x76C) && (temp_a1 < 0x7D0)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xD, temp_a1 - 0x76C, arg1);
            } else if ((temp_a1 >= 0x7D0) && (temp_a1 < 0x834)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xE, temp_a1 - 0x7D0, arg1);
            } else if ((temp_a1 >= 0x834) && (temp_a1 < 0x898)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xA, temp_a1 - 0x4B0, arg1);
            } else if ((temp_a1 >= 0x898) && (temp_a1 < 0x8FC)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xF, temp_a1 - 0x898, arg1);
            }
            var_s3 += 1;
            var_s2 += var_s2[1];
            var_s2 += 2;
        } while (var_s3 < *sp34);
    }
}

void idworldmake_entrypoint_1(s32 arg0, s32 arg1, volatile unsigned int arg2, s32 arg3)
{
  s16 *_glidmake_entrypoint_1();
  s32 func_80800000_idworldmake(s32, s16, s32, s32, s32);
  s16 *sp3C;
  s16 *temp_v0;
  s16 *var_s3;
  s16 temp_a1;
  s32 var_s4;
  temp_v0 = _glidmake_entrypoint_1();
  sp3C = temp_v0;
  var_s3 = temp_v0;
  var_s3 = var_s3 + 1;
  var_s4 = 0;
  if ((*temp_v0) > 0)
  {
    do
    {
      temp_a1 = *((s16 *) (((s8 *) var_s3) + 0));
      if (arg2 == temp_a1)
      {
        if ((arg1 >= 0x65) && (arg1 < 0xC8))
        {
          func_80800000_idworldmake(arg0, temp_a1, 1, arg1 - 0x64, arg3);
        }
        else
          if ((arg1 >= 0xC8) && (arg1 < 0x12C))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0, arg1 - 0xC8, arg3);
        }
        else
          if ((arg1 >= 0x12C) && (arg1 < 0x190))
        {
          func_80800000_idworldmake(arg0, temp_a1, 3, arg1 - 0x12C, arg3);
        }
        else
          if ((arg1 >= 0x190) && (arg1 < 0x1F4))
        {
          func_80800000_idworldmake(arg0, temp_a1, 2, arg1 - 0x190, arg3);
        }
        else
          if ((arg1 >= 0x1F4) && (arg1 < 0x258))
        {
          func_80800000_idworldmake(arg0, temp_a1, 4, arg1 - 0x1F4, arg3);
        }
        else
          if ((arg1 >= 0x258) && (arg1 < 0x2BC))
        {
          func_80800000_idworldmake(arg0, temp_a1, 2, arg1 - 0x258, arg3);
        }
        else
          if ((arg1 >= 0x320) && (arg1 < 0x384))
        {
          func_80800000_idworldmake(arg0, temp_a1, 6, arg1 - 0x320, arg3);
        }
        else
          if ((arg1 >= 0x384) && (arg1 < 0x3E8))
        {
          func_80800000_idworldmake(arg0, temp_a1, 8, arg1 - 0x384, arg3);
        }
        else
          if ((arg1 >= 0x3E8) && (arg1 < 0x44C))
        {
          func_80800000_idworldmake(arg0, temp_a1, 7, arg1 - 0x3E8, arg3);
        }
        else
          if ((arg1 >= 0x44C) && (arg1 < 0x4B0))
        {
          func_80800000_idworldmake(arg0, temp_a1, 9, arg1 - 0x44C, arg3);
        }
        else
          if ((arg1 >= 0x6A4) && (arg1 < 0x708))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xB, arg1 - 0x6A4, arg3);
        }
        else
          if ((arg1 >= 0x708) && (arg1 < 0x76C))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xC, arg1 - 0x708, arg3);
        }
        else
          if ((arg1 >= 0x76C) && (arg1 < 0x7CF))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xD, arg1 - 0x76C, arg3);
        }
        else
          if ((arg1 >= 0x2BC) && (arg1 < 0x320))
        {
          func_80800000_idworldmake(arg0, temp_a1, 5, arg1 - 0x2BC, arg3);
        }
        else
          if ((arg1 >= 0x4B0) && (arg1 < 0x6A4))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xA, arg1 - 0x4B0, arg3);
        }
        else
          if ((arg1 >= 0x898) && (arg1 < 0x8FC))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xF, arg1 - 0x898, arg3);
        }
      }
      var_s4 += 1;
      var_s3 += *((s16 *) (((s8 *) var_s3) + 2));
      var_s3 += 2;
    }
    while (var_s4 < (*sp3C));
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/worldmake/idworldmake_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/worldmake/idworldmake_entrypoint_3.s")

void idworldmake_entrypoint_4(void) {
}

void idworldmake_entrypoint_5(s32 arg0, s32 arg1) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80127EF8;
    u32 temp_v0;
    u32 sp18;
    u32 var_v1;

    sp18 = vector_end(D_80127EF8);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp18) {
        do {
            if (arg0 == (*(s32 *)((s8 *)(var_v1) + (0)))) {
                (*(s8 *)((s8 *)(var_v1) + (7))) = (s8) arg1;
            }
            var_v1 += 0xA8;
        } while (var_v1 < sp18);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/worldmake/idworldmake_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/worldmake/idworldmake_entrypoint_7.s")
