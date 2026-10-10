#include "common.h"

/* extern */

s32 func_80800000_chmumboskullfakearchpanellava(void) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x134) {
        return 0x39C;
    }
    if (func_800EA05C() == 0xEF) {
        return 0x39D;
    }
    return 0;
}

/* extern */

void func_80800054_chmumboskullfakearchpanellava(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_80800000_chmumboskullfakearchpanellava();
    if (func_800DA298(func_80800000_chmumboskullfakearchpanellava()) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/skullfakearchpanellava/func_8080008C_chmumboskullfakearchpanellava.s")

OSThread *chmumboskullfakearchpanellava_entrypoint_0(void)
{
    extern u8 D_808001E0_chmumboskullfakearchpanellava[];

    return (OSThread *) D_808001E0_chmumboskullfakearchpanellava;
}

/* extern */

void func_8080012C_chmumboskullfakearchpanellava(s32 arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24(arg0 + 0x4);
}

OSThread *chmumboskullfakearchpanellava_entrypoint_1(void)
{
    extern u8 D_80800228_chmumboskullfakearchpanellava[];

    return (OSThread *) D_80800228_chmumboskullfakearchpanellava;
}
