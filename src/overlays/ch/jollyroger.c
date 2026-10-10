#include "common.h"

OSThread *chjollyroger_entrypoint_0(void)
{
    extern u8 D_80801358_chjollyroger[];

    return (OSThread *) D_80801358_chjollyroger;
}

OSThread *chjollyroger_entrypoint_1(void)
{
    extern u8 D_808013A0_chjollyroger[];

    return (OSThread *) D_808013A0_chjollyroger;
}

OSThread *chjollyroger_entrypoint_2(void)
{
    extern u8 D_808013E8_chjollyroger[];

    return (OSThread *) D_808013E8_chjollyroger;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800024_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_808002E8_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800370_chjollyroger.s")

void func_8080056C_chjollyroger(void *arg0) {
    extern u32 D_80801430_chjollyroger;
    extern u32 D_8080143C_chjollyroger;
    _subaddieaudioquick_entrypoint_4(arg0, (u8 *)arg0 + 24, &D_80801430_chjollyroger, &D_8080143C_chjollyroger);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_8080059C_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800624_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800930_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800AEC_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800BA0_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800CC4_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800D28_chjollyroger.s")

void func_80800DB8_chjollyroger(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
/* extern */

s32 func_80800DD8_chjollyroger(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80800E6C_chjollyroger(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 2) {
            func_80800E6C_chjollyroger(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800E30_chjollyroger(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800E6C_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800F3C_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_80800FBC_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_8080103C_chjollyroger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jollyroger/func_808010A0_chjollyroger.s")

/* extern */

void func_80801194_chjollyroger(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 func_800DA544(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    func_800DA544(0x41);
}
