#include "common.h"

/* extern */

void func_80800000_chboggyfish(s32 *arg0, void *arg1) {
    s32 func_800D1844(s32);
    s32 func_800DA544(s32);
    s32 func_800F54E4();
    s32 func_800F6388(s32, s32);
    s32 func_800FC6B0(s32);
    s32 func_800FFA88(s32);
    if (((u32) (*(u32 *)((s8 *)(arg1) + (0x24))) >> 0x16) == 0) {
        func_800F6388(func_800F54E4(), 0x4BA);
        func_800D1844(0x51);
        func_800FC6B0(0xE);
        func_800DA544(0x438);
        func_800FFA88(*arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fish/func_80800064_chboggyfish.s")

void func_8080018C_chboggyfish(void *arg0) {
    (*(f32 *)((s8 *)arg0 + 0x28)) += (*(f32 *)((s8 *)arg0 + 0x2C));
    if ((*(f32 *)((s8 *)(arg0) + (0x28))) <= 0.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x28))) = 0.0f;
        (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (0.0f - (*(f32 *)((s8 *)arg0 + 0x2C)));
    }
    if ((*(f32 *)((s8 *)(arg0) + (0x28))) >= 4.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x28))) = 4.0f;
        (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (0.0f - (*(f32 *)((s8 *)(arg0) + (0x2C))));
    }
}

OSThread *chboggyfish_entrypoint_0(void)
{
    extern u8 D_80800220_chboggyfish[];

    return (OSThread *) D_80800220_chboggyfish;
}
