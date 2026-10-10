#include "common.h"

OSThread *charea51gate_entrypoint_0(void)
{
    extern u8 D_80800290_charea51gate[];

    return (OSThread *) D_80800290_charea51gate;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/area51gate/func_8080000C_charea51gate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/area51gate/func_80800054_charea51gate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/area51gate/func_808000A0_charea51gate.s")

void func_80800228_charea51gate(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_800DA544(s32);
    s32 func_800FFAB0(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    extern s32 D_808002D8_charea51gate;
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_808002D8_charea51gate);
    func_800FFAB0(arg0);
    func_800DA544(0xA7);
}
