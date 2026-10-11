#include "common.h"

/* extern */

void func_80800000_chdinoroargrill(void *arg0) {
    s32 func_8010A800(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
    func_8010A800(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/roargrill/func_80800028_chdinoroargrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/roargrill/func_80800124_chdinoroargrill.s")

OSThread *chdinoroargrill_entrypoint_0(void)
{
    extern u8 D_80800258_chdinoroargrill[];

    return (OSThread *) D_80800258_chdinoroargrill;
}
