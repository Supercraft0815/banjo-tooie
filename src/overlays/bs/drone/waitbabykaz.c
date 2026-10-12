#include "common.h"

void bsdronewaitbabykaz_entrypoint_0(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/waitbabykaz/bsdronewaitbabykaz_entrypoint_1.s")

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
