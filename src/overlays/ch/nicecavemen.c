#include "common.h"

OSThread *chnicecavemen_entrypoint_0(void)
{
    extern u8 D_80801A5C_chnicecavemen[];

    return (OSThread *) D_80801A5C_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_1(void)
{
    extern u8 D_80801AA4_chnicecavemen[];

    return (OSThread *) D_80801AA4_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_2(void)
{
    extern u8 D_80801AEC_chnicecavemen[];

    return (OSThread *) D_80801AEC_chnicecavemen;
}

OSThread *chnicecavemen_entrypoint_3(void)
{
    extern u8 D_80801B34_chnicecavemen[];

    return (OSThread *) D_80801B34_chnicecavemen;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800030_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800128_chnicecavemen.s")

void func_808003B8_chnicecavemen(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_808003D8_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800624_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_8080077C_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800AB8_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800BF8_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800C6C_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80800CC8_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801178_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801200_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_8080126C_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_8080134C_chnicecavemen.s")

/* extern */

s32 func_808013D0_chnicecavemen(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80801464_chnicecavemen(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 2) {
            func_80801464_chnicecavemen(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80801428_chnicecavemen(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801464_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801508_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801580_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_80801604_chnicecavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemen/func_808016E8_chnicecavemen.s")
