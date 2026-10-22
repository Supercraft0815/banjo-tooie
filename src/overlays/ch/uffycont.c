#include "common.h"

void func_80800000_chchuffycont(Actor *arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_6(u8 *, s32);
    void _gcnewoption_entrypoint_4(Actor *, u32, u32 *, u32, s32);
    s32 _gcnewoption_entrypoint_8(s32, s32);
    s32 _gcnewoption_entrypoint_9(s32, s32);
    s32 _gcnewoption_entrypoint_10(s32, s32);
    s32 _gcnewoption_entrypoint_11(s32);
    s32 _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    s32 _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
    void _gcnewoption_entrypoint_42(void *, f32);
    void func_80090708(s32);
    s32 func_80100094(s32, s32);
    void func_80102424(Actor *, s32);
    u32 func_8010A828(Actor *, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_8080046C_chchuffycont(s32, s32);
    s32 func_8080070C_chchuffycont(s32);
    extern s32 _gcnewoption_entrypoint_35;
    s32 count;
    s32 option;

    if (arg0->unk70_10 == 5) {
        _gcnewoption_entrypoint_6((u8 *)arg0, 1);
        func_80090708(0);
        func_8010A828(arg0, 2);
    }
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
        case 2:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xF96, 0xE, arg0->position, 0x42);
            break;
        case 3:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xD80, 0xE, arg0->position, 0x42);
            break;
        case 6:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12C5, 0xE, arg0->position, 0x42);
            break;
        case 5:
            count = func_8080070C_chchuffycont((s32)arg0);
            _gcnewoption_entrypoint_4(arg0, 1, (u32 *)&_gcnewoption_entrypoint_35, 0, 0x184B);
            option = func_80100094((s32)arg0, 1);
            func_80090708(2);
            _gcnewoption_entrypoint_8(option, count >= 6 ? 5 : count);
            _gcnewoption_entrypoint_9(option, count);
            _gcnewoption_entrypoint_10(option, 0);
            func_8080046C_chchuffycont((s32)arg0, (s32)option);
            _gcnewoption_entrypoint_14(option, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_40(option, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_42((void *)option, 0.1f);
            _gcnewoption_entrypoint_11(option);
            func_8010A828(arg0, 10);
            break;
    }
}

s32 func_808001F8_chchuffycont(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80101080(void);
    void func_80800000_chchuffycont(Actor *, s32);
    void func_80800494_chchuffycont(s32, s32);
    void func_80800620_chchuffycont(Actor *, s32);
    void *temp_a1;

    switch (arg1) {
        case 0x91:
            arg0->unk64_19 = 1;
            break;
        case 0x20:
            temp_a1 = func_80101080();
            switch (*((s16 *)&arg2 + 1)) {
                case 3:
                    func_80800620_chchuffycont(arg0, *(s16 *)&arg2);
                    func_80800000_chchuffycont(arg0, 1);
                    break;
                case 0:
                    func_80800494_chchuffycont((s32)arg0, (s32)temp_a1);
                    break;
                case 2:
                    func_80800000_chchuffycont(arg0, 1);
                    break;
            }
            break;
        case 0x2E:
            func_80800000_chchuffycont(arg0, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808002C4_chchuffycont(Actor *arg0) {
    void _gcnewoption_entrypoint_0(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_80100094();
    s32 func_8010CAC0(f32 *, u32);
    s32 func_8080070C_chchuffycont(s32);
    void func_80800A7C_chchuffycont(Actor *);
    u32 flag;
    u32 state;

    func_80800A7C_chchuffycont(arg0);
    state = arg0->unk70_10;
    switch (state) {
    case 1:
        if (!func_800DA298(0x66D) && !func_800DA298(0x86) && func_8010CAC0(arg0->position, 250)) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xFAC, 0xE, NULL, 0x42);
            func_800DA544(0x66D);
        }
        if (arg0->unk64_19 && _subaddiedialog_entrypoint_4(arg0->position, 100, 0)) {
            if (!func_800DA298(0x86)) {
                arg0->unk74_30 = 0;
                func_80800000_chchuffycont(arg0, 2);
            } else if (func_8080070C_chchuffycont((s32)arg0) <= 0) {
                arg0->unk74_30 = 0;
                func_80800000_chchuffycont(arg0, 3);
                flag = arg0->unk64_19;
                goto done;
            } else {
                func_80800000_chchuffycont(arg0, 5);
            }
        }
        flag = arg0->unk64_19;
        break;
    case 5:
        _gcnewoption_entrypoint_0(func_80100094(arg0, 1));
        flag = arg0->unk64_19;
        break;
    default:
        flag = arg0->unk64_19;
        break;
    }
done:
    if (flag) {
        arg0->unk64_19 = 0;
    }
}

void func_80800440_chchuffycont(Actor *arg0) {
    u32 func_8010A828(Actor*, u32);
    arg0->scale = 0.5f;
    func_8010A828(arg0, 2U);
}

/* extern */

void func_8080046C_chchuffycont(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_32(s32, s32);
    _gcnewoption_entrypoint_32(arg1, 66);
}

void func_80800494_chchuffycont(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    int func_808006A4_chchuffycont(s32);
    extern s16 D_80800B20_chchuffycont;
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        if (func_808006A4_chchuffycont(var_s0) != 0) {
            _gcnewoption_entrypoint_12(arg1, var_s1, (s16) (var_s0 + 0xA));
            _gcnewoption_entrypoint_31(arg1, var_s1, ((s16 *)((u8 *)&D_80800B20_chchuffycont + var_s0 * 10))[4]);
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != 7);
}

void func_80800540_chchuffycont(Actor *arg0, s32 arg1) {
    void _glcutDll_entrypoint_0(void);
    void _glcutDll_entrypoint_7(u32);
    void _glcutDll_entrypoint_10(u32);
    void _glcutDll_entrypoint_22(u32);
    void _glcutDll_entrypoint_16(void);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_80800000_chchuffycont(Actor *, s32);
    extern s16 D_80800B20_chchuffycont;
    extern s16 D_80800B66_chchuffycont;
    s16 *entry;

    entry = (s16 *)((u8 *)&D_80800B20_chchuffycont + arg1 * 10);
    if (entry[0] == 0x12A && func_800DA298(0x171) == 0) {
        func_80800000_chchuffycont(arg0, 6);
        return;
    }
    func_800DA544(entry[2]); entry = &D_80800B20_chchuffycont; loop: if (func_800DA298(entry[1]) == 0) { entry += 5; if (entry != &D_80800B66_chchuffycont) { goto loop; } } if (*entry == 0xEC) { func_800DA544(0x6E7); } _glcutDll_entrypoint_0(); _glcutDll_entrypoint_7(*entry); _glcutDll_entrypoint_10(0xD0); _glcutDll_entrypoint_22(0x6F); _glcutDll_entrypoint_16();
}

/* extern */

void func_80800620_chchuffycont(Actor *arg0, s32 arg1) {
    void func_80800540_chchuffycont(Actor *, s32);
    int func_808006A4_chchuffycont(s32);
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        if (func_808006A4_chchuffycont(var_s0) != 0) {
            if (var_s1 == arg1) {
                func_80800540_chchuffycont(arg0, var_s0);
                return;
            }
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != 7);
}

int func_808006A4_chchuffycont(s32 arg0) {
  extern s16 D_80800B20_chchuffycont;
  s32 func_800DA298(s32);
    return (!(*(s16 *)((u8 *)&D_80800B20_chchuffycont + arg0 * 10 + 6) + 1)
        || func_800DA298(*(s16 *)((u8 *)&D_80800B20_chchuffycont + arg0 * 10 + 6)))
        && !func_800DA298(*(s16 *)((u8 *)&D_80800B20_chchuffycont + arg0 * 10 + 2));
}

s32 func_8080070C_chchuffycont(s32 arg0) {
    int func_808006A4_chchuffycont(s32);
    int i;
    int count = 0;
    for (i = 0; i < 7; i++) {
        if (func_808006A4_chchuffycont(i)) count++;
    }
    return count;
}

/* extern */

void func_80800768_chchuffycont(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_1(s32, s32);
    s32 func_800EB854();
    s32 func_80100094(s32, s32);
    s32 func_80101870(s32, s32);
    s32 temp_v0;

    if (func_800EB854() == 3) {
        temp_v0 = func_80100094(arg0, 1);
        if (temp_v0 != 0) {
            _gcnewoption_entrypoint_1(temp_v0, arg1);
        }
    } else {
        func_80101870(arg0, arg1);
    }
}

s32 chchuffycont_entrypoint_0(s32 *arg0, s32 *arg1)
{
  s32 _gcsectionDll_entrypoint_4(s32);
  void func_800A7A5C(void);
  void func_800A8230(void);
  s32 func_800DA298(s32);
  void func_800DA3B8(s32, s32);
  s32 func_800EA05C(void);
  extern u8 D_8012762C;
  extern s16 D_80800B20_chchuffycont;
  extern s16 D_80800B66_chchuffycont;
  register s16 *end;
  s16 *first_end;
  s16 *var_s0;
  s16 *var_v1;
  s32 temp_s0;
  s32 temp_v0;
  if (func_800EA05C() == 0xD0)
  {
    var_s0 = &D_80800B20_chchuffycont;
    first_end = &D_80800B66_chchuffycont;
    do
    {
      if (func_800DA298(var_s0[1]) != 0)
      {
        break;
      }
      var_s0 += 5;
    }
    while (var_s0 != first_end);
    *arg0 = *var_s0;
    *arg1 = 2;
    if (func_800DA298(0x66B) != 0)
    {
      func_800A7A5C();
    }
    else
    {
      temp_s0 = _gcsectionDll_entrypoint_4(*arg0);
      if (_gcsectionDll_entrypoint_4(0xD0) != temp_s0)
      {
        func_800A8230();
      }
    }
    func_800DA3B8(0x66B, 0);
 return 1; } temp_v0 = func_800EA05C(); var_v1 = &D_80800B20_chchuffycont; end = &D_80800B66_chchuffycont; do { if (temp_v0 == (*var_v1)) { break; }
    var_v1 += 5;
  }
  while (var_v1 != end);
  if (func_800DA298(var_v1[1]) != 0)
  {
    *arg0 = 0xD0;
    *arg1 = 1;
    if (_gcsectionDll_entrypoint_4(0xD0) != D_8012762C)
    {
      func_800A8230();
    }
    return 1;
  }
  return 0;
}

s32 chchuffycont_entrypoint_1(s32 *arg0, s32 *arg1) {
    s32 _gcsectionDll_entrypoint_4(s32);
    void func_800A8230(void);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    extern u8 D_8012762C;
    extern s16 D_80800B20_chchuffycont;
    extern s16 D_80800B66_chchuffycont;
    s16 *ptr;
    s16 *end;
    s16 *scan;
    s16 *scan_end;
    s32 section;
    s32 map;
    s32 result;

    map = func_800EA05C();
    result = 0;
    if (map == 0x121) {
        if (func_800DA298(0x95) == 0) {
            *arg0 = 0xD7;
            *arg1 = 3;
        } else {
            ptr = &D_80800B20_chchuffycont; end = &D_80800B66_chchuffycont; do { if (func_800DA298(ptr[1]) != 0) {
                    break;
                }
                ptr += 5;
            } while (ptr != end);
            *arg0 = *ptr;
            *arg1 = 3;
        }
        section = _gcsectionDll_entrypoint_4(*arg0);
        if (_gcsectionDll_entrypoint_4(0x121) != section) {
            func_800A8230();
        }
        result = 1;
    } else {
        scan = &D_80800B20_chchuffycont; scan_end = &D_80800B66_chchuffycont; do { if (map == *scan) {
                break;
            }
            scan += 5;
        } while (scan != scan_end);
        if (func_800DA298(scan[1]) != 0 ||
            (map == 0xD7 && func_800DA298(0x95) == 0)) {
            *arg0 = 0x121;
            result = 1;
            *arg1 = 1;
            if (_gcsectionDll_entrypoint_4(0x121) != D_8012762C) {
                func_800A8230();
            }
        }
    }
    return result;
}

void func_80800A7C_chchuffycont(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_80800B68_chchuffycont;
    extern f32 D_80800B78_chchuffycont;
    _subaddieaudioloop_entrypoint_4(arg0, &D_80800B78_chchuffycont, 1U, &D_80800B68_chchuffycont);
}

OSThread *chchuffycont_entrypoint_2(void)
{
    extern u8 D_80800B84_chchuffycont[];

    return (OSThread *) D_80800B84_chchuffycont;
}

void chchuffycont_entrypoint_3(void)
{
  extern s16 D_80800B20_chchuffycont;
  extern s16 D_80800B66_chchuffycont;
  s32 _gcsectionDll_entrypoint_4(s32);
  s32 func_800DA298(s32);
  s16 *var_s0;
  s16 *var_s1;
 var_s0 = &D_80800B20_chchuffycont; var_s1 = &D_80800B66_chchuffycont; loop_1: if (func_800DA298(var_s0[1]) == 0) { var_s0 += 5; if (var_s0 != var_s1) { goto loop_1; }
  }

  _gcsectionDll_entrypoint_4(*var_s0);
}
