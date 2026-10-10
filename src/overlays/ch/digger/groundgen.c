#include "common.h"

OSThread *chdiggergroundgen_entrypoint_0(void)
{
    extern u8 D_80800500_chdiggergroundgen[];

    return (OSThread *) D_80800500_chdiggergroundgen;
}

/* extern */

void func_8080000C_chdiggergroundgen(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _subaddielink_entrypoint_0(u8 *);
    _subaddielink_entrypoint_0(func_80100094(arg0, 0U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_80800034_chdiggergroundgen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_808000AC_chdiggergroundgen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_80800118_chdiggergroundgen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_808002C4_chdiggergroundgen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/groundgen/func_8080035C_chdiggergroundgen.s")
