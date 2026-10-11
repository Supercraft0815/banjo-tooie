#include "core2/1ED4E30.h"

extern s32 D_80135960;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB540.s")

/* extern */

void func_800FB5BC(void *arg0) {
    s32 func_800FED90(s16, void *);
    if ((*(u8 *)((s8 *)(arg0) + (0x33))) != 0) {
        func_800FED90((*(s16 *)((s8 *)(arg0) + (0x28))), arg0);
        (*(u8 *)((s8 *)(arg0) + (0x33))) = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB650.s")

void func_800FB6C0(s32 *ptr, s32 volume) {
    void func_800FB650(s32 *, s32, s32);
    func_800FB650(ptr, volume, volume);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FB968.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FBEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FBF9C.s")

void func_800FC124(u32 arg0)
{
  s32 func_800172D4(s32, u32);
  s32 func_80017764(u32);
  void func_800FB6C0(s32 *, s32);
  s32 func_800FB6E0(s32 *, s32, u32);
  extern f32 D_80135964;
  extern s32 D_80135980;
  extern s16 D_80135988;
  extern s16 D_8013598A;
  s32 temp_v0;
  if (arg0 != D_80135988)
  {
    func_800FB6E0(&D_80135960, 0, arg0);
    func_800172D4(5, arg0);
    D_80135988 = (s16) arg0;
    temp_v0 = func_80017764(arg0) ^ 0;
    D_80135980 = temp_v0;
    D_8013598A = 0;
    D_80135964 = 0.0f;
    func_800FB6C0(&D_80135960, temp_v0);
  }
}

void func_800FC1A8()
{
    func_800FB774(&D_80135960);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC508.s")

void func_800FC618(s32 arg0, s32 arg1) {
    func_800FC508(arg0, arg1, 0, (-1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC63C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC6B0.s")

void func_800FC74C(u32 track_id) {
    void *func_800FB5F8(s32);
    void *ptr = func_800FB5F8(track_id);
    if (ptr != NULL && *(s16 *)((u8 *)ptr + 0x28) >= 0) func_800FB774(ptr);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC884.s")

/* extern */

void func_800FC8EC(void) {
    void *func_800FB5F8();
    void *temp_v0;

    temp_v0 = func_800FB5F8();
    if (temp_v0 != NULL) {
        (*(f32 *)((s8 *)(temp_v0) + (0xC))) = 1.0f;
        (*(f32 *)((s8 *)(temp_v0) + (0x14))) = 1.0f;
        (*(f32 *)((s8 *)(temp_v0) + (8))) = 0.0f;
        (*(f32 *)((s8 *)(temp_v0) + (0x10))) = 0.25f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FC9B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCB00.s")

void func_800FCB54(s32 track_id, s32 arg1, s32 arg2, f32 arg3) {
    void *func_800FB5F8(s32);
    void func_800FCB9C(s32, s32, s32, f32, void *);
    func_800FCB9C(track_id, arg1, arg2, 0.0f, (u8 *)func_800FB5F8(track_id) + 0x3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCB9C.s")

s32 func_800FCCD4(s32 track_id) {
    void *func_800FB5F8(s32);
    void *ptr = func_800FB5F8(track_id);
    return (ptr == NULL || *(s16 *)((u8 *)ptr + 0x28) == -1) ? 0 : 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCD14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCD5C.s")

/* extern */

s32 func_800FCDB4(void) {
    void *func_800FB5F8();
    void *temp_v0;

    temp_v0 = func_800FB5F8();
    if (temp_v0 != NULL) {
        return (*(s32 *)((s8 *)(temp_v0) + (0x2C)));
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCDE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED4E30/func_800FCF50.s")
