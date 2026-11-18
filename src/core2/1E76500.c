#include "core2/1E76500.h"

s32 func_8009CC10() 
{
    return 0x84;
}    typedef struct { u8 pad0[0x80]; u8 unk80; } Obj1E76500_func_8009CC18_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_8009CC18(PlayerState *self, f32 *arg1)
{
  void func_800EE7F8(f32 dst[3], f32 src[3]);
  u8 *temp_v0;
  u8 *temp_v1;
  temp_v0 = self->unkF0;
  temp_v0 = temp_v0;
  temp_v1 = temp_v0;
  temp_v1 += (((Obj1E76500_func_8009CC18_temp_v0 *)temp_v0)->unk80) * ((char) 0x10);
  if (!(*((u8 *) (((s8 *) temp_v1) + ((-0xF) & 0xFFFFFFFFFFFFFFFF)))))
  {
    return 0;
  }
  func_800EE7F8(arg1, temp_v1 - 0xC);
  return 1;
}    typedef struct { u8 pad0[0x80]; u8 unk80; } Obj1E76500_func_8009CC68_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

s32 func_8009CC68(PlayerState *self) {
    u8 temp_a1;
    u8 *temp_v1;

    temp_v1 = (self->unkF0);
    temp_a1 = (((Obj1E76500_func_8009CC68_temp_v1 *)temp_v1)->unk80);
    if (temp_a1 == 0) {
        return 0;
    }
    return (s32) (*(u8 *)((s8 *)((u8 *)temp_v1 + ((u32)temp_a1 << 4)) - 0x10));
} typedef struct { u8 pad0[0xF0]; union { u8 * unkF0; void * unkF0_voidp; }; } Obj1E76500_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8009CC90(void *arg0) {
    (*(s8 *)((s8 *)((((Obj1E76500_arg0 *)arg0)->unkF0_voidp)) + (0x81))) = 0;
    (*(s8 *)((s8 *)((((Obj1E76500_arg0 *)arg0)->unkF0_voidp)) + (0x80))) = 0;
}    typedef struct { u8 pad0[0x80]; u8 unk80; } Obj1E76500_func_8009CCA4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009CCA4(PlayerState *arg0) {
    void func_8009BDAC(PlayerState *, f32);
    int temp_v1;
    u8 *temp_v0;

    temp_v0 = (arg0->unkF0);
    temp_v1 = (((Obj1E76500_func_8009CCA4_temp_v0 *)temp_v0)->unk80);
    if (temp_v1 != 0) {
        (((Obj1E76500_func_8009CCA4_temp_v0 *)temp_v0)->unk80) = (u8) (temp_v1 - 1);
        if ((*(u8 *)((s8 *)((arg0->unkF0)) + (0x80))) == 0) {
            func_8009BDAC(arg0, 1.2f);
            (*(s8 *)((s8 *)((arg0->unkF0)) + (0x81))) = 0;
        }
    }
}

void func_8009CCFC(s32 *arg0, s32 arg1)
{
  void func_800EFD24(f32 vec[3]);
  u8 *temp_v0;
  temp_v0 = ((Obj1E76500_arg0 *)arg0)->unkF0;
  temp_v0[(*((u8 *) (temp_v0 + 0x80))) * 0x10] = arg1;
  temp_v0 = ((Obj1E76500_arg0 *)arg0)->unkF0;
  temp_v0[(2 * (8 * (*((u8 *) (temp_v0 + 0x80))))) + 1] = 0;
  temp_v0 = ((Obj1E76500_arg0 *)arg0)->unkF0;
  func_800EFD24((BtIntPtr) ((temp_v0 + ((*((u8 *) (temp_v0 + 0x80))) * 0x10)) + ((0, 4))));
  temp_v0 = ((Obj1E76500_arg0 *)arg0)->unkF0;
  *((u8 *) (temp_v0 + 0x80)) = (*((u8 *) (temp_v0 + 0x80))) + 1;
}    typedef struct { u8 pad0[0x80]; u8 unk80; } Obj1E76500_func_8009CD70_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009CD70(u8 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void func_800EFD24(f32 vec[3]);
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;

    temp_v0 = (((PlayerState *)arg0)->unkF0);
    (*(s8 *)((s8 *)((temp_v0 + ((((Obj1E76500_func_8009CD70_temp_v0 *)temp_v0)->unk80) * 0x10))) + (-0xF))) = 1;
    if (arg1 != NULL) {
        temp_v0_2 = (((PlayerState *)arg0)->unkF0);
        func_800EE7F8((f32 *)((temp_v0_2 + temp_v0_2[0x80] * 0x10) + (0, -0xC)), arg1);
        return;
    }
    temp_v0_3 = (((PlayerState *)arg0)->unkF0);
    func_800EFD24((BtIntPtr)((temp_v0_3 + temp_v0_3[0x80] * 0x10) + (0, -0xC)));
}

void func_8009CDE0(void *arg0, s32 arg1) {
    s32 func_8009E7C8(PlayerState *, s32);
    int val = 0;

    switch (arg1) {
        case 1:
            if (func_8009E7C8(arg0, 0x1E) == 2)
                val = 1;
            break;
        case 2:
            if (func_8009E7C8(arg0, 0x1C) == 2)
                val = 1;
            break;
        case 3:
            if (func_8009E7C8(arg0, 0x1D) == 2)
                val = 1;
            break;
        case 4:
            if (func_8009E7C8(arg0, 0x25) == 2)
                val = 1;
            break;
        default:
            val = 1;
            break;
    }
    if (val)
        (((Obj1E76500_arg0 *)arg0)->unkF0)[0x81] = arg1;
}    typedef struct { u8 pad0[0x80]; u8 unk80; s8 unk81; } Obj1E76500_func_8009CEE8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009CEE8(void *arg0) {
    void *temp_v0;

    temp_v0 = (((Obj1E76500_arg0 *)arg0)->unkF0_voidp);
    if ((((Obj1E76500_func_8009CEE8_temp_v0 *)temp_v0)->unk80) != 0) {
        (((Obj1E76500_func_8009CEE8_temp_v0 *)temp_v0)->unk81) = 0;
    }
}    typedef struct { u8 pad0[0x80]; u8 unk80; u8 unk81; } Obj1E76500_func_8009CF04_temp_a3; /* offsets.py genstruct: fields from raw offsets on temp_a3; rename once understood */

/* extern */

void func_8009CF04(void *arg0) { void func_8009CDE0(void *, s32); s32 var_v0; u8 *temp_a3; u8 *var_v1; int temp_v0; s32 var_a2; u8 count; s32 one; temp_a3 = (((Obj1E76500_arg0 *)arg0)->unkF0); temp_v0 = (((Obj1E76500_func_8009CF04_temp_a3 *)temp_a3)->unk80); count = temp_v0; if (temp_v0 != 0) { one = 1; var_a2 = (*(u8 *)((s8 *)(((u8 *)((BtUIntPtr)temp_a3 + (temp_v0 * 0x10)))) + (-0x10))); if ((s32) temp_v0 > 0) { var_v0 = 0; var_v1 = temp_a3; do { var_v0 += 0x10; if (*var_v1 == one) { var_a2 = one; } var_v1 += 0x10; } while (var_v0 < (count * 0x10)); } if (var_a2 != (((Obj1E76500_func_8009CF04_temp_a3 *)temp_a3)->unk81)) { func_8009CDE0(arg0, var_a2); } } }
