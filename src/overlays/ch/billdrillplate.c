#include "common.h"

OSThread *chbilldrillplate_entrypoint_0(void)
{
    extern u8 D_808010DC_chbilldrillplate[];

    return (OSThread *) D_808010DC_chbilldrillplate;
}

OSThread *chbilldrillplate_entrypoint_1(void)
{
    extern u8 D_80801124_chbilldrillplate[];

    return (OSThread *) D_80801124_chbilldrillplate;
}

OSThread *chbilldrillplate_entrypoint_2(void)
{
    extern u8 D_8080116C_chbilldrillplate[];

    return (OSThread *) D_8080116C_chbilldrillplate;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800024_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_808000B0_chbilldrillplate.s")

/* extern */

s32 func_80800240_chbilldrillplate(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_5(Actor *, s32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    s32 *value = &arg2;
    switch (arg1) {
    case 0x3F:
        if (_subaddieDll_entrypoint_5(arg0, *value) != 0) {
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_808002A0_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800358_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800408_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800738_chbilldrillplate.s")

/* extern */

void func_80800924_chbilldrillplate(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(void *, s32);
    void *func_80801020_chbilldrillplate();
    s32 var_a1;

    if ((*(u8 *)((s8 *)(func_80801020_chbilldrillplate()) + (0x13))) != 0) {
        var_a1 = 0;
    } else {
        var_a1 = (*(s32 *)((s8 *)(arg0) + (0x2C)));
    }
    func_800DF744(1, var_a1);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800978_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800B9C_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800C98_chbilldrillplate.s")

/* extern */

void func_80800D5C_chbilldrillplate(s32 arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 func_800DA298(u16);
    s32 func_800FFAB0(s32);
    void *func_80800FCC_chbilldrillplate();
    if (func_800DA298((*(u16 *)((s8 *)(func_80800FCC_chbilldrillplate()) + (0xC)))) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    _subaddiefade_entrypoint_14(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800DA4_chbilldrillplate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillplate/func_80800F24_chbilldrillplate.s")

void *func_80800FCC_chbilldrillplate(void)
{
  s32 func_800EA05C();
  extern u16 D_808010A0_chbilldrillplate;
  extern u8 D_808010DC_chbilldrillplate[];
  s32 temp_v0;
  u16 *var_v1;
  temp_v0 = func_800EA05C();
 var_v1 = &D_808010A0_chbilldrillplate; loop_1: if (temp_v0 == (*var_v1)) {
    return var_v1;
  }

  var_v1 += 0xA;
  if (((u8 *) var_v1) == D_808010DC_chbilldrillplate)
  {
    return NULL;
  }
  goto loop_1;
}

void *func_80801020_chbilldrillplate(void)
{
  s32 func_800EA05C();
  extern u16 D_808010A0_chbilldrillplate;
  extern u8 D_808010DC_chbilldrillplate[];
  u16 *var_v1;
  s32 temp_v0;
  temp_v0 = func_800EA05C();
 var_v1 = &D_808010A0_chbilldrillplate; loop_1: if (temp_v0 == var_v1[1]) {
    return var_v1;
  }

  var_v1 += 0xA;
  if (((u8 *) var_v1) == D_808010DC_chbilldrillplate)
  {
    return NULL;
  }
  goto loop_1;
}
