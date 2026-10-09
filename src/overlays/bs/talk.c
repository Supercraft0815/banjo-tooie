#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/talk/bstalk_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/talk/bstalk_entrypoint_1.s")

void bstalk_entrypoint_2(s32 arg0) 
{
}
s32 bstalk_entrypoint_3(s32 arg0) {
    extern s32 D_80800170_bstalk[];
    return ((s32 *)&D_80800170_bstalk)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/talk/bstalk_entrypoint_4.s")
