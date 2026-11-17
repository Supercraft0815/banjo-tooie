#include "ch/lagoonentrygate.h"

/* extern */

void func_80800000_chlagoonentrygate(Actor *arg0) {
    s32 _chdoormake_entrypoint_0(Actor *arg0, f32 arg1, u32 arg2, s32 arg3);
    void _chdoormake_entrypoint_5(Actor *, f32);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _sujiggy_entrypoint_20(u32);
    s32 func_800D3E40(s32);
    void func_800DA544(GameFlag);
    void func_80101FDC(Actor *, u32);
    s32 var_a3;

    if (_sujiggy_entrypoint_20(3) != 0) {
        func_800DA544(0x395);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7D) == 0)) {
        var_a3 = -1;
        func_80101FDC(arg0, 4);
    } else {
        var_a3 = 0x395;
    }
    _chdoormake_entrypoint_0(arg0, -150.0f, 0, var_a3);
    _chdoormake_entrypoint_5(arg0, 0.0f);
}

void func_8080008C_chlagoonentrygate(Actor *arg0) {
    void _chdoor_entrypoint_0(BtIntPtr arg0);
    void func_800C3F48(u32);
    s32 func_800D90A4(f32 *);
    if (arg0->unk70_10 == 3) {
        if (!arg0->unk64_20) {
            func_800C3F48(0x66509D6D);
            *(f32 *)&arg0->actorData[7] = 1.5f;
            arg0->unk64_20 = 1;
        } else if (func_800D90A4((f32 *)&arg0->actorData[7]) != 0) {
            func_800C3F48(0x66509CA1);
            *(f32 *)&arg0->actorData[7] = 1.0f;
        }
    }
    _chdoor_entrypoint_0(arg0);
}

OSThread *chlagoonentrygate_entrypoint_0(void)
{
    extern ActorData D_80800150_chlagoonentrygate[];

    return (OSThread *) D_80800150_chlagoonentrygate;
}
/* data_to_c.py: from asm/data/overlays/ch/lagoon/entrygate.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_80800150_chlagoonentrygate [1] BT_DATA(4, overlays_ch_lagoon_entrygate, 0x0) = { { 172, 914, 2414, 1, 0, (void (*)(struct Actor *))func_8080008C_chlagoonentrygate, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chlagoonentrygate, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
