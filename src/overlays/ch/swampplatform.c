#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swampplatform/func_80800000_chswampplatform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swampplatform/func_808000BC_chswampplatform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swampplatform/func_8080061C_chswampplatform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swampplatform/func_808007A4_chswampplatform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/swampplatform/func_80800804_chswampplatform.s")

OSThread *chswampplatform_entrypoint_0(void)
{
    extern u8 D_808009F8_chswampplatform[];

    return (OSThread *) D_808009F8_chswampplatform;
}
