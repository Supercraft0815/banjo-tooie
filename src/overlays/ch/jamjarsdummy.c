#include "common.h"

void func_80800000_chjamjarsdummy(Actor *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_8(Actor *, s32);

    arg0->unk79_4 = arg1;
    switch (arg0->unk79_4) {
    case 0:
        arg0->unk58 = 2.0f;
        _subaddiefade_entrypoint_8(arg0, 0xFF);
        break;
    case 1:
        switch (arg0->unk6C_0) {
        case 0:
            arg0->unk58 = 5.0f;
            break;
        case 1:
            arg0->unk58 = 5.0f;
            break;
        case 2:
            arg0->unk58 = 5.0f;
            break;
        }
        break;
    case 2:
        arg0->unk58 = 2.0f;
        ((f32 *)arg0->actorData)[4] = 0.0f;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jamjarsdummy/func_808000E0_chjamjarsdummy.s")

void func_80800238_chjamjarsdummy(s32 arg0) 
{
}
void func_80800240_chjamjarsdummy(Actor *arg0) {
    void func_80800000_chjamjarsdummy(Actor *, s32);
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
