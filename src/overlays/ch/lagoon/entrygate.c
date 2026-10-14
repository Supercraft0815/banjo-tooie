#include "ch/lagoonentrygate.h"

/* extern */

void func_80800000_chlagoonentrygate(Actor *arg0) {
    void _chdoormake_entrypoint_0(void *, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _sujiggy_entrypoint_20(u32);
    s32 func_800D3E40(s32);
    void func_800DA544(GameFlag);
    void func_80101FDC(Actor *, u32);
    s32 var_a3;

    if (_sujiggy_entrypoint_20(3) != 0) {
        func_800DA544(0x395);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7D) == 0)) {
        var_a3 = -1;
        func_80101FDC(arg0, 4);
    } else {
        var_a3 = 0x395;
    }
    _chdoormake_entrypoint_0(arg0, -150.0f, 0, var_a3);
    _chdoormake_entrypoint_5(arg0, 0.0f);
}

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
