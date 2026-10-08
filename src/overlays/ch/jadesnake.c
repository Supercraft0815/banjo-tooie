#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800000_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800048_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_8080009C_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800150_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800728_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_80800770_chjadesnake.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadesnake/func_808007DC_chjadesnake.s")

OSThread *chjadesnake_entrypoint_0(void)
{
    extern u8 D_808009F4_chjadesnake[];

    return (OSThread *) D_808009F4_chjadesnake;
}
