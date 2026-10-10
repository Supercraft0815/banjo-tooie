#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dialog/badialog_entrypoint_0.s")

void badialog_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
}
s32 badialog_entrypoint_2(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dialog/badialog_entrypoint_3.s")

/* extern */

s32 badialog_entrypoint_4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 badialog_entrypoint_3(s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA3B8(s32, s32);
    if (func_800DA298(arg3) != 0) {
        return 0;
    }
    if (badialog_entrypoint_3(arg0, arg1, arg2) != 0) {
        func_800DA3B8(arg3, 1);
    }
    return func_800DA298(arg3);
}
