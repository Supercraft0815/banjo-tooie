#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcoa/func_80800000_chstoneballcoach.s")

/* extern */

void func_80800090_chstoneballcoach(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800C05B8(s32, s32, f32 *, Unk80132ED0 *, s32, s32, s16);
    if (arg1 != 0) {
        func_800C05B8(arg1, arg2, arg0->position, arg0->unk0, 0, 0, 0x34);
        arg0->unk70_10 = 2;
        arg0->unk74_30 = 1;
    }
}

/* extern */

void func_80800100_chstoneballcoach(void *arg0) {
    s32 func_80102B2C(void *, s32);
    s32 func_80102CF4(void *, s32);
    f32 func_8010CD28();
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_8010CD28();
    if (func_80102CF4(arg0, 0x3F800000) == 0) {
        func_80102B2C(arg0, 0x3F800000);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcoa/func_80800140_chstoneballcoach.s")

/* extern */

void func_8080035C_chstoneballcoach(Actor *arg0) {
    f32 func_800DC0C0(void);
    void func_80101EE4(Actor *, f32);
    func_80101EE4(arg0, func_800DC0C0());
}

OSThread *chstoneballcoach_entrypoint_0(void)
{
    extern u8 D_808003D4_chstoneballcoach[];

    return (OSThread *) D_808003D4_chstoneballcoach;
}
