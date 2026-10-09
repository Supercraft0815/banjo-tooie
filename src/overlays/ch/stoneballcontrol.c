#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800000_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800040_chstoneballcontrol.s")

/* extern */

f32 func_80800070_chstoneballcontrol(void) {
    f32 func_80800040_chstoneballcontrol();
    return func_80800040_chstoneballcontrol() * 0.75f;
}

/* extern */

f32 func_8080009C_chstoneballcontrol(void) {
    f32 func_80800040_chstoneballcontrol();
    return func_80800040_chstoneballcontrol() * 0.33f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808000C8_chstoneballcontrol.s")

void func_808000F4_chstoneballcontrol()
{
    func_808000C8_chstoneballcontrol();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800114_chstoneballcontrol.s")

s32 func_80800130_chstoneballcontrol(s32 arg0) {
    extern s32 D_80805088_chstoneballcontrol[];
    return ((s32 *)&D_80805088_chstoneballcontrol)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800144_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800210_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800360_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080079C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800908_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800B4C_chstoneballcontrol.s")

void func_80800BCC_chstoneballcontrol(u8 *arg0, s32 arg1) {
    typedef struct { f32 v[3]; } Vec3;
    f32 func_800DC178(f32, f32);
    s32 func_800EE780(u8 *, u8 *, s32 *);
    s32 func_800EFCD8(s32 *, f32, s32);
    f32 func_80102D78(u8 *);
    s32 func_80800B4C_chstoneballcontrol(u8 *, s32);
    f32 func_8080009C_chstoneballcontrol();
    extern Vec3 D_808050B0_chstoneballcontrol;
    Vec3 sp2C = D_808050B0_chstoneballcontrol;
    f32 var_f2;
    f32 sp24;

    if (arg1 == 0) {
        var_f2 = (*(f32 *)((s8 *)(arg0) + (0x48))) + func_800DC178(110.0f, 250.0f);
    } else {
        sp24 = func_80102D78(arg0);
        var_f2 = func_800DC178(110.0f, 250.0f) + sp24;
    }
    func_800EFCD8((s32 *)&sp2C, var_f2, 0x43FA0000);
    func_800EE780(arg0 + 0x18, arg0 + 4, (s32 *)&sp2C);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = func_8080009C_chstoneballcontrol(arg0);
    if ((*(f32 *)((s8 *)(arg0) + (0x18))) > 720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x18))) = 720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x20))) > 720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x20))) = 720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x18))) < -720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x18))) = -720.0f;
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x20))) < -720.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x20))) = -720.0f;
    }
    (*(f32 *)((s8 *)(arg0) + (0x34))) = func_800DC178(0.25f, 1.0f);
    func_80800B4C_chstoneballcontrol(arg0, 7);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800D20_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800DB4_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800EBC_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800F24_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80800F9C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080120C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080128C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808012E0_chstoneballcontrol.s")

s32 func_80801320_chstoneballcontrol(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801330_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080145C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801638_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801734_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808017AC_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801808_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801884_chstoneballcontrol.s")

OSThread *chstoneballcontrol_entrypoint_0(void)
{
    extern u8 D_808050D4_chstoneballcontrol[];

    return (OSThread *) D_808050D4_chstoneballcontrol;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801944_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801B00_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801B44_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80801BE0_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808023AC_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802418_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808024F8_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802588_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802614_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802648_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808026A0_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080282C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802C30_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802D9C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802E30_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802EA0_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802F14_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80802FBC_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/chstoneballcontrol_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80803148_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80803538_chstoneballcontrol.s")

void func_8080367C_chstoneballcontrol(s32 arg0)
{
    func_80801944_chstoneballcontrol(arg0,0);
}

OSThread *chstoneballcontrol_entrypoint_2(void)
{
    extern u8 D_808052CC_chstoneballcontrol[];

    return (OSThread *) D_808052CC_chstoneballcontrol;
}

OSThread *chstoneballcontrol_entrypoint_3(void)
{
    extern u8 D_80805314_chstoneballcontrol[];

    return (OSThread *) D_80805314_chstoneballcontrol;
}

OSThread *chstoneballcontrol_entrypoint_4(void)
{
    extern u8 D_8080535C_chstoneballcontrol[];

    return (OSThread *) D_8080535C_chstoneballcontrol;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808036C0_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80803724_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80803FF4_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808040B8_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_8080419C_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804218_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804304_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808046C4_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_808047E8_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804810_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804B60_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804D40_chstoneballcontrol.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stoneballcontrol/func_80804DA0_chstoneballcontrol.s")

OSThread *chstoneballcontrol_entrypoint_5(void)
{
    extern u8 D_80805434_chstoneballcontrol[];

    return (OSThread *) D_80805434_chstoneballcontrol;
}
