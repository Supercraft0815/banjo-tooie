#include "common.h"

OSThread *chwarriorbaddy_entrypoint_0(void)
{
    extern u8 D_80800128_chwarriorbaddy[];

    return (OSThread *) D_80800128_chwarriorbaddy;
}

void func_8080000C_chwarriorbaddy(Actor *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    void func_8010A3E8(void *, f32);
    if (_sucoaster_entrypoint_0(arg0, 0) != 0) {
        func_80102FDC(arg0, arg0->scale * 1.5f);
        func_8010A3E8(arg0, 0.4f);
        if (!arg0->unk7A_5) {
            _sucoaster_entrypoint_10(arg0, 2);
        }
    }
}
