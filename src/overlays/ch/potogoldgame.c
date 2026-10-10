#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800000_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800124_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800434_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80800A94_chpotogoldgame.s")

/* extern */

void chpotogoldgame_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800D395C();
    s32 func_80106790(s32);
    s32 func_80800434_chpotogoldgame(s32, s32);
    if (func_800D395C() != 0) {
        func_80800434_chpotogoldgame(func_80106790(arg1), 0xE);
        return;
    }
    func_80800434_chpotogoldgame(func_80106790(arg1), 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_808010A0_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_8080111C_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_8080117C_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_808011DC_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801244_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_808013BC_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801494_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801558_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_808016E8_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801870_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/chpotogoldgame_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801998_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/chpotogoldgame_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80801A7C_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/chpotogoldgame_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_8080206C_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_80802124_chpotogoldgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/potogoldgame/func_8080219C_chpotogoldgame.s")

/* extern */

void func_8080227C_chpotogoldgame(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x34))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

OSThread *chpotogoldgame_entrypoint_4(void)
{
    extern u8 D_80802578_chpotogoldgame[];

    return (OSThread *) D_80802578_chpotogoldgame;
}
