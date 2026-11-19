#include "core2/1ED3900.h"
#include "infobar_hud_entries.inc"
void func_800FA010(void) {
    extern HudInfoEntry D_80123880[48];
    extern s8 D_80123DC0[10];
    extern u8 D_801357B0;
    s8 *entry;
    HudInfoEntry *item;
    u32 i;
    f32 total = 0.0f;

    i = 0;
clear_entries:
    {
        D_80123880[i].flag = 0;
        i++;
        if (i < 48U) goto clear_entries;
    }
    entry = D_80123DC0;
    i = 0;
sum_counts:
    {
        total += *entry++;
        i++;
        if (i < 10U) goto sum_counts;
    }
    i = 0;
init_entries:
    {
        D_80123880[i].dx = (D_80123880[i].direction & 1) ? 0 : 1 - D_80123880[i].direction;
        D_80123880[i].dy = (D_80123880[i].direction & 1) ? D_80123880[i].direction - 2 : 0;
        D_80123880[i].state = 0;
        D_80123880[i].flag11 = 0;
        D_80123880[i].mode = 0;
        D_80123880[i].x = D_80123880[i].homeX - D_80123880[i].dx * total;
        D_80123880[i].y = D_80123880[i].homeY - D_80123880[i].dy * total;
        i++;
        if (i != 48U) goto init_entries;
    }
    D_801357B0 = 1;
}

void func_800FA130(s32 arg0, s32 arg1) {
    void *_scinfobar_entrypoint_0(s32 arg0, s32 arg1, s32 arg2);
    BT_LP64_ONLY(void _scinfobar_entrypoint_1(void *, s32);) BT_ILP32_ONLY(s32 _scinfobar_entrypoint_1(s32);) BT_IDO_ONLY(s32 _scinfobar_entrypoint_1(s32);)
    void _scinfobar_entrypoint_6(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32), s32);
    extern HudInfoEntry D_80123880[48];

    if (arg1 != D_80123880[arg0].state) {
        D_80123880[arg0].state = arg1;
        switch (arg1) {
        case 1:
            if (D_80123880[arg0].handle == 0) {
                D_80123880[arg0].handle = _scinfobar_entrypoint_0(D_80123880[arg0].type, D_80123880[arg0].style, D_80123880[arg0].mode);
            }
            break;
        case 2:
            if (D_80123880[arg0].x != D_80123880[arg0].homeX || D_80123880[arg0].y != D_80123880[arg0].homeY) {
                D_80123880[arg0].x = D_80123880[arg0].homeX;
                D_80123880[arg0].y = D_80123880[arg0].homeY;
            }
            if (D_80123880[arg0].flag11 == 0) {
                _scinfobar_entrypoint_6(D_80123880[arg0].handle, 1);
            }
            break;
        case 3:
            _scinfobar_entrypoint_6(D_80123880[arg0].handle, 0);
            break;
        case 0:
            if (D_80123880[arg0].handle != 0) {
                HUD_RELEASE(D_80123880[arg0].handle, arg1);
                D_80123880[arg0].handle = 0;
            }
            break;
        }
    }
}

void func_800FA240(s32 arg0, s32 arg1) {
    extern HudInfoEntry D_80123880[48];
    HudInfoEntry *entry;

    entry = &D_80123880[arg0];
    entry->flag = arg1;
    switch (arg1) {
    case 0:
        if (entry->state != 0) {
            func_800FA130(arg0, 3);
        }
        break;
    case 1:
        if (entry->state != 2) {
            func_800FA130(arg0, 1);
        }
        break;
    }
}

void func_800FA2C0(void) {
    extern HudInfoEntry D_80123880[48];
    extern s8 D_80123DC0[10];
    f32 func_800D8FF8(void);
    int func_800FA874(s32, s32);
    void _scinfobar_entrypoint_2(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32));
    s32 _scinfobar_entrypoint_21(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32));
    void _scinfobar_entrypoint_6(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32), s32);
    f32 dt[2];
    HudInfoEntry *entry;










    s32 i;
    s8 step;
    s8 (*table)[10];

    dt[0] = func_800D8FF8();
    for (i = 0; i < 0x30; i++) {
        entry = &D_80123880[i];
        if (entry->flag == 1 && func_800FA874(i, entry->type)) {
            if (entry->timer >= 0.0f) {
                entry->timer -= dt[0];
                if (entry->timer < 0.0f) {
                    entry->timer = 0.0f;
                    func_800FA240(i, 0);
                }
            }
        }
    }
    table = &D_80123DC0;
    for (i = 0; i < 0x30; i++) {
        entry = &D_80123880[i];
        if (entry->handle != 0) {
            _scinfobar_entrypoint_2(entry->handle);
        }
        switch (entry->state) {
        case 1:
            if ((u32)entry->frame < 10U) {
                step = (*table)[entry->frame];
                entry->x = (s32)entry->x + entry->dx * step;
                entry->y = (s32)entry->y + entry->dy * step;
                entry->frame++;
            }
            if ((u32)entry->frame >= 10U) {
                entry->frame = 10;
                func_800FA130(i, 2);
            }
            break;
        case 2:
            if (_scinfobar_entrypoint_21(entry->handle) && entry->flag11 == 0) {
                _scinfobar_entrypoint_6(entry->handle, 1);
            }
            break;
        case 3:
            if (_scinfobar_entrypoint_21(entry->handle)) {
                if (entry->frame > 0) {
                    entry->frame = entry->frame - 1;
                    step = (*table)[entry->frame];
                    entry->x = (s32)entry->x - entry->dx * step;
                    entry->y = (s32)entry->y - entry->dy * step;
                }
                if (entry->frame <= 0) {
                    entry->frame = 0;
                    func_800FA130(i, 0);
                }
            }
            break;
        }
    }
}    typedef struct { u8 pad0[0x6]; s16 unk6; s16 unk8; } Obj1ED3900_func_800FA508_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

void func_800FA508(BtIntPtr arg0) {
    void _scinfobar_entrypoint_24(BtIntPtr arg0, void *arg1, s32 arg2, s32 arg3);
    s32 func_800A9C98(void);
    int func_800DB9B0(void);
    extern HudInfoEntry D_80123880[48];
    BT_IDO_ONLY(extern s32 D_80123998;)
    BT_IDO_ONLY(extern s32 D_801239B4;)
    BT_IDO_ONLY(extern s32 D_80123D6C;)
    extern s8 D_80123DC0[10];
    extern u8 D_801357B0;
    HudInfoEntry *var_s0;
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) temp_a1;
    int var_v1;
    int var_v1_2;

    if (D_801357B0 != 0) {
        var_v1 = func_800A9C98() != 0 || func_800DB9B0() != 0;
        var_s0 = D_80123880; do { temp_a1 = var_s0->handle;
            if (temp_a1 != 0) {
                var_v1_2 = (BtIntPtr) var_s0 != (BtIntPtr)BT_DATA_FIELD(&D_80123880[11], &D_801239B4) && (BtIntPtr) var_s0 != (BtIntPtr)BT_DATA_FIELD(&D_80123880[10], &D_80123998) && (BtIntPtr) var_s0 != (BtIntPtr)BT_DATA_FIELD(&D_80123880[45], &D_80123D6C);
                if ((var_v1 == 0) || (var_v1_2 == 0)) {
                    _scinfobar_entrypoint_24(arg0, temp_a1, var_s0->x, var_s0->y);
                }
            }
            var_s0++;
        } while (var_s0 != BT_DATA_FIELD(D_80123880 + 48, (HudInfoEntry *)&D_80123DC0));
    }
}

void func_800FA608(void)
{
  BtIntPtr defrag(BtIntPtr);
  extern HudInfoEntry D_80123880[48];
  extern s8 D_80123DC0[10];
  BtIntPtr new_var;
  HudInfoEntry *var_s0;
  BT_LP64_ONLY(void *) BT_ILP32_ONLY(s32) BT_IDO_ONLY(s32) temp_a0;
 var_s0 = D_80123880; do { temp_a0 = var_s0->handle;
    if (temp_a0 != 0)
    {
      new_var = defrag((BtIntPtr)temp_a0);
      var_s0->handle = (void *)new_var;
    }
    var_s0++;
  }
  while (var_s0 != BT_DATA_FIELD(D_80123880 + 48, (HudInfoEntry *)&D_80123DC0));
}

void func_800FA660(BT_PARAM_OR_VOID(BT_PASS2(s32 bt_a0, s32 bt_a1)))
{
  BT_LP64_ONLY(void _scinfobar_entrypoint_1(void *, s32);) BT_ILP32_ONLY(s32 _scinfobar_entrypoint_1(s32);) BT_IDO_ONLY(s32 _scinfobar_entrypoint_1(s32);)
  extern s8 D_80123DC0[10];
  extern HudInfoEntry D_80123880[48];
  HudInfoEntry *var_s0;
  BT_LP64_ONLY(void *) BT_ILP32_ONLY(s32) BT_IDO_ONLY(s32) temp_a0;
 var_s0 = D_80123880; do {
    temp_a0 = var_s0->handle;
    if (temp_a0 != 0)
    {
      HUD_RELEASE(temp_a0, bt_a1);
      var_s0->handle = 0;
    }
    var_s0++;
  }
  while (var_s0 != BT_DATA_FIELD(D_80123880 + 48, (HudInfoEntry *)&D_80123DC0));
}

void func_800FA6B8(s32 arg0, s32 arg1, s32 arg2) {
    extern HudInfoEntry D_80123880[48];
    if (arg1) {
        arg0 = arg0;
    }
    HUD_STYLE(D_80123880[arg0].handle, arg1);
    _scinfobar_entrypoint_8(D_80123880[arg0].handle, arg2);
}

s32 func_800FA708(u32 arg0, s32 arg1, s32 arg2, u32 arg3)
{
  void _scinfobar_entrypoint_6(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32), s32);
  s32 _scinfobar_entrypoint_16(s16 *arg0);
  s32 _scinfobar_entrypoint_22(u8 *arg0);
  s32 _scinfobar_entrypoint_23(u8 *arg0);
  s32 _scinfobar_entrypoint_7(void *arg0, s32 arg1);
  extern HudInfoEntry D_80123880[48];
  HudInfoEntry *entry;
  BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) handle;
  s32 state;
  u32 mode;
  entry = &D_80123880[arg1];
  if ((arg2 != (D_80123880[arg1].type)) || (arg3 != (D_80123880[arg1].mode)))
  {
    handle = entry->handle;
    if ((handle != 0) && (_scinfobar_entrypoint_23(handle) != 0))
    {
      return 0;
    }
    handle = entry->handle;
    if ((handle != 0) && (_scinfobar_entrypoint_7(handle, arg2) == 0))
    {
      return 0;
    }
  }
  state = arg2;
  mode = arg3;
  D_80123880[arg1].type = state;
  D_80123880[arg1].flag11 = 0;
  D_80123880[arg1].mode = mode;
  func_800FA240(arg1, 1);
  D_80123880[arg1].timer = 2.0f;
  if ((_scinfobar_entrypoint_16(D_80123880[arg1].handle) != arg2) && (_scinfobar_entrypoint_22(D_80123880[arg1].handle) != 0))
  {
    _scinfobar_entrypoint_6(D_80123880[arg1].handle, 0);
  }
  func_800FA6B8(arg1, arg3, arg0);
  return 1;
}

s32 func_800FA818(s32 arg0, s32 arg1) {
    void func_800FA240(s32, s32);
    extern HudInfoEntry D_80123880[48];
    if ((D_80123880[arg0].handle == 0) || (arg1 != D_80123880[arg0].type)) {
        return 0;
    }
    func_800FA240(arg0, 0);
    return 1;
}    typedef struct { u8 pad0[0xC]; u8 unkC; u8 padD[0x1]; s8 unkE; } Obj1ED3900_func_800FA874_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

int func_800FA874(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_22(u8 *arg0);
    extern HudInfoEntry D_80123880[48];
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) temp_a2;
    HudInfoEntry *temp_v1;

    temp_v1 = &D_80123880[arg0];
    temp_a2 = temp_v1->handle;
    if ((temp_a2 == 0) || (arg1 != (temp_v1->type))) {
        return 0;
    }
    return (temp_v1->state) == 2 &&
        _scinfobar_entrypoint_22(temp_a2) != 0;
}

s32 func_800FA8E8(s32 arg0, s32 arg1) {
    extern HudInfoEntry D_80123880[48];
    HudInfoEntry *temp_v1;

    temp_v1 = &D_80123880[arg0];
    if ((temp_v1->handle == 0) || (arg1 != temp_v1->type)) {
        return -1;
    }
    return (temp_v1->state) != 0;
}    typedef struct { u8 pad0[0xC]; u8 unkC; u8 padD[0x1]; s8 unkE; } Obj1ED3900_func_800FA934_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

int func_800FA934(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_21(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32));
    extern HudInfoEntry D_80123880[48];
    BT_LP64_ONLY(void *) BT_ILP32_ONLY(s32) BT_IDO_ONLY(s32) temp_a2;
    HudInfoEntry *temp_v1;

    temp_v1 = &D_80123880[arg0];
    temp_a2 = temp_v1->handle;
    if ((temp_a2 == 0) || (arg1 != (temp_v1->type))) {
        return -1;
    }
    return (temp_v1->state) == 2 &&
        _scinfobar_entrypoint_21(temp_a2) != 0;
}

void func_800FA9A8(s32 arg0) {
    extern u8 D_801357B0;
    D_801357B0 = arg0;
}

void func_800FA9B4(s32 arg0, s32 arg1) {
    void _scinfobar_entrypoint_9(u32 *arg0, s32 arg1);
    BT_IDO_ONLY(extern s32 D_80123898[][7];)
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) temp_a2;

    temp_a2 = BT_DATA_FIELD(D_80123880[arg0].handle, D_80123898[arg0][0]);
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_9(temp_a2, arg1);
    }
}

void func_800FA9F4(s32 arg0, s32 arg1) {
    void _scinfobar_entrypoint_4(s32 *arg0, s32 arg1);
    BT_IDO_ONLY(extern s32 D_80123898[][7];)
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) temp_a2;

    temp_a2 = BT_DATA_FIELD(D_80123880[arg0].handle, D_80123898[arg0][0]);
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_4(temp_a2, arg1);
    }
}

void func_800FAA34(s32 arg0) {
    void _scinfobar_entrypoint_5(s8 *arg0, s32 arg1);
    BT_IDO_ONLY(extern s32 D_80123898[][7];)
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) temp_a2;

    temp_a2 = BT_DATA_FIELD(D_80123880[arg0].handle, D_80123898[arg0][0]);
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 1);
    }
}

void func_800FAA74(s32 arg0) {
    void _scinfobar_entrypoint_5(s8 *arg0, s32 arg1);
    BT_IDO_ONLY(extern s32 D_80123898[][7];)
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(BtIntPtr) temp_a2;

    temp_a2 = BT_DATA_FIELD(D_80123880[arg0].handle, D_80123898[arg0][0]);
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 2);
    }
}    typedef struct { u8 pad0[0x14]; f32 unk14; } Obj1ED3900_func_800FAAB4_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */

s32 func_800FAAB4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_7(void *arg0, s32 arg1);
    void _scinfobar_entrypoint_6(BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(s32), s32);
    extern HudInfoEntry D_80123880[48];
    HudInfoEntry *temp_s0;

    temp_s0 = &D_80123880[arg0];
    if (temp_s0->handle == 0) {
        return 0;
    }
    temp_s0->type = arg1;
    func_800FA240(arg0, 1);
    if (_scinfobar_entrypoint_7(temp_s0->handle, arg1) == 0) {
        return 0;
    }
    temp_s0->timer = 2.0f;
    _scinfobar_entrypoint_6(temp_s0->handle, 0);
    temp_s0->flag11 = 1;
    return 1;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_801357B0 BT_DATA(4, bss_core2bss2_2, 0x2910);
#endif
