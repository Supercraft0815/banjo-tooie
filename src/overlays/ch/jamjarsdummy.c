#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jamjarsdummy/func_80800000_chjamjarsdummy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jamjarsdummy/func_808000E0_chjamjarsdummy.s")

void func_80800238_chjamjarsdummy(s32 arg0) 
{
}
void func_80800240_chjamjarsdummy(Actor *arg0) {
    s32 func_80800000_chjamjarsdummy(Actor *, s32);
    extern struct { u16 value; u16 pad; } D_8080032C_chjamjarsdummy[];
    extern struct { s16 value; s16 pad; } D_8080032E_chjamjarsdummy[];
    func_80103140(arg0, D_8080032C_chjamjarsdummy[arg0->unk6C_0].value, arg0->unk0->unk16); func_80102424(arg0, D_8080032E_chjamjarsdummy[arg0->unk6C_0].value); func_80800000_chjamjarsdummy(arg0, 0);
}

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
