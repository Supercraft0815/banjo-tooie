#include "common.h"

s32 func_80800000_glgamedata() 
{
    return 0x2;
}

void func_80800008_glgamedata(s8 *arg0) {
    *arg0 = 0x1E;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_0.s")

s32 func_80800084_glgamedata(s32 *arg0) {
    *arg0 = 0x4B484A43;
    return 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/func_80800098_glgamedata.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_1.s")

s32 func_808001E4_glgamedata(s32 arg0) {
    return 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/func_808001F0_glgamedata.s")

/* extern */

void glgamedata_entrypoint_2(s32 arg0) {
    s32 func_808001F0_glgamedata(s32, s32 *);
    s32 sp24;

    sp24 = func_808001E4_glgamedata(arg0);
    if (func_808001F0_glgamedata(arg0, &sp24) != 0) {
        do {

        } while (func_808001F0_glgamedata(arg0, &sp24) != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/func_808002CC_glgamedata.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamedata/glgamedata_entrypoint_6.s")
