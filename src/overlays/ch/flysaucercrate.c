#include "common.h"

OSThread *chflysaucercrate_entrypoint_0(void)
{
    extern u8 D_80800D78_chflysaucercrate[];

    return (OSThread *) D_80800D78_chflysaucercrate;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_8080000C_chflysaucercrate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_808000E4_chflysaucercrate.s")

void func_8080028C_chflysaucercrate(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11((*(Unk80132ED0 **)((s8 *)(arg0) + (0))), arg1, arg2, arg0 + 4, 0x41U);
    ((struct Flags *)arg0)->flag = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_808002D8_chflysaucercrate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_80800348_chflysaucercrate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_80800904_chflysaucercrate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_80800A2C_chflysaucercrate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flysaucercrate/func_80800A88_chflysaucercrate.s")
