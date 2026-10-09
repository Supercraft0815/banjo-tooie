#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/fire/func_80800000_cheggfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/fire/func_808000B8_cheggfire.s")

void func_80800228_cheggfire(s32 arg0) {
    s32 _suegg_entrypoint_21(s32, s32 *);
    s32 _suegg_entrypoint_5();
    extern s32 D_808003B0_cheggfire;
    _suegg_entrypoint_5();
    _suegg_entrypoint_21(arg0, &D_808003B0_cheggfire);
}

OSThread *cheggfire_entrypoint_0(void)
{
    extern u8 D_808003BC_cheggfire[];

    return (OSThread *) D_808003BC_cheggfire;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/fire/cheggfire_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/fire/cheggfire_entrypoint_2.s")
