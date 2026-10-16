#include "gl/globalsettings.h"

void heap_free(void *mem);

/* extern */

void glglobalsettings_entrypoint_0(void) {
    s32 glglobalsettings_entrypoint_4(s32);
    void glglobalsettings_entrypoint_6(s32, s32);
    s32 glglobalsettings_entrypoint_8(s32);
    glglobalsettings_entrypoint_4(0);
    glglobalsettings_entrypoint_6(0, 0);
    glglobalsettings_entrypoint_8(1);
}

void func_80800034_glglobalsettings(void) { s32 glglobalsettings_entrypoint_3(void); s32 glglobalsettings_entrypoint_4(s32); void glglobalsettings_entrypoint_5(s32 *, s32 *); void glglobalsettings_entrypoint_6(s32, s32); s32 glglobalsettings_entrypoint_7(void); s32 glglobalsettings_entrypoint_8(s32); s32 sp24; s32 sp20; glglobalsettings_entrypoint_4(glglobalsettings_entrypoint_3()); glglobalsettings_entrypoint_8(glglobalsettings_entrypoint_7()); glglobalsettings_entrypoint_5(&sp24, &sp20); glglobalsettings_entrypoint_6(sp24, sp20); }

void *func_80800084_glglobalsettings()
{
    return heap_alloc(0x80);
}

/* extern */

s32 func_808000A4_glglobalsettings(s32 arg0, void *arg1) {
    s32 _glgamestore_entrypoint_1(s32, void *);
    s32 _glglobaldata_entrypoint_4(void *);
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

s32 func_80800168_glglobalsettings(void **arg0) {
    s32 var_s0;
    s32 var_s2;
    s32 var_s5;
    void *temp_v0;
    void *var_s1;

    var_s1 = func_80800084_glglobalsettings();
    var_s5 = -1;
    var_s0 = 0;
    var_s2 = 0;
    do {
        if (func_808000A4_glglobalsettings(var_s0, var_s1) == 0) {
            temp_v0 = var_s1;
            var_s1 = *arg0;
            var_s2 += 1;
            var_s5 = var_s0;
            *arg0 = temp_v0;
        }
        var_s0 += 1;
    } while (var_s0 != 2);
    if (var_s2 >= 2) {
        func_80800114_glglobalsettings(var_s5);
    }
    heap_free(var_s1);
    return var_s5;
}

/* extern */

void glglobalsettings_entrypoint_1(void) {
    s32 _glglobaldata_entrypoint_2(void *);
    void *sp18[2];

    sp18[0] = func_80800084_glglobalsettings();
    if (func_80800168_glglobalsettings(sp18) == -1) {
        glglobalsettings_entrypoint_0();
    } else {
        _glglobaldata_entrypoint_2(sp18[0]);
        func_80800034_glglobalsettings();
    }
    heap_free(sp18[0]);
}

s32 func_80800278_glglobalsettings(s32 arg0, s32 arg1) {
    s32 _glgamestore_entrypoint_3(s32, s32);
    s32 count;
    s32 result;
    void *buffer;

    count = 3;
    buffer = func_80800084_glglobalsettings();
    do {
        result = _glgamestore_entrypoint_3(arg0, arg1);
        if (result == 0) {
            func_808000A4_glglobalsettings(arg0, buffer);
        }
        count--;
    } while (result != 0 && count != 0);
    heap_free(buffer);
    return result;
}

/* extern */

s32 glglobalsettings_entrypoint_2(void) {
    s32 _glglobaldata_entrypoint_3(void *);
    s32 sp24;
    s32 sp20;
    s32 var_a0;
    void *sp18;

    if (func_800DA298(FLAG5_D54_IF_GLOBALFLAGS_CHANGED) == 0) {
        return 0;
    }
    sp18 = func_80800084_glglobalsettings();
    sp20 = func_80800168_glglobalsettings(&sp18);
    _glglobaldata_entrypoint_3(sp18);
    var_a0 = 0;
loop_3:
    if (var_a0 == sp20) {
        var_a0 += 1;
        if (var_a0 != 2) {
            goto loop_3;
        }
    }
    sp24 = func_80800278_glglobalsettings(var_a0, (s32) sp18);
    if (sp24 == 0) {
        func_80800114_glglobalsettings(var_a0);
        func_800DA524(FLAG5_D54_IF_GLOBALFLAGS_CHANGED);
    }
    heap_free(sp18);
    return sp24;
}

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

void glglobalsettings_entrypoint_6(s32 arg0, s32 arg1) {
    s32 func_80015670();
    void func_800DA7A8(GameFlag startIndex, s32 set, s32 length);
    func_80015670();
    arg0 += 0x20;
    arg1 += 0x28;
    arg0 = arg0 < 0x40 ? arg0 : 0x3F;
    arg1 = arg1 < 0x40 ? arg1 : 0x3F;
    func_800DA7A8(GFLAG_BBA_SCREEN_ALIGN_X_1, arg0, 6);
    func_800DA7A8(GFLAG_BC0_SCREEN_ALIGN_Y_1, arg1, 6);
}

s32 glglobalsettings_entrypoint_7(void) {
    return func_800DA564(0xBC6, 2);
}

s32 glglobalsettings_entrypoint_8(s32 arg0) {
    extern s8 D_80800560_glglobalsettings[];
    s16 *sp18[2];
    s16 *temp;
    s32 value;
    temp = (s16 *)&D_80800560_glglobalsettings[arg0 * 4];
    value = *temp;
    sp18[1] = temp;
    func_80012F0C(value);
    func_80012F34(0, sp18[1][1]);
    func_80012F34(1, sp18[1][1]);
    func_800DA7A8(GFLAG_BC6_SPEAKER_MODE_1, arg0, 2);
}
