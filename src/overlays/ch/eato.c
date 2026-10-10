#include "common.h"

OSThread *chcheato_entrypoint_0(void)
{
    extern u8 D_80800E98_chcheato[];

    return (OSThread *) D_80800E98_chcheato;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_8080000C_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800068_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800204_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_8080035C_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_808003C4_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800434_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_808006B8_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_8080078C_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800824_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800888_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_808008B8_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_8080098C_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800A04_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800AB4_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800B00_chcheato.s")

/* extern */

s32 func_80800BB8_chcheato(void) {
    s32 func_800D3DD0(s32);
    s32 var_s0;

    var_s0 = 1;
loop_1:
    if (func_800D3DD0(var_s0) == 0) {
        return var_s0;
    }
    var_s0 += 1;
    if (var_s0 == 6) {
        return -1;
    }
    goto loop_1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800C0C_chcheato.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800C64_chcheato.s")

/* extern */

void func_80800CC0_chcheato(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eato/func_80800D08_chcheato.s")
