#include "common.h"
#include "uffycont_tables.h"

void func_80800000_chchuffycont(Actor *arg0, s32 arg1) {
    void _gcnewoption_entrypoint_6(Actor *arg0, volatile s16 arg1);
    void _gcnewoption_entrypoint_4(Actor *arg0, volatile s16 arg1, BtIntPtr arg2, BtIntPtr arg3, s32 arg4);
    void _gcnewoption_entrypoint_8(s16 *arg0, s32 arg1);
    void _gcnewoption_entrypoint_9(s16 *arg0, s32 arg1);
    void _gcnewoption_entrypoint_10(void *arg0, s32 arg1);
    void _gcnewoption_entrypoint_11(s16 *arg0);
    void _gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
    void _gcnewoption_entrypoint_40(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);
    void _gcnewoption_entrypoint_42(void *, f32);
    void func_80090708(s32);
    BtIntPtr func_80100094(BtIntPtr, s32);
    void func_80102424(Actor *, s32);
    void func_8010A828(void **arg0, s32 arg1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_8080046C_chchuffycont(BtIntPtr, BtIntPtr);
    s32 func_8080070C_chchuffycont(BtIntPtr);
    extern s32 _gcnewoption_entrypoint_35;
    s32 count;
    BtIntPtr option;

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
            count = func_8080070C_chchuffycont((BtIntPtr)arg0);
            _gcnewoption_entrypoint_4(arg0, 1, (u32 *)&_gcnewoption_entrypoint_35, 0, 0x184B);
            option = func_80100094((BtIntPtr)arg0, 1);
            func_80090708(2);
            _gcnewoption_entrypoint_8(option, count >= 6 ? 5 : count);
            _gcnewoption_entrypoint_9(option, count);
            _gcnewoption_entrypoint_10(option, 0);
            func_8080046C_chchuffycont((BtIntPtr)arg0, (s32)option);
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
    void func_80800494_chchuffycont(BtIntPtr, BtIntPtr);
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
                    func_80800494_chchuffycont((BtIntPtr)arg0, (BtIntPtr)temp_a1);
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
    void _gcnewoption_entrypoint_0(BtIntPtr);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    BtIntPtr func_80100094();
    s32 func_8010CAC0(f32 *, u32);
    s32 func_8080070C_chchuffycont(BtIntPtr);
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
            } else if (func_8080070C_chchuffycont((BtIntPtr)arg0) <= 0) {
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
    void func_8010A828(void **arg0, s32 arg1);
    arg0->scale = 0.5f;
    func_8010A828(arg0, 2U);
}

/* extern */

void func_8080046C_chchuffycont(BtIntPtr arg0, BtIntPtr arg1) {
    void _gcnewoption_entrypoint_32(void *arg0, s16 arg1);
    _gcnewoption_entrypoint_32(arg1, 66);
}

void func_80800494_chchuffycont(BtIntPtr arg0, BtIntPtr arg1) {
    void _gcnewoption_entrypoint_12(void *a0, u32 optionIndex, s16 textIndex);
    void _gcnewoption_entrypoint_31(BtIntPtr, s32, s16);
    int func_808006A4_chchuffycont(s32);
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 0;
    do {
        if (func_808006A4_chchuffycont(var_s0) != 0) {
            _gcnewoption_entrypoint_12(arg1, var_s1, (s16) (var_s0 + 0xA));
            _gcnewoption_entrypoint_31(arg1, var_s1, D_80800B20_chchuffycont.data.stations[var_s0].icon);
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
    void func_800DA544(s32 index);
    void func_80800000_chchuffycont(Actor *, s32);
    ChuffyStation *entry;

    entry = &D_80800B20_chchuffycont.data.stations[arg1];
    if (entry->map == 0x12A && func_800DA298(0x171) == 0) {
        func_80800000_chchuffycont(arg0, 6);
        return;
    }
    func_800DA544(entry->visitFlag);
        entry = D_80800B20_chchuffycont.scan; loop: if (func_800DA298(entry->currentFlag) == 0) {
        entry++; if (entry != CHUFFY_STATION_END) { goto loop; }
        } if (entry->map == 0xEC) { func_800DA544(0x6E7); } _glcutDll_entrypoint_0(); _glcutDll_entrypoint_7(entry->map); _glcutDll_entrypoint_10(0xD0); _glcutDll_entrypoint_22(0x6F); _glcutDll_entrypoint_16();
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
  s32 func_800DA298(s32);
    return (!(D_80800B20_chchuffycont.data.stations[arg0].prerequisite + 1)
        || func_800DA298(D_80800B20_chchuffycont.data.stations[arg0].prerequisite))
        && !func_800DA298(D_80800B20_chchuffycont.data.stations[arg0].currentFlag);
}

s32 func_8080070C_chchuffycont(BtIntPtr arg0) {
    int func_808006A4_chchuffycont(s32);
    int i;
    int count = 0;
    for (i = 0; i < 7; i++) {
        if (func_808006A4_chchuffycont(i)) count++;
    }
    return count;
}

/* extern */

void func_80800768_chchuffycont(BtIntPtr arg0, BtIntPtr arg1) {
    void _gcnewoption_entrypoint_1(u8 *arg0, BtIntPtr arg1);
    s32 func_800EB854();
    BtIntPtr func_80100094(BtIntPtr, s32);
    void func_80101870(Actor* arg0, void* arg1);
    BtIntPtr temp_v0;

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
  BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcsectionDll_entrypoint_4(s32);
  void func_800A7A5C(void);
  void func_800A8230(void);
  s32 func_800DA298(s32);
  void func_800DA3B8(s32, s32);
  s32 func_800EA05C(void);
  extern u8 D_8012762C;
  register ChuffyStation *end;
  ChuffyStation *first_end;
  ChuffyStation *var_s0;
  ChuffyStation *var_v1;
  s32 temp_s0;
  s32 temp_v0;
  if (func_800EA05C() == 0xD0)
  {
    var_s0 = D_80800B20_chchuffycont.scan;
    first_end = CHUFFY_STATION_END;
    do
    {
      if (func_800DA298(var_s0->currentFlag) != 0)
      {
        break;
      }
      var_s0++;
    }
    while (var_s0 != first_end);
    *arg0 = var_s0->map;
    *arg1 = 2;
    if (func_800DA298(0x66B) != 0)
    {
      func_800A7A5C();
    }
    else
    {
      temp_s0 = BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(*arg0);
      if (BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(0xD0) != temp_s0)
      {
        func_800A8230();
      }
    }
    func_800DA3B8(0x66B, 0);
 return 1;
        }
        temp_v0 = func_800EA05C(); var_v1 = D_80800B20_chchuffycont.scan; end = CHUFFY_STATION_END; do { if (temp_v0 == (var_v1->map)) {
        break; }
    var_v1++;
  }
  while (var_v1 != end);
  if (func_800DA298(var_v1->currentFlag) != 0)
  {
    *arg0 = 0xD0;
    *arg1 = 1;
    if (BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(0xD0) != D_8012762C)
    {
      func_800A8230();
    }
    return 1;
  }
  return 0;
}

s32 chchuffycont_entrypoint_1(s32 *arg0, s32 *arg1) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcsectionDll_entrypoint_4(s32);
    void func_800A8230(void);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    extern u8 D_8012762C;

    ChuffyStation *ptr;
    ChuffyStation *end;
    ChuffyStation *scan;
    ChuffyStation *scan_end;
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
            ptr = D_80800B20_chchuffycont.scan; end = CHUFFY_STATION_END; do { if (func_800DA298(ptr->currentFlag) != 0) {
                    break;
                }
                ptr++;
            } while (ptr != end);
            *arg0 = ptr->map;
            *arg1 = 3;
        }
        section = BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(*arg0);
        if (BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(0x121) != section) {
            func_800A8230();
        }
        result = 1;
    } else {
        scan = D_80800B20_chchuffycont.scan; scan_end = CHUFFY_STATION_END; do { if (map == scan->map) {
                break;
            }
            scan++;
        } while (scan != scan_end);
        if (func_800DA298(scan->currentFlag) != 0 ||
            (map == 0xD7 && func_800DA298(0x95) == 0)) {
            *arg0 = 0x121;
            result = 1;
            *arg1 = 1;
            if (BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(0x121) != D_8012762C) {
                func_800A8230();
            }
        }
    }
    return result;
}

void func_80800A7C_chchuffycont(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);

    extern f32 D_80800B78_chchuffycont[3];
    _subaddieaudioloop_entrypoint_4(arg0, D_80800B78_chchuffycont, 1U, (u32 *)D_80800B20_chchuffycont.data.audio);
}

OSThread *chchuffycont_entrypoint_2(void)
{
    extern ActorData D_80800B84_chchuffycont;

    return (OSThread *)&D_80800B84_chchuffycont;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) chchuffycont_entrypoint_3(void)
{
  BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcsectionDll_entrypoint_4(s32);
  s32 func_800DA298(s32);
  ChuffyStation *var_s0;
  ChuffyStation *var_s1;

 var_s0 = D_80800B20_chchuffycont.scan; var_s1 = CHUFFY_STATION_END; loop_1: if (func_800DA298(var_s0->currentFlag) == 0) {
        var_s0++; if (var_s0 != var_s1) { goto loop_1; }
  }
  BT_NATIVE_ONLY(return) BT_NATIVE_ONLY((s8)) _gcsectionDll_entrypoint_4(var_s0->map);
}
#include "uffycont_data.inc"
