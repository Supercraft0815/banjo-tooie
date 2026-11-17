#include "common.h"

void func_80800000_chTalTorpWall(s32 arg0) 
{
}
s32 func_80800008_chTalTorpWall(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800DA544(GameFlag);
    extern s32 D_80800080_chTalTorpWall[6];
    f32 *sp18[2];
    if (arg1 == 0x40) {
        sp18[1] = arg0->position;
        _chexploder_entrypoint_3(arg0, sp18[1], 0xE);
        _subaddieaudioquick_entrypoint_2(arg0, sp18[1], D_80800080_chTalTorpWall);
        func_800DA544(0x3AA);
        return 1;
    }
    return 0;
}

OSThread *chTalTorpWall_entrypoint_0(void)
{
    extern ActorData D_80800098_chTalTorpWall[];

    return (OSThread *) D_80800098_chTalTorpWall;
}
/* data_to_c.py: from asm/data/overlays/ch/TalTorpWall.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800080_chTalTorpWall[6] BT_DATA(4, overlays_ch_TalTorpWall, 0x0) = { 1769491, 83099658, 13369366, 1835008001, 81922500, 0 };
ActorData D_80800098_chTalTorpWall [1] BT_DATA(4, overlays_ch_TalTorpWall, 0x18) = { { 887, 1177, 2385, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 938, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chTalTorpWall, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800008_chTalTorpWall, 0 } };
