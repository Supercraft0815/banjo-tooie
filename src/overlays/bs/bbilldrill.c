#include "common.h"

void func_80800000_bsbbilldrill(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x168) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_80800008_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_808000C0_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_80800100_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_80800158_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_8080019C_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_80800250_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_80800298_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_808002DC_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/func_808005C0_bsbbilldrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bbilldrill/bsbbilldrill_entrypoint_2.s")

s32 bsbbilldrill_entrypoint_3(s32 arg0) {
    extern s32 D_80800B68_bsbbilldrill[];
    return ((s32 *)&D_80800B68_bsbbilldrill)[arg0];
}
