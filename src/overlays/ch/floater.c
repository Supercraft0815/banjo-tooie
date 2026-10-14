#include "common.h"

OSThread *chfloater_entrypoint_0(void)
{
    extern u8 D_808002A0_chfloater[];

    return (OSThread *) D_808002A0_chfloater;
}

/* extern */

void func_8080000C_chfloater(Actor *arg0) {
    s32 _mlwave_entrypoint_1(u8 *);
    f32 _mlwave_entrypoint_5(u8 *, f32, f32);
    f32 func_800136E4(f32);
    void *func_80100094(Actor *, u32);
    void *sp2C = func_80100094(arg0, 0);
    u8 *wave[3];

    _mlwave_entrypoint_1(sp2C);
    wave[1] = (u8 *)sp2C + 0x1C;
    _mlwave_entrypoint_1(wave[1]);
    wave[0] = (u8 *)sp2C + 0x38;
    _mlwave_entrypoint_1(wave[0]);
    arg0->rotation[2] = func_800136E4(*(f32 *)&arg0->actorData[4] + _mlwave_entrypoint_5(wave[1], -7.5f, 7.5f));
    arg0->rotation[0] = func_800136E4(*(f32 *)&arg0->actorData[5] + _mlwave_entrypoint_5(sp2C, -3.0f, 3.0f));
    arg0->position[1] = *(f32 *)&arg0->actorData[6] + _mlwave_entrypoint_5(wave[0], -20.0f, 20.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floater/func_808000C0_chfloater.s")
