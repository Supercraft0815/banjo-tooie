#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800000_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_8080018C_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800284_chcanarymarycage.s")

/* extern */

void func_808002E0_chcanarymarycage(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DB9B0();
    if ((func_800DB9B0() == 0) && (func_800DA298(1) != 0) && (func_800DA298(0x507) == 0)) {
        func_800DA544(0x66);
        func_800DA544(0x507);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800338_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800410_chcanarymarycage.s")

OSThread *chcanarymarycage_entrypoint_0(void)
{
    extern u8 D_80800674_chcanarymarycage[];

    return (OSThread *) D_80800674_chcanarymarycage;
}
