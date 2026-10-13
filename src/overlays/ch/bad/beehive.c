#include "common.h"

OSThread *chbadbeehive_entrypoint_0(void)
{
    extern u8 D_80800B1C_chbadbeehive[];

    return (OSThread *) D_80800B1C_chbadbeehive;
}

f32 func_8080000C_chbadbeehive(void) {
    extern u8 D_8012762C;
    switch (D_8012762C) {
    case 19:
        return 420.0f;
    case 16:
        return 440.0f;
    case 15:
        return 460.0f;
    case 18:
        return 480.0f;
    case 20:
        return 500.0f;
    case 21:
        return 550.0f;
    case 22:
        return 600.0f;
    case 23:
        return 650.0f;
    case 24:
        return 700.0f;
    case 25:
        return 630.0f;
    case 26:
        return 700.0f;
    default:
        return 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_808000EC_chbadbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_80800158_chbadbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_80800298_chbadbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_8080070C_chbadbeehive.s")

void func_808008F0_chbadbeehive(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_808008F8_chbadbeehive.s")

/* extern */

s32 func_80800990_chbadbeehive(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _suchase_entrypoint_1(Actor *);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_8010C9B0(arg0->position, 0x3E8) != 0) && (_suchase_entrypoint_1(arg0) != 0) && (func_8010C500(arg0) != 0)) {
        return 1;
    }
    return 0;
}
