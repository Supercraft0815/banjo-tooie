#include "common.h"

typedef struct player_state_s PlayerState;
s32 func_800964D0(PlayerState *arg0);
f32 func_800D8840(s32 arg0);

s32 func_80094E70(void)
{
	return 0x1C;
}

 s32 func_80094E78(PlayerState *arg0)
{
    return func_800964D0(arg0);
}

f32 func_80094E98(PlayerState *arg0) { s32 index = func_80094E78(arg0); u8 *data = *(u8 **)((u8 *)arg0 + 0x74); if (data[index] != 0) return *(f32 *)((s32)data + 8 + index * 4); return func_800D8840(index); }

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
