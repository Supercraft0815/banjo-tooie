#include "common.h"

OSThread *chtntdetonator_entrypoint_0(void)
{
    extern u8 D_808006A8_chtntdetonator[];

    return (OSThread *) D_808006A8_chtntdetonator;
}

void func_8080000C_chtntdetonator(Actor *arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    void func_80102FDC(Actor*, f32);
    s32 func_8010A63C(s32);
    func_80102FDC(arg0, arg0->scale * 0.5f);
    _subaddiefade_entrypoint_14((s32) arg0);
    func_8010A63C((s32) arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800054_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800148_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_8080021C_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_808002D8_chtntdetonator.s")

void func_80800380_chtntdetonator(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_80800704_chtntdetonator;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 12, &D_80800704_chtntdetonator);
}

void func_808003C0_chtntdetonator(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_80800754_chtntdetonator;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 15, &D_80800754_chtntdetonator);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800400_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/func_80800588_chtntdetonator.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/detonator/chtntdetonator_entrypoint_1.s")
