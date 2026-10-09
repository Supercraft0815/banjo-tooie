#include "common.h"

void func_80800000_glsavegame()
{
    heap_alloc(0x1C0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/func_80800020_glsavegame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/func_808000CC_glsavegame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/func_808002E0_glsavegame.s")

/* extern */

s32 func_8080036C_glsavegame(s32 arg0) {
    s32 _glgamestore_entrypoint_4(s32);
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 3;
loop_1:
    temp_v0 = _glgamestore_entrypoint_4(arg0);
    if (temp_v0 != 0) {
        var_s0 -= 1;
        if (var_s0 != 0) {
            goto loop_1;
        }
    }
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_4.s")

s32 glsavegame_entrypoint_5() 
{
    return 0x1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_6.s")

void func_808004B8_glsavegame(s32 arg0) {
    extern s8 D_80127614;
    *(s8 *)((u8 *)&D_80127614 + 22) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/func_808004C4_glsavegame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_10.s")
