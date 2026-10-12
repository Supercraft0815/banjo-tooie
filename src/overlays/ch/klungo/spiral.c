#include "common.h"

OSThread *chklungospiral_entrypoint_0(void)
{
    extern u8 D_80800620_chklungospiral[];

    return (OSThread *) D_80800620_chklungospiral;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_8080000C_chklungospiral.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_80800060_chklungospiral.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_8080015C_chklungospiral.s")

/* extern */

s32 func_808002A0_chklungospiral(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_808002FC_chklungospiral(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_808002FC_chklungospiral(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_808002FC_chklungospiral.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_808003AC_chklungospiral.s")

int func_80800430_chklungospiral(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/spiral/func_80800480_chklungospiral.s")
