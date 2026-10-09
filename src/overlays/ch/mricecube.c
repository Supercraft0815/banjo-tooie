#include "common.h"

OSThread *chmricecube_entrypoint_0(void)
{
    extern u8 D_80800928_chmricecube[];

    return (OSThread *) D_80800928_chmricecube;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mricecube/func_8080000C_chmricecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mricecube/func_808000AC_chmricecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mricecube/func_8080050C_chmricecube.s")

/* extern */

void func_80800734_chmricecube(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, u32);
    s32 func_80101870(void *, s32);
    func_800DF744(3, (u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) << 0xC) >> 0x1F);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mricecube/func_80800778_chmricecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mricecube/func_808007B0_chmricecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mricecube/func_80800850_chmricecube.s")
