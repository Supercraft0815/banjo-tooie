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

/* extern */

s32 func_808000A4_glglobalsettings(s32 arg0, s32 arg1) {
    s32 _glgamestore_entrypoint_1(s32, s32);
    s32 _glglobaldata_entrypoint_4(s32);
    s32 sp28;
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 3;
loop_1:
    temp_v0 = _glgamestore_entrypoint_1(arg0, arg1);
    if (temp_v0 != 0) {
        var_s0 -= 1;
        if (var_s0 != 0) {
            goto loop_1;
        }
    }
    if (temp_v0 != 0) {
        sp28 = temp_v0;
        _glglobaldata_entrypoint_4(arg1);
    }
    return temp_v0;
}

/* extern */

void func_80800114_glglobalsettings(s32 arg0) {
    s32 _glgamestore_entrypoint_5(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (var_s0 != arg0) {
            _glgamestore_entrypoint_5(var_s0);
        }
        var_s0 += 1;
    } while (var_s0 != 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/func_80800168_glglobalsettings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/func_80800278_glglobalsettings.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_2.s")

s32 glglobalsettings_entrypoint_3()
{
    return func_800DA298(GFLAG_BB9_WIDESCREEN_ENABLED);
}

s32 glglobalsettings_entrypoint_4(s32 arg0) {
    void set_widescreen(s32);
    s32 var_a1;

    set_widescreen(arg0);
    if (arg0 != 0) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }
    func_800DA3B8(GFLAG_BB9_WIDESCREEN_ENABLED, var_a1);
}

void glglobalsettings_entrypoint_5(s32 *arg0, s32 *arg1) {
    *arg0 = func_800DA564(GFLAG_BBA_SCREEN_ALIGN_X_1, 6) - 0x20;
    *arg1 = func_800DA564(GFLAG_BC0_SCREEN_ALIGN_Y_1, 6) - 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_6.s")

void glglobalsettings_entrypoint_7(void) {
    func_800DA564(0xBC6, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obalsettings/glglobalsettings_entrypoint_8.s")
