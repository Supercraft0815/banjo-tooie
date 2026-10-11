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

void gcdialogexec_entrypoint_10(void *arg0) {
    typedef struct {
        s16 code;
        s16 pad;
        void *text;
    } DialogEntry;
    typedef struct {
        u8 mode : 2;
        u8 busy : 2;
        u8 unused : 4;
    } BoxFlags;
    typedef struct {
        u8 pad0[0x104];
        s32 entries[2];
        u8 *data[2];
        u8 pad114[2];
        u8 index[2];
        s16 code[2];
        BoxFlags boxFlags[2];
        u8 pad11E[2];
        s32 box[2];
        u8 pad128[0x30];
        u8 value;
        u8 pad159;
        u16 flags;
        u8 state;
        u8 count;
        u16 current : 1;
        u16 pending : 1;
        u16 unused15E : 6;
        u32 opened : 2;
        u32 skipped : 2;
        u32 unused15F : 4;
        s8 answer;
        u8 pad161;
        s16 dialogId;
        u8 pad164[3];
        u8 callerId;
        void *caller;
        s32 callerArg;
    } Dialog;
    void func_80015E80(s32, void *);
    void func_80015ECC(s32, void *);
    void func_80015F28(s32, void *);
    void func_80015F5C(s32, void *);
    s32 func_80015F0C(s32, s32);
    int _gcaudiolist_entrypoint_0();
    int _gcdialogcamera_entrypoint_10();
    int _gczoombox_entrypoint_1();
    int _gczoombox_entrypoint_7();
    int _gczoombox_entrypoint_8();
    int _gczoombox_entrypoint_10();
    int _gczoombox_entrypoint_11();
    void _gczoombox_entrypoint_12();
    int _gczoombox_entrypoint_18();
    int _gczoombox_entrypoint_32();
    int _gczoombox_entrypoint_35();
    int _gczoombox_entrypoint_37(s32, s16);
    int _gczoombox_entrypoint_39();
    int _subaddiedialog_entrypoint_15();
    int func_80800478_gcdialogexec();
    int func_80800A50_gcdialogexec();
    int func_80801DB4_gcdialogexec();
    int func_80802020_gcdialogexec();
    s32 scanCode;
    s32 i;
    s32 result = -1;
    s32 face[6];
    s32 side[3];
    s32 handled;
    void *texts[8];
    s32 scanIndex;

    if (((Dialog *)arg0)->flags & 0x80) {
        func_80015ECC(0, face);
        func_80015F5C(0, side);
    } else {
        func_80015E80(0, face);
        func_80015F28(0, side);
    }
    switch (((Dialog *)arg0)->state) {
    case 1:
        i = 0;
        for (scanIndex = 0; scanIndex < 2; scanIndex++) {
            if (((Dialog *)arg0)->box[scanIndex] == 0) {
                i++;
            }
        }
        if (i == 2) {
            func_80800A50_gcdialogexec(arg0, 7);
        } else if (((Dialog *)arg0)->count == ((u32)((u8 *)arg0)[0x15F] >> 6)) {
            ((Dialog *)arg0)->opened = 0;
            func_80800A50_gcdialogexec(arg0, 2);
        }
        break;
    case 2:
        handled = 0;
        ((Dialog *)arg0)->code[((Dialog *)arg0)->current] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((s32)((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8)))->code;
        ((Dialog *)arg0)->data[((Dialog *)arg0)->current] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((s32)((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8)))->text;
        switch (((Dialog *)arg0)->code[((Dialog *)arg0)->current]) {
        case -8:
            func_80800478_gcdialogexec(arg0, *((Dialog *)arg0)->data[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            handled = 1;
            break;
        case -9:
            if (!(((Dialog *)arg0)->flags & 0x200)) {
                _gcdialogcamera_entrypoint_10(arg0, *((Dialog *)arg0)->data[((Dialog *)arg0)->current], 0);
            }
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            handled = 1;
            break;
        case -2:
            ((Dialog *)arg0)->value = *((Dialog *)arg0)->data[((Dialog *)arg0)->current];
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            func_80800A50_gcdialogexec(arg0, 11);
            handled = 1;
            break;
        case -1:
            if (_subaddiedialog_entrypoint_15(((Dialog *)arg0)->caller, ((Dialog *)arg0)->dialogId, ((Dialog *)arg0)->index[((Dialog *)arg0)->current]) == 1) {
                func_80800A50_gcdialogexec(arg0, 9);
            }
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            handled = 1;
            break;
        }
        if (handled) {
            break;
        }
        if (((Dialog *)arg0)->box[((Dialog *)arg0)->current] == 0 || _gczoombox_entrypoint_39(((Dialog *)arg0)->box[((Dialog *)arg0)->current]) || ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].busy) {
            ((Dialog *)arg0)->current ^= 1;
            break;
        }
        switch (((Dialog *)arg0)->code[((Dialog *)arg0)->current]) {
        case -10:
        case -11:
            do {
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
                ((Dialog *)arg0)->code[((Dialog *)arg0)->current] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((s32)((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8)))->code;
            } while (((Dialog *)arg0)->code[((Dialog *)arg0)->current] == -10 || ((Dialog *)arg0)->code[((Dialog *)arg0)->current] == -11);
            break;
        case -4:
            if (((Dialog *)arg0)->index[((Dialog *)arg0)->current] == 0) {
                ((Dialog *)arg0)->skipped++;
            }
            _gczoombox_entrypoint_12(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 1;
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].busy = 1;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        case -5:
            _gczoombox_entrypoint_12(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            _gczoombox_entrypoint_10(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 0;
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].busy = 1;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        case -7:
            for (scanIndex = ((Dialog *)arg0)->index[((Dialog *)arg0)->current]; (scanCode = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + scanIndex * 8))->code) < -5; scanIndex++) {}
            if (scanCode >= 0) {
                _gczoombox_entrypoint_37(((Dialog *)arg0)->box[((Dialog *)arg0)->current], scanCode + 12);
            }
            if (((Dialog *)arg0)->index[((Dialog *)arg0)->current]) {
                _gczoombox_entrypoint_12(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            }
            if (((Dialog *)arg0)->index[((Dialog *)arg0)->current] == 0 && ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode == 2) {
                _gczoombox_entrypoint_12(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            }
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 0;
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        case -6:
            _gczoombox_entrypoint_12(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
            ((Dialog *)arg0)->boxFlags[((Dialog *)arg0)->current].mode = 0;
            ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            ((Dialog *)arg0)->current ^= 1;
            ((Dialog *)arg0)->pending = 1;
            break;
        default:
            if (((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))[1].code == -10) {
                result = func_80801DB4_gcdialogexec(arg0);
            } else if (((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))[1].code == -11) {
                result = func_80802020_gcdialogexec(arg0);
            }
            if (!_gczoombox_entrypoint_1(((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + ((Dialog *)arg0)->index[((Dialog *)arg0)->current] * 8))->text)) {
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
                break;
            }
            if (func_80800000_gcdialogexec(((Dialog *)arg0)->caller, ((Dialog *)arg0)->callerArg)) {
                _gczoombox_entrypoint_35(((Dialog *)arg0)->box[((Dialog *)arg0)->current], ((Dialog *)arg0)->caller, ((Dialog *)arg0)->callerId, ((Dialog *)arg0)->callerArg);
            }
            if (result == -1) {
                if (_gczoombox_entrypoint_37(((Dialog *)arg0)->box[((Dialog *)arg0)->current], ((Dialog *)arg0)->code[((Dialog *)arg0)->current] + 12)) {
                    _gczoombox_entrypoint_12(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                    ((Dialog *)arg0)->pending = 1;
                } else {
                    _gczoombox_entrypoint_18(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                }
            }
            if (((Dialog *)arg0)->pending) {
                _gczoombox_entrypoint_11(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                ((Dialog *)arg0)->pending = 0;
            }
            if (result == -1) {
                for (i = ((Dialog *)arg0)->index[((Dialog *)arg0)->current];
                     ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))->code == ((Dialog *)arg0)->code[((Dialog *)arg0)->current] &&
                     i - ((Dialog *)arg0)->index[((Dialog *)arg0)->current] < 8 &&
                     ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))[1].code != -11 &&
                     ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))[1].code != -10;
                     i++) {
                    texts[i - ((Dialog *)arg0)->index[((Dialog *)arg0)->current]] = ((DialogEntry *)(((Dialog *)arg0)->entries[((Dialog *)arg0)->current] + (i << 3)))->text;
                }
                _gczoombox_entrypoint_32(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                _gczoombox_entrypoint_7(((Dialog *)arg0)->box[((Dialog *)arg0)->current], i - ((Dialog *)arg0)->index[((Dialog *)arg0)->current], texts);
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current] = i;
            } else {
                _gczoombox_entrypoint_32(((Dialog *)arg0)->box[((Dialog *)arg0)->current]);
                _gczoombox_entrypoint_8(((Dialog *)arg0)->box[((Dialog *)arg0)->current], arg0);
                ((Dialog *)arg0)->index[((Dialog *)arg0)->current]++;
            }
            func_80800A50_gcdialogexec(arg0, 3);
            break;
        }
        break;
    case 3:
        if ((((Dialog *)arg0)->flags & 1) && face[1] == 1) {
            func_80800A50_gcdialogexec(arg0, 6);
        } else if (!(((Dialog *)arg0)->flags & 0x40)) {
            if ((((Dialog *)arg0)->flags & 0x80) ? func_80015F0C(0, 1) == 1 : func_80015F0C(0, 0) == 1) {
                func_80800A50_gcdialogexec(arg0, 6);
            }
        }
        break;
    case 4:
        if (face[0] == 1) {
            ((Dialog *)arg0)->answer = 1;
            _gcaudiolist_entrypoint_0(6);
        } else if (face[1] == 1) {
            ((Dialog *)arg0)->answer = 0;
            _gcaudiolist_entrypoint_0(7);
        }
        if (((Dialog *)arg0)->answer != -1) {
            func_80800A50_gcdialogexec(arg0, 10);
        }
        break;
    case 7:
        func_80800A50_gcdialogexec(arg0, 0);
        break;
    }
}
