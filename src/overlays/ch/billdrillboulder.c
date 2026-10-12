#include "common.h"

OSThread *chbilldrillboulder_entrypoint_0(void)
{
    extern u8 D_80800540_chbilldrillboulder[];

    return (OSThread *) D_80800540_chbilldrillboulder;
}

OSThread *chbilldrillboulder_entrypoint_1(void)
{
    extern u8 D_80800588_chbilldrillboulder[];

    return (OSThread *) D_80800588_chbilldrillboulder;
}

OSThread *chbilldrillboulder_entrypoint_2(void)
{
    extern u8 D_808005D0_chbilldrillboulder[];

    return (OSThread *) D_808005D0_chbilldrillboulder;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillboulder/func_80800024_chbilldrillboulder.s")

void func_8080026C_chbilldrillboulder(Actor *arg0)
{
  void _chexploder_entrypoint_3(void *, void *, u32);
  f32 *new_var;
  s32 _subaddieDll_entrypoint_6(Actor *, s32);
  void func_8010A570(Actor *);
 if ((((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 2) && (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)) { new_var = arg0->position; func_8010A570(arg0);
    _chexploder_entrypoint_3(arg0, new_var, 2U);
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillboulder/func_808002C4_chbilldrillboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/billdrillboulder/func_808003F0_chbilldrillboulder.s")

s32 func_808004D4_chbilldrillboulder(void *arg0) {
    s32 temp_v1;

    if (((u32) ((*(s32 *)((s8 *)(arg0) + (0x6C))) << 0xB) >> 0x14) == 0x3CF) {
        return 0;
    }
    temp_v1 = ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) - 0x33;
    if ((temp_v1 < 0) || (temp_v1 >= 0x1E)) {
        return 0;
    }
    return temp_v1 + 0x514;
}
