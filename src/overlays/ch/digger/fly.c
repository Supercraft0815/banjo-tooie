#include "common.h"

OSThread *chdiggerfly_entrypoint_0(void)
{
    extern u8 D_808000F8_chdiggerfly[];

    return (OSThread *) D_808000F8_chdiggerfly;
}

OSThread *chdiggerfly_entrypoint_1(void)
{
    extern u8 D_80800140_chdiggerfly[];

    return (OSThread *) D_80800140_chdiggerfly;
}

/* extern */

void func_80800018_chdiggerfly(void *arg0) {
    s32 _sucoasterfly_entrypoint_1(s32, s32);
    void func_80102FDC(void *, f32);
    void func_8010A3E8(void *, f32);
    _sucoasterfly_entrypoint_1((s32)arg0, 0);
    func_80102FDC(arg0, (*(f32 *)((s8 *)(arg0) + (0x38))) * 0.75f);
    func_8010A3E8(arg0, 0.75f);
}
