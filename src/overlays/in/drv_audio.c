#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/in/drv_audio/func_80800000_indrv_audio.s")

void func_808000BC_indrv_audio(s32 arg0, s32 *arg1) {
    s32 func_800C3BDC(u8);
    u8 func_800C4350(s32, s32, s32 *);
    extern s32 D_80801478_indrv_audio;
    u8 sp1F;
    u8 temp_v0;

    temp_v0 = func_800C4350(0, 0, &D_80801478_indrv_audio);
    sp1F = temp_v0;
    func_800C4350(temp_v0 & 0xFF, 0, arg1);
    func_800C3BDC(sp1F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/in/drv_audio/indrv_audio_entrypoint_0.s")
