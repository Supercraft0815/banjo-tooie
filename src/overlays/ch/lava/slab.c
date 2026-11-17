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
    extern ActorData D_808000A0_chlavaslab[];

    return (OSThread *) D_808000A0_chlavaslab;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/slab.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_808000A0_chlavaslab [1] BT_DATA(4, overlays_ch_lava_slab, 0x0) = { { 812, 592, 2260, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chlavaslab, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
