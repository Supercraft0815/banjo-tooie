#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/grenade/func_80800000_chegggrenade.s")

/* extern */

void chegggrenade_entrypoint_0(void *arg0) {
    s32 _cheggsplode_entrypoint_1(s32 *, s32, s32);
    s32 _gcegg_entrypoint_0(u32);
    s32 _suegg_entrypoint_4(s32, s32);
    void *func_80100094(s32, s32);
    s32 func_80106790();
    s32 sp24;
    s32 temp_v0;
    s32 sp1C;

    temp_v0 = func_80106790();
    sp24 = temp_v0;
    sp1C = (s32) (*(s16 *)((s8 *)(func_80100094(temp_v0, 0)) + (0x3A)));
    _cheggsplode_entrypoint_1(&sp24, sp1C, _gcegg_entrypoint_0((u32) (*(u32 *)((s8 *)(arg0) + (0x24))) >> 0x16));
    _suegg_entrypoint_4(sp24, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/grenade/func_80800164_chegggrenade.s")

OSThread *chegggrenade_entrypoint_1(void)
{
    extern u8 D_80800450_chegggrenade[];

    return (OSThread *) D_80800450_chegggrenade;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/grenade/chegggrenade_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/grenade/chegggrenade_entrypoint_3.s")
