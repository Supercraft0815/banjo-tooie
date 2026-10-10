#include "common.h"

OSThread *chfirefx_entrypoint_0(void)
{
    extern u8 D_80801200_chfirefx[];

    return (OSThread *) D_80801200_chfirefx;
}

OSThread *chfirefx_entrypoint_1(void)
{
    extern u8 D_80801248_chfirefx[];

    return (OSThread *) D_80801248_chfirefx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800018_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_5.s")

void chfirefx_entrypoint_6(Actor *arg0, s16 arg1, s16 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(temp_v0) + (0x14))) = arg1;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800884_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800AA8_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800C18_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800E9C_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800F00_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800F7C_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_8080116C_chfirefx.s")
