#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800000_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800054_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800394_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_8080064C_chlavagargoyle.s")

OSThread *chlavagargoyle_entrypoint_0(void)
{
    extern u8 D_80800D7C_chlavagargoyle[];

    return (OSThread *) D_80800D7C_chlavagargoyle;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_808006EC_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_8080099C_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800A2C_chlavagargoyle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/gargoyle/func_80800B8C_chlavagargoyle.s")

void chlavagargoyle_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800ED8_chlavagargoyle;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_80800ED8_chlavagargoyle);
}

OSThread *chlavagargoyle_entrypoint_2(void)
{
    extern u8 D_80800F20_chlavagargoyle[];

    return (OSThread *) D_80800F20_chlavagargoyle;
}
