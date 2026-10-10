#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/jump/bsdronejump_entrypoint_0.s")

void bsdronejump_entrypoint_1(s32 arg0)
{
    func_800961A0(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/jump/bsdronejump_entrypoint_2.s")

void bsdronejump_entrypoint_3()
{
    func_80099AA8();
}

/* extern */

void bsdronejump_entrypoint_4(s32 arg0) {
    s32 _badata_entrypoint_34(s32);
    s32 bs_setState(s32, s32);
    s32 _bamovegoto_entrypoint_4();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bamovegoto_entrypoint_4() != 0) {
        var_a1 = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, var_a1);
}
