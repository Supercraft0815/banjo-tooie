#include "common.h"

OSThread *chfactorybattery_entrypoint_0(void)
{
    extern u8 D_80801B34_chfactorybattery[];

    return (OSThread *) D_80801B34_chfactorybattery;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_8080000C_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800050_chfactorybattery.s")

void func_8080019C_chfactorybattery(volatile unsigned int arg0, void *arg1, s32 arg2, s32 arg3)
{
  s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
  extern s32 _subaddietaxi_entrypoint_16;
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, *((s32 *) (((s8 *) arg1) + 0)), *((s32 *) (((s8 *) arg1) + 4)), *((s32 *) (((s8 *) arg1) + 8)), arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808001F8_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808003C0_chfactorybattery.s")

/* extern */

s32 func_80800444_chfactorybattery(void) {
    s32 func_800DA298(s32);
    s32 func_80800480_chfactorybattery();
    s32 temp_v0;

    temp_v0 = func_80800480_chfactorybattery();
    if (temp_v0 != 0) {
        return func_800DA298(temp_v0);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800480_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808004E8_chfactorybattery.s")

/* extern */

void func_80800558_chfactorybattery(void) {
    s32 func_800DA298(s32);
    s32 func_80800678_chfactorybattery();
    func_800DA298(func_80800678_chfactorybattery() + 0x1B1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800580_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800678_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808006E4_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800760_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808008C8_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800948_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808009C8_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800AB8_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80801040_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_8080130C_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808014C0_chfactorybattery.s")

OSThread *chfactorybattery_entrypoint_1(void)
{
    extern u8 D_80801BA8_chfactorybattery[];

    return (OSThread *) D_80801BA8_chfactorybattery;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_8080150C_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80801728_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80801804_chfactorybattery.s")

OSThread *chfactorybattery_entrypoint_2(void)
{
    extern u8 D_80801BF0_chfactorybattery[];

    return (OSThread *) D_80801BF0_chfactorybattery;
}
