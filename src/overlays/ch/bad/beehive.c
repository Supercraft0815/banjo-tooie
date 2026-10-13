#include "common.h"

OSThread *chbadbeehive_entrypoint_0(void)
{
    extern u8 D_80800B1C_chbadbeehive[];

    return (OSThread *) D_80800B1C_chbadbeehive;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/beehive/func_8080000C_chbadbeehive.s")

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
