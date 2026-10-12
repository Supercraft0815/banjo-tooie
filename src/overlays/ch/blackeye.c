#include "common.h"

/* extern */

void func_80800000_chblackeye(s32 arg0, s32 arg1) {
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32);
    s32 func_800DA298(s32);
    if (func_800DA298(0) == 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_8080003C_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800128_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800224_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800314_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_808003C0_chblackeye.s")

void func_80800444_chblackeye(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800478_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_8080061C_chblackeye.s")

void func_80800774_chblackeye(u8 *arg0) {
    s32 pad[2];
    s32 func_800BBCB8(s32 *, s32 *, f32, s32, s32 *);
    s32 func_800EF04C(s32 *, u8 *);
    s32 func_800EF334(s32 *, s32);
    s32 func_800EF934(s32 *, s32 *, s32);
    s32 func_800EFA4C(s32 *, f32, f32, f32);
    extern s32 D_80800E20_chblackeye;
    extern s32 D_80800F18_chblackeye;
    extern s32 D_80800F6C_chblackeye;
    s32 sp2C;

    func_800EFA4C(&sp2C, 0.0f, 40.0f, -800.0f);
    func_800EF334(&sp2C, (*(s32 *)((s8 *)(arg0) + (0x38))));
    func_800EF934(&sp2C, &sp2C, (*(s32 *)((s8 *)(arg0) + (0x48))));
    func_800EF04C(&sp2C, arg0 + 4);
    func_800BBCB8(&sp2C, &sp2C, 1.0f, 3, &D_80800F18_chblackeye);
    func_800BBCB8(&sp2C, &sp2C, 1.0f, 1, &D_80800F6C_chblackeye);
    func_80800000_chblackeye((s32) arg0, (s32) &D_80800E20_chblackeye);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800838_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800BC4_chblackeye.s")

OSThread *chblackeye_entrypoint_0(void)
{
    extern u8 D_8080104C_chblackeye[];

    return (OSThread *) D_8080104C_chblackeye;
}
