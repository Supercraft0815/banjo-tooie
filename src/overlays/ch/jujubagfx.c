#include "common.h"

OSThread *chjujubagfx_entrypoint_0(void)
{
    extern u8 D_80800470_chjujubagfx[];

    return (OSThread *) D_80800470_chjujubagfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/func_8080000C_chjujubagfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/func_80800100_chjujubagfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/func_80800174_chjujubagfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/func_808001A8_chjujubagfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/func_808003D4_chjujubagfx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/chjujubagfx_entrypoint_1.s")

void chjujubagfx_entrypoint_2(void) {
    s32 _chbaddiesetup_entrypoint_0(s32 *);
    extern s32 _chjujubagfx_entrypoint_1;
    _chbaddiesetup_entrypoint_0(&_chjujubagfx_entrypoint_1);
}
