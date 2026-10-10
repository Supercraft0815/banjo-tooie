#include "common.h"

OSThread *chcaveofhorrorsdoors_entrypoint_0(void)
{
    extern u8 D_808001C0_chcaveofhorrorsdoors[];

    return (OSThread *) D_808001C0_chcaveofhorrorsdoors;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/caveofhorrorsdoors/func_8080000C_chcaveofhorrorsdoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/caveofhorrorsdoors/func_8080006C_chcaveofhorrorsdoors.s")

void func_80800144_chcaveofhorrorsdoors(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 func_800C4AF0(s32, s32 *);
    s32 func_800DA544(s32);
    s32 func_800FFAB0(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    s32 func_808001A4_chcaveofhorrorsdoors(s32);
    extern s32 D_80800208_chcaveofhorrorsdoors;
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    func_800C4AF0(arg0 + 4, &D_80800208_chcaveofhorrorsdoors);
    func_800DA544(func_808001A4_chcaveofhorrorsdoors(arg0));
    func_800FFAB0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/caveofhorrorsdoors/func_808001A4_chcaveofhorrorsdoors.s")
