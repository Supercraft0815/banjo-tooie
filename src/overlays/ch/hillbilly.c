#include "common.h"

OSThread *chhillbilly_entrypoint_0(void)
{
    extern u8 D_80800C60_chhillbilly[];

    return (OSThread *) D_80800C60_chhillbilly;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_8080000C_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800064_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800298_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_808002F0_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800348_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_808003C8_chhillbilly.s")

/* extern */

s32 func_8080042C_chhillbilly(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    struct Flags {
        u8 pad[0x64];
        u32 : 2;
        u32 flag : 1;
        u32 : 29;
    };

    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    } else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_8080046C_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_808004D0_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800540_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_808006B4_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800894_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800944_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_808009D8_chhillbilly.s")
