#include "common.h"

OSThread *changlerbossbubble_entrypoint_0(void)
{
    extern u8 D_808005D0_changlerbossbubble[];

    return (OSThread *) D_808005D0_changlerbossbubble;
}

/* extern */

void func_8080000C_changlerbossbubble(void *arg0) {
    s32 func_800EC75C(s32, s32 *);
    s32 func_800EFD4C(s32);
    s32 sp1C[3];

    func_800EC75C((*(s32 *)((s8 *)(arg0) + (0))), sp1C);
    func_800EFD4C((*(s32 *)((s8 *)(arg0) + (0))) + 0x1E);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 0.75f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800054_changlerbossbubble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800194_changlerbossbubble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800200_changlerbossbubble.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800334_changlerbossbubble.s")

/* extern */

void func_80800450_changlerbossbubble(u8 *arg0) {
    s32 func_800F5BF0(s32, u8 *, u8 *);
    func_800F5BF0((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF, arg0 + 4, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800480_changlerbossbubble.s")
