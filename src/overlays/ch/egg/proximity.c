#include "common.h"

OSThread *cheggproximity_entrypoint_0(void)
{
    extern u8 D_80800CE0_cheggproximity[];

    return (OSThread *) D_80800CE0_cheggproximity;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/cheggproximity_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_808000A8_cheggproximity.s")

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 prefix[0x78];
        u16 unused : 14;
        u16 flags : 2;
    } proximity;
} ProximityActor;

void func_80800164_cheggproximity(ProximityActor *arg0) {
    s32 _subaddiedraw25d_entrypoint_1();
    s32 sp1C;

    sp1C = arg0->proximity.flags;
    if (arg0->actor.alpha != 0xFF) {
        arg0->proximity.flags = 1;
    }
    _subaddiedraw25d_entrypoint_1();
    arg0->proximity.flags = sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_808001CC_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/cheggproximity_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800330_cheggproximity.s")

/* extern */

void func_8080048C_cheggproximity(s32 arg0, void *arg1) {
    s32 _suegg_entrypoint_16(s32);
    s32 func_800EEEA8(s32);
    s32 func_808001CC_cheggproximity(s32);
    s32 func_80800718_cheggproximity(s32, s32);
    if (func_800EEEA8(arg0 + 0x28) != 0) {
        func_80800718_cheggproximity(arg0, 3);
        return;
    }
    func_808001CC_cheggproximity(arg0);
    _suegg_entrypoint_16(arg0);
    if ((*(f32 *)((s8 *)(arg1) + (0x30))) > 0.19999695f) {
        func_80800718_cheggproximity(arg0, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800510_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800588_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_808005EC_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800650_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_808006A4_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800718_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800874_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800AFC_cheggproximity.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/proximity/func_80800BF4_cheggproximity.s")
