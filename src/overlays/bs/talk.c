#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/talk/bstalk_entrypoint_0.s")

void bstalk_entrypoint_1(u8 *arg0) {
    s32 bs_setState(s32, s32);
    s32 var_a1;

    var_a1 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x15C))) == 0) {
        var_a1 = 1;
    }
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    bs_setState((s32) arg0, var_a1);
}

void bstalk_entrypoint_2(s32 arg0) 
{
}
s32 bstalk_entrypoint_3(s32 arg0) {
    extern s32 D_80800170_bstalk[];
    return ((s32 *)&D_80800170_bstalk)[arg0];
}

/* extern */

void bstalk_entrypoint_4(void *arg0) {
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    if (func_8009E6EC() == 8) {
        (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}
