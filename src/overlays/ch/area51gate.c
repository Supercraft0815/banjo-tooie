#include "common.h"

OSThread *charea51gate_entrypoint_0(void)
{
    extern u8 D_80800290_charea51gate[];

    return (OSThread *) D_80800290_charea51gate;
}

void func_8080000C_charea51gate(s32 arg0) {
    s32 func_80104004(s32, s32, s32);
    void func_8010A800(Actor*, s32);
    func_80104004(arg0, arg0 + 0x18, arg0 + 0x28);
    (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x20))) + 40.0f);
    func_8010A800((Actor *) arg0, 2);
}

/* extern */

void func_80800054_charea51gate(Actor *arg0) {
    int func_800DC298(f32);
    s32 _chelectricfence_entrypoint_2(Actor *, u8 *, u8 *);
    if (arg0->unk7C_12 && (func_800DC298(0.15f) != 0)) {
        _chelectricfence_entrypoint_2(arg0, (u8 *)arg0 + 0x18, (u8 *)arg0 + 0x28);
    }
}

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
