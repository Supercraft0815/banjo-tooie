#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/func_80800000_bsbreegullbash.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/func_808000A4_bsbreegullbash.s")

void func_808001B4_bsbreegullbash(s32 arg0)
{
    _babackpack_set_state(arg0,0x7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/func_808001D4_bsbreegullbash.s")

/* extern */

void bsbreegullbash_entrypoint_0(s32 arg0) {
    s32 baflag_clear(s32, s32);
    s32 func_8009E474();
    s32 func_808001D4_bsbreegullbash(s32);
    func_8009E474();
    func_808001D4_bsbreegullbash(arg0);
    baflag_clear(arg0, 0x3E);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/bsbreegullbash_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/breegullbash/bsbreegullbash_entrypoint_2.s")

s32 bsbreegullbash_entrypoint_3(s32 arg0) {
    extern s32 D_80800560_bsbreegullbash[];
    return ((s32 *)&D_80800560_bsbreegullbash)[arg0];
}
