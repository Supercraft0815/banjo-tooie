#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800000_chlakemonster.s")

void func_80800064_chlakemonster(Actor *arg0) {
    u32 func_800FDC28(u32);
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, 0U, 0U);
    func_800FDC28(0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800090_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808001C0_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808002FC_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800404_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_8080064C_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800724_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800838_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808008E8_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800968_chlakemonster.s")

/* extern */

void func_808009CC_chlakemonster(void) {
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 func_800DA544(s32);
    s32 func_800F54E4();
    s32 func_800F7C9C(s32, s32, s32, s32);
    func_800F7C9C(func_800F54E4(), 0x95, 0x116, 0xA);
    _gcgoto_entrypoint_1(0x123, 1);
    func_800DA544(0x6E8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800A14_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800C88_chlakemonster.s")

void func_808013E8_chlakemonster(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F964(s32 *);
    s32 func_8008F9C4(s32 *, s32);
    extern s32 D_808020D4_chlakemonster;
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F964(&D_808020D4_chlakemonster);
    func_8008F8D8(0);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F9C4(&D_808020D4_chlakemonster, 0x3F400000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801448_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801494_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_808016B0_chlakemonster.s")

OSThread *chlakemonster_entrypoint_0(void)
{
    extern u8 D_80802204_chlakemonster[];

    return (OSThread *) D_80802204_chlakemonster;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801790_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801834_chlakemonster.s")

void func_808018AC_chlakemonster(s32 arg0) 
{
}
/* extern */

void chlakemonster_entrypoint_1(s32 arg0) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/chlakemonster_entrypoint_2.s")

void chlakemonster_entrypoint_3(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 func_800B53A4(s32);
    s32 func_800BA1D0(s32, void *, void *, s32);
    s32 func_800BABB8(s32, void *, s32, s32, s32 *);
    extern s32 D_8080229C_chlakemonster;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(3);
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) + 200.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg0) + (4))) + 200.0f);
    func_800BABB8(temp_v0, arg1, 0, 0x3F800000, &D_8080229C_chlakemonster);
    func_800BA1D0(sp24, arg0, arg1, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801A60_chlakemonster.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801E60_chlakemonster.s")

OSThread *chlakemonster_entrypoint_4(void)
{
    extern u8 D_808022E0_chlakemonster[];

    return (OSThread *) D_808022E0_chlakemonster;
}

/* extern */

void func_80801EA8_chlakemonster(s32 arg0) {
    s32 _chswitch_entrypoint_14(s32, s32);
    s32 func_800DA298(s32);
    s32 func_8010A570(s32);
    _chswitch_entrypoint_14(arg0, 0x187);
    if (func_800DA298(0x187) != 0) {
        func_8010A570(arg0);
    }
}

void func_80801EE4_chlakemonster(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80801EEC_chlakemonster.s")

OSThread *chlakemonster_entrypoint_5(void)
{
    extern u8 D_80802328_chlakemonster[];

    return (OSThread *) D_80802328_chlakemonster;
}
