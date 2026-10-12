#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/splat/bssplat_entrypoint_0.s")

/* extern */

void func_8080009C_bssplat(void *arg0) {
    s32 baanim_playForDuration_once(void *, s32, f32);
    s32 bssplat_entrypoint_0(void *);
    s32 func_8008E944(void *);
    s32 func_8009DF18(void *, s32, f32, s32);
    s32 func_8009FFD8(void *, s32, s32, s32, s32);
    baanim_playForDuration_once(arg0, 0x46, 1.1f);
    func_8009FFD8(arg0, 1, 1, 3, 3);
    bssplat_entrypoint_0(arg0);
    func_8009DF18(arg0, 0x427, 1.0f, 0x6D60);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_8008E944(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/splat/func_80800114_bssplat.s")

void func_80800274_bssplat(s32 arg0)
{
    func_8008E95C();
    func_8009BD88(arg0);
}
s32 bssplat_entrypoint_1(s32 arg0) {
    extern s32 D_808002B0_bssplat[];
    return ((s32 *)&D_808002B0_bssplat)[arg0];
}
