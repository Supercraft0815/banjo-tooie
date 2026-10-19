#include "common.h"

void func_80800000_chquizexitdoor(Actor *arg0) {
    s32 func_800D90A4(f32 *);
    s32 func_800DA544(s32);
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
    extern u8 D_80800190_chquizexitdoor[];

    return (OSThread *) D_80800190_chquizexitdoor;
}
