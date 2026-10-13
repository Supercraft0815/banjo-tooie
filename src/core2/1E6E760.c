#include "common.h"

typedef struct player_state_s PlayerState;
s32 func_800964D0(PlayerState *arg0);

s32 func_80094E70(void)
{
	return 0x1C;
}

void func_80094E78(PlayerState *arg0)
{
    func_800964D0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E760/func_80094E98.s")

s32 func_80094EEC(PlayerState *arg0, s32 arg1) {
    return func_800964D0(arg0) == arg1;
}

void func_80094F14(u8 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    (*(u8 **)(arg0 + 0x74))[arg1] = arg2;
    (*(f32 **)(arg0 + 0x74))[arg1 + 2] = arg3;
}

void func_80094F38(u8 *arg0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        (*(u8 **)(arg0 + 0x74))[i] = 0;
    }
}
