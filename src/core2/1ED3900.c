#include "core2/1ED3900.h"

void func_800FA010(void) {
    extern s32 D_80123880[][7];
    extern s32 D_80123DC0;
    extern u8 D_801357B0;
    s8 *entry;
    s32 (*item)[7];
    u32 i;
    f32 total = 0.0f;

    i = 0;
clear_entries:
    {
        ((s8 *)D_80123880[i])[0x10] = 0;
        i++;
        if (i < 48U) goto clear_entries;
    }
    entry = (s8 *)&D_80123DC0;
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
        ((s8 *)D_80123880[i])[0xA] = (*(u8 *)((s8 *)D_80123880[i] + 4) & 1) ? 0 : 1 - *(u8 *)((s8 *)D_80123880[i] + 4);
        ((s8 *)D_80123880[i])[0xB] = (*(u8 *)((s8 *)D_80123880[i] + 4) & 1) ? *(u8 *)((s8 *)D_80123880[i] + 4) - 2 : 0;
        ((s8 *)D_80123880[i])[0xC] = 0;
        ((s8 *)D_80123880[i])[0x11] = 0;
        ((s8 *)D_80123880[i])[0x12] = 0;
        *(s16 *)((s8 *)D_80123880[i] + 6) = *(s16 *)D_80123880[i] - ((s8 *)D_80123880[i])[0xA] * total;
        *(s16 *)((s8 *)D_80123880[i] + 8) = *(s16 *)((s8 *)D_80123880[i] + 2) - ((s8 *)D_80123880[i])[0xB] * total;
        i++;
        if (i != 48U) goto init_entries;
    }
    D_801357B0 = 1;
}

void func_800FA130(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_0(s32, s32, s32);
    s32 _scinfobar_entrypoint_1(s32);
    void _scinfobar_entrypoint_6(s32, s32);
    extern s32 D_80123880[][7];

    if (arg1 != *(u8 *)((s8 *)D_80123880[arg0] + 0xC)) {
        *(u8 *)((s8 *)D_80123880[arg0] + 0xC) = arg1;
        switch (arg1) {
        case 1:
            if (D_80123880[arg0][6] == 0) {
                D_80123880[arg0][6] = _scinfobar_entrypoint_0(((s8 *)D_80123880[arg0])[0xE], *(u8 *)((s8 *)D_80123880[arg0] + 5), *(u8 *)((s8 *)D_80123880[arg0] + 0x12));
            }
            break;
        case 2:
            if (*(s16 *)((s8 *)D_80123880[arg0] + 6) != *(s16 *)D_80123880[arg0] || *(s16 *)((s8 *)D_80123880[arg0] + 8) != *(s16 *)((s8 *)D_80123880[arg0] + 2)) {
                *(s16 *)((s8 *)D_80123880[arg0] + 6) = *(s16 *)D_80123880[arg0];
                *(s16 *)((s8 *)D_80123880[arg0] + 8) = *(s16 *)((s8 *)D_80123880[arg0] + 2);
            }
            if (*(u8 *)((s8 *)D_80123880[arg0] + 0x11) == 0) {
                _scinfobar_entrypoint_6(D_80123880[arg0][6], 1);
            }
            break;
        case 3:
            _scinfobar_entrypoint_6(D_80123880[arg0][6], 0);
            break;
        case 0:
            if (D_80123880[arg0][6] != 0) {
                _scinfobar_entrypoint_1(D_80123880[arg0][6]);
                D_80123880[arg0][6] = 0;
            }
            break;
        }
    }
}

void func_800FA240(s32 arg0, s32 arg1) {
    extern s32 D_80123880[][7];
    s8 *entry;

    entry = (s8 *)D_80123880[arg0];
    entry[0x10] = arg1;
    switch (arg1) {
    case 0:
        if (*(u8 *)(entry + 0xC) != 0) {
            func_800FA130(arg0, 3);
        }
        break;
    case 1:
        if (*(u8 *)(entry + 0xC) != 2) {
            func_800FA130(arg0, 1);
        }
        break;
    }
}

void func_800FA2C0(void) {
    extern s32 D_80123880[][7];
    extern s32 D_80123DC0;
    f32 func_800D8FF8(void);
    int func_800FA874(s32, s32);
    void _scinfobar_entrypoint_2(s32);
    s32 _scinfobar_entrypoint_21(s32);
    void _scinfobar_entrypoint_6(s32, s32);
    f32 dt[2];
    struct InfoEntry {
        s16 unk0[3];
        s16 x, y;
        s8 dx, dy;
        u8 state;
        s8 frame, type, unkF;
        u8 flag, flag11;
        s16 unk12;
        f32 timer;
        s32 handle;
    } *entry;
    s32 i;
    s8 step;
    s8 (*table)[10];

    dt[0] = func_800D8FF8();
    for (i = 0; i < 0x30; i++) {
        entry = (struct InfoEntry *)D_80123880[i];
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
    table = (s8 (*)[10])&D_80123DC0;
    for (i = 0; i < 0x30; i++) {
        entry = (struct InfoEntry *)D_80123880[i];
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
}

void func_800FA508(s32 arg0) {
    s32 _scinfobar_entrypoint_24(s32, s32, s16, s16);
    s32 func_800A9C98(void);
    int func_800DB9B0(void);
    extern s32 D_80123880[][7];
    extern s32 D_80123998;
    extern s32 D_801239B4;
    extern s32 D_80123D6C;
    extern s32 D_80123DC0;
    extern u8 D_801357B0;
    s32 (*var_s0)[7];
    s32 temp_a1;
    int var_v1;
    int var_v1_2;

    if (D_801357B0 != 0) {
        var_v1 = func_800A9C98() != 0 || func_800DB9B0() != 0;
        var_s0 = D_80123880; do { temp_a1 = var_s0[0][6];
            if (temp_a1 != 0) {
                var_v1_2 = (s32) var_s0 != (s32) &D_801239B4 && (s32) var_s0 != (s32) &D_80123998 && (s32) var_s0 != (s32) &D_80123D6C;
                if ((var_v1 == 0) || (var_v1_2 == 0)) {
                    _scinfobar_entrypoint_24(arg0, temp_a1, *(s16 *)((s8 *)var_s0 + 6), *(s16 *)((s8 *)var_s0 + 8));
                }
            }
            var_s0++;
        } while (var_s0 != (s32 (*)[7]) &D_80123DC0);
    }
}

void func_800FA608(void)
{
  s32 defrag(s32);
  extern s32 D_80123880[][7];
  extern s32 D_80123DC0;
  s32 new_var;
  s32 (*var_s0)[7];
  s32 temp_a0;
 var_s0 = D_80123880; do { temp_a0 = var_s0[0][6];
    if (temp_a0 != 0)
    {
      new_var = defrag(temp_a0);
      var_s0[0][6] = new_var;
    }
    var_s0++;
  }
  while (var_s0 != ((s32 (*)[7]) (&D_80123DC0)));
}

void func_800FA660(void)
{
  s32 _scinfobar_entrypoint_1(s32);
  extern s32 D_80123DC0;
  extern s32 D_80123880[][7];
  s32 (*var_s0)[7];
  s32 temp_a0;
 var_s0 = D_80123880; do {
    temp_a0 = var_s0[0][6];
    if (temp_a0 != 0)
    {
      _scinfobar_entrypoint_1(temp_a0);
      var_s0[0][6] = 0;
    }
    var_s0++;
  }
  while (var_s0 != ((s32 (*)[7]) (&D_80123DC0)));
}

void func_800FA6B8(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_80123880[][7];
    if (arg1) {
        arg0 = arg0;
    }
    _scinfobar_entrypoint_3(D_80123880[arg0][6]);
    _scinfobar_entrypoint_8(D_80123880[arg0][6], arg2);
}

s32 func_800FA708(u32 arg0, s32 arg1, s32 arg2, u32 arg3)
{
  void _scinfobar_entrypoint_6(s32, s32);
  s32 _scinfobar_entrypoint_16(s32);
  s32 _scinfobar_entrypoint_22(s32);
  s32 _scinfobar_entrypoint_23(s32);
  s32 _scinfobar_entrypoint_7(s32, s32);
  extern s32 D_80123880[][7];
  s32 *entry;
  s32 handle;
  s32 state;
  u32 mode;
  entry = D_80123880[arg1];
  if ((arg2 != (*(((s8 *) D_80123880[arg1]) + 0xE))) || (arg3 != (*(((u8 *) D_80123880[arg1]) + 0x12))))
  {
    handle = entry[6];
    if ((handle != 0) && (_scinfobar_entrypoint_23(handle) != 0))
    {
      return 0;
    }
    handle = entry[6];
    if ((handle != 0) && (_scinfobar_entrypoint_7(handle, arg2) == 0))
    {
      return 0;
    }
  }
  state = arg2;
  mode = arg3;
  *(((s8 *) D_80123880[arg1]) + 0xE) = state;
  *(((s8 *) D_80123880[arg1]) + 0x11) = 0;
  *(((u8 *) D_80123880[arg1]) + 0x12) = mode;
  func_800FA240(arg1, 1);
  *(((f32 *) D_80123880[arg1]) + 5) = 2.0f;
  if ((_scinfobar_entrypoint_16(D_80123880[arg1][6]) != arg2) && (_scinfobar_entrypoint_22(D_80123880[arg1][6]) != 0))
  {
    _scinfobar_entrypoint_6(D_80123880[arg1][6], 0);
  }
  func_800FA6B8(arg1, arg3, arg0);
  return 1;
}

s32 func_800FA818(s32 arg0, s32 arg1) {
    void func_800FA240(s32, s32);
    extern s32 D_80123880[][7];
    if ((D_80123880[arg0][6] == 0) || (arg1 != *((s8 *)D_80123880[arg0] + 0xE))) {
        return 0;
    }
    func_800FA240(arg0, 0);
    return 1;
}

int func_800FA874(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_22(s32);
    extern s32 D_80123880[][7];
    s32 temp_a2;
    s32 *temp_v1;

    temp_v1 = D_80123880[arg0];
    temp_a2 = temp_v1[6];
    if ((temp_a2 == 0) || (arg1 != (*(s8 *)((s8 *)(temp_v1) + (0xE))))) {
        return 0;
    }
    return (*(u8 *)((s8 *)(temp_v1) + (0xC))) == 2 &&
        _scinfobar_entrypoint_22(temp_a2) != 0;
}

s32 func_800FA8E8(s32 arg0, s32 arg1) {
    extern s32 D_80123880[][7];
    s32 *temp_v1;

    temp_v1 = D_80123880[arg0];
    if ((temp_v1[6] == 0) || (arg1 != *((s8 *)temp_v1 + 0xE))) {
        return -1;
    }
    return (*((u8 *)temp_v1 + 0xC)) != 0;
}

int func_800FA934(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_21(s32);
    extern s32 D_80123880[][7];
    s32 temp_a2;
    s32 *temp_v1;

    temp_v1 = D_80123880[arg0];
    temp_a2 = temp_v1[6];
    if ((temp_a2 == 0) || (arg1 != (*(s8 *)((s8 *)(temp_v1) + (0xE))))) {
        return -1;
    }
    return (*(u8 *)((s8 *)(temp_v1) + (0xC))) == 2 &&
        _scinfobar_entrypoint_21(temp_a2) != 0;
}

void func_800FA9A8(s32 arg0) {
    extern u8 D_801357B0;
    D_801357B0 = arg0;
}

void func_800FA9B4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_9(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_9(temp_a2, arg1);
    }
}

void func_800FA9F4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_4(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_4(temp_a2, arg1);
    }
}

void func_800FAA34(s32 arg0) {
    s32 _scinfobar_entrypoint_5(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 1);
    }
}

void func_800FAA74(s32 arg0) {
    s32 _scinfobar_entrypoint_5(s32, s32);
    extern s32 D_80123898[][7];
    s32 temp_a2;

    temp_a2 = D_80123898[arg0][0];
    if (temp_a2 != 0) {
        _scinfobar_entrypoint_5(temp_a2, 2);
    }
}

s32 func_800FAAB4(s32 arg0, s32 arg1) {
    s32 _scinfobar_entrypoint_7(s32, s32);
    void _scinfobar_entrypoint_6(s32, s32);
    extern s32 D_80123880[][7];
    s32 *temp_s0;

    temp_s0 = D_80123880[arg0];
    if (temp_s0[6] == 0) {
        return 0;
    }
    ((s8 *)temp_s0)[0xE] = arg1;
    func_800FA240(arg0, 1);
    if (_scinfobar_entrypoint_7(temp_s0[6], arg1) == 0) {
        return 0;
    }
    *(f32 *)((s8 *)temp_s0 + 0x14) = 2.0f;
    _scinfobar_entrypoint_6(temp_s0[6], 0);
    ((s8 *)temp_s0)[0x11] = 1;
    return 1;
}
