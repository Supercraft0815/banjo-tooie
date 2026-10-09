#include "common.h"

/* extern */

void func_80800000_chhumba(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_2(s32, s32, s32);
    _capod_entrypoint_2(*arg0, 9, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800028_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808000D4_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_8080015C_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808001E4_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800238_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800294_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800338_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800384_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808003CC_chhumba.s")

/* extern */

s32 func_80800414_chhumba(void *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        return 0x346;
    }
    return ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) + 0x346;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800450_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_8080071C_chhumba.s")

s32 func_808007EC_chhumba(s32 arg0) {
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808007F8_chhumba.s")

/* extern */

void func_80800878_chhumba(void *arg0) {
    s32 func_800DA298(s32);
    func_800DA298(((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) + 0xD5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808008A0_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800934_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800A50_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800B40_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800BA8_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800C20_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800C6C_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800CC8_chhumba.s")

/* extern */

s32 func_80800D2C_chhumba(s32 arg0) {
    s32 func_800DA9E4(s32, s32);
    s32 func_80800338_chhumba(s32, s32, s32);
    if (func_800DA9E4(0xE2, 1) == 0) {
        func_80800338_chhumba(arg0, 0x11B5, 0xF);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800D74_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800E44_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80801260_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_8080138C_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_8080144C_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808015DC_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80801DB0_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80801F74_chhumba.s")

void func_808021F4_chhumba(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
OSThread *chhumba_entrypoint_0(void)
{
    extern u8 D_80802738_chhumba[];

    return (OSThread *) D_80802738_chhumba;
}

/* extern */

void func_80802234_chhumba(void *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        (*(f32 *)((s8 *)(arg0) + (0x38))) = 2.0f;
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 1.0f;
}

OSThread *chhumba_entrypoint_1(void)
{
    extern u8 D_80802780_chhumba[];

    return (OSThread *) D_80802780_chhumba;
}
