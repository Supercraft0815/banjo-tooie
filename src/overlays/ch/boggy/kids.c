#include "common.h"

s32 chboggykids_entrypoint_0(Actor *arg0) {
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32, s32, s32);
    s32 func_800DC128(s32, s32);
    extern u16 D_808000E0_chboggykids[];
    s32 kid;
    s32 index;

    if (func_800DA564(0x59D, 2) == 0) {
        func_800DA7A8(0x59D, func_800DC128(0, 3) + 1, 2);
        func_800DA7A8(0x59F, func_800DC128(0, 3) + 1, 2);
        func_800DA7A8(0x5A1, func_800DC128(0, 3) + 1, 2);
    }
    kid = arg0->unk74_7 - 0x32;
    index = (arg0->unk0->unk24 >> 22) - 0x192;
    if (func_800DA564(D_808000E0_chboggykids[index], 2) != kid + 1) {
        return 0;
    }
    return 1;
}
