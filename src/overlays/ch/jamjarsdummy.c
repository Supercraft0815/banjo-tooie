#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jamjarsdummy/func_80800000_chjamjarsdummy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jamjarsdummy/func_808000E0_chjamjarsdummy.s")

void func_80800238_chjamjarsdummy(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jamjarsdummy/func_80800240_chjamjarsdummy.s")

/* extern */

void func_808002AC_chjamjarsdummy(Actor *arg0, void *arg1) {
    void func_80101870(Actor *, void *);
    if (arg0->unk6C_0 == 2) {
        arg0->unk7C_12 = 1;
        return;
    }
    func_80101870(arg0, arg1);
}

OSThread *chjamjarsdummy_entrypoint_0(void)
{
    extern u8 D_80800338_chjamjarsdummy[];

    return (OSThread *) D_80800338_chjamjarsdummy;
}
