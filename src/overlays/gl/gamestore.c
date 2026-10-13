#include "common.h"

/* extern */

s32 func_80800000_glgamestore(void) {
    s32 _glcrc_entrypoint_1();
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = _glcrc_entrypoint_1();
    var_v1 = temp_v0;
    if (temp_v0 != 0) {
        var_v1 = 3;
    }
    return var_v1;
}

s32 func_80800030_glgamestore(s32 arg0) {
    return arg0 << 7;
}

s32 func_80800038_glgamestore(s32 arg0) {
    return func_80800030_glgamestore(2) + arg0 * 0x1C0;
}

s32 func_8080006C_glgamestore(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gleeprom_entrypoint_2();
    s32 func_80800000_glgamestore();
    s32 var_v1;
    s32 sp1C;

    sp1C = 0;
    var_v1 = sp1C;
    if (_gleeprom_entrypoint_2(arg0) != 0) {
        var_v1 = 2;
    }
    if (var_v1 == 0) {
        var_v1 = func_80800000_glgamestore(arg1, arg2);
    }
    return var_v1;
}

/* extern */

void glgamestore_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_8080006C_glgamestore(s32, s32, s32);
    func_8080006C_glgamestore(func_80800038_glgamestore(arg0), arg1, 0x1C0);
}

/* extern */

s32 glgamestore_entrypoint_1(s32 arg0, s32 arg1) {
    s32 _glglobaldata_entrypoint_1(s32);
    s32 func_8080006C_glgamestore(s32, s32, s32);
    s32 var_v1;
    s32 sp1C;

    var_v1 = func_8080006C_glgamestore(func_80800030_glgamestore(arg0), arg1, 0x80);
    if (var_v1 == 0) {
        sp1C = var_v1;
        if (_glglobaldata_entrypoint_1(arg1) == 0) {
            var_v1 = 2;
        }
    }
    return var_v1;
}

s32 func_8080013C_glgamestore() {
    s32 _gleeprom_entrypoint_1();
    extern s32 D_80079D70;
    s32 var_v1;

    var_v1 = 0;
    if ((*(s32 *)((s8 *)(&D_80079D70) + (0x1EC))) == 2) {
        if (_gleeprom_entrypoint_1() != 0) {
            var_v1 = 1;
        }
    }
    return var_v1;
}

/* extern */

void glgamestore_entrypoint_2(s32 arg0, s32 arg1) {
    s32 func_8080013C_glgamestore();
    func_8080013C_glgamestore(func_80800038_glgamestore(arg0), arg1, 0x1C0);
}

/* extern */

void glgamestore_entrypoint_3(s32 arg0, s32 arg1) {
    s32 func_8080013C_glgamestore();
    func_8080013C_glgamestore(func_80800030_glgamestore(arg0), arg1, 0x80);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/func_808001E0_glgamestore.s")

void glgamestore_entrypoint_4()
{
    s32 func_80800038_glgamestore();
    func_808001E0_glgamestore(func_80800038_glgamestore());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/glgamestore_entrypoint_5.s")
