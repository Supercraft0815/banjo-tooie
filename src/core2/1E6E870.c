#include "core2/1E6E870.h"

s32 func_80094F80(void)
{
	return 0x20;
}

f32 func_80094F88(PlayerState *player, s32 id) {
    f32 func_800A0C2C(PlayerState *);
    f32 func_800A0C38(PlayerState *);
    switch (id) {
        case 0: return func_800A0C2C(player);
        case 1: return func_800A0C38(player);
        case 2: return 0.0f;
        case 3: return 0.0f;
        default: return 0.0f;
    }
}

void func_80095004(PlayerState *player, s32 id, f32 position) {
    void func_800A0D74(PlayerState *, f32);
    void func_800A0D84(PlayerState *, f32);
    switch (id) {
        case 0: func_800A0D74(player, position); break;
        case 1: func_800A0D84(player, position); break;
        case 2: break;
        case 3: default: break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E870/func_80095068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E870/func_800950FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E870/func_80095124.s")

void func_8009514C(PlayerState *player) {
    void func_80095124(PlayerState *, s32, f32);
    func_80095124(player, 0, 0.09f);
    func_80095124(player, 1, 0.09f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E870/func_8009518C.s")

void func_800951B4(PlayerState *player) {
    void func_8009518C(PlayerState *, s32, f32);
    func_8009518C(player, 0, 0.034f);
    func_8009518C(player, 1, 0.034f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6E870/func_800951F4.s")
