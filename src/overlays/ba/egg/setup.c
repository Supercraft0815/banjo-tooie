#include "common.h"

s32 baeggsetup_entrypoint_0() 
{
    return 0x28;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/func_80800008_baeggsetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_3.s")

/* extern */

void baeggsetup_entrypoint_4(s32 arg0) {
    s32 baeggsetup_entrypoint_3(s32, u8, u8 *, u8 *, u8 *);
    u8 *func_800F53D0();
    u8 *temp_a2;

    temp_a2 = (*(u8 **)((s8 *)(func_800F53D0()) + (0x70)));
    baeggsetup_entrypoint_3(arg0, (*(u8 *)((s8 *)(temp_a2) + (0x24))), temp_a2, temp_a2 + 0xC, temp_a2 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/setup/baeggsetup_entrypoint_10.s")
