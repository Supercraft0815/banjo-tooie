#include "common.h"

OSThread *chballoonbomb_entrypoint_0(void)
{
    extern u8 D_808004B0_chballoonbomb[];

    return (OSThread *) D_808004B0_chballoonbomb;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_8080000C_chballoonbomb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_80800118_chballoonbomb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_808001F8_chballoonbomb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_80800230_chballoonbomb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_80800294_chballoonbomb.s")

void func_80800354_chballoonbomb(u8 *arg0) {
    s32 func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    extern s32 D_8080050C_chballoonbomb;
    u8 *temp_a0;

    temp_a0 = arg0 + 4;
    func_800BBCB8(temp_a0, temp_a0, (*(s32 *)((s8 *)(arg0) + (0x38))), 8, &D_8080050C_chballoonbomb);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_80800394_chballoonbomb.s")

void func_80800400_chballoonbomb(u8 *arg0) {
    s32 func_800BBCB8(u8 *, u8 *, s32, s32, s32 *);
    extern s32 D_8080057C_chballoonbomb;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_8080057C_chballoonbomb);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/balloonbomb/func_80800440_chballoonbomb.s")
