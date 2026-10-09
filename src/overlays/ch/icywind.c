#include "common.h"

OSThread *chicywind_entrypoint_0(void)
{
    extern u8 D_80800300_chicywind[];

    return (OSThread *) D_80800300_chicywind;
}

/* extern */

void func_8080000C_chicywind(s32 arg0) {
    s32 func_800D0B68(s32, s32);
    s32 func_800FFAB0(s32);
    if (func_800D0B68(0x21, 0) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icywind/func_80800044_chicywind.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icywind/func_808001AC_chicywind.s")
