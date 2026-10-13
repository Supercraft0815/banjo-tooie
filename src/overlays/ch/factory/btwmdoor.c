#include "common.h"

/* extern */

void func_80800000_chfactorybtwmdoor(Actor *arg0) {
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    s32 func_8010C500(Actor *);
    *(f32 *)&arg0->actorData[7] = arg0->position[1];
    if (func_8010C500(arg0) && func_800F64A4(func_800F54E4(), 0x40)) {
        arg0->unk58 = 3.0f;
    } else {
        arg0->unk58 = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/btwmdoor/func_80800068_chfactorybtwmdoor.s")

OSThread *chfactorybtwmdoor_entrypoint_0(void)
{
    extern u8 D_80800344_chfactorybtwmdoor[];

    return (OSThread *) D_80800344_chfactorybtwmdoor;
}
