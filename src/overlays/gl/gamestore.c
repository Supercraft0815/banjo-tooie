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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/func_80800038_glgamestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/func_8080006C_glgamestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/glgamestore_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/glgamestore_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/func_8080013C_glgamestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/glgamestore_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/glgamestore_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/func_808001E0_glgamestore.s")

void glgamestore_entrypoint_4()
{
    func_808001E0_glgamestore(func_80800038_glgamestore());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/gamestore/glgamestore_entrypoint_5.s")
