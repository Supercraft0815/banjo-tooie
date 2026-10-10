#include "common.h"

OSThread *chklungoforcefield_entrypoint_0(void)
{
    extern u8 D_80800400_chklungoforcefield[];

    return (OSThread *) D_80800400_chklungoforcefield;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/forcefield/func_8080000C_chklungoforcefield.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/forcefield/func_808000F0_chklungoforcefield.s")

void func_808001D4_chklungoforcefield(u8 *arg0) {
    void func_800C8B84(s32);
    void func_800E8C08(u8 a0);
    s32 temp_a1;
    u8 temp_a0;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x18)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
    temp_a0 = (*(u8 *)((s8 *)(arg0) + (0x24)));
    if (temp_a0 != 0) {
        func_800E8C08(temp_a0);
        (*(u8 *)((s8 *)(arg0) + (0x24))) = 0U;
    }
}

/* extern */

s32 func_80800228_chklungoforcefield(void *arg0, s32 arg1, s32 arg2) {
    s32 _chlightfader_entrypoint_1(s32, s32, s32, void *);
    s32 _subaddiefade_entrypoint_3(void *);
    s32 temp_a0;

    if (arg1 == 0x2C) {
        temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x18)));
        if (temp_a0 != 0) {
            (*(s32 *)((s8 *)(arg0) + (0x18))) = _chlightfader_entrypoint_1(temp_a0, 0x4019999A, 2, arg0);
        }
        _subaddiefade_entrypoint_3(arg0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/klungo/forcefield/func_80800288_chklungoforcefield.s")
