#include "common.h"

void func_80800000_chquizexitdoor(Actor *arg0) {
    s32 func_800D90A4(f32 *);
    void func_800DA544(s32 index);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80103110(Actor *, u32);

    switch (arg0->unk70_10) {
        case 1:
            func_80103110(arg0, 0);
            break;
        case 2:
            if (func_800D90A4(&arg0->unk58)) {
                func_800DA544(0x440);
                func_800FFAB0(arg0);
            }
            arg0->alpha = (u32)func_800F10B4(arg0->unk58, 2.0f, 0.0f, 255.0f, 0.0f);
            break;
    }
}

void func_80800124_chquizexitdoor(s32 arg0) 
{
}
s32 func_8080012C_chquizexitdoor(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor*, u32);
    void func_80103110(Actor*, u32);
    if (arg1 == 7) {
        arg0->unk58 = 2.0f;
        func_80101FDC(arg0, 2U);
        func_80103110(arg0, 1U);
        return 1;
    }
    return 0;
}

OSThread *chquizexitdoor_entrypoint_0(void)
{
    extern ActorData D_80800190_chquizexitdoor[];

    return (OSThread *) D_80800190_chquizexitdoor;
}
/* data_to_c.py: from asm/data/overlays/ch/quizexitdoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800190_chquizexitdoor [1] BT_DATA(4, overlays_ch_quizexitdoor, 0x0) = { { 344, 1229, 2382, 1, 0, (void (*)(struct Actor *))func_80800000_chquizexitdoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 1088, 0, 0, 0, (void (*)(struct Actor *))func_80800124_chquizexitdoor, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_8080012C_chquizexitdoor, 0 } };
