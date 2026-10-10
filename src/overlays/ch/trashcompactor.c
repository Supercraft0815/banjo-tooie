#include "common.h"

OSThread *chtrashcompactor_entrypoint_0(void)
{
    extern u8 D_808008D0_chtrashcompactor[];

    return (OSThread *) D_808008D0_chtrashcompactor;
}

OSThread *chtrashcompactor_entrypoint_1(void)
{
    extern u8 D_80800918_chtrashcompactor[];

    return (OSThread *) D_80800918_chtrashcompactor;
}

OSThread *chtrashcompactor_entrypoint_2(void)
{
    extern u8 D_80800960_chtrashcompactor[];

    return (OSThread *) D_80800960_chtrashcompactor;
}

OSThread *chtrashcompactor_entrypoint_3(void)
{
    extern u8 D_808009A8_chtrashcompactor[];

    return (OSThread *) D_808009A8_chtrashcompactor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcompactor/func_80800030_chtrashcompactor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcompactor/func_808000BC_chtrashcompactor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcompactor/func_80800684_chtrashcompactor.s")

/* extern */

void func_808007A4_chtrashcompactor(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    _chswitch_entrypoint_7(arg0, 0x9F5);
    _chswitch_entrypoint_8(arg0, 512);
    _chswitch_entrypoint_9(arg0);
}

void func_808007DC_chtrashcompactor(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x3B7, 7, 0);
        return;
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/trashcompactor/func_8080081C_chtrashcompactor.s")
