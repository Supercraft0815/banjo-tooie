#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800000_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_8080009C_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_808004AC_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_808005F0_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800924_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800964_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800AB4_chgoldfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/fish/func_80800BA8_chgoldfish.s")

OSThread *chgoldfish_entrypoint_0(void)
{
    extern u8 D_80800D94_chgoldfish[];

    return (OSThread *) D_80800D94_chgoldfish;
}
