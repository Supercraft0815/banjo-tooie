#include "common.h"

void bsdronewaitbabykaz_entrypoint_0(s32 arg0) 
{
}
/* extern */

void bsdronewaitbabykaz_entrypoint_1(s32 arg0) {
    s32 _badata_entrypoint_3(s32, s32 *, s32 *);
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 func_8009FFD8(s32, s32, s32, s32, s32);
    s32 sp24;
    s32 sp20;

    _badata_entrypoint_3(arg0, &sp20, &sp24);
    baanim_playForDuration_loopSmooth(arg0, sp20, sp24);
    func_8009FFD8(arg0, 1, 1, 3, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/waitbabykaz/bsdronewaitbabykaz_entrypoint_2.s")

void bsdronewaitbabykaz_entrypoint_3(s32 arg0) {
    s32 _badata_entrypoint_34(s32);
    s32 _plsu_entrypoint_1(s32);
    s32 bs_setState(s32, s32);
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_plsu_entrypoint_1(0x11) == -1) {
        var_a1 = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, var_a1);
}
