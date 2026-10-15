#include "common.h"

OSThread *chbottlesplantgrill_entrypoint_0(void)
{
    extern u8 D_808000F0_chbottlesplantgrill[];

    return (OSThread *) D_808000F0_chbottlesplantgrill;
}

/* extern */

void func_8080000C_chbottlesplantgrill(Actor *arg0) {
    s32 _chdoormake_entrypoint_12(Actor *, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_8010A800(Actor *, s32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 250.0f, 0, -1) != 0) {
        _chdoormake_entrypoint_6(arg0, 0x3F800000);
        _chdoormake_entrypoint_5(arg0, 3.0f);
        _chdoormake_entrypoint_8(arg0, 5);
        _chdoormake_entrypoint_12(arg0, 0, 0x65);
        _chdoormake_entrypoint_9(arg0, 0, 3, 0x2900);
    }
    func_8010A800(arg0, 0);
    if ((_glcutDll_entrypoint_19(0x65) == 0) && ((func_800DA298(0x1A5) != 0) || (func_800DA298(0x3B) != 0))) {
        func_800FFAB0(arg0);
    }
}
