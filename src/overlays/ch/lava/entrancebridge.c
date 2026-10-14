#include "common.h"

void func_80800000_chlavaentrancebridge(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = -2750.0f;
}

/* extern */

s32 func_80800010_chlavaentrancebridge(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0x95:
        if (func_800DA298(0x391) != 0) {
            func_80101FDC(arg0, 4);
        }
        break;
    case 0x60:
        func_80101FDC(arg0, 2);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lava/entrancebridge/func_8080008C_chlavaentrancebridge.s")

OSThread *chlavaentrancebridge_entrypoint_0(void)
{
    extern u8 D_80800230_chlavaentrancebridge[];

    return (OSThread *) D_80800230_chlavaentrancebridge;
}
