#include "common.h"

/* extern */

void func_80800000_chcrashmat(Actor *arg0) {
    s32 _plsu_entrypoint_3(BtIntPtr arg0);
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

OSThread *chcrashmat_entrypoint_0(void)
{
    extern ActorData D_808000A0_chcrashmat[];

    return (OSThread *) D_808000A0_chcrashmat;
}
/* data_to_c.py: from asm/data/overlays/ch/crashmat.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808000A0_chcrashmat [1] BT_DATA(4, overlays_ch_crashmat, 0x0) = { { 344, 1291, 2347, 1, 0, (void (*)(struct Actor *))func_80800000_chcrashmat, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 65536000, 0, 0, 0, 2, 7176, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, 0, 0 } };
