#include "common.h"

OSThread *chcheato_entrypoint_0(void)
{
    extern u8 D_80800E98_chcheato[];

    return (OSThread *) D_80800E98_chcheato;
}

/* extern */

void func_8080000C_chcheato(Actor *arg0) {
    void _subaddieitem_entrypoint_0(s32, u32, s32, s32);
  s32 func_80100094(void *, s32);
    u32 func_8010A828(Actor*, u32);
    s32 _subaddieitem_entrypoint_1(s32, s32);
    _subaddieitem_entrypoint_0(func_80100094(arg0, 1), 0x4E3U, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 1), 5);
    func_8010A828(arg0, 9U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800068_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800204_chcheato.s")

void func_8080035C_chcheato(void *arg0, s32 arg1)
{
  s32 _gcnewoption_entrypoint_1(s32, s32);
  s32 func_800EB854();
  s32 func_80100094(void *, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_808003C4_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800434_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_808006B8_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_8080078C_chcheato.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800B00_chcheato.s")

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
