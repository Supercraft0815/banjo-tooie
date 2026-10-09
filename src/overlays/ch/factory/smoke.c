#include "common.h"

OSThread *chfactorysmoke_entrypoint_0(void)
{
    extern u8 D_80800100_chfactorysmoke[];

    return (OSThread *) D_80800100_chfactorysmoke;
}

/* extern */

void func_8080000C_chfactorysmoke(void *arg0) {
    f32 func_800DC178(f32, f32);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = func_800DC178(0.55f, 0.65f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/smoke/func_80800044_chfactorysmoke.s")

void func_808000A8_chfactorysmoke(s32 arg0) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80800148_chfactorysmoke;
    func_800BBCB8(arg0 + 4, 0, 0x3F800000, 4, &D_80800148_chfactorysmoke);
}
