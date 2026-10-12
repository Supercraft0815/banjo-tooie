#include "common.h"

OSThread *chlagoonpirate_entrypoint_0(void)
{
    extern u8 D_808000F8_chlagoonpirate[];

    return (OSThread *) D_808000F8_chlagoonpirate;
}

/* extern */

void func_8080000C_chlagoonpirate(void *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    s32 func_80102FDC(void *, f32);
    s32 func_8010A3E8(void *, s32);
    _sucoaster_entrypoint_0(arg0, 0);
    func_80102FDC(arg0, (*(f32 *)((s8 *)(arg0) + (0x38))) * 1.5f);
    func_8010A3E8(arg0, 0x3F4CCCCD);
}
