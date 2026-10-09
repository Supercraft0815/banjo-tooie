#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/func_80800000_bsbreegullbash.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/func_808000A4_bsbreegullbash.s")

void func_808001B4_bsbreegullbash(s32 arg0)
{
    _babackpack_set_state(arg0,0x7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/func_808001D4_bsbreegullbash.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/bsbreegullbash_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/bsbreegullbash_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/bsbreegullbash_entrypoint_2.s")

s32 bsbreegullbash_entrypoint_3(s32 arg0) {
    extern s32 D_80800560_bsbreegullbash[];
    return ((s32 *)&D_80800560_bsbreegullbash)[arg0];
}
