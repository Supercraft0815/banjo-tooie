#include "core2/1E6EC70.h"

s32 func_80095380(void)
{
	return 0x18;
}

u8 func_80095388(s32 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    s32 threshold = arg3 + 0x3E8;
    s16 *entry = (s16 *)(arg2 + 0xC);
    s16 index;
    if (*entry >= 0) {
      do {
        index = *entry;
        if (index + threshold < arg1) {
            *arg0 = ((u8 *)entry)[2];
            return ((u8 *)entry)[3];
        }
        entry += 2;
        index = *entry;
      } while (index >= 0);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_800953E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_80095490.s")

/* extern */

s32 func_800954E8(void *arg0, s32 *arg1) {
    s32 func_800D3E40(s32);
    if (func_800D3E40(3) != 0) {
        *arg1 = 0;
    } else {
        *arg1 = (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x7C)))) + (0x10)));
    }
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x7C)))) + (0x14)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_80095534.s")

s32 func_8009557C(PlayerState *arg0) {
    return ((u8 *) *(void **)((u8 *)arg0 + 0x7C))[0xC];
}

void func_80095588(PlayerState *arg0, s32 arg1) {
    u8 temp_v0;

    (*(u8 **)((s8 *)(arg0) + 0x7C))[0xC] = arg1;
    temp_v0 = (*(u8 **)((s8 *)(arg0) + 0x7C))[0xC];
    if ((temp_v0 == 2) || (temp_v0 == 3)) {
        func_800956B8(arg0);
    }
}

/* extern */

void func_800955CC(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 *temp_v0;

    func_8009C128(arg0, (*(f32 **)((s8 *)(arg0) + (0x7C))));
    (*(s8 *)((s8 *)((*(f32 **)((s8 *)(arg0) + (0x7C)))) + (0xC))) = 0;
    func_80095588(arg0, 1);
    (*(s32 *)((s8 *)((*(f32 **)((s8 *)(arg0) + (0x7C)))) + (0x10))) = 0;
    temp_v0 = (*(f32 **)((s8 *)(arg0) + (0x7C)));
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = (s32) (*(s32 *)((s8 *)(temp_v0) + (0x10)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6EC70/func_8009561C.s")

void func_800956B8(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    func_8009C128(arg0, (*(f32 **)((s8 *)(arg0) + (0x7C))));
}
