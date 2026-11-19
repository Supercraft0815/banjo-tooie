#include "common.h"

OSThread *changlerbossdoor_entrypoint_0(void)
{
    extern ActorData D_80800110_changlerbossdoor[];

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
            BT_BITFIELD_ORDER(u32 pad70_1 : 31, u32 enabled : 1);
            BT_BITFIELD_ORDER(u32 enabled : 1, u32 pad70_1 : 31);
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
/* data_to_c.py: from asm/data/overlays/ch/anglerboss/door.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_80800110_changlerbossdoor [1] BT_DATA(4, overlays_ch_anglerboss_door, 0x0) = { { 172, 1132, 2372, 4, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 887, 0, 0, 1040, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_changlerbossdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
