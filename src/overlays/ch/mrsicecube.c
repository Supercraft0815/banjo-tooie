#include "common.h"

OSThread *chmrsicecube_entrypoint_0(void)
{
    extern u8 D_8080099C_chmrsicecube[];

    return (OSThread *) D_8080099C_chmrsicecube;
}

OSThread *chmrsicecube_entrypoint_1(void)
{
    extern u8 D_808009E4_chmrsicecube[];

    return (OSThread *) D_808009E4_chmrsicecube;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800018_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_808000BC_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800260_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_808003BC_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_8080043C_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_8080048C_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800508_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800634_chmrsicecube.s")

void func_8080066C_chmrsicecube(u8 *arg0, u8 *arg1)
{
  s32 func_800EE7F8(u8 *, s32, u8 *);
  func_800EE7F8(arg1, arg0 + 4, arg1);
  *((f32 *) (((s8 *) arg1) + 4)) += (*((f32 *) (((s8 *) arg0) + 0x38))) * 100.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_808006C4_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800818_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800898_chmrsicecube.s")
