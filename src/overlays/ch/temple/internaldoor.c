#include "common.h"

OSThread *chtempleinternaldoor_entrypoint_0(void)
{
    extern u8 D_808001C0_chtempleinternaldoor[];

    return (OSThread *) D_808001C0_chtempleinternaldoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/internaldoor/func_8080000C_chtempleinternaldoor.s")

/* extern */

void func_808000F8_chtempleinternaldoor(u8 *arg0) {
    s32 _chdoor_entrypoint_0();
    s32 _chdoormake_entrypoint_7(u8 *, s32);
    _chdoor_entrypoint_0();
    if (((u32) (*(u16 *)((s8 *)(arg0) + (0x72))) >> 0xA) == 1) {
        _chdoormake_entrypoint_7(arg0, 0x40A00000);
    }
}

/* extern */

void func_80800138_chtempleinternaldoor(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    s32 func_80800178_chtempleinternaldoor();
    if (arg1 == 0x95) {
        func_80800178_chtempleinternaldoor();
    }
    _chdoor_entrypoint_1(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/internaldoor/func_80800178_chtempleinternaldoor.s")
