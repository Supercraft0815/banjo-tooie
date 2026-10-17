#include "common.h"

OSThread *changlerbossdoor_entrypoint_0(void)
{
    extern u8 D_80800110_changlerbossdoor[];

    return (OSThread *) D_80800110_changlerbossdoor;
}

void func_8080000C_changlerbossdoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    void func_800F1A88(f32 *, f32 *);
    void func_80101FDC(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    union DoorActor {
        Actor actor;
        struct {
            u8 pad0[0x70];
            u32 pad70_1 : 31;
            u32 enabled : 1;
        } flags;
    };
    f32 sp3C[3];
    f32 sp30[3];
    s32 var_v1;

    var_v1 = func_800DA298(0x1AF) != 0;
    if (var_v1 == 0) {
        var_v1 = _glcutDll_entrypoint_20() != 0;
    }
    if (var_v1 != 0) {
        func_80101FDC(arg0, 1);
    }
    func_80102FDC(arg0, arg0->scale * 1.75f);
    ((union DoorActor *)arg0)->flags.enabled = 1;
    func_800EF6A8(sp30, arg0->rotation, 0.0f, 500.0f, 0.0f);
    func_800F1A88(sp30, sp3C);
    if (_chdoormake_entrypoint_3(arg0, sp3C[1], sp3C[0], 500.0f, 0x802, -1)) {
        _chdoormake_entrypoint_5(arg0, 3.0f);
        _chdoormake_entrypoint_6(arg0, 0x3F4CCCCD);
        _chdoormake_entrypoint_8(arg0, 5);
    }
}
