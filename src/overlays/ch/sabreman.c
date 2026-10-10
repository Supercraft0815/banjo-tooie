#include "common.h"

OSThread *chsabreman_entrypoint_0(void)
{
    extern u8 D_80801BE0_chsabreman[];

    return (OSThread *) D_80801BE0_chsabreman;
}

OSThread *chsabreman_entrypoint_1(void)
{
    extern u8 D_80801D30_chsabreman[];

    return (OSThread *) D_80801D30_chsabreman;
}

OSThread *chsabreman_entrypoint_2(void)
{
    extern u8 D_80801D78_chsabreman[];

    return (OSThread *) D_80801D78_chsabreman;
}

OSThread *chsabreman_entrypoint_3(void)
{
    extern u8 D_80801DC0_chsabreman[];

    return (OSThread *) D_80801DC0_chsabreman;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800030_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800218_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808008C8_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800CDC_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800D30_chsabreman.s")

void func_80800F04_chsabreman(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800DA564(s32, s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA564(0x1CA, 2) != 3) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80800F74_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801010_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_8080112C_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808011AC_chsabreman.s")

void func_808011F8_chsabreman()
{
    func_80102424();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801218_chsabreman.s")

void func_8080158C_chsabreman(Actor *arg0) {
    s32 func_800DA564(s32, s32);
    void func_800FFAB0(Actor*);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, 0.45f);
    if (func_800DA564(0x1CA, 2) != 3) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808015D4_chsabreman.s")

/* extern */

void func_80801620_chsabreman(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(5, 1);
    func_800DF744(3, 0);
    func_800DF744(6, 0);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

/* extern */

s32 func_8080167C_chsabreman(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(s32, s32);
    s32 func_80801724_chsabreman(s32, s32, s32);
    void *temp_v0;

    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        temp_v0 = func_80100094(arg0, 0);
        if ((temp_v0 != NULL) && ((*(s16 *)((s8 *)(temp_v0) + (0x820))) != 2)) {
            func_80801724_chsabreman(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808016E4_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801724_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808017D8_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_80801864_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808018DC_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_8080193C_chsabreman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/sabreman/func_808019A4_chsabreman.s")
