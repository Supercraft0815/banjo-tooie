#include "common.h"

void func_80800000_chlavatraindoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_12(Actor *, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_6(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    f32 var_f0;

    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 1007.5f, 0x20, 0x1D0) != 0) {
        _chdoormake_entrypoint_12(arg0, 0, 0x4D);
        _chdoormake_entrypoint_8(arg0, 5);
        if (arg0->unk74_7 == 0x32) {
            var_f0 = 0.8f;
        } else {
            var_f0 = 3.5f;
        }
        _chdoormake_entrypoint_6(arg0, var_f0);
        if (arg0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_9(arg0, 0, 8, 0x910);
        }
    }
}

OSThread *chlavatraindoor_entrypoint_0(void)
{
    extern u8 D_808000F0_chlavatraindoor[];

    return (OSThread *) D_808000F0_chlavatraindoor;
}
