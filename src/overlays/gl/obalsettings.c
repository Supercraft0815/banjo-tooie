#include "gl/globalsettings.h"

/* extern */

void glglobalsettings_entrypoint_0(void) {
    s32 glglobalsettings_entrypoint_4(s32);
    s32 glglobalsettings_entrypoint_6(s32, s32);
    s32 glglobalsettings_entrypoint_8(s32);
    glglobalsettings_entrypoint_4(0);
    glglobalsettings_entrypoint_6(0, 0);
    glglobalsettings_entrypoint_8(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/func_80800034_glglobalsettings.s")

void func_80800084_glglobalsettings()
{
    heap_alloc(0x80);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/func_808000A4_glglobalsettings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/func_80800114_glglobalsettings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/func_80800168_glglobalsettings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/func_80800278_glglobalsettings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_2.s")

s32 glglobalsettings_entrypoint_3()
{
    return func_800DA298(GFLAG_BB9_WIDESCREEN_ENABLED);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_4.s")

void glglobalsettings_entrypoint_5(s32 *arg0, s32 *arg1) {
    *arg0 = func_800DA564(GFLAG_BBA_SCREEN_ALIGN_X_1, 6) - 0x20;
    *arg1 = func_800DA564(GFLAG_BC0_SCREEN_ALIGN_Y_1, 6) - 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_8.s")
