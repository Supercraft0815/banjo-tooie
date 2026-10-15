#include "common.h"

/* extern */

void func_80800000_chjellycastle(Actor *arg0) {
    s32 _plsu_entrypoint_3(Unk80132ED0 *);
    void func_800C3F48(u32);
    s32 func_800D90A4(f32 *);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = _plsu_entrypoint_3(arg0->unk0);
    sp24 = temp_v0;
    if ((temp_v0 == 0) && (func_800D90A4(&arg0->unk58) != 0) && !arg0->unk64_20) {
        func_800C3F48(0x599C5699);
        arg0->unk58 = 0.5f;
    }
    arg0->unk64_20 = sp24 == 0;
}

OSThread *chjellycastle_entrypoint_0(void)
{
    extern u8 D_808000A0_chjellycastle[];

    return (OSThread *) D_808000A0_chjellycastle;
}
