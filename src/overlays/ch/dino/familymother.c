#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_80800000_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_808000A0_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_80800218_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_808005EC_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_808008E4_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_8080096C_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_80801118_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_8080119C_chdinofamilymother.s")

/* extern */

void func_80801228_chdinofamilymother(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x34))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

OSThread *chdinofamilymother_entrypoint_0(void)
{
    extern u8 D_80801474_chdinofamilymother[];

    return (OSThread *) D_80801474_chdinofamilymother;
}
