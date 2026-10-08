#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekeydoor/func_80800000_chicekeydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekeydoor/func_80800318_chicekeydoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekeydoor/func_8080057C_chicekeydoor.s")

OSThread *chicekeydoor_entrypoint_0(void)
{
    extern u8 D_80800930_chicekeydoor[];

    return (OSThread *) D_80800930_chicekeydoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekeydoor/func_80800640_chicekeydoor.s")
