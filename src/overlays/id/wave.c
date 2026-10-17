#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wave/idwave_entrypoint_0.s")

void idwave_entrypoint_1(s32 arg0) 
{
}
void idwave_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void _glidmake_entrypoint_2(s32, s32, u8 *, u8 *);
    struct Wave { f32 f[10]; s16 a; s16 b; f32 c; };
    s16 sp28[3];
    s16 sp20[3];

    _glidmake_entrypoint_2(arg2, arg3, (u8 *)sp28, (u8 *)sp20);
    ((struct Wave *)arg0)->f[1] = 0.0f;
    ((struct Wave *)arg0)->f[2] = 0.0f;
    ((struct Wave *)arg0)->f[0] = 1.0f;
    ((struct Wave *)arg0)->f[3] = sp28[1] + (sp20[1] - sp28[1]) * 0.5f;
    ((struct Wave *)arg0)->f[4] = sp28[0];
    ((struct Wave *)arg0)->f[5] = sp28[2];
    ((struct Wave *)arg0)->f[8] = (sp20[1] - sp28[1]) * 0.25f;
    ((struct Wave *)arg0)->a = 0;
    ((struct Wave *)arg0)->b = 0;
    ((struct Wave *)arg0)->c = 0.0f;
    ((struct Wave *)arg0)->f[9] = 2.0f * ((struct Wave *)arg0)->f[8];
    if (arg1 >= 0 && arg1 < 11) {
        ((struct Wave *)arg0)->f[0] = arg1 * 0.1f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/wave/idwave_entrypoint_3.s")
