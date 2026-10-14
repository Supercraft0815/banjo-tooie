#include "common.h"

OSThread *chdumbwaiterlift_entrypoint_0(void)
{
    extern u8 D_80800BE8_chdumbwaiterlift[];

    return (OSThread *) D_80800BE8_chdumbwaiterlift;
}

/* extern */

void func_8080000C_chdumbwaiterlift(s32 arg0) {
    s32 func_800EE7F8(s32, s32, s32);
    s32 func_8010A828(s32, s32);
    func_800EE7F8(arg0 + 0x28, arg0 + 4, arg0);
    func_8010A828(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800044_chdumbwaiterlift.s")

void func_80800268_chdumbwaiterlift(u8 *arg0)
{
  s32 func_800C53EC(s32, s32);
  s32 func_80100094(void *, s32);
  s32 _gcnewoption_entrypoint_6(u8 *, s32);
  if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFFu) >> 0xA) == 6)
  {
    func_800C53EC(0, 0);
  }
  if (func_80100094(arg0, 0) != 0)
  {
    _gcnewoption_entrypoint_6(arg0, 0);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_808002C0_chdumbwaiterlift.s")

void func_8080035C_chdumbwaiterlift(void *arg0, s32 arg1)
{
  s32 _gcnewoption_entrypoint_1(s32, s32);
  s32 func_800EB854();
  s32 func_80100094(void *, s32);
  s32 func_80101870(void *, s32);
  if (func_800EB854() == 3)
  {
    if (((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFFu) >> 0xA) == 4)
    {
      _gcnewoption_entrypoint_1(func_80100094(arg0, 0), arg1);
    }
  }
  else
  {
    func_80101870(arg0, arg1);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_808003C4_chdumbwaiterlift.s")

/* extern */

void func_808004E8_chdumbwaiterlift(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    s32 _gcnewoption_entrypoint_32(s32, s32);
    s32 _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
    _gcnewoption_entrypoint_14(arg1, 0, 1, 4, 4.0f);
    _gcnewoption_entrypoint_40(arg1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(arg1, 0xA3);
}

void func_80800560_chdumbwaiterlift(s32 arg0) {
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    s32 _gcnewoption_entrypoint_21(s32, s32);
    void _gcnewoption_entrypoint_31(s32, s32, s16);
    s32 func_800EA05C();
    extern s16 D_80800BC0_chdumbwaiterlift[][4];
    s32 var_s0;
    s32 var_s1;
    s16 flag;

    var_s0 = 0;
    for (var_s1 = 0; var_s1 < 5; var_s1++) {
        if (func_800EA05C() != D_80800BC0_chdumbwaiterlift[var_s1][0]) {
            _gcnewoption_entrypoint_12(arg0, var_s0, (s16) (var_s1 + 0xA));
            _gcnewoption_entrypoint_21(arg0, var_s0);
            _gcnewoption_entrypoint_31(arg0, var_s0, flag = ((u8 *)D_80800BC0_chdumbwaiterlift[var_s1])[7]);
            var_s0 += 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800608_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800770_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800804_chdumbwaiterlift.s")

s32 func_808008B4_chdumbwaiterlift(void) {
    s32 func_800EA05C();
    extern s16 D_80800BC0_chdumbwaiterlift[][4];
    s32 map;
    s32 i;

    map = func_800EA05C();
    for (i = 0; i < 5; i++) {
        if (map == D_80800BC0_chdumbwaiterlift[i][0]) {
            return i;
        }
    }
    return -1;
}

s32 func_8080094C_chdumbwaiterlift(void) {
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    extern s16 D_80800BC0_chdumbwaiterlift[][4];
    s16 (*var_s0)[4];
    s32 var_s1;

    var_s0 = D_80800BC0_chdumbwaiterlift;
    var_s1 = 0;
loop_1:
    if (func_800DA298((*var_s0)[2]) != 0) {
        func_800DA524((*var_s0)[2]);
        return var_s1;
    }
    var_s1 += 1;
    var_s0 += 1;
    if (var_s1 == 5) {
        return -1;
    }
    goto loop_1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_808009B8_chdumbwaiterlift.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dumbwaiterlift/func_80800A8C_chdumbwaiterlift.s")

void func_80800B40_chdumbwaiterlift(Actor *arg0) {
    void _capod_entrypoint_3(u32);
    void _subaddieDll_entrypoint_4(Actor*, u32);
    if (arg0->unk64_20) {
        _capod_entrypoint_3(0U);
        _subaddieDll_entrypoint_4(arg0, 0U);
        *(volatile u8 *)((s8 *)arg0 + 0x65) = *(volatile u8 *)((s8 *)arg0 + 0x65) & 0xFFEF;
    }
}
