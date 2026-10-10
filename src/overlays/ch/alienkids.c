#include "ch/alienkids.h"

OSThread *chalienkids_entrypoint_0(void)
{
    extern u8 D_808020DC_chalienkids[];

    return (OSThread *) D_808020DC_chalienkids;
}

OSThread *chalienkids_entrypoint_1(void)
{
    extern u8 D_80802124_chalienkids[];

    return (OSThread *) D_80802124_chalienkids;
}

OSThread *chalienkids_entrypoint_2(void)
{
    extern u8 D_8080216C_chalienkids[];

    return (OSThread *) D_8080216C_chalienkids;
}

OSThread *chalienkids_entrypoint_3(void)
{
    extern u8 D_808021B4_chalienkids[];

    return (OSThread *) D_808021B4_chalienkids;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800030_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800058_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_8080017C_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_808001D0_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800370_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800408_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800454_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800648_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800D58_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800DB8_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80800FA4_chalienkids.s")

void func_80801138_chalienkids(Actor* arg0)
{
    func_80801994_chalienkids(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801158_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_808014B0_chalienkids.s")

/* extern */

void func_80801520_chalienkids(void *arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiefade_entrypoint_2();
    s32 func_80102424(void *, s32);
    s32 func_8010A3E8(void *, s32);
    s32 func_808014B0_chalienkids(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 2.0f;
    _subaddiefade_entrypoint_2();
    _subaddieDll_entrypoint_4(arg0, 1);
    func_8010A3E8(arg0, 0x3F19999A);
    func_80102424(arg0, 0xD);
    func_808014B0_chalienkids(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_8080158C_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801628_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_808016D4_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_8080184C_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801884_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_8080193C_chalienkids.s")

void func_80801994_chalienkids(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_808019C8_chalienkids.s")

void func_80801A50_chalienkids(u8 *arg0) {
    void func_80109F08(void *arg0, s32 arg1);
    func_80109F08(arg0, 0x44);
    (*(u8 *)((s8 *)(arg0) + (0x7A))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x7A))) & 0xFF3F) | 0x80);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801A88_chalienkids.s")

/* extern */

void func_80801B08_chalienkids(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801B40_chalienkids.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/alienkids/func_80801BC4_chalienkids.s")
