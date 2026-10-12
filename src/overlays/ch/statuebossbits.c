#include "common.h"

s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);

OSThread *chstatuebossbits_entrypoint_0(void)
{
    extern u8 D_808006F0_chstatuebossbits[];

    return (OSThread *) D_808006F0_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_1(void)
{
    extern u8 D_80800738_chstatuebossbits[];

    return (OSThread *) D_80800738_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_2(void)
{
    extern u8 D_80800780_chstatuebossbits[];

    return (OSThread *) D_80800780_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_3(void)
{
    extern u8 D_808007C8_chstatuebossbits[];

    return (OSThread *) D_808007C8_chstatuebossbits;
}

void func_80800030_chstatuebossbits(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800038_chstatuebossbits.s")

/* extern */

s32 func_80800224_chstatuebossbits(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800FFA88(s32);
    void func_80800270_chstatuebossbits(Actor *);
    s32 ret;
    if (arg1 == 0x40) {
        func_80800270_chstatuebossbits((Actor *) arg0);
        func_800FFA88(*arg0);
        ret = 1;
    } else {
        return 0;
    }
    return ret;
}

void func_80800270_chstatuebossbits(Actor *arg0) {
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_80800810_chstatuebossbits;
    extern s32 D_8080084C_chstatuebossbits;
    (void)&arg0;
    func_800BBCB8(arg0->position, 0, arg0->scale, 2, &D_80800810_chstatuebossbits);
    func_8010D930(4, -1, arg0->position, &D_8080084C_chstatuebossbits);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_808002CC_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800360_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_8080040C_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_808004D8_chstatuebossbits.s")

void func_80800604_chstatuebossbits(s32 arg0, s32 arg1) {
    s32 func_800EC398(s32, f32 *);
    extern s32 D_80800864_chstatuebossbits;
    f32 sp24[3];

    func_800EC398(arg1, sp24);
    func_800BBCB8(sp24, sp24, 1.0f, 4, &D_80800864_chstatuebossbits);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_8080064C_chstatuebossbits.s")
