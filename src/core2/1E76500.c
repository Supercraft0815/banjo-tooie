#include "core2/1E76500.h"

s32 func_8009CC10() 
{
    return 0x84;
}

s32 func_8009CC18(PlayerState *self, f32 *arg1)
{
  void func_800EE7F8(f32 dst[3], f32 src[3]);
  u8 *temp_v0;
  u8 *temp_v1;
  temp_v0 = *((u8 **) (((s8 *) self) + 0xF0));
  temp_v0 = temp_v0;
  temp_v1 = temp_v0;
  temp_v1 += (*((u8 *) (((s8 *) temp_v0) + 0x80))) * ((char) 0x10);
  if (!(*((u8 *) (((s8 *) temp_v1) + ((-0xF) & 0xFFFFFFFFFFFFFFFF)))))
  {
    return 0;
  }
  func_800EE7F8(arg1, temp_v1 - 0xC);
  return 1;
}

s32 func_8009CC68(PlayerState *self) {
    u8 temp_a1;
    u8 *temp_v1;

    temp_v1 = (*(u8 **)((s8 *)(self) + (0xF0)));
    temp_a1 = (*(u8 *)((s8 *)(temp_v1) + (0x80)));
    if (temp_a1 == 0) {
        return 0;
    }
    return (s32) (*(u8 *)((s8 *)((u8 *)temp_v1 + ((u32)temp_a1 << 4)) - 0x10));
}

void func_8009CC90(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xF0)))) + (0x81))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xF0)))) + (0x80))) = 0;
}

void func_8009CCA4(PlayerState *arg0) {
    void func_8009BDAC(PlayerState *, f32);
    int temp_v1;
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xF0)));
    temp_v1 = (*(u8 *)((s8 *)(temp_v0) + (0x80)));
    if (temp_v1 != 0) {
        (*(u8 *)((s8 *)(temp_v0) + (0x80))) = (u8) (temp_v1 - 1);
        if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xF0)))) + (0x80))) == 0) {
            func_8009BDAC(arg0, 1.2f);
            (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xF0)))) + (0x81))) = 0;
        }
    }
}

void func_8009CCFC(s32 *arg0, s32 arg1)
{
  s32 func_800EFD24(s32);
  u8 *temp_v0;
  temp_v0 = *((u8 **) (((s8 *) arg0) + 0xF0));
  temp_v0[(*((u8 *) (temp_v0 + 0x80))) * 0x10] = arg1;
  temp_v0 = *((u8 **) (((s8 *) arg0) + 0xF0));
  temp_v0[(2 * (8 * (*((u8 *) (temp_v0 + 0x80))))) + 1] = 0;
  temp_v0 = *((u8 **) (((s8 *) arg0) + 0xF0));
  func_800EFD24((s32) ((temp_v0 + ((*((u8 *) (temp_v0 + 0x80))) * 0x10)) + ((0, 4))));
  temp_v0 = *((u8 **) (((s8 *) arg0) + 0xF0));
  *((u8 *) (temp_v0 + 0x80)) = (*((u8 *) (temp_v0 + 0x80))) + 1;
}

void func_8009CD70(u8 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800EFD24(s32);
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xF0)));
    (*(s8 *)((s8 *)((temp_v0 + ((*(u8 *)((s8 *)(temp_v0) + (0x80))) * 0x10))) + (-0xF))) = 1;
    if (arg1 != NULL) {
        temp_v0_2 = (*(u8 **)((s8 *)(arg0) + (0xF0)));
        func_800EE7F8((f32 *)((temp_v0_2 + temp_v0_2[0x80] * 0x10) + (0, -0xC)), arg1);
        return;
    }
    temp_v0_3 = (*(u8 **)((s8 *)(arg0) + (0xF0)));
    func_800EFD24((s32)((temp_v0_3 + temp_v0_3[0x80] * 0x10) + (0, -0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76500/func_8009CDE0.s")

void func_8009CEE8(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xF0)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x80))) != 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x81))) = 0;
    }
}

/* extern */

void func_8009CF04(void *arg0) { void func_8009CDE0(void *, s32); s32 var_v0; u8 *temp_a3; u8 *var_v1; int temp_v0; s32 var_a2; u8 count; s32 one; temp_a3 = (*(u8 **)((s8 *)(arg0) + (0xF0))); temp_v0 = (*(u8 *)((s8 *)(temp_a3) + (0x80))); count = temp_v0; if (temp_v0 != 0) { one = 1; var_a2 = (*(u8 *)((s8 *)(((u8 *)((u32)temp_a3 + (temp_v0 * 0x10)))) + (-0x10))); if ((s32) temp_v0 > 0) { var_v0 = 0; var_v1 = temp_a3; do { var_v0 += 0x10; if (*var_v1 == one) { var_a2 = one; } var_v1 += 0x10; } while (var_v0 < (count * 0x10)); } if (var_a2 != (*(u8 *)((s8 *)(temp_a3) + (0x81)))) { func_8009CDE0(arg0, var_a2); } } }
