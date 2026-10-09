#include "common.h"

void bsdronefired_entrypoint_0()
{
    _babounce_entrypoint_3();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/fired/bsdronefired_entrypoint_1.s")

void bsdronefired_entrypoint_2()
{
    func_80099AA8();
}

/* extern */

void bsdronefired_entrypoint_3(s32 arg0) {
    s32 _babounce_entrypoint_10();
    s32 _badata_entrypoint_24(s32);
    s32 bs_setState(s32, s32);
    if (_babounce_entrypoint_10() != 0) {
        bs_setState(arg0, _badata_entrypoint_24(arg0));
    }
}
