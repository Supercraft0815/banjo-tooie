#include "common.h"

void func_80800000_chTalTorpWall(s32 arg0) 
{
}
s32 func_80800008_chTalTorpWall(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800DA544(GameFlag);
    extern s32 D_80800080_chTalTorpWall;
    f32 *sp18[2];
    if (arg1 == 0x40) {
        sp18[1] = arg0->position;
        _chexploder_entrypoint_3(arg0, sp18[1], 0xE);
        _subaddieaudioquick_entrypoint_2(arg0, sp18[1], &D_80800080_chTalTorpWall);
        func_800DA544(0x3AA);
        return 1;
    }
    return 0;
}

OSThread *chTalTorpWall_entrypoint_0(void)
{
    extern u8 D_80800098_chTalTorpWall[];

    return (OSThread *) D_80800098_chTalTorpWall;
}
