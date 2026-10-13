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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800824_chcheato.s")

s32 func_80800888_chcheato(void) {
    s32 func_80800BB8_chcheato(void);
    s32 volatile sp1C;
    s32 temp_v0;

    temp_v0 = func_80800BB8_chcheato();
    sp1C = temp_v0;
    func_800D3EF4(temp_v0);
    return sp1C + 0x114A;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_808008B8_chcheato.s")

/* extern */

void func_8080098C_chcheato(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    s32 _gcnewoption_entrypoint_32(s32, s32);
    s32 _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
    _gcnewoption_entrypoint_14(arg1, 0, 1, 2, 4.0f);
    _gcnewoption_entrypoint_40(arg1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(arg1, 0x37);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800A04_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800AB4_chcheato.s")

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
    s32 func_80800D08_chcheato(void *, s32, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800D08_chcheato.s")
