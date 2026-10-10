#include "common.h"

void func_80800000_chwaterfallgrillswitch(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x11B, 7, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_80800054_chwaterfallgrillswitch(Actor *arg0) {
    void _chswitch_entrypoint_8(s16 *arg0, s32 arg1);
    void _chswitch_entrypoint_7(Actor*, s32);
    _chswitch_entrypoint_7(arg0, 0);
    _chswitch_entrypoint_8((s16 *) arg0, 0x201);
}

OSThread *chwaterfallgrillswitch_entrypoint_0(void)
{
    extern u8 D_80800090_chwaterfallgrillswitch[];

    return (OSThread *) D_80800090_chwaterfallgrillswitch;
}
