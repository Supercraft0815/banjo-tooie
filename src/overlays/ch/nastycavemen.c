#include "common.h"

OSThread *chnastycavemen_entrypoint_0(void)
{
    extern u8 D_808010E8_chnastycavemen[];

    return (OSThread *) D_808010E8_chnastycavemen;
}

/* extern */

int func_8080000C_chnastycavemen(void) {
    s32 _plsu_entrypoint_1(s32);
    return (func_80090178(0x10000) != 0) &&
        (_plsu_entrypoint_1(1) == -1) &&
        (_plsu_entrypoint_1(0xB) == -1);
}

/* extern */

int func_80800060_chnastycavemen(void) {
    u32 func_800F54E4(void);
    s32 func_800F640C(s32, s32);
    s32 func_8008FE14();
    return (func_8008FE14() == 0x1D9) ||
        (func_800F640C(func_800F54E4(), 0x1D9) != 0);
}

int func_808000AC_chnastycavemen(int arg0, s32 *arg1, s32 *arg2) {
    switch (arg0) {
        default:
        case 1:
            *arg1 = 0xC5;
            *arg2 = 3;
            break;
        case 2:
            *arg1 = 0x112;
            *arg2 = 5;
            break;
        case 5:
            *arg1 = 0x112;
            *arg2 = 0xD;
            break;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_8080010C_chnastycavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800194_chnastycavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800268_chnastycavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_808003FC_chnastycavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_808004C4_chnastycavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_8080067C_chnastycavemen.s")

/* extern */

void func_80800968_chnastycavemen(void) {
    extern f32 D_80127194;
    s32 func_800EA090(void);
    s32 sp1C;
    sp1C = func_800EA090();
    if (((*(s16 *)((s8 *)(&D_80127194) + 0x436)) == 0) || ((sp1C != 0) && (func_80090178(0x10000) == 0))) {
        (*(s16 *)((s8 *)(&D_80127194) + 0x436)) = (s16) sp1C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_808009BC_chnastycavemen.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800B10_chnastycavemen.s")

OSThread *chnastycavemen_entrypoint_1(void)
{
    extern u8 D_808011BC_chnastycavemen[];

    return (OSThread *) D_808011BC_chnastycavemen;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800BE0_chnastycavemen.s")

void func_80800E68_chnastycavemen(u8 *arg0, s32 arg1) {
    extern s32 func_801017D0;
    s32 func_80101808(void *, s32 *);
    func_80101808(arg0, &func_801017D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nastycavemen/func_80800E90_chnastycavemen.s")

void func_8080103C_chnastycavemen(s32 arg0) {
    _suexpression_entrypoint_8(arg0, 1);
}
