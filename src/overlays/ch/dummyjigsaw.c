#include "common.h"

void func_80800000_chdummyjigsaw(Actor *arg0) {
    void _fxtwinkle_entrypoint_2(f32 *, s32);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_80103DFC(Actor *, f32 *);
    f32 sp5C[3];
    f32 temp_f20;
    s32 var_s1;

    var_s1 = 0;
    if (arg0->unk7C_12) {
        do {
            if (func_800DC0C0() < 0.015f) {
                func_80103DFC(arg0, sp5C);
                temp_f20 = func_800DC178(0.0f, 360.0f);
                func_800EF214(sp5C, temp_f20, func_800DC178(0.0f, 360.0f), 40.0f);
                _fxtwinkle_entrypoint_2(sp5C, 0x9E2);
            }
            var_s1 += 1;
        } while (var_s1 != 4);
    }
    arg0->rotation[1] += func_800D8FF8() * 230.0f;
    arg0->rotation[1] = func_800136E4(arg0->rotation[1]);
}

s32 func_80800128_chdummyjigsaw(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFA88(Unk80132ED0 *);
    if ((arg1 == 0x3E) && arg0->unk64_20) {
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}

OSThread *chdummyjigsaw_entrypoint_0(void)
{
    extern ActorData D_80800190_chdummyjigsaw[];

    return (OSThread *) D_80800190_chdummyjigsaw;
}
/* data_to_c.py: from asm/data/overlays/ch/dummyjigsaw.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800190_chdummyjigsaw [1] BT_DATA(4, overlays_ch_dummyjigsaw, 0x0) = { { 303, 664, 1552, 1, 0, (void (*)(struct Actor *))func_80800000_chdummyjigsaw, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 163840000, 0, 0, 0, 0, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 16384, (void (*)(struct Actor *, long, long))func_80800128_chdummyjigsaw, 0 } };
