#include "common.h"

/* extern */

void func_80800000_chlavaslab(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_6(Actor*, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    if (_chdoormake_entrypoint_3(arg0, arg0->rotation[1] + 90.0f, 0.0f, arg0->scale * 430.0f, 0, 0x38F) != 0) {
        if (arg0->unk74_7 == 0x33) {
            _chdoormake_entrypoint_6(arg0, 0x40C00000);
        }
        _chdoormake_entrypoint_8(arg0, 0xA);
    }
}

OSThread *chlavaslab_entrypoint_0(void)
{
    extern u8 D_808000A0_chlavaslab[];

    return (OSThread *) D_808000A0_chlavaslab;
}
