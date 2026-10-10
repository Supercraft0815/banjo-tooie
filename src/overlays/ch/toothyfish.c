#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800000_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_808000E8_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800188_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_808002DC_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800350_chtoothyfish.s")

void func_808003D4_chtoothyfish(s32 arg0, u8 *arg1)
{
  s32 func_808000E8_chtoothyfish(s32, s32, s32, u8 *);
  s32 sp18;
  s32 var_a2;
  s32 var_v0;
  u8 *var_v1;
  var_a2 = 0;
 do { var_v0 = 0; var_v1 = arg1; do { var_v0 += 1; if ((*((u8 *) (((s8 *) var_v1) + 0x34))) == 0) { var_a2 += 1; } var_v1 += 1; } while (var_v0 != 5); } while (0);
  if (var_a2 != (*((u8 *) (((s8 *) arg1) + 0x3E))))
  {
    if (var_a2 != 0)
    {
      sp18 = var_a2;
      func_808000E8_chtoothyfish(arg0, 2, var_a2, arg1);
    }
    else
    {
      sp18 = var_a2;
      func_808000E8_chtoothyfish(arg0, 3, var_a2, arg1);
    }
    *((u8 *) (((s8 *) arg1) + 0x3E)) = ((u8) var_a2) & 0xFFFF;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800470_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_808004A4_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800908_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_8080096C_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800B68_chtoothyfish.s")

OSThread *chtoothyfish_entrypoint_0(void)
{
    extern u8 D_80801870_chtoothyfish[];

    return (OSThread *) D_80801870_chtoothyfish;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800E04_chtoothyfish.s")

void func_80800EDC_chtoothyfish(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800EE4_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80800F6C_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_8080106C_chtoothyfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/toothyfish/func_80801588_chtoothyfish.s")

OSThread *chtoothyfish_entrypoint_1(void)
{
    extern u8 D_80801914_chtoothyfish[];

    return (OSThread *) D_80801914_chtoothyfish;
}
