#include "common.h"

s32 func_80800000_gcdialogexec(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

/* extern */

void func_8080002C_gcdialogexec(u8 *arg0) {
    s32 _gczoombox_entrypoint_0(s32);
    s32 temp_a0;
    s32 var_s1;
    u8 *var_s0;

    var_s0 = arg0;
    var_s1 = 0;
    do {
        _gczoombox_entrypoint_0((*(s32 *)((s8 *)(var_s0) + (0x120))));
        var_s1 += 1;
        var_s0 += 4;
        (*(s32 *)((s8 *)(var_s0) + (0x11C))) = 0;
    } while (var_s1 != 2);
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x12C)));
    if (temp_a0 != 0) {
        _gczoombox_entrypoint_0(temp_a0);
        (*(s32 *)((s8 *)(arg0) + (0x12C))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808000A0_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800164_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808001DC_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808002E4_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800350_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800478_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_8080052C_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_8080064C_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800A50_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800D30_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800F60_gcdialogexec.s")

s32 func_80801008_gcdialogexec(s32 arg0) {
    s32 result = 0xC8;
    return arg0 ? 0x1C : result;
}

s32 func_80801020_gcdialogexec(s32 arg0) {
    s32 result = 0;
    return arg0 ? 1 : result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80801038_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808011A4_gcdialogexec.s")

void func_80801268_gcdialogexec(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7)
{
  typedef struct 
  {
    s16 id;
    s16 pad;
    s32 data;
  } Text;
  typedef struct 
  {
    u8 state : 2;
    u8 unused : 2;
    u8 rest : 4;
  } BoxFlags;
  typedef struct 
  {
    u8 pad[0x12];
    u16 id : 15;
    u16 flag : 1;
  } Marker;
  typedef struct 
  {
    u8 pad0[0x104];
    Text *text[2];
    s32 data[2];
    u8 count[2];
    u8 index[2];
    s16 id[2];
    BoxFlags boxflags[2];
    u8 pad11e[2];
    s32 box[2];
    s16 y[2];
    u8 pad12c[0x2e];
    s16 flags;
    u32 unused15c : 8;
    u32 numBoxes : 8;
    u32 top : 1;
    u32 active : 1;
    u32 unused1 : 2;
    u32 fast : 1;
    u32 unused2 : 1;
    u32 low : 2;
    u32 opened : 2;
    u32 cleared : 2;
    u32 pending : 2;
    u32 other : 2;
    s8 speed;
    u8 pad161;
    s16 textId;
    u8 pad164[3];
    u8 markerArg;
    void *marker;
    s32 markerId;
    s32 callback;
    s32 callback2;
    s32 callback3;
  } Dialog;
  s32 _gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
  int _gczoombox_entrypoint_10(s32);
  int _gczoombox_entrypoint_24(s32, s32);
  int _gczoombox_entrypoint_25(s32, s32);
  int _gczoombox_entrypoint_35(s32, void *, s32, s32);
  s32 func_800A9C98(void);
  int func_80801038_gcdialogexec(void *, s32);
  int func_80800A50_gcdialogexec();
  s32 func_808011A4_gcdialogexec(s32, s32, f32 *, void *, void *, void *);
  extern void func_800C01D8(void);
  Text *text;
  s32 i;
  s32 j;
  s16 initial;
  u8 count;
  ((Dialog *) arg0)->markerArg = arg7;
  func_80801038_gcdialogexec(arg0, arg1);
  ((Dialog *) arg0)->marker = arg3;
  ((Dialog *) arg0)->cleared = 0;
 if (0) { }
  ((Dialog *) arg0)->numBoxes = (((Dialog *) arg0)->pending = (((Dialog *) arg0)->opened = (((Dialog *) arg0)->other = (u8) ((Dialog *) arg0)->cleared)));
  ((Dialog *) arg0)->callback = arg4;
  ((Dialog *) arg0)->callback2 = arg5;
  ((Dialog *) arg0)->callback3 = arg6;
  ((Dialog *) arg0)->markerId = (arg3) ? ((((Marker *) arg3)->id) ? (((Marker *) arg3)->id) : (-1)) : (-1);
  ((Dialog *) arg0)->low = 0;
  for (i = 0; i < 2; i++)
  {
    text = ((Dialog *) arg0)->text[i];
    j = 0;
    initial = text[0].id;
    if (initial < (-5))
    {
      count = ((Dialog *) arg0)->count[i];
      while (j < count)
      {
        if (text[++j].id >= (-5))
        {
          break;
        }
      }

    }
    ((Dialog *) arg0)->id[i] = initial;
    ((Dialog *) arg0)->data[i] = ((Dialog *) arg0)->text[i][0].data;
    ((Dialog *) arg0)->index[i] = 0;
    ((Dialog *) arg0)->y[i] = func_80801008_gcdialogexec(i);
    ((Dialog *) arg0)->boxflags[i].unused = 0;
    if (((Dialog *) arg0)->text[i][j].id >= 0)
    {
      if (((Dialog *) arg0)->boxflags[i].state == 0)
      {
        if (((((Dialog *) arg0)->text[i][j].id + 0xC) != 0x29) && ((((Dialog *) arg0)->text[i][j].id + 0xC) != 0x84))
        {
          ((Dialog *) arg0)->box[i] = _gczoombox_entrypoint_5(((Dialog *) arg0)->y[i], ((Dialog *) arg0)->text[i][j].id + 0xC, 0, func_80801020_gcdialogexec(i), (s32) func_800C01D8);
        }
        else
        {
          ((Dialog *) arg0)->box[i] = _gczoombox_entrypoint_5(((Dialog *) arg0)->y[i], ((Dialog *) arg0)->text[i][j].id + 0xC, 0, 1 - func_80801020_gcdialogexec(i), (s32) func_800C01D8);
        }
        if (arg2 & 0x100)
        {
          _gczoombox_entrypoint_24(((Dialog *) arg0)->box[i], 0);
        }
        if (arg2 & 0x400)
        {
          _gczoombox_entrypoint_25(((Dialog *) arg0)->box[i], 1);
        }
      }
      else
      {
        if (func_80800000_gcdialogexec(((Dialog *) arg0)->marker, ((Dialog *) arg0)->markerId))
        {
          _gczoombox_entrypoint_35(((Dialog *) arg0)->box[i], ((Dialog *) arg0)->marker, ((Dialog *) arg0)->markerArg, ((Dialog *) arg0)->markerId);
        }
        ((Dialog *) arg0)->opened++;
      }
      ((Dialog *) arg0)->numBoxes++;
    }
    else
      if (((Dialog *) arg0)->text[i][j].id < (-4))
    {
      if (((Dialog *) arg0)->boxflags[i].state != 0)
      {
        _gczoombox_entrypoint_10(((Dialog *) arg0)->box[i]);
        ((Dialog *) arg0)->numBoxes++;
      }
      else
      {
        ((Dialog *) arg0)->box[i] = 0;
      }
      ((Dialog *) arg0)->boxflags[i].state = 0;
    }
    else
      if (((Dialog *) arg0)->boxflags[i].state != 0)
    {
      ((Dialog *) arg0)->numBoxes++;
      ((Dialog *) arg0)->opened++;
    }
  }

  ((Dialog *) arg0)->textId = arg1;
  ((Dialog *) arg0)->flags = arg2;
  if (((Dialog *) arg0)->id[0] < 0)
  {
    ((Dialog *) arg0)->top = 0;
  }
  else
  {
    ((Dialog *) arg0)->top = 1;
  }
  ((Dialog *) arg0)->active = 1;
  if (func_800A9C98() && ((Dialog *) arg0)->fast)
  {
    ((Dialog *) arg0)->speed = 1;
  }
  else
  {
    ((Dialog *) arg0)->speed = -1;
  }
  func_80800A50_gcdialogexec(arg0, (func_800A9C98() && ((Dialog *) arg0)->fast) ? (6) : (1));
  func_808011A4_gcdialogexec((s32) arg0, 5, (f32 *) 2, (void *) 0xF, (void *) (arg2 & 2), (void *) (arg2 & 0x80));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_3.s")

s32 gcdialogexec_entrypoint_4(s32 text_id, s32 arg1, f32 *pos, void *marker, void *callback, void *arg5) {
    s32 func_808011A4_gcdialogexec(s32, s32, f32 *, void *, void *, void *);
    return func_808011A4_gcdialogexec(text_id, arg1, pos, marker, callback, arg5);
}

void gcdialogexec_entrypoint_5()
{
    func_80800D30_gcdialogexec();
}

void gcdialogexec_entrypoint_6()
{
    func_80800A50_gcdialogexec();
}

void gcdialogexec_entrypoint_7()
{
    func_80800164_gcdialogexec();
}

void gcdialogexec_entrypoint_8(s32 arg0)
{
    func_80800A50_gcdialogexec(arg0,0x2);
}

void gcdialogexec_entrypoint_9()
{
    func_80800F60_gcdialogexec();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80801DB4_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80802020_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_10.s")
