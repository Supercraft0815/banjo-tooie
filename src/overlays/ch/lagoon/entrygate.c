#include "ch/lagoonentrygate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/entrygate/func_80800000_chlagoonentrygate.s")

void func_8080008C_chlagoonentrygate(Actor *arg0) {
    s32 _chdoor_entrypoint_0();
    void func_800C3F48(u32);
    s32 func_800D90A4(f32 *);
    if (arg0->unk70_10 == 3) {
        if (!arg0->unk64_20) {
            func_800C3F48(0x66509D6D);
            *(f32 *)&arg0->actorData[7] = 1.5f;
            arg0->unk64_20 = 1;
        } else if (func_800D90A4((f32 *)&arg0->actorData[7]) != 0) {
            func_800C3F48(0x66509CA1);
            *(f32 *)&arg0->actorData[7] = 1.0f;
        }
    }
    _chdoor_entrypoint_0(arg0);
}

OSThread *chlagoonentrygate_entrypoint_0(void)
{
    extern u8 D_80800150_chlagoonentrygate[];

    return (OSThread *) D_80800150_chlagoonentrygate;
}
