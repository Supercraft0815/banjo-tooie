#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/silowait/func_80800000_bssilowait.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/silowait/func_8080003C_bssilowait.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/silowait/func_808000D0_bssilowait.s")

void func_80800120_bssilowait(s32 arg0) 
{
}
s32 bssilowait_entrypoint_0(s32 arg0) {
    extern s32 D_80800140_bssilowait[];
    return ((s32 *)&D_80800140_bssilowait)[arg0];
}
