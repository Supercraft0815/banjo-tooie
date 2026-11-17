#include "common.h"

void func_80800000_chlavatraindoor(Actor *arg0) {
    void _chdoormake_entrypoint_12(Actor *arg0, s32 arg1, u16 arg2);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_6(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void _chdoormake_entrypoint_9(Actor *arg0, s32 arg1, u16 arg2, s32 arg3);
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
    extern ActorData D_808000F0_chlavatraindoor[];

    return (OSThread *) D_808000F0_chlavatraindoor;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/traindoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_808000F0_chlavatraindoor [1] BT_DATA(4, overlays_ch_lava_traindoor, 0x0) = { { 172, 641, 2294, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chlavatraindoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9234, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
