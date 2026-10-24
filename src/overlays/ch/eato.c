#include "common.h"

OSThread *chcheato_entrypoint_0(void)
{
    extern u8 D_80800E98_chcheato[];

    return (OSThread *) D_80800E98_chcheato;
}

/* extern */

void func_8080000C_chcheato(Actor *arg0) {
    void _subaddieitem_entrypoint_0(s32, u32, s32, s32);
    void *func_80100094(Actor *, u32);
    u32 func_8010A828(Actor*, u32);
    s32 _subaddieitem_entrypoint_1(s32, s32);
    _subaddieitem_entrypoint_0(func_80100094(arg0, 1), 0x4E3U, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 1), 5);
    func_8010A828(arg0, 9U);
}

void func_80102424(Actor *, s32);

void func_80800068_chcheato(Actor *arg0) {
    s32 _gcnewoption_entrypoint_0(s32);
    s32 _gcnewoption_entrypoint_6(u8 *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    void func_80090708(s32);
    s32 func_800C0638(void);
    void func_800D1824(s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102B2C(Actor *, f32);
    void func_80103DFC(Actor *, f32 *);
    f32 func_8010CD28(Actor *);
    s32 func_8010D23C(void);
    void func_808003C4_chcheato(Actor *);
    void func_808006B8_chcheato(Actor *);
    void func_8080078C_chcheato(Actor *);
    void func_80800B00_chcheato(Actor *);
    void func_80800CC0_chcheato(void *);
    void func_80800D08_chcheato(Actor *, s32, s32);
    f32 sp34[3];

    _sudeflect_entrypoint_0(arg0->position, 150.0f, 150.0f, 10);
    func_808006B8_chcheato(arg0);
    func_8080078C_chcheato(arg0);
    func_800D1824(0x4A);
    switch (arg0->unk70_10) {
    case 1:
        if (!arg0->unk64_19 && func_8010D23C()) {
            arg0->unk54 = func_8010CD28(arg0);
            func_80102B2C(arg0, 4.0f);
            func_808003C4_chcheato(arg0);
        }
        break;
    case 3:
        func_80103DFC(arg0, sp34);
        if (_subaddieitem_entrypoint_3(arg0, sp34, func_80100094(arg0, 1))) {
            func_80102424(arg0, 2);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x115D, 0xE, arg0->position, 0x37);
        }
        break;
    case 4:
        if (!func_800C0638()) {
            func_80800D08_chcheato(arg0, 2, 1);
            func_80800B00_chcheato(arg0);
        }
        break;
    case 5:
        _gcnewoption_entrypoint_0(func_80100094(arg0, 0));
        break;
    case 6:
        _gcnewoption_entrypoint_6(arg0, 0);
        func_80090708(0);
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        break;
    }
}

s32 func_80800204_chcheato(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800434_chcheato(Actor *, s32, s32);
    void func_80800AB4_chcheato(s32, s32, s32, s32);
    s32 func_80800C64_chcheato(void *, s32, s32);
    void *func_80101080(void);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    extern u32 D_80800E50_chcheato;

    switch (arg1) {
    case 0x2E:
        func_80800434_chcheato(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x49:
        if (arg2 == 1) {
            arg0->unk64_19 = 1;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1143, 4, arg0->position, 0x37);
            _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x830);
        }
        break;
    case 0x20:
        func_80800AB4_chcheato((s32)arg0, (s32)func_80101080(), ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80800E50_chcheato, arg0->scale);
        break;
    case 0x95:
        arg0->unk64_20 = 0;
        break;
    case 0x57:
        return func_80800C64_chcheato(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    default:
        return 0;
    }
    return 1;
}

void func_8080035C_chcheato(void *arg0, s32 arg1)
{
  s32 _gcnewoption_entrypoint_1(s32, s32);
  s32 func_800EB854();
    void *func_80100094(Actor *, u32);
  s32 func_80101870(void *, s32);
  if (func_800EB854() == 3)
  {
    if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFFu) >> 0xA) == 5)
    {
      _gcnewoption_entrypoint_1(func_80100094(arg0, 0), arg1);
    }
  }
  else
  {
    func_80101870(arg0, arg1);
  }
}

void func_808003C4_chcheato(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_7(Actor *, f32 *, s32 *);
    int func_80800824_chcheato(s32 *);
    void func_80800D08_chcheato(Actor *, s32, s32);
    extern s32 D_80800EE0_chcheato;
    extern s16 D_80800EE6_chcheato;
    extern s16 D_80800EF4_chcheato;
    s32 sp1C;
    s32 temp_v0;

    sp1C = 0xE;
    D_80800EE6_chcheato = func_80800824_chcheato(&sp1C);
    D_80800EF4_chcheato = sp1C;
    temp_v0 = _subaddiedialog_entrypoint_7(arg0, arg0->position, &D_80800EE0_chcheato);
    if ((temp_v0 != 0) && (temp_v0 != 0x1208)) {
        func_80800D08_chcheato(arg0, 3, 0);
    }
}

/* extern */

void func_80800434_chcheato(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor *, s32);
    int func_80800824_chcheato(s32 *arg0);
    s32 func_80800888_chcheato(void);
    s32 func_80800BB8_chcheato(void);
    s32 func_80800C0C_chcheato(void);
    void func_80800CC0_chcheato(void *arg0);
    s32 _capod_entrypoint_14();
    s32 _glcutDll_entrypoint_17();
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddieitem_entrypoint_2(s32);
    s32 func_800C01A8(s32, s32);
    s32 func_800C0850();
    s32 func_800D1A04(s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void * func_80100094(Actor *, u32);
    s32 sp2C;

    switch (arg1) {
    case 0x1144:
        _subaddieitem_entrypoint_2(func_80100094(arg0, 1));
        func_80102424(arg0, 3);
        return;
    case 0x115D:
        _subaddiedialog_entrypoint_11(arg0->unk0, func_80800888_chcheato(), 0xE, arg0->position, 0x37);
        return;
    case 0x1142:
        if (func_800D1A04(0x4A) != 0) {
            sp2C = 0xE;
            _subaddiedialog_entrypoint_11(arg0->unk0, func_80800824_chcheato(&sp2C), sp2C, arg0->position, 0x37);
            return;
        }
        func_800C01A8(0x64, 0);
        func_800C0850();
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    case 0x1145:
        if (func_80800C0C_chcheato() != 0) {
            func_80102424(arg0, 4);
            return;
        }
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    case 0x1147:
        func_80102424(arg0, 4);
        return;
    case 0x1148:
        func_800DA544(0x69);
        if (func_80800C0C_chcheato() != 0) {
            func_80102424(arg0, 4);
            return;
        }
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    case 0x114B:
    case 0x114C:
    case 0x114D:
    case 0x114E:
    case 0x114F:
        if ((func_800D1A04(0x4A) >= 5) && (func_80800BB8_chcheato() != -1)) {
            _subaddieitem_entrypoint_2(func_80100094(arg0, 1));
            func_80102424(arg0, 3);
            return;
        }
        if (func_800DA298(0x69) == 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1148, 0xE, arg0->position, 0x37);
            return;
        }
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x115E, 0xE, arg0->position, 0x37);
        return;
    case 0x1143:
        _capod_entrypoint_14();
        _glcutDll_entrypoint_17();
        return;
    case 0x115E:
        func_80102424(arg0, 4);
        return;
    default:
        func_80102424(arg0, 1);
        func_80800CC0_chcheato(arg0);
        return;
    }
}

void func_808006B8_chcheato(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B7C(s32);
    s32 func_80101E14(Actor *, f32);
    struct CheatoTimes { f32 values[2]; };
    struct CheatoSounds { s16 values[2]; };
    extern struct CheatoTimes D_80800EFC_chcheato;
    extern struct CheatoSounds D_80800F04_chcheato;
    extern s32 D_80800F08_chcheato;
    struct CheatoTimes times;
    struct CheatoSounds sounds;
    s32 i;

    times = D_80800EFC_chcheato;
    sounds = D_80800F04_chcheato;
    for (i = 0; i < 2; i++) {
        if (func_80101E14(arg0, times.values[i]) != 0) {
            func_800C4B7C(sounds.values[i]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800F08_chcheato);
        }
    }
}

/* extern */

void func_8080078C_chcheato(Actor *arg0) {
    void func_800FC63C(u32, u32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    s32 func_8010CAC0(f32 *, u32);
    s32 temp_v0;

    temp_v0 = func_8010CAC0(arg0->position, 0x2EE);
    if (!arg0->unk64_20) {
        if (temp_v0 != 0) {
            func_800FC63C(0x44, 0);
            func_800FCAE0(0x44, -1, 0x1F4);
            arg0->unk64_20 = 1;
        }
    } else if (temp_v0 == 0) {
        func_800FCAE0(0x44, 0, 0x1F4);
        func_800FCA90(0x44);
        arg0->unk64_20 = 0;
    }
}

int func_80800824_chcheato(s32 *arg0) {
    s32 func_800D1A04(s32);
    s32 func_80800BB8_chcheato(void);
    s32 sp1C;

    sp1C = func_800D1A04(0x4A);
    if (func_80800BB8_chcheato() == -1) {
        return 0x1147;
    }
    if (sp1C < 5) {
        *arg0 |= 1;
        return 0x1145;
    } else {
        return 0x1144;
    }
}

s32 func_80800888_chcheato(void) {
    s32 func_80800BB8_chcheato(void);
    s32 volatile sp1C;
    s32 temp_v0;

    temp_v0 = func_80800BB8_chcheato();
    sp1C = temp_v0;
    func_800D3EF4(temp_v0);
    return sp1C + 0x114A;
}

void func_808008B8_chcheato(s32 arg0, s32 arg1) {
    typedef struct {
        s16 data[3];
    } OptionColors;
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    s32 _gcnewoption_entrypoint_13(s32, s32, void *);
    s32 _gcnewoption_entrypoint_17();
    s32 _gcnewoption_entrypoint_19(s32, s32);
    extern OptionColors D_80800F20_chcheato;
    extern OptionColors D_80800F28_chcheato;
    s32 pad;
    OptionColors sp2C;
    OptionColors sp24;

    if (_gcnewoption_entrypoint_17() != 0) {
        sp2C = D_80800F20_chcheato;
        _gcnewoption_entrypoint_13(arg0, arg1, &sp2C);
        _gcnewoption_entrypoint_12(arg0, arg1, (s16) ((arg1 * 2) + 3));
        return;
    }
    if (_gcnewoption_entrypoint_19(arg0, arg1) != 0) {
        sp24 = D_80800F28_chcheato;
        _gcnewoption_entrypoint_13(arg0, arg1, &sp24);
        _gcnewoption_entrypoint_12(arg0, arg1, (s16) ((arg1 * 2) + 4));
    }
}

/* extern */

void func_8080098C_chcheato(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    s32 _gcnewoption_entrypoint_32(s32, s32);
    s32 _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
    _gcnewoption_entrypoint_14(arg1, 0, 1, 2, 4.0f);
    _gcnewoption_entrypoint_40(arg1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(arg1, 0x37);
}

/* extern */

void func_80800A04_chcheato(s32 arg0) {
    s32 _gcnewoption_entrypoint_21(s32, s32);
    void _gcnewoption_entrypoint_23(s32, s32);
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    s32 func_800D3E14(s32);
    u32 func_800D3FC0(s32);
    s32 func_80800C0C_chcheato(void);
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s0;

    temp_v0 = func_80800C0C_chcheato();
    for (var_s0 = 0; var_s0 < temp_v0; var_s0++) {
            temp_s1 = var_s0 + 1;
            if (func_800D3E14(temp_s1) != 0) {
                _gcnewoption_entrypoint_21(arg0, var_s0);
            } else {
                _gcnewoption_entrypoint_23(arg0, var_s0);
            }
            func_808008B8_chcheato(arg0, var_s0);
            _gcnewoption_entrypoint_31(arg0, var_s0, func_800D3FC0(temp_s1));
    }
}

void func_80800AB4_chcheato(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_80800A04_chcheato(s32);
    switch (arg3) {
        case 0:
            func_80800A04_chcheato(arg1);
            break;
        case 2:
            func_80102424((Actor *) arg0, 6);
            break;
    }
}

void func_80800B00_chcheato(Actor *arg0) {
    s32 _gcnewoption_entrypoint_10(s32, s32);
    s32 _gcnewoption_entrypoint_11(s32);
    void _gcnewoption_entrypoint_4(Actor *, u32, u32 *, u32, s32);
    s32 _gcnewoption_entrypoint_8(s32, s32);
    s32 _gcnewoption_entrypoint_9(s32, s32);
    void func_80090708(s32);
    s32 func_800F1418(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80800C0C_chcheato(void);
    extern u32 _gcnewoption_entrypoint_16;
    extern s32 _gcnewoption_entrypoint_35;
    s32 optionCounts[3];
    void *temp_s0;

    optionCounts[0] = func_80800C0C_chcheato();
    _gcnewoption_entrypoint_4(arg0, 0, &_gcnewoption_entrypoint_16, &_gcnewoption_entrypoint_35, 0x1849);
    temp_s0 = func_80100094(arg0, 0);
    _gcnewoption_entrypoint_8(temp_s0, func_800F1418(5, optionCounts[0]));
    _gcnewoption_entrypoint_9(temp_s0, optionCounts[0]);
    _gcnewoption_entrypoint_10(temp_s0, 1);
    func_8080098C_chcheato(arg0, temp_s0);
    _gcnewoption_entrypoint_11(temp_s0);
    func_80102424(arg0, 5);
    func_80090708(2);
}

/* extern */

s32 func_80800BB8_chcheato(void) {
    s32 func_800D3DD0(s32);
    s32 var_s0;

    var_s0 = 1;
loop_1:
    if (func_800D3DD0(var_s0) == 0) {
        return var_s0;
    }
    var_s0 += 1;
    if (var_s0 == 6) {
        return -1;
    }
    goto loop_1;
}

s32 func_80800C0C_chcheato(void) {
    s32 func_800D3DD0(s32);
    int i;
    int count = 0;
    for (i = 1; i < 6; i++) {
        if (func_800D3DD0(i)) count++;
    }
    return count;
}

/* extern */

s32 func_80800C64_chcheato(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80800D08_chcheato(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_80800D08_chcheato(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800CC0_chcheato(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

void func_80800D08_chcheato(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    void _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);
    extern u32 D_80800E50_chcheato;

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x19, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->unk6C_0 = 2;
            _gcdialogcamera_entrypoint_3(&D_80800E50_chcheato, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
    }
}
