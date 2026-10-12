#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800000_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_808001F8_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_808002C4_chchuffycont.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800494_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800540_chchuffycont.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/func_80800620_chchuffycont.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffycont/chchuffycont_entrypoint_1.s")

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
