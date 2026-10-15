#include "common.h"

OSThread *chboilerbossdoor_entrypoint_0(void)
{
    extern u8 D_808000F0_chboilerbossdoor[];

    return (OSThread *) D_808000F0_chboilerbossdoor;
}

/* extern */

void func_8080000C_chboilerbossdoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_8010108C();
    void func_80101FDC(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    s32 sp28;

    sp28 = func_800DA298(0x179) || _glcutDll_entrypoint_20();
    if (sp28 != 0) {
        func_80101FDC(arg0, 1);
    }
    func_80102FDC(arg0, arg0->scale * 1.1f);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 400.0f, 0x802, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 4.0f);
        _chdoormake_entrypoint_8(arg0, 0xC);
    }
    if (sp28 == 0) {
        func_8010108C(arg0, 8, 0);
    }
}
