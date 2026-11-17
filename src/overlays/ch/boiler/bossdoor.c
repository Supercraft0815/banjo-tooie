#include "common.h"

OSThread *chboilerbossdoor_entrypoint_0(void)
{
    extern ActorData D_808000F0_chboilerbossdoor[];

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
/* data_to_c.py: from asm/data/overlays/ch/boiler/bossdoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_808000F0_chboilerbossdoor [1] BT_DATA(4, overlays_ch_boiler_bossdoor, 0x0) = { { 172, 1133, 1915, 4, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 134, 0, 0, 1024, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chboilerbossdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
