#include "common.h"

void func_80800000_chscreenadjust(Actor *arg0) {
    void _glglobalsettings_entrypoint_6(s32, s32);
    void func_80016068(u32, f32 *);
    f32 func_800D8FF8(void);
    f32 mlAbsF(f32);
    f32 stick[2];
    f32 dt;

    dt = func_800D8FF8();
    func_80016068(0, stick);
    if (mlAbsF(stick[0]) > 0.05f) {
        ((f32 *)arg0->actorData)[0] += stick[0] * dt * 64.0f;
    }
    if (((f32 *)arg0->actorData)[0] < -32.0f) {
        ((f32 *)arg0->actorData)[0] = -32.0f;
    } else if (((f32 *)arg0->actorData)[0] > 32.0f) {
        ((f32 *)arg0->actorData)[0] = 32.0f;
    }
    if (mlAbsF(stick[1]) > 0.05f) {
        ((f32 *)arg0->actorData)[1] += stick[1] * dt * -64.0f;
    }
    if (((f32 *)arg0->actorData)[1] < -40.0f) {
        ((f32 *)arg0->actorData)[1] = -40.0f;
    } else if (((f32 *)arg0->actorData)[1] > 24.0f) {
        ((f32 *)arg0->actorData)[1] = 24.0f;
    }
    _glglobalsettings_entrypoint_6((s32)((f32 *)arg0->actorData)[0],
                                  (s32)((f32 *)arg0->actorData)[1]);
}

/* extern */

s32 func_8080016C_chscreenadjust(void *arg0, s32 arg1, s32 arg2) {
    s32 _glglobalsettings_entrypoint_5(s32 *, s32 *, void *);
    s32 sp1C;
    s32 sp18;

    if (arg1 == 0x95) {
        _glglobalsettings_entrypoint_5(&sp1C, &sp18, arg0);
        (*(f32 *)((s8 *)(arg0) + (0x18))) = (f32) sp1C;
        (*(f32 *)((s8 *)(arg0) + (0x1C))) = (f32) sp18;
        return 1;
    }
    return 0;
}

void func_808001E0_chscreenadjust(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    void func_800BC474(Gfx **, s32, s32, s32, s32, s32, s32, s32);
    s32 edges[4];

    func_800BC474(arg0, arg1, arg2, arg5, arg6, arg7, arg8, arg9);
    func_800BC474(arg0, arg1, arg2, arg6, arg5, arg7, arg8, arg9);
    func_800BC474(arg0, (edges[3] = arg3 - arg5), arg2, arg5, arg6, arg7, arg8, arg9);
    func_800BC474(arg0, (edges[2] = arg3 - arg6), arg2, arg6, arg5, arg7, arg8, arg9);
    func_800BC474(arg0, arg1, (edges[1] = arg4 - arg6), arg5, arg6, arg7, arg8, arg9);
    func_800BC474(arg0, arg1, (edges[0] = arg4 - arg5), arg6, arg5, arg7, arg8, arg9);
    func_800BC474(arg0, edges[3], edges[1], arg5, arg6, arg7, arg8, arg9);
    func_800BC474(arg0, edges[2], edges[0], arg6, arg5, arg7, arg8, arg9);
}

/* extern */

void func_8080037C_chscreenadjust(s32 arg0, Gfx **arg1) {
    void func_808001E0_chscreenadjust(Gfx **, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    func_808001E0_chscreenadjust(arg1, 0, 0, 0x130, 0xE4, 0x40, 0xA, 0xFF, 0, 0);
    func_808001E0_chscreenadjust(arg1, 0x20, 0x20, 0x110, 0xC4, 0x20, 5, 0xFF, 0, 0);
}

OSThread *chscreenadjust_entrypoint_0(void)
{
    extern u8 D_80800430_chscreenadjust[];

    return (OSThread *) D_80800430_chscreenadjust;
}
