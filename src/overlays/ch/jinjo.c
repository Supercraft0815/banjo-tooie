#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80800000_chjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_808000DC_chjinjo.s")

s32 chjinjo_entrypoint_0(s32 arg0) {
    extern s16 D_80801368_chjinjo[];
    return ((s16 *)&D_80801368_chjinjo)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80800120_chjinjo.s")

/* extern */

void chjinjo_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800D0C78(s32, s32, s32);
    func_800D0C78(arg0 + 0x51, 1, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/chjinjo_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/chjinjo_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_808002E0_chjinjo.s")

/* extern */

void chjinjo_entrypoint_4(s32 arg0, s32 arg1, s32 arg2) {
    s32 _glcutDll_entrypoint_6(s32, s32);
    _glcutDll_entrypoint_6(0x142, 0x84);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80800C10_chjinjo.s")

void func_80800EE4_chjinjo(Actor *arg0) {
    extern u32 D_80801358_chjinjo;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801358_chjinjo, 0x3F19999A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80800F14_chjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80800F80_chjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80800FC4_chjinjo.s")

s32 func_8080102C_chjinjo(Actor *arg0, s32 arg1) {
    if (arg0->unk74_30) {
        chjinjo_entrypoint_1(func_800D0CC8(arg0->unk6C_0), arg1);
        *(u8 *)((s8 *)arg0 + 0x74) = (*(u8 *)((s8 *)arg0 + 0x74)) & 0xFFBF;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jinjo/func_80801098_chjinjo.s")

OSThread *chjinjo_entrypoint_5(void)
{
    extern u8 D_808013A4_chjinjo[];

    return (OSThread *) D_808013A4_chjinjo;
}

OSThread *chjinjo_entrypoint_6(void)
{
    extern u8 D_808013EC_chjinjo[];

    return (OSThread *) D_808013EC_chjinjo;
}
