#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800000_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_8080018C_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800284_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_808002E0_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800338_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800410_chcanarymarycage.s")

OSThread *chcanarymarycage_entrypoint_0(void)
{
    extern u8 D_80800674_chcanarymarycage[];

    return (OSThread *) D_80800674_chcanarymarycage;
}
