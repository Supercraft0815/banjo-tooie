#include "common.h"

/* extern */

s32 gldbstring_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800D674C(s32);
    s32 func_800D70D0(s32);
    s32 func_800D71F4(s32);
    arg0 = func_800D674C(arg1);
    func_800D70D0(1);
    func_800D71F4(1);
    return arg0 + 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dbstring/gldbstring_entrypoint_1.s")

void gldbstring_entrypoint_2(s32 arg0) {
    s32 func_800D6CEC(s32);
    s32 func_800D70F8(s32, s32);
    s32 func_800D721C(s32, s32);
    func_800D721C(arg0, 0);
    func_800D70F8(arg0, 0);
    func_800D6CEC(arg0);
}
