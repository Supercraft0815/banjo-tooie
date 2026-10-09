#include "common.h"

OSThread *chtntdetonator_entrypoint_0(void)
{
    extern u8 D_808006A8_chtntdetonator[];

    return (OSThread *) D_808006A8_chtntdetonator;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_8080000C_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800054_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800148_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_8080021C_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_808002D8_chtntdetonator.s")

void func_80800380_chtntdetonator(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_80800704_chtntdetonator;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 12, &D_80800704_chtntdetonator);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_808003C0_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800400_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800588_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/chtntdetonator_entrypoint_1.s")
